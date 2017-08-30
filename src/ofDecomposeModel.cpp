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
            speeds.push_back(ofVec3f(0, 0, 3.5));
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

void ofDecomposeModel::reset() {
    setStateSolid();
    decomposeBeginTime = 0;
    vectors.clear();
    speeds.clear();
    colors.clear();
    decomposeCount++;
}

void ofDecomposeModel::setStateSolid() {
    state = solid;
}

void ofDecomposeModel::update() {
    setScaleNormalization(false);
    
    if (state == decomposting) {
        for (int i=0; i<vectors.size(); i++) {
            vectors[i] += speeds[i];
            if (vectors[i].z > 70) {
                speeds[i].x = ofRandom(-12, 12);
                speeds[i].y = ofRandom(-12, 12);
                speeds[i].z = 6.5;//5.5;
                
                //float alpha = (vectors[i].z - 100) / 100;
                
                //colors[i] = ofFloatColor(0.5, 0.8, 1.0, alpha);
                //vectors[i].z = 100;
            } else if(vectors[i].z > 200) {
                state = decomposed;
            }
        }
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
    /*
     ofVboMesh mesh = getMesh(0);
     
     ofPushMatrix();
     
     vector<ofVec3f>& verts = mesh.getVertices();
     for(unsigned int i = 0; i < verts.size(); i++) {
     verts[i].z += elapsedTime * 10;
     }
     
     //ofSetColor(126, 230, 255, 200);
     //mesh.drawWireframe();
     ofPopMatrix();*/
    
    ofVec3f vectorArray[vectors.size()];
    ofFloatColor colorArray[colors.size()];
    for (int i=0; i<vectors.size(); i++) {
        vectorArray[i] = vectors[i];//verts[i];
        colorArray[i] = colors[i];
        //vectorArray[i].x += 30;
        //vectorArray[i].y += 30;
    }
    
    vbo.updateVertexData(vectorArray, vectors.size());
    vbo.updateColorData(colorArray, colors.size());
    
    glPointSize(0.01);
    vbo.draw(GL_POINTS, 0, vectors.size());
}
