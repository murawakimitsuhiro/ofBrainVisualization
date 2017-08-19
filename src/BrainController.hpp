//
//  BrainController.hpp
//  Brain-Fu_k
//
//  Created by Murawaki on 2017/08/20.
//
//

#ifndef BrainController_hpp
#define BrainController_hpp

#include <stdio.h>

#include "ofMain.h"
#include "ofxAssimpModelLoader.h"
#include "OSCManager.hpp"

class BrainController {
    
private:
    static const int modelNum = 152;
    ofxAssimpModelLoader models[modelNum];
    
    void setupOSCMessageReceive();
    
public:
    void setup();
    void update();
    void draw();
    
    int gain;
};

#endif /* BrainController_hpp */
