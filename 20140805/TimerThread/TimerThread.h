#ifndef TIMER_THREAD_H_
#define TIMER_THREAD_H_ 

#include <functional>
#include "Timer.h"
#include "Thread.h"
#include "NonCopyable.h"

class TimerThread : NonCopyable
{
	public:
		typedef std::function<void()> TimerCallback;

		void setTimer(int val, int interval);
		void setTimerCallback(const TimerCallback &callback);
		void startTimerThread();
		void cancelTimerThread();
	private:
		Timer timer_;
		Thread thread_;
};



#endif  /*TIMER_THREAD_H_*/
