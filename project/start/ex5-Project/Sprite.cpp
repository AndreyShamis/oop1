#include "Sprite.h"

using namespace std ;

//=============================================================================
Sprite::~Sprite()
{
	//for(int i=0;i<_height;i++)
	//{
	//	delete	  _image[i];
	//}
	//delete [] _image;
}
Sprite::Sprite(const char* filename) {


	char path[200];
	memset(path,'\0',200);
	strcpy_s(path,RGBA_FOLDER);
	strcat_s(path,"\\");
	strcat_s(path,RGBA_SIZE);
	strcat_s(path,"\\");
	strcat_s(path,filename);
	ifstream imageFile(path);		//open a file

	if(!imageFile.is_open())
	{
		cout << "Can`t load file " << path << "\n";
		exit(EXIT_FAILURE);
	}
		//get from the file width and hieght og image
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