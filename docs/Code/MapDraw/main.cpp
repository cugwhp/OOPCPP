#include <graphics.h>
#include <conio.h>
#include "Command.h"

int main()
{
	initgraph(1280, 720);

	IMAGE	img_bg;
	IMAGE	img_menu;

	loadimage(&img_bg, "C:\\Users\\wanghp\\Desktop\\image.jpg");
	loadimage(&img_menu, "C:\\Users\\wanghp\\Desktop\\MapDraw_UI.png");

	putimage(200, 0, &img_bg);
	putimage(0, 0, &img_menu);

	Commander	cmder;
	cmder.Run();

	//_getch();
	closegraph();

	return 0;
}
