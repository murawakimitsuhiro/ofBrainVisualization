//
//  ofDisassemblyModel.cpp
//  Brain-Fu_k
//
//  Created by Murawaki on 2017/08/23.
//
//

#include "ofDisassemblyModel.hpp"

//draw the model manually
void ofDisassemblyModel::drawCustom() {
    //get the model attributes we need
    ofVec3f scale = getScale();
    ofVec3f position = getPosition();
    float normalizedScale = getNormalizedScale();
    ofVboMesh mesh = getMesh(0);
    
    ofPushMatrix();
    
    float randX = ofRandom(-10, 10);
    vector<ofVec3f>& verts = mesh.getVertices();
    for(unsigned int i = 0; i < verts.size(); i++){
        verts[i].y += randX;
    }
    
    mesh.drawVertices();//drawWireframe();
    ofPopMatrix();
}
