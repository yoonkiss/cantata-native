
#include "AppResourceId.h"
#include "SplashForm.h"

using namespace Tizen::Base;
using namespace Tizen::Ui;
using namespace Tizen::Ui::Controls;
using namespace Tizen::Ui::Scenes;

SplashForm::SplashForm(void)
{
}

SplashForm::~SplashForm(void)
{
}

bool
SplashForm::Initialize()
{
	Construct( FRM_SPLASH );

	Tizen::Base::TimeSpan uptime(0);
	long long tick = uptime.GetTicks();
	TimeSpan span = static_cast< long >(tick);

	__pTimer.Construct( *this );
	__pTimer.Start( SHOW_TIME );
	return true;
}

result
SplashForm::OnInitializing(void)
{
	result r = E_SUCCESS;

	return r;
}

result
SplashForm::OnTerminating(void)
{
	result r = E_SUCCESS;

	// TODO: Add your termination code here

	return r;
}

void
SplashForm::OnTimerExpired(Tizen::Base::Runtime::Timer& timer)
{
	SceneManager* pSceneManager = SceneManager::GetInstance();
	pSceneManager->GoForward( SceneTransitionId( TR_MAIN ) );

}



void
SplashForm::OnSceneActivatedN(const Tizen::Ui::Scenes::SceneId& previousSceneId,
								const Tizen::Ui::Scenes::SceneId& currentSceneId, Tizen::Base::Collection::IList* pArgs)
{
	// TODO: Add your implementation codes here

}

void
SplashForm::OnSceneDeactivated(const Tizen::Ui::Scenes::SceneId& currentSceneId,
								const Tizen::Ui::Scenes::SceneId& nextSceneId)
{
	// TODO: Add your implementation codes here

}
