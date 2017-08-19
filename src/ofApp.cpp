#include "ofApp.h"


void ofApp::setup() {
    ofBackgroundHex(0x000000);
    ofSetFrameRate(30);
    ofEnableAlphaBlending();
    ofEnableBlendMode(OF_BLENDMODE_ALPHA);
    ofEnableDepthTest();
    glShadeModel(GL_SMOOTH);
    ofEnableSeparateSpecularLight();
    
//camera
    cam.setDistance(250);
    
//light setup
    ofFloatColor initAmbColor = ofFloatColor(0.8, 0.8, 0.8,1.0);
    ofFloatColor initDifColor = ofFloatColor(0.7, 0.7, 0.7);
    ofFloatColor initSpeColor = ofFloatColor(0.6, 0.6,0.6);
    
    light.enable();
    light.setAreaLight(2000, 2000);
    light.setPosition(100, 100, 100);
    light.setAmbientColor(initAmbColor);
    light.setDiffuseColor(initDifColor);
    light.setSpecularColor(initSpeColor);
    
    secondLight.enable();
    secondLight.setAreaLight(2000, 2000);
    secondLight.setPosition(100, -100, 100);
    secondLight.setAmbientColor(initAmbColor);
    secondLight.setDiffuseColor(initDifColor);
    secondLight.setSpecularColor(initSpeColor);
    
    brain.setup();
}

void ofApp::update() {
    brain.update();
}

void ofApp::draw(){
    ofEnableDepthTest();
    cam.begin();
    
    ofPushStyle();
    
    brain.draw();
    
    ofPopStyle();
    
    cam.end();
    
    ofDisableDepthTest();
}

//
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
