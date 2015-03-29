#pragma once
#include "ofMain.h"
#include "ofxOpenCv.h"

class Sound {
    
public:
    Sound();
    
    void setup(int i, ofVec2f position, ofVec2f size);
    void update(ofxCvGrayscaleImage grayDiff, int threshold);
    void draw();
    
    ofVec2f position;
    ofVec2f size;
    int radius;
    ofImage img;
    ofSoundPlayer note;
    int state;
    
    bool touched;
};