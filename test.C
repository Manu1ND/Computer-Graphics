#include <time.h>
#include <graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
void maze(int, int, int, int);
int move();
char a[50], ck[100]; //to store buffer

int x1, y1, x2, y2;
time_t before; //relative measurement of time
time_t diff;

void main()
{

  int gd = DETECT, gm;
  int check = 1;

  initgraph(&gd, &gm, "C://TURBOC3//BGI");
  while (check)
  {
    cleardevice();
    before = time(0);
    setaspectratio(1600, 1280);
    x1 = x2 = 80; //start point
    y1 = y2 = 40; //start point
    maze(x1, y1, x2, y2);
    //ch = 0;
    check = move();
  }
  getch();
  closegraph();
}

int move()
{
  int ch1, ch2, exitch = 0, s = 1;
  while (ch1 != 27) //escape=27
  {

    ch1 = getch();
    if (ch1 == 0 || ch1 == 224)
      ch2 = getch();

    if ((x1 == 80 && y1 == 40) && (ch2 != 80 && ch1 != 115)) //start point so only down
    {
      outtextxy(350, 350, "INVALID INPUT");
      continue;
    }
    if ((x2 == 80 && y2 == 40) && (ch2 != 80 && ch1 != 115)) //start point so only down
    {
      outtextxy(350, 350, "INVALID INPUT");
      continue;
    }
    switch (ch1)
    {
    case 0:
      switch (ch2)
      {
      case 72:                          //up
        if (getpixel(x1, y1 - 10) == 3) //checks color
        {
          outtextxy(35, 300, "INVALID INPUT");
          continue;
        }
        else
          y1 = y1 - 10;
        break;
      case 80:                          //down
        if (getpixel(x1, y1 + 10) == 3) //checks color
        {
          outtextxy(350, 200, "INVALID INPUT");
          continue;
        }
        else
          y1 = y1 + 10;
        break;
      case 77:                          //right
        if (getpixel(x1 + 10, y1) == 3) //checks color
        {
          outtextxy(350, 200, "INVALID INPUT");
          continue;
        }
        else
          x1 = x1 + 10;
        break;
      case 75:                          //left
        if (getpixel(x1 - 10, y1) == 3) //checks color
        {
          outtextxy(350, 200, "INVALID INPUT");
          continue;
        }
        else
          x1 = x1 - 10;
        break;
      }
      break;

    case 87:                          //W
    case 119:                         //w
      if (getpixel(x2, y2 - 10) == 3) //checks color
      {
        outtextxy(35, 300, "INVALID INPUT");
        continue;
      }
      else
        y2 = y2 - 10;
      break;
    case 83:                          //S
    case 115:                         //s
      if (getpixel(x2, y2 + 10) == 3) //checks color
      {
        outtextxy(350, 200, "INVALID INPUT");
        continue;
      }
      else
        y2 = y2 + 10;
      break;
    case 65:                          //A
    case 97:                          //a
      if (getpixel(x2 - 10, y2) == 3) //checks color
      {
        outtextxy(350, 200, "INVALID INPUT");
        continue;
      }
      else
        x2 = x2 - 10;
      break;
    case 68:                          //D
    case 100:                         //d
      if (getpixel(x2 + 10, y2) == 3) //checks color
      {
        outtextxy(350, 200, "INVALID INPUT");
        continue;
      }
      else
        x2 = x2 + 10;
      break;
    }

    cleardevice();
    maze(x1, y1, x2, y2);
    if (x1 == 310 || x2 == 310) //end point
    {
      (x1 == 310) ? outtextxy(350, 200, "Player1 WIN") : outtextxy(350, 200, "Player2 WIN");
      ;
      diff = time(0) - before;
      sprintf(ck, "Time taken %d seconds", diff);
      outtextxy(350, 180, ck);
      //stop timer

      outtextxy(350, 220, "PRESS R TO PLAY AGAIN OR Q TO EXIT");
      while (s)
      {
        exitch = getch();
        if (exitch == 'q' || exitch == 'Q')
        {
          return 0;
        }
        else if (exitch == 'r' || exitch == 'R')
        {
          return 1;
        }
      }
    }
  }
}

void maze(int x1, int y1, int x2, int y2)
{
  setcolor(WHITE);
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

  setcolor(WHITE);
  outtextxy(65, 15, "ENTRY");
  outtextxy(315, 297, "EXIT");
  setcolor(YELLOW);
  circle(x1, y1, 3);
  setfillstyle(1, 2);
  floodfill(x1, y1, 14); // color pointer
  setcolor(RED);
  circle(x2, y2, 3);
  setfillstyle(1, 15);
  floodfill(x2, y2, 4); // color pointer
}