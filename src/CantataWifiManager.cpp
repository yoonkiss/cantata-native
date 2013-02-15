/*
 * MyTimerThread.cpp
 *
 *  Created on: Jan 29, 2013
 *      Author: mustafa
 */

#include "CantataWifiManager.h"

using namespace Tizen::Net::Wifi;

CantataWifiManager::CantataWifiManager(void) {

}

CantataWifiManager::~CantataWifiManager(void) {

}

void CantataWifiManager::OnWifiActivated(result r) {
    AppLog("wifi is activated now");
}

void CantataWifiManager::OnWifiDeactivated(result r) {
    AppLog("wifi is deactivated now");
}

void CantataWifiManager::OnWifiConnected(const Tizen::Base::String& ssid, result r) {
    AppLog("wifi is connected now");
}

void CantataWifiManager::OnWifiDisconnected(void) {
    AppLog("wifi is disconnected now");
}

void CantataWifiManager::OnWifiRssiChanged(long rssi) {

}

void CantataWifiManager::OnWifiScanCompletedN(const Tizen::Base::Collection::IList* pWifiBssInfoList, result r) {
}

result CantataWifiManager::createConnection(void) {
    WifiManager wifiMgr; // Creates an instance of WifiManager
    result r;

    r = wifiMgr.Construct(*this);
    if (IsFailed(r)) {
        goto CATCH;
    }

    // Activates the local Wi-Fi device
    if (wifiMgr.IsActivated() == false) {
        AppLog("turn on wifi");
        r = wifiMgr.Activate();
        if (IsFailed(r)) {
            goto CATCH;
        }
    }

    // Checks the current connection status
    if (wifiMgr.IsConnected() == false) {
        AppLog("verify wifi connection");

        return E_FAILURE;
//		Tizen::App::AppId calleeAppId = L"1234567890";
//		Tizen::App::AppManager* pAppManager = Tizen::App::AppManager::GetInstance();
//		Tizen::App::AppManager::LaunchApplication(calleeAppId, Tizen::App::AppManager::LAUNCH_OPTION_DEFAULT);
    }
    AppLog("wifi connected");
    return r;

    CATCH:
    // Do some exception handling.
    AppLog("error occurred: %ls", GetErrorMessage(r));
    return r;
}
