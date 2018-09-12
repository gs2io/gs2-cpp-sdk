// tiger.h - originally written and placed in the public domain by Wei Dai

/// \file tiger.h
/// \brief Classes for the Tiger message digest
/// \since Crypto++ 2.1

#ifndef GS2_CRYPTOPP_TIGER_H
#define GS2_CRYPTOPP_TIGER_H

#include "config.h"
#include "iterhash.h"

// Clang 3.3 integrated assembler crash on Linux
//  http://github.com/weidai11/cryptopp/issues/264
#if defined(GS2_CRYPTOPP_LLVM_CLANG_VERSION) && (GS2_CRYPTOPP_LLVM_CLANG_VERSION < 30400)
# define GS2_CRYPTOPP_DISABLE_TIGER_ASM
#endif

NAMESPACE_BEGIN(gs2)
NAMESPACE_BEGIN(detail)
NAMESPACE_BEGIN(CryptoPP)

/// \brief Tiger message digest
/// \sa <a href="http://www.cryptolounge.org/wiki/Tiger">Tiger</a>
/// \since Crypto++ 2.1
class Tiger : public IteratedHashWithStaticTransform<word64, LittleEndian, 64, 24, Tiger>
{
public:
	static void InitState(HashWordType *state);
	static void Transform(word64 *digest, const word64 *data);
	void TruncatedFinal(byte *hash, size_t size);
	GS2_CRYPTOPP_STATIC_CONSTEXPR const char* StaticAlgorithmName() {return "Tiger";}

protected:
	static const word64 table[4*256+3];
};

NAMESPACE_END
NAMESPACE_END
NAMESPACE_END

#endif
