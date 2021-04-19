#include "Header.h"

#include <windows.h>
#include <GL/glut.h> 
static int window;
static int menu_id;
static int submenu_id;
static int value = 0;

static int submenu_tomau_id;
static int submenu_oval_id;
static int submenu_tamgiac_id;
static int submenu_tugiac_id;
static int submenu_dagiacdeu_id;
static int submenu_hinhkhac_id;
static int submenu_dau_id;
static Point startPoint;
static Point endPoint;
//#define maxVer 10000

Shape::Shape() {
    pstart.x = startPoint.x;
    pstart.y = startPoint.y;
    pend.x = endPoint.x;
    pend.y = endPoint.y;
    type = value;
    center.x = (pstart.x + pend.x) / 2;
    center.y = (pstart.y + pend.y) / 2;
}
void Line::draw()
{
    glBegin(GL_LINES);
    glVertex2f(pstart.x, pstart.y);
    glVertex2f(pend.x, pend.y);
    glEnd();
}
void HinhTron::draw()
{
    GLfloat xi, yi, theta = 0;
    float radius = sqrt((pstart.x - pend.x) * (pstart.x - pend.x) + (pstart.y - pend.y) * (pstart.y - pend.y))/2;
    int COUNT;
    for (COUNT = 1; COUNT <= 1000; COUNT++) {
        theta = theta + 0.01;
        xi = center.x + radius * cos(theta);
        yi = center.y + radius * sin(theta);
        glBegin(GL_POINTS);
        glVertex2f(xi, yi);
        glEnd();
        Point tmp = { xi, yi };
        vertice.push_back(tmp);
    }
}
void HinhEllipse::draw() {
    float xi, yi, theta = 0;
    float radius = sqrt((pstart.x - pend.x) * (pstart.x - pend.x) + (pstart.y - pend.y) * (pstart.y - pend.y)) / 2;
    float rb = 20; 

    int COUNT;
    for (COUNT = 1; COUNT <= 1000; COUNT++) {
        theta = theta + 0.01;
        xi = center.x + radius * cos(theta);
        yi = center.y + rb * sin(theta);
        glBegin(GL_POINTS);
        glVertex2f(xi, yi);
        glEnd();
        Point tmp = { xi, yi };
        vertice.push_back(tmp);
    }
}
void TGVuongCan::draw() {
    float radius = sqrt((pstart.x - pend.x) * (pstart.x - pend.x) + (pstart.y - pend.y) * (pstart.y - pend.y));

        glBegin(GL_POLYGON);
        glVertex2f(pend.x, pend.y);
        Point tmp = { pend.x, pend.y };
        vertice.push_back(tmp);

        glVertex2f(pend.x-radius, pend.y);
        tmp = { pend.x - radius, pend.y };
        vertice.push_back(tmp);

        glVertex2f(pend.x - radius, pend.y-radius);
        tmp = { pend.x - radius, pend.y - radius };
        vertice.push_back(tmp);
        glEnd();
}
void TGDeu::draw() {
    float radius = sqrt((pstart.x - pend.x) * (pstart.x - pend.x) + (pstart.y - pend.y) * (pstart.y - pend.y));

    glBegin(GL_POLYGON);
    glVertex2f(pend.x, pend.y);
    glVertex2f(pend.x - radius, pend.y);
    glVertex2f(pend.x - radius/2, pend.y - radius*0.866);
    glEnd();
}
void HinhChuNhat::draw() {
    //glColor3f(1, 1, 0);
    glBegin(GL_POLYGON);
    glVertex2f(pend.x, pend.y);
    glVertex2f(pstart.x, pend.y);
    glVertex2f(pstart.x, pstart.y);
    glVertex2f(pend.x, pstart.y);
    glEnd();
}
void HinhVuong::draw() {
    //glColor3f(1, 0, 0);
    float radius = sqrt((pstart.x - pend.x) * (pstart.x - pend.x) + (pstart.y - pend.y) * (pstart.y - pend.y));

    glBegin(GL_POLYGON);
    glVertex2f(pend.x, pend.y);
    glVertex2f(pend.x - radius, pend.y);
    glVertex2f(pend.x - radius, pend.y - radius);
    glVertex2f(pend.x, pend.y - radius);

    glEnd();
}
void DauTru::draw() {
    //glColor3f(1, 1, 0);
    glBegin(GL_POLYGON);
    glVertex2f(pend.x, pend.y);
    glVertex2f(pstart.x, pend.y);
    glVertex2f(pstart.x, pstart.y);
    glVertex2f(pend.x, pstart.y);
    glEnd();
}
void DauCong::draw() {
    float radius = sqrt((pstart.x - pend.x) * (pstart.x - pend.x) + (pstart.y - pend.y) * (pstart.y - pend.y));
    float unit= radius/3;

    //glColor3f(1, 1, 0);
    glBegin(GL_POLYGON);
    glVertex2f(pend.x, pend.y - unit);
    glVertex2f(pend.x, pend.y - 2 * unit);
    glVertex2f(pend.x - unit, pend.y - 2 * unit);
    glVertex2f(pend.x - unit, pend.y - 3 * unit);
    glVertex2f(pend.x - 2 * unit, pend.y - 3 * unit);
    glVertex2f(pend.x - 2 * unit, pend.y - 2 * unit);
    glVertex2f(pend.x - 3 * unit, pend.y - 2 * unit);
    glVertex2f(pend.x - 3 * unit, pend.y - unit);
    glVertex2f(pend.x - 2 * unit, pend.y - unit);
    glVertex2f(pend.x - 2 * unit, pend.y);
    glVertex2f(pend.x - unit, pend.y);
    glVertex2f(pend.x - unit, pend.y - unit);
    glEnd();
}
void DauNhan::draw() {
    float radius = sqrt((pstart.x - pend.x) * (pstart.x - pend.x) + (pstart.y - pend.y) * (pstart.y - pend.y));
    float unit = radius / 4;

    //glColor3f(1, 1, 0);
    glBegin(GL_POLYGON);
    glVertex2f(pend.x, pend.y - unit);
    glVertex2f(pend.x-unit, pend.y - 2 * unit);
    glVertex2f(pend.x, pend.y - 3 * unit);
    glVertex2f(pend.x - unit, pend.y - 4 * unit);

    glVertex2f(pend.x - 2 * unit, pend.y - 3 * unit);
    glVertex2f(pend.x - 3 * unit, pend.y - 4 * unit);
    glVertex2f(pend.x - 4 * unit, pend.y - 3*unit);
    glVertex2f(pend.x - 3 * unit, pend.y - 2*unit);

    glVertex2f(pend.x - 4 * unit, pend.y-unit);
    glVertex2f(pend.x - 3*unit, pend.y);
    glVertex2f(pend.x - 2*unit, pend.y - unit);
    glVertex2f(pend.x - unit, pend.y);

    glEnd();
}
void DauChia::draw() {
    //glColor3f(1, 1, 0);
    float radius = sqrt((pstart.x - pend.x) * (pstart.x - pend.x) + (pstart.y - pend.y) * (pstart.y - pend.y));
    float unit = radius / 4;

    glBegin(GL_POLYGON);
    glVertex2f(pend.x-unit, pend.y-radius);
    glVertex2f(pend.x - 2*unit, pend.y - radius);
    glVertex2f(pend.x - 3*unit, pend.y);
    glVertex2f(pend.x - 3 * unit, pend.y);
    glVertex2f(pend.x - 2 * unit, pend.y);

    glEnd();
}
void NguGiacDeu::draw() {
    float angleIncrement = 360.0f / 5;  // n is 5 in your case
    angleIncrement *= 3.1416 / 180.0f;    // convert degrees to radians
    float radius = sqrt((pstart.x - pend.x) * (pstart.x - pend.x) + (pstart.y - pend.y) * (pstart.y - pend.y))/2;
    int xa = (pstart.x + pend.x) / 2;
    int ya = (pstart.y + pend.y) / 2;
    glBegin(GL_POLYGON);
    float angle = 0.0f;
    for (int k = 0; k < 5; ++k) {
        glVertex2f(xa+radius * cos(angle), ya+radius * sin(angle));
        angle += angleIncrement;
    }
    glEnd();
}
void LucGiacDeu::draw() {
    float angleIncrement = 360.0f / 6;  // n is 5 in your case
    angleIncrement *= 3.1416 / 180.0f;    // convert degrees to radians
    float radius = sqrt((pstart.x - pend.x) * (pstart.x - pend.x) + (pstart.y - pend.y) * (pstart.y - pend.y)) / 2;
    int xa = (pstart.x + pend.x) / 2;
    int ya = (pstart.y + pend.y) / 2;
    glBegin(GL_POLYGON);
    float angle = 0.0f;
    for (int k = 0; k < 6; ++k) {
        glVertex2f(xa + radius * cos(angle), ya + radius * sin(angle));
        angle += angleIncrement;
    }
    glEnd();
}
void NgoiSao::draw() {
    float radius = sqrt((pstart.x - pend.x) * (pstart.x - pend.x) + (pstart.y - pend.y) * (pstart.y - pend.y));
    float unit = radius / 6;

    //glColor3f(1, 1, 0);
    glBegin(GL_POLYGON);
    glVertex2f(pend.x-0.6*unit, pend.y-0.2*unit);
    glVertex2f(pend.x-1.5*unit, pend.y - 2.5*unit);
    glVertex2f(pend.x , pend.y - 4 * unit);
    glVertex2f(pend.x-2*unit, pend.y - 4 * unit);
    glVertex2f(pend.x - 3*unit, pend.y - 6 * unit);
    glVertex2f(pend.x - 4 * unit, pend.y - 4 * unit);
    glVertex2f(pend.x - 6 * unit, pend.y - 4 * unit);
    glVertex2f(pend.x - 4.5 * unit, pend.y - 2.5 * unit);
    glVertex2f(pend.x - 5.6 * unit, pend.y -0.2*unit);
    glVertex2f(pend.x - 3 * unit, pend.y - 1.5*unit);



    glEnd();
}
void MuiTen::draw() {
    float radius = sqrt((pstart.x - pend.x) * (pstart.x - pend.x) + (pstart.y - pend.y) * (pstart.y - pend.y));
    float unit = radius / 3;

    //glColor3f(1, 1, 0);
    glBegin(GL_POLYGON);
    glVertex2f(pend.x, pend.y - 1.5 * unit);
    glVertex2f(pend.x-unit, pend.y - 3 * unit);
    glVertex2f(pend.x - unit, pend.y - 2 * unit);
    glVertex2f(pend.x - 4*unit, pend.y - 2 * unit);
    glVertex2f(pend.x - 4 * unit, pend.y - unit);
    glVertex2f(pend.x - unit, pend.y - unit);
    glVertex2f(pend.x - unit, pend.y);
    glEnd();
}
void menu(int num) {
    if (num == 0) {
        glutDestroyWindow(window);
        exit(0);
    }
    else {
        value = num;
    }
    glutPostRedisplay();
}
void createMenu(void) {
    //To Mau
    submenu_tomau_id = glutCreateMenu(menu);
    glutAddMenuEntry("Xanh", id_MauXanh);
    glutAddMenuEntry("Do", id_MauDo);
    glutAddMenuEntry("Vang", id_MauVang);


    //Oval
    submenu_oval_id = glutCreateMenu(menu);
    glutAddMenuEntry("Hinh tron", id_HinhTron);
    glutAddMenuEntry("Ellipse", id_Ellipse);

    //TamGiac
    submenu_tamgiac_id = glutCreateMenu(menu);
    glutAddMenuEntry("Vuong Can", id_TgVuongCan);
    glutAddMenuEntry("Deu", id_TgDeu);
    //Tugiac
    submenu_tugiac_id = glutCreateMenu(menu);
    glutAddMenuEntry("Hinh Chu Nhat", id_HinhChuNhat);
    glutAddMenuEntry("Hinh Vuong", id_HinhVuong);

    //dagiacdeu
    submenu_dagiacdeu_id = glutCreateMenu(menu);
    glutAddMenuEntry("Ngu Giac Deu", id_NguGiacDeu);
    glutAddMenuEntry("Luc Giac Deu", id_LucGiacDeu);
    //hinhkhac
    submenu_hinhkhac_id = glutCreateMenu(menu);
    glutAddMenuEntry("Ngoi Sao", id_NgoiSao);
    glutAddMenuEntry("Mui Ten", id_MuiTen);
    //dau
    submenu_dau_id = glutCreateMenu(menu);
    glutAddMenuEntry("Cong", id_DauCong);
    glutAddMenuEntry("Tru", id_DauTru);
    glutAddMenuEntry("Nhan", id_DauNhan);
    glutAddMenuEntry("Chia", id_DauChia);

    //

    submenu_id = glutCreateMenu(menu);

    //Layout subMenu (Tang 2)
    glutAddSubMenu("Oval", submenu_oval_id);
    glutAddSubMenu("Tam Giac", submenu_tamgiac_id);

    glutAddSubMenu("Tu Giac", submenu_tugiac_id);
    glutAddMenuEntry("Line", id_Line);
    glutAddSubMenu("Da Giac Deu", submenu_dagiacdeu_id);
    glutAddSubMenu("Hinh Khac", submenu_hinhkhac_id);
    glutAddSubMenu("Dau", submenu_dau_id);
    glutAddSubMenu("To Mau", submenu_tomau_id);

    //Layout Menu (tang 1)
    menu_id = glutCreateMenu(menu);
    glutAddMenuEntry("Clear", 1);
    glutAddSubMenu("Draw", submenu_id);
    glutAddMenuEntry("Quit", 0);     
    glutAttachMenu(GLUT_RIGHT_BUTTON);
}
RGBColor getPixel(int x, int y) {
    float* ptr = new float[3];
    glReadPixels(x, 500 - y, 1, 1, GL_RGB, GL_FLOAT, ptr);
    RGBColor color;
    color.r = ptr[0];
    color.g = ptr[1];
    color.b = ptr[2];
    return color;
}
void putPixel(int x, int y, RGBColor color) {
    float* ptr = new float[3];
    ptr[0] = color.r;
    ptr[1] = color.g;
    ptr[2] = color.b;
    glRasterPos2i(x, y);
    glDrawPixels(1, 1, GL_RGB, GL_FLOAT, ptr);
    glFlush();
}
bool isSameColor(RGBColor a, RGBColor b) {
    if (abs(a.r - b.r)<0.01 && abs(a.g - b.g) < 0.01 && abs(a.b - b.b) < 0.01)
        return true;
    return false;
}
void boundaryFill(int x, int y, RGBColor fill_color, RGBColor boundary_color)
{
    RGBColor curr = getPixel(x, y);
    cout << x << "   " << y << endl;
    if (!isSameColor(curr, fill_color) && !isSameColor(curr, boundary_color))
    {
        putPixel(x, y, fill_color);
        boundaryFill(x + 1, y, fill_color, boundary_color);
        boundaryFill(x, y + 1, fill_color, boundary_color);
        boundaryFill(x - 1, y, fill_color, boundary_color);
        boundaryFill(x, y - 1, fill_color, boundary_color);
    }
    else
        cout << "huhu" << endl;
}
void floodFill(int x, int y, RGBColor oldcolor, RGBColor newcolor)
{
    RGBColor curr = getPixel(x, y);
    if (isSameColor(curr, oldcolor))
    {
        putPixel(x, y, newcolor);
        floodFill(x + 1, y, oldcolor, newcolor);
        floodFill(x, y + 1, oldcolor, newcolor);
        floodFill(x - 1, y, oldcolor, newcolor);
        floodFill(x, y - 1, oldcolor, newcolor);
    }
}
//Shape* getShape() {
//    float min = 1000;
//    Shape* res = nullptr;
//    for (Shape* sh : listOfShape) {
//        float tmp = distance(startPoint, sh->getCenter());
//        if (tmp <= min) {
//               min = tmp;
//                res = sh;
//        }
//    }
//    return res;
//}
//int sortIntersection(vector<Point>& listPoint) {
//    int numEdge = 0;
//    for (int i = 0; i < listPoint.size() - 1; i++) {
//        for (int j = i + 1; j < listPoint.size(); j++) {
//            if ((abs(listPoint[i].x - listPoint[j].x) < 0.1) && abs(listPoint[i].y - listPoint[j].y) < 0.1) {
//                listPoint.erase(listPoint.begin() + j);
//                ++numEdge;
//            }
//        }
//    }
//    for (int i = 0; i < listPoint.size() - 1; i++) {
//        for (int j = i + 1; j < listPoint.size(); j++) {
//            if (listPoint[i].x > listPoint[j].x) {
//                Point tmp = { listPoint[i].x, listPoint[i].y };
//                listPoint[i].x = listPoint[j].x;
//                listPoint[i].y = listPoint[j].y;
//                listPoint[j].x = tmp.x;
//                listPoint[j].y = tmp.y;
//            }
//        }
//    }
//    return numEdge;
//}
//Point getIntersectionFromLine(Point start1, Point end1, Point start2, Point end2) {
//    Point res;
//    float a1 = end1.y - start1.y;
//    float b1 = start1.x - end1.x;
//    float c1 = a1 * (start1.x) + b1 * (start1.y);
//    float a2 = end2.x - start2.x;
//    float b2 = start2.x - end2.x;
//    float c2 = a2 * (start2.x) + b2 * (start2.y);
//    float d = a1 * b2 - a2 * b1;
//
//    if (abs(d) < 0.1) {
//        res = { -1,-1 };
//    }
//    else {
//        bool intersect = false;
//        float xInter = (b2 * c1 - b1 * c2) / d;
//        float yInter = (a1 * c2 - a2 * c1) / d;
//        float checkX = (xInter - start1.x) * (xInter - end1.x);
//        float checkY = (yInter - start1.y) * (yInter - end1.y);
//
//        if (checkX < 0 && abs(checkX)>1) {
//            intersect = true;
//        }
//        else if (checkX < 0.1) {
//            if (checkY < 0 && abs(checkY)>1) {
//                intersect = true;
//            }
//            else if (checkY < 0.1) {
//                intersect = true;
//            }
//            else if (abs(checkX) == 0 && abs(checkY) == 0) {
//                intersect = true;
//            }
//        }
//
//        if (intersect) {
//            res = { xInter, yInter };
//        }
//        else res = { -1,-1 };
//
//    }
//    return res;
//
//}
//vector<Point> Shape::getIntersection(float y, float xMin, float xMax) {
//    vector<Point> res;
//    Point startY = { xMin, y };
//    Point endY = { xMax, y };
//    for (int i = 0; i < vertice.size(); i++) {
//        int j = i + 1;
//        if (j == vertice.size()) {
//            j = 0;
//        }
//        Point tmp = getIntersectionFromLine(vertice[i], vertice[j], startY, endY);
//        if (tmp.x != -1 && tmp.y != -1) {
//            res.push_back(tmp);
//        }
//    }
//    return res;
//}
//void scanline() {
//    Shape* shape = getShape();
//    vector<Point> listOfVertices = shape->getVertice();
//    Point p1 = shape->getStartPoint();
//    Point p2 = shape->getEndPoint();
//    float xMin = p1.x, xMax = p2.x;
//    float yMin = p1.y, yMax = p2.y;
//
//    float yLine = yMin + 1;
//    while (yLine < yMax) {
//        vector<Point>inter = shape->getIntersection(yLine, xMin, xMax);
//        if (inter.size() > 1) {
//            int count = sortIntersection(inter);
//            if (count == 0) {
//                int i = 0;
//                int j;
//                while (i < inter.size() && (i != inter.size() - 1)) {
//                    j = i + 1;
//                    for (int k = inter[i].x; k <= inter[j].x; k++) {
//                        putPixel(k, yLine, F_Color_Yellow);
//                    }
//                    i = i + 2;
//
//                }
//                glEnd();
//            }
//            else {
//                int i = 0;
//                int j;
//                while (i < inter.size() - 1) {
//                    j = i + 1;
//                    for (int k = inter[i].x; k <= inter[j].x; k++) {
//                        putPixel(k, yLine, F_Color_Yellow);
//                    }
//                    i = j;
//                }
//                glEnd();
//            }
//        }
//        ++yLine;
//    }
//    Sleep(100);
//    glFlush();
//}
void display(void) {
    glClear(GL_COLOR_BUFFER_BIT);   if (value == 1) {
        return; //glutPostRedisplay();
    }

    for (int i = 0; i < listOfShape.size(); i++) {
        listOfShape[i]->draw();
    }
    glFlush();
    //glutPostRedisplay();
}
void mouse(int button, int state, int x, int y) {


    if (button == GLUT_LEFT_BUTTON)
    {
        if (state == GLUT_DOWN) {
            startPoint.x = x;
            startPoint.y = y;
        }
        if (state == GLUT_UP) {
            endPoint.x = x;
            endPoint.y = y;
            switch (value) {
            case id_HinhTron: 
            {
                cout << "tron" << endl;
                HinhTron* tmpLine = new HinhTron();
                Shape* obj = tmpLine;
                listOfShape.push_back(obj);
            }
            break;
            case id_Ellipse:
            {
                cout << "ellipse" << endl;
                HinhEllipse* tmpLine = new HinhEllipse();
                Shape* obj = tmpLine;
                listOfShape.push_back(obj);

            }
            break;
            case id_TgVuongCan:
            {
                cout << "vc" << endl;
                TGVuongCan* tmpLine = new TGVuongCan();
                Shape* obj = tmpLine;
                listOfShape.push_back(obj);
            }
            break;
            case id_TgDeu:
            {
                cout << "deu" << endl;
                TGDeu* tmpLine = new TGDeu();
                Shape* obj = tmpLine;
                listOfShape.push_back(obj);

            }
            break;
            case id_HinhChuNhat:
            {
                HinhChuNhat* tmpLine = new HinhChuNhat();
                Shape* obj = tmpLine;
                listOfShape.push_back(obj);
            }
            break;
            case id_HinhVuong:
            {
                HinhVuong* tmpLine = new HinhVuong();
                Shape* obj = tmpLine;
                listOfShape.push_back(obj);
            }
            break;
            case id_Line:
            {
                Line* tmpLine = new Line();
                Shape* obj = tmpLine;
                listOfShape.push_back(obj);
            }
            break;
            case id_DauCong:
            {
                DauCong* tmpLine = new DauCong();
                Shape* obj = tmpLine;
                listOfShape.push_back(obj);
            }
            break;

            case id_DauTru:
            {
                DauTru* tmpLine = new DauTru();
                Shape* obj = tmpLine;
                listOfShape.push_back(obj);
            }
            break;
            case id_DauNhan:
            {
                DauNhan* tmpLine = new DauNhan();
                Shape* obj = tmpLine;
                listOfShape.push_back(obj);
            }
            break;
            case id_DauChia:
            {
                DauChia* tmpLine = new DauChia();
                Shape* obj = tmpLine;
                listOfShape.push_back(obj);
            }
            break;
            case id_NguGiacDeu:
            {
                NguGiacDeu* tmpLine = new NguGiacDeu();
                Shape* obj = tmpLine;
                listOfShape.push_back(obj);
            }
            break;
            case id_LucGiacDeu:
            {
                LucGiacDeu* tmpLine = new LucGiacDeu();
                Shape* obj = tmpLine;
                listOfShape.push_back(obj);
            }
            break;
            case id_NgoiSao:
            {
                NgoiSao* tmpLine = new NgoiSao();
                Shape* obj = tmpLine;
                listOfShape.push_back(obj);
            }
            break;
            case id_MuiTen:
            {
                MuiTen* tmpLine = new MuiTen();
                Shape* obj = tmpLine;
                listOfShape.push_back(obj);
            }
            break;
            case id_MauXanh:
            {
                //boundaryFill(x, y, F_Color, B_Color);
                floodFill(x, y, O_Color, F_Color_Blue);
                //scanline();
            }
            break;
            case id_MauDo:
            {
                //boundaryFill(x, y, F_Color, B_Color);
                floodFill(x, y, O_Color, F_Color_Red);
            }
            break;
            case id_MauVang:
            {
                //boundaryFill(x, y, F_Color, B_Color);
                floodFill(x, y, O_Color, F_Color_Yellow);
            }
            break;
            }
        }
    }
    glutPostRedisplay();
};
void motion(int x, int y) {
    endPoint.x = x;
    endPoint.y = y;
    glutPostRedisplay();
}
void init(void) {
    glClearColor(1.0, 1.0, 1.0, 0.0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0.0, 500, 500, 0.0);
    glColor3f(1, 1, 1); 
    glPointSize(2); //size
    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
}
int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGBA | GLUT_SINGLE);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);
    window = glutCreateWindow("18125110");
    init();
    createMenu();
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glutMouseFunc(mouse);
    glutDisplayFunc(display);
    glutMotionFunc(motion);
    glutMainLoop();
    return EXIT_SUCCESS;
}