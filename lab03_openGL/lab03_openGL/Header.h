#pragma once
#include <iostream>
#include "glut.h"
#include <vector>

#include<windows.graphics.h>

typedef struct _RGBColor {
	float r;
	float g;
	float b;


}RGBColor;
const int id_Oval = 1;
const int id_HinhTron = 11;
const int id_Ellipse = 12;

const int id_TamGiac = 2;
const int id_TgVuongCan = 21;
const int id_TgDeu = 22;

const int id_TuGiac = 3;
const int id_HinhChuNhat = 31;
const int id_HinhVuong = 32;

const int id_Line = 4;

const int id_DaGiacDeu = 5;
const int id_NguGiacDeu = 51;
const int id_LucGiacDeu = 52;

const int id_HinhKhac = 6;
const int id_NgoiSao = 61;
const int id_MuiTen = 62;

const int id_Dau = 7;
const int id_DauCong = 71;
const int id_DauTru = 72;
const int id_DauNhan = 73;
const int id_DauChia = 74;

const int id_MauXanh = 81;
const int id_MauDo = 82;
const int id_MauVang = 83;
const RGBColor O_Color = { 0,0,0 };
const RGBColor B_Color = { 1,1,1 };
const RGBColor F_Color_Blue = { 0,0,1 };
const RGBColor F_Color_Red = { 1,0,0 };
const RGBColor F_Color_Yellow = { 1,1,0 };

using namespace std;

struct Point {
	float x, y;
};
class Shape {
protected:
	Point pstart;
	Point pend;
	Point center;
	vector<Point> vertice;
	int type;
	//int button, state;
public:
	Shape();
	virtual void draw()=0;
	int getType() {
		return type;
	}
	Point getEndPoint() {
		return pend;
	}
	Point getStartPoint() {
		return pstart;
	}
	Point getCenter() {
		return center;
	}
	vector<Point> getVertice() {
		return vertice;
	}

	//vector<Point> getIntersection(float y, float xMin, float xMax);

};
vector<Shape*> listOfShape;
float distance(Point a, Point b) {
	return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}
class Line : public Shape {
public:
	Line() :Shape() {};
	void draw();
};
class DaGiacDeu : public Shape {
public:
	DaGiacDeu() :Shape() {};
};
class NguGiacDeu : public DaGiacDeu {
public:
	NguGiacDeu() :DaGiacDeu() {};
	void draw();
};
class LucGiacDeu : public DaGiacDeu {
public:
	LucGiacDeu() :DaGiacDeu() {};
	void draw();
};
class Dau : public Shape {
public:
	Dau() :Shape() {};
};
class DauCong : public Dau {
public:
	DauCong() :Dau() {};
	void draw();
};
class DauTru : public Dau {
public:
	DauTru() :Dau() {};
	void draw();
};
class DauNhan : public Dau {
public:
	DauNhan() :Dau() {};
	void draw();
};
class DauChia : public Dau {
public:
	DauChia() :Dau() {};
	void draw();
};
class HinhKhac : public Shape {
public:
	HinhKhac() :Shape() {};
};
class MuiTen : public HinhKhac {
public:
	MuiTen() :HinhKhac() {};
	void draw();
};
class NgoiSao : public HinhKhac {
public:
	NgoiSao() :HinhKhac() {};
	void draw();
};
class Oval :public Shape {
public:
	Oval() :Shape() {};
};
class HinhTron : public Oval {
public:
	HinhTron() :Oval() {};
	void draw();

};
class HinhEllipse : public Oval {
public:
	HinhEllipse() :Oval() {};
	void draw();
};
class TamGiac : public Shape {
public:
	TamGiac() :Shape() {};
};
class TGVuongCan : public TamGiac {
public:
	TGVuongCan() :TamGiac() {};
	void draw();
};
class TGDeu : public TamGiac {
public:
	TGDeu() :TamGiac() {};
	void draw();
};
class TuGiac : public Shape {
public:
	TuGiac() :Shape() {};
};
class HinhChuNhat : public TuGiac {
public:
	HinhChuNhat() :TuGiac() {};
	void draw();
};
class HinhVuong : public TuGiac {
public:
	HinhVuong() :TuGiac() {};
	void draw();
};
RGBColor getPixel(int x, int y);
void putPixel(int x, int y, RGBColor color);
bool isSameColor(RGBColor a, RGBColor b);
void boundaryFill(int, int, RGBColor, RGBColor);
void floodFill(int x, int y, RGBColor oldcolor, RGBColor newcolor);
//Shape* getShape();
//int sortIntersection(vector<Point>& listPoint);
//Point getIntersectionFromLine(Point start1, Point end1, Point start2, Point end2);

