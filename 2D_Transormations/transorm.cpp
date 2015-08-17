@@ -0,0 +1,108 @@
#include <iostream>
#include<stdio.h>
#include<GLUT/glut.h>  
#include<math.h> 
int xc,yc,Rx,tx,ty,rPointX=0,rPointY=0,choice;
double theta=0.0;

void init(void)  
{  
glClearColor(1.0,1.0,1.0,1.0); 
glColor3f(0.0f,0.0f,0.0f);
glPointSize(2); 
glMatrixMode(GL_PROJECTION); 
glLoadIdentity();
gluOrtho2D(-320.0,320,-240,240); 

} 

void putpixel(int x,int y)  
{        glBegin(GL_POINTS);	
glVertex2i(rPointX+(x-rPointX)*cos(theta)-(y-rPointY)*sin(theta)+tx,rPointY+(x-rPointX)*sin(theta)+(y-rPointY)*cos(theta)+ty);  
glEnd();  
glFlush();  
}  

void circle(int rx, int ry, int r, float f)
{
int x,y;
for(x=rx-r; x<=rx+r; x++)
for(y=ry-r; y<=ry+r; y++)
if ( (((x*x)+(y*y))>(r*r)-(f/2)) && (((x*x)+(y*y))<(r*r)+(f/2)) ) 
putpixel(x,y);
}

void hSpoke(int rx, int ry, int r)
{
int x,y=ry;
for(x=rx-r; x<=rx+r; x++)
putpixel(x,y);
}

void vSpoke(int rx, int ry, int r)
{
int x=rx,y;
for(y=ry-r; y<=ry+r; y++)
putpixel(x,y);
}

void drawCircle()
{glClear(GL_COLOR_BUFFER_BIT);
glBegin(GL_POINTS); 
circle(xc,yc,Rx,250);// 250 is a parameter whihc defines thickness and completeness of line
hSpoke(xc,yc,Rx);
vSpoke(xc,yc,Rx);
	
switch(choice)
	{
		case 1:
			//Translation takes plave here :P
			tx=100;
			ty=100;

			circle(xc,yc,Rx,250);// 250 is a parameter whihc defines thickness and completeness of line
			hSpoke(xc,yc,Rx);
			vSpoke(xc,yc,Rx);

			tx-=100;// Once translation is over, returning to original values
			ty-=100;
			break;
			
		case 2:
			Rx *= 2; // scaling takes place here :)
			circle(xc,yc,Rx,250);// 250 is a parameter whihc defines thickness and completeness of line
			hSpoke(xc,yc,Rx);
			vSpoke(xc,yc,Rx);
			Rx/=2;
			break;
			
		case 3:

			rPointX=5; // Rotation takes place here :)
			rPointY=5;
			theta = 45;
			circle(xc,yc,Rx,250);// 250 is a parameter whihc defines thickness and completeness of line
			hSpoke(xc,yc,Rx);
			vSpoke(xc,yc,Rx);
			break;
	}
	
}

int main(int argc,char** argv)  
{  
glutInit(&argc,argv);  
printf("\n Enter the radius: ");
scanf("%d",&Rx);
printf("\n Center (x,y): ");
scanf("%d %d",&xc, &yc);
	printf("Enter the choice that you want \n1.Translation\n2.Scaling \n3.Rotation\n ");
	scanf("%d",&choice);
glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);  
glutInitWindowSize(640,480);  
glutCreateWindow("CIRCLE"); 
glutDisplayFunc(drawCircle);  
init();  
glutMainLoop();  
return 0;  
}
