#ifndef GS2_CRYPTOPP_TRDLOCAL_H
#define GS2_CRYPTOPP_TRDLOCAL_H

#include "config.h"

#if !defined(NO_OS_DEPENDENCE) && defined(THREADS_AVAILABLE)

#include "misc.h"

#ifdef HAS_WINTHREADS
typedef unsigned long ThreadLocalIndexType;
#else
#include <pthread.h>
typedef pthread_key_t ThreadLocalIndexType;
#endif

NAMESPACE_BEGIN(gs2)
NAMESPACE_BEGIN(detail)
NAMESPACE_BEGIN(CryptoPP)

/// thread local storage
class GS2_CRYPTOPP_DLL ThreadLocalStorage : public NotCopyable
{
public:
	/// exception thrown by ThreadLocalStorage class
	class Err : public OS_Error
	{
	public:
		Err(const std::string& operation, int error);
	};

	ThreadLocalStorage();
	~ThreadLocalStorage() GS2_CRYPTOPP_THROW;

	void SetValue(void *value);
	void *GetValue() const;

private:
	ThreadLocalIndexType m_index;
};

NAMESPACE_END
NAMESPACE_END
NAMESPACE_END

#endif	// THREADS_AVAILABLE

#endif  // GS2_CRYPTOPP_TRDLOCAL_H
