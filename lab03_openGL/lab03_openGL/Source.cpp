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
}
void Line::draw()
{
    cout << "ve duong thang na" << endl;
    glBegin(GL_LINES);
    glVertex2f(pstart.x, pstart.y);
    glVertex2f(pend.x, pend.y);
    glEnd();

}
void HinhTron::draw()
{
    cout << "ve hinh tron na" << endl;
    GLfloat xi, yi, theta = 0;
    float radius = sqrt((pstart.x - pend.x) * (pstart.x - pend.x) + (pstart.y - pend.y) * (pstart.y - pend.y))/2;
    int xa = (pstart.x + pend.x) / 2;
    int ya = (pstart.y + pend.y) / 2;

    int COUNT;
    for (COUNT = 1; COUNT <= 10000; COUNT++) {
        theta = theta + 0.001;
        xi = xa + radius * cos(theta);
        yi = ya + radius * sin(theta);
        glBegin(GL_POINTS);
        glVertex2f(xi, yi);
        glEnd();
    }
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
    float radius = sqrt((pstart.x - pend.x) * (pstart.x - pend.x) + (pstart.y - pend.y) * (pstart.y - pend.y));

        glBegin(GL_POLYGON);
        glVertex2f(pend.x, pend.y);
        glVertex2f(pend.x-radius, pend.y);
        glVertex2f(pend.x - radius, pend.y-radius);
        /*storeEdgeInTable(pend.x, pend.y, pend.x - radius, pend.y);
        storeEdgeInTable( pend.x - radius, pend.y, pend.x - radius, pend.y - radius);
        storeEdgeInTable(pend.x - radius, pend.y - radius, pend.x, pend.y);
*/

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

    /*storeEdgeInTable(pend.x - 0.6 * unit, pend.y - 0.2 * unit,pend.x - 1.5 * unit, pend.y - 2.5 * unit);
    storeEdgeInTable(pend.x - 1.5 * unit, pend.y - 2.5 * unit,pend.x, pend.y - 4 * unit);
    storeEdgeInTable(pend.x, pend.y - 4 * unit,pend.x - 2 * unit, pend.y - 4 * unit);
    storeEdgeInTable(pend.x - 2 * unit, pend.y - 4 * unit,pend.x - 3 * unit, pend.y - 6 * unit);
    storeEdgeInTable(pend.x - 3 * unit, pend.y - 6 * unit,pend.x - 4 * unit, pend.y - 4 * unit);
    storeEdgeInTable(pend.x - 4 * unit, pend.y - 4 * unit,pend.x - 6 * unit, pend.y - 4 * unit);
    storeEdgeInTable(pend.x - 6 * unit, pend.y - 4 * unit,pend.x - 4.5 * unit, pend.y - 2.5 * unit);
    storeEdgeInTable(pend.x - 4.5 * unit, pend.y - 2.5 * unit,pend.x - 5.6 * unit, pend.y - 0.2 * unit);
    storeEdgeInTable(pend.x - 5.6 * unit, pend.y - 0.2 * unit,pend.x - 3 * unit, pend.y - 1.5 * unit);
    storeEdgeInTable(pend.x - 3 * unit, pend.y - 1.5 * unit, pend.x - 0.6 * unit, pend.y - 0.2 * unit);*/




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

//
//typedef struct edgebucket
//{
//    int ymax;   //max y-coordinate of edge
//    float xofymin;  //x-coordinate of lowest edge point updated only in aet
//    float slopeinverse;
//}EdgeBucket;
//
//typedef struct edgetabletup
//{
//
//    int countEdgeBucket;    //no. of edgebuckets
//    EdgeBucket buckets[maxVer];
//}EdgeTableTuple;
//
//EdgeTableTuple EdgeTable[500], ActiveEdgeTuple;
//
//
//// Scanline Function
//void initEdgeTable()
//{
//    int i;
//    for (i = 0; i < 500; i++)
//    {
//        EdgeTable[i].countEdgeBucket = 0;
//    }
//
//    ActiveEdgeTuple.countEdgeBucket = 0;
//}

//
//void printTuple(EdgeTableTuple* tup)
//{
//    int j;
//
//    if (tup->countEdgeBucket)
//        printf("\nCount %d-----\n", tup->countEdgeBucket);
//
//    for (j = 0; j < tup->countEdgeBucket; j++)
//    {
//        printf(" %d+%.2f+%.2f",
//            tup->buckets[j].ymax, tup->buckets[j].xofymin, tup->buckets[j].slopeinverse);
//    }
//}
//
//void printTable()
//{
//    int i, j;
//
//    for (i = 0; i < 500; i++)
//    {
//        if (EdgeTable[i].countEdgeBucket)
//            printf("\nScanline %d", i);
//
//        printTuple(&EdgeTable[i]);
//    }
//}

//
///* Function to sort an array using insertion sort*/
//void insertionSort(EdgeTableTuple* ett)
//{
//    int i, j;
//    EdgeBucket temp;
//
//    for (i = 1; i < ett->countEdgeBucket; i++)
//    {
//        temp.ymax = ett->buckets[i].ymax;
//        temp.xofymin = ett->buckets[i].xofymin;
//        temp.slopeinverse = ett->buckets[i].slopeinverse;
//        j = i - 1;
//
//        while ((temp.xofymin < ett->buckets[j].xofymin) && (j >= 0))
//        {
//            ett->buckets[j + 1].ymax = ett->buckets[j].ymax;
//            ett->buckets[j + 1].xofymin = ett->buckets[j].xofymin;
//            ett->buckets[j + 1].slopeinverse = ett->buckets[j].slopeinverse;
//            j = j - 1;
//        }
//        ett->buckets[j + 1].ymax = temp.ymax;
//        ett->buckets[j + 1].xofymin = temp.xofymin;
//        ett->buckets[j + 1].slopeinverse = temp.slopeinverse;
//    }
//}
//
//
//void storeEdgeInTuple(EdgeTableTuple* receiver, int ym, int xm, float slopInv)
//{
//    // both used for edgetable and active edge table..
//    // The edge tuple sorted in increasing ymax and x of the lower end.
//    (receiver->buckets[(receiver)->countEdgeBucket]).ymax = ym;
//    (receiver->buckets[(receiver)->countEdgeBucket]).xofymin = (float)xm;
//    (receiver->buckets[(receiver)->countEdgeBucket]).slopeinverse = slopInv;
//
//    // sort the buckets
//    insertionSort(receiver);
//
//    (receiver->countEdgeBucket)++;
//
//
//}
//
//void storeEdgeInTable(int x1, int y1, int x2, int y2)
//{
//    float m, minv;
//    int ymaxTS, xwithyminTS, scanline; //ts stands for to store
//
//    if (x2 == x1)
//    {
//        minv = 0.000000;
//    }
//    else
//    {
//        m = ((float)(y2 - y1)) / ((float)(x2 - x1));
//
//        // horizontal lines are not stored in edge table
//        if (y2 == y1)
//            return;
//
//        minv = (float)1.0 / m;
//        //printf("\nSlope string for %d %d & %d %d: %f", x1, y1, x2, y2, minv);
//    }
//
//    if (y1 > y2)
//    {
//        scanline = y2;
//        ymaxTS = y1;
//        xwithyminTS = x2;
//    }
//    else
//    {
//        scanline = y1;
//        ymaxTS = y2;
//        xwithyminTS = x1;
//    }
//    // the assignment part is done..now storage..
//    storeEdgeInTuple(&EdgeTable[scanline], ymaxTS, xwithyminTS, minv);
//
//
//}
//
//void removeEdgeByYmax(EdgeTableTuple* Tup, int yy)
//{
//    int i, j;
//    for (i = 0; i < Tup->countEdgeBucket; i++)
//    {
//        if (Tup->buckets[i].ymax == yy)
//        {
//            printf("\nRemoved at %d", yy);
//
//            for (j = i; j < Tup->countEdgeBucket - 1; j++)
//            {
//                Tup->buckets[j].ymax = Tup->buckets[j + 1].ymax;
//                Tup->buckets[j].xofymin = Tup->buckets[j + 1].xofymin;
//                Tup->buckets[j].slopeinverse = Tup->buckets[j + 1].slopeinverse;
//            }
//            Tup->countEdgeBucket--;
//            i--;
//        }
//    }
//}
//
//
//void updatexbyslopeinv(EdgeTableTuple* Tup)
//{
//    int i;
//
//    for (i = 0; i < Tup->countEdgeBucket; i++)
//    {
//        (Tup->buckets[i]).xofymin = (Tup->buckets[i]).xofymin + (Tup->buckets[i]).slopeinverse;
//    }
//}
//
//
//void ScanlineFill()
//{
//    /* Follow the following rules:
//    1. Horizontal edges: Do not include in edge table
//    2. Horizontal edges: Drawn either on the bottom or on the top.
//    3. Vertices: If local max or min, then count twice, else count
//        once.
//    4. Either vertices at local minima or at local maxima are drawn.*/
//
//
//    int i, j, x1, ymax1, x2, ymax2, FillFlag = 0, coordCount;
//
//    // we will start from scanline 0; 
//    // Repeat until last scanline:
//    for (i = 0; i < 500; i++)//4. Increment y by 1 (next scan line)
//    {
//
//        // 1. Move from ET bucket y to the
//        // AET those edges whose ymin = y (entering edges)
//        for (j = 0; j < EdgeTable[i].countEdgeBucket; j++)
//        {
//            storeEdgeInTuple(&ActiveEdgeTuple, EdgeTable[i].buckets[j].
//                ymax, EdgeTable[i].buckets[j].xofymin,
//                EdgeTable[i].buckets[j].slopeinverse);
//        }
//        //printTuple(&ActiveEdgeTuple);
//
//        // 2. Remove from AET those edges for 
//        // which y=ymax (not involved in next scan line)
//        removeEdgeByYmax(&ActiveEdgeTuple, i);
//
//        //sort AET (remember: ET is presorted)
//        insertionSort(&ActiveEdgeTuple);
//
//        //printTuple(&ActiveEdgeTuple);
//
//        //3. Fill lines on scan line y by using pairs of x-coords from AET
//        j = 0;
//        FillFlag = 0;
//        coordCount = 0;
//        x1 = 0;
//        x2 = 0;
//        ymax1 = 0;
//        ymax2 = 0;
//        while (j < ActiveEdgeTuple.countEdgeBucket)
//        {
//            if (coordCount % 2 == 0)
//            {
//                x1 = (int)(ActiveEdgeTuple.buckets[j].xofymin);
//                ymax1 = ActiveEdgeTuple.buckets[j].ymax;
//                if (x1 == x2)
//                {
//                    /* three cases can arrive-
//                        1. lines are towards top of the intersection
//                        2. lines are towards bottom
//                        3. one line is towards top and other is towards bottom
//                    */
//                    if (((x1 == ymax1) && (x2 != ymax2)) || ((x1 != ymax1) && (x2 == ymax2)))
//                    {
//                        x2 = x1;
//                        ymax2 = ymax1;
//                    }
//
//                    else
//                    {
//                        coordCount++;
//                    }
//                }
//
//                else
//                {
//                    coordCount++;
//                }
//            }
//            else
//            {
//                x2 = (int)ActiveEdgeTuple.buckets[j].xofymin;
//                ymax2 = ActiveEdgeTuple.buckets[j].ymax;
//
//                FillFlag = 0;
//
//                // checking for intersection...
//                if (x1 == x2)
//                {
//                    /*three cases can arive-
//                        1. lines are towards top of the intersection
//                        2. lines are towards bottom
//                        3. one line is towards top and other is towards bottom
//                    */
//                    if (((x1 == ymax1) && (x2 != ymax2)) || ((x1 != ymax1) && (x2 == ymax2)))
//                    {
//                        x1 = x2;
//                        ymax1 = ymax2;
//                    }
//                    else
//                    {
//                        coordCount++;
//                        FillFlag = 1;
//                    }
//                }
//                else
//                {
//                    coordCount++;
//                    FillFlag = 1;
//                }
//
//
//                if (FillFlag)
//                {
//                    //drawing actual lines...
//                    glColor3f(0.0f, 0.7f, 0.0f);
//
//                    glBegin(GL_LINES);
//                    glVertex2i(x1, i);
//                    glVertex2i(x2, i);
//                    glEnd();
//                    glFlush();
//
//                    // printf("\nLine drawn from %d,%d to %d,%d",x1,i,x2,i);
//                }
//
//            }
//
//            j++;
//        }
//
//
//        // 5. For each nonvertical edge remaining in AET, update x for new y
//        updatexbyslopeinv(&ActiveEdgeTuple);
//    }
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
            case id_MauXanh:
            {
                //boundaryFill(x, y, F_Color, B_Color);
                floodFill(x, y, O_Color, F_Color_Blue);
                //ScanlineFill();
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