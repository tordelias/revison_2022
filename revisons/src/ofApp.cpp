#include "ofApp.h"
#include "Hero.h"
#include "GameManager.h"
#include "Ailien.h"
#include "Claw.h"

GameManager::STATUS GameManager::gameMode = GameManager::Start_SCREEN;
//bool ailienDead = false;

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
	
	float clawHeight = heroHeight / 100;
	float clawWidth = 50;


	superHero = make_shared<Hero>(heroPositonX, heroPositonY, heroWidth, heroHeight, heroColor);
	ailien = make_shared<Ailien>(ailienPosX, ailienPosY, ailienWidth, ailienHeight,ailienColor);
	claw = make_shared<Claw>( clawWidth, clawHeight,superHero);
	ailien->claw = claw;


}

//--------------------------------------------------------------
void ofApp::update() {
	if (GameManager::gameMode == GameManager::RUN)
	{
		//distanceX = abs((claw->x + claw->width) - (ailien->x + ailien->width));
		//distanceY = abs((claw->y + claw->height) - (ailien->y + ailien->height));
		//totalWidth = claw->width + ailien->width;
		//totalHeight = claw->height + ailien->height;

		superHero->Update();
		ailien->Move();
		claw->Move();
		//if (distanceX <= totalWidth && distanceY <= totalHeight)
		//{
		//	ailienDead = true;
		//}
		//if (claw->clawReleaced == false)
		//{
		//	ailienDead = false;
		//}
	}

}

//--------------------------------------------------------------
void ofApp::draw() {
	
	GameManager::DisplayOnScreenMesseger();
	superHero->Draw();
	ailien->Draw();
	claw->Draw();
	//if (ailienDead == false)
	//{
	//	ailien->Draw();
	//}
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
