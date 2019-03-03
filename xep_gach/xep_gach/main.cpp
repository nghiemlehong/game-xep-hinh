#include "windows.h"
#include <ctime>
#include<iostream>
#include<conio.h>
#include "time.h"
#include "dohoa.h"
#include "gach.h"
#include "bang.h"
#include "diem.h"


using namespace std;

bool huongDanGame();
void chienThang();
void thuaCuoc();
bool ketThucGame();
void tamDung(Gach g);
void reSetDiem(Diem &d_Score);
void tieuDe();

int main(){
	system("color F4");
	
	Diem d_Score;
	Gach gNext, gStart;
	Bang b_Game, *p1 = &b_Game, *p2 = & d_Score, *p3 = &gStart;
	char c;		

	clock_t Start, End;
	if (huongDanGame() == true) {
		clrscr();
		tieuDe();
		p1->veBang();
		p1->veGach();
		p2->veBang();
		
		gotoxy(60, 10);
		cout << "-->> KET QUA CUA GAME <<--";
		textcolor(GREEN);
		gotoxy(25,22);
		cout << "-- BAM P DEN TAM DUNG GAME --";
		textcolor(RED);

		srand(time(NULL));

		gNext.ganGiaTri(gNext.loaiGach());
		gStart.ganGiaTri(gStart.loaiGach());

		Nocursortype(); //KHONG HIEN THI NHAY CHUOT LEN MAN HINH
		do {
			
			d_Score.veDiem(gNext);
			p3->veGach();

			Start = clock();
			do {
				if (_kbhit()) {
					c = toupper(_getch());
					gStart.xoaGach();

					switch (c) {
					case 'A': {
						gStart.dichTrai(b_Game);
						break;
					}
					case 'S': {
						gStart.roiXuong(b_Game);
						break;
					}
					case 'D': {
						gStart.dichPhai(b_Game);
						break;
					}
					case 'W': {
						gStart.xoayGach(b_Game);
						break;
					}
					case 'P': {
						tamDung(gStart);
						break;
					}
					}

					p3->veGach();
				}
				End = clock();
			} while (((float)(End - Start) / CLK_TCK) < d_Score.getTocdo());

			if (gStart.roiXuong(b_Game) == false) {
				gStart.capNhatBang(b_Game);
				bool ketqua = d_Score.capNhatDiem(gStart, b_Game);
				if (ketqua == false) {
					d_Score.veDiem(gNext);
					p1->veGach();
					thuaCuoc();
					PlaySound(TEXT("Game_Over.wav"), NULL, SND_ASYNC);
					delay(15000);
					if (ketThucGame() == true) {
						Bang b;
						b_Game = b;
						gotoxy(60, 12);
						textcolor(BLACK);
						cout << "                       ";
						gotoxy(51, 14);
						textcolor(BLUE);
						cout << "\t                                             ";
						reSetDiem(d_Score);
						clrscr();

						tieuDe();
						p1->veBang();
						p1->veGach();
						p2->veBang();

						gotoxy(60, 10);
						cout << "-->> KET QUA CUA GAME <<--";
						textcolor(GREEN);
						gotoxy(25, 22);
						cout << "-- BAM P DEN TAM DUNG GAME --";
						textcolor(RED);

					}
					else break;
				}
				else if (d_Score.getCap() > 9) {
					d_Score.veDiem(gNext);
					p1->veGach();
					chienThang();
					PlaySound(TEXT("You_Win.wav"), NULL, SND_ASYNC);
					delay(6000);										
					if (ketThucGame() == true) {
						Bang b;
						b_Game = b;
						gotoxy(60, 12);
						textcolor(RED);
						cout << "                                       ";
						gotoxy(51, 14);
						textcolor(BLUE);
						cout << "\t                                             ";
						reSetDiem(d_Score);
						clrscr();

						tieuDe();
						p1->veBang();
						p1->veGach();
						p2->veBang();

						gotoxy(60, 10);
						cout << "-->> KET QUA CUA GAME <<--";
						textcolor(GREEN);
						gotoxy(25, 22);
						cout << "-- BAM P DEN TAM DUNG GAME --";
						textcolor(RED);


					}
					else break;
				}

				gStart = gNext;
				d_Score.xoaGachNext(gNext);
				gNext.ganGiaTri(gNext.loaiGach());
			}
			p1->veGach();

		} while (1);
	}
	
	return 0;
}

bool huongDanGame() {
	textcolor(RED);
	cout << "\t\t\t --- >>>>>      GAME KINH DIEN - XEP GACH (TETRIS)      <<<<< ---" << endl;
	cout << "\t\t\t --- >>>>>    CODER: VU VAN CONG - DH SU PHAM TP.HCM    <<<<< ---" << endl << endl << endl;
	textcolor(BLUE);
	cout << "\t\t\t --- >>>>>             HUONG DAN  CHOI GAME             <<<<< ---" << endl << endl;
	textcolor(GREEN);
	cout << "\t A. LUAT CHOI:" << endl << endl;
	textcolor(BLACK);
	cout << "\t - Moi lan game se hien len mot loai gach ngau nhien voi hinh dang khac nhau, nhiem vu cua ban la" << endl;
	cout << "\t xep cac loai gach nay thanh mot hang ngang trong khung game." << endl << endl;
	cout << "\t - Neu ghep du mot hang trong khung game thi hang gach do se bien mat va ban ghi duoc mot diem," << endl;
	cout << "\t cu tiep tuc nhu vay cho den khi ban thang hoac thua thi game se dung." << endl << endl;
	cout << "\t - Ban phai ghi duoc 10 diem de duoc len cap va co 9 cap, toc do se giam qua moi cap." << endl;
	cout << "\t Ban se gianh chien thang khi vuot qua duoc het 9 cap do cua game." << endl << endl;
	cout << "\t - Ban se thua neu de gach tran khoi khung game." << endl << endl;

	textcolor(GREEN);
	cout << "\t B. HUONG DAN:" << endl << endl;
	textcolor(BLACK);
	cout << "\t - Cac phim dieu khien trong Game nhu sau: " << endl;
	cout << "\t + A - Dich Trai khoi gach." << endl;
	cout << "\t + D - Dich Phai khoi gach." << endl;
	cout << "\t + S - Di chuyen khoi gach roi xuong." << endl;
	cout << "\t + W - Xoay khoi gach." << endl;
	cout << "\t + Y or N - Lua chon trong Game." << endl;
	cout << "\t + P - Tam dunng Game." << endl;
	textcolor(RED);
	char c;
	do {
			gotoxy(10, 30);
			cout << "\t ==>> Neu ban da san sang thi bam Y - Neu muon thoat game thi bam N:   ";
			c = toupper(_getch());
	} while (c != 'Y' && c != 'N');
	if (c == 'Y') return true;
	return false;
}

void chienThang() {
	gotoxy(60, 12);
	textcolor(GREEN);
	cout << "XIN CHUC MUNG BAN DA CHIEN THANG!!! :))";
}

void thuaCuoc() {
	gotoxy(60, 12);
	textcolor(BLACK);
	cout << "BAN DA THUA CUOC!!! :((";
}

bool ketThucGame() {
	char c;
	do {
		gotoxy(51,14);
		textcolor(BLUE);
		cout << "\t ==>> Bam Y de choi lai - Bam N de thoat <<==";
		c = toupper(_getch());
	} while (c != 'Y' && c != 'N');
	if (c == 'Y') return true;
	return false;
}

void tamDung(Gach g) {
	char c;
	do {
		g.veGach();
		c = toupper(_getch());
	} while (c != 'P');
}

void reSetDiem(Diem &d_Score) {
	Diem d;
	d_Score = d;
}

void tieuDe() {
	cout << "\t\t\t --- >>>>>      GAME KINH DIEN - XEP GACH (TETRIS)      <<<<< ---" << endl;
	cout << "\t\t\t --- >>>>>    CODER: VU VAN CONG - DH SU PHAM TP.HCM    <<<<< ---" << endl << endl;
}