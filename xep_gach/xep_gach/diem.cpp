#include "diem.h"

#define LE_TRAI 10
#define LE_TREN 5
#define CONST_DIEM 10

Diem::Diem(){
	this->m_idiem = 0;
	this->m_icap = 1;
	this->m_ftocdo = 1.0;
}

Diem::Diem(int dong, int cot, int khung[30][30], int diem, int cap, float tocdo) : Bang(dong, cot, khung){
	this->m_idiem = diem;
	this->m_icap = cap;
	this->m_ftocdo = tocdo;
}

float Diem::getTocdo(){
	return this->m_ftocdo;
}

int Diem::getDiem(){
	return this->m_idiem;
}

int Diem::getCap(){
	return this->m_icap;
}

void Diem::setDiem(int diem){
	this->m_idiem = diem;
}

void Diem::setCap(int cap){
	this->m_icap = cap;
}

void Diem::setTocdo(float tocdo){
	this->m_ftocdo = tocdo;
}

void Diem::veBang(){
	int le_trai = 5, n = 11, le_tren = 3;
	

	for (int i = 0; i <= n; i++){
		textcolor(3);
		gotoxy(LE_TRAI + i + this->m_icot + le_trai, LE_TREN + le_tren);
		std::cout << (char)219;
		gotoxy(LE_TRAI + i + this->m_icot + le_trai, LE_TREN + le_tren + n);
		std::cout << (char)219;

		textcolor(LIGHTRED);
		gotoxy(LE_TRAI + this->m_icot + le_trai - 1, LE_TREN + le_tren + i);
		std::cout << (char)124;
		gotoxy(LE_TRAI + this->m_icot + le_trai + 1 + n, LE_TREN + le_tren + i);
		std::cout << (char)124;
	}
}

void Diem::veDiem(Gach g){
	int le_trai = 5, n = 10, le_tren = 3;
	Gach k = g;
	k.setX(2*le_tren + 2);
	k.setY(3*le_trai + n/3);
	
	k.veGach();
	textcolor(BLACK);
	gotoxy(LE_TRAI + this->m_icot + le_trai, LE_TREN + n);
	std::cout << "Diem: " << this->m_idiem << std::endl;
	gotoxy(LE_TRAI + this->m_icot + le_trai, LE_TREN + n + 1);
	std::cout << "Cap do: " << this->m_icap << std::endl;
	gotoxy(LE_TRAI + this->m_icot + le_trai, LE_TREN + n + 2);
	std::cout << "Toc do: " << roundf(this->m_ftocdo * 100)/100 << std::endl;
	
}

void Diem::xoaGachNext(Gach g){
	int le_trai = 5, n = 10, le_tren = 3;
	Gach k = g;
	
	k.setX(2 * le_tren + 2);
	k.setY(3 * le_trai + n / 3);

	k.xoaGach();
}

bool Diem::capNhatDiem(Gach g, Bang &b){
	int id = g.getDong() - 1, dem;
	if (g.getX() <= 2) return false;	//GAMEOVER
	do{
		dem = 0;
		for (int j = 0; j < b.getCot(); j++){
			if (b.getPTKhung(g.getX() + id, j) == 1) dem++;
		}
		if (dem == b.getCot()){
			this->m_idiem += 1;
			g.ghiDiem(b,g.getX()+id);			
			b.veGach();
			PlaySound(TEXT("Correct_Score.wav"), NULL, SND_ASYNC);
		}
		else id--;
	} while (id >= 0);
	if (this->m_idiem >= CONST_DIEM*this->m_icap){
		this->m_icap++;
		this->m_ftocdo = this->m_ftocdo - 0.1;
	}// LEN CAP
	return true;//CHOI TIEP
}

Diem::~Diem(){

}	