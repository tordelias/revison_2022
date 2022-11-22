#include "ofApp.h"
#include "Hero.h"
#include "GameManager.h"
#include "Ailien.h"

GameManager::STATUS GameManager::gameMode = GameManager::Start_SCREEN;

//float x = 250;
//float y = 50;
//float size1 = 50;
//int ammount = 5;

shared_ptr<Hero> superHero;
shared_ptr<Ailien> ailien;

//--------------------------------------------------------------
void ofApp::setup() {
	ofSetFrameRate(60);
	//ofSetRectMode(OF_RECTMODE_CENTER);
	float heroWidth = 50;
	float heroHeight = 100;
	float heroPositonX = 0;
	float heroPositonY = (ofGetWindowHeight() - heroHeight) / 2;
	ofColor heroColor = ofColor::cyan;

	float ailienWidth = 75;
	float ailienHeight = 150;
	float ailienPosX = ofGetWindowWidth() - ailienWidth;
	float ailienPosY = (ofGetWindowHeight() - ailienHeight) / 2;
	ofColor ailienColor = ofColor::magenta;

	superHero = make_shared<Hero>(heroPositonX, heroPositonY, heroWidth, heroHeight, heroColor);
	ailien = make_shared<Ailien>(ailienPosX, ailienPosY, ailienWidth, ailienHeight,ailienColor);
}

//--------------------------------------------------------------
void ofApp::update() {
	if (GameManager::gameMode == GameManager::RUN)
	{
		superHero->Update();
		ailien->Move();
	}

}

//--------------------------------------------------------------
void ofApp::draw() {
	
	GameManager::DisplayOnScreenMesseger();
	//if (GameManager::gameMode == GameManager::RUN)
	//{

	////for (int i = 0; i <= ammount; i++)
	////{
	////	ofNoFill();
	////	ofDrawRectangle(x, y, size1, size1);
	////	x = x + size1 / 2 + size1 * 1.25 / 2;
	////	size1 *= 1.25;
	////	if (i == ammount)
	////	{
	////		size1 = 10;
	////		x = 250;
	////	}
	////}
	//}
	superHero->Draw();
	ailien->Draw();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key) {
	if (key == OF_KEY_UP)
	{
		superHero->speedY = -3;
	}
	else if (key == OF_KEY_DOWN)
	{
		superHero->speedY = 3;
	}

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
