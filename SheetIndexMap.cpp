// SheetIndexMap.cpp : implementation file
//

#include "stdafx.h"
#include "GDF.h"
#include "SheetIndexMap.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CSheetIndexMap property page

IMPLEMENT_DYNCREATE(CSheetIndexMap, CPropertyPage)

CSheetIndexMap::CSheetIndexMap() : CPropertyPage(CSheetIndexMap::IDD)
{
	LayerCnt = 0;
	m_pLayerListSHP = NULL;
	m_pLayerList = NULL;
	//{{AFX_DATA_INIT(CSheetIndexMap)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}

CSheetIndexMap::~CSheetIndexMap()
{
}

void CSheetIndexMap::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPage::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CSheetIndexMap)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CSheetIndexMap, CPropertyPage)
	//{{AFX_MSG_MAP(CSheetIndexMap)
	ON_WM_PAINT()
	ON_BN_CLICKED(IDC_BUTTON1, OnButton1)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSheetIndexMap message handlers

void CSheetIndexMap::OnPaint() 
{
	return;

	CPaintDC dc(this); // device context for painting
	
	
	dc.FloodFill(0,0,RGB(255,255,255));
	
	if(m_pLayerList != NULL)
	{

		// ȭ���� ũ��
		if(m_Render==false)
		{
			double x1,y1,x2,y2;
			
			m_Scaler.mxMin = m_pParentScaler->mxMin;	
			m_Scaler.myMin = m_pParentScaler->myMin;
			m_Scaler.mxMax = m_pParentScaler->mxMax;
			m_Scaler.myMax = m_pParentScaler->myMax;
			m_Scaler.mox = (m_Scaler.mxMax + m_Scaler.mxMin) / 2;
			m_Scaler.moy = (m_Scaler.myMax + m_Scaler.myMin) / 2;
			
			// 	m_Scaler.DeviceToWorld(rect.left,rect.top,&x1,&y1);
			// 	m_Scaler.DeviceToWorld(rect.right,rect.bottom,&x2,&y2);
			
			m_Scaler.DeviceToWorld(INDEXMAP_POS_MIN,INDEXMAP_POS_MIN,&x1,&y1);
			m_Scaler.DeviceToWorld(INDEXMAP_POS_MAX,INDEXMAP_POS_MAX,&x2,&y2);
			
			m_Scaler.mxMin = x1;	
			m_Scaler.myMin = y2;
			m_Scaler.mxMax = x2;
			m_Scaler.myMax = y1;
			m_Scaler.mox = (m_Scaler.mxMax + m_Scaler.mxMin) / 2;
			m_Scaler.moy = (m_Scaler.myMax + m_Scaler.myMin) / 2;
			
			m_Render = true;
		}

		//////////////////////////
		//		�׳� �׸���		//
		//////////////////////////
		//m_pLayerList->DrawLayer(&dc,m_Scaler);
		//////////////////////////

		////////////////
		// ������۸� //
		////////////////
		CRect m_rtCtrlSize;
		GetClientRect(&m_rtCtrlSize);
		
		// �����Ͱ� �ٲ������(�߰�/����)
		if(m_pLayerList->m_Cnt != LayerCnt)
		{
			CRect m_rtCtrlSize;
			GetClientRect(&m_rtCtrlSize);
			m_mDC->DeleteDC();
			m_mDC->CreateCompatibleDC(&dc);
			m_Bitmap->DeleteObject();
			m_Bitmap->CreateCompatibleBitmap(&dc, m_rtCtrlSize.Width(), m_rtCtrlSize.Height());   
			m_mDC->SelectObject(m_Bitmap);
			m_mDC->PatBlt(0,0,m_rtCtrlSize.Width(), m_rtCtrlSize.Height(), WHITENESS);
			
			// �׸� �׸��� �κ�(mDC�� �׸��׸���)
			m_pLayerList->DrawLayer(m_mDC,m_Scaler);
			LayerCnt = m_pLayerList->m_Cnt;
		}
		//�޸� DC���� �׸� �׸� �ٿ��ֱ�
		dc.BitBlt(0, 0, m_rtCtrlSize.Width(), m_rtCtrlSize.Height(), m_mDC, 0, 0, SRCCOPY);
		
		//�簢�� �׸���
		DrawRectangle(dc);
	}

	if(m_pLayerListSHP != NULL)
	{
		m_pLayerListSHP->DrawLayer(&dc,m_Scaler,NULL);
		DrawRectangle(dc);
	}

	// Do not call CPropertyPage::OnPaint() for painting messages
}

void CSheetIndexMap::OnButton1() 
{


}

BOOL CSheetIndexMap::OnInitDialog() 
{
	CPropertyPage::OnInitDialog();
	
	RECT rect;
	GetClientRect(&rect);
	m_Scaler.sxMin = INDEXMAP_POS_MIN;
	m_Scaler.syMin = INDEXMAP_POS_MIN;
	m_Scaler.sxMax = INDEXMAP_POS_MAX;//rect.right;
	m_Scaler.syMax = INDEXMAP_POS_MAX;//rect.bottom;
	
	m_Scaler.sox = (m_Scaler.sxMax + m_Scaler.sxMin) / 2;
	m_Scaler.soy = (m_Scaler.syMax + m_Scaler.syMin) / 2;

	//�ӽ�
	m_Render = false;

	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CSheetIndexMap::DrawRectangle(CDC &pDC)
{
	double sx, sy;
	POINT sPoint, ePoint;

	RECT rect;
	GetClientRect(&rect);

	m_Scaler.WorldToDevice( m_pParentScaler->mxMin, m_pParentScaler->myMin,
		&sx, &sy);
	sPoint.x = (LONG)sx;
	sPoint.y = (LONG)sy;
	//�簢�� ũ�� ����	
	if(sPoint.x < INDEXMAP_POS_MIN)
	{
		sPoint.x = INDEXMAP_POS_MIN;
	}
	if(sPoint.y < INDEXMAP_POS_MIN)
	{
		sPoint.y = INDEXMAP_POS_MIN;
	}

	m_Scaler.WorldToDevice(m_pParentScaler->mxMax, m_pParentScaler->myMax,
		&sx, &sy);
	ePoint.x = (LONG)sx;
	ePoint.y = (LONG)sy;
	//�簢�� ũ�� ����
	if(ePoint.x >INDEXMAP_POS_MAX)
	{
		ePoint.x = INDEXMAP_POS_MAX;
	}
	if(ePoint.y >INDEXMAP_POS_MAX)
	{
		ePoint.y = INDEXMAP_POS_MAX;
	}
	CPen pen;
	pen.CreatePen(0,3,RGB(255,0,0));
	CPen *pPen = pDC.SelectObject(&pen);
	
	


	pDC.MoveTo(sPoint.x, sPoint.y);
	pDC.LineTo(ePoint.x, sPoint.y);
	pDC.LineTo(ePoint.x, ePoint.y);
	pDC.LineTo(sPoint.x, ePoint.y);
	pDC.LineTo(sPoint.x, sPoint.y);

	pDC.SelectObject(pPen);
}
