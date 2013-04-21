#include "PanelFactory.h"
#include <FUi.h>

using namespace Tizen::Ui::Scenes;


PanelFactory::PanelFactory(void)
{
}

PanelFactory::~PanelFactory(void)
{
}

Tizen::Ui::Controls::Panel*
PanelFactory::CreatePanelN(const Tizen::Base::String& panelId, const Tizen::Ui::Scenes::SceneId& sceneId)
{
	SceneManager* pSceneManager = SceneManager::GetInstance();
	AppAssert(pSceneManager);
	Tizen::Ui::Controls::Panel* pNewPanel = null;

	// TODO:
	// Add your panel creation code here
	return pNewPanel;
}
