#include "Sprite.h"
using namespace std ;
Sprite::Sprite(const char* filename) {

	char path[300];
	memset(path,'\0',300);
	strcpy_s(path,RGBA_FOLDER);
	strcat_s(path,"\\");
	strcat_s(path,RGBA_SIZE);
	strcat_s(path,"\\");
	strcat_s(path,filename);
	ifstream imageFile(path);		//open a file


	//read width and hieght
	imageFile >> _width >> _height;

	//creat a matrix and read into it the pixels
	_image  = new RGBA*[_height];
	for(int i=0; i<_height; i++){
		_image[i] = new RGBA[_width];
		for(int j=0; j< _width; j++){
			imageFile >> _image[i][j]._r >> _image[i][j]._g >> _image[i][j]._b >> _image[i][j]._a;  
		}
	}

	//close the file
	imageFile.close();
}


void Sprite::Draw(const Vertex &cord){
	glBegin(GL_POINTS);	
	int y=0,x=_width;
	for(int i=0; i<_height;i++){
		x=_width;
		for(int j=0; j< _width; j++){
			glColor4ub(_image[i][j]._r, _image[i][j]._g, _image[i][j]._b, _image[i][j]._a);
			glVertex2i(x + cord._x ,(20*28)-(y + cord._y));
			//cout << x + cord._x << y + cord._y<< endl;
			x++;
		}
		y++;
	}

	glEnd();

}