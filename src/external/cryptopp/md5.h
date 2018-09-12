#ifndef GS2_CRYPTOPP_MD5_H
#define GS2_CRYPTOPP_MD5_H

#include "iterhash.h"

NAMESPACE_BEGIN(gs2)
NAMESPACE_BEGIN(detail)
NAMESPACE_BEGIN(CryptoPP)

namespace Weak1 {

/// \brief MD5 message digest
/// \sa <a href="http://www.cryptolounge.org/wiki/MD5">MD5</a>
/// \since Crypto++ 1.0
class MD5 : public IteratedHashWithStaticTransform<word32, LittleEndian, 64, 16, MD5>
{
public:
	static void InitState(HashWordType *state);
	static void Transform(word32 *digest, const word32 *data);
	GS2_CRYPTOPP_STATIC_CONSTEXPR const char* StaticAlgorithmName() {return "MD5";}
};

}
#if GS2_CRYPTOPP_ENABLE_NAMESPACE_WEAK >= 1
namespace Weak {using namespace Weak1;}		// import Weak1 into gs2::detail::CryptoPP::Weak
#else
using namespace Weak1;	// import Weak1 into CryptoPP with warning
#ifdef __GNUC__
#warning "You may be using a weak algorithm that has been retained for backwards compatibility. Please '#define GS2_CRYPTOPP_ENABLE_NAMESPACE_WEAK 1' before including this .h file and prepend the class name with 'Weak::' to remove this warning."
#else
#pragma message("You may be using a weak algorithm that has been retained for backwards compatibility. Please '#define GS2_CRYPTOPP_ENABLE_NAMESPACE_WEAK 1' before including this .h file and prepend the class name with 'Weak::' to remove this warning.")
#endif
#endif

NAMESPACE_END
NAMESPACE_END
NAMESPACE_END

#endif
