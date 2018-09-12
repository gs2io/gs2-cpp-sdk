// dh2.cpp - originally written and placed in the public domain by Wei Dai

#include "pch.h"
#include "cryptlib.h"
#include "misc.h"
#include "dh2.h"

NAMESPACE_BEGIN(gs2)
NAMESPACE_BEGIN(detail)
NAMESPACE_BEGIN(CryptoPP)

#if defined(GS2_CRYPTOPP_DEBUG) && !defined(GS2_CRYPTOPP_DOXYGEN_PROCESSING)
struct NullCryptoParameters : public CryptoParameters
{
	void AssignFrom(const NameValuePairs &source) {
		GS2_CRYPTOPP_UNUSED(source);
	}
	bool Validate(RandomNumberGenerator &rng, unsigned int level) const {
		GS2_CRYPTOPP_UNUSED(rng); GS2_CRYPTOPP_UNUSED(level);
		return false;
	}
	bool GetVoidValue(const char *name, const std::type_info &valueType, void *pValue) const {
		GS2_CRYPTOPP_UNUSED(name); GS2_CRYPTOPP_UNUSED(valueType); GS2_CRYPTOPP_UNUSED(pValue);
		return false;
	}
};

struct NullSimpleKeyAgreementDomain : public TwoBases<NullCryptoParameters, SimpleKeyAgreementDomain>
{
	CryptoParameters & AccessCryptoParameters() {
		return *this;
	}
	unsigned int AgreedValueLength() const {
		return 1;
	}
	unsigned int PrivateKeyLength() const {
		return 1;
	}
	unsigned int PublicKeyLength() const {
		return 1;
	}
	void GeneratePrivateKey(RandomNumberGenerator &rng, byte *privateKey) const {
		GS2_CRYPTOPP_UNUSED(rng); GS2_CRYPTOPP_UNUSED(privateKey);
	}
	void GeneratePublicKey(RandomNumberGenerator &rng, const byte *privateKey, byte *publicKey) const {
		GS2_CRYPTOPP_UNUSED(rng); GS2_CRYPTOPP_UNUSED(privateKey); GS2_CRYPTOPP_UNUSED(publicKey);
	}
	bool Agree(byte *agreedValue, const byte *privateKey, const byte *otherPublicKey, bool validateOtherPublicKey=true) const {
		GS2_CRYPTOPP_UNUSED(agreedValue); GS2_CRYPTOPP_UNUSED(privateKey);
		GS2_CRYPTOPP_UNUSED(otherPublicKey); GS2_CRYPTOPP_UNUSED(validateOtherPublicKey);
		return false;
	}
};

void DH2_TestInstantiations()
{
	NullSimpleKeyAgreementDomain dom;
	DH2 dh(dom);
}
#endif

bool DH2::Agree(byte *agreedValue,
		const byte *staticSecretKey, const byte *ephemeralSecretKey,
		const byte *staticOtherPublicKey, const byte *ephemeralOtherPublicKey,
		bool validateStaticOtherPublicKey) const
{
	return d1.Agree(agreedValue, staticSecretKey, staticOtherPublicKey, validateStaticOtherPublicKey)
		&& d2.Agree(agreedValue+d1.AgreedValueLength(), ephemeralSecretKey, ephemeralOtherPublicKey, true);
}

NAMESPACE_END
NAMESPACE_END
NAMESPACE_END
