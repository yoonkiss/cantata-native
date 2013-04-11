#ifndef _CANTATA_NODE_H_
#define _CANTATA_NODE_H_

#include <FBase.h>
#include <FApp.h>


class CantataNode {
public:
    CantataNode(void);
    virtual ~CantataNode(void);

    Tizen::Base::Object* Run(void);

    bool isRunning();

private:
    volatile bool isRunningThread;
};

#endif
