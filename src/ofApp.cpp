#include "ofApp.h"

using namespace ofxCv;
using namespace cv;

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetFrameRate(30);
    wsize = ofGetWindowSize();
    touch_threshold = 5;
    
    // Camera
    cam.setDeviceID(0);
    cam.initGrabber(ofGetWidth(), ofGetHeight());
    
    // Images
    colorImg.allocate(wsize.x, wsize.y);
    grayImg.allocate(wsize.x, wsize.y);
    last_grayImg.allocate(wsize.x, wsize.y);
    grayDiff.allocate(wsize.x, wsize.y);
    threshold = 40;

    // Sound Balls
    sounds[0].setup(0, ofVec2f(100, wsize.y-100));
    sounds[1].setup(1, ofVec2f(140, wsize.y/2+40));
    sounds[2].setup(2, ofVec2f(280, 200));
    sounds[3].setup(3, ofVec2f(wsize.x/2-160, 100));
    sounds[4].setup(4, ofVec2f(wsize.x/2+160, 100));
    sounds[5].setup(5, ofVec2f(wsize.x-280, 200));
    sounds[6].setup(6, ofVec2f(wsize.x-140, wsize.y/2+40));
    sounds[7].setup(7, ofVec2f(wsize.x-100, wsize.y-100));
    
    // get First frame & set last_grayImg
    cam.update();
    if (1){
        colorImg.setFromPixels(cam.getPixels(), wsize.x, wsize.y);
        colorImg.mirror(false, true);
        last_grayImg = colorImg;
    }
}

//--------------------------------------------------------------
void ofApp::update(){
    cam.update();
    if(cam.isFrameNew()) {
        colorImg.setFromPixels(cam.getPixels(), wsize.x, wsize.y);
        colorImg.mirror(false, true);
        grayImg = colorImg;
        
        grayDiff.absDiff(last_grayImg, grayImg);
        grayDiff.threshold(threshold);
        
        last_grayImg = grayImg;
    }
    
    for(int i=0; i<8; i++) {
        sounds[i].update(grayDiff, touch_threshold);
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    if(debugMode) {
        drawDebug();
    } else {
        drawGame();
    }
}

//--------------------------------------------------------------
void ofApp::drawGame(){
    ofSetColor(255, 255, 255);
    colorImg.draw(0, 0);
    
    for(int i=0; i<8; i++) {
        sounds[i].draw();
    }
    
    ofSetWindowTitle(ofToString(ofGetFrameRate()));
}

//--------------------------------------------------------------
void ofApp::drawDebug(){
    ofSetColor(255, 255, 255);
    grayDiff.draw(0, 0);
    
    for(int i=0; i<8; i++) {
        sounds[i].draw();
    }
    
    ofSetWindowTitle(ofToString(threshold));
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    switch(key) {
        case '1':
            debugMode = false;
            break;
        case '2':
            debugMode = true;
            break;
    }
    
    if(debugMode) {
        switch(key) {
            case 'q':
                threshold++;
                break;
            case 'a':
                threshold--;
                break;
            case 'w':
                touch_threshold++;
                break;
            case 's':
                touch_threshold--;
                break;
        }
    }
}