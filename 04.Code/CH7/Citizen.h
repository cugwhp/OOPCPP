#pragma once

#include <string>
using namespace std;

// class CCitizen
class CCitizen
{
public:
	CCitizen();
	~CCitizen(void);

	const string& GetName() const {return m_strName;}
	const string& GetId() const {return m_strId;}

protected:
	string		m_strName;
	string		m_strId;
};

//
class CStudent : public CCitizen
{
public:
	CStudent();
	~CStudent();

	const string& GetStudyId() const {return m_strStudyId;}
	int GetLevel() {return m_nLevel;}

protected:
	string		m_strStudyId;
	unsigned int	m_nLevel;
};