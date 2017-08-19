//
//  BrainController.cpp
//  Brain-Fu_k
//
//  Created by Murawaki on 2017/08/20.
//
//

#include "BrainController.hpp"

void BrainController::setup() {
    ifstream ifs("/Users/murawakimitsuhiro/Documents/_Xcode_Project/SDK_Library/of_v0.9.8_osx_release/apps/Brain-Fu_k/bin/data/model/model_file_name_list.txt");
    string buf;
    string dir = "model/";
    
    int num;
    num = 0;
    while(getline(ifs, buf)){
        string tmp;
        istringstream stream(buf);
        while (getline(stream, tmp, ',')){
            tmp = dir + tmp;
            models[num].loadModel(tmp);
            models[num].setScaleNormalization(false);
            num++;
        }
    }
}

void BrainController::update() {
    for (int i = 0; i < modelNum; i++) {
        models[i].setScaleNormalization(false);
    }
}

/* call in camera rendering */
void BrainController::draw() {
    ofSetColor(100, 100, 100, 255);
    
    for (int i = 0; i < modelNum; i++) {
        models[i].drawFaces();
        //models[i].drawWireframe();
    }
}
