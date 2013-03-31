#include <FUi.h>

#include "AppResourceId.h"
#include "MainForm.h"
#include "CantataNode.h"

using namespace Tizen::Base;
using namespace Tizen::Ui;
using namespace Tizen::Ui::Controls;
using namespace Tizen::Ui::Scenes;

const String MainForm::DEFAULT_PORT = String( L"3000" );

MainForm::MainForm(void)
{
	pNode = new CantataNode();
	pNode->Construct();
}

MainForm::~MainForm(void)
{
	delete pNode;
}

bool
MainForm::Initialize()
{
	Form::Construct(FRM_MAIN);

	return true;
}

result
MainForm::OnInitializing(void)
{
	result r = E_SUCCESS;

	Label *pPortLabel = static_cast<Label*>(GetControl(IDC_LBL_PORT));
	TextBox *pPort = static_cast<TextBox*>(GetControl(IDC_PORT));
	pPortLabel->SetShowState( false );
	pPort->SetShowState( false );

	Button *pBtnConnect = static_cast<Button *>(GetControl(IDC_BTN_CONNECT));

	if(pBtnConnect)
	{
		pBtnConnect->SetActionId(ACTION_CONNECT);
		pBtnConnect->AddActionEventListener(*this);
	}
	Button *pBtnConfirm = static_cast<Button *>(GetControl(IDC_BTN_CONFIRM));
	if(pBtnConfirm)
	{
		pBtnConfirm->SetShowState( false );
		pBtnConfirm->SetActionId(ACTION_CONFIRM);
		pBtnConfirm->AddActionEventListener(*this);
	}
	Button *pBtnCancel = static_cast<Button *>(GetControl(IDC_BTN_CANCEL));
	if(pBtnCancel)
	{
		pBtnCancel->SetShowState( false );
		pBtnCancel->SetActionId(ACTION_CANCEL);
		pBtnCancel->AddActionEventListener(*this);
	}
	Label *pLblSyncing = static_cast<Label *>(GetControl(IDC_SYNCING));
	pLblSyncing->SetShowState( false );

	Label *pLblAuthentication = static_cast<Label *>(GetControl(IDC_AUTHENTICATION));
	pLblAuthentication->SetShowState( false );

	Label *pAnimate1 = static_cast<Label*>(GetControl( IDC_ANIMATE1 ));
	pAnimate1->SetShowState( true );
	Label *pAnimate2 = static_cast<Label*>(GetControl( IDC_ANIMATE2 ));
	pAnimate2->SetShowState( false );
	Label *pAnimate3 = static_cast<Label*>(GetControl( IDC_ANIMATE3 ));
	pAnimate3->SetShowState( false );
	Label *pAnimate4 = static_cast<Label*>(GetControl( IDC_ANIMATE4 ));
	pAnimate4->SetShowState( false );
	Label *pAnimate5 = static_cast<Label*>(GetControl( IDC_ANIMATE5 ));
	pAnimate5->SetShowState( false );

	return r;
}

result
MainForm::OnTerminating(void)
{
	result r = E_SUCCESS;

	// TODO: Add your termination code here

	return r;
}



void
MainForm::OnSceneActivatedN(const Tizen::Ui::Scenes::SceneId& previousSceneId,
								const Tizen::Ui::Scenes::SceneId& currentSceneId, Tizen::Base::Collection::IList* pArgs)
{
	// TODO: Add your implementation codes here

}

void
MainForm::OnSceneDeactivated(const Tizen::Ui::Scenes::SceneId& currentSceneId,
								const Tizen::Ui::Scenes::SceneId& nextSceneId)
{
	// TODO: Add your implementation codes here

}

void
MainForm::OnActionPerformed(const Tizen::Ui::Control& source, int actionId)
{
	SceneManager* pSceneManager = SceneManager::GetInstance();
	AppAssert(pSceneManager);
	Label *pTitle = static_cast<Label*>(GetControl(IDC_TITLE));
	Label *pPortLabel = static_cast<Label*>(GetControl(IDC_LBL_PORT));
	TextBox *pPort = static_cast<TextBox*>(GetControl(IDC_PORT));
	Label *pAuthentication = static_cast<Label*>(GetControl(IDC_AUTHENTICATION));
	Label *pCode = static_cast<Label*>(GetControl(IDC_CODE));
	Label *pSyncing = static_cast<Label*>(GetControl( IDC_SYNCING ));
	Label *pAnimate1 = static_cast<Label*>(GetControl( IDC_ANIMATE1 ));
	Label *pAnimate2 = static_cast<Label*>(GetControl( IDC_ANIMATE2 ));
	Label *pAnimate3 = static_cast<Label*>(GetControl( IDC_ANIMATE3 ));
	Label *pAnimate4 = static_cast<Label*>(GetControl( IDC_ANIMATE4 ));
	Label *pAnimate5 = static_cast<Label*>(GetControl( IDC_ANIMATE5 ));

	Button *pBtnConnect = static_cast<Button*>(GetControl(IDC_BTN_CONNECT));
	Button *pBtnConfirm = static_cast<Button*>(GetControl(IDC_BTN_CONFIRM));
	Button *pBtnCancel = static_cast<Button*>(GetControl(IDC_BTN_CANCEL));
	UuId* uid = UuId::GenerateN();

	String id;
	AppLog( "Init" );

	switch(actionId)
	{
	case ACTION_CONNECT:
		pTitle->SetShowState( false );
		pPortLabel->SetShowState( true );
		pPort->SetShowState( true );
//		pPort->SetText( (const String) String( L"3000" ) );
		pBtnConnect->SetShowState( false );
		pBtnConfirm->SetShowState( true );
		pAnimate1->SetShowState( false );
		pAnimate2->SetShowState( false );
		pAnimate3->SetShowState( false );
		pAnimate4->SetShowState( false );
		pAnimate5->SetShowState( false );

		pAuthentication->SetShowState( true );

		uid->ToString().SubString( 0, 8, id );
		pCode->SetText( id );
		pCode->Invalidate( true );
		pCode->SetShowState( true );

		break;
	case ACTION_CONFIRM:
		if (pNode->isRunning() == false) {
			AppLog("Node service start");
			pNode->Start();
			pTitle->SetShowState( true );
			pAuthentication->SetShowState( false );
			pCode->SetShowState( false );
			pPort->SetShowState( false );
			pPortLabel->SetShowState( false );
			pSyncing->SetShowState( true );
			pAnimate5->SetShowState( true );
			pBtnConfirm->SetShowState( false );
			pBtnCancel->SetShowState( true );
		}
		break;
	case ACTION_CANCEL:
		pNode->Stop();
		pBtnCancel->SetShowState( false );
		pSyncing->SetShowState( false );
		pAnimate1->SetShowState( true );
		pAnimate2->SetShowState( false );
		pAnimate3->SetShowState( false );
		pAnimate4->SetShowState( false );
		pAnimate5->SetShowState( false );
		pBtnConnect->SetShowState( true );
		break;

	default:
		break;
	}
}


