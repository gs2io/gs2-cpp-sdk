// argnames.h - originally written and placed in the public domain by Wei Dai

/// \file argnames.h
/// \brief Standard names for retrieving values by name when working with \p NameValuePairs

#ifndef GS2_CRYPTOPP_ARGNAMES_H
#define GS2_CRYPTOPP_ARGNAMES_H

#include "cryptlib.h"

NAMESPACE_BEGIN(gs2)
NAMESPACE_BEGIN(detail)
NAMESPACE_BEGIN(CryptoPP)

DOCUMENTED_NAMESPACE_BEGIN(Name)

#define GS2_CRYPTOPP_DEFINE_NAME_STRING(name)	inline const char *name() {return #name;}

GS2_CRYPTOPP_DEFINE_NAME_STRING(ValueNames)			///< string, a list of value names with a semicolon (';') after each name
GS2_CRYPTOPP_DEFINE_NAME_STRING(Version)			///< int
GS2_CRYPTOPP_DEFINE_NAME_STRING(Seed)				///< ConstByteArrayParameter
GS2_CRYPTOPP_DEFINE_NAME_STRING(Key)				///< ConstByteArrayParameter
GS2_CRYPTOPP_DEFINE_NAME_STRING(IV)					///< ConstByteArrayParameter, also accepts const byte * for backwards compatibility
GS2_CRYPTOPP_DEFINE_NAME_STRING(StolenIV)			///< byte *
GS2_CRYPTOPP_DEFINE_NAME_STRING(Nonce)				///< ConstByteArrayParameter
GS2_CRYPTOPP_DEFINE_NAME_STRING(Rounds)				///< int
GS2_CRYPTOPP_DEFINE_NAME_STRING(FeedbackSize)		///< int
GS2_CRYPTOPP_DEFINE_NAME_STRING(WordSize)			///< int, in bytes
GS2_CRYPTOPP_DEFINE_NAME_STRING(BlockSize)			///< int, in bytes
GS2_CRYPTOPP_DEFINE_NAME_STRING(EffectiveKeyLength)	///< int, in bits
GS2_CRYPTOPP_DEFINE_NAME_STRING(KeySize)			///< int, in bits
GS2_CRYPTOPP_DEFINE_NAME_STRING(ModulusSize)		///< int, in bits
GS2_CRYPTOPP_DEFINE_NAME_STRING(SubgroupOrderSize)	///< int, in bits
GS2_CRYPTOPP_DEFINE_NAME_STRING(PrivateExponentSize)///< int, in bits
GS2_CRYPTOPP_DEFINE_NAME_STRING(Modulus)			///< Integer
GS2_CRYPTOPP_DEFINE_NAME_STRING(PublicExponent)		///< Integer
GS2_CRYPTOPP_DEFINE_NAME_STRING(PrivateExponent)	///< Integer
GS2_CRYPTOPP_DEFINE_NAME_STRING(PublicElement)		///< Integer
GS2_CRYPTOPP_DEFINE_NAME_STRING(SubgroupOrder)		///< Integer
GS2_CRYPTOPP_DEFINE_NAME_STRING(Cofactor)			///< Integer
GS2_CRYPTOPP_DEFINE_NAME_STRING(SubgroupGenerator)	///< Integer, ECP::Point, or EC2N::Point
GS2_CRYPTOPP_DEFINE_NAME_STRING(Curve)				///< ECP or EC2N
GS2_CRYPTOPP_DEFINE_NAME_STRING(GroupOID)			///< OID
GS2_CRYPTOPP_DEFINE_NAME_STRING(PointerToPrimeSelector)		///< const PrimeSelector *
GS2_CRYPTOPP_DEFINE_NAME_STRING(Prime1)				///< Integer
GS2_CRYPTOPP_DEFINE_NAME_STRING(Prime2)				///< Integer
GS2_CRYPTOPP_DEFINE_NAME_STRING(ModPrime1PrivateExponent)	///< Integer
GS2_CRYPTOPP_DEFINE_NAME_STRING(ModPrime2PrivateExponent)	///< Integer
GS2_CRYPTOPP_DEFINE_NAME_STRING(MultiplicativeInverseOfPrime2ModPrime1)	///< Integer
GS2_CRYPTOPP_DEFINE_NAME_STRING(QuadraticResidueModPrime1)	///< Integer
GS2_CRYPTOPP_DEFINE_NAME_STRING(QuadraticResidueModPrime2)	///< Integer
GS2_CRYPTOPP_DEFINE_NAME_STRING(PutMessage)			///< bool
GS2_CRYPTOPP_DEFINE_NAME_STRING(TruncatedDigestSize)	///< int
GS2_CRYPTOPP_DEFINE_NAME_STRING(BlockPaddingScheme)	///< StreamTransformationFilter::BlockPaddingScheme
GS2_CRYPTOPP_DEFINE_NAME_STRING(HashVerificationFilterFlags)		///< word32
GS2_CRYPTOPP_DEFINE_NAME_STRING(AuthenticatedDecryptionFilterFlags)	///< word32
GS2_CRYPTOPP_DEFINE_NAME_STRING(SignatureVerificationFilterFlags)	///< word32
GS2_CRYPTOPP_DEFINE_NAME_STRING(InputBuffer)		///< ConstByteArrayParameter
GS2_CRYPTOPP_DEFINE_NAME_STRING(OutputBuffer)		///< ByteArrayParameter
GS2_CRYPTOPP_DEFINE_NAME_STRING(InputFileName)		///< const char *
GS2_CRYPTOPP_DEFINE_NAME_STRING(InputFileNameWide)	///< const wchar_t *
GS2_CRYPTOPP_DEFINE_NAME_STRING(InputStreamPointer)	///< std::istream *
GS2_CRYPTOPP_DEFINE_NAME_STRING(InputBinaryMode)	///< bool
GS2_CRYPTOPP_DEFINE_NAME_STRING(OutputFileName)		///< const char *
GS2_CRYPTOPP_DEFINE_NAME_STRING(OutputFileNameWide)	///< const wchar_t *
GS2_CRYPTOPP_DEFINE_NAME_STRING(OutputStreamPointer)	///< std::ostream *
GS2_CRYPTOPP_DEFINE_NAME_STRING(OutputBinaryMode)	///< bool
GS2_CRYPTOPP_DEFINE_NAME_STRING(EncodingParameters)	///< ConstByteArrayParameter
GS2_CRYPTOPP_DEFINE_NAME_STRING(KeyDerivationParameters)	///< ConstByteArrayParameter
GS2_CRYPTOPP_DEFINE_NAME_STRING(Separator)			///< ConstByteArrayParameter
GS2_CRYPTOPP_DEFINE_NAME_STRING(Terminator)			///< ConstByteArrayParameter
GS2_CRYPTOPP_DEFINE_NAME_STRING(Uppercase)			///< bool
GS2_CRYPTOPP_DEFINE_NAME_STRING(GroupSize)			///< int
GS2_CRYPTOPP_DEFINE_NAME_STRING(Pad)				///< bool
GS2_CRYPTOPP_DEFINE_NAME_STRING(PaddingByte)		///< byte
GS2_CRYPTOPP_DEFINE_NAME_STRING(Log2Base)			///< int
GS2_CRYPTOPP_DEFINE_NAME_STRING(EncodingLookupArray)	///< const byte *
GS2_CRYPTOPP_DEFINE_NAME_STRING(DecodingLookupArray)	///< const byte *
GS2_CRYPTOPP_DEFINE_NAME_STRING(InsertLineBreaks)	///< bool
GS2_CRYPTOPP_DEFINE_NAME_STRING(MaxLineLength)		///< int
GS2_CRYPTOPP_DEFINE_NAME_STRING(DigestSize)			///< int, in bytes
GS2_CRYPTOPP_DEFINE_NAME_STRING(L1KeyLength)		///< int, in bytes
GS2_CRYPTOPP_DEFINE_NAME_STRING(TableSize)			///< int, in bytes
GS2_CRYPTOPP_DEFINE_NAME_STRING(Blinding)			///< bool, timing attack mitigations, ON by default
GS2_CRYPTOPP_DEFINE_NAME_STRING(DerivedKey)			///< ByteArrayParameter, key derivation, derived key
GS2_CRYPTOPP_DEFINE_NAME_STRING(DerivedKeyLength)	///< int, key derivation, derived key length in bytes
GS2_CRYPTOPP_DEFINE_NAME_STRING(Personalization)	///< ConstByteArrayParameter
GS2_CRYPTOPP_DEFINE_NAME_STRING(PersonalizationSize)	///< int, in bytes
GS2_CRYPTOPP_DEFINE_NAME_STRING(Salt)				///< ConstByteArrayParameter
GS2_CRYPTOPP_DEFINE_NAME_STRING(Tweak)				///< ConstByteArrayParameter
GS2_CRYPTOPP_DEFINE_NAME_STRING(SaltSize)			///< int, in bytes
GS2_CRYPTOPP_DEFINE_NAME_STRING(TreeMode)			///< byte
GS2_CRYPTOPP_DEFINE_NAME_STRING(FileName)			///< const char *
GS2_CRYPTOPP_DEFINE_NAME_STRING(FileTime)			///< int
GS2_CRYPTOPP_DEFINE_NAME_STRING(Comment)			///< const char *
GS2_CRYPTOPP_DEFINE_NAME_STRING(Identity)			///< ConstByteArrayParameter
DOCUMENTED_NAMESPACE_END

NAMESPACE_END
NAMESPACE_END
NAMESPACE_END

#endif
