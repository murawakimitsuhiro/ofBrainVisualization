//
//  ofDisassemblyModel.cpp
//  Brain-Fu_k
//
//  Created by Murawaki on 2017/08/23.
//
//

#include "ofDecomposeModel.hpp"

void ofDecomposeModel::startDecompose() {
    if (state == solid) {
        state = decomposting;
        decomposeBeginTime = ofGetElapsedTimef();
        
        ofVboMesh mesh = getMesh(0);
        vector<ofVec3f>& verts = mesh.getVertices();
        for (int i=0; i<verts.size(); i++) {
            vectors.push_back(verts[i]);
            colors.push_back(ofFloatColor(0.5, 0.8, 1.0, 1.0));
        }
        
        ofVec3f vectorArray[verts.size()];
        ofFloatColor colorArray[verts.size()];
        for (int i=0; i<verts.size(); i++) {
            vectorArray[i] = verts[i];
            colorArray[i] = colors[i];
        }
        
        vbo.setVertexData(vectorArray, verts.size(), GL_DYNAMIC_DRAW);
        vbo.setColorData(colorArray, verts.size(), GL_DYNAMIC_DRAW);
    }
}

//draw the model manually
void ofDecomposeModel::draw() {
    switch (state) {
        case solid:
            drawSolid();
            break;
        case decomposting:
            drawDecomposing();
            break;
        case decomposed:
            break;
    }
}

void ofDecomposeModel::drawSolid() {
    drawWireframe();
}

void ofDecomposeModel::drawDecomposing() {
    float elapsedTime = ofGetElapsedTimef() - decomposeBeginTime;
    
    ofVboMesh mesh = getMesh(0);
    
    ofPushMatrix();
    
    vector<ofVec3f>& verts = mesh.getVertices();
    for(unsigned int i = 0; i < verts.size(); i++) {
        verts[i].y += elapsedTime * 10;
    }
   
    ofSetColor(126, 230, 255, 200);
    mesh.drawWireframe();
    ofPopMatrix();
    
    
    ofVec3f vectorArray[vectors.size()];
    for (int i=0; i<vectors.size(); i++) {
        vectorArray[i] = verts[i];//vectors
    }
    
    vbo.updateVertexData(vectorArray, vectors.size());
    
    glPointSize(1);
    vbo.draw(GL_POINTS, 0, vectors.size());
}
