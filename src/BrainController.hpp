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
#include <unistd.h>

#include "ofMain.h"
#include "ofxAssimpModelLoader.h"
#include "OSCManager.hpp"
#include "ofDecomposeModel.hpp"
#include "BrainModelData.h"
//#include "BrainModelRersource.hpp"

class BrainController {
    
private:
    ofDecomposeModel models[BrainModelData::modelNum];
    int nextDecomposeNum = 0;
    
    void setupOSCMessageReceive();
    int isLearning = 0;
    int wasStart = 0;
    
    //debug
    int gain;
    int debugTarget;
    
public:
    void setup();
    void update();
    void draw();
    void drawWithMesh(ofxAssimpModelLoader mesh);
};

#endif /* BrainController_hpp */
