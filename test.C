#include <time.h>
#include <graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
void maze(int, int);
char a[50];
int f1 = 0, f2 = 0, f3 = 0, f4 = 0, f5 = 0;
int c = 0, g, l;
int f11 = 1, f22 = 0, f33 = 0, f44 = 0, f55 = 0;
clock_t before;
clock_t diff;

char z;
int tt = 0;
void main()
{

  char ck[100];

  /* request auto detection */
  int gd = DETECT, gm;
  char ch = 0, h;
  int x, y;

  /* initialize graphics and local variables */
  initgraph(&gd, &gm, "C://TURBOC3//BGI");
p:
  cleardevice();
  before = clock();
  l = 0;
  srand(time(0));
  f11 = f22 = f33 = f44 = f55 = f1 = f2 = f3 = f4 = f5 = h = 0;
  setaspectratio(1600, 1280);
  c = 0;
  x = 80;
  y = 40;
  maze(x, y);
  ch = 0;
 
  while (ch != 27) //escape=27
  {
    if (l == 0)
    {
    u:
      g = (rand()) % 10;
      g = g * 10;
      if (getpixel(50 + g, 50 + g) == 3)
        goto u;
      l = l + 1;
    }
    ch = getch();
    if ((x == 120 && y == 280) && (f11 < 3))
    {
      f1 = 1;
      c = c + 1;
      f11++;
    }
    if ((x == 100 && y == 100) && (f33 < 3))
    {
      f3 = 1;
      c = c + 1;
      f33++;
    }
    if ((x == (50 + g) && y == (50 + g)) && (f22 < 3))
    {
      f2 = 1;
      c = c + 1;
      f22++;
    }
    if ((x == 200 && y == 320) && (f44 < 3))
    {
      f4 = 1;
      c = c + 1;
      f44++;
    }
    if ((x == 210 && y == 140) && (f55 != 2))
    {
      f5 = 1;
      c = c + 1;
      f55++;
    }

    if ((x == 80 && y == 40) && (ch != 80)) //only down
    {
      outtextxy(350, 350, "INVALID INPUT");
      continue;
    }
    switch (ch)
    {
    case 72: //up
      if (getpixel(x, y - 10) == 3)
      {
        outtextxy(35, 300, "INVALID INPUT");
        continue;
      }
      else
        y = y - 10;
      break;
    case 80: //down
      if (getpixel(x, y + 10) == 3)
      {
        outtextxy(350, 200, "INVALID INPUT");
        continue;
      }
      else
        y = y + 10;
      break;
    case 77: //right
      if (getpixel(x + 10, y) == 3)
      {
        outtextxy(350, 200, "INVALID INPUT");
        continue;
      }
      else
        x = x + 10;
      break;
    case 75: //left
      if (getpixel(x - 10, y) == 3)
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
    s:

      h = getch();
      outtextxy(350, 200, "YOU WIN");
      diff = -(before - clock());
      sprintf(ck, "Time taken %d seconds %d milliseconds\n",
              diff / 10, diff % 10);
      outtextxy(350, 180, ck);

      outtextxy(350, 220, "PRESS R TO PLAY AGAIN OR Q TO EXIT");
      if (h == 'q' || h == 'Q')
      {
        break;
      }
      else if (h == 'r' || h == 'R')
      {
        goto p;
      }
      else
      {
        goto s;
      } //stop timer
    }
  }
  getch();
  closegraph();
}

void maze(int x, int y)
{
  setcolor(WHITE);
  outtextxy(400, 100, "COLLECT ALL 5 COINS TO WIN");
  setcolor(3);
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
  sprintf(a, "THE NUMBER OF COLLECTED COINS IS %d", c / 2);
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
  if (c < 10)
    line(290, 290, 290, 310);
  if (f1 != 1)
    circle(120, 280, 3);
  if (f2 != 1)
    circle(50 + g, 50 + g, 3);
  if (f3 != 1)
    circle(100, 100, 3);
  if (f4 != 1)
    circle(200, 320, 3);
  if (f5 != 1)
    circle(210, 140, 3);

  setcolor(WHITE);
  outtextxy(65, 15, "ENTRY");
  outtextxy(315, 297, "EXIT");
  setcolor(YELLOW);
  circle(x, y, 3);
  setfillstyle(1, 2);
  floodfill(x, y, 14);
}