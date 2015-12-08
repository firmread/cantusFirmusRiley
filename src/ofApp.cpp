#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    ofBackground(255);
    
    y.c.setHex(0xA79C26);
    y.width = 9;
    
    p.c.setHex(0xC781A8);
    p.width = 9;
    
    b.c.setHex(0x64A2C9);
    b.width = 11;
    
    k.c.setHex(0x222B32);
    k.width = 39;
    
    w.c.setHex(0xE3E2DE);
    w.width = 29;
    
    g.c.set(127);
    g.width = 29;
    
    r.c.set(255,0,0);
    r.width = 10;
    
    int counter = 0;
    
    for (int i = 0; i <= 10000; i++){
        if(i == 5000) stripes.push_back(w);
        
        else if(abs(i-5000)% 8 == 1) stripes.push_back(y);
        else if(abs(i-5000)% 8 == 2) stripes.push_back(p);
        else if(abs(i-5000)% 8 == 3) stripes.push_back(b);
        
        else if(abs(i-5000)% 8 == 5) stripes.push_back(b);
        else if(abs(i-5000)% 8 == 6) stripes.push_back(p);
        else if(abs(i-5000)% 8 == 7) stripes.push_back(y);
        
        else if(abs(i-5000)%12 == 0) stripes.push_back(w);
        else if(abs(i-5000)%12 == 4) stripes.push_back(g);
        else if(abs(i-5000)%12 == 8) stripes.push_back(k);

        
        else stripes.push_back(r);
    }
    
}

//--------------------------------------------------------------
void ofApp::update(){
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofTranslate(mouseX, 0);
    //noise between 0 & screenwidth
    
    float zoomNoise = ofNoise(ofGetElapsedTimef()*0.1);
    // cinematic = 0.1 // motion sickness = 10
    
    float microScale = ofMap(mouseY, 0, ofGetHeight()/2, 0.015, 1.0, true);
    float macroScale = ofMap(mouseY, ofGetHeight()/2, ofGetHeight(), 1.0, 2.5,true);

    float maxZoomOut = mouseY < ofGetHeight()/2 ? microScale : macroScale;
//     zoom range control
    float zoom = ofMap(zoomNoise, 0, 1, .0001, maxZoomOut, true);

//    float microScale = ofMap(zoomNoise, 0, 0.5, 0.001, 1.0, true);
//    float macroScale = ofMap(zoomNoise, 0.5, 1.0, 1.0, 2.5, true);
//    
//    float zoom = zoomNoise < 0.5 ? microScale : macroScale;
    
    ofScale(zoom, 1);
    
    //midline
    stripes[5000].x = -stripes[5000].width/2;
    ofSetColor(stripes[5000].c);
    ofDrawRectangle(stripes[5000].x, 0, stripes[5000].width, ofGetWidth());
    
    //loop to the left
    for (int i = 4999; i> 0; i--){
        ofSetColor(stripes[i].c);
        stripes[i].x = stripes[i+1].x - stripes[i].width;
        ofDrawRectangle(stripes[i].x, 0, stripes[i].width, ofGetHeight());
    }
    
    //loop to the right
    for (int i = 5001; i< stripes.size();i++) {
        ofSetColor(stripes[i].c);
        stripes[i].x = stripes[i-1].x + stripes[i-1].width;
        ofDrawRectangle(stripes[i].x, 0, stripes[i].width, ofGetHeight());
    }
    
    
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){ }
void ofApp::keyReleased(int key){ }
void ofApp::mouseMoved(int x, int y ){ }
void ofApp::mouseDragged(int x, int y, int button){ }
void ofApp::mousePressed(int x, int y, int button){ }
void ofApp::mouseReleased(int x, int y, int button){ }
void ofApp::mouseEntered(int x, int y){ }
void ofApp::mouseExited(int x, int y){ }
void ofApp::windowResized(int w, int h){ }
void ofApp::gotMessage(ofMessage msg){ }
void ofApp::dragEvent(ofDragInfo dragInfo){ }
