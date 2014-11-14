#include "cTimer.hpp"

const int Timer::FRAMES_PER_SECOND = 20;

Timer::Timer() : startTicks(0), pausedTicks(0), isStarted(false), isPaused(false) {

}

Timer::~Timer() {

}

void Timer::Start() {
    isStarted = true;
    isPaused = false;

    startTicks = SDL_GetTicks();
}

void Timer::Stop() {
    isStarted = false;
    isPaused = false;
}

void Timer::Pause() {
    if (isStarted && isPaused) {
        isPaused = true;

        pausedTicks = SDL_GetTicks() - startTicks;
    }
}

void Timer::Resume() {
    if (isPaused) {
        isPaused = false;

        startTicks = SDL_GetTicks() - pausedTicks;

        pausedTicks = 0;
    }
}

int Timer::GetTicks() {
    if (isStarted) {
        if (isPaused) {
            return pausedTicks;
        } else {
            return SDL_GetTicks() - startTicks;
        }
    }

    return 0;
}

void Timer::FrameRate() {
    if (GetTicks() < 1000 / Timer::FRAMES_PER_SECOND) {
        SDL_Delay((1000 / Timer::FRAMES_PER_SECOND) - GetTicks());
    }
}