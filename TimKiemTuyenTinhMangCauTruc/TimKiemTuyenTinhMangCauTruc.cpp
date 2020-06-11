// TimKiemTuyenTinhMangCauTruc.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string.h>
#include <stdio.h>
using namespace std;


struct SinhVien
{
	char ma[10];
	char ten[150];
	bool gioiTinh;
};
void NhapDanhSach(SinhVien dsSV[], int siSo);
void XuatDanhSach(SinhVien dsSV[], int siSo);
SinhVien* TimSinhVienTheoMa(SinhVien dsSV[], int siSo, char maTim[]);

void NhapDanhSach(SinhVien dsSV[], int siSo)
{
	for (int i = 0; i < siSo; i++)
	{
		cout << "Nhap ma: ";
		gets_s(dsSV[i].ma);
		cout << "Nhap ten: ";
		gets_s(dsSV[i].ten);
		cout << "Gioi tinh (M/F): ";
		char gt[2];
		gets_s(gt);
		if (strcmp(gt, "m") == 0)
			dsSV[i].gioiTinh = false;
		else 
			dsSV[i].gioiTinh = true;
	}
}

void XuatDanhSach(SinhVien dsSV[], int siSo)
{
	for (int i = 0; i < siSo; i++)
	{
		cout << dsSV[i].ma << "\t" << dsSV[i].ten << "\t" << (dsSV[i].gioiTinh==true?"Nu":"Nam") << "\n";
	}
}

SinhVien* TimSinhVienTheoMa(SinhVien dsSV[], int siSo, char maTim[])
{
	for (int i = 0; i < siSo; i++)
	{
		if (strcmp(dsSV[i].ma, maTim) == 0)
		{
			return &dsSV[i];
		}
	}
	return NULL;
}
void TimSinhVienTheoGioiTinh(SinhVien dsSV[], int siSo, char gttim[2])
{
	
	
	for (int i = 0; i < siSo; i++)
	{
		bool gttimbool = true;//Nam
		if (strcmp(gttim, "f"))
			gttimbool = false;//Nu
		if (dsSV[i].gioiTinh == gttimbool)
		{
			cout << dsSV[i].ma << "\t" << dsSV[i].ten << "\t" << (dsSV[i].gioiTinh == true ? "nu" : "nam") << endl;
		}
	}
}
int main()
{
	const int siSo = 3;
	SinhVien dsSV[siSo];
	NhapDanhSach(dsSV, siSo);
	cout << "Danh sach Sinh vien sau khi nhap: \n";
	XuatDanhSach(dsSV, siSo);
	/*char maTim[10];
	cout << "Nhap ma muon tim: ";
	gets_s(maTim);
	SinhVien* pSv = TimSinhVienTheoMa(dsSV, siSo, maTim);
	if (pSv == NULL)
		cout << "Khong tim thay ma " << maTim;
	else
	{
		cout << "Tim thay sinh vien co ma = " << maTim << endl;
		cout << pSv->ma << "\t" << pSv->ten << "\t" << (pSv->gioiTinh == true ? "Nu" : "Nam") << endl;
	}*/

	cout << "Moi ban nhap gioi tinh (M/F): ";
	char gttim[2];
	gets_s(gttim);
	TimSinhVienTheoGioiTinh(dsSV, siSo, gttim);
	return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
