// elgamal.cpp - originally written and placed in the public domain by Wei Dai

#include "pch.h"
#include "elgamal.h"
#include "asn.h"
#include "nbtheory.h"

NAMESPACE_BEGIN(gs2)
NAMESPACE_BEGIN(detail)
NAMESPACE_BEGIN(CryptoPP)

#if defined(GS2_CRYPTOPP_DEBUG) && !defined(GS2_CRYPTOPP_DOXYGEN_PROCESSING)
void ElGamal_TestInstantiations()
{
	ElGamalEncryptor test1(1, 1, 1);
	ElGamalDecryptor test2(NullRNG(), 123);
	ElGamalEncryptor test3(test2);
}
#endif

NAMESPACE_END
NAMESPACE_END
NAMESPACE_END
