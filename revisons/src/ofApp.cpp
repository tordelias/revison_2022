#include "ofApp.h"
#include "Hero.h"
#include "GameManager.h"
#include "Ailien.h"
#include "Claw.h"
#include "FireBall.h"

GameManager::STATUS GameManager::gameMode = GameManager::Start_SCREEN;

shared_ptr<Hero> superHero;
shared_ptr<Ailien> ailien;
shared_ptr<Claw> claw;
shared_ptr<FireBall> fireBall;

float distanceX;
float distanceY;
float totalWidth;
float totalHeight;

ofImage background;

// countDown
float countdownGiven;
float countdownToCalculate;
float countdownToDisplay;
float StartTime;
std::ostringstream countdownStream;
bool startTimer = false;

int score = 0;


//--------------------------------------------------------------
void ofApp::setup() {
	//CountDown
	StartTime = ofGetElapsedTimef();
	countdownGiven = 30;
	countdownToCalculate = countdownGiven;
	countdownStream << fixed << setprecision(2);


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

	float fireBallHeight = 50;
	float fireBallWidth = 150;


	superHero = make_shared<Hero>(heroPositonX, heroPositonY, heroWidth, heroHeight, heroColor);
	ailien = make_shared<Ailien>(ailienPosX, ailienPosY, ailienWidth, ailienHeight,ailienColor);
	claw = make_shared<Claw>( clawWidth, clawHeight,superHero);
	fireBall = make_shared<FireBall>(fireBallWidth, fireBallHeight);

	ailien->claw = claw;
	fireBall->superHero = superHero;

	background.loadImage("Space_Background_0.png");
	fireBall->Setup();
	superHero->Setup();
	ailien->Setup();
	claw->Setup();


	GameManager::gameMode = GameManager::Start_SCREEN;
}

//--------------------------------------------------------------
void ofApp::update() {
	if (GameManager::gameMode == GameManager::RUN)
	{
		ailien->framNumber += 1;
		superHero->Update();
		ailien->Move();
		claw->Move();
		fireBall->Move();

		//countDown
		
		float timerCounted = ofGetElapsedTimef() - StartTime;
		countdownToDisplay = countdownToCalculate - timerCounted;
		if (countdownToDisplay <= 0)
		{
			countdownToDisplay = 0;
		}
		countdownStream.str("0:00");
		countdownStream << countdownToDisplay;
		if (countdownToDisplay == 0 and score > 0)
		{
			GameManager::gameMode = GameManager::VICTORY;
		}
		else if (countdownToDisplay == 0)
		{
			GameManager::gameMode = GameManager::END_GAME;
		}
		score = ailien->ailianScore;
	}
	//if (startTimer)
	//{
	//	//countdownGiven = 30;
	//	StartTime = ofGetElapsedTimef();
	//	startTimer = false;
	//}

}

//--------------------------------------------------------------
void ofApp::draw() {
	ofSetColor(178, 190, 181);
	/*ofDrawRectangle(0, 0, 1024, 768);*/
	background.draw(0, 0, 1024, 768);
	superHero->Draw();
	ailien->Draw();
	claw->Draw();
	fireBall->Draw();
	GameManager::DisplayOnScreenMesseger();
	//ofSetBackgroundColor(178, 190, 181);
	ofSetColor(120, 255, 100);
	ofDrawBitmapString(countdownStream.str() + "sec remaining...", 350, 50);
	ofDrawBitmapString("Score: " + to_string(score), 150, 50);
	if (GameManager::gameMode == GameManager::VICTORY)
	{
		ofDrawBitmapString("final score is " + to_string(score), 250, 300);
	}
	
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
	if (key == 'f' && GameManager::Start_SCREEN || GameManager::END_GAME)
	{
		GameManager::gameMode = GameManager::RUN;
		startTimer = true;
		
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

//void Reset()
//{
//	if(startTimer)
//	{
//		countdownToCalculate = countdownGiven - 2;
//		ofResetElapsedTimeCounter();
//	}
//}
