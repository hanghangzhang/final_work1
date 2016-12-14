#pragma once

#include "ofMain.h"
#include "ofxCv.h"
#include "ofxFaceTracker.h"

class ofApp : public ofBaseApp {
public:
	void setup();
	void update();
	void draw();
	void keyPressed(int key);
    
    ofVideoPlayer babymirror;
	ofVideoGrabber cam;
	ofxFaceTracker tracker;
    ofxFaceTracker trackerV;

		
	ofEasyCam easyCam;
    int w=babymirror.getWidth();
    int h=babymirror.getHeight();
    ExpressionClassifier classifier;

};
