//
//  ofDisassemblyModel.hpp
//  Brain-Fu_k
//
//  Created by Murawaki on 2017/08/23.
//
//

#ifndef ofDisassemblyModel_hpp
#define ofDisassemblyModel_hpp

#include <stdio.h>
#include "ofxAssimpModelLoader.h"

enum ofDecomposeState {
    solid,
    decomposting,
    decomposed
};

class ofDecomposeModel: public ofxAssimpModelLoader {
    
private:
    ofDecomposeState state = solid;
    float decomposeBeginTime = 0;
    
    ofVbo vbo;
    vector<ofVec3f> vectors;
    vector<ofVec3f> speeds;
    vector<ofFloatColor> colors;
    
    void drawSolid();
    void drawDecomposing();
    
public:
    void update();
    void draw();
    void startDecompose();
    void setStateSolid();
    
    void reset();
    int decomposeCount = 0;
};

#endif /* ofDisassemblyModel_hpp */

