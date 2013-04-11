#ifndef _PANEL_FACTORY_H_
#define _PANEL_FACTORY_H_

#include <FUi.h>


class PanelFactory
	: public Tizen::Ui::Scenes::IPanelFactory
{
public:
	PanelFactory(void);
	virtual ~PanelFactory(void);

	virtual Tizen::Ui::Controls::Panel* CreatePanelN(const Tizen::Base::String& panelId, const Tizen::Ui::Scenes::SceneId& sceneId);
};

#endif // _CANTATA_PANEL_FACTORY_H_
