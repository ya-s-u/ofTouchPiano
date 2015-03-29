#pragma once
#include "ofMain.h"
#include "ofxOpenCv.h"

class Sound {
    
public:
    Sound();
    
    void setup(int i, ofVec2f position);
    void update(ofxCvGrayscaleImage grayDiff);
    void draw();
    
    ofVec2f position;
    int radius;
    
    bool touched;
};