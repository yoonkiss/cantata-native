
#ifndef _MAINFORM_H_
#define _MAINFORM_H_

#include <FBase.h>
#include <FUi.h>

#include "CantataNode.h"



class MainForm :
	public Tizen::Ui::Controls::Form,
 	public Tizen::Ui::Scenes::ISceneEventListener,
	public Tizen::Ui::IActionEventListener
{

// Construction
public:
	MainForm(void);
	virtual ~MainForm(void);
	bool Initialize();
	result OnInitializing(void);
	result OnTerminating(void);

// Implementation
protected:
	static const Tizen::Base::String DEFAULT_PORT;

	static const int ACTION_CONNECT = 1000;
	static const int ACTION_CONFIRM = 2000;
	static const int ACTION_CANCEL = 3000;

	CantataNode* pNode;

// Generated call-back functions
public:


	virtual void OnSceneActivatedN(const Tizen::Ui::Scenes::SceneId& previousSceneId,
								   const Tizen::Ui::Scenes::SceneId& currentSceneId, Tizen::Base::Collection::IList* pArgs);
	virtual void OnSceneDeactivated(const Tizen::Ui::Scenes::SceneId& currentSceneId,
									const Tizen::Ui::Scenes::SceneId& nextSceneId);

	virtual void OnActionPerformed(const Tizen::Ui::Control& source, int actionId);
};

#endif
