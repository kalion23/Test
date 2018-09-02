// Shapefile.cpp: implementation of the CShape class.

#include "stdafx.h"
#include "../Shape/Shapefile.h"
//#include "Labeler.h"
//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CShapefile::CShapefile()
{
	m_bOpen = false;
	
	m_MBR.xmax = m_MBR.ymax = m_MBR.xmin = m_MBR.ymin = 0.;
	
	m_nShapeType = 0;
	
	m_pSHPPoints = NULL;
	m_pSHPPolyObjects = NULL;

//	m_labeler = new Labeler;
//	m_labeler->shp = this;
	
}

CShapefile::~CShapefile()
{
	if(m_bOpen== true)
		Close();
}

void CShapefile::SwapWord(int _length, void* _pWord)   
{
	int		i;
	unsigned char	temp;
	
	for( i=0; i< _length/2; i++ )
	{
		temp = ((unsigned char *) _pWord)[i];
		((unsigned char *) _pWord)[i] = ((unsigned char *) _pWord)[_length-i-1];
		((unsigned char *) _pWord)[_length-i-1] = temp;
	}
}

bool CShapefile::Open(char* _filename)
{
	FILE *fpSHP, *fpSHX;
	int tmp, i, j;
	int lengthfilename;
	
	
	strcpy(m_strSHPPath, _filename);	//SHP file path
	lengthfilename = strlen(m_strSHPPath) -4;	// ".shp"�� ���� ����
	
	//Get SHX file path
	for(int w=0; w<lengthfilename; w++)
	{ 
		m_strSHXPath[w] = m_strSHPPath[w];
		if(w==lengthfilename-1)
		{
			m_strSHXPath[w+1]=0;
			strcat(m_strSHXPath,".shx" );
		}
	}
	
	
	//open SHP/SHX file
	fpSHP = fopen(m_strSHPPath, "rb");
	fpSHX = fopen(m_strSHXPath, "rb");
	
	if(fpSHP == NULL || fpSHX == NULL)
	{
		// ������ ������ ������ �޽����ڽ� ���
		::AfxMessageBox("SHP File Error!! \n", MB_OK, -1);
		return false;
	}
	
	/* release memory of exsiting one */
	if(m_bOpen)
		Close();
	
	/* Now read a Header of SHP/SHX */
	// Get File size & Number of records
	fseek(fpSHX, 24L, SEEK_SET);
	fread(&tmp, 4, 1, fpSHX);
	SwapWord(4, &tmp);	// Byte Order Changing
	
	m_nFileSize = tmp * 2;	// get file size
	m_nRecords = (m_nFileSize - 100)/8;	//get a number of records
	
	// get shp type
	fseek(fpSHP, 32L, SEEK_SET);
	fread(&m_nShapeType, 4, 1, fpSHP);
	
	// Check a invalid shp type
	if(!(m_nShapeType == 1 || m_nShapeType == 3 || m_nShapeType == 5 || m_nShapeType == 8)) 
	{
		::AfxMessageBox("Invalid SHP Type.\nThis program only support Point, Arc, Polygon & MultiPoint SHP Type.\n", MB_OK, -1);
		return false;
	}
	
	// get a MBR
	fread(&m_MBR, sizeof(MBR), 1, fpSHP);
	
	// real routine of feature reading(point, arc, polygon, multipoint)
	switch(m_nShapeType)
	{
		// ����Ʈ�� �о���δ�.
	case SHPT_POINT:
		m_pSHPPoints = new GeoPoint[m_nRecords];
		
		for(i = 0; i < m_nRecords; ++i)
		{
			// SHX������ ���ڵ� ������ ù 4����Ʈ�� �ش��ϴ� feature�� ��ǥ������ ���۵Ǵ�
			// ����Ʈ �� �� �˷� �ش�.
			fseek(fpSHX, 100 + i * 8, SEEK_SET);
			fread(&tmp, 4, 1, fpSHX);
			SwapWord(4, &tmp);
			tmp=tmp * 2;
			
			fseek(fpSHP, tmp + 12, SEEK_SET);
			fread((GeoPoint*)&m_pSHPPoints[i], 16, 1, fpSHP);
		}
		break;
		
		// �������ΰ� �������� �о���δ�.
	case SHPT_ARC :
	case SHPT_POLYGON:
		m_pSHPPolyObjects = new PolyObject[m_nRecords];
		
		for(i=0;i<m_nRecords;++i)
		{
			fseek(fpSHX, 100+i*8, SEEK_SET);
			fread(&tmp, 4, 1, fpSHX);
			SwapWord(4, &tmp);
			tmp=tmp*2;
			
			fseek(fpSHP, tmp+12, SEEK_SET);
			fread((MBR*)&m_pSHPPolyObjects[i].m_MBR, 32, 1, fpSHP);	//get MBR
			fread(&m_pSHPPolyObjects[i].m_nNumParts, 4, 1, fpSHP);	//get parts number
			fread(&m_pSHPPolyObjects[i].m_nNumPoints, 4, 1, fpSHP);  //get points number
			
			m_pSHPPolyObjects[i].m_pParts = new int[m_pSHPPolyObjects[i].m_nNumParts];
			m_pSHPPolyObjects[i].m_pPoints = new GeoPoint[m_pSHPPolyObjects[i].m_nNumPoints];
			
			for(j=0;j<m_pSHPPolyObjects[i].m_nNumParts;++j)
				fread(&m_pSHPPolyObjects[i].m_pParts[j], 4, 1, fpSHP);

				
			for(j=0;j<m_pSHPPolyObjects[i].m_nNumPoints;++j)
				fread(&m_pSHPPolyObjects[i].m_pPoints[j], 16, 1, fpSHP);
		}


		break;
		
		// �������� �о���δ�.
	case SHPT_MULTIPOINT:
		m_pSHPPolyObjects = new PolyObject[m_nRecords];
		
		for(i=0;i<m_nRecords;++i)
		{
			fseek(fpSHX, 100+i*8, SEEK_SET);
			fread(&tmp, 4, 1, fpSHX);
			SwapWord(4, &tmp);
			tmp=tmp*2;
			
			fseek(fpSHP, tmp+12, SEEK_SET);
			fread((MBR*)&m_pSHPPolyObjects[i].m_MBR, 32, 1, fpSHP);	//get  MBR
			fread(&m_pSHPPolyObjects[i].m_nNumPoints, 4, 1, fpSHP);	// get points number
			
			m_pSHPPolyObjects[i].m_pPoints = new GeoPoint[m_pSHPPolyObjects[i].m_nNumPoints];
			
			for(j=0;j<m_pSHPPolyObjects[i].m_nNumPoints;++j)
				fread(&m_pSHPPolyObjects[i].m_pPoints[j], 16, 1, fpSHP);
		}
		break;
	}
	
	fclose(fpSHX);
	fclose(fpSHP);
	
	m_bOpen = true;
	return true;
}


// �Ҵ�� �޸𸮸� �����Ѵ�.
bool CShapefile::Close()
{
	if(m_bOpen)
	{
		int i;
		switch(m_nShapeType)
		{
		case SHPT_POINT:
			delete []m_pSHPPoints;
			break;
			
		case SHPT_MULTIPOINT:
			for(i = 0; i < m_nRecords; ++i)
				delete [] m_pSHPPolyObjects[i].m_pPoints;
			break;
			
		case SHPT_ARC:
		case SHPT_POLYGON:
			for(i = 0; i < m_nRecords; ++i)
			{
				delete [] m_pSHPPolyObjects[i].m_pParts;
				delete [] m_pSHPPolyObjects[i].m_pPoints;
			}
			delete[] m_pSHPPolyObjects;
			break;
		}
	}
	m_bOpen = false;
	return true;
}




void CShapefile::Draw(CDC *pDC, Scaler& sc, ClickedObject *pClickedObject)
{
	double sx, sy;
	int i;
	CPen pen;
	bool bCheck = false;

	switch(m_nShapeType)
	{
	case SHPT_POINT :
		for(i=0; i<m_nRecords ; i++)
		{
			CPoint pt;	
			sc.WorldToDevice(m_pSHPPoints[i].x,
				m_pSHPPoints[i].y, &sx,&sy);
			pt.x = sx;
			pt.y = sy;
			
			if(sx > 0 && sy > 0 && pClickedObject->m_nObjectType != CLEAR)
			{
				CPen* oldPen;

				switch(pClickedObject->m_nObjectType)
				{
				case StartObject:
					if(abs(pClickedObject->m_stDevicePoints[0].x - sx) < 5  && abs(pClickedObject->m_stDevicePoints[0].y - sy) < 5)
					{
						pen.CreatePen( PS_SOLID, 5, RGB(255,0,0) ); 
						oldPen = pDC->SelectObject( &pen );
						bCheck = true;
					}
					break;
				case EndObject:
					if(abs(pClickedObject->m_stDevicePoints[1].x - sx) < 5  && abs(pClickedObject->m_stDevicePoints[1].y - sy) < 5)
					{
						pen.CreatePen( PS_SOLID, 5, RGB(0,0,255) ); 
						oldPen = pDC->SelectObject( &pen );
						bCheck = true;
					}
					break;
				}
				
				pDC->Ellipse(pt.x-2, pt.y-2, pt.x+2, pt.y+2);
				
				if(bCheck)
				{
					pDC->SelectObject( oldPen );
					pen.DeleteObject();        // ������ ���� �����Ѵ�.
					bCheck = false;
				}
			}
			else
				pDC->Ellipse(pt.x-2, pt.y-2, pt.x+2, pt.y+2);
		}

		break;
	case SHPT_ARC :
		
		for(i = 0; i < m_nRecords; ++i)
		{
			// �������� ����ȭ
			int NumPoints = m_pSHPPolyObjects[i].m_nNumPoints;
			int NumParts = m_pSHPPolyObjects[i].m_nNumParts;
			// �ϳ��� feature�� ���ϴ� ��������� ������ ���� �Ҵ�
			CPoint* pTempPoint = new CPoint[NumPoints];
			// �� Part�� ���ϴ� ���ؽ�(��)���� ������ ������ ������ ���� �Ҵ�
			int* pVertex = new int[NumParts];
			// �� feature�� ���� pTempPoint�� ����
			for(int j = 0; j < NumPoints; ++j)
			{
				sc.WorldToDevice(m_pSHPPolyObjects[i].m_pPoints[j].x,
					m_pSHPPolyObjects[i].m_pPoints[j].y, &sx,&sy);
				pTempPoint[j].x = sx;
				pTempPoint[j].y = sy;
			}
			// ���ؽ� ���� ���ϴ� ����
			for(int j = 0; j < NumParts; j++)	{
				// ������ Part�� ���ؽ� ���� ��ü ���ؽ� ������ ������ Part�� �ε����� ����
				if(j == NumParts - 1)	
					pVertex[j] = NumPoints - m_pSHPPolyObjects[i].m_pParts[j];
				// ���ؽ��� ���� Part�� �ε����� ���� Part�� �ε��� ���� ����
				else {
					pVertex[j] = m_pSHPPolyObjects[i].m_pParts[j+1]
						- m_pSHPPolyObjects[i].m_pParts[j];
				}
			}

			pDC->PolyPolyline(pTempPoint, (DWORD*)pVertex, NumParts);
			// ��� ���� �Ҵ��� ����
			delete[] pTempPoint;
			delete[] pVertex;
		}
		break;
	case SHPT_POLYGON :
		
		for(i = 0; i < m_nRecords; ++i)
		{
			// �������� ����ȭ
			int NumPoints = m_pSHPPolyObjects[i].m_nNumPoints;
			int NumParts = m_pSHPPolyObjects[i].m_nNumParts;
			// �ϳ��� feature�� ���ϴ� ��������� ������ ���� �Ҵ�
			CPoint* pTempPoint = new CPoint[NumPoints];
			// �� Part�� ���ϴ� ���ؽ�(��)���� ������ ������ ������ ���� �Ҵ�
			int* pVertex = new int[NumParts];
			// �� feature�� ���� pTempPoint�� ����
			for(int j = 0; j < NumPoints; ++j)
			{
				sc.WorldToDevice(m_pSHPPolyObjects[i].m_pPoints[j].x,
					m_pSHPPolyObjects[i].m_pPoints[j].y, &sx,&sy);
				pTempPoint[j].x = sx;
				pTempPoint[j].y = sy;
			}
			// ���ؽ� ���� ���ϴ� ����
			for(int j = 0; j < NumParts; j++)	{
				// ������ Part�� ���ؽ� ���� ��ü ���ؽ� ������ ������ Part�� �ε����� ����
				if(j == NumParts - 1)	
					pVertex[j] = NumPoints - m_pSHPPolyObjects[i].m_pParts[j];
				// ���ؽ��� ���� Part�� �ε����� ���� Part�� �ε��� ���� ����
				else {
					pVertex[j] = m_pSHPPolyObjects[i].m_pParts[j+1]
						- m_pSHPPolyObjects[i].m_pParts[j];
				}
			}

			pDC->PolyPolygon (pTempPoint, pVertex, NumParts);
			// ��� ���� �Ҵ��� ����
			delete[] pTempPoint;
			delete[] pVertex;
		}
		break;

	}

}
