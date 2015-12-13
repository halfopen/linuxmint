/*************************************************************************
	> File Name: Star.c
	> Author: halfopen
	> Mail: halfopen@yeah.net
	> Created Time: 2015年11月11日 星期四 17时12分46秒
 ************************************************************************/

#include<stdio.h>
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include<math.h>

#define PI 3.14159262423

static double	y=sin(PI/5)*tan(PI/5)-cos(PI/5); 
static GLint axis = 2;
static GLfloat theta[] = {0.0,0.0,0.0};
static double colors[][3] = {0.0, 255.0, 0.0,  
			255.0, 0.0, 0.0,  
			0.0,0.0, 255,  
			0,255.0, 255.0,  
			125.0,   125.0, 120.0
};

static double stars[10][2]={0,y,  
			-sin(PI/5),-cos(PI/5),
			cos(PI/10)*y,sin(PI/10)*y,
			-cos(PI/10),sin(PI/10),
			sin(PI/5)*y,-cos(PI/5)*y,
			0,1,
			-sin(PI/5)*y,-cos(PI/5)*y,
			cos(PI/10),sin(PI/10),
			-cos(PI/10)*y,sin(PI/10)*y,
			sin(PI/5),-cos(PI/5)
};

int width=400, height=400;

void drawStar()
{
		glClear(GL_COLOR_BUFFER_BIT); 
		glBegin(GL_POLYGON); 
		double px,py;
		glColor3f(255,255,255);
		glVertex2f(0.0 , 0.0 );
		for(int i=0;i<10;++i)
		{			
			px = stars[i][0];
			py = stars[i][1];
			int j = i/2;
			if(i==0)glColor3f(255,255,0);
			else if(i%2)glColor3f(colors[j][0],colors[j][1],colors[j][2]);
			
			glVertex2f(px , py );
			//getchar();		
		}
		glColor3f(255,255,0);
		glVertex2f(0.0,y);
		//glVertex2f(0,0);
		glEnd();
		glFlush();
}

static void display(void)
{
 		
 		drawStar();
		glRotatef(theta[0]/10, 1.0, 0.0, 0.0);
		glRotatef(theta[1]/10, 0.0, 1.0, 0.0);
		glRotatef(theta[2]/10, 0.0, 0.0, 1.0);		
}


/* This routine inputs new control points */
static void mouse(int button, int state, int x, int y)
{
        glFlush();

}

void init(void) 
{
		glClearColor(0.0,0.0,0.0,0.0);     
	
}

/* This routine handles keystroke commands */
void keyboard(unsigned char key, int x, int y)
{	
        switch (key)
    		{
				case 'j':
					axis = 0;
					theta[axis] += 2.0;
					if( theta[axis] > 360.0 ) theta[axis] -= 360.0;
					glutPostRedisplay();break;
				case 'k':
					axis = 1;
					theta[axis] += 2.0;
					if( theta[axis] > 360.0 ) theta[axis] -= 360.0;
					glutPostRedisplay();break;
				case 'l':
					axis = 2;
					theta[axis] += 2.0;
					if( theta[axis] > 360.0 ) theta[axis] -= 360.0;
					glutPostRedisplay();break;
                case 'q': case 'Q':
                    exit(0);
                    break;
                case 'c': case 'C':
                    break;
                case 'e': case 'E':
                    break;
                case 'b': case 'B':
                    break;
                case 'i': case 'I':
                    break;
                case 's': case 'S':
                    break;
            
    }

}

void spinCube()
{
		theta[axis] += 2.0;
		if( theta[axis] > 360.0 ) theta[axis] -= 360.0;
		glutPostRedisplay();
}

void reshape(int w, int h)
{
        width = w;
        height = h;

        /* Set the transformations */
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);
        glMatrixMode(GL_MODELVIEW);
        glViewport(0, 0, w, h);

}
main(int argc, char **argv)
{
        /* Intialize the program */
        glutInit(&argc, argv);
        glutInitDisplayMode(GLUT_RGB);
        glutInitWindowSize(width, height);
        glutCreateWindow("star");

        /* Register the callbacks */
        glutDisplayFunc(display);

        glutMouseFunc(mouse);
        glutKeyboardFunc(keyboard);
        glutReshapeFunc(reshape);
        glClearColor(1.0, 1.0, 1.0, 1.0);
        glEnable(GL_MAP1_VERTEX_3);

		init();
		glutMainLoop();
}
