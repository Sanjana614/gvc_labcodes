#include<GLUT/glut.h>
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define MAX_CPTS  25
#define PI 3.14


GLfloat cpts[MAX_CPTS][3];
int ncpts = 0;
static int width = 1000, height = 1000;
float l, b;
int maxWidth, maxHeight;
int count = 0;


float scale = 1;

void addPoint(float l, float b) {

    cpts[ncpts][0] = (l * scale)/maxHeight;
    cpts[ncpts][1] = (b*scale)/maxWidth;
    cpts[ncpts][2] = 0.0;
    ncpts++;
}

void addIntitialPoints() {
    addPoint(0, 0);
    addPoint(b + b/2, l/4);
    addPoint(b + b/2, 3*(l/4));
    addPoint(0, l);
}
void drawCurves()
{
    int i;
    for(i=0; i<ncpts-3; i +=3)
    {
        

        glMap1f(GL_MAP1_VERTEX_3, 0.0, 1.0, 3, 4, cpts[i]);
        glMapGrid1f(30, 0.0, 1.0);
        glEvalMesh1(GL_LINE, 0, 30);
    }
    glFlush();
}


void drawPetal() {
    glPushMatrix();
        glScalef(-1, 1, 1);
        drawCurves();
    glPopMatrix();
    drawCurves();
}

float getRadians(float degree) {
    return (degree * PI)/180;
}

void drawPetalAtAngele(float angle) {
    //float angle = getRadians(degree);
    glPushMatrix();
        glRotatef(angle, 0, 0, 1);
        drawPetal();
    glPopMatrix();
}


void drawFlower(int n) {
    int angle = 0;
    int delta_angle = (360.0)/n;

    for(int i = 0; i < n; i++) {
        drawPetalAtAngele(angle + i * delta_angle);
    }
}


void display()
{
    int i;
    glClear(GL_COLOR_BUFFER_BIT);

    srand(time(0));

    int flowerCount=10;
    for(int i=0;i<flowerCount;++i){
        double x=(double)(rand()%100 -50)/100 ;
        double y=(double)(rand()%100 -50)/100 ;
        int scale=rand()%10;
         glPushMatrix();
            glTranslated(x, y,1);
            glScalef((double)1/scale, (double)1/scale, (double)1/scale);
            drawFlower(6);
        glPopMatrix();
    }
   


    glFlush();
}

void reshape(int w, int h)
{
    width = w;
    height = h;

    maxWidth = w > h ? w : h;
    maxHeight = maxWidth;

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);
    glMatrixMode(GL_MODELVIEW);
    glViewport(0, 0, w, h);

    ncpts = 0;
    addIntitialPoints();
    glutPostRedisplay();
}



void addReflection() {

}
void keyboard(unsigned char key, int x, int y)
{
    
}

int main(int argc, char **argv)
{
    l=280;
    b=30;

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB);
    glutInitWindowSize(width, height);
    glutCreateWindow("curves");
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboard);
    glClearColor(1.0, 1.0, 1.0, 1.0);
    glColor3f(0.0, 0.0, 0.0);
    glPointSize(5.0);
    glEnable(GL_MAP1_VERTEX_3);
    glutMainLoop();
}
