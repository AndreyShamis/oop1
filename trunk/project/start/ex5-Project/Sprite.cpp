#include "Sprite.h"
using namespace std ;
Sprite::Sprite(const char* filename) {
	//open a file
	ifstream imageFile(filename);

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
	int y=_height,x=_width;
	for(int i=0; i<_height;i++){
		x=_width;
		for(int j=0; j< _width; j++){
			glColor4ub(_image[i][j]._r, _image[i][j]._g, _image[i][j]._b, _image[i][j]._a);
			glVertex2i(x + cord._x ,y + cord._y);
			x++;
		}
		y--;
	}

	glEnd();

}