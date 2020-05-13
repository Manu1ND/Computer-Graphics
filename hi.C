#include <stdio.h>
#include <conio.h>

int main ()
{
    int ch;

    while ((ch = getch()) != 27) /* 27 = Esc key */
    {
        printf("%d", ch);
        if (ch == 0 || ch == 224)
            printf (", %d", getch ()); 
        printf("\n");
    }

    printf("ESC %d\n", ch);

    return (0);
}
/*
w - 119
W - 87
s - 115
S - 83
a - 97
A - 65
d - 100
D - 68
*/