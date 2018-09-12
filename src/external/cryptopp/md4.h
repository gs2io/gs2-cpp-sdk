#ifndef GS2_CRYPTOPP_MD4_H
#define GS2_CRYPTOPP_MD4_H

#include "iterhash.h"

NAMESPACE_BEGIN(gs2)
NAMESPACE_BEGIN(detail)
NAMESPACE_BEGIN(CryptoPP)

namespace Weak1 {

/// <a href="http://www.weidai.com/scan-mirror/md.html#MD4">MD4</a>
/*! \warning MD4 is considered insecure, and should not be used
	unless you absolutely need it for compatibility. */
class MD4 : public IteratedHashWithStaticTransform<word32, LittleEndian, 64, 16, MD4>
{
public:
	static void InitState(HashWordType *state);
	static void Transform(word32 *digest, const word32 *data);
	GS2_CRYPTOPP_STATIC_CONSTEXPR const char* StaticAlgorithmName() {return "MD4";}
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
