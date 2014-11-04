#include "cEvent.hpp"

Event::Event() {

}

Event::~Event() {

}

void Event::OnEvent(SDL_Event* parEvent) {
    switch(parEvent->type) {
        case SDL_ACTIVEEVENT: {
            switch(parEvent->active.state) {
                case SDL_APPMOUSEFOCUS: {
                    if (parEvent->active.gain) {
                    	OnMouseFocus();
                    } else {
                    	OnMouseBlur();
                    }

                    break;
                }
                case SDL_APPINPUTFOCUS: {
                    if (parEvent->active.gain) {
                    	OnInputFocus();
                    } else {
                    	OnInputBlur();
                    }

                    break;
                }
                case SDL_APPACTIVE: {
                    if (parEvent->active.gain) {
                    	OnRestore();
                    } else {
                    	OnMinimize();
                    }

                    break;
                }
            }
            break;
        }

        case SDL_KEYDOWN: {
            OnKeyDown(parEvent->key.keysym.sym, parEvent->key.keysym.mod, parEvent->key.keysym.unicode);
            break;
        }

        case SDL_KEYUP: {
            OnKeyUp(parEvent->key.keysym.sym, parEvent->key.keysym.mod, parEvent->key.keysym.unicode);
            break;
        }

        case SDL_MOUSEMOTION: {
            OnMouseMove(parEvent->motion.x, parEvent->motion.y, parEvent->motion.xrel, parEvent->motion.yrel, (parEvent->motion.state & SDL_BUTTON(SDL_BUTTON_LEFT)) != 0, (parEvent->motion.state & SDL_BUTTON(SDL_BUTTON_RIGHT)) != 0, (parEvent->motion.state & SDL_BUTTON(SDL_BUTTON_MIDDLE)) != 0);
            break;
        }

        case SDL_MOUSEBUTTONDOWN: {
            switch(parEvent->button.button) {
                case SDL_BUTTON_LEFT: {
                    OnLButtonDown(parEvent->button.x, parEvent->button.y);
                    break;
                }
                case SDL_BUTTON_RIGHT: {
                    OnRButtonDown(parEvent->button.x, parEvent->button.y);
                    break;
                }
                case SDL_BUTTON_MIDDLE: {
                    OnMButtonDown(parEvent->button.x, parEvent->button.y);
                    break;
                }
            }
            break;
        }

        case SDL_MOUSEBUTTONUP:    {
            switch(parEvent->button.button) {
                case SDL_BUTTON_LEFT: {
                    OnLButtonUp(parEvent->button.x, parEvent->button.y);
                    break;
                }
                case SDL_BUTTON_RIGHT: {
                    OnRButtonUp(parEvent->button.x, parEvent->button.y);
                    break;
                }
                case SDL_BUTTON_MIDDLE: {
                    OnMButtonUp(parEvent->button.x, parEvent->button.y);
                    break;
                }
            }
            break;
        }

        case SDL_JOYAXISMOTION: {
            OnJoyAxis(parEvent->jaxis.which, parEvent->jaxis.axis, parEvent->jaxis.value);
            break;
        }

        case SDL_JOYBALLMOTION: {
            OnJoyBall(parEvent->jball.which, parEvent->jball.ball, parEvent->jball.xrel, parEvent->jball.yrel);
            break;
        }

        case SDL_JOYHATMOTION: {
            OnJoyHat(parEvent->jhat.which, parEvent->jhat.hat, parEvent->jhat.value);
            break;
        }
        case SDL_JOYBUTTONDOWN: {
            OnJoyButtonDown(parEvent->jbutton.which, parEvent->jbutton.button);
            break;
        }

        case SDL_JOYBUTTONUP: {
            OnJoyButtonUp(parEvent->jbutton.which, parEvent->jbutton.button);
            break;
        }

        case SDL_QUIT: {
            OnExit();
            break;
        }

        case SDL_SYSWMEVENT: {
            //Ignore
            break;
        }

        case SDL_VIDEORESIZE: {
            OnResize(parEvent->resize.w, parEvent->resize.h);
            break;
        }

        case SDL_VIDEOEXPOSE: {
            OnExpose();
            break;
        }

        default: {
            OnUser(parEvent->user.type, parEvent->user.code, parEvent->user.data1, parEvent->user.data2);
            break;
        }
    }
}

void Event::OnInputFocus() {
    //Pure virtual, do nothing
}

void Event::OnInputBlur() {
    //Pure virtual, do nothing
}

void Event::OnKeyDown(SDLKey sym, SDLMod mod, Uint16 unicode) {
    //Pure virtual, do nothing
}

void Event::OnKeyUp(SDLKey sym, SDLMod mod, Uint16 unicode) {
    //Pure virtual, do nothing
}

void Event::OnMouseFocus() {
    //Pure virtual, do nothing
}

void Event::OnMouseBlur() {
    //Pure virtual, do nothing
}

void Event::OnMouseMove(int mX, int mY, int relX, int relY, bool Left,bool Right,bool Middle) {
    //Pure virtual, do nothing
}

void Event::OnMouseWheel(bool Up, bool Down) {
    //Pure virtual, do nothing
}

void Event::OnLButtonDown(int mX, int mY) {
    //Pure virtual, do nothing
}

void Event::OnLButtonUp(int mX, int mY) {
    //Pure virtual, do nothing
}

void Event::OnRButtonDown(int mX, int mY) {
    //Pure virtual, do nothing
}

void Event::OnRButtonUp(int mX, int mY) {
    //Pure virtual, do nothing
}

void Event::OnMButtonDown(int mX, int mY) {
    //Pure virtual, do nothing
}

void Event::OnMButtonUp(int mX, int mY) {
    //Pure virtual, do nothing
}

void Event::OnJoyAxis(Uint8 which,Uint8 axis,Sint16 value) {
    //Pure virtual, do nothing
}

void Event::OnJoyButtonDown(Uint8 which,Uint8 button) {
    //Pure virtual, do nothing
}

void Event::OnJoyButtonUp(Uint8 which,Uint8 button) {
    //Pure virtual, do nothing
}

void Event::OnJoyHat(Uint8 which,Uint8 hat,Uint8 value) {
    //Pure virtual, do nothing
}

void Event::OnJoyBall(Uint8 which,Uint8 ball,Sint16 xrel,Sint16 yrel) {
    //Pure virtual, do nothing
}

void Event::OnMinimize() {
    //Pure virtual, do nothing
}

void Event::OnRestore() {
    //Pure virtual, do nothing
}

void Event::OnResize(int w, int h) {
    //Pure virtual, do nothing
}

void Event::OnExpose() {
    //Pure virtual, do nothing
}

void Event::OnExit() {
    //Pure virtual, do nothing
}

void Event::OnUser(Uint8 type, int code, void* data1, void* data2) {
    //Pure virtual, do nothing
}
