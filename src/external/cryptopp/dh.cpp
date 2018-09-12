// dh.cpp - originally written and placed in the public domain by Wei Dai

#include "pch.h"

#ifndef GS2_CRYPTOPP_IMPORTS

#include "dh.h"

NAMESPACE_BEGIN(gs2)
NAMESPACE_BEGIN(detail)
NAMESPACE_BEGIN(CryptoPP)

#if defined(GS2_CRYPTOPP_DEBUG) && !defined(GS2_CRYPTOPP_DOXYGEN_PROCESSING)
void DH_TestInstantiations()
{
	DH dh1;
	DH dh2(NullRNG(), 10);
}
#endif

NAMESPACE_END
NAMESPACE_END
NAMESPACE_END

#endif
