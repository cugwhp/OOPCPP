#ifndef _RS_IMAGE_H_INC_
#define _RS_IMAGE_H_INC_

#ifndef NULL
#define NULL 0
#endif	//#ifndef NULL

enum INTERLEAVE_TYPE {BSQ,BIP,BIL};

class CRSImage
{
public:
	typedef unsigned char	DataType;

	CRSImage();
	CRSImage(const CRSImage& img);
	~CRSImage();

	// Operations
	bool	Open(const char* lpstrPath);
	inline bool	IsOpen() const { return (NULL != m_pppData ? true : false);}
	bool	Save(const char* lpstrPath);
	void	Close();
	void	PrintInfo();
	int		CalcStatistics();
	int		Histogram();
	void	Rotate(float fAngle);
	void	Zoom(float fZoom);
	void	Filter(double* dFilterKernel, int nSize);

	inline int	GetBands() const {return m_nBands;}
	inline int	GetLines() const {return m_nLines;}
	inline int GetSamples() const {return m_nSamples;}
	inline DataType*** GetDataBuffer() const {return m_pppData;}

protected:
	bool	ReadMetaData(const char* lpstrMetaFilePath);
	bool	InitBuffer(void);
	bool	ReadImgData(const char* lpstrImgFilePath);

protected:
	DataType***		m_pppData;
	int				m_nBands;
	int				m_nLines;
	int				m_nSamples;
	INTERLEAVE_TYPE m_eInterleave;
	short       m_nDataType;
private:
};

#endif	//#ifndef _RS_IMAGE_H_INC_
