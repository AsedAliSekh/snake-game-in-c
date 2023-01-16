#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

int height = 30, width = 30, x, y, fruitX, fruitY, flag, gameEnd, score;
int tailX[100], tailY[100];
int piece =0;
// logic of the game
void makeLogic()
{   

    // logic for incriment the snake and run
    int i;
    int prevX, prevY, prev2X, prev2Y;
    prevX = tailX[0];
    prevY = tailY[0];
    tailX[0] = x;
    tailY[0] = y;

    for (i = 1; i <= piece; i++)
    {
        prev2X = tailX[i];
        prev2Y = tailY[i];
        tailX[i] = prevX;
        tailY[i] = prevY;

        prevX = prev2X;
        prevY = prev2Y;
    }
    // end of increement logic
    
    switch (flag)
    {
    case 1:
    {
        x--;
        break;
    }

    case 2:
    {
        x++;
        break;
    }

    case 3:
    {
        y--;
        break;
    }

    case 4:
    {
        y++;
        break;
    }
    }
    if (x == 0 || x == height || y == 0 || y == width)
    {
        gameEnd = 1;
    }
    if (x == fruitX && y == fruitY)
    {
    label3:
        fruitX = rand() % 20;
        if (fruitX == 0)
        {
            goto label3;
        }

    label4:
        fruitY = rand() % 20;
        if (fruitY == 0)
        {
            goto label4;
        }
        score+=10;
        piece++;
    }
}
// for movment of snake
void input()
{
    if (kbhit())
    {
        switch (getch())
        {
        case 'w':
        {
            flag = 1;
            break;
        }

        case 's':
        {
            flag = 2;
            break;
        }

        case 'a':
        {
            flag = 3;
            break;
        }

        case 'd':
        {
            flag = 4;
            break;
        }
        }
    }
}
// setup function for setup the snake's possition
void setup()
{
    x = height / 2;
    y = width / 2;

label1:
    fruitX = rand() % 20;
    if (fruitX == 0)
    {
        goto label1;
    }

label2:
    fruitY = rand() % 20;
    if (fruitY == 0)
    {
        goto label2;
    }
    gameEnd = 0;
    score = 0;
    
}

// the draw function is for printing the fream of the game boddy
void draw()
{
    system("cls");

    int i, j, k, ch;
    for (i = 0; i <= height; i++)
    {
        for (j = 0; j <= width; j++)
        {
            if (i == 0 || i == height || j == 0 || j == width)
            {
                printf("*");
            }
            else
            {
                if (i == x && j == y)
                {
                    printf("0");
                }
                else if (i == fruitX && j == fruitY)
                {
                    printf("@");
                }
                else
                {
                    ch =0;
                    // this loop is for print snake's body
                    for(k = 0; k < piece; k++)
                    {
                        if (i == tailX[k] && j == tailY[k])
                        {
                            printf("o");
                            ch =1;
                        }
                        
                    }
                    if (ch == 0)
                    printf(" ");
                }
            }
        }
        printf("\n");
    }
    printf("Your Score is: %d", score); 
}
int main()
{

    setup();
    while (gameEnd != 1)
    {
        input();
        draw();
        makeLogic();
    }

    return 0;
}

// finished
