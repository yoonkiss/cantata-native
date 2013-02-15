#include <FApp.h>
#include "cantataMainForm.h"
#include "CantataWifiManager.h"

using namespace Tizen::Base;
using namespace Tizen::App;
using namespace Tizen::Ui;
using namespace Tizen::Ui::Controls;
using namespace Tizen::Ui::Scenes;


cantataMainForm::cantataMainForm(void)
{
	pNode = new CantataNode;
	pNode->Construct();
}

cantataMainForm::~cantataMainForm(void)
{
	delete pNode;
}

bool
cantataMainForm::Initialize(void)
{
	Construct(L"IDF_FORM");

	return true;
}

result
cantataMainForm::OnInitializing(void)
{
	result r = E_SUCCESS;

	// TODO:
	// Add your initialization code here

	// Setup back event listener
	SetFormBackEventListener(this);

	// Get a button via resource ID
	Tizen::Ui::Controls::Button *pButtonOk = static_cast<Button*>(GetControl(L"IDC_BUTTON_OK"));
	if (pButtonOk != null)
	{
		pButtonOk->SetActionId(ID_BUTTON_OK);
		pButtonOk->AddActionEventListener(*this);
	}

	return r;
}

result
cantataMainForm::OnTerminating(void)
{
	result r = E_SUCCESS;

	// TODO:
	// Add your termination code here
	return r;
}

void
cantataMainForm::OnActionPerformed(const Tizen::Ui::Control& source, int actionId)
{
	SceneManager* pSceneManager = SceneManager::GetInstance();
	AppAssert(pSceneManager);
	Tizen::Ui::Controls::Button *pButtonOk = static_cast<Button*>(GetControl(L"IDC_BUTTON_OK"));

	switch(actionId)
	{
	case ID_BUTTON_OK:
		//pNode->forkExec();
		if (pNode->isRunning() == false) {
			AppLog("Node service start");
			pNode->Start();

			if (pButtonOk != null)
			{
				pButtonOk->SetText("Running service");
			}

		} else {
			AppLog("Node service stop");
			pButtonOk->SetText("Start service");

			//pNode->stopService();
			//pNode->Join();
			delete pNode;
		}
		break;

	default:
		break;
	}
}

void
cantataMainForm::OnFormBackRequested(Tizen::Ui::Controls::Form& source)
{
	UiApp* pApp = UiApp::GetInstance();
	AppAssert(pApp);
	pApp->Terminate();
}

void
cantataMainForm::OnSceneActivatedN(const Tizen::Ui::Scenes::SceneId& previousSceneId,
										  const Tizen::Ui::Scenes::SceneId& currentSceneId, Tizen::Base::Collection::IList* pArgs)
{
	// TODO:
	// Add your scene activate code here
	AppLog("OnSceneActivatedN");
}

void
cantataMainForm::OnSceneDeactivated(const Tizen::Ui::Scenes::SceneId& currentSceneId,
										   const Tizen::Ui::Scenes::SceneId& nextSceneId)
{
	// TODO:
	// Add your scene deactivate code here
	AppLog("OnSceneDeactivated");
}

