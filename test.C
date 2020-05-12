#include <time.h>
#include <graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
void maze(int, int);
char a[50]; //to store buffer
int f1, f2, f3, f4; //to check collected coins
int c = 0; //number of coins
time_t before; //relative measurement of time
time_t diff;

void main()
{
  char ck[100]; //to store buffer

  int gd = DETECT, gm;
  char ch = 0, exitch;
  int x, y;

  initgraph(&gd, &gm, "C://TURBOC3//BGI");
p:
  cleardevice();
  before = time(0);
  f1 = f2 = f3 = f4 = exitch = 0;
  setaspectratio(1600, 1280);
  c = 0;
  x = 80; //start point
  y = 40; //start point
  maze(x, y);
  ch = 0; 
  while (ch != 27) //escape=27
  {
    
    ch = getch();
    if ((x == 120 && y == 280) && (f1 < 1))
    {
      f1 = 1;
      c = c + 1;
    }
    
    if ((x == 210 && y == 140) && (f2 < 1))
    {
      f2 = 1;
      c = c + 1;
    }

    if ((x == 100 && y == 100) && (f3 < 1))
    {
      f3 = 1;
      c = c + 1;
    }
    
    if ((x == 200 && y == 320) && (f4 < 1))
    {
      f4 = 1;
      c = c + 1;
    }

    if ((x == 80 && y == 40) && (ch != 80)) //start point so only down
    {
      outtextxy(350, 350, "INVALID INPUT");
      continue;
    }
    switch (ch)
    {
    case 72: //up
      if (getpixel(x, y - 10) == 3) //checks color
      {
        outtextxy(35, 300, "INVALID INPUT");
        continue;
      }
      else
        y = y - 10;
      break;
    case 80: //down
      if (getpixel(x, y + 10) == 3) //checks color
      {
        outtextxy(350, 200, "INVALID INPUT");
        continue;
      }
      else
        y = y + 10;
      break;
    case 77: //right
      if (getpixel(x + 10, y) == 3) //checks color
      {
        outtextxy(350, 200, "INVALID INPUT");
        continue;
      }
      else
        x = x + 10;
      break;
    case 75: //left
      if (getpixel(x - 10, y) == 3) //checks color
      {
        outtextxy(350, 200, "INVALID INPUT");
        continue;
      }
      else
        x = x - 10;
      break;
    }

    cleardevice();
    maze(x, y);
    if (x == 310)
    {
      outtextxy(350, 200, "YOU WIN");
      diff = time(0) - before;
      sprintf(ck, "Time taken %d seconds\n", diff);
      outtextxy(350, 180, ck);
      //stop timer

      outtextxy(350, 220, "PRESS R TO PLAY AGAIN OR Q TO EXIT");
    s:
      exitch = getch();
      if (exitch == 'q' || exitch == 'Q')
      {
        break;
      }
      else if (exitch == 'r' || exitch == 'R')
      {
        goto p;
      }
      else
      {
        goto s;
      }
    }
  }
  getch();
  closegraph();
}

void maze(int x, int y)
{
  setcolor(WHITE);
  outtextxy(400, 100, "COLLECT ALL 4 COINS TO WIN");
  setcolor(3); //blue
  line(50, 50, 70, 50);
  line(90, 50, 290, 50);
  line(290, 50, 290, 290);
  line(290, 310, 290, 370);
  line(50, 370, 290, 370);
  line(50, 50, 50, 370);
  line(70, 70, 70, 90);
  line(50, 90, 70, 90);
  line(90, 90, 270, 90);
  line(90, 70, 90, 90);
  line(50, 110, 250, 110);
  line(270, 90, 270, 230);
  line(270, 230, 150, 230);
  line(150, 230, 150, 150);
  line(150, 150, 90, 150);
  line(250, 110, 250, 150);
  line(250, 150, 200, 150);
  line(200, 150, 200, 130);
  line(200, 130, 70, 130);
  line(70, 130, 70, 310);
  sprintf(a, "THE NUMBER OF COLLECTED COINS IS %d", c); //string print
  outtextxy(150, 450, a);
  line(70, 310, 150, 310);
  line(150, 310, 150, 350);
  line(150, 350, 250, 350);
  line(250, 350, 250, 310);
  line(250, 310, 170, 310);
  line(170, 310, 170, 330);
  line(170, 330, 230, 330);
  line(90, 150, 90, 290);
  line(90, 290, 290, 290);
  line(170, 130, 170, 170);
  line(270, 290, 270, 350);
  rectangle(170, 170, 250, 210);
  line(70, 50, 70, 30);
  line(90, 50, 90, 30);
  line(290, 290, 310, 290);
  line(290, 310, 310, 310);

  if (c < 4)
    line(290, 290, 290, 310);
  if (f1 != 1)
    circle(120, 280, 3);
  if (f2 != 1)
    circle(210, 140, 3);
  if (f3 != 1)
    circle(100, 100, 3);
  if (f4 != 1)
    circle(200, 320, 3);

  setcolor(WHITE);
  outtextxy(65, 15, "ENTRY");
  outtextxy(315, 297, "EXIT");
  setcolor(YELLOW);
  circle(x, y, 3);
  setfillstyle(1, 2);
  floodfill(x, y, 14);
}