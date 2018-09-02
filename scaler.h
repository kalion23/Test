// Scaler.h: interface for the Scaler class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(SCALER_H)
#define SCALER_H
#include "GDFHeader.h"
class Scaler  
{
	
public:
	Scaler();
	void DeviceToWorld(double sx, double sy, double *mx, double *my);
	void WorldToDevice(double mx, double my, double *sx, double *sy);
	void TextSize(double mx, double my, int *x, int *y);

	void test1(SPATIAL_HDL *header ,double mx, double my, double *sx, double *sy);

	//////////////////////////////
	// �����׸��� ���� ��� 
	double mox , moy ;					// ���� ������
	double mxMin, myMin, mxMax, myMax;	// ���� Extent
	double sox , soy ;					// ȭ�� ������
	double sxMin, syMin, sxMax, syMax;	// ȭ�� Extent
	

	// ĵ���� 1������ �������� �� - �Ÿ���(��������/ĵ��������)
	double nowRatio;		
};

#endif

