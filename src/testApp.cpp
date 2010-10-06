#include "testApp.h"


//--------------------------------------------------------------
void testApp::setup(){
	ofSetWindowTitle("template project");
	ofBackground(0, 0, 0);
	ofSetBackgroundAuto(true);
	ofSetFrameRate(60); // if vertical sync is off, we can go a bit fast... this caps the framerate at 60fps.
	ofSetVerticalSync(true);
	img.loadImage("testSmall3.gif");
	//img.setImageType(OF_IMAGE_GRAYSCALE);
	img.setImageType(OF_IMAGE_GRAYSCALE);
	pixels = img.getPixels();
	thres = 10;
	cnt=0;
	first = true;
	sample=1;
	resample = true;
}

//--------------------------------------------------------------
void testApp::update(){
	if (resample) {

	}
	if (!moveBack) {
		for (int i=0; i< pos.size(); i++) {
			//pos[i] +=ofxVec3f(0,1,0);
			pos[i].posCurr +=ofxVec3f(ofRandom(-mouseX/50, +mouseX/50), ofRandom(-mouseY/50, mouseY/50),0);
		}
	} else {
		
		if (!moveCenter) {
			for (int i=0; i< pos.size(); i++) {
				pos[i].posCenter = ofxVec3f(pos[i].posCurr.x, ofGetHeight()/2);
				ofxVec3f diff =  pos[i].posCenter - pos[i].posCurr;
				float mag = diff.length();
				ofxVec3f dir = diff.normalize();
				mag *= 0.05;
				pos[i].posCurr += dir*mag;
			}
			
			
		} else {
			for (int i=0; i< pos.size(); i++) {
				ofxVec3f diff =  pos[i].posInit - pos[i].posCurr;
				float mag = diff.length();
				ofxVec3f dir = diff.normalize();
				mag *= 0.05;
				pos[i].posCurr += dir*mag;
			}
		}				
	}
}
	void testApp::sampleImage(int sampleSize)
	{
		pos.clear();
		for (int y=0; y< img.getHeight()-sampleSize; y+= sampleSize)
		{
			for (int x=0; x< img.getWidth()-sampleSize; x+= sampleSize) {
				if ((float) pixels[y*(int)img.getWidth()+x] >=thres /*&& (float) pixels[y*(int)img.getWidth()+x] < 245*/) {
					pix p;
					p.posCurr = ofxVec3f(x,y,0);
					p.posInit = ofxVec3f(x,y,0);
					p.pixelColor = (float)pixels[y*(int)img.getWidth()+x];
					pos.push_back(p);
					//cout << (float)pixels[y*(int)img.getWidth()+x] << endl;
				} 
				
			}
		}
		
		
		
	}
	
	//--------------------------------------------------------------
	void testApp::draw(){
		glPointSize(sample);
		glBegin(GL_POINTS);
		for (int i=0; i< pos.size(); i++)
		{
			glColor3f(pos[i].pixelColor/255, pos[i].pixelColor/255, pos[i].pixelColor/255);
			glVertex3f(pos[i].posCurr.x, pos[i].posCurr.y, 0);
		}
		//cout << "total: " << cnt << endl;
		glEnd();
	}
	
	
	//--------------------------------------------------------------
	void testApp::keyPressed  (int key){
		if (key == 'f'){
			ofToggleFullscreen();
		}
		if (key == 'r'){
			moveBack =!moveBack;
		}
		if (key == 'c'){
			moveCenter =!moveCenter;
		}

		if (key == '+'){
			sample = sample++;
			sampleImage(sample);
			//resample=false;
			
		}
		if (key == '-'){
			sample = sample--;
			if (sample<=0) sample=1;
			sampleImage(sample);	
		}
		if (key == ' '){
			resample =!resample;
		}
		//if (key == 'p'){
		//	moveBack =false;
		//}
	}
	
	//--------------------------------------------------------------
	void testApp::keyReleased  (int key){
		
	}
	
	//--------------------------------------------------------------
	void testApp::mouseMoved(int x, int y ){
	}
	
	//--------------------------------------------------------------
	void testApp::mouseDragged(int x, int y, int button){
	}
	
	//--------------------------------------------------------------
	void testApp::mousePressed(int x, int y, int button){
	}
	
	
	//--------------------------------------------------------------
	void testApp::mouseReleased(int x, int y, int button){
		
	}
	
	//--------------------------------------------------------------
	void testApp::windowResized(int w, int h){
		
	}
