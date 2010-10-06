/*
 *  pixies.h
 *  BS_test
 *
 *  Created by Tamar Ziv on 3/10/10.
 *  Copyright 2010 __MyCompanyName__. All rights reserved.
 *
 */


#ifndef _PIXIES_
#define _PIXIES_

#include <vector>
#include "ofxVec3f.h"
#include "ofMain.h"
#include "perlin.h"
#include "ofImage.h"
#include <vector> 

struct particle {
	ofxVec3f posStart;
	ofxVec3f posCurrent;
	ofColor color;
}

class pixies {
	public :
	pixies(ofImage *_img, float _thres);	
	pixies ( ofxVec3f _posInit, ofxVec3f _posCurr, ofxVec3f _posTarget, float pColor, Perlin *_noises);
	void getPixelParticles();
	
	ofImage				*image;
	unsigned char		*pixels;
	float				thres;
	int					cnt;
	bool				first;
	bool				moveBack;
	bool				moveCenter;
	vector <particle*	> pos;
	/*
	ofxVec3f posInit;
	ofxVec3f vel;
	ofxVec3f acc;
	Perlin *noise;
	
	int color;
	int life;
	int initLife;
	float size, iniSize;
	 */
	

	void update();
	void draw();
	void die();


}
















#endif

