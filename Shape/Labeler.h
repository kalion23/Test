// Labeler.h: interface for the Labeler class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_LABELER_H__53063506_6376_4254_AC74_DEA4CFC3C488__INCLUDED_)
#define AFX_LABELER_H__53063506_6376_4254_AC74_DEA4CFC3C488__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000



#include "../Scaler.h"
#include "Shapefile.h"
class CShapefile;


struct LabelObject
{
	double x;
	double y;
	CString label;
};

class Labeler  
{
public:
	void FreeAllLabelObject();


	CShapefile *shp;
	char		m_strDBFPath[500];

	// DBF���� ���
	DBF_FILEHEADER fHeader;
	// DBF �ʵ� ��� �迭
	DBF_FILEDDESCRIPTOR* pField ;
	// �ʵ��� ���� 
	int nfield;

	bool m_isLoad;
	// �� ������ 
	LabelObject * labels;
	// DBF �󿡼� �󺧷� ����ϴ� �Ӽ� �ε��� 
	int dbf_index;


	Labeler();
	~Labeler();

	void Open(char * filename, int index);
	void removeSpace(char *rec, int length);
	void readDBF();
	bool CalculateLabelPoint();
	void Draw(CDC *pDC, Scaler &scaler);
	void DrawText(CDC *pDC, CString str, long x, long y);
};

#endif // !defined(AFX_LABELER_H__53063506_6376_4254_AC74_DEA4CFC3C488__INCLUDED_)
