#pragma once

#include <iostream>
#include <vector>

#include "Shape.h"
struct Point {
	int x, y;
};
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

using namespace std;
class Painter {
private:
	Painter();

	vector<Shape*> listOfShape;

public:

};

