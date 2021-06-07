#pragma once
#include <graphics.h>

//定义窗口消息枚举，只定义了部分
enum eWndCmd {
	WC_NULL,		//null command
	WC_LOADIMAGE,	//Load Image
	WC_LOADVECTOR,	//Load Vector
	WC_NEWVECTOR,	//New Vector
	WC_SAVE,		//Save Vector
	WC_DRAWPOINT,	//Draw Point
	WC_DRAWLINE,	//Draw Line
	WC_DRAWPOLYGON,	//Draw Polygon
	WC_MOVE,		//Move
	WC_DEL,			//Del
	WC_MODIFY,		//Modify
	WC_DRAW,		//Draw Action
	WC_EXIT = 999	//Exit
};

class Commander
{
public:
	Commander();

	//
	void Run();
protected:
	void CheckCommand(int x, int y);// 根据坐标返回CommandID
	void onLButtondown(const MOUSEMSG& msg);// 执行对应的Command函数

	bool IsExit() { return !m_bState; }
private:
	bool	m_bState;		//是否退出程序的标记
	int		m_nDrawType;	//绘制的状态
	eWndCmd	m_eCurWndCmd;	//当前的状态
};
