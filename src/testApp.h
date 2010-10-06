#ifndef _TEST_APP
#define _TEST_APP


#include "ofMain.h"
#include <vector>
#include "ofxVec3f.h"
#include "perlin.h"


struct pix{
	ofxVec3f posInit;
	ofxVec3f posCurr; 
	ofxVec3f posCenter;
	float pixelColor;
};
class testApp : public ofBaseApp{
	
public:
	void setup();
	void update();
	void draw();
		
	void keyPressed(int key);
	void keyReleased(int key);
	void mouseMoved(int x, int y );
	void mouseDragged(int x, int y, int button);
	void mousePressed(int x, int y, int button);
	void mouseReleased(int x, int y, int button);
	void windowResized(int w, int h);
	void sampleImage(int sampleSize);
	ofImage img;
	unsigned char * pixels;
	float thres;
	int cnt;
	int sample;
	int pSize;
	vector <pix> pos;
	bool first;
	bool moveBack;
	bool moveCenter;
	bool resample;

};

#endif
	
