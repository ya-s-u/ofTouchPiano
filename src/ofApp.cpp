#include "ofApp.h"

using namespace ofxCv;
using namespace cv;

//--------------------------------------------------------------
void ofApp::setup(){
    ofVec2f wsize = ofGetWindowSize();
    
    // Camera
    cam.setDeviceID(0);
    cam.initGrabber(ofGetWidth(), ofGetHeight());

    // Sound Balls
    sounds[0].setup(0, ofVec2f(100, wsize.y-100));
    sounds[1].setup(1, ofVec2f(100, wsize.y/2));
    sounds[2].setup(2, ofVec2f(100, 100));
    sounds[3].setup(3, ofVec2f(wsize.x/2-220, 100));
    sounds[4].setup(4, ofVec2f(wsize.x/2+220, 100));
    sounds[5].setup(5, ofVec2f(wsize.x-100, 100));
    sounds[6].setup(6, ofVec2f(wsize.x-100, wsize.y/2));
    sounds[7].setup(7, ofVec2f(wsize.x-100, wsize.y-100));
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