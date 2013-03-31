#include "cantataFrame.h"
#include "cantataFormFactory.h"
#include "cantataPanelFactory.h"
#include "AppResourceId.h"

using namespace Tizen::Base;
using namespace Tizen::Ui;
using namespace Tizen::Ui::Controls;
using namespace Tizen::Ui::Scenes;

cantataFrame::cantataFrame(void)
{
}

cantataFrame::~cantataFrame(void)
{
}

result
cantataFrame::OnInitializing(void)
{
	// Prepare Scene management.
	SceneManager* pSceneManager = SceneManager::GetInstance();
	static cantataFormFactory formFactory;
	static cantataPanelFactory panelFactory;
	pSceneManager->RegisterFormFactory(formFactory);
	pSceneManager->RegisterPanelFactory(panelFactory);
	pSceneManager->RegisterScene(L"workflow");

	// Goto the scene.
	result r = pSceneManager->GoForward(SceneTransitionId(TR_SPLASH));
	

	// TODO: Add your initialization code here
	return r;
}

result
cantataFrame::OnTerminating(void)
{
	result r = E_SUCCESS;

	// TODO:
	// Add your termination code here
	return r;
}
