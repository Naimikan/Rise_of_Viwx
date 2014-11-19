#ifndef _CSTATE_HPP_
#define _CSTATE_HPP_

#include "../../Core/iGlobals.hpp"
#include "../../Core/EventListener/cEventListener.hpp"

class State : public EventListener {
	public:
		State();

		virtual void OnActivate() = 0;
		virtual void OnDeactivate() = 0;
		virtual void OnLoop() = 0;
		virtual OnRender(SDL_Surface* parSurface) = 0;
};






/*class State {
	public:
		State();
		virtual ~State();

		virtual void LoadState() = 0;
		virtual void ClearState() = 0;
		virtual void UpdateState() = 0;

		bool IsLoaded() { return isLoaded; }

	protected:
		bool isLoaded;
};*/


/*State(StateManager* parStateManager);
virtual ~State();

void setStateManager(StateManager* parStateManager) { stateManager = parStateManager; }

virtual void loadState() = 0;
virtual void clearState() = 0;
virtual void updateState(Ogre::Real parDeltaTime, bool parActive) = 0;

virtual bool keyPressed(const OIS::KeyEvent &parEvent) { return true; }
virtual bool keyReleased(const OIS::KeyEvent &parEvent) { return true; }

virtual bool mouseMoved(const OIS::MouseEvent &parArg) { return true; }
virtual bool mousePressed(const OIS::MouseEvent &parArg, OIS::MouseButtonID parID) { return true; }
virtual bool mouseReleased(const OIS::MouseEvent &parArg, OIS::MouseButtonID parID) { return true; }

virtual void buttonHit(OgreBites::Button *parButton) = 0;
virtual void itemSelected(OgreBites::SelectMenu* parMenu) = 0;
virtual void labelHit(OgreBites::Label* parLabel) = 0;
virtual void sliderMoved(OgreBites::Slider* parSlider) = 0;
virtual void checkBoxToggled(OgreBites::CheckBox* parCheckBox) = 0;
virtual void okDialogClosed(const Ogre::DisplayString& parMessage) = 0;
virtual void yesNoDialogClosed(const Ogre::DisplayString& parQuestion, bool parYesHit) = 0;

protected:
Ogre::Viewport* viewport;
Ogre::Camera* camera;

StateManager* stateManager;
//GameObjectManager* gameObjectManager;

bool isLoaded;

virtual void createCamera() = 0;
virtual void createViewports() = 0;*/

#endif // End _CSTATE_HPP_