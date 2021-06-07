# 程序主框架

[TOC]

使用EasyX可以在控制台程序中显示图像、绘制图形，让程序变得美观点。基于此考虑，我们把程序界面设置为控制按钮+图形显示的形式。

## 主界面

![MainFace](https://i.loli.net/2021/06/07/scvMPXYfK7Eo9JO.png)

主界面由两张图片构成，左侧的工具栏为图片，右侧为加载的底图。

- 示例代码为：

```c++
#include <graphics.h>	//EasyX
#include <conio.h>		//_getch
int main()
{
	initgraph(1280, 720);	//initialize graphics

	IMAGE	img_bg;		//background image
	IMAGE	img_menu;	//menu image

    // load images
	loadimage(&img_bg, "C:\\image.jpg");
	loadimage(&img_menu, "C:\\MapDraw_UI.png");

    // display images
	putimage(200, 0, &img_bg);	
	putimage(0, 0, &img_menu);

    _getch();		//waitting for user input, = pause()
	closegraph();	//close graphics

    return 0;
}
```

## 如何响应按钮消息

当鼠标在工具栏图片对应按钮位置单击时，需要响应对应的功能。其实现思路是：

### 1.监听鼠标消息

以下代码监听了鼠标消息，当鼠标左键按下时，弹出一个消息框；当鼠标右键抬起时，退出程序。

```c++
int main()
{
    initgraph(1280, 720);
	//省略加载图片代码...

	MOUSEMSG msg;		//定义变量，保存鼠标消息
	FlushMouseMsgBuffer();// 清空鼠标消息缓冲区，避免无效鼠标信息带入到正式判断中
	bool	bExit = false;	//是否退出的标志

	while (!bExit)	//一直循环
	{
		while (MouseHit())	//检查鼠标消息
		{
			msg = GetMouseMsg();	//鼠标消息状态
			switch (msg.uMsg)
			{
			case WM_LBUTTONDOWN:	//左键按下
				MessageBox(NULL, "LButtonDown", "Info", MB_ICONINFORMATION);
				break;
			case WM_RBUTTONUP:		//右键抬起
				bExit = true;	//退出程序标记
				break;
			default:
				Sleep(10);	//休眠10ms
				break;
			}

			if (bExit) break;	//退出循环
		}
	}

	closegraph();

	return 0;
}
```

### 2. 根据鼠标消息的位置，判断单击的是哪个按钮

在WM_LBUTTONDOWN分支中，根据鼠标按钮的位置，来判断鼠标位置判断，返回鼠标所在位置的功能名称。

```c++
int main()
{
    //...
    		switch (msg.uMsg)
			{
			case WM_LBUTTONDOWN:	//左键按下
				bState = onCommand(CheckCommand(msg.x, msg.y));	//检查Command 并 执行
				break;
            }
	//...
}

// Command.h 
//定义窗口消息枚举，只定义了部分，后续自行添加
enum eWndCmd {
	WC_NULL,		//null command
	WC_LOADIMAGE,	//Load Image
	WC_LOADVECTOR,	//Load Vector
	WC_NEWVECTOR,	//New Vector
	WC_SAVE,		//Save Vector
	WC_EXIT = 999	//Exit
};

// Command.cpp
//-------------------------------------------------//
// 根据坐标返回CommandID
// 参数：int x - 
//		 int y - 
// 返回值: eWndCmd - CommandID，无返回WM_NULL
//-------------------------------------------------//
eWndCmd CheckCommand(int x, int y)
{
	eWndCmd	cmd = WC_NULL;

	if (x <= 160 && x >= 40)
	{
		if (y >= 35 && y <= 65)	cmd = WC_LOADIMAGE;
		else if (y >= 80 && y <= 110) cmd = WC_LOADVECTOR;
		else if (y >= 125 && y <= 155) cmd = WC_NEWVECTOR;
		else if (y >= 170 && y <= 200) cmd = WC_SAVE;
		else if (y >= 585 && y <= 615) cmd = WC_EXIT;
		else cmd = WC_NULL;
	}

	return cmd;
}
```

### 3.根据预设的按钮，执行与之对应的功能

```c++
//-----------------------------------------------------//
// 执行对应的Command函数
// 参数：eWndCmd cmd - CommandID
// 返回值： bool - 若退出返回false，其他返回true
//----------------------------------------------------//
bool onCommand(eWndCmd cmd)
{
	bool	bState = true;

	switch (cmd)
	{
	case WC_EXIT:
		bState = false;
		break;
	case WC_LOADIMAGE:
		MessageBox(NULL, "Load Image.", "Info", MB_ICONINFORMATION);
		break;
	case WC_LOADVECTOR:
		MessageBox(NULL, "Load Vector.", "Info", MB_ICONINFORMATION);
		break;
	case WC_NEWVECTOR:
		MessageBox(NULL, "New Vector.", "Info", MB_ICONINFORMATION);
		break;
	case WC_SAVE:
		MessageBox(NULL, "Save", "Info", MB_ICONINFORMATION);
		break;
	default:
		bState = true;
		break;
	}

	return bState;
}
```

至此程序的主框架基本完成。鼠标在左侧Menu图片上左键单击时，可以根据鼠标位置判断时哪个功能。后续要做的是，根据不同的功能分支，进入响应的处理函数即可。

---





