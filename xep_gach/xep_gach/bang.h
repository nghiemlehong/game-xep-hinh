#ifndef __BANG_H__
#define __BANG_H__


class Bang{
protected:
	int m_idong, m_icot;
	int m_ikhung[30][30];
	
public:
	//KHOI TAO
	Bang();
	Bang(int dong, int cot, int khung[30][30]);
	Bang(const Bang &b);

	//HAM GET, SET
	int getCot();
	int getDong();
	int getPTKhung(int i, int j);
	void setDong(int d);
	void setCot(int c);
	void setPTKhung(int i, int j, int gt);

	//PHUONG THUC AO VE BANG, GACH NEN BANG GAME
	virtual void veBang();
	virtual void veGach();
	~Bang();
};


#endif