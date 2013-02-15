#include <FBase.h>
#include <FApp.h>


class CantataNode: public Tizen::Base::Runtime::Thread {
public:
    CantataNode(void);
    virtual ~CantataNode(void);

    result Construct(void);

    Object* Run(void);
    void stopService();

    bool isRunning();

private:
    volatile bool isRunningThread;
};

