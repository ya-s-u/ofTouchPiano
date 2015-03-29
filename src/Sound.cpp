#include "Sound.h"

using namespace cv;

Sound::Sound(){
    radius = 90;
}

void Sound::setup(int i, ofVec2f _position){
    position = _position;
}

void Sound::update(ofxCvGrayscaleImage grayDiff){
    int collision = 0;
    int detection = 5;
    
    int x = position.x - radius;
    int y = position.y - radius;
    
    ofVec2f wsize = ofGetWindowSize();
    
    int index;
    touched = false;
    for(y; y<position.y+radius; y++) {
        if(y<0 || y>wsize.y) continue;
        
        for(x; x<position.x+radius; x++) {
            if(x<0 || x>wsize.x) continue;
            
            index = y * wsize.x + x;
            
            if(grayDiff.getPixels()[index]) {
                collision++;
            }
            if(collision > detection) touched=true;
        }
        if(collision > detection) touched=true;
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