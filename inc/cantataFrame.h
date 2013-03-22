#ifndef _CANTATA_FRAME_H_
#define _CANTATA_FRAME_H_

#include <FBase.h>
#include <FUi.h>


class cantataFrame
	: public Tizen::Ui::Controls::Frame
{
public:
	cantataFrame(void);
	virtual ~cantataFrame(void);

public:
	virtual result OnInitializing(void);
	virtual result OnTerminating(void);
};

#endif	//_CANTATA_FRAME_H_
