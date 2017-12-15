#Top 4 Open Source Image Library
简要介绍四大图像库：OpenCV/FreeImage/CImg/CxImage

___

##1.OpenCV
1.对OpenCV 的印象：功能十分的强大，而且支持目前先进的图像处理技术，体系十分完善，操作手册很详细，手册首先给大家补计算机视觉的知识，几乎涵盖了近10年内的主流算法；

然后将图像格式和矩阵运算，然后将各个算法的实现函数。
我用它来做了一个Harris角点检测器和Canny边缘检测器，总共就花了一个小时（第一次用OpenCV）。
而且该库显示图像极其方便，两句话就可以。
但该库似乎不大稳定，对32F和16S、8U的图像数据支持上bug重重。
我用 cvFilter2D函数进行线性滤波，屡屡出错，后来一查原来是大bug。
后来用cvmGet来取矩阵元素也是频繁出错，仔细检查了N遍确保程序没问题之后在yahoogroup上找到答案：仍然是bug。。。
但好歹该库是开放的，所以自己可以修改；而且支持CVS。另外该库用的是IPL矩阵库，速度奇快～～
<http://sourceforge.net/projects/opencvlibrary/>

##2.CxImage
2.对CxImage 考察的印象：该开发包完全开放源代码，图像封装为一个类，功能极为强大，与Windows、MFC支持极好

，支持图像的多种操作（线性滤波、中值滤波、直方图操作、旋转缩放、区域选取、阈值处理、膨胀腐蚀、alpha混合等等）
，支持从文件、内存或者win32api 定义的位图图像格式中读取图像，支持将图像显示在任意窗口
，功能可谓很强大了，而且对像素的操作很方便
，另外还有一个界面很强的demo，可以直接在上面进行二次开发，推荐使用！

缺点：里面的子库很多，用起来可能较麻烦；而且感觉速度稍慢，不如后面提到的freeimage
但功能真的十分强大啊！
<http://www.xdp.it/cximage.htm>


##3.CImg
### 3.1 Introduction

[CImg](www.cimg.eu) is a convient and simple image process toolkit with C++ template library. 

[CImg](www.cimg.eu) has some strong alogrithm supported by LAPACK in image filtering, neighbor calculation, registration, etc. Moreover, it can display image, text, line, rectangle etc.

There are some open source using [CImg](www.cimg.eu). 

### 3.2 Compile

Compile CImg is simple, only include <cimg.h> in your projects.

CImg supports many image formats, such as jpeg, png, tiff etc by the 3rd library. If you want CImg supports the 3rd lirary, you need download the 3rd library, and compile CImg. The following is the CImg supports [libjpeg steps](https://stackoverflow.com/questions/46055720/cannot-load-any-image-with-cimg/46058914#46058914).

Visit [Git](https://github.com/dtschump/CImg) to colne CImg code source.

### 3.3 [Tutorial](http://cimg.eu/reference/group__cimg__tutorial.html)

[Tutorial : Getting Started](http://cimg.eu/reference/group__cimg__tutorial.html)

- sample code

```c++
// using JPEG, need prepare libjpeg
#define XMD_H
#define cimg_use_jpeg

// using CImg
#include "CImg.h"
using namespace cimg_library;	//namespace

// main function
int main() 
{
  // define 2 image object, one for image data, the other for image profile
  CImg image("lena.jpg"), visu(500,400,1,3,0);
  
  // define different color to draw plot
  const unsigned char red[] = { 255,0,0 }, green[] = { 0,255,0 }, blue[] = { 0,0,255 };
 
  // Blur the image, with a gaussian blur and a standard variation of 2.5.
  image.blur(2.5);
  
  // Creation of two display windows, one for the input image image, and one for the image visu which will be display intensity profiles. By default, CImg displays handles events (mouse,keyboard,..). 
  CImgDisplay main_disp(image,"Click a point"), draw_disp(visu,"Intensity profile");
  
  // event loop
  while (!main_disp.is_closed() && !draw_disp.is_closed()) 
  {
    main_disp.wait();	//blank loop
    if (main_disp.button() && main_disp.mouse_y()>=0) 
    {
      // click y position
      const int y = main_disp.mouse_y();
      
      visu.fill(0);	// clear visu
     
      // get_crop(x,y,z,c) and draw_graph in visu(image)
      visu.draw_graph(image.get_crop(0,y,0,0,image.width()-1,y,0,0),red,1,1,0,255,0);
      visu.draw_graph(image.get_crop(0,y,0,1,image.width()-1,y,0,1),green,1,1,0,255,0); 
      visu.draw_graph(image.getcrop(0, y,0,2,image.width()-1,y,0,2),blue,1,1,0,255, 0);
     
      //Display visu
      draw_disp.display(visu);
    }
  }
  return 0;
}
```

- 程序截图![image](http://cimg.eu/img/tutorial.jpg)

##4.FreeImg
4.FreeImage ：C语言的体系，大量使用指针运算速度可以保证，内含先进的多种插值算法。
另外独有的支持meta exif信息的读取。该库最大的特点就是比较简练，只把重点放在对各种格式图像的读取写入支持上，没有显示部分，实际编程的时候还是需要调用API函数进行显示。
<http://freeimage.sourceforge.net/>