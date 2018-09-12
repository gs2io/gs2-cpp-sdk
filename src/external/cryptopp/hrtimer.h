#ifndef GS2_CRYPTOPP_HRTIMER_H
#define GS2_CRYPTOPP_HRTIMER_H

#include "config.h"

#if !defined(HIGHRES_TIMER_AVAILABLE) || (defined(GS2_CRYPTOPP_WIN32_AVAILABLE) && !defined(THREAD_TIMER_AVAILABLE))
#include <time.h>
#endif

NAMESPACE_BEGIN(gs2)
NAMESPACE_BEGIN(detail)
NAMESPACE_BEGIN(CryptoPP)

#ifdef HIGHRES_TIMER_AVAILABLE
	typedef word64 TimerWord;
#else
	typedef clock_t TimerWord;
#endif

/// \brief Base class for timers
class GS2_CRYPTOPP_DLL GS2_CRYPTOPP_NO_VTABLE TimerBase
{
public:
	enum Unit {SECONDS = 0, MILLISECONDS, MICROSECONDS, NANOSECONDS};
	TimerBase(Unit unit, bool stuckAtZero)
		: m_timerUnit(unit), m_stuckAtZero(stuckAtZero), m_started(false)
		, m_start(0), m_last(0) {}

	virtual TimerWord GetCurrentTimerValue() =0;	// GetCurrentTime is a macro in MSVC 6.0
	virtual TimerWord TicksPerSecond() =0;	// this is not the resolution, just a conversion factor into seconds

	void StartTimer();
	double ElapsedTimeAsDouble();
	unsigned long ElapsedTime();

private:
	double ConvertTo(TimerWord t, Unit unit);

	Unit m_timerUnit;	// HPUX workaround: m_unit is a system macro on HPUX
	bool m_stuckAtZero, m_started;
	TimerWord m_start, m_last;
};

/// \brief Measure CPU time spent executing instructions of this thread (if supported by OS)
/// \note ThreadUserTimer only works correctly on Windows NT or later desktops and servers.
/// On Unix-based it reports process time. On Windows Phone and Windows Store it reports wall
/// clock time with performance counter precision. On all others it reports wall clock time.
class ThreadUserTimer : public TimerBase
{
public:
	ThreadUserTimer(Unit unit = TimerBase::SECONDS, bool stuckAtZero = false) : TimerBase(unit, stuckAtZero) {}
	TimerWord GetCurrentTimerValue();
	TimerWord TicksPerSecond();
};

/// high resolution timer
class GS2_CRYPTOPP_DLL Timer : public TimerBase
{
public:
	Timer(Unit unit = TimerBase::SECONDS, bool stuckAtZero = false)	: TimerBase(unit, stuckAtZero) {}
	TimerWord GetCurrentTimerValue();
	TimerWord TicksPerSecond();
};

NAMESPACE_END
NAMESPACE_END
NAMESPACE_END

#endif
