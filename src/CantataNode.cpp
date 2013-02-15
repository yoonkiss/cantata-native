/*
 * CantataNode.cpp
 *
 *  Created on: Jan 29, 2013
 *      Author: mustafa
 */
#include "CantataNode.h"

static const char *NODE_EXECUTABLE = "node";
static const char *JS_SCRIPT = "app.js";

extern "C" {
int cantata_main(int argc, char *argv[]);
}

CantataNode::CantataNode(void) {
    //TODO: initialize wifi connection
    /*
    CantataWifiManager wifi;
    wifi.createConnection();
    */
    isRunningThread = false;
}

CantataNode::~CantataNode(void) {
}

result CantataNode::Construct(void) {
    return Thread::Construct();
}

Tizen::Base::Object* CantataNode::Run(void) {
    char *argv2[2];

    Tizen::Base::String appName = Tizen::App::App::GetInstance()->GetAppRootPath() + Tizen::App::App::GetInstance()->GetAppName();
    Tizen::Base::String resPath = Tizen::App::App::GetInstance()->GetAppResourcePath();
    char app_path[512];
    char js_path[512];
    char node_path[512];
    int ret = 0;

    sprintf(app_path, "%ls", (const wchar_t*) appName.GetPointer());
    sprintf(node_path, "%ls%s", resPath.GetPointer(), NODE_EXECUTABLE);
    sprintf(js_path, "%ls%s", resPath.GetPointer(), JS_SCRIPT);

    argv2[0] = strdup(app_path);
    argv2[1] = strdup(js_path);

    isRunningThread = true;
    ret = cantata_main(2, argv2);

    if (app_path != NULL) {
        free(app_path);
    }
    if (app_path != NULL) {
        free(js_path);
    }
#if 0
   /* handle = dlopen(node_path, RTLD_LAZY);
    if (handle == NULL) {
        AppLog("load error %s: %s\n", node_path, dlerror());
        return null;
    }

    AppLog("Calling main func");
    // TODO: how to stop node thread?
    call_nodejs = (void (*)(int, char**))dlsym(handle, "cantata_main");

    if((error = dlerror()) != NULL) {
        AppLog("dlsym error %s: %s\n", node_path, error);
        dlclose(handle);
        return null;
    }
    AppLog("Calling node");
    call_nodejs(2, argv2);
    dlclose(handle);
    */
#endif
    return null;
}

void CantataNode::stopService() {
    // FIXME: do not stop on purpose
    isRunningThread = false;
}

bool CantataNode::isRunning() {
    return isRunningThread;
}
