#include "Command.h"
#include <graphics.h>

Commander::Commander()
{
	m_bState = true;	//初始为ture，退出按钮设置为false，程序退出Run
	m_nDrawType = 0;
}


//---------------------------------------------------------------//
// Run() - 监听鼠标消息，一直运行着。。。
//--------------------------------------------------------------//
void Commander::Run()
{
	MOUSEMSG msg;		//定义变量，保存鼠标消息
	FlushMouseMsgBuffer();// 清空鼠标消息缓冲区，避免无效鼠标信息带入到正式判断中

	while (m_bState)	//一直循环
	{
		while (MouseHit())	//检查鼠标消息
		{
			msg = GetMouseMsg();	//鼠标消息状态
			switch (msg.uMsg)
			{
			case WM_LBUTTONDOWN:	//左键按下
				onLButtondown(msg);
				break;
			default:
				Sleep(10);	//休眠10ms
				break;
			}

			if (IsExit()) break;	//退出循环
		}
	}
}

//-----------------------------------------------------------------------//
// 执行对应的Command函数
// 参数：eWndCmd cmd - CommandID
// 返回值： bool - 若退出返回false，其他返回true
//-----------------------------------------------------------------------//
void Commander::onLButtondown(const MOUSEMSG& msg)
{
	CheckCommand(msg.x, msg.y);

	switch (m_eCurWndCmd)
	{
	case WC_EXIT:
		m_bState = false;
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
		m_bState = true;
		break;
	}
}
//-----------------------------------------------------------------------//
// 根据坐标返回CommandID
// 参数：int x - 
//		 int y - 
// 返回值: eWndCmd - CommandID，无返回WM_NULL
//-----------------------------------------------------------------------//
void Commander::CheckCommand(int x, int y)// 根据坐标返回CommandID
{
	if (x <= 160 && x >= 40)	//左侧按钮
	{
		if (y >= 35 && y <= 65)	m_eCurWndCmd = WC_LOADIMAGE;
		else if (y >= 80 && y <= 110) m_eCurWndCmd = WC_LOADVECTOR;
		else if (y >= 125 && y <= 155) m_eCurWndCmd = WC_NEWVECTOR;
		else if (y >= 170 && y <= 200) m_eCurWndCmd = WC_SAVE;

		else if (y >= 250 && y <= 280) m_eCurWndCmd = WC_DRAWPOINT;
		else if (y >= 295 && y <= 325) m_eCurWndCmd = WC_DRAWPOLYGON;
		else if (y >= 340 && y <= 370) m_eCurWndCmd = WC_DRAWLINE;

		else if (y >= 415 && y <= 415) m_eCurWndCmd = WC_MOVE;
		else if (y >= 460 && y <= 490) m_eCurWndCmd = WC_DEL;
		else if (y >= 505 && y < 535) m_eCurWndCmd = WC_MODIFY;
		else if (y >= 585 && y <= 615) m_eCurWndCmd = WC_EXIT;

		else m_eCurWndCmd = WC_NULL;
	}
	else if (x > 200)	//右侧绘图区域
	{
		m_eCurWndCmd = WC_DRAW;
	}
	else
	{
		m_eCurWndCmd = WC_NULL;
	}
}
