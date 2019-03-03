#include <iostream>
#include "dohoa.h"
#include "bang.h"
#include "gach.h"

#define LE_TRAI 10
#define LE_TREN 5

Gach::Gach(){
	this->m_ix = 2;
	this->m_iy = 4;
	this->m_idong = this->m_icot = 2;
	for (int i = 0; i < 2; i++)
		for (int j = 0; j < 2; j++){
			this->m_ikhung[i][j] = 1;
		}
}

Gach::Gach(int dong, int cot, int khung[30][30], int x, int y) : Bang(dong, cot, khung){	
	this->m_ix = x;
	this->m_iy = y;
}

Gach::Gach(const Gach &g){
	this->m_idong = g.m_idong;
	this->m_icot = g.m_icot;
	this->m_ix = g.m_ix;
	this->m_iy = g.m_iy;
	for (int i = 0; i < this->m_idong; i++)
		for (int j = 0; j < this->m_icot; j++){
			this->m_ikhung[i][j] = g.m_ikhung[i][j];
		}
}

void Gach::setX(int X){
	this->m_ix = X;
}

void Gach::setY(int Y){
	this->m_iy = Y;
}

int Gach::getX(){
	return this->m_ix;
}

int Gach::getY(){
	return this->m_iy;
}

void Gach::ganGiaTri(int id){
	switch (id){
	case 31:{
		this->m_ix = 2;
		this->m_iy = 4;
		this->m_idong = this->m_icot = 2;		
		break;
	}
	case 15:{
		this->m_ix = 0;
		this->m_iy = 4;
		this->m_idong = 4;
		this->m_icot = 1;
		break;
	}
	default:{
		this->m_ix = 2;
		this->m_iy = 4;
		this->m_idong = 2;
		this->m_icot = 3;
		break;
	}
	}
	int k = 0;
	for (int i = 0; i < this->m_idong; i++)
		for (int j = 0; j < this->m_icot; j++){
			this->m_ikhung[i][j] = (id >> (this->m_idong*this->m_icot - k - 1))&1;
			k++;
		}
}

void Gach::veGach(){
	char c = 5;	
	for (int i = 0; i < this->m_idong; i++){
		for (int j = 0; j < this->m_icot; j++){
			if (this->m_ikhung[i][j] == 1 && this->m_ix + i > 3){
				textcolor(LIGHTBLUE);
				gotoxy(LE_TRAI + this->m_iy + j + 1, LE_TREN + this->m_ix + i - 3);
				std::cout << c;
			}
		}
	}
}

void Gach::xoaGach(){
	for (int i = 0; i < this->m_idong; i++){
		for (int j = 0; j < this->m_icot; j++){
			if (this->m_ikhung[i][j] == 1 && this->m_ix + i > 3){
				textcolor(LIGHTRED);
				gotoxy(LE_TRAI + this->m_iy + j + 1, LE_TREN + this->m_ix + i - 3);
				std::cout << " ";
			}
		}
	}

}

int Gach::loaiGach(){
	int x = rand() % 7;
	switch (x){
		case 0:{
			return 15;
			break;
		}
		case 1:{
			return 31;
			break;
		}
		case 2:{
			return 51;
			break;
		}
		case 3:{
			return 30;
			break;
		}
		case 4:{
			return 58;
			break;
		}
		case 5:{
			return 57;
			break;
		}
		case 6:{
			return 60;
			break;
		}
	}
}

//kiem tra gach co con trong khung hay khong
bool Gach::ktTrong(int i, int j, Bang b){
	if ((this->m_ix + i) >= 0 && (this->m_iy + j) >= 0 && (this->m_ix + i) < b.getDong() && (this->m_iy + j) < b.getCot()) return true;
	else return false;
}

bool Gach::ktTrai(int i, int j, Bang b){
	if (this->m_iy + j - 1 >= 0 && ktTrong(i,j,b) == true && b.getPTKhung(this->m_ix + i,this->m_iy + j - 1) == 0) return true;
	else return false;
}

bool Gach::ktPhai(int i, int j, Bang b){
	if (this->m_iy + j + 1 < b.getCot() && ktTrong(i,j,b) == true && b.getPTKhung(this->m_ix + i,this->m_iy + j + 1) == 0) return true;
	else return false;
}

bool Gach::ktXuong(int i, int j, Bang b){
	if (this->m_ix + i + 1 < b.getDong() && ktTrong(i,j,b) == true && b.getPTKhung(this->m_ix + i + 1,this->m_iy + j) == 0) return true;
	else return false;
}

//dich trai, dich phai, roi xuong, xoay khoi gach
void Gach::dichTrai(Bang a){
	for (int i = 0; i < this->m_idong; i++){
		for (int j = 0; j < this->m_icot; j++){
			if (this->m_ikhung[i][j] == 1){
				if (ktTrai(i, j, a) == false) return;
			}
		}
	}
	this->m_iy -= 1;
}

void Gach::dichPhai(Bang a){
	for (int i = 0; i < this->m_idong; i++){
		for (int j = 0; j < this->m_icot; j++){
			if (this->m_ikhung[i][j] == 1){
				if (ktPhai(i, j, a) == false) return;
			}
		}
	}
	this->m_iy += 1;
}

bool Gach::roiXuong(Bang a){
	for (int i = 0; i < this->m_idong; i++){
		for (int j = 0; j < this->m_icot; j++){
			if (this->m_ikhung[i][j] == 1){
				if (ktXuong(i, j, a) == false) return false;
			}
		}
	}
	this->m_ix += 1;
	return true;
}

void Gach::xoayGach(Bang a){
	int tmpRow = this->m_icot;
	int tmpCol = this->m_idong;
	int tmp_x = this->m_ix;
	int tmp_y = this->m_iy;
	int tmp[4][4];

	//KIEM TRA CO THE XOAY HAY KHONG
	
	for (int i = 0; i < tmpRow; i++){
		for (int j = 0; j < tmpCol; j++){
			if (ktTrong(i,j,a) == false || a.getPTKhung(this->m_ix + i, this->m_iy + j) == 1) return;
		}
	}
	
	//NEU CO THE XOAY THI THUC HIEN NHU SAU:

	for (int i = this->m_idong - 1; i >= 0; i--){
		for (int j = this->m_icot - 1; j >= 0; j--){
			tmp[j][this->m_idong - i - 1] = this->m_ikhung[i][j];
		}
	}
	huyKhoiGach();
	this->m_icot = tmpCol;
	this->m_idong = tmpRow;
	this->m_ix = tmp_x;
	this->m_iy = tmp_y;

	for (int i = 0; i < this->m_idong; i++)
		for (int j = 0; j < this->m_icot; j++){
			this->m_ikhung[i][j] = tmp[i][j];
		}
}

//CAP NHAT GIA TRI  CHO BANG

void Gach::capNhatBang(Bang &a){	
	for (int i = 0; i < this->m_idong; i++){
		for (int j = 0; j < this->m_icot; j++){
			if (this->m_ikhung[i][j] == 1 && ktTrong(i, j, a) == true){
				a.setPTKhung(this->m_ix + i,this->m_iy + j, 1);
			}			
		}		
	}
	
}

void Gach::ghiDiem(Bang &a, int D){
	for (int i = D; i > 0; i--){
		for (int j = 0; j < a.getCot(); j++){
			a.setPTKhung(i, j, a.getPTKhung(i - 1, j));
		}
	}
}

void Gach::huyKhoiGach(){
	this->m_idong = this->m_icot = 0;
	for (int i = 0; i < 4; i++){
		for (int j = 0; j < 4; j++){
			this->m_ikhung[i][j] = 0;
		}
	}
}

Gach::~Gach(){
	this->m_idong = this->m_icot = 0;
	for (int i = 0; i < 4; i++){
		for (int j = 0; j < 4; j++){
			this->m_ikhung[i][j] = 0;
		}
	}
}