#include "Sprite.h"

using namespace std ;

//=============================================================================
//	return height
int Sprite::getHeight()
{
	return(_height);
}
//=============================================================================
//	return width
int Sprite::getWidth()
{
	return(_width);
}
//=============================================================================
//	Class constructor 
Sprite::Sprite(const char* filename) {


	char path[CHAR_MAX_STR_LEN];		//	variable for get riht path
	//	manipulation whith char
	memset(path,'\0',CHAR_MAX_STR_LEN);
	strcpy_s(path,RGBA_FOLDER);
	strcat_s(path,"\\");
	strcat_s(path,RGBA_SIZE);
	strcat_s(path,"\\");
	strcat_s(path,filename);
	// and manipulation and open file
	ifstream imageFile(path);		//open a file

	if(!imageFile.is_open())
	{
		cout << "Can`t load file " << path << "\n";
		exit(EXIT_FAILURE);
	}
		//get from the file width and hieght of image
	imageFile >> _width >> _height;

	_image  = new RGBA*[_height];
	for(int i=0; i<_height; i++){
		_image[i] = new RGBA[_width];
		for(int j=0; j< _width; j++){
			imageFile >> _image[i][j]._r >> _image[i][j]._g >> _image[i][j]._b >> _image[i][j]._a;  
		}
	}

	
	imageFile.close();		//close the file
}

//=============================================================================
//	Draw function
void Sprite::Draw(const Vertex &cord){
	glBegin(GL_POINTS);	
	int y=0,x=_width;
	for(int i=0; i<_height;i++){
		x=_width;
		for(int j=0; j< _width; j++){
			glColor4ub(_image[i][j]._r, _image[i][j]._g, _image[i][j]._b, _image[i][j]._a);
			glVertex2i(x + cord._x ,(20*PIC_WIDTH)-(y + cord._y));
			x++;
		}
		y++;
	}

	glEnd();

}