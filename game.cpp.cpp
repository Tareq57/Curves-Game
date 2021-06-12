# include "iGraphics.h"
#include<math.h>

int x,y,tim=20,xx=0,yy=0,r,g,b,x1,x2,yy1,yy2,a=1,bb=1,c=1,d=1,sinn=1,coss=1,sincos=1,sincoss=1,upp=100,siz,
     ballsin=1,ballcos=1,ballsincos=1,ballsincoss=1,flag=1,p=1,rem=1;
char pic[1][100]={"help.bmp"};
double feq=1.0,pi=3.14159265,sin_circle[100],cos_circle[100],sincos_circle[100],sincoss_circle[100],pos=1;
void mk()
{
    for(int i=1;i<=sinn;i++)
    {
     sin_circle[i-1]=upp*sin(double(feq)*double(i)*(double)yy*pos*pi/180.0);
    }
    for(int i=1;i<=coss;i++)
    {
      cos_circle[i-1]=upp*cos(double(feq)*double(i)*double(yy)*pos*pi/180.0);
    }
    for(int i=1;i<=sincos;i++)
    {
     sincos_circle[i-1]=upp*sin(double(feq)*double(i)*(double)yy*pos*pi/180.0)+
                        upp*cos(double(feq)*double(i)*double(yy)*pos*pi/180.0);
    }
    for(int i=1;i<=sincoss;i++)
    {
     sincoss_circle[i-1]=upp*sin(double(feq)*double(i)*(double)yy*pos*pi/180.0)-
                     upp*cos(double(feq)*double(i)*double(yy)*pos*pi/180.0);
    }
    if(flag){xx++;yy++;}
    if(!flag){xx--;yy--;}
}
void iDraw()
{
    if(rem==1){
    iClear();
    if(p)
    {
        iShowBMP(200,200,pic[0]);
        iSetColor(r=0,g=0,b=0);
        iText(250,976,"Press p for start the game");
        iText(250,946,"Press q for exit the game");
        iText(250,916,"Press f and F frequency");
        iText(250,886,"Press s and S for curve visibility");
        iText(250,856,"Press 1,2,3,4 for ball vanishing");
        iText(250,526,"Press !,@,#,$ for ball visbility");
        iText(250,826,"Press pgUP and pgDOWN for streching the curves");
        iText(250,796,"Press a and A for number of  sine curves");
        iText(250,766,"Press b and B for number of  cos curves");
        iText(250,736,"Press c and C for number of  sin+cos curves");
        iText(250,706,"Press d and D for number of  sine-cos curves");
        iText(250,676,"Press + and - for speed of the ball");
        iText(250,646,"Press w and W for sin curve visibility");
        iText(250,616,"Press x and X for cos curve visibility");
        iText(250,586,"Press y and Y for sin+cos curve visibility");
        iText(250,556,"Press z and Z for sin-cos curve visibility");


    }
    else{
    if(pos*xx>=1915)
        flag=0;
    if(pos*xx<=5)
        flag=1;
    iSetColor(r=255,g=255,b=255);
    iLine(x1=0,yy1=540,x2=1920,yy2=540);
    if(a)
    {
        for(int i=1;i<=sinn;i++)
        {
            for(int j=0;j<=1920;j++)
            {
               double k=upp*sin(double(feq)*double(i)*(double)j*pi/180.0);
               iSetColor(r=255,g=0,b=0);
               iPoint(double(j),540+k,siz=0);
            }
        }
    }
    if(ballsin)
    for(int i=1;i<=sinn;i++)
    {
        iSetColor(r=255,g=0,b=0);
        iFilledCircle(pos*xx,540+sin_circle[i-1],10);
    }
    if(bb)
    {
        for(int i=1;i<=coss;i++)
        {
            for(int j=0;j<=1920;j++)
            {
                double k=upp*cos(double(feq)*double(i)*double(j)*pi/180.0);
                iSetColor(r=0,g=255,b=0);
                iPoint(double(j),540+k,siz=0);
            }
        }
    }
    if(ballcos)
    for(int i=1;i<=coss;i++)
    {
        iSetColor(r=0,g=255,b=0);
        iFilledCircle(pos*xx,540+cos_circle[i-1],10);
    }
    if(c)
    {
        for(int i=1;i<=sincos;i++)
        {
            for(int j=0;j<=1920;j++)
            {
                double k=upp*sin(double(feq)*double(i)*double(j)*pi/180.0)+upp*cos(double(feq)*double(i)*double(j)*pi/180.0);
                iSetColor(r=0,g=0,b=255);
                iPoint(double(j),540+k,siz=0);
            }
        }
    }
    if(ballsincos)
    for(int i=1;i<=sincos;i++)
    {
        iSetColor(r=0,g=0,b=255);
        iFilledCircle(pos*xx,540+sincos_circle[i-1],10);
    }
    if(d)
    {
        for(int i=1;i<=sincoss;i++)
        {
            for(int j=0;j<=1920;j++)
            {
                double k=upp*sin(double(feq)*double(i)*double(j)*pi/180.0)-upp*cos(double(feq)*double(i)*double(j)*pi/180.0);
                iSetColor(r=255,g=255,b=0);
                iPoint(double(j),540+k,siz=0);
            }
        }
    }
    if(ballsincoss)
    for(int i=1;i<=sincoss;i++)
    {
        iSetColor(r=255,g=255,b=0);
        iFilledCircle(pos*xx,540+sincoss_circle[i-1],10);
    }
    }
    }


}
void iMouseMove(int mx, int my)
{
    //printf("x = %d, y= %d\n",mx,my);
    //place your codes here
}
void iMouse(int button, int state, int mx, int my)
{
    if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
    {
        x += 5;
        y += 5;

    }
    if(button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
    {
        x -= 5;
        y -= 5;
    }

}
void iKeyboard(unsigned char key)
{
    if(key == 'q')
    {
        exit(0);
    }
    if(key=='a')sinn--;if(key=='A')sinn++;if(key=='b')coss--;if(key=='B')coss++;if(key=='c')sincos--;if(key=='C')sincos++;if(key=='d')sincoss--;if(key=='D')sincoss++;
    if(key=='w')a=1;if(key=='W')a=0;if(key=='x')bb=1;if(key=='X')bb=0;if(key=='y')c=1;if(key=='Y')c=0;if(key=='z')d=1;if(key=='Z')d=0;
    if(key=='1')ballsin=0;if(key=='2')ballcos=0;if(key=='3')ballsincos=0;if(key=='4')ballsincoss=0;
    if(key=='!')ballsin=1;if(key=='@')ballcos=1;if(key=='#')ballsincos=1;if(key=='$')ballsincoss=1;
    if(key=='f')feq-=.25;
    if(key=='F')feq+=.25;
    if(key=='-'){xx*=pos;yy*=pos;pos-=.4;xx/=pos;yy/=pos;}
    if(key=='+'){xx*=pos;yy*=pos;pos+=.4;xx/=pos;yy/=pos;}
    if(key=='s')
    {
        a=0;bb=0;c=0;d=0;
    }
    if(key=='S')
    {
        a=1;bb=1;c=1;d=1;
    }
    if(key=='p')
        p=0;
    if(key=='r')flag=1;
    if(key=='l')flag=0;
    if(key=='r')
    {
        rem=0;
    }
    if(key=='R')
        rem=1;
}
void iSpecialKeyboard(unsigned char key)
{

    if(key == GLUT_KEY_END)
    {
        exit(0);
    }
    if(key==GLUT_KEY_UP)
        upp+=5;
    if(key==GLUT_KEY_DOWN)
        upp-=5;
}


int main()
{
    iSetTimer(tim,mk);
    iInitialize(1920, 1080, "Demo!");
    return 0;
}
