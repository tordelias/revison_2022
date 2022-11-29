#include "ofApp.h"
#include "Hero.h"
#include "GameManager.h"
#include "Ailien.h"
#include "Claw.h"

GameManager::STATUS GameManager::gameMode = GameManager::Start_SCREEN;

shared_ptr<Hero> superHero;
shared_ptr<Ailien> ailien;
shared_ptr<Claw> claw;

float distanceX;
float distanceY;
float totalWidth;
float totalHeight;



//--------------------------------------------------------------
void ofApp::setup() {
	ofSetFrameRate(30);
	float heroWidth = 120;
	float heroHeight = 150;
	float heroPositonX = 0;
	float heroPositonY = (ofGetWindowHeight() - heroHeight) / 2;
	ofColor heroColor = ofColor::white;

	float ailienWidth = 110;
	float ailienHeight = 85;
	float ailienPosX = ofGetWindowWidth() - ailienWidth;
	float ailienPosY = (ofGetWindowHeight() - ailienHeight) / 2;
	ofColor ailienColor = ofColor::blue;
	
	float clawHeight = 30;
	float clawWidth = 50;


	superHero = make_shared<Hero>(heroPositonX, heroPositonY, heroWidth, heroHeight, heroColor);
	ailien = make_shared<Ailien>(ailienPosX, ailienPosY, ailienWidth, ailienHeight,ailienColor);
	claw = make_shared<Claw>( clawWidth, clawHeight,superHero);
	ailien->claw = claw;

	GameManager::gameMode = GameManager::Start_SCREEN;
}

//--------------------------------------------------------------
void ofApp::update() {
	if (GameManager::gameMode == GameManager::RUN)
	{

		superHero->Update();
		ailien->Move();
		claw->Move();
	}

}

//--------------------------------------------------------------
void ofApp::draw() {
	ofSetColor(178, 190, 181);
	ofDrawRectangle(0, 0, 1024, 768);
	superHero->Draw();
	ailien->Draw();
	claw->Draw();
	GameManager::DisplayOnScreenMesseger();
	//ofSetBackgroundColor(178, 190, 181);

	
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key) {
	if (key == OF_KEY_UP or key == 'w')
	{
		superHero->speedY = -3;
	}
	else if (key == OF_KEY_DOWN || key == 's')
	{
		superHero->speedY = 3;
	}

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key) {
	//if (key == 's')
	//{
	//	GameManager::gameMode = GameManager::END_GAME;
	//}
	if (key == 'f')
	{
		GameManager::gameMode = GameManager::RUN;
		
	}
	//if (key == 'd')
	//{
	//	GameManager::gameMode = GameManager::Start_SCREEN;
	//}
	if (key == 'g')
	{
		claw->clawReleaced = true;
		claw->speedX = 3;
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
