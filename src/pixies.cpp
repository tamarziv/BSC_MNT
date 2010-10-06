/*
 *  pixies.cpp
 *  BS_test
 *
 *  Created by Tamar Ziv on 3/10/10.
 *  Copyright 2010 __MyCompanyName__. All rights reserved.
 *
 */

#include "pixies.h"

pixies::pixies(ofImage* _img, float _thres)
{
	image = _img;	
	image->setImageType(OF_IMAGE_GRAYSCALE);
	thres = _thres;
	pixels = image->getPixels();
	
}

pixies::pixies ( ofxVec3f _posInit, ofxVec3f _posCurr, ofxVec3f _posTarget, float pColor, Perlin *_noise) 
{
	

}
void pixies::getPixelParticles()
{




}