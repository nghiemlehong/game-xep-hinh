#ifndef __DIEM_H__
#define __DIEM_H__
#include <iostream>
#include <windows.h>
#include <mmsystem.h>
#include <math.h>
#include "dohoa.h"
#include "gach.h"
#include "sound.h"
#include <mciapi.h>
//#include "sound_1.h"
#pragma comment(lib,"Winmm.lib")

class Diem : public Bang{
private:
	int m_idiem, m_icap;
	float m_ftocdo;

public:
	//KHOI TAO
	Diem();
	Diem(int dong, int cot, int khung[30][30], int diem, int cap, float tocdo);
	
	//HAM GET, SET
	float getTocdo();
	int getDiem();
	int getCap();
	void setDiem(int diem);
	void setCap(int cap);
	void setTocdo(float tocdo);

	//HIEN THI BANG DIEM VA GACH TIEP THEO
	void veDiem(Gach g);
	virtual void veBang();

	//XOA BANG TIEP THEO
	void xoaGachNext(Gach g);

	//CAP NHAT DIEM
	bool capNhatDiem(Gach g, Bang &b);

	~Diem();
};

#endif