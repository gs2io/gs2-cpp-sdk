// fips140.cpp - originally written and placed in the public domain by Wei Dai

#include "pch.h"

#ifndef GS2_CRYPTOPP_IMPORTS

#include "fips140.h"
#include "misc.h"
#include "trdlocal.h"	// needs to be included last for cygwin

NAMESPACE_BEGIN(gs2)
NAMESPACE_BEGIN(detail)
NAMESPACE_BEGIN(CryptoPP)

// Define this to 1 to turn on FIPS 140-2 compliance features, including additional tests during
// startup, random number generation, and key generation. These tests may affect performance.
#ifndef GS2_CRYPTOPP_ENABLE_COMPLIANCE_WITH_FIPS_140_2
#define GS2_CRYPTOPP_ENABLE_COMPLIANCE_WITH_FIPS_140_2 0
#endif

#if (GS2_CRYPTOPP_ENABLE_COMPLIANCE_WITH_FIPS_140_2 && !defined(THREADS_AVAILABLE))
#error FIPS 140-2 compliance requires the availability of thread local storage.
#endif

#if (GS2_CRYPTOPP_ENABLE_COMPLIANCE_WITH_FIPS_140_2 && !defined(OS_RNG_AVAILABLE))
#error FIPS 140-2 compliance requires the availability of OS provided RNG.
#endif

PowerUpSelfTestStatus g_powerUpSelfTestStatus = POWER_UP_SELF_TEST_NOT_DONE;

bool FIPS_140_2_ComplianceEnabled()
{
	return GS2_CRYPTOPP_ENABLE_COMPLIANCE_WITH_FIPS_140_2;
}

void SimulatePowerUpSelfTestFailure()
{
	g_powerUpSelfTestStatus = POWER_UP_SELF_TEST_FAILED;
}

PowerUpSelfTestStatus GS2_CRYPTOPP_API GetPowerUpSelfTestStatus()
{
	return g_powerUpSelfTestStatus;
}

#if GS2_CRYPTOPP_ENABLE_COMPLIANCE_WITH_FIPS_140_2
ThreadLocalStorage & AccessPowerUpSelfTestInProgress()
{
	static ThreadLocalStorage selfTestInProgress;
	return selfTestInProgress;
}
#endif

bool PowerUpSelfTestInProgressOnThisThread()
{
#if GS2_CRYPTOPP_ENABLE_COMPLIANCE_WITH_FIPS_140_2
	return AccessPowerUpSelfTestInProgress().GetValue() != NULLPTR;
#else
	GS2_CRYPTOPP_ASSERT(false);	// should not be called
	return false;
#endif
}

void SetPowerUpSelfTestInProgressOnThisThread(bool inProgress)
{
	GS2_CRYPTOPP_UNUSED(inProgress);
#if GS2_CRYPTOPP_ENABLE_COMPLIANCE_WITH_FIPS_140_2
	AccessPowerUpSelfTestInProgress().SetValue((void *)inProgress);
#endif
}

void EncryptionPairwiseConsistencyTest_FIPS_140_Only(const PK_Encryptor &encryptor, const PK_Decryptor &decryptor)
{
	GS2_CRYPTOPP_UNUSED(encryptor), GS2_CRYPTOPP_UNUSED(decryptor);
#if GS2_CRYPTOPP_ENABLE_COMPLIANCE_WITH_FIPS_140_2
	EncryptionPairwiseConsistencyTest(encryptor, decryptor);
#endif
}

void SignaturePairwiseConsistencyTest_FIPS_140_Only(const PK_Signer &signer, const PK_Verifier &verifier)
{
	GS2_CRYPTOPP_UNUSED(signer), GS2_CRYPTOPP_UNUSED(verifier);
#if GS2_CRYPTOPP_ENABLE_COMPLIANCE_WITH_FIPS_140_2
	SignaturePairwiseConsistencyTest(signer, verifier);
#endif
}

NAMESPACE_END
NAMESPACE_END
NAMESPACE_END

#endif
