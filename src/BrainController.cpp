//
//  BrainController.cpp
//  Brain-Fu_k
//
//  Created by Murawaki on 2017/08/20.
//
//

#include "BrainController.hpp"

void BrainController::setup() {
    for(int i=0; i<BrainModelData::modelNum; i++) {
        string tmp = BrainModelData::basePath + BrainModelData::modelNames[i];
        models[i].loadModel(tmp);
        models[i].setScaleNormalization(false);
    }
    
    setupOSCMessageReceive();
}

//LINK OSC
void BrainController::setupOSCMessageReceive() {
    /* /gain to gain */
    OSCManager::get_instance().setMessageReceiver("/leg", isLearning);
    OSCManager::get_instance().setMessageReceiver("/gain", gain);
    OSCManager::get_instance().setMessageReceiver("/debug_target", debugTarget);
    OSCManager::get_instance().setMessageReceiver("/start", wasStart);
}

void BrainController::update() {
    for (int i = 0; i < BrainModelData::modelNum; i++) {
        models[i].update();
    }
    
    if (wasStart == 0) {
        return;
    }
    
    //decomposed by time
    if (isLearning > 0 && nextDecomposeNum/* * 3*/ - int(ofGetElapsedTimef()) < 0) {
        models[nextDecomposeNum].startDecompose();
        
        if (nextDecomposeNum == BrainModelData::modelNum - 10) {
            nextDecomposeNum = 0;
            for (int i=0; i<BrainModelData::modelNum; i++) {
                models[i].setStateSolid();
            }
        } else {
            nextDecomposeNum++;
        }
    }
}

/* call in camera rendering */
void BrainController::draw() {
    for (int i = 0; i < BrainModelData::modelNum; i++) {
        
        //decomposed brain parts
        if(i < nextDecomposeNum) {
            models[i].draw();
            continue;
        }
        
        if (OSCManager::get_instance().bci[i / 9] > 1.0) {
            ofSetColor(255, 0, 0, 30);
        } else if (OSCManager::get_instance().bci[i / 9] > 0.6) {
            ofSetColor(0, 250, 250, 30);
        } else {
            ofSetColor(255, 255, 255, 30);
        }
        
        //normal draw
        models[i].drawWireframe();
    }
}
