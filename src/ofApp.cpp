#include "ofApp.h"

using namespace ofxCv;
using namespace cv;

//--------------------------------------------------------------
void ofApp::setup(){
    // Camera
    cam.setDeviceID(0);
    cam.initGrabber(ofGetWidth(), ofGetHeight());

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
    originalImage.draw(0, 0);
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