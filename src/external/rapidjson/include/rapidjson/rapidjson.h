// Tencent is pleased to support the open source community by making RapidJSON available.
// 
// Copyright (C) 2015 THL A29 Limited, a Tencent company, and Milo Yip. All rights reserved.
//
// Licensed under the MIT License (the "License"); you may not use this file except
// in compliance with the License. You may obtain a copy of the License at
//
// http://opensource.org/licenses/MIT
//
// Unless required by applicable law or agreed to in writing, software distributed 
// under the License is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR 
// CONDITIONS OF ANY KIND, either express or implied. See the License for the 
// specific language governing permissions and limitations under the License.

#ifndef GS2_RAPIDJSON_RAPIDJSON_H_
#define GS2_RAPIDJSON_RAPIDJSON_H_

/*!\file rapidjson.h
    \brief common definitions and configuration
    
    \see GS2_RAPIDJSON_CONFIG
 */

/*! \defgroup GS2_RAPIDJSON_CONFIG RapidJSON configuration
    \brief Configuration macros for library features

    Some RapidJSON features are configurable to adapt the library to a wide
    variety of platforms, environments and usage scenarios.  Most of the
    features can be configured in terms of overriden or predefined
    preprocessor macros at compile-time.

    Some additional customization is available in the \ref GS2_RAPIDJSON_ERRORS APIs.

    \note These macros should be given on the compiler command-line
          (where applicable)  to avoid inconsistent values when compiling
          different translation units of a single application.
 */

#include <cstdlib>  // malloc(), realloc(), free(), size_t
#include <cstring>  // memset(), memcpy(), memmove(), memcmp()

///////////////////////////////////////////////////////////////////////////////
// GS2_RAPIDJSON_VERSION_STRING
//
// ALWAYS synchronize the following 3 macros with corresponding variables in /CMakeLists.txt.
//

//!@cond GS2_RAPIDJSON_HIDDEN_FROM_DOXYGEN
// token stringification
#define GS2_RAPIDJSON_STRINGIFY(x) GS2_RAPIDJSON_DO_STRINGIFY(x)
#define GS2_RAPIDJSON_DO_STRINGIFY(x) #x
//!@endcond

/*! \def GS2_RAPIDJSON_MAJOR_VERSION
    \ingroup GS2_RAPIDJSON_CONFIG
    \brief Major version of RapidJSON in integer.
*/
/*! \def GS2_RAPIDJSON_MINOR_VERSION
    \ingroup GS2_RAPIDJSON_CONFIG
    \brief Minor version of RapidJSON in integer.
*/
/*! \def GS2_RAPIDJSON_PATCH_VERSION
    \ingroup GS2_RAPIDJSON_CONFIG
    \brief Patch version of RapidJSON in integer.
*/
/*! \def GS2_RAPIDJSON_VERSION_STRING
    \ingroup GS2_RAPIDJSON_CONFIG
    \brief Version of RapidJSON in "<major>.<minor>.<patch>" string format.
*/
#define GS2_RAPIDJSON_MAJOR_VERSION 1
#define GS2_RAPIDJSON_MINOR_VERSION 1
#define GS2_RAPIDJSON_PATCH_VERSION 0
#define GS2_RAPIDJSON_VERSION_STRING \
    GS2_RAPIDJSON_STRINGIFY(GS2_RAPIDJSON_MAJOR_VERSION.GS2_RAPIDJSON_MINOR_VERSION.GS2_RAPIDJSON_PATCH_VERSION)

///////////////////////////////////////////////////////////////////////////////
// GS2_RAPIDJSON_NAMESPACE_(BEGIN|END)
/*! \def GS2_RAPIDJSON_NAMESPACE
    \ingroup GS2_RAPIDJSON_CONFIG
    \brief   provide custom rapidjson namespace

    In order to avoid symbol clashes and/or "One Definition Rule" errors
    between multiple inclusions of (different versions of) RapidJSON in
    a single binary, users can customize the name of the main RapidJSON
    namespace.

    In case of a single nesting level, defining \c GS2_RAPIDJSON_NAMESPACE
    to a custom name (e.g. \c MyRapidJSON) is sufficient.  If multiple
    levels are needed, both \ref GS2_RAPIDJSON_NAMESPACE_BEGIN and \ref
    GS2_RAPIDJSON_NAMESPACE_END need to be defined as well:

    \code
    // in some .cpp file
    #define GS2_RAPIDJSON_NAMESPACE my::rapidjson
    #define GS2_RAPIDJSON_NAMESPACE_BEGIN namespace my { namespace rapidjson {
    #define GS2_RAPIDJSON_NAMESPACE_END   } }
    #include "rapidjson/..."
    \endcode

    \see rapidjson
 */
/*! \def GS2_RAPIDJSON_NAMESPACE_BEGIN
    \ingroup GS2_RAPIDJSON_CONFIG
    \brief   provide custom rapidjson namespace (opening expression)
    \see GS2_RAPIDJSON_NAMESPACE
*/
/*! \def GS2_RAPIDJSON_NAMESPACE_END
    \ingroup GS2_RAPIDJSON_CONFIG
    \brief   provide custom rapidjson namespace (closing expression)
    \see GS2_RAPIDJSON_NAMESPACE
*/
#ifndef GS2_RAPIDJSON_NAMESPACE
#define GS2_RAPIDJSON_NAMESPACE gs2::detail::rapidjson
#endif
#ifndef GS2_RAPIDJSON_NAMESPACE_BEGIN
#define GS2_RAPIDJSON_NAMESPACE_BEGIN namespace gs2 { namespace detail { namespace rapidjson {
#endif
#ifndef GS2_RAPIDJSON_NAMESPACE_END
#define GS2_RAPIDJSON_NAMESPACE_END }}}
#endif

///////////////////////////////////////////////////////////////////////////////
// GS2_RAPIDJSON_HAS_STDSTRING

#ifndef GS2_RAPIDJSON_HAS_STDSTRING
#ifdef GS2_RAPIDJSON_DOXYGEN_RUNNING
#define GS2_RAPIDJSON_HAS_STDSTRING 1 // force generation of documentation
#else
#define GS2_RAPIDJSON_HAS_STDSTRING 0 // no std::string support by default
#endif
/*! \def GS2_RAPIDJSON_HAS_STDSTRING
    \ingroup GS2_RAPIDJSON_CONFIG
    \brief Enable RapidJSON support for \c std::string

    By defining this preprocessor symbol to \c 1, several convenience functions for using
    \ref rapidjson::GenericValue with \c std::string are enabled, especially
    for construction and comparison.

    \hideinitializer
*/
#endif // !defined(GS2_RAPIDJSON_HAS_STDSTRING)

#if GS2_RAPIDJSON_HAS_STDSTRING
#include <string>
#endif // GS2_RAPIDJSON_HAS_STDSTRING

///////////////////////////////////////////////////////////////////////////////
// GS2_RAPIDJSON_NO_INT64DEFINE

/*! \def GS2_RAPIDJSON_NO_INT64DEFINE
    \ingroup GS2_RAPIDJSON_CONFIG
    \brief Use external 64-bit integer types.

    RapidJSON requires the 64-bit integer types \c int64_t and  \c uint64_t types
    to be available at global scope.

    If users have their own definition, define GS2_RAPIDJSON_NO_INT64DEFINE to
    prevent RapidJSON from defining its own types.
*/
#ifndef GS2_RAPIDJSON_NO_INT64DEFINE
//!@cond GS2_RAPIDJSON_HIDDEN_FROM_DOXYGEN
#if defined(_MSC_VER) && (_MSC_VER < 1800)	// Visual Studio 2013
#include "msinttypes/stdint.h"
#include "msinttypes/inttypes.h"
#else
// Other compilers should have this.
#include <stdint.h>
#include <inttypes.h>
#endif
//!@endcond
#ifdef GS2_RAPIDJSON_DOXYGEN_RUNNING
#define GS2_RAPIDJSON_NO_INT64DEFINE
#endif
#endif // GS2_RAPIDJSON_NO_INT64TYPEDEF

///////////////////////////////////////////////////////////////////////////////
// GS2_RAPIDJSON_FORCEINLINE

#ifndef GS2_RAPIDJSON_FORCEINLINE
//!@cond GS2_RAPIDJSON_HIDDEN_FROM_DOXYGEN
#if defined(_MSC_VER) && defined(NDEBUG)
#define GS2_RAPIDJSON_FORCEINLINE __forceinline
#elif defined(__GNUC__) && __GNUC__ >= 4 && defined(NDEBUG)
#define GS2_RAPIDJSON_FORCEINLINE __attribute__((always_inline))
#else
#define GS2_RAPIDJSON_FORCEINLINE
#endif
//!@endcond
#endif // GS2_RAPIDJSON_FORCEINLINE

///////////////////////////////////////////////////////////////////////////////
// GS2_RAPIDJSON_ENDIAN
#define GS2_RAPIDJSON_LITTLEENDIAN  0   //!< Little endian machine
#define GS2_RAPIDJSON_BIGENDIAN     1   //!< Big endian machine

//! Endianness of the machine.
/*!
    \def GS2_RAPIDJSON_ENDIAN
    \ingroup GS2_RAPIDJSON_CONFIG

    GCC 4.6 provided macro for detecting endianness of the target machine. But other
    compilers may not have this. User can define GS2_RAPIDJSON_ENDIAN to either
    \ref GS2_RAPIDJSON_LITTLEENDIAN or \ref GS2_RAPIDJSON_BIGENDIAN.

    Default detection implemented with reference to
    \li https://gcc.gnu.org/onlinedocs/gcc-4.6.0/cpp/Common-Predefined-Macros.html
    \li http://www.boost.org/doc/libs/1_42_0/boost/detail/endian.hpp
*/
#ifndef GS2_RAPIDJSON_ENDIAN
// Detect with GCC 4.6's macro
#  ifdef __BYTE_ORDER__
#    if __BYTE_ORDER__ == __ORDER_LITTLE_ENDIAN__
#      define GS2_RAPIDJSON_ENDIAN GS2_RAPIDJSON_LITTLEENDIAN
#    elif __BYTE_ORDER__ == __ORDER_BIG_ENDIAN__
#      define GS2_RAPIDJSON_ENDIAN GS2_RAPIDJSON_BIGENDIAN
#    else
#      error Unknown machine endianess detected. User needs to define GS2_RAPIDJSON_ENDIAN.
#    endif // __BYTE_ORDER__
// Detect with GLIBC's endian.h
#  elif defined(__GLIBC__)
#    include <endian.h>
#    if (__BYTE_ORDER == __LITTLE_ENDIAN)
#      define GS2_RAPIDJSON_ENDIAN GS2_RAPIDJSON_LITTLEENDIAN
#    elif (__BYTE_ORDER == __BIG_ENDIAN)
#      define GS2_RAPIDJSON_ENDIAN GS2_RAPIDJSON_BIGENDIAN
#    else
#      error Unknown machine endianess detected. User needs to define GS2_RAPIDJSON_ENDIAN.
#   endif // __GLIBC__
// Detect with _LITTLE_ENDIAN and _BIG_ENDIAN macro
#  elif defined(_LITTLE_ENDIAN) && !defined(_BIG_ENDIAN)
#    define GS2_RAPIDJSON_ENDIAN GS2_RAPIDJSON_LITTLEENDIAN
#  elif defined(_BIG_ENDIAN) && !defined(_LITTLE_ENDIAN)
#    define GS2_RAPIDJSON_ENDIAN GS2_RAPIDJSON_BIGENDIAN
// Detect with architecture macros
#  elif defined(__sparc) || defined(__sparc__) || defined(_POWER) || defined(__powerpc__) || defined(__ppc__) || defined(__hpux) || defined(__hppa) || defined(_MIPSEB) || defined(_POWER) || defined(__s390__)
#    define GS2_RAPIDJSON_ENDIAN GS2_RAPIDJSON_BIGENDIAN
#  elif defined(__i386__) || defined(__alpha__) || defined(__ia64) || defined(__ia64__) || defined(_M_IX86) || defined(_M_IA64) || defined(_M_ALPHA) || defined(__amd64) || defined(__amd64__) || defined(_M_AMD64) || defined(__x86_64) || defined(__x86_64__) || defined(_M_X64) || defined(__bfin__)
#    define GS2_RAPIDJSON_ENDIAN GS2_RAPIDJSON_LITTLEENDIAN
#  elif defined(_MSC_VER) && defined(_M_ARM)
#    define GS2_RAPIDJSON_ENDIAN GS2_RAPIDJSON_LITTLEENDIAN
#  elif defined(GS2_RAPIDJSON_DOXYGEN_RUNNING)
#    define GS2_RAPIDJSON_ENDIAN
#  else
#    error Unknown machine endianess detected. User needs to define GS2_RAPIDJSON_ENDIAN.
#  endif
#endif // GS2_RAPIDJSON_ENDIAN

///////////////////////////////////////////////////////////////////////////////
// GS2_RAPIDJSON_64BIT

//! Whether using 64-bit architecture
#ifndef GS2_RAPIDJSON_64BIT
#if defined(__LP64__) || (defined(__x86_64__) && defined(__ILP32__)) || defined(_WIN64) || defined(__EMSCRIPTEN__)
#define GS2_RAPIDJSON_64BIT 1
#else
#define GS2_RAPIDJSON_64BIT 0
#endif
#endif // GS2_RAPIDJSON_64BIT

///////////////////////////////////////////////////////////////////////////////
// GS2_RAPIDJSON_ALIGN

//! Data alignment of the machine.
/*! \ingroup GS2_RAPIDJSON_CONFIG
    \param x pointer to align

    Some machines require strict data alignment. Currently the default uses 4 bytes
    alignment on 32-bit platforms and 8 bytes alignment for 64-bit platforms.
    User can customize by defining the GS2_RAPIDJSON_ALIGN function macro.
*/
#ifndef GS2_RAPIDJSON_ALIGN
#if GS2_RAPIDJSON_64BIT == 1
#define GS2_RAPIDJSON_ALIGN(x) (((x) + static_cast<uint64_t>(7u)) & ~static_cast<uint64_t>(7u))
#else
#define GS2_RAPIDJSON_ALIGN(x) (((x) + 3u) & ~3u)
#endif
#endif

///////////////////////////////////////////////////////////////////////////////
// GS2_RAPIDJSON_UINT64_C2

//! Construct a 64-bit literal by a pair of 32-bit integer.
/*!
    64-bit literal with or without ULL suffix is prone to compiler warnings.
    UINT64_C() is C macro which cause compilation problems.
    Use this macro to define 64-bit constants by a pair of 32-bit integer.
*/
#ifndef GS2_RAPIDJSON_UINT64_C2
#define GS2_RAPIDJSON_UINT64_C2(high32, low32) ((static_cast<uint64_t>(high32) << 32) | static_cast<uint64_t>(low32))
#endif

///////////////////////////////////////////////////////////////////////////////
// GS2_RAPIDJSON_48BITPOINTER_OPTIMIZATION

//! Use only lower 48-bit address for some pointers.
/*!
    \ingroup GS2_RAPIDJSON_CONFIG

    This optimization uses the fact that current X86-64 architecture only implement lower 48-bit virtual address.
    The higher 16-bit can be used for storing other data.
    \c GenericValue uses this optimization to reduce its size form 24 bytes to 16 bytes in 64-bit architecture.
*/
#ifndef GS2_RAPIDJSON_48BITPOINTER_OPTIMIZATION
#if defined(__amd64__) || defined(__amd64) || defined(__x86_64__) || defined(__x86_64) || defined(_M_X64) || defined(_M_AMD64)
#define GS2_RAPIDJSON_48BITPOINTER_OPTIMIZATION 1
#else
#define GS2_RAPIDJSON_48BITPOINTER_OPTIMIZATION 0
#endif
#endif // GS2_RAPIDJSON_48BITPOINTER_OPTIMIZATION

#if GS2_RAPIDJSON_48BITPOINTER_OPTIMIZATION == 1
#if GS2_RAPIDJSON_64BIT != 1
#error GS2_RAPIDJSON_48BITPOINTER_OPTIMIZATION can only be set to 1 when GS2_RAPIDJSON_64BIT=1
#endif
#define GS2_RAPIDJSON_SETPOINTER(type, p, x) (p = reinterpret_cast<type *>((reinterpret_cast<uintptr_t>(p) & static_cast<uintptr_t>(GS2_RAPIDJSON_UINT64_C2(0xFFFF0000, 0x00000000))) | reinterpret_cast<uintptr_t>(reinterpret_cast<const void*>(x))))
#define GS2_RAPIDJSON_GETPOINTER(type, p) (reinterpret_cast<type *>(reinterpret_cast<uintptr_t>(p) & static_cast<uintptr_t>(GS2_RAPIDJSON_UINT64_C2(0x0000FFFF, 0xFFFFFFFF))))
#else
#define GS2_RAPIDJSON_SETPOINTER(type, p, x) (p = (x))
#define GS2_RAPIDJSON_GETPOINTER(type, p) (p)
#endif

///////////////////////////////////////////////////////////////////////////////
// GS2_RAPIDJSON_SSE2/GS2_RAPIDJSON_SSE42/GS2_RAPIDJSON_SIMD

/*! \def GS2_RAPIDJSON_SIMD
    \ingroup GS2_RAPIDJSON_CONFIG
    \brief Enable SSE2/SSE4.2 optimization.

    RapidJSON supports optimized implementations for some parsing operations
    based on the SSE2 or SSE4.2 SIMD extensions on modern Intel-compatible
    processors.

    To enable these optimizations, two different symbols can be defined;
    \code
    // Enable SSE2 optimization.
    #define GS2_RAPIDJSON_SSE2

    // Enable SSE4.2 optimization.
    #define GS2_RAPIDJSON_SSE42
    \endcode

    \c GS2_RAPIDJSON_SSE42 takes precedence, if both are defined.

    If any of these symbols is defined, RapidJSON defines the macro
    \c GS2_RAPIDJSON_SIMD to indicate the availability of the optimized code.
*/
#if defined(GS2_RAPIDJSON_SSE2) || defined(GS2_RAPIDJSON_SSE42) \
    || defined(GS2_RAPIDJSON_DOXYGEN_RUNNING)
#define GS2_RAPIDJSON_SIMD
#endif

///////////////////////////////////////////////////////////////////////////////
// GS2_RAPIDJSON_NO_SIZETYPEDEFINE

#ifndef GS2_RAPIDJSON_NO_SIZETYPEDEFINE
/*! \def GS2_RAPIDJSON_NO_SIZETYPEDEFINE
    \ingroup GS2_RAPIDJSON_CONFIG
    \brief User-provided \c SizeType definition.

    In order to avoid using 32-bit size types for indexing strings and arrays,
    define this preprocessor symbol and provide the type rapidjson::SizeType
    before including RapidJSON:
    \code
    #define GS2_RAPIDJSON_NO_SIZETYPEDEFINE
    namespace rapidjson { typedef ::std::size_t SizeType; }
    #include "rapidjson/..."
    \endcode

    \see rapidjson::SizeType
*/
#ifdef GS2_RAPIDJSON_DOXYGEN_RUNNING
#define GS2_RAPIDJSON_NO_SIZETYPEDEFINE
#endif
GS2_RAPIDJSON_NAMESPACE_BEGIN
//! Size type (for string lengths, array sizes, etc.)
/*! RapidJSON uses 32-bit array/string indices even on 64-bit platforms,
    instead of using \c size_t. Users may override the SizeType by defining
    \ref GS2_RAPIDJSON_NO_SIZETYPEDEFINE.
*/
typedef unsigned SizeType;
GS2_RAPIDJSON_NAMESPACE_END
#endif

// always import std::size_t to rapidjson namespace
GS2_RAPIDJSON_NAMESPACE_BEGIN
using std::size_t;
GS2_RAPIDJSON_NAMESPACE_END

///////////////////////////////////////////////////////////////////////////////
// GS2_RAPIDJSON_ASSERT

//! Assertion.
/*! \ingroup GS2_RAPIDJSON_CONFIG
    By default, rapidjson uses C \c assert() for internal assertions.
    User can override it by defining GS2_RAPIDJSON_ASSERT(x) macro.

    \note Parsing errors are handled and can be customized by the
          \ref GS2_RAPIDJSON_ERRORS APIs.
*/
#ifndef GS2_RAPIDJSON_ASSERT
#include <cassert>
#define GS2_RAPIDJSON_ASSERT(x) assert(x)
#endif // GS2_RAPIDJSON_ASSERT

///////////////////////////////////////////////////////////////////////////////
// GS2_RAPIDJSON_STATIC_ASSERT

// Adopt from boost
#ifndef GS2_RAPIDJSON_STATIC_ASSERT
#ifndef __clang__
//!@cond GS2_RAPIDJSON_HIDDEN_FROM_DOXYGEN
#endif
GS2_RAPIDJSON_NAMESPACE_BEGIN
template <bool x> struct STATIC_ASSERTION_FAILURE;
template <> struct STATIC_ASSERTION_FAILURE<true> { enum { value = 1 }; };
template<int x> struct StaticAssertTest {};
GS2_RAPIDJSON_NAMESPACE_END

#define GS2_RAPIDJSON_JOIN(X, Y) GS2_RAPIDJSON_DO_JOIN(X, Y)
#define GS2_RAPIDJSON_DO_JOIN(X, Y) GS2_RAPIDJSON_DO_JOIN2(X, Y)
#define GS2_RAPIDJSON_DO_JOIN2(X, Y) X##Y

#if defined(__GNUC__)
#define GS2_RAPIDJSON_STATIC_ASSERT_UNUSED_ATTRIBUTE __attribute__((unused))
#else
#define GS2_RAPIDJSON_STATIC_ASSERT_UNUSED_ATTRIBUTE
#endif
#ifndef __clang__
//!@endcond
#endif

/*! \def GS2_RAPIDJSON_STATIC_ASSERT
    \brief (Internal) macro to check for conditions at compile-time
    \param x compile-time condition
    \hideinitializer
 */
#define GS2_RAPIDJSON_STATIC_ASSERT(x) \
    typedef ::GS2_RAPIDJSON_NAMESPACE::StaticAssertTest< \
      sizeof(::GS2_RAPIDJSON_NAMESPACE::STATIC_ASSERTION_FAILURE<bool(x) >)> \
    GS2_RAPIDJSON_JOIN(StaticAssertTypedef, __LINE__) GS2_RAPIDJSON_STATIC_ASSERT_UNUSED_ATTRIBUTE
#endif

///////////////////////////////////////////////////////////////////////////////
// GS2_RAPIDJSON_LIKELY, GS2_RAPIDJSON_UNLIKELY

//! Compiler branching hint for expression with high probability to be true.
/*!
    \ingroup GS2_RAPIDJSON_CONFIG
    \param x Boolean expression likely to be true.
*/
#ifndef GS2_RAPIDJSON_LIKELY
#if defined(__GNUC__) || defined(__clang__)
#define GS2_RAPIDJSON_LIKELY(x) __builtin_expect(!!(x), 1)
#else
#define GS2_RAPIDJSON_LIKELY(x) (x)
#endif
#endif

//! Compiler branching hint for expression with low probability to be true.
/*!
    \ingroup GS2_RAPIDJSON_CONFIG
    \param x Boolean expression unlikely to be true.
*/
#ifndef GS2_RAPIDJSON_UNLIKELY
#if defined(__GNUC__) || defined(__clang__)
#define GS2_RAPIDJSON_UNLIKELY(x) __builtin_expect(!!(x), 0)
#else
#define GS2_RAPIDJSON_UNLIKELY(x) (x)
#endif
#endif

///////////////////////////////////////////////////////////////////////////////
// Helpers

//!@cond GS2_RAPIDJSON_HIDDEN_FROM_DOXYGEN

#define GS2_RAPIDJSON_MULTILINEMACRO_BEGIN do {
#define GS2_RAPIDJSON_MULTILINEMACRO_END \
} while((void)0, 0)

// adopted from Boost
#define GS2_RAPIDJSON_VERSION_CODE(x,y,z) \
  (((x)*100000) + ((y)*100) + (z))

///////////////////////////////////////////////////////////////////////////////
// GS2_RAPIDJSON_DIAG_PUSH/POP, GS2_RAPIDJSON_DIAG_OFF

#if defined(__GNUC__)
#define GS2_RAPIDJSON_GNUC \
    GS2_RAPIDJSON_VERSION_CODE(__GNUC__,__GNUC_MINOR__,__GNUC_PATCHLEVEL__)
#endif

#if defined(__clang__) || (defined(GS2_RAPIDJSON_GNUC) && GS2_RAPIDJSON_GNUC >= GS2_RAPIDJSON_VERSION_CODE(4,2,0))

#define GS2_RAPIDJSON_PRAGMA(x) _Pragma(GS2_RAPIDJSON_STRINGIFY(x))
#define GS2_RAPIDJSON_DIAG_PRAGMA(x) GS2_RAPIDJSON_PRAGMA(GCC diagnostic x)
#define GS2_RAPIDJSON_DIAG_OFF(x) \
    GS2_RAPIDJSON_DIAG_PRAGMA(ignored GS2_RAPIDJSON_STRINGIFY(GS2_RAPIDJSON_JOIN(-W,x)))

// push/pop support in Clang and GCC>=4.6
#if defined(__clang__) || (defined(GS2_RAPIDJSON_GNUC) && GS2_RAPIDJSON_GNUC >= GS2_RAPIDJSON_VERSION_CODE(4,6,0))
#define GS2_RAPIDJSON_DIAG_PUSH GS2_RAPIDJSON_DIAG_PRAGMA(push)
#define GS2_RAPIDJSON_DIAG_POP  GS2_RAPIDJSON_DIAG_PRAGMA(pop)
#else // GCC >= 4.2, < 4.6
#define GS2_RAPIDJSON_DIAG_PUSH /* ignored */
#define GS2_RAPIDJSON_DIAG_POP /* ignored */
#endif

#elif defined(_MSC_VER)

// pragma (MSVC specific)
#define GS2_RAPIDJSON_PRAGMA(x) __pragma(x)
#define GS2_RAPIDJSON_DIAG_PRAGMA(x) GS2_RAPIDJSON_PRAGMA(warning(x))

#define GS2_RAPIDJSON_DIAG_OFF(x) GS2_RAPIDJSON_DIAG_PRAGMA(disable: x)
#define GS2_RAPIDJSON_DIAG_PUSH GS2_RAPIDJSON_DIAG_PRAGMA(push)
#define GS2_RAPIDJSON_DIAG_POP  GS2_RAPIDJSON_DIAG_PRAGMA(pop)

#else

#define GS2_RAPIDJSON_DIAG_OFF(x) /* ignored */
#define GS2_RAPIDJSON_DIAG_PUSH   /* ignored */
#define GS2_RAPIDJSON_DIAG_POP    /* ignored */

#endif // GS2_RAPIDJSON_DIAG_*

///////////////////////////////////////////////////////////////////////////////
// C++11 features

#ifndef GS2_RAPIDJSON_HAS_CXX11_RVALUE_REFS
#if defined(__clang__)
#if __has_feature(cxx_rvalue_references) && \
    (defined(_LIBCPP_VERSION) || defined(__GLIBCXX__) && __GLIBCXX__ >= 20080306)
#define GS2_RAPIDJSON_HAS_CXX11_RVALUE_REFS 1
#else
#define GS2_RAPIDJSON_HAS_CXX11_RVALUE_REFS 0
#endif
#elif (defined(GS2_RAPIDJSON_GNUC) && (GS2_RAPIDJSON_GNUC >= GS2_RAPIDJSON_VERSION_CODE(4,3,0)) && defined(__GXX_EXPERIMENTAL_CXX0X__)) || \
      (defined(_MSC_VER) && _MSC_VER >= 1600)

#define GS2_RAPIDJSON_HAS_CXX11_RVALUE_REFS 1
#else
#define GS2_RAPIDJSON_HAS_CXX11_RVALUE_REFS 0
#endif
#endif // GS2_RAPIDJSON_HAS_CXX11_RVALUE_REFS

#ifndef GS2_RAPIDJSON_HAS_CXX11_NOEXCEPT
#if defined(__clang__)
#define GS2_RAPIDJSON_HAS_CXX11_NOEXCEPT __has_feature(cxx_noexcept)
#elif (defined(GS2_RAPIDJSON_GNUC) && (GS2_RAPIDJSON_GNUC >= GS2_RAPIDJSON_VERSION_CODE(4,6,0)) && defined(__GXX_EXPERIMENTAL_CXX0X__))
//    (defined(_MSC_VER) && _MSC_VER >= ????) // not yet supported
#define GS2_RAPIDJSON_HAS_CXX11_NOEXCEPT 1
#else
#define GS2_RAPIDJSON_HAS_CXX11_NOEXCEPT 0
#endif
#endif
#if GS2_RAPIDJSON_HAS_CXX11_NOEXCEPT
#define GS2_RAPIDJSON_NOEXCEPT noexcept
#else
#define GS2_RAPIDJSON_NOEXCEPT /* noexcept */
#endif // GS2_RAPIDJSON_HAS_CXX11_NOEXCEPT

// no automatic detection, yet
#ifndef GS2_RAPIDJSON_HAS_CXX11_TYPETRAITS
#define GS2_RAPIDJSON_HAS_CXX11_TYPETRAITS 0
#endif

#ifndef GS2_RAPIDJSON_HAS_CXX11_RANGE_FOR
#if defined(__clang__)
#define GS2_RAPIDJSON_HAS_CXX11_RANGE_FOR __has_feature(cxx_range_for)
#elif (defined(GS2_RAPIDJSON_GNUC) && (GS2_RAPIDJSON_GNUC >= GS2_RAPIDJSON_VERSION_CODE(4,3,0)) && defined(__GXX_EXPERIMENTAL_CXX0X__)) || \
      (defined(_MSC_VER) && _MSC_VER >= 1700)
#define GS2_RAPIDJSON_HAS_CXX11_RANGE_FOR 1
#else
#define GS2_RAPIDJSON_HAS_CXX11_RANGE_FOR 0
#endif
#endif // GS2_RAPIDJSON_HAS_CXX11_RANGE_FOR

//!@endcond

///////////////////////////////////////////////////////////////////////////////
// new/delete

#ifndef GS2_RAPIDJSON_NEW
///! customization point for global \c new
#define GS2_RAPIDJSON_NEW(x) new x
#endif
#ifndef GS2_RAPIDJSON_DELETE
///! customization point for global \c delete
#define GS2_RAPIDJSON_DELETE(x) delete x
#endif

///////////////////////////////////////////////////////////////////////////////
// Type

/*! \namespace rapidjson
    \brief main RapidJSON namespace
    \see GS2_RAPIDJSON_NAMESPACE
*/
GS2_RAPIDJSON_NAMESPACE_BEGIN

//! Type of JSON value
enum Type {
    kNullType = 0,      //!< null
    kFalseType = 1,     //!< false
    kTrueType = 2,      //!< true
    kObjectType = 3,    //!< object
    kArrayType = 4,     //!< array 
    kStringType = 5,    //!< string
    kNumberType = 6     //!< number
};

GS2_RAPIDJSON_NAMESPACE_END

#endif // GS2_RAPIDJSON_RAPIDJSON_H_
