#include <iostream>
#include "CImg.h"

using namespace std;
using namespace cimg_library;

int main()
{
	//define an unsigned char image with 640*400
	CImg<unsigned char>	img(640,400,1,3);

	// fill image using back color
	img.fill(0);

	//define purple color
	unsigned char purple[] = {255,0,255};

	//
	img.draw_text(100, 100, "Hello World", purple);
	img.display("My first CImg code");

    return 0;
}
