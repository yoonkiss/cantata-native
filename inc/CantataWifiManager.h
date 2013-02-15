#include <FBase.h>
#include <FNet.h>

class CantataWifiManager: public Tizen::Net::Wifi::IWifiManagerEventListener {
public:
    CantataWifiManager(void);
    ~CantataWifiManager(void);

    // implement IWifiManagerEventListener
    virtual void OnWifiActivated(result r);
    virtual void OnWifiDeactivated(result r);
    virtual void OnWifiConnected(const Tizen::Base::String& ssid, result r);
    virtual void OnWifiDisconnected(void);
    virtual void OnWifiRssiChanged(long rssi);
    virtual void OnWifiScanCompletedN(const Tizen::Base::Collection::IList* pWifiBssInfoList,
            result r);

    result createConnection();
private:
    static volatile bool isRunningThread;
};

