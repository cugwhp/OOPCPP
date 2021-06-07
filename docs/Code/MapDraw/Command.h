#pragma once
#include <graphics.h>

//���崰����Ϣö�٣�ֻ�����˲���
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
	void CheckCommand(int x, int y);// �������귵��CommandID
	void onLButtondown(const MOUSEMSG& msg);// ִ�ж�Ӧ��Command����

	bool IsExit() { return !m_bState; }
private:
	bool	m_bState;		//�Ƿ��˳�����ı��
	int		m_nDrawType;	//���Ƶ�״̬
	eWndCmd	m_eCurWndCmd;	//��ǰ��״̬
};
