#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    const string rightBrainModelPath = "model/brain-rh.stl";
    const string leftBrainModelPath = "model/brain-lh.stl";
    
    float scale = 0.5;
    
    leftBrainModel.setScale(scale, scale, scale);
    rightBrainModel.setScale(scale, scale, scale);
    
    leftBrainModel.loadModel(leftBrainModelPath);
    rightBrainModel.loadModel(rightBrainModelPath);
    
    //ofEnableDepthTest();
}

//--------------------------------------------------------------
void ofApp::update(){
    leftBrainModel.update();
    rightBrainModel.update();
    
    camera.lookAt(ofVec3f(0,0,0));
    camera.setPosition(500*cos(ofGetElapsedTimef()/10), 200, 500*sin(ofGetElapsedTimef()/10));
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofBackground(0);
    
    ofSetColor(255, 30);
    
    ofPushMatrix();
    ofTranslate(ofGetWidth()/2, ofGetHeight()/2);
    camera.begin();
    ofRotateX(-90);
    ofSetLineWidth(1);
    
    rightBrainModel.drawVertices();
    rightBrainModel.drawFaces();
    
    leftBrainModel.drawVertices();
    leftBrainModel.drawFaces();
    
    camera.end();
    ofPopMatrix();
    
    ofSetColor(255, 255, 255, 255);
    string info = ofToString(ofGetFrameRate(), 2);
    ofDrawBitmapString(info, 30, 30);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
    
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
