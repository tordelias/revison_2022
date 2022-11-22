#include "ofApp.h"

#include "GameManager.h"

GameManager::STATUS GameManager::gameMode = GameManager::Start_SCREEN;

float x = 250;
float y = 50;
float size1 = 50;
int ammount = 5;

//--------------------------------------------------------------
void ofApp::setup() {
	ofSetFrameRate(15);
	ofSetRectMode(OF_RECTMODE_CENTER);
	//y = ofGetWindowHeight() / 2;
}

//--------------------------------------------------------------
void ofApp::update() {

}

//--------------------------------------------------------------
void ofApp::draw() {
	
	GameManager::DisplayOnScreenMesseger();
	if (GameManager::gameMode == GameManager::RUN)
	{
	for (int i = 0; i <= ammount; i++)
	{
		ofNoFill();
		ofDrawRectangle(x, y, size1, size1);
		x = x + size1 / 2 + size1 * 1.25 / 2;
		size1 *= 1.25;
		if (i == ammount)
		{
			size1 = 10;
			x = 250;
		}
	}
	}
	
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key) {

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key) {
	if (key == 's')
	{
		GameManager::gameMode = GameManager::END_GAME;
	}
	if (key == 'a')
	{
		GameManager::gameMode = GameManager::RUN;
	}
	if (key == 'd')
	{
		GameManager::gameMode = GameManager::Start_SCREEN;
	}
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h) {

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg) {

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo) {

}
