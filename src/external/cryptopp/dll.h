// dll.h - originally written and placed in the public domain by Wei Dai

/// \file dll.h
/// \brief Functions and definitions required for building the FIPS-140 DLL on Windows

#ifndef GS2_CRYPTOPP_DLL_H
#define GS2_CRYPTOPP_DLL_H

#if !defined(GS2_CRYPTOPP_IMPORTS) && !defined(GS2_CRYPTOPP_EXPORTS) && !defined(GS2_CRYPTOPP_DEFAULT_NO_DLL)
#ifdef GS2_CRYPTOPP_CONFIG_H
#error To use the DLL version of Crypto++, this file must be included before any other Crypto++ header files.
#endif
#define GS2_CRYPTOPP_IMPORTS
#endif

#include "aes.h"
#include "cbcmac.h"
#include "ccm.h"
#include "cmac.h"
#include "channels.h"
#include "des.h"
#include "dh.h"
#include "dsa.h"
#include "ec2n.h"
#include "eccrypto.h"
#include "ecp.h"
#include "files.h"
#include "fips140.h"
#include "gcm.h"
#include "hex.h"
#include "hmac.h"
#include "modes.h"
#include "mqueue.h"
#include "nbtheory.h"
#include "osrng.h"
#include "pkcspad.h"
#include "pssr.h"
#include "randpool.h"
#include "rsa.h"
#include "rw.h"
#include "sha.h"
#include "skipjack.h"
#include "trdlocal.h"

#ifdef GS2_CRYPTOPP_IMPORTS

#ifdef _DLL
// cause CRT DLL to be initialized before Crypto++ so that we can use malloc and free during DllMain()
#ifdef GS2_CRYPTOPP_DEBUG
# pragma comment(lib, "msvcrtd")
# pragma comment(lib, "cryptopp")
#else
# pragma comment(lib, "msvcrt")
# pragma comment(lib, "cryptopp")
#endif
#endif

#endif		// #ifdef GS2_CRYPTOPP_IMPORTS

#include <new>	// for new_handler

NAMESPACE_BEGIN(gs2)
NAMESPACE_BEGIN(detail)
NAMESPACE_BEGIN(CryptoPP)

typedef void * (GS2_CRYPTOPP_API * PNew)(size_t);
typedef void (GS2_CRYPTOPP_API * PDelete)(void *);
typedef void (GS2_CRYPTOPP_API * PGetNewAndDelete)(PNew &, PDelete &);
typedef std::new_handler (GS2_CRYPTOPP_API * PSetNewHandler)(std::new_handler);
typedef void (GS2_CRYPTOPP_API * PSetNewAndDelete)(PNew, PDelete, PSetNewHandler);

NAMESPACE_END
NAMESPACE_END
NAMESPACE_END

#endif
