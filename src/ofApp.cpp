#include "ofApp.h"

using namespace ofxCv;

void ofApp::setup() {
	ofSetVerticalSync(true);
    babymirror.load("babymirror.mp4");
    babymirror.play();

	cam.initGrabber(ofGetWidth(), ofGetHeight());
	tracker.setup();
    trackerV.setup();
}

void ofApp::update() {
    babymirror.update();
    if(babymirror.isFrameNew()){
        trackerV.update(toCv(babymirror));
        classifier.classify(trackerV);
    }

	cam.update();
	if(cam.isFrameNew()) {
		tracker.update(toCv(cam));
	}
    
}

void ofApp::draw() {
	ofSetColor(255);
    babymirror.draw(0, -80, 1435, 1430);
    ofVec2f position=trackerV.getPosition();
    float x =position.x;
    float y=position.y;
//	cam.draw(0, 0);
//	ofDrawBitmapString(ofToString((int) ofGetFrameRate()), 10, 20);

	if(tracker.getFound()) {
//		tracker.draw();
		ofMesh objectMesh = tracker.getObjectMesh();
		ofMesh meanMesh = tracker.getMeanObjectMesh();

		ofSetupScreenOrtho(1435, 1430, -2000, 2000);
		ofTranslate(x+890,y+460);
		ofScale(8,15,15);
		cam.getTexture().bind();
		meanMesh.draw();
		cam.getTexture().unbind();
	}
}

void ofApp::keyPressed(int key) {
	if(key == 'r') {
		tracker.reset();
	}
}
