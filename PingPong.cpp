#include <iostream>
#include <GL/gl.h>
#include <GL/glut.h>
#include<math.h>
#include<stdlib.h>
#include <stdio.h>
#include <unistd.h> 
int interval = 1000/60;
int width =900;
int height=600;
int racket_width = 10;
int racket_height = 80;
int racket_speed = 10;
float racket_left_x = 10.0f;
float racket_left_y = height/2;
float racket_right_x = width - racket_width - 10;
float racket_right_y = height/2;
float ball_pos_x = width / 2;
float ball_pos_y = height / 2;
float ball_dir_x = -1.0f;
float ball_dir_y = 0.0f;
int ball_size = 8;
float ball_speed = 2;
int mainmenu=0;
int cpu=0;
int score_left =0;
int score_right =0;
int r=0,l=0;
float R=2,g=2,b=0,z=1;
int c=0;
int t=0;
int q=0;
using namespace std;
void Rect(float x, float y, float width, float height) 
{
  	glBegin(GL_QUADS);
        glColor3f(2,0,0);
	glVertex2f(x, y);
        glVertex2f(x + width, y);
        glVertex2f(x + width, y + height);
        glVertex2f(x, y + height);
	glColor3f(1,1,1);
	glEnd();
}
void rect1()
{
	glBegin(GL_LINES);
	glColor3f(0,1,0);
	glVertex2f(11,20);
	glVertex2f(11,height-20);
	glVertex2f(11,height-20);
	glVertex2f(racket_right_x+10,height-20);
	glVertex2f(racket_right_x+10,height-20);
	glVertex2f(racket_right_x+10,20);
	if(cpu ==1 || cpu ==2)
	{	
		glVertex2f(width/2,height-20);
		glVertex2f(width/2,20);
	}
	glVertex2f(11,20);
	glVertex2f(racket_right_x+10,20);
	if( r == 0 && cpu == 0 )
	{
		
		glColor3f(R,g,b);	
	}
	else
	glColor3f(1,1,1);
	glEnd();

}	
void Draw()
{
	if ( r == 1)
	{
		char ch1[24] ="CPU WINS";
		char ch4[24] ="PLAYER2 WINS";
		if ( cpu == 1)
		{
			glRasterPos2f(width/2-40,height/2-12);	
			for (int i=0;ch1[i]!='\0';i++)
			glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,ch1[i]);
		}
		else if (cpu == 2)
		{
			glRasterPos2f(width/2-40,height/2-12);	
			for (int i=0;ch4[i]!='\0';i++)
			glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,ch4[i]);
		}
		mainmenu=0;
		r=0;
		score_right=0;
		score_left=0;
		c=0;
		t=0;
		q=1;
		ball_speed = 2;
		cpu=0;
		racket_left_x = 10.0f;
		racket_left_y = height/2;
		racket_right_x = width - racket_width - 10;
		ball_pos_x = width / 2;
		ball_pos_y = height / 2;
		racket_right_y = height/2;
		ball_dir_x = -1.0f;
		ball_dir_y = 0.0f;
	}
	else if ( r == 2)
	{
		char ch2[19] ="PLAYER WINS";
		char ch3[19] ="PLAYER1 WINS";
		if ( cpu == 1)
		{
			glRasterPos2f(width/2-40,height/2-12);	
			for (int i=0;ch2[i]!='\0';i++)
			glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,ch2[i]);
		}
		else if (cpu == 2)
		{
			glRasterPos2f(width/2-40,height/2-12);	
			for (int i=0;ch3[i]!='\0';i++)
			glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,ch3[i]);
		}	
		mainmenu=0;
		r=0;
		score_right=0;
		score_left=0;
		c=0;
		t=0;
		ball_speed = 2;
		q=1;	
		cpu=0;	
		racket_left_x = 10.0f;
		racket_left_y = height/2;
		racket_right_x = width - racket_width - 10;
		ball_pos_x = width / 2;
		ball_pos_y = height / 2;
		racket_right_y = height/2;
		ball_dir_x = -1.0f;
		ball_dir_y = 0.0f;	
	}
	else if (r == 0)
	{
		
		char ch3[20]="PLAYER1";
		char ch4[20]="PLAYER2";
		glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
		glLoadIdentity();
		Rect(racket_left_x,racket_left_y,racket_width,racket_height);
		
		Rect(racket_right_x,racket_right_y,racket_width,racket_height);
				
		Rect(ball_pos_x, ball_pos_y, ball_size, ball_size);	
		glRasterPos2f(width/2-15,height-15);
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_10,(char)(score_left+48));		
		glRasterPos2f(width/2-2,height-15);		
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_10,(char)(58));
		glRasterPos2f(width/2+10,height-15);
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_10,(char)(score_right+48));
		if ( cpu == 1)
		{
			char ch1[20]="CPU";
			char ch2[20]="PLAYER";
			glRasterPos2f(11,height-15);	
			for (int i=0;ch2[i]!='\0';i++)
			glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_10,ch2[i]);
			glRasterPos2f(racket_right_x-10,height-15);	
			for (int i=0;ch1[i]!='\0';i++)
			glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_10,ch1[i]);
		}
		else if ( cpu == 2)
		{
			char ch1[20]="PLAYER1";
			char ch2[20]="PLAYER2";
			glRasterPos2f(11,height-15);	
			for (int i=0;ch1[i]!='\0';i++)
			glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_10,ch1[i]);
			glRasterPos2f(racket_right_x-35,height-15);	
			for (int i=0;ch2[i]!='\0';i++)
			glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_10,ch2[i]);
		}
		rect1();
		if ( mainmenu == 0)
		{
			if(q == 1)
			{			
				sleep(1);
				q=0;
			}
			char ch[15]="1.Start Game";
			char ch1[15]="2.Credits";
			char ch2[15]="3.Exit";
			glRasterPos2f(width/2-40,height/2);
			for (int i=0;ch[i]!='\0';i++)
			{
				glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,ch[i]);
			}
			glRasterPos2f(width/2-40,(height/2)-30);
			for (int i=0;ch1[i]!='\0';i++)
			{
				glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,ch1[i]);
			}
			glRasterPos2f(width/2-40, (height/2)-60);
			for (int i=0;ch2[i]!='\0';i++)
			{
				glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,ch2[i]);
			}
			char ch3[40]="WELCOME TO WORLD OF PING-PONG";
			glRasterPos2f(width/2-180,height/2+100);
			for (int i=0;ch3[i]!='\0';i++)
			{					
				glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,ch3[i]);
			}
				
		}			
		else if(mainmenu == 1)
		{
			char ch[20]="1.Vs Computer";
			char ch1[20]="2.Vs Player";
			char ch2[20]="3.Go Back";
			glRasterPos2f(width/2-40,height/2);
			for (int i=0;ch[i]!='\0';i++)
			{
				glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,ch[i]);
			}
			glRasterPos2f(width/2-40,height/2-30);
			for (int i=0;ch1[i]!='\0';i++)
			{
				glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,ch1[i]);
			}
			glRasterPos2f(width/2-40,height/2-60);
			for (int i=0;ch2[i]!='\0';i++)
			{
				glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,ch2[i]);
			}
			t=1;
		}
		else if( mainmenu == 2)
		{
			cpu=1;
			if ( z== 1)
			{
				racket_left_x = 10.0f;
				racket_left_y = height/2;
				racket_right_x = width - racket_width - 10;
				ball_pos_x = width / 2;
				ball_pos_y = height / 2;
				racket_right_y = height/2;
				ball_dir_x = -1.0f;
				ball_dir_y = 0.0f;
				ball_speed =2;
				z=0;
			}	
		}
		if( c == 2)
		{
			cpu=2;
			if ( z == 1)
			{
				racket_left_x = 10.0f;
				racket_left_y = height/2;
				racket_right_x = width - racket_width - 10;
				ball_pos_x = width / 2;
				ball_pos_y = height / 2;
				racket_right_y = height/2;
				ball_dir_x = -1.0f;
				ball_dir_y = 0.0f;
				ball_speed=2;
				z=0;
			}
		}
		if ( c == 1)
		{
			char ch1[19]="Priyank Bhatt";
			char ch2[19]="Vraj Solanki";
			char ch3[19]="Prashant Bhanawat";
			glRasterPos2f(width/2-40,height/2);
			for (int i=0;ch1[i]!='\0';i++)
			{
				glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,ch1[i]);
			}
			glRasterPos2f(width/2-40,height/2-30);
			for (int i=0;ch2[i]!='\0';i++)
			{
				glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,ch2[i]);
			}
			glRasterPos2f(width/2-40,height/2-60);
			for (int i=0;ch3[i]!='\0';i++)
			{
				glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,ch3[i]);
			}		
			t=3;
			mainmenu=3;
			c=1;
		}
	}
	glutSwapBuffers();
}
void Mouse ( int button , int state , int x ,int y)
{
	if ( button == GLUT_LEFT_BUTTON && state== GLUT_DOWN )
	{
		
		if ( x>=(width/2)-40 && x<=((width/2)+70) && y<=(height/2)+30 && y>(height/2))
		{
			
			if ( t == 0)
			{
				c=1;
				mainmenu=3;
			}
			else if ( t == 1)
			{
				
				c=2;
				mainmenu=3;
			}
		
		}
		else if ( x >= ((width/2)-40) && x <= ((width/2) + 70) && y<=(height/2) && y>((height/2)-20))
		{
			if( t==0)
			{
				mainmenu=1;
			}			
			else if ( t == 1)
			{
				mainmenu=2;
				c=3;
			}
		}	
		else if ( x>=((width/2)-40) && x<=(width/2)+70 && y<=(height/2)+60 && y>=(height/2)+40)	
		{
			if (t == 0)
			{
				exit(0);
			}
			else if ( t == 1)
			{
				mainmenu=0;
				c=3;
				t=0;
			}
		}
	}
}			
void keyboard(unsigned char key, int x, int y)
{
	if(key == 27)
	 {	
		mainmenu=0;
		c=0;
		t=0;	
		cpu=0;
		score_right=0;
		score_left=0;
	}
	else if((char)key == 'w')
	{
		
		if (racket_left_y < height-23-racket_height)
		racket_left_y += racket_speed;
	}
	else if((char)key == 's')
	{
		if (racket_left_y > 23)
		racket_left_y -= racket_speed;
	}
	if ( cpu == 2)
	{

		if ((char)key == 'o')
		{
			if (racket_right_y < height-23-racket_height)
			racket_right_y += racket_speed;
		}
		else if ((char)key == 'l')
		{	
			if (racket_right_y > 23)
			racket_right_y -= racket_speed;
		}
	}
}
void updateball()
{
	ball_pos_x += ball_dir_x*ball_speed;
	ball_pos_y += ball_dir_y*ball_speed;
	if (cpu == 0)
	{
		racket_right_y = ball_pos_y*0.87f;
		racket_left_y = ball_pos_y*0.87f;
	}
	else if ( cpu == 1)
	{
		racket_right_y = ball_pos_y*0.87f;
	}	
	if ( ball_pos_x < racket_left_x + racket_width && ball_pos_x > racket_left_x && ball_pos_y < racket_left_y +racket_height && ball_pos_y > racket_left_y)
	{
		float t = ((ball_pos_y - racket_left_y)/racket_height) ;
		ball_dir_x = fabs(ball_dir_x);
		ball_dir_y = t;
	}
	if (ball_pos_x > racket_right_x && ball_pos_x < racket_right_x + racket_width &&  ball_pos_y < racket_right_y + racket_height && ball_pos_y > racket_right_y)
	{ 
		float t = ((ball_pos_y - racket_right_y)/racket_height);
		ball_dir_x = -1 * fabs(ball_dir_x);
		ball_dir_y = t;
	}
	if (ball_pos_x < 0)
	{
		ball_pos_x = width/2;
		ball_pos_y = height/2;
		ball_dir_x = fabs(ball_dir_x);
		ball_dir_y = 0;
		score_right++;
		ball_speed=2;
		if ( score_right == 3)
		{
			r=1;
		}
		
	}
	if(ball_pos_x > width )
	{
		ball_pos_x = width/2;
		ball_pos_y = height/2;
		ball_dir_x = -1 * fabs(ball_dir_x);
		ball_dir_y=0;
		score_left++;
		ball_speed=2;
		if (score_left == 3)
		{
			r=2;
		}
	}
	if ( ball_pos_y >= height-24)
	{
		ball_dir_y =  -1*fabs(ball_dir_y);
	}
	if ( ball_pos_y <= 24)
	{
		ball_dir_y = fabs(ball_dir_y);
	}
	if ( cpu == 1 || cpu == 2)
	ball_speed +=0.0002f;
}
void update(int value)
{
	if (mainmenu <=2)
	glutMouseFunc(Mouse);			
	glutKeyboardFunc(keyboard);
	updateball();	
	glutTimerFunc(interval,update,0);
	glutPostRedisplay();
		
}
void enable2d(int width,int height)
{
	glViewport(0.0f,0.0f,width,height);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0.0f,width,0.0f,height,0.0f,2.0f);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}
int main(int argc, char** argv)
{	
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB);
	glutInitWindowSize(width,height);
	glutCreateWindow("Pong");
	enable2d(width,height);	
	glutDisplayFunc(Draw);
	glutTimerFunc(interval,update,0);
	glutMainLoop();
	return 0;
}
	
