#pragma once

#include "ofMain.h"
#include "ofxCv.h"
#include "Sound.h"

using namespace ofxCv;
using namespace cv;

class ofApp : public ofBaseApp{
public:
    void setup();
    void update();
    void draw();
    
    ofVideoGrabber cam;
    ofImage originalImage;
    
    Sound sounds[8];
};
