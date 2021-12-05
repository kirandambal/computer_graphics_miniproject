#include <GL/glut.h>
#include <GL/glu.h>
#include<math.h>
#include <stdlib.h>
#include<stdio.h>
#define PI 3.1416

GLint i;
GLfloat cx=0,str=500.0,mn=500.0,mcloud=0,fan=0,sx=0,mc=0,xc=0,cm=0,radius=4,radiusa=3.5,radiusb=3.5,radiusc=3,radiusd=4,star=0,cara=0,carb=0,carc=0,card=0,care=0,carf=0;
GLfloat sr=0.0,sg=0.749,sb=1.0;
float rfan=0.0;
int frameNumber = 0;

struct wcPt3D
{
	GLfloat x,y,z;
};
GLsizei winWidth=600,winHeight=600;
GLfloat xwcMin=0.0,xwcMax=130.0;
GLfloat ywcMin=0.0,ywcMax=130.0;
void bino(GLint n,GLint *C)
{
	GLint k,j;
	for(k=0;k<=n;k++)
	{
		C[k]=1;
		for(j=n;j>=k+1;j--)
		C[k]*=j;
		for(j=n-k;j>=2;j--)
		C[k]/=j;
	}
}
void computeBezPt(GLfloat u,struct wcPt3D *bezPt,GLint nCtrlPts,struct wcPt3D *ctrlPts,GLint *C)
{
	GLint k,n=nCtrlPts-1;
	GLfloat bezBlendFcn;
	bezPt->x =bezPt->y =bezPt->z=0.0;
	for(k=0;k<nCtrlPts;k++)
	{
		bezBlendFcn=C[k]*pow(u,k)*pow(1-u,n-k);
		bezPt->x += ctrlPts[k].x * bezBlendFcn;
		bezPt->y += ctrlPts[k].y * bezBlendFcn;
		bezPt->z += ctrlPts[k].z * bezBlendFcn;
	}
}
void bezier(struct wcPt3D *ctrlPts, GLint nCtrlPts,GLint nBezCurvePts)
{
	struct wcPt3D bezCurvePt;
	GLfloat u;
	GLint *C,k;
	C=new GLint[nCtrlPts];
	bino(nCtrlPts-1,C);
	glBegin(GL_LINE_STRIP);
	for(k=0;k<=nBezCurvePts;k++)
	{
		u=GLfloat(k)/GLfloat(nBezCurvePts);
		computeBezPt(u,&bezCurvePt,nCtrlPts,ctrlPts,C);
		glVertex2f(bezCurvePt.x, bezCurvePt.y);
	}
glEnd();
delete[]C;
}


void circle(GLdouble rad)
{
    GLint points = 50;
    GLdouble delTheta = (2.0 * PI) / (GLdouble)points;
    GLdouble theta = 0.0;

    glBegin(GL_POLYGON);
    {
        for( i = 0; i <=50; i++, theta += delTheta )
        {
            glVertex2f(rad * cos(theta),rad * sin(theta));
        }
    }
    glEnd();
}

void bus()
{

    glColor3f(1.0, 0.5, 0.0);
    glBegin(GL_POLYGON);
    glVertex3f(-0.52, 0.2, 0);
    glVertex3f(-0.89, 0.2, 0);
    glVertex3f(-0.86, 0.5, 0);
    glVertex3f(-0.52, 0.5, 0);
    glEnd();

    glColor3f(1.0, 0.5, 0.0);
    glBegin(GL_POLYGON);
    glVertex3f(-0.39, 0.2, 0);
    glVertex3f(-0.52, 0.2, 0);
    glVertex3f(-0.52, 0.5, 0);
    glVertex3f(-0.43, 0.45, 0);
    glEnd();

     glColor3f(255.0, 223.0, 0.0);
    glBegin(GL_POLYGON);
    glVertex3f(cara, carb, 0);
    glVertex3f(carc, card, 0);
    glVertex3f(care, carf, 0);
    glVertex3f(care, carf, 0);
    glEnd();

    glColor3f(1.0, 1.5, 1.0);
    glBegin(GL_POLYGON);
    //glScalef(1.7,1.7,1.0);
    //glTranslatef(-.5, .2, 0);
    glVertex3f(-0.55, 0.5, 0);
    glVertex3f(-0.80, 0.5, 0);
    glVertex3f(-0.78, 0.75, 0);
    glVertex3f(-0.58, 0.75, 0);
    glEnd();

    glColor3f(0, 0, 0);
    glBegin(GL_LINES);
    glVertex3f(-0.65, 0.2, 0);
    glVertex3f(-0.65, 0.5, 0);
    glEnd();



    glColor3f(0, 0, 0);
    glBegin(GL_LINES);
    glVertex3f(-0.75, 0.2, 0);
    glVertex3f(-0.75, 0.5, 0);
    glEnd();


    glColor3f(0, 0, 0);
    glBegin(GL_LINES);
    glVertex3f(-0.55, 0.2, 0);
    glVertex3f(-0.55, 0.5, 0);
    glEnd();

    glColor3f(0, 0, 0);
    glBegin(GL_LINES);
    glVertex3f(-0.55, 0.5, 0);
    glVertex3f(-0.58, 0.77, 0);
    glEnd();


    glColor3f(0, 0, 0);
    glBegin(GL_LINES);
    glVertex3f(-0.65, 0.5, 0);
    glVertex3f(-0.68, 0.77, 0);
    glEnd();


    glColor3f(0, 0, 0);
    glBegin(GL_LINES);
    glVertex3f(-0.75, 0.5, 0);
    glVertex3f(-0.78, 0.77, 0);
    glEnd();

    glColor3f(0, 0, 0);
    glBegin(GL_LINES);
    glVertex3f(-0.80, 0.5, 0);
    glVertex3f(-0.78, 0.77, 0);
    glEnd();

    glColor3f(0, 0, 0);
    glBegin(GL_LINES);
    glVertex3f(-0.6, 0.4, 0);
    glVertex3f(-0.62, 0.4, 0);
    glEnd();

    glColor3f(0, 0, 0);
    glBegin(GL_LINES);
    glVertex3f(-0.7, 0.4, 0);
    glVertex3f(-0.72, 0.4, 0);
    glEnd();

      glColor3f(0, 0, 0);
    glBegin(GL_LINES);
    glVertex3f(-0.78, 0.76, 0);
    glVertex3f(-0.58, 0.76, 0);
    glEnd();


    glColor3f(0, 0, 0);
    glBegin(GL_LINES);
    glVertex3f(-0.623, 0.5, 0);
    glVertex3f(-0.622, 0.6, 0);
    glEnd();

    glColor3f(0, 0, 0);
    glBegin(GL_LINES);
    glVertex3f(-0.711, 0.5, 0);
    glVertex3f(-0.71, 0.62, 0);
    glEnd();



	 glColor3f(0.0, 0.0, 0.0);///sss
    glPushMatrix();
    glTranslatef(-.78, .2, 0);
    glRotatef(360,1,1,0);
    circle(0.07);
    glPopMatrix();

    glColor3f(0.0, 0.0, 0.0);///sss
    glPushMatrix();
    glTranslatef(-.5, .2, 0);
    glRotatef(360,1,1,0);
    circle(0.07);
    glPopMatrix();


    glPushMatrix();
	glColor3f(1,1,1);
	glTranslated(-0.78,0.2, 0.0);
	glRotated(mc,0,0,-1);
	glutWireTorus(0.05,0.0000,2,10);
	glPopMatrix();

	glPushMatrix();
	glColor3f(1,1,1);
	glTranslated(-0.5,0.2, 0.0);
	glRotated(mc,0,0,-1);
	glutWireTorus(0.05,0.0000,2,10);
	glPopMatrix();

    glColor3f(0.0, 0.0, 0.0);  //car human1
    glPushMatrix();
    glRotatef(10,10,5,0);
    glTranslatef(-0.62, 0.65, 0);
    glRotatef(360,1,1,0);
    circle(0.03);
    glPopMatrix();

    glColor3f(0.0, 0.0, 0.0);  //car human2
    glPushMatrix();
    glRotatef(10,10,5,0);
    glTranslatef(-0.71, 0.65, 0);
    glRotatef(360,1,1,0);
    circle(0.025);
    glPopMatrix();



}






void buss()
{

    glColor3f(1.0, 0.5, 0.0);
    glBegin(GL_POLYGON);
    glVertex3f(-0.52, 0.2, 0);
    glVertex3f(-0.9, 0.2, 0);
    glVertex3f(-0.87, 0.5, 0);
    glVertex3f(-0.52, 0.5, 0);
    glEnd();

    glColor3f(1.0, 0.5, 0.0);
    glBegin(GL_POLYGON);
    glVertex3f(-0.43, 0.2, 0);
    glVertex3f(-0.52, 0.2, 0);
    glVertex3f(-0.52, 0.5, 0);
    glVertex3f(-0.46, 0.45, 0);
    glEnd();

    glColor3f(1.0, 0.5, 1.0);
    glBegin(GL_POLYGON);
    glVertex3f(-0.53, 0.5, 0);
    glVertex3f(-0.83, 0.5, 0);
    glVertex3f(-0.77, 0.8, 0);
    glVertex3f(-0.56, 0.75, 0);
    glEnd();

    glColor3f(0, 0, 0);
    glBegin(GL_LINES);
    glVertex3f(-0.65, 0.2, 0);
    glVertex3f(-0.65, 0.5, 0);
    glEnd();

    glColor3f(0, 0, 0);
    glBegin(GL_LINES);
    glVertex3f(-0.65, 0.5, 0);
    glVertex3f(-0.68, 0.79, 0);
    glEnd();

    glColor3f(0, 0, 0);
    glBegin(GL_LINES);
    glVertex3f(-0.75, 0.2, 0);
    glVertex3f(-0.75, 0.5, 0);
    glEnd();

    glColor3f(0, 0, 0);
    glBegin(GL_LINES);
    glVertex3f(-0.75, 0.5, 0);
    glVertex3f(-0.77, 0.8, 0);
    glEnd();

    glColor3f(0, 0, 0);
    glBegin(GL_LINES);
    glVertex3f(-0.55, 0.2, 0);
    glVertex3f(-0.55, 0.5, 0);
    glEnd();

    glColor3f(0, 0, 0);
    glBegin(GL_LINES);
    glVertex3f(-0.55, 0.5, 0);
    glVertex3f(-0.58, 0.77, 0);
    glEnd();

    glColor3f(0, 0, 0);
    glBegin(GL_LINES);
    glVertex3f(-0.6, 0.4, 0);
    glVertex3f(-0.62, 0.4, 0);
    glEnd();

    glColor3f(0, 0, 0);
    glBegin(GL_LINES);
    glVertex3f(-0.7, 0.4, 0);
    glVertex3f(-0.72, 0.4, 0);
    glEnd();

    glColor3f(0.0, 0.0, 0.0);///sss
    glPushMatrix();
    glTranslatef(-.78, .2, 0);
    glRotatef(360,1,1,0);
    circle(0.06);
    glPopMatrix();

    glColor3f(0.0, 0.0, 0.0);///sss
    glPushMatrix();
    glTranslatef(-.5, .2, 0);
    glRotatef(360,1,1,0);
    circle(0.06);
    glPopMatrix();

    glColor3f(1.0, 1.0, 1.0);
    glPushMatrix();
    glRotatef(10,10,0,0);
    glTranslatef(-.5, .2, 0);
    glRotatef(360,1,1,0);
    circle(0.02);
    glPopMatrix();

    glColor3f(1.0, 1.0, 1.0);
    glPushMatrix();
    glTranslatef(-.78, .2, 0);
    glRotatef(360,1,1,0);
    circle(0.02);
    glPopMatrix();
}

void cloudB()

{
    //left

    glPushMatrix();
    glTranslatef(4,5.5,0);
    circle(4);
    glPopMatrix();

    //right

    glPushMatrix();
    glTranslatef(-8,5.5,0);
    circle(3.5);
    glPopMatrix();

    //top left

    glPushMatrix();
    glTranslatef(-3.5,9,0);

    circle(3.5);
    glPopMatrix();

    //top right

    glPushMatrix();
    glTranslatef(1,9,0);
    circle(3);
    glPopMatrix();

    //middle

    glPushMatrix();

    //glColor3f (1, 1 ,1);
    glTranslatef(-1.5,5.5,0);
    circle(4);
    glPopMatrix();

}


void a()                                        //mini Cloud

{
    //left

    glPushMatrix();
    glTranslatef(4,5.5,0);
    circle(radius);
    glPopMatrix();

    //right

    glPushMatrix();
    glTranslatef(-8,5.5,0);
    circle(radiusa);
    glPopMatrix();

    //top left

    glPushMatrix();
    glTranslatef(-3.5,9,0);
    circle(radiusb);
    glPopMatrix();

    //top right

    glPushMatrix();
    glTranslatef(1,9,0);
    circle(radiusc);
    glPopMatrix();

    //middle

    glPushMatrix();
    glTranslatef(-1.5,5.5,0);
    circle(radiusd);
    glPopMatrix();

}


void treeleaves()                                        //mini Cloud

{
    //left

    glPushMatrix();
    glTranslatef(4,5.5,0);
    circle(4);
    glPopMatrix();

    //right

    glPushMatrix();
    glTranslatef(-8,5.5,0);
    circle(3.5);
    glPopMatrix();

    //top left

    glPushMatrix();
    glTranslatef(-3.5,9,0);
    circle(3.5);
    glPopMatrix();

    //top right

    glPushMatrix();
    glTranslatef(1,9,0);
    circle(3);
    glPopMatrix();

    //middle

    glPushMatrix();
    glTranslatef(-1.5,5.5,0);
    circle(4);
    glPopMatrix();

}






void c()                                        //One Single Cloud
{
    glPushMatrix();
    glColor3f (1,1,1);
    glTranslatef(35,10,0);
    a();
    glPopMatrix();


    glPushMatrix();
    glColor3f (1,1,1);
    glTranslatef(28,16,0);
    a();
    glPopMatrix();

    glPushMatrix();
    glColor3f (1,1,1);
    glTranslatef(20,10,0);
    a();
    glPopMatrix();
}

void cloud()                                     // Three Cloud
{
    glPushMatrix();
    glTranslatef(-15.0,30.0,0.0);
    glScalef(0.7,0.7,0.0);
    c();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(20.0,25.0,0.0);
    glScalef(0.7,0.7,0.0);
    c();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(-60.0,25.0,0.0);
    glScalef(0.7,0.7,0.0);
    c();
    glPopMatrix();
}





void rect()
{
    glRectf(-16.0, -16.0, 16.0, 16.0);
}
GLfloat ss=0.0;
void day()
{
    glBegin(GL_POLYGON);                        // blue sky
    glColor3f(sr,sg,sb);
    glVertex3f(-50,-3,0.0);
    glVertex3f(-50,50,0.0);
    glVertex3f(80,50,0.0);
    glVertex3f(80,-3,0.0);
    glEnd();

    glPushMatrix();                             //sun
    glTranslatef(ss,0.0,0.0);
    glTranslatef(-20.0,40.0,0.0);
    glScalef(1.0,1.5,0.0);
    glColor3f(1.0,1.0,0.0);
    circle(6);
    glPopMatrix();
}
void ground()
{

    glColor3f(0.2,0.3,0.4);
    glPushMatrix();
    glTranslatef(-70,-42,0);
    glBegin(GL_POLYGON);
    glVertex3f (-10, 0, 0.0);
    glVertex3f (-10,10, 0.0);
    glVertex3f (600,10, 0.0);
    glVertex3f (600,0, 0.0);




    glEnd();







}

void rect123()
{

    glColor3f(0,1,1);
    glPushMatrix();
    glTranslatef(-70,-42,0);
    glBegin(GL_POLYGON);

    glVertex3f (-6, 4, 0.0);
    glVertex3f (-6,16, 0.0);
    glVertex3f (-2,6, 0.0);
    glVertex3f (-2,4, 0.0);

    glEnd();
}

void night ()                                    //black sky
{
    glBegin(GL_POLYGON);
    glColor3f(0.0,0.0,0.0);
    glVertex3f(-50,-3,0.0);
    glVertex3f(-50,50,0.0);
    glVertex3f(80,50,0.0);
    glVertex3f(80,-3,0.0);

    glEnd();



}
void moon()                                     //moon
{
    glPushMatrix();
    glTranslatef(mn,0.0,0.0);
    glTranslatef(14.0,35.0,0.0);
    glScalef(1.0,1.5,0.0);
    glColor3f(1.0,1.0,1.0);
    circle(5.0);
    glPopMatrix();

    glutPostRedisplay();
}

void triangle(void)
{
    glColor3f (0.137255,0.556863,0.137255);
    glBegin(GL_POLYGON);

    glVertex3f (0, 0, 0.0);
    glVertex3f (9, 13, 0.0);
    glVertex3f (18, 0, 0.0);

    glEnd();
}

void grass()
{

    glPushMatrix();
    glColor3f (0.8,0.196078,0.6);
    glTranslatef(38,16,0);
    glScalef(.1,.1,0);
    cloud();
    glPopMatrix();



}
void tree2()
{
    glPushMatrix();
    glTranslatef(3,8,0);
    triangle();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(3.5,14,0);
    glScalef(.9,.9,0);
    triangle();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(4.5,20,0);
    glScalef(.8,.8,0);
    triangle();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(7,26,0);
    glScalef(.5,.5,0);
    triangle();
    glPopMatrix();

    //gora

    glPushMatrix();
    glBegin(GL_POLYGON);

    glColor3f(0.36,0.25,0.20);
    glVertex3f (10, 4, 0.0);
    glVertex3f (10, 8, 0.0);
    glVertex3f (14, 8, 0.0);
    glVertex3f (14, 4, 0.0);

    glEnd();
    glPopMatrix();

}
void tree()                             //green leaves
{
    glPushMatrix();
    glTranslatef(35,10,0);
    treeleaves();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(28,16,0);
    treeleaves();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(20,10,0);
    treeleaves();
    glPopMatrix();
}
void treebody()                         //tree body
{
    glBegin(GL_POLYGON);
    glColor3f (0.502, 0.000, 0.000);
    glVertex3f(0,0,0);
    glVertex3f(2.5,2,0);
    glVertex3f(4.0,-2,0);
    glVertex3f(1,-4,0);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f (0.502, 0.000, 0.000);
    glVertex3f(7,2,0);
    glVertex3f(9,2,0);
    glVertex3f(8,-2,0);
    glVertex3f(4,-2,0);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f (0.502, 0.000, 0.000);
    glVertex3f(1,-4,0);
    glVertex3f(4,-2,0);
    glVertex3f(8,-2,0);
    glVertex3f(7,-7,0);
    glVertex3f(1.5,-7,0);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f (0.502, 0.000, 0.000);
    glVertex3f(1.5,-7,0);
    glVertex3f(7,-7,0);
    glVertex3f(6.5,-10,0);
    glVertex3f(2,-10,0);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f (0.502, 0.000, 0.000);
    glVertex3f(2,-10,0);
    glVertex3f(6.5,-10,0);
    glVertex3f(6.8,-13,0);
    glVertex3f(1.5,-13,0);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f (0.502, 0.000, 0.000);
    glVertex3f(1.5,-13,0);
    glVertex3f(6.8,-13,0);
    glVertex3f(7,-18,0);
    glVertex3f(.5,-18,0);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f (0.502, 0.000, 0.000);
    glVertex3f(.5,-18,0);
    glVertex3f(7,-18,0);
    glVertex3f(3,-27,0);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f (0.502, 0.000, 0.000);
    glVertex3f(.5,-18,0);
    glVertex3f(2.5,-23,0);
    glVertex3f(-1,-25,0);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f (0.502, 0.000, 0.000);
    glVertex3f(7,-18,0);
    glVertex3f(8,-28,0);
    glVertex3f(4,-22,0);
    glEnd();
}
//////////////////////
///***HOME Start***////
//////////////////////
void home1()
{
    //1st Home
    //1
    glColor3ub(102,0,0);
    glBegin(GL_POLYGON);
    glVertex2d(3,14);
    glVertex2d(3,11);
    glVertex2d(10,8);
    glVertex2d(10,12);
    glVertex2d(6,18);
    glEnd();
    //2
    glColor3ub(153,153,0);
    glBegin(GL_POLYGON);
    glVertex2d(10,8);
    glVertex2d(10,12);
    glVertex2d(20,12);
    glVertex2d(20,8);
    glEnd();
    //3
    glColor3ub(0,100,200);
    glBegin(GL_POLYGON);
    glVertex2d(10,12);
    glVertex2d(6,18);
    glVertex2d(17,18);
    glVertex2d(21,12);
    glEnd();
    //4
    glColor3ub(255,255,0);
    glBegin(GL_POLYGON);
    glVertex2d(5,11);
    glVertex2d(5,12);
    glVertex2d(8,11);
    glVertex2d(8,10);
    glEnd();
    //5

    glColor3ub(50,50,50);
    glBegin(GL_POLYGON);
    glVertex2d(14,8);
    glVertex2d(14,10);
    glVertex2d(17,10);
    glVertex2d(17,8);
    glEnd();
    //6

    glColor3ub(255,255,0);
    glBegin(GL_POLYGON);
    glVertex2d(5,14.7);
    glVertex2d(5,15.8);
    glVertex2d(7,15.3);
    glVertex2d(7,14.2);
    glEnd();



}
void house()
{
    glColor3ub(240,150,100);
    glBegin(GL_POLYGON);
    glVertex2d(33,23);
    glVertex2d(44,23);
    glVertex2d(44,30);
    glVertex2d(33,30);
    glEnd();

    glColor3ub(0,105,105);
    glBegin(GL_POLYGON);
    glVertex2d(31,30);
    glVertex2d(46,30);
    glVertex2d(38.5,38);
    glEnd();

}
///HOME END///

///street light///
void street()
{
    glColor3ub(50,50,50);
    glBegin(GL_POLYGON);
    glVertex2d(14,8);
    glVertex2d(14,10);
    glVertex2d(17,10);
    glVertex2d(17,8);
    glEnd();
}

void street1()
{
   glColor3ub(0,0,0);
    glBegin(GL_POLYGON);
    glVertex2d(8,10.3);
    glVertex2d(8,10.2);
    glVertex2d(23,10);
    glVertex2d(23,10.1);
    glEnd();
}
void streetwire()
{
    glColor3f(0, 0, 0);
    glBegin(GL_LINES);
    glVertex3f(-1.7, 3.56, 0);
    glVertex3f(20.72, 3.56, 0);
    glLineWidth(3);
    glEnd();
}

///street light ends///
void chimni()
{
     glColor3ub(1,0,0);
    glBegin(GL_POLYGON);
    glVertex2d(14,8);
    glVertex2d(14,8.6);
    glVertex2d(17,8.6);
    glVertex2d(17,8);
    glEnd();
}

void habab(float mcloud)
{

    glPushMatrix();
    glColor3f (1,1,1);
    glTranslatef(mcloud,17.0,0.0);
    cloudB();
    glPopMatrix();

    glPushMatrix();
    glColor3f (1,1,1);
    glTranslatef(mcloud,20.0,0.0);
    cloudB();
    glPopMatrix();
}
void drawcloud()
{

    mcloud=mcloud+.01;
    if(mcloud>70)
        mcloud=-70;

    sx=sx+0.7;
    if(sx>5000)
        sx=-5000;


}




void drawWindmill() {
	int i;
	glColor3f(0.8f, 0.8f, 0.9f);
	glBegin(GL_POLYGON);
	glVertex2d(14,-13);
    glVertex2d(14,60);
    glVertex2d(18,60);
    glVertex2d(18,-13);
	glEnd();
	//glTranslatef(0, 3, 0);
	glTranslatef(15.5,60.0,0.0);
	glScalef(0.6,0.6,0.0);
	glRotated(frameNumber * (180.0/46), 0, 0, -1);
	glColor3f(0.4f, 0.4f, 0.8f);
	for (i = 0; i < 3; i++) {


		glRotated(120, 0, 0, 1);  // Note: These rotations accumulate.

		glBegin(GL_POLYGON);

		glVertex2f(0,0);
		glVertex2f(0.5f, 0.1f);
		glVertex2f(1.5f,0);
		glVertex2f(0.5f, -0.1f);
        glVertex2d(14,-14);
        glVertex2d(14,60);
        glVertex2d(18,60);
        glVertex2d(18,-14);
		glEnd();
	}
}

void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);

    glPushMatrix();
    day();
    glPopMatrix();
    

    ///ground///
    glPushMatrix();
    glTranslatef(0.0,-35.0,0.0);
    glScalef(3.5,3.0,0.0);
    glColor3f(0.0, 0.5, 0.0);
    rect();

    glPopMatrix();
    
    

    drawcloud();



/// stars start ///

    glColor3f(1.0, 1.0, 1.0);///sss
    glPushMatrix();
    glTranslatef(-0.5,34.0,0.0);
    glRotatef(360,0,0,1);
    glutWireTorus(0.3,0.1,star,star);
    glPopMatrix();

    glColor3f(1.0, 1.0, 1.0);///sss
    glPushMatrix();
    glTranslatef(-10.0,39.0,0.0);
    glRotatef(360,0,0,1);
    glutWireTorus(0.3,0.1,star,star);
    glPopMatrix();

    glColor3f(1.0, 1.0, 1.0);///sss
    glPushMatrix();
    glTranslatef(-25.0,48.0,0.0);
    glRotatef(360,0,0,1);
    glutWireTorus(0.3,0.1,star,star);
    glPopMatrix();

    glColor3f(1.0, 1.0, 1.0);///sss
    glPushMatrix();
    glTranslatef(-20.0,40.0,0.0);
    glRotatef(360,0,0,1);
    glutWireTorus(0.2,0.1,star,star);
    glPopMatrix();

    glColor3f(1.0, 1.0, 1.0);///sss
    glPushMatrix();
    glTranslatef(-30.0,32.0,0.0);
    glRotatef(360,0,0,1);
    glutWireTorus(0.2,0.1,star,star);
    glPopMatrix();


     glColor3f(1.0, 1.0, 1.0);///sss
    glPushMatrix();
    glTranslatef(-33.0,30.0,0.0);
    glRotatef(360,0,0,1);
    glutWireTorus(0.1,0.1,star,star);
    glPopMatrix();

    glColor3f(1.0, 1.0, 1.0);///sss
    glPushMatrix();
    glTranslatef(-40.0,40.0,0.0);
    glRotatef(360,0,0,1);
    glutWireTorus(0.1,0.1,star,star);
    glPopMatrix();

    glColor3f(1.0, 1.0, 1.0);///sss
    glPushMatrix();
    glTranslatef(-43.0,47.0,0.0);
    glRotatef(360,0,0,1);
    glutWireTorus(0.1,0.1,star,star);
    glPopMatrix();

    glColor3f(1.0, 1.0, 1.0);///sss
    glPushMatrix();
    glTranslatef(-48.0,38.0,0.0);
    glRotatef(360,0,0,1);
    glutWireTorus(0.1,0.1,star,star);
    glPopMatrix();

    glColor3f(1.0, 1.0, 1.0);///sss
    glPushMatrix();
    glTranslatef(-22.0,40.0,0.0);
    glRotatef(360,0,0,1);
    glutWireTorus(0.1,0.1,star,star);
    glPopMatrix();

    glColor3f(1.0, 1.0, 1.0);///sss
    glPushMatrix();
    glTranslatef(-12.0,45.0,0.0);
    glRotatef(360,0,0,1);
    glutWireTorus(0.1,0.1,star,star);
    glPopMatrix();

    glColor3f(1.0, 1.0, 1.0);///sss
    glPushMatrix();
    glTranslatef(-10.0,30.0,0.0);
    glRotatef(360,0,0,1);
    glutWireTorus(0.1,0.1,star,star);
    glPopMatrix();

    glColor3f(1.0, 1.0, 1.0);///sss
    glPushMatrix();
    glTranslatef(-19.0,28.0,0.0);
    glRotatef(360,0,0,1);
    glutWireTorus(0.1,0.1,star,star);
    glPopMatrix();

    glColor3f(1.0, 1.0, 1.0);///sss
    glPushMatrix();
    glTranslatef(5.0,40.0,0.0);
    glRotatef(360,0,0,1);
    glutWireTorus(0.1,0.1,star,star);
    glPopMatrix();

    glColor3f(1.0, 1.0, 1.0);///sss
    glPushMatrix();
    glTranslatef(15.0,45.0,0.0);
    glRotatef(360,0,0,1);
    glutWireTorus(0.2,0.1,star,star);
    glPopMatrix();

    glColor3f(1.0, 1.0, 1.0);///sss
    glPushMatrix();
    glTranslatef(25.0,40.0,0.0);
    glRotatef(360,0,0,1);
    glutWireTorus(0.1,0.1,star,star);
    glPopMatrix();

    glColor3f(1.0, 1.0, 1.0);///sss
    glPushMatrix();
    glTranslatef(30.0,35.0,0.0);
    glRotatef(360,0,0,1);
    glutWireTorus(0.1,0.1,star,star);
    glPopMatrix();

    glColor3f(1.0, 1.0, 1.0);///sss
    glPushMatrix();
    glTranslatef(35.0,33.0,0.0);
    glRotatef(360,0,0,1);
    glutWireTorus(0.2,0.1,star,star);
    glPopMatrix();

    glColor3f(1.0, 1.0, 1.0);///sss
    glPushMatrix();
    glTranslatef(48.0,40.0,0.0);
    glRotatef(360,0,0,1);
    glutWireTorus(0.1,0.1,star,star);
    glPopMatrix();

    glColor3f(1.0, 1.0, 1.0);///sss
    glPushMatrix();
    glTranslatef(40.0,32.0,0.0);
    glRotatef(360,0,0,1);
    glutWireTorus(0.1,0.1,star,star);
    glPopMatrix();

    glColor3f(1.0, 1.0, 1.0);///sss
    glPushMatrix();
    glTranslatef(37.0,39.0,0.0);
    glRotatef(360,0,0,1);
    glutWireTorus(0.2,0.1,star,star);
    glPopMatrix();

///star ends///
///windmill //

    glPushMatrix();
    glColor3f(0.0, 0.0, 0.0);
    glTranslatef(-46.0,2.5,0.0);
    glScalef(0.4,0.5,0.0);
    drawWindmill();
    glPopMatrix();

    glColor3f(160.0, 82.0, 45.0);///sss
    glPushMatrix();
    glTranslatef(-39.5,32.0,0.0);
    glRotatef(360,0,0,1);
    circle(1.05);
    glPopMatrix();
///windmill ends//

///
    glPushMatrix();
    moon();
    glPopMatrix();

///
    glPushMatrix();
    glTranslatef(mcloud,0.0,0.0);
    glScalef(.8,1,0);
    cloud();
    glPopMatrix();
    ///***///



///home 2///
    glPushMatrix();
    glTranslatef(-72.0,-30.0,0.0);
    house();
    glPopMatrix();
///***///
///home 1///
    glPushMatrix();
    glTranslatef(-28.0,-30.0,1.0);
    glScalef(1.0,2.6,2.0);
    home1();
    glPopMatrix();
///home 2///
    glPushMatrix();
    glTranslatef(4.0,-55.0,0.0);
    glScalef(1.5,5.0,3.0);
    home1();
    glPopMatrix();
///***///
   ///tree big///
    glPushMatrix();
    glColor3f(0.133, 0.545, 0.133);
    glTranslatef(-10.0,-10.5,0.0);
    glScalef(0.4,1.5,0.0);
    tree();
    glPopMatrix();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(-1.0,7.5,0.0);
    glScalef(0.4,0.7,0.0);
    treebody();
    glPopMatrix();
    ///***///
///tree typeB 1///
    glPushMatrix();
    glTranslatef(35.0,-5.0,0.0);
    glScalef(.5,1,0);
    tree2();
    glPopMatrix();
    ///***///
///tree typeC 1///
    glPushMatrix();
    glTranslatef(30.0,-15.0,0.0);
    glScalef(.5,1,0);
    tree2();
    glPopMatrix();
///***///

//flag
    GLint nCtrlPts=4,nBezCurvePts=20;
	static float theta=0;
	struct wcPt3D ctrlPts[4]={{3,-28,0},{8,-27.099,0},{10,-28.001,0},{13,-28,0}};
	ctrlPts[1].x +=(10*sin(theta * PI/180.0))/10;
	ctrlPts[1].y +=(5*sin(theta * PI/180.0))/10;
	ctrlPts[2].x -=(10*sin((theta+30) * PI/180.0))/10;
	ctrlPts[2].y -=(10*sin((theta+30) * PI/180.0))/10;
	ctrlPts[3].x -=(4*sin((theta)*PI/180.0))/10;
	ctrlPts[3].y += (sin((theta-30)*PI/180.0))/10;
	theta+=3;
	glPointSize(5);
	glPushMatrix();
	glLineWidth(7);
	glColor3f(1.0,0.5,0);
	for(int i=0;i<4;i++)
	{
		glTranslatef(0,-0.8,0);
		bezier(ctrlPts, nCtrlPts, nBezCurvePts);
	}
	glColor3f(1,1,1);
	for(int i=0;i<4;i++)
	{
		glTranslatef(0,-0.8,0);
		bezier(ctrlPts, nCtrlPts, nBezCurvePts);
	}
	glColor3f(0,1.0,0);
	for(int i=0;i<4;i++)
	{
		glTranslatef(0,-0.8,0);
		bezier(ctrlPts, nCtrlPts, nBezCurvePts);
	}
		glPopMatrix();
		glColor3f(0.7,0.6,0.3);
		glLineWidth(5);
		glBegin(GL_LINES);
		glVertex2f(3,-27.5);
		glVertex2f(3,-45);
		glEnd();
		
	//flag2
	struct wcPt3D ctrlPts1[4]={{15,-28,0},{20,-27.099,0},{22,-28.001,0},{25,-28,0}};
	ctrlPts1[1].x +=(10*sin(theta * PI/180.0))/10;
	ctrlPts1[1].y +=(5*sin(theta * PI/180.0))/10;
	ctrlPts1[2].x -=(10*sin((theta+30) * PI/180.0))/10;
	ctrlPts1[2].y -=(10*sin((theta+30) * PI/180.0))/10;
	ctrlPts1[3].x -=(4*sin((theta)*PI/180.0))/10;
	ctrlPts1[3].y += (sin((theta-30)*PI/180.0))/10;
	theta+=3;
	glPointSize(5);
	glPushMatrix();
	glLineWidth(7);
	glColor3f(1.0,0.5,0);
	for(int i=0;i<4;i++)
	{
		glTranslatef(0,-0.8,0);
		bezier(ctrlPts1, nCtrlPts, nBezCurvePts);
	}
	glColor3f(1,1,1);
	for(int i=0;i<4;i++)
	{
		glTranslatef(0,-0.8,0);
		bezier(ctrlPts1, nCtrlPts, nBezCurvePts);
	}
	glColor3f(0,1.0,0);
	for(int i=0;i<4;i++)
	{
		glTranslatef(0,-0.8,0);
		bezier(ctrlPts1, nCtrlPts, nBezCurvePts);
	}
		glPopMatrix();
		glColor3f(0.7,0.6,0.3);
		glLineWidth(5);
		glBegin(GL_LINES);
		glVertex2f(15,-27.5);
		glVertex2f(15,-45);
		glEnd();




///tree2///
    glPushMatrix();
    glColor3f(0.133, 0.545, 0.133);
    glTranslatef(-54.0,-1,0.0);
    glScalef(0.4,0.5,0.0);
    tree();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(-45.0,5.0,0.0);
    glScalef(0.4,0.5,0.0);
    treebody();
    glPopMatrix();

    ///street light///

     glPushMatrix();
    glTranslatef(-14, -12, 0);
    glScalef(30, 8, 0);
    streetwire();
    glPopMatrix();

     glPushMatrix();
    glTranslatef(-14, -13, 0);
    glScalef(30, 8, 0);
    streetwire();
    glPopMatrix();

     glPushMatrix();
    glTranslatef(-14, -14, 0);
    glScalef(30, 8, 0);
    streetwire();
    glPopMatrix();

    /// ///
     glPushMatrix();
    glTranslatef(-32.0,-135.0,1.0);
    glScalef(0.5,14.8,0.0);
    street1();
    glPopMatrix();


    glPushMatrix();
    glTranslatef(0.0,-135.0,1.0);
    glScalef(0.5,14.8,0.0);
    street1();
    glPopMatrix();


    glPushMatrix();
    glTranslatef(38.0,-135.0,1.0);
    glScalef(0.5,14.8,0.0);
    street1();
    glPopMatrix();

    ///  ///

    glPushMatrix();
    glTranslatef(-32.0,-130.0,1.0);
    glScalef(0.5,14.8,0.0);
    street();
    glPopMatrix();


    glPushMatrix();
    glTranslatef(0.0,-130.0,1.0);
    glScalef(0.5,14.8,0.0);
    street();
    glPopMatrix();


    glPushMatrix();
    glTranslatef(38.0,-130.0,1.0);
    glScalef(0.5,14.8,0.0);
    street();
    glPopMatrix();

    /// street light ends///

    ///chimni///
    glPushMatrix();
    glTranslatef(-20.0,-125.0,1.0);
    glScalef(0.5,16.8,0.0);
    chimni();
    glPopMatrix();


    glPushMatrix();
    glTranslatef(20,-90.0,1.0);
    glScalef(0.5,14.8,0.0);
    chimni();
    glPopMatrix();
    /// chimni ends///


///********road********///
    glPushMatrix();
    glTranslatef(-10.0,15.0,0.0);
    ground();


    glPopMatrix();
    glPopMatrix();


    glPushMatrix();
    glTranslatef(-10.0,20.0,0.0);
    ground();

    glPopMatrix();
    glPopMatrix();
    
    


///************///
///BUS///
    glPushMatrix();
    glTranslatef(cx, -28, 0);
    glScalef(30, 18, 0);
    //glRotatef(cx,0.0,0.0,1.0);
    bus();
    glPopMatrix();
///***///

///BUS2///
    glPushMatrix();
    glTranslatef(-14, -12, 0);
    glScalef(30, 8, 0);
    buss();
    glPopMatrix();
    ///***///

    ///tree3///
    glPushMatrix();
    glColor3f(0.133, 0.545, 0.133);
    glTranslatef(22.0,-32.5,0.0);
    glScalef(0.4,0.5,0.0);
    tree();
    glPopMatrix();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(30.5,-26.5,0.0);
    glScalef(0.4,0.5,0.0);
    treebody();
    glPopMatrix();
    ///***///

    ///home 3///
    glPushMatrix();
    glTranslatef(-5.0,-70.0,0.0);
    house();
    glPopMatrix();
    glPopMatrix();
    ///***///

    ///***///

///********home 4********///
    glPushMatrix();
    glTranslatef(-50.0,-60.0,0.0);
    glScalef(1.5,2.0,3.0);
    home1();
    glPopMatrix();
    glPopMatrix();
///***///

 ///tree big///
    glPushMatrix();
    glColor3f(0.133, 0.545, 0.133);
    glTranslatef(-53.0,-53.5,0.0);
    glScalef(0.4,1.5,0.0);
    tree();
    glPopMatrix();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(-44.5,-33.5,0.0);
    glScalef(0.4,0.7,0.0);
    treebody();
    glPopMatrix();
    ///***///



    ///tree big///
    glPushMatrix();
    glColor3f(0.133, 0.545, 0.133);
    glTranslatef(35.0,-45.5,0.0);
    glScalef(0.4,2.0,0.0);
    tree();
    glPopMatrix();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(43.5,-20.5,0.0);
    glScalef(0.4,1.0,0.0);
    treebody();
    glPopMatrix();
    ///***///

    ///tree typeD 1///
    glPushMatrix();
    glTranslatef(-10.0,-50.0,0.0);
    glScalef(0.5,1,0);
    tree2();
    glPopMatrix();
    ///***///
    glFlush();
}
void init(void)
{
    glClearColor (0, 0.749, 1, 0);
    glOrtho(-50.0,50.0, -50.0, 50.0, -1.0, 1.0);
}

void spinDisplays()
{
    cx = cx + xc;
    if(cx>70)
        cx = -70;


    mc=mc + cm;
    if(mc>360)
        mc = -360;

    glutPostRedisplay();
}
void speeda()
{
    xc=0.01;
    cm=0.2;
    spinDisplays();
    glutPostRedisplay();

}
void speedb()
{
    xc=0.05;
    cm=0.4;
    spinDisplays();
    glutPostRedisplay();

}
void speedc()
{
    xc=0.09;
    cm=0.6;
    spinDisplays();
    glutPostRedisplay();

}
void speedd()
{
    xc=0.2;
    cm=0.10;
    spinDisplays();
    glutPostRedisplay();

}




void mouse(int key, int state, int x, int y)
{

    switch (key)
    {
    case GLUT_LEFT_BUTTON:
        if (state == GLUT_DOWN)
        {
            glutIdleFunc(spinDisplays);
           // glutIdleFunc(drawcloud);
        }
        break;
    case GLUT_MIDDLE_BUTTON:
       // glutIdleFunc(drawcloud);
    case GLUT_RIGHT_BUTTON:
        if (state == GLUT_DOWN)
        {
            glutIdleFunc(NULL);
        }
        break;
    default:
        //glutIdleFunc(drawcloud);

        break;
    }
}

void keyDisplayAnimationDay()
{
///background color///
    str=500.0;
    sr=0.0;
    sg=0.749;
    sb=1.0;

    ss = 0.0;

    mn = 500.0;
///cloud///
    radius = 4;
    radiusa = 3.5;
    radiusb = 3.5;
    radiusc = 3;
    radiusd = 4;
///stars///
    star = 0;
///carlight///
    cara = 0;
    carb = 0;
    carc = 0;
    card = 0;
    care = 0;
    carf = 0;
    glutPostRedisplay();


}
void keyDisplayAnimationNight()
{

///background color///
    str = 0.0;
    sr=0.0;
    sg=0.0;
    sb=0.0;

    ss = 500.0;

    mn = 0.0;

    ///cloud///
    radius = 0;
    radiusa = 0;
    radiusb = 0;
    radiusc = 0;
    radiusd = 0;

    ///stars///
    star = 4;

    ///carlight///
    cara = -0.22;
    carb = 0.45;
    carc = -0.20;
    card = 0.15;
    care = -0.41;
    carf = 0.32;

    glutPostRedisplay();





}
void keyboard(unsigned char key, int x, int y)
{
    switch(key)
    {
    case 'd':
        keyDisplayAnimationDay();
        break;

    case 'n':
        //night();

        keyDisplayAnimationNight();

        break;
    case 'q':
        speeda();
        break;
    case 'w':
        speedb();
        break;
    case 'e':
        speedc();
        break;
    case 'r':
        speedd();
        break;

    default:
        break;
    }
}
void doFrame(int v) {
    frameNumber++;
    glutPostRedisplay();
    glutTimerFunc(30,doFrame,0);
}

int main(int argc, char** argv)
{
    printf(">><< K S INSTITUTE OF TECHNOLOGY>><< CSE >><<\n\n");
    printf(">><< NAME : KIRAN V DAMBAL>><< USN : 1KS18CS033 >><<\n\n");
    printf("INSTRUCTIONS:\n\n");
    printf(">><< Press N for nightmood>><< Press D for day mood >><<\n\n");
    printf("Click Mouse Left to start car and mouse Right to stop car\n");
    printf("Press q for low speed traffic\n");
    printf("Press w for average speed traffic\n");
    printf("Press e for high speed traffic\n");
    printf("Press r for super speed traffic\n");
    glutInit(&argc, argv);
    glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize (1350, 690);
    glutInitWindowPosition (0, 0);
    glutCreateWindow ("Dispaly of Town");
    init();
    glutDisplayFunc(display);
    glutTimerFunc(200,doFrame,0);
    glutMouseFunc(mouse);
    glutKeyboardFunc(keyboard);
    glutMainLoop();
    return 0;
}
