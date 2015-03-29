#include "Sound.h"

Sound::Sound(){
    
}

void Sound::setup(int i, ofVec2f _position){
    position = _position;
}

void Sound::update(){
}

void Sound::draw(){
    ofSetColor(0, 0, 255);
    ofCircle(position, 50);
}