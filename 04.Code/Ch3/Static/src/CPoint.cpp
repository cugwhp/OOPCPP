#include "CPoint.h"
#include <iostream>

using namespace std;

int  CPoint::m_nCount = 0;

CPoint::CPoint()
{
     m_nCount++;
}

CPoint::~CPoint()
{
    m_nCount--;
}

void
CPoint::ShowCount()
{
    cout << m_nCount << endl;
}
