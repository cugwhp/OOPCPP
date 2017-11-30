#include "Point.h"
#include <iostream>
using namespace std;

int Point::m_ptCount = 0;

Point::Point()
{
    m_ptCount++;

    cout << m_ptCount << " Point::Point()" << endl;
}

Point::~Point()
{
    cout << m_ptCount << " Point::~Point()" << endl;
    m_ptCount--;
}
