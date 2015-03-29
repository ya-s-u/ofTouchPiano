#pragma once

#include "ofMain.h"
#include "ofxCv.h"

using namespace ofxCv;
using namespace cv;

class ofApp : public ofBaseApp{
public:
    void setup();
    void update();
    void draw();
    
    void movePoint(vector<ofVec2f>& points, ofVec2f point);
    void mousePressed(int x, int y, int button);
    void mouseDragged(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    
    ofVideoGrabber cam;
    ofImage originalImage;
};
