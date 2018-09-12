// rijndael.h - originally written and placed in the public domain by Wei Dai

/// \file rijndael.h
/// \brief Classes for Rijndael encryption algorithm
/// \details All key sizes are supported. The library only provides Rijndael with 128-bit blocks,
///   and not 192-bit or 256-bit blocks
/// \since Rijndael since Crypto++ 3.1, Intel AES-NI since Crypto++ 5.6.1, ARMv8 AES since Crypto++ 6.0,
///   Power8 AES since Crypto++ 6.0

#ifndef GS2_CRYPTOPP_RIJNDAEL_H
#define GS2_CRYPTOPP_RIJNDAEL_H

#include "seckey.h"
#include "secblock.h"

#if GS2_CRYPTOPP_BOOL_X64 || GS2_CRYPTOPP_BOOL_X32 || GS2_CRYPTOPP_BOOL_X86 || GS2_CRYPTOPP_BOOL_ARM32 || \
	GS2_CRYPTOPP_BOOL_ARM64 || GS2_CRYPTOPP_BOOL_PPC32 || GS2_CRYPTOPP_BOOL_PPC64
# define GS2_CRYPTOPP_RIJNDAEL_ADVANCED_PROCESS_BLOCKS 1
#endif

NAMESPACE_BEGIN(gs2)
NAMESPACE_BEGIN(detail)
NAMESPACE_BEGIN(CryptoPP)

/// \brief Rijndael block cipher information
/// \details All key sizes are supported. The library only provides Rijndael with 128-bit blocks,
///   and not 192-bit or 256-bit blocks
/// \since Rijndael since Crypto++ 3.1, Intel AES-NI since Crypto++ 5.6.1, ARMv8 AES since Crypto++ 6.0,
///   Power8 AES since Crypto++ 6.0
struct Rijndael_Info : public FixedBlockSize<16>, public VariableKeyLength<16, 16, 32, 8>
{
	GS2_CRYPTOPP_DLL static const char * GS2_CRYPTOPP_API StaticAlgorithmName() {return GS2_CRYPTOPP_RIJNDAEL_NAME;}
};

/// \brief Rijndael block cipher
/// \details All key sizes are supported. The library only provides Rijndael with 128-bit blocks,
///   and not 192-bit or 256-bit blocks
/// \since Rijndael since Crypto++ 3.1, Intel AES-NI since Crypto++ 5.6.1, ARMv8 AES since Crypto++ 6.0,
///   Power8 AES since Crypto++ 6.0
/// \sa <a href="http://www.cryptopp.com/wiki/Rijndael">Rijndael</a>
class GS2_CRYPTOPP_DLL Rijndael : public Rijndael_Info, public BlockCipherDocumentation
{
	/// \brief Rijndael block cipher transformation functions
	/// \details Provides implementation common to encryption and decryption
	class GS2_CRYPTOPP_DLL GS2_CRYPTOPP_NO_VTABLE Base : public BlockCipherImpl<Rijndael_Info>
	{
	public:
		void UncheckedSetKey(const byte *userKey, unsigned int keyLength, const NameValuePairs &params);

	protected:
		static void FillEncTable();
		static void FillDecTable();

		// VS2005 workaround: have to put these on separate lines, or error C2487 is triggered in DLL build
		static const byte Se[256];
		static const byte Sd[256];

		static const word32 rcon[];

		unsigned int m_rounds;
		FixedSizeAlignedSecBlock<word32, 4*15> m_key;
		mutable SecByteBlock m_aliasBlock;
	};

	/// \brief Provides implementation for encryption transformation
	/// \details Enc provides implementation for encryption transformation. All key sizes are supported.
	///   The library only provides Rijndael with 128-bit blocks, and not 192-bit or 256-bit blocks
	/// \since Rijndael since Crypto++ 3.1, Intel AES-NI since Crypto++ 5.6.1, ARMv8 AES since Crypto++ 6.0,
	///   Power8 AES since Crypto++ 6.0
	class GS2_CRYPTOPP_DLL GS2_CRYPTOPP_NO_VTABLE Enc : public Base
	{
	public:
		void ProcessAndXorBlock(const byte *inBlock, const byte *xorBlock, byte *outBlock) const;
#if GS2_CRYPTOPP_RIJNDAEL_ADVANCED_PROCESS_BLOCKS
		size_t AdvancedProcessBlocks(const byte *inBlocks, const byte *xorBlocks, byte *outBlocks, size_t length, word32 flags) const;
#endif
	};

	/// \brief Provides implementation for decryption transformation
	/// \details Dec provides implementation for decryption transformation. All key sizes are supported.
	///   The library only provides Rijndael with 128-bit blocks, and not 192-bit or 256-bit blocks
	/// \since Rijndael since Crypto++ 3.1, Intel AES-NI since Crypto++ 5.6.1, ARMv8 AES since Crypto++ 6.0,
	///   Power8 AES since Crypto++ 6.0
	class GS2_CRYPTOPP_DLL GS2_CRYPTOPP_NO_VTABLE Dec : public Base
	{
	public:
		void ProcessAndXorBlock(const byte *inBlock, const byte *xorBlock, byte *outBlock) const;
#if GS2_CRYPTOPP_RIJNDAEL_ADVANCED_PROCESS_BLOCKS
		size_t AdvancedProcessBlocks(const byte *inBlocks, const byte *xorBlocks, byte *outBlocks, size_t length, word32 flags) const;
#endif
	};

public:
	typedef BlockCipherFinal<ENCRYPTION, Enc> Encryption;
	typedef BlockCipherFinal<DECRYPTION, Dec> Decryption;
};

typedef Rijndael::Encryption RijndaelEncryption;
typedef Rijndael::Decryption RijndaelDecryption;

NAMESPACE_END
NAMESPACE_END
NAMESPACE_END

#endif
