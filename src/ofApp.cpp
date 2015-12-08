#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    y.c.setHex(0xA79C26);
    y.width = 0.9;
    
    p.c.setHex(0xC781A8);
    p.width = 0.9;
    
    b.c.setHex(0x64A2C9);
    b.width = 1.1;
    
    k.c.setHex(0x222B32);
    k.width = 3.9;
    
    w.c.setHex(0xE3E2DE);
    w.width = 2.9;
    
    g.width = 2.9;
    
    int counter = 0;
    
    for (int i = 0; i <= 1000; i++){
        if(i == 500) stripes.push_back(w);
        else if(abs(i-500)%8 == 1) stripes.push_back(y);
        else if(abs(i-500)%8 == 2) stripes.push_back(p);
        else if(abs(i-500)%8 == 3) stripes.push_back(b);
        
        else if(abs(i-500)%8 == 5) stripes.push_back(b);
        else if(abs(i-500)%8 == 6) stripes.push_back(p);
        else if(abs(i-500)%8 == 7) stripes.push_back(y);
        else stripes.push_back(w);
    }
}

//--------------------------------------------------------------
void ofApp::update(){
    
    width = ofMap(mouseY, 0,ofGetHeight(),0.1,40);
}

//--------------------------------------------------------------
void ofApp::draw(){
    stripes[500].x = mouseX;
    ofSetColor(stripes[500].c);
    ofDrawRectangle(stripes[500].x, 0, stripes[500].width*width, ofGetWidth());
    
    for (int i = 499; i> 0; i--){
        ofSetColor(stripes[i].c);
        stripes[i].x = stripes[i+1].x - stripes[i].width*width;
        ofDrawRectangle(stripes[i].x, 0, stripes[i].width*width + 1, ofGetHeight());
    }
    
    for (int i = 501; i< stripes.size();i++) {
        ofSetColor(stripes[i].c);
        stripes[i].x = stripes[i-1].x + stripes[i-1].width*width;
        ofDrawRectangle(stripes[i].x, 0, stripes[i].width*width + 1, ofGetHeight());
    }
    
    cout << stripes.size()<< endl;
    
    ofSetColor(sin(ofGetElapsedTimef()*10)*100, 0,0);
    ofDrawRectangle(stripes[stripes.size()/2].x, 0, stripes[stripes.size()/2].width*width, ofGetWidth());
    
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
