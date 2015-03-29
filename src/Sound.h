#pragma once
#include "ofMain.h"
#include "ofxOpenCv.h"

class Sound {
    
public:
    Sound();
    
    void setup(int i, ofVec2f position);
    void update(ofxCvGrayscaleImage grayDiff, int threshold);
    void draw();
    
    ofVec2f position;
    int radius;
    ofSoundPlayer note;
    int state;
    
    bool touched;
};