#ifndef _CANTATA_FORM_FACTORY_H_
#define _CANTATA_FORM_FACTORY_H_

#include <FUi.h>


class FormFactory
	: public Tizen::Ui::Scenes::IFormFactory
{
public:
	FormFactory(void);
	virtual ~FormFactory(void);

	virtual Tizen::Ui::Controls::Form* CreateFormN(const Tizen::Base::String& formId, const Tizen::Ui::Scenes::SceneId& sceneId);
};

#endif // _CANTATA_FORM_FACTORY_H_
