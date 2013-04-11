
#ifndef _SPLASHFORM_H_
#define _SPLASHFORM_H_

#include <FBase.h>
#include <FUi.h>



class SplashForm :
	public Tizen::Ui::Controls::Form,
	public Tizen::Base::Runtime::ITimerEventListener

{

// Construction
public:
	SplashForm(void);
	virtual ~SplashForm(void);
	virtual void OnTimerExpired(Tizen::Base::Runtime::Timer& timer);

	bool Initialize();
	result OnInitializing(void);
	result OnTerminating(void);

// Implementation
protected:
	int static const SHOW_TIME = 2000;

	Tizen::Base::Runtime::Timer __pTimer;

// Generated call-back functions
public:


	virtual void OnSceneActivatedN(const Tizen::Ui::Scenes::SceneId& previousSceneId,
								   const Tizen::Ui::Scenes::SceneId& currentSceneId, Tizen::Base::Collection::IList* pArgs);
	virtual void OnSceneDeactivated(const Tizen::Ui::Scenes::SceneId& currentSceneId,
									const Tizen::Ui::Scenes::SceneId& nextSceneId);
};

#endif
