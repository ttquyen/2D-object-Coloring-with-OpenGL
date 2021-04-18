#include "Header.h"

#include <windows.h>
#include <GL/glut.h> 
static int window;
static int menu_id;
static int submenu_id;
static int value = 0;

static int submenu_oval_id;
static int submenu_tamgiac_id;
static int submenu_tugiac_id;
static int submenu_dagiacdeu_id;
static int submenu_hinhkhac_id;
static int submenu_dau_id;
static Point startPoint;
static Point endPoint;


Shape::Shape() {
    pstart.x = startPoint.x;
    pstart.y = startPoint.y;
    pend.x = endPoint.x;
    pend.y = endPoint.y;
}
void Line::draw()
{
    cout << "ve duong thang na" << endl;
    //glColor3f(1, 0, 0);
    glBegin(GL_LINES);
    glVertex2f(pstart.x, pstart.y);
    glVertex2f(pend.x, pend.y);
    glEnd();

}
void HinhTron::draw()
{
    cout << "ve hinh tron na" << endl;
    //glColor3f(1, 0, 0);
    GLfloat xi, yi, theta = 0;
    float radius = sqrt((pstart.x - pend.x) * (pstart.x - pend.x) + (pstart.y - pend.y) * (pstart.y - pend.y))/2;
    int xa = (pstart.x + pend.x) / 2;
    int ya = (pstart.y + pend.y) / 2;

    //GLfloat x_c = 0, y_c = 0, r = 0.5;
    int COUNT;
    //glClear(GL_COLOR_BUFFER_BIT);
    for (COUNT = 1; COUNT <= 10000; COUNT++) {
        theta = theta + 0.001;
        xi = xa + radius * cos(theta);
        yi = ya + radius * sin(theta);
        glBegin(GL_POINTS);
        glVertex2f(xi, yi);
        glEnd();
    }
    //glFlush();

}
void HinhEllipse::draw() {
    float xi, yi, theta = 0;
    float radius = sqrt((pstart.x - pend.x) * (pstart.x - pend.x) + (pstart.y - pend.y) * (pstart.y - pend.y)) / 2;
    int xa = (pstart.x + pend.x) / 2;
    int ya = (pstart.y + pend.y) / 2;
    float rb = 50; 

    int COUNT;
    for (COUNT = 1; COUNT <= 10000; COUNT++) {
        theta = theta + 0.001;
        xi = xa + radius * cos(theta);
        yi = ya + rb * sin(theta);
        glBegin(GL_POINTS);
        glVertex2f(xi, yi);
        glEnd();
    }
}
void TGVuongCan::draw() {
    glColor3f(1, 0, 0);
    float radius = sqrt((pstart.x - pend.x) * (pstart.x - pend.x) + (pstart.y - pend.y) * (pstart.y - pend.y));

        glBegin(GL_POLYGON);
        glVertex2f(pend.x, pend.y);
        glVertex2f(pend.x-radius, pend.y);
        glVertex2f(pend.x - radius, pend.y-radius);
        glEnd();
}

void TGDeu::draw() {
    //glColor3f(1, 0, 0);
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
    //glVertex2f(pend.x - 3 * unit, pend.y);
    //glVertex2f(pend.x - 2 * unit, pend.y - unit);
   // glVertex2f(pend.x - unit, pend.y);

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

    //Layout Menu (tang 1)
    menu_id = glutCreateMenu(menu);
    glutAddMenuEntry("Clear", 1);
    glutAddSubMenu("Draw", submenu_id);
    glutAddMenuEntry("Quit", 0);     glutAttachMenu(GLUT_RIGHT_BUTTON);
}
RGBColor getPixel(int x, int y) {
    unsigned char* ptr = new unsigned char[3];
    glReadPixels(x, 500 - y, 1, 1, GL_RGB, GL_UNSIGNED_BYTE, ptr);
    RGBColor color;
    color.r = ptr[0];
    color.g = ptr[1];
    color.b = ptr[2];
    return color;
}

void putPixel(int x, int y, RGBColor color) {
    unsigned char* ptr = new unsigned char[3];
    ptr[0] = color.r;
    ptr[1] = color.g;
    ptr[2] = color.b;
    glRasterPos2i(x, y);
    glDrawPixels(1, 1, GL_RGB, GL_UNSIGNED_BYTE, ptr);
    glFlush();
}

bool isSameColor(RGBColor a, RGBColor b) {
    if (a.r == b.r && a.g == b.g && a.b == b.b)
        return true;
    return false;
}
void boundaryFill(int x, int y, RGBColor fill_color, RGBColor boundary_color)
{
    RGBColor curr = getPixel(x, y);
    if (!isSameColor(curr, fill_color) && !isSameColor(curr, boundary_color))
    {
        putPixel(x, y, fill_color);
        boundaryFill(x + 1, y, fill_color, boundary_color);
        boundaryFill(x, y + 1, fill_color, boundary_color);
        boundaryFill(x - 1, y, fill_color, boundary_color);
        boundaryFill(x, y - 1, fill_color, boundary_color);
    }
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


    // Save the left button state
    if (button == GLUT_LEFT_BUTTON)
    {
        if (state == GLUT_DOWN) {
            startPoint.x = x;
            startPoint.y = y;

           
            //cout << startPoint.x << "  " << startPoint.y << endl;
        }
        if (state == GLUT_UP) {
            endPoint.x = x;
            endPoint.y = y;
            //cout << endPoint.x << "  " << endPoint.y << endl;
            if (startPoint.x == endPoint.x && startPoint.y == endPoint.y) {
                RGBColor B_Color;
                B_Color.r = 1;
                B_Color.g = 1;
                B_Color.b = 1;
                RGBColor F_Color;
                F_Color.r = 0.75;
                F_Color.g = 1;
                F_Color.b = 0;
                cout << "vo day" << endl;
                boundaryFill(x, y, F_Color, B_Color);
            }
           // Shape shp;
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
                cout << "duong thang" << endl;
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
            }
        }
        if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN && startPoint.x==endPoint.x &&startPoint.y==endPoint.y) {
            //RGBColor B_Color;
            //B_Color.r= 1;
            //B_Color.g = 0;
            //B_Color.b = 0;
            RGBColor O_Color;
            O_Color.r = 0;
            O_Color.g = 0;
            O_Color.b = 0;
            cout << "vo day" << endl;
            RGBColor F_Color;
            F_Color.r = 1;
            F_Color.g = 1;
            F_Color.b = 0;
            //boundaryFill(x, y, F_Color, B_Color);
            floodFill(x, y, O_Color, F_Color);
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
    glColor3f(1, 1, 1); // blue
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