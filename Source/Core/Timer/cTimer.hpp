#ifndef _CTIMER_HPP_
#define _CTIMER_HPP_

#include "SDL/SDL.h"

class Timer {
    public:
        Timer();
        ~Timer();

        void Start();
        void Stop();
        void Pause();
        void Resume();

        int GetTicks();

        bool IsStarted() { return isStarted; }
        bool IsPaused() { return isPaused; }

        void FrameRate();

        static const int FRAMES_PER_SECOND;

    private:
        int startTicks;
        int pausedTicks;

        bool isPaused;
        bool isStarted;
};

#endif // End _CTIMER_HPP_