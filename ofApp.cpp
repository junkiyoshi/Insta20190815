#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {

	ofSetFrameRate(60);
	ofSetWindowTitle("openframeworks");

	ofBackground(239);
	ofSetColor(39);
	ofSetLineWidth(2);
	ofEnableDepthTest();
}
//--------------------------------------------------------------
void ofApp::update() {

	ofSeedRandom(39);
}

//--------------------------------------------------------------
void ofApp::draw() {

	this->cam.begin();

	auto R = 300.f;
	auto r = 80.f;

	for (auto i = 0; i < 30; i++) {

		ofRotate(ofRandom(360));

		auto v_start = ofRandom(15, 360) + ofGetFrameNum();
		for (auto v = v_start - 15; v < v_start + 15; v += 0.5) {

			auto u = v * 8.f;
			ofSetColor(ofMap(abs(v - v_start), 0, 15, 39, 239));
			ofDrawSphere(this->make_point(R, r, u, v), ofMap(abs(v - v_start), 0, 15, 6, 1));
		}
	}

	this->cam.end();
}

//--------------------------------------------------------------
glm::vec3 ofApp::make_point(float R, float r, float u, float v) {

	// 数学デッサン教室 描いて楽しむ数学たち　P.31

	u *= DEG_TO_RAD;
	v *= DEG_TO_RAD;

	auto x = (R + r * cos(u)) * cos(v);
	auto y = (R + r * cos(u)) * sin(v);
	auto z = r * sin(u);

	return glm::vec3(x, y, z);
}


//--------------------------------------------------------------
int main() {

	ofSetupOpenGL(720, 720, OF_WINDOW);
	ofRunApp(new ofApp());
}