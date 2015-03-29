#include "Sound.h"

using namespace cv;

Sound::Sound(){
    radius = 90;
}

void Sound::setup(int i, ofVec2f _position){
    position = _position;
}

void Sound::update(ofxCvGrayscaleImage grayDiff, int threshold){
    int collision = 0;
    int r = radius;
    
    int x = position.x - r;
    int y = position.y - r;
    
    ofVec2f wsize = ofGetWindowSize();
    
    int index;
    touched = false;
    for(y; y<position.y+r; y++) {
        if(y<0 || y>wsize.y) continue;
        
        for(x; x<position.x+r; x++) {
            if(x<0 || x>wsize.x) continue;
            
            index = y * wsize.x + x;
            
            if(grayDiff.getPixels()[index]) {
                collision++;
            }
            if(collision > threshold) touched=true;
        }
        if(collision > threshold) touched=true;
    }
}

void Sound::draw(){
    if(touched) {
        ofSetColor(255, 0, 0, 200);
    } else {
        ofSetColor(0, 0, 255, 100);
    }
    ofCircle(position, radius);
}