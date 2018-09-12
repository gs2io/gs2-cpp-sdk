// trap.h - written and placed in public domain by Jeffrey Walton.

/// \file trap.h
/// \brief Debugging and diagnostic assertions
/// \details <tt>GS2_CRYPTOPP_ASSERT</tt> is the library's debugging and diagnostic assertion. <tt>GS2_CRYPTOPP_ASSERT</tt>
///   is enabled by <tt>GS2_CRYPTOPP_DEBUG</tt>, <tt>DEBUG</tt> or <tt>_DEBUG</tt>.
/// \details <tt>GS2_CRYPTOPP_ASSERT</tt> raises a <tt>SIGTRAP</tt> (Unix) or calls <tt>__debugbreak()</tt> (Windows).
///   <tt>GS2_CRYPTOPP_ASSERT</tt> is only in effect when the user requests a debug configuration. Unlike Posix assert,
///   <tt>NDEBUG</tt> (or failure to define it) does not affect the library.
/// The traditional Posix define <tt>NDEBUG</tt> has no effect on <tt>GS2_CRYPTOPP_DEBUG</tt> or DebugTrapHandler.
/// \since Crypto++ 5.6.5
/// \sa DebugTrapHandler, <A HREF="http://github.com/weidai11/cryptopp/issues/277">Issue 277</A>,
///   <A HREF="http://seclists.org/oss-sec/2016/q3/520">CVE-2016-7420</A>

#ifndef GS2_CRYPTOPP_TRAP_H
#define GS2_CRYPTOPP_TRAP_H

#include "config.h"

#if defined(GS2_CRYPTOPP_DEBUG)
#  include <iostream>
#  include <sstream>
#  if defined(UNIX_SIGNALS_AVAILABLE)
#    include "ossig.h"
#  elif defined(GS2_CRYPTOPP_WIN32_AVAILABLE) && !defined(__CYGWIN__)
     extern "C" __declspec(dllimport) void __stdcall DebugBreak();
     extern "C" __declspec(dllimport)  int __stdcall IsDebuggerPresent();
#  endif
#endif // GS2_CRYPTOPP_DEBUG

// ************** run-time assertion ***************

#if defined(GS2_CRYPTOPP_DOXYGEN_PROCESSING)
/// \brief Debugging and diagnostic assertion
/// \details <tt>GS2_CRYPTOPP_ASSERT</tt> is the library's debugging and diagnostic assertion. <tt>GS2_CRYPTOPP_ASSERT</tt>
///   is enabled by the preprocessor macros <tt>GS2_CRYPTOPP_DEBUG</tt>, <tt>DEBUG</tt> or <tt>_DEBUG</tt>.
/// \details <tt>GS2_CRYPTOPP_ASSERT</tt> raises a <tt>SIGTRAP</tt> (Unix) or calls <tt>DebugBreak()</tt> (Windows).
///   <tt>GS2_CRYPTOPP_ASSERT</tt> is only in effect when the user explicitly requests a debug configuration.
/// \details If you want to ensure <tt>GS2_CRYPTOPP_ASSERT</tt> is inert, then <em>do not</em> define
///   <tt>GS2_CRYPTOPP_DEBUG</tt>, <tt>DEBUG</tt> or <tt>_DEBUG</tt>. Avoiding the defines means <tt>GS2_CRYPTOPP_ASSERT</tt>
///   is preprocessed into an empty string.
/// \details The traditional Posix define <tt>NDEBUG</tt> has no effect on <tt>GS2_CRYPTOPP_DEBUG</tt>, <tt>GS2_CRYPTOPP_ASSERT</tt>
///   or DebugTrapHandler.
/// \details An example of using \ref GS2_CRYPTOPP_ASSERT "GS2_CRYPTOPP_ASSERT" and DebugTrapHandler is shown below. The library's
///   test program, <tt>cryptest.exe</tt> (from test.cpp), exercises the structure:
///  <pre>
///    #if defined(GS2_CRYPTOPP_DEBUG) && defined(UNIX_SIGNALS_AVAILABLE)
///    static const DebugTrapHandler g_dummyHandler;
///    #endif
///
///    int main(int argc, char* argv[])
///    {
///       GS2_CRYPTOPP_ASSERT(argv != nullptr);
///       ...
///    }
///  </pre>
/// \since Crypto++ 5.6.5
/// \sa DebugTrapHandler, SignalHandler, <A HREF="http://github.com/weidai11/cryptopp/issues/277">Issue 277</A>,
///   <A HREF="http://seclists.org/oss-sec/2016/q3/520">CVE-2016-7420</A>
#  define GS2_CRYPTOPP_ASSERT(exp) { ... }
#endif

#if defined(GS2_CRYPTOPP_DEBUG) && defined(UNIX_SIGNALS_AVAILABLE)
#  define GS2_CRYPTOPP_ASSERT(exp) {                                  \
    if (!(exp)) {                                                 \
      std::ostringstream oss;                                     \
      oss << "Assertion failed: " << (char*)(__FILE__) << "("     \
          << (int)(__LINE__) << "): " << (char*)(__func__)        \
          << std::endl;                                           \
      std::cerr << oss.str();                                     \
      raise(SIGTRAP);                                             \
    }                                                             \
  }
#elif GS2_CRYPTOPP_DEBUG && defined(GS2_CRYPTOPP_WIN32_AVAILABLE) && !defined(__CYGWIN__)
#  define GS2_CRYPTOPP_ASSERT(exp) {                                  \
    if (!(exp)) {                                                 \
      std::ostringstream oss;                                     \
      oss << "Assertion failed: " << (char*)(__FILE__) << "("     \
          << (int)(__LINE__) << "): " << (char*)(__FUNCTION__)    \
          << std::endl;                                           \
      std::cerr << oss.str();                                     \
      if (IsDebuggerPresent()) {DebugBreak();}                    \
    }                                                             \
  }
#endif // DEBUG and Unix or Windows

// Remove GS2_CRYPTOPP_ASSERT in non-debug builds.
//  Can't use GS2_CRYPTOPP_UNUSED due to circular dependency
#ifndef GS2_CRYPTOPP_ASSERT
#  define GS2_CRYPTOPP_ASSERT(exp) (void)0
#endif

NAMESPACE_BEGIN(gs2)
NAMESPACE_BEGIN(detail)
NAMESPACE_BEGIN(CryptoPP)

// ************** SIGTRAP handler ***************

#if (GS2_CRYPTOPP_DEBUG && defined(UNIX_SIGNALS_AVAILABLE)) || defined(GS2_CRYPTOPP_DOXYGEN_PROCESSING)
/// \brief Default SIGTRAP handler
/// \details DebugTrapHandler() can be used by a program to install an empty SIGTRAP handler. If present,
///   the handler ensures there is a signal handler in place for <tt>SIGTRAP</tt> raised by
///   <tt>GS2_CRYPTOPP_ASSERT</tt>. If <tt>GS2_CRYPTOPP_ASSERT</tt> raises <tt>SIGTRAP</tt> <em>without</em>
///   a handler, then one of two things can occur. First, the OS might allow the program
///   to continue. Second, the OS might terminate the program. OS X allows the program to continue, while
///   some Linuxes terminate the program.
/// \details If DebugTrapHandler detects another handler in place, then it will not install a handler. This
///   ensures a debugger can gain control of the <tt>SIGTRAP</tt> signal without contention. It also allows multiple
///   DebugTrapHandler to be created without contentious or unusual behavior. Though multiple DebugTrapHandler can be
///   created, a program should only create one, if needed.
/// \details A DebugTrapHandler is subject to C++ static initialization [dis]order. If you need to install a handler
///   and it must be installed early, then reference the code associated with <tt>GS2_CRYPTOPP_INIT_PRIORITY</tt> in
///   cryptlib.cpp and cpu.cpp.
/// \details If you want to ensure <tt>GS2_CRYPTOPP_ASSERT</tt> is inert, then <em>do not</em> define
///   <tt>GS2_CRYPTOPP_DEBUG</tt>, <tt>DEBUG</tt> or <tt>_DEBUG</tt>. Avoiding the defines means <tt>GS2_CRYPTOPP_ASSERT</tt>
///   is processed into <tt>((void)(exp))</tt>.
/// \details The traditional Posix define <tt>NDEBUG</tt> has no effect on <tt>GS2_CRYPTOPP_DEBUG</tt>, <tt>GS2_CRYPTOPP_ASSERT</tt>
///   or DebugTrapHandler.
/// \details An example of using \ref GS2_CRYPTOPP_ASSERT "GS2_CRYPTOPP_ASSERT" and DebugTrapHandler is shown below. The library's
///   test program, <tt>cryptest.exe</tt> (from test.cpp), exercises the structure:
///  <pre>
///    #if defined(GS2_CRYPTOPP_DEBUG) && defined(UNIX_SIGNALS_AVAILABLE)
///    static const DebugTrapHandler g_dummyHandler;
///    #endif
///
///    int main(int argc, char* argv[])
///    {
///       GS2_CRYPTOPP_ASSERT(argv != nullptr);
///       ...
///    }
///  </pre>
/// \since Crypto++ 5.6.5
/// \sa \ref GS2_CRYPTOPP_ASSERT "GS2_CRYPTOPP_ASSERT", SignalHandler, <A HREF="http://github.com/weidai11/cryptopp/issues/277">Issue 277</A>,
///   <A HREF="http://seclists.org/oss-sec/2016/q3/520">CVE-2016-7420</A>

#if defined(GS2_CRYPTOPP_DOXYGEN_PROCESSING)
class DebugTrapHandler : public SignalHandler<SIGILL, false> { };
#else
typedef SignalHandler<SIGILL, false> DebugTrapHandler;
#endif

#endif  // Linux, Unix and Documentation

NAMESPACE_END
NAMESPACE_END
NAMESPACE_END

#endif // GS2_CRYPTOPP_TRAP_H
