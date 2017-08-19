//
//  OSCManager.hpp
//  Brain-Fu_k
//
//  Created by Murawaki on 2017/08/20.
//
//

#ifndef OSCManager_hpp
#define OSCManager_hpp

#include <stdio.h>
#include <map>

#include "ofMain.h"
#include "ofxOsc.h"

class OSCManager {
private:
    OSCManager() = default;
    ~OSCManager() = default;
    
    static const int fromPort = 8000;
    static const int toPort = 8001;
    
    ofxOscReceiver receiver;
    
    map<string, int> messageMap;
    
public:
    OSCManager(const OSCManager&) = delete;
    OSCManager& operator=(const OSCManager&) = delete;
    OSCManager(OSCManager&&) = delete;
    OSCManager& operator=(OSCManager&&) = delete;
    
    static OSCManager& get_instance() {
        static OSCManager inst;
        return inst;
    }
    
    void setup();
    void update();
    void dumpOSC(ofxOscMessage m);
};

#endif /* OSCManager_hpp */
