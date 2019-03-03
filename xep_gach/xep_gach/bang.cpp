#include <iostream>
#include "bang.h"
#include "dohoa.h"

#define LE_TRAI 10
#define LE_TREN 5

Bang::Bang(){
	this->m_icot = 10;
	this->m_idong = 22;
	for (int i = 0; i < this->m_idong; i++){
		for (int j = 0; j < this->m_icot; j++){
			this->m_ikhung[i][j] = 0;
		}
	}
}

Bang::Bang(int dong, int cot, int khung[30][30]){
	this->m_idong = dong;
	this->m_icot = cot;
	for (int i = 0; i < this->m_idong; i++){
		for (int j = 0; j < this->m_icot; j++){
			this->m_ikhung[i][j] = khung[i][j];
		}
	}
}

Bang::Bang(const Bang &b) {
	this->m_idong = b.m_idong;
	this->m_icot = b.m_icot;
	for (int i = 0; i < this->m_idong; i++) {
		for (int j = 0; j < this->m_icot; j++) {
			this->m_ikhung[i][j] = b.m_ikhung[i][j];
		}
	}
}

int Bang::getCot(){
	return this->m_icot;
}

int Bang::getDong(){
	return this->m_idong;
}

int Bang::getPTKhung(int i, int j){
	return this->m_ikhung[i][j];
}

void Bang::setDong(int d){
	this->m_idong = d;
}

void Bang::setCot(int c){
	this->m_icot = c;
}

void Bang::setPTKhung(int i, int j, int gt){
	this->m_ikhung[i][j] = gt;
}

void Bang::veBang(){
	char c = 219, e = 179;
	textcolor(BLACK);
	for (int i = 0; i <= this->m_icot+1; i++){
		gotoxy(LE_TRAI + i, LE_TREN);
		std::cout << c;
		gotoxy(LE_TRAI + i, LE_TREN + this->m_idong + 1 - 4);
		std::cout << c;
	}

	for (int i = 0; i <= this->m_idong + 1 - 4; i++){
		gotoxy(LE_TRAI, LE_TREN + i);
		std::cout << e;
		gotoxy(LE_TRAI + this->m_icot+1, LE_TREN + i);		
		std::cout << e;
	}

	gotoxy(LE_TRAI, LE_TREN); textcolor(LIGHTGREEN); std::cout << c;
	gotoxy(LE_TRAI + 11, LE_TREN); textcolor(LIGHTGREEN); std::cout << c;
	gotoxy(LE_TRAI, LE_TREN + 19); textcolor(LIGHTGREEN); std::cout << c;
	gotoxy(LE_TRAI + 11, LE_TREN + 19); textcolor(LIGHTGREEN); std::cout << c;
} 

void Bang::veGach(){
	char c = 5;//219
	for (int i = 0; i < this->m_idong; i++){
		for (int j = 0; j < this->m_icot; j++){
			if (this->m_ikhung[i][j] == 1 && i >= 4){
				gotoxy(LE_TRAI + j + 1, LE_TREN + i - 3);
				textcolor(LIGHTRED);
				std::cout << c;
			}
			
			if (this->m_ikhung[i][j] == 0 && i >= 4){
				gotoxy(LE_TRAI + j + 1, LE_TREN + i + 1 - 4);
				std::cout << " ";
			}
			
		}
	}
}

Bang::~Bang(){

}