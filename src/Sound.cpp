#include "Sound.h"

using namespace cv;

Sound::Sound(){
    radius = 70;
    state = 0;
}

void Sound::setup(int i, ofVec2f _position){
    position = _position;
    
    std::ostringstream img_file;
    img_file << "images/" << i << ".png";
    img.loadImage(img_file.str());
    
    std::ostringstream sound_file;
    sound_file << "sounds/" << i << ".wav";
    note.loadSound(sound_file.str());
}

void Sound::update(ofxCvGrayscaleImage grayDiff, int threshold){
    if(state==5) {
        state = 0;
    } else if(state>0) {
        state++;
    } else {
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
            }
            if(collision > threshold) {
                touched=true;
                state = 1;
            }
        }
    }
}

void Sound::draw(){
    if(touched) {
        ofSetColor(255, 0, 0, 160-state*10);
        ofCircle(position, radius+state*50);
        if(state==1) note.play();
    }
    
    img.draw(position);
}