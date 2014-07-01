#pragma once

#include "ofMain.h"
#include "ofxUI.h"
#include "Composer.h"
#include "Player.h"

#include "UniformDistribution.h"
#include "LinearDistribution.h"
#include "TriangularDistribution.h"
#include "ExponentialDistribution.h"
#include "GaussianDistribution.h"
#include "CauchyDistribution.h"
#include "BetaDistribution.h"
#include "WeibullDistribution.h"
#include "PoissonDistribution.h"

#include <iostream>
using namespace std;
#include "ofxTonic.h"

using namespace Tonic;

class App : public ofBaseApp{
	
public:
	void setup();
	void update();
	void draw();
	void exit();
	
	void keyPressed(int key);
	void keyReleased(int key);
	void mouseMoved(int x, int y );
	void mouseDragged(int x, int y, int button);
	void mousePressed(int x, int y, int button);
	void mouseReleased(int x, int y, int button);
	void windowResized(int w, int h);
	
	void dragEvent(ofDragInfo dragInfo);
	void gotMessage(ofMessage msg);
    
	void audioRequested (float * output, int bufferSize, int nChannels);

	static float getFramerate(){ return ofGetFrameRate(); }
	
	static void setMidiNote(int note);
	static void setIsSilence(bool t);
	static void setVolume(float volume);
	static void setCurrentFigure(Figure * f);
private:
    
	Composer * composer;
	Player * player;
	static ofxTonicSynth synth;
	
	void initSynth();
	void initGUI();
	
	std::vector<Figure *> composition;
	
	UniformDistribution * uniform;
	LinearDistribution * linear;
	TriangularDistribution * triangular;
	ExponentialDistribution * exponential;
	GaussianDistribution * gauss;
	CauchyDistribution * cauchy;
	BetaDistribution * beta;
	WeibullDistribution * weibull;
	PoissonDistribution * poisson;
	
	ofxUITabBar *guiTabBar;
	vector<ofxUICanvas *> guis;
	void guiEvent(ofxUIEventArgs &e);
	
	ofxUICanvas *gui1;
	ofxUIScrollableCanvas *gui2;
	static ofxUITextArea *currentFigureLabel;
	
	
};
