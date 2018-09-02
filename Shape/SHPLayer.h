// Layer.h: interface for the Layer class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_LAYER_H__DEA5EFF1_0BC9_405F_80DE_3C222DC3CFA9__INCLUDED_)
#define AFX_LAYER_H__DEA5EFF1_0BC9_405F_80DE_3C222DC3CFA9__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Shapefile.h"
#include "Labeler.h"

class SHPLayer  
{
public:

	CShapefile m_shp;	
	Labeler m_label;

	bool m_isOn;		// ���̾� ǥ�� ���� 
	bool m_isSelect;	// ���̾� ���� ���� (���� �˻��� ���)
	bool m_isLabelOn;	// ���̾��� �� ǥ�� ���� 
	
	int m_MaxScale;		// ���̾� ǥ�� �ִ� ��ĳ��
	int m_MinScale;		// ���̾� ǥ�� �ּ� ������

	SHPLayer();
	void Draw(CDC* pDC, Scaler& sc, ClickedObject *pClickedObject);
	void OpenFile(char* filename);
	virtual ~SHPLayer();

};

#endif // !defined(AFX_LAYER_H__DEA5EFF1_0BC9_405F_80DE_3C222DC3CFA9__INCLUDED_)
