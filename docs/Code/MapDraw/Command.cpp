#include "Command.h"
#include <graphics.h>

Commander::Commander()
{
	m_bState = true;	//��ʼΪture���˳���ť����Ϊfalse�������˳�Run
	m_nDrawType = 0;
}


//---------------------------------------------------------------//
// Run() - ���������Ϣ��һֱ�����š�����
//--------------------------------------------------------------//
void Commander::Run()
{
	MOUSEMSG msg;		//������������������Ϣ
	FlushMouseMsgBuffer();// ��������Ϣ��������������Ч�����Ϣ���뵽��ʽ�ж���

	while (m_bState)	//һֱѭ��
	{
		while (MouseHit())	//��������Ϣ
		{
			msg = GetMouseMsg();	//�����Ϣ״̬
			switch (msg.uMsg)
			{
			case WM_LBUTTONDOWN:	//�������
				onLButtondown(msg);
				break;
			default:
				Sleep(10);	//����10ms
				break;
			}

			if (IsExit()) break;	//�˳�ѭ��
		}
	}
}

//-----------------------------------------------------------------------//
// ִ�ж�Ӧ��Command����
// ������eWndCmd cmd - CommandID
// ����ֵ�� bool - ���˳�����false����������true
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
// �������귵��CommandID
// ������int x - 
//		 int y - 
// ����ֵ: eWndCmd - CommandID���޷���WM_NULL
//-----------------------------------------------------------------------//
void Commander::CheckCommand(int x, int y)// �������귵��CommandID
{
	if (x <= 160 && x >= 40)	//��ఴť
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
	else if (x > 200)	//�Ҳ��ͼ����
	{
		m_eCurWndCmd = WC_DRAW;
	}
	else
	{
		m_eCurWndCmd = WC_NULL;
	}
}
