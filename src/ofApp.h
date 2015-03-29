#pragma once

#include "ofMain.h"
#include "ofxCv.h"
#include "ofxOpenCv.h"
#include "Sound.h"

using namespace ofxCv;
using namespace cv;

class ofApp : public ofBaseApp{
public:
    void setup();
    void update();
    void draw();
    
    void drawGame();
    void drawDebug();
    
    void keyPressed(int key);
    
    ofVec2f wsize;
    bool debugMode;
    
    ofVideoGrabber cam;
    ofxCvColorImage colorImg;
    ofxCvGrayscaleImage last_grayImg, grayImg, grayDiff;
    int threshold;
    
    Sound sounds[8];
};
