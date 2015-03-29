#pragma once
#include "ofMain.h"

class Sound {
    
public:
    Sound();
    
    void setup(int i, ofVec2f position);
    void update();
    void draw();
    
    ofVec2f position;
    int radius;
};