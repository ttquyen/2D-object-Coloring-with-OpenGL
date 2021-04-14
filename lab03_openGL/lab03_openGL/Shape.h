#include "glut.h"
#include"Header.h"
#ifndef SHAPE_H_
#define SHAPE_H_


class Shape {
private:
	//Point _start, _end;
	int button, state;
public:
	Shape();
	virtual void Draw() =0;
};

#endif // !1


