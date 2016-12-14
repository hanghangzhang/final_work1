#include "ofApp.h"
#include "ofAppGlutWindow.h"

int main() {
	ofAppGlutWindow window;
	ofSetupOpenGL(&window, 1435, 1430, OF_WINDOW);
	ofRunApp(new ofApp());
}
