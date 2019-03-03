#ifndef __GACH_H__
#define __GACH_H__
#include "bang.h"

class Gach : public Bang{
private:
	int m_ix, m_iy;
public:
	//KHOI TAO GIA TRI CHO GACH
	Gach();
	Gach(int dong, int cot, int khung[30][30], int x, int y);
	Gach(const Gach &g);
	//HAM GET, SET
	void setX(int X);
	void setY(int Y);
	int getX();
	int getY();

	//GAN GIA TRI CHO MANG GACH
	void ganGiaTri(int id);
	//VE GACH LEN BANG GAME
	virtual void veGach();
	//XOA GACH TREN BANG GAME
	void xoaGach();
	//LUA CHON GACH NGAU NHIEN
	int loaiGach();
	//KIEM TRA GACH CO CON TRONG VUNG CHO PHEP HAY KHONG
	bool ktTrong(int i, int j, Bang b);
	bool ktTrai(int i, int j, Bang b);
	bool ktPhai(int i, int j, Bang b);
	bool ktXuong(int i, int j, Bang b);

	//DIEU KHIEN KHOI GACH: TRAI - PHAI - XUONG - XOAY
	void dichTrai(Bang a);
	void dichPhai(Bang a);
	bool roiXuong(Bang a);
	void xoayGach(Bang a);

	//CAP NHAT GIA TRI CHO BANG GAME KHI GACH KHONG CON DI CHUYEN
	void capNhatBang(Bang &a);
	//CAP NHAT GIA TRI CHO BANG GAME KHI GHI DIEM TAI HANG C
	void ghiDiem(Bang &a, int D);

	void huyKhoiGach();
	~Gach();
};


#endif