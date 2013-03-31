#include "cantataFormFactory.h"
#include "cantataMainForm.h"
#include "AppResourceId.h"
#include "SplashForm.h"
#include "MainForm.h"

using namespace Tizen::Ui::Scenes;


cantataFormFactory::cantataFormFactory(void)
{
}

cantataFormFactory::~cantataFormFactory(void)
{
}

Tizen::Ui::Controls::Form*
cantataFormFactory::CreateFormN(const Tizen::Base::String& formId, const Tizen::Ui::Scenes::SceneId& sceneId)
{
	SceneManager* pSceneManager = SceneManager::GetInstance();
	AppAssert(pSceneManager);
	Tizen::Ui::Controls::Form* pNewForm = null;

	if (formId == FRM_SPLASH)
	{
		SplashForm* pForm = new SplashForm();
		pForm->Initialize();
		pNewForm = pForm;
	}
	else if (formId == FRM_MAIN)
	{
		MainForm* pForm = new MainForm();
		pForm->Initialize();
		pNewForm = pForm;
	}



	return pNewForm;
}
