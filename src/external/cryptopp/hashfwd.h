// hashfwd.h - written and placed in the public domain by Jeffrey Walton

/// \file hashfwd.h
/// \brief Forward declarations for hash functions used in signature encoding methods

#ifndef GS2_CRYPTOPP_HASHFWD_H
#define GS2_CRYPTOPP_HASHFWD_H

#include "config.h"

NAMESPACE_BEGIN(gs2)
NAMESPACE_BEGIN(detail)
NAMESPACE_BEGIN(CryptoPP)

class SHA1;
class SHA224;
class SHA256;
class SHA384;
class SHA512;

class SHA3_256;
class SHA3_384;
class SHA3_512;

class Tiger;
class RIPEMD128;
class RIPEMD160;
class Whirlpool;

namespace Weak1 {
  class MD2;
  class MD5;
}

NAMESPACE_END
NAMESPACE_END
NAMESPACE_END

#endif  // GS2_CRYPTOPP_HASHFWD_H
