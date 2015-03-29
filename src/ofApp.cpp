#include "ofApp.h"

using namespace ofxCv;
using namespace cv;

//--------------------------------------------------------------
void ofApp::setup(){
    // Camera
    cam.setDeviceID(0);
    cam.initGrabber(ofGetWidth(), ofGetHeight());

    // Sound Balls
    for(int i=0; i<8; i++) {
        sounds[i].setup(i, ofVec2f(100+i*100, 500));
    }
}

//--------------------------------------------------------------
void ofApp::update(){
    cam.update();
    if(cam.isFrameNew()) {
        originalImage.setFromPixels(cam.getPixelsRef());
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofSetColor(255, 255, 255);
    originalImage.draw(0, 0);
    
    for(int i=0; i<8; i++) {
        sounds[i].draw();
    }
}