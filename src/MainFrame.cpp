#include "MainFrame.h"
#include "FormFactory.h"
#include "PanelFactory.h"
#include "AppResourceId.h"

using namespace Tizen::Base;
using namespace Tizen::Ui;
using namespace Tizen::Ui::Controls;
using namespace Tizen::Ui::Scenes;

MainFrame::MainFrame(void)
{
}

MainFrame::~MainFrame(void)
{
}

result
MainFrame::OnInitializing(void)
{
	// Prepare Scene management.
	SceneManager* pSceneManager = SceneManager::GetInstance();
	static FormFactory formFactory;
	static PanelFactory panelFactory;
	pSceneManager->RegisterFormFactory(formFactory);
	pSceneManager->RegisterPanelFactory(panelFactory);
	pSceneManager->RegisterScene(L"workflow");

	// Goto the scene.
	result r = pSceneManager->GoForward(SceneTransitionId(TR_SPLASH));
	
	return r;
}

result
MainFrame::OnTerminating(void)
{
	result r = E_SUCCESS;

	return r;
}
