// THIS IS SNAKE GAME CODE
// coppy rigth reserved @2022  november
// This code is written by vishal kumar ...
// working effort on this code from [ date :- 23/11/2022 to 29/11/2022 ]
// finnally closing this project on 29/11/2022 at 9:14:45 pm

//................................ introduction about this code

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <windows.h> // Beep(frequency,second in ms)

//..................................header file

int row = 20, column = 30; // row === y and column == x
int foodx = 0, foody = 0, endgame = 0;
int lable = 0, x = 0, y = 0, count = 0, i = 1, j = 1;
int s, position = 0, position2 = 0;

//..................................variables
void rand_location_food();
void boundry();
void snake_move_input();
void snake_move_output();
void length_increase();
void right_move();
void left_move();
void down_move();
void up_move();
void load();
void gotoxy();
void instruction();
//..................................function prototype
int main()
{
    x = row / 2;
    y = column / 2;

    system("cls");
    instruction();
    system("cls");
    load();
    rand_location_food();

    while (endgame != 1)
    {
        printf("          SCORE : %d \n\n", count);
        boundry();
        system("cls");
        snake_move_input();
        snake_move_output();

        if (x == foodx && y == foody)
        {
            rand_location_food();
            count++;
        }
    }
    if (endgame == 1)
    {
        printf("\n\n\t\t\t   Opps\n\t\t........ Game End .......\n");
        printf("\t\t\t SCORE : %d \n\n\n", count);
    }
    printf("\n\n\n\tThis Snake Game Is Developed By Vishal kumar \n\n\n\n\n\n\n");

    return 0;
}
//...................................main() function
void boundry()
{

    for (i = 1; i <= row; i++) // control row line
    {
        for (j = 1; j <= column; j++) // control column line
        {
            if (i == 1 || i == row || j == 1 || j == column)
            {
                printf("!");
            }
            else
            {

                if (i == foodx && j == foody)
                {
                    printf("%c", 1);
                }
                else if (i == x && j == y)
                {
                    if (lable == 1)
                    {
                        printf("%c", 94);
                    }
                    if (lable == 2)
                    {
                        printf("%c", 118);
                    }
                    if (lable == 3)
                    {
                        printf("%c", 60);
                    }
                    if (lable == 4)
                    {
                        printf("%c", 62);
                    }
                    if (lable == 0)
                    {
                        printf("%c", 94);
                    }
                }
                else
                {

                    printf(" ");
                }
                if (count > 0)
                {
                    if (lable == 1)
                    {
                        up_move();
                    }
                    if (lable == 2)
                    {
                        down_move();
                    }
                    if (lable == 3)
                    {
                        left_move();
                    }
                    if (lable == 4)
                    {
                        right_move();
                    }
                }
            }
        }
        printf("\n");
    }
}

//.......................................boundry() function
void rand_location_food()
{
    srand(time(0));

l1:
    foodx = rand() % row;
    if (foodx == 1 || foodx == 0)
    {
        goto l1;
    }

l2:
    foody = rand() % column;
    if (foody == 1 || foody == 0)
    {
        goto l2;
    }
}
//.......................................randlocationfood() function
void snake_move_input()

{
    if (kbhit())
    {
        switch (getch())
        {
        case 'w': //"w"...upper
            lable = 1;
            break;
        case 's': //"s"....down
            lable = 2;
            break;
        case 'a': //"a"....left
            lable = 3;
            break;
        case 'd': //"d"....right
            lable = 4;
            break;
        }
    }
}
//................................snake_move_input() function
void snake_move_output()
{
    switch (lable)
    {
    case 1:
        x--; //"w"...upper
        break;
    case 2:
        x++; //"s"....down
        break;
    case 3:
        y--; //"a"....left
        break;
    case 4:
        y++; //"d"....right
        break;
    }
    if (x == 1 || x == row || y == 1 || y == column)
    {
        endgame = 1;
    }
}
//..................................snake_move_output() function

void up_move()
{
    position = x;
    position2 = y;
    for (s = 1; s <= count; s++)
    {
        position++;
        if (i == position && j == position2--)
        {
            printf("%c", '.');
        }
    }
}
void down_move()
{
    position = x;
    for (s = 1; s <= count; s++)
    {
        position--;
        if (i == position && j == y)
        {
            printf("%c", '.');
        }
    }
}
void right_move() // x is constant
{
    position = y;
    for (s = 1; s <= count; s++)
    {
        position--;
        if (i == x && j == position)
        {
            printf("%c", '.');
        }
    }
}
void left_move()
{
    position = x;
    for (s = 1; s <= count; s++)
    {
        position--;
        if (i == x && j == y)
        {
            printf("%c", '.');
        }
    }
}

void gotoxy(int x, int y)
{

    COORD coord;

    coord.X = x;

    coord.Y = y;

    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void load()
{
    int row, col, r, c, q;
    gotoxy(30, 10);
    printf(" loading...\n");
    gotoxy(25, 11);
    for (r = 1; r <= 20; r++)
    {
        for (q = 0; q <= 100000000; q++)
            ;
        printf("%c", 177); // to display the character slowly
    }
    // getch();
}
void instruction()
{
    printf("\n");
    printf( "coppy rigth reserved @2022 November... "
            "This code is written by Vishal kumar ... " 
            "working effort on this code from [ date :- 23/11/2022 to 29/11/2022 ]... "
            "finnally Finished this project on 29/11/2022 at 9:14:45 pm\n\nPress Enter Key To Go Next Step \n");
    getch();
    system("cls");

    printf("................. Welcome to Snake Game .................\n\nPress Enter Key To Go Next Step \n");
    getch();
    system("cls");

    printf("Game instruction.............\n");
    printf("  1. snake move : Upward , Downward , Leftward , Rightward.\n");
    printf("  2. For Move Up used  'W' Button.\n");
    printf("  3. For Move Down used 'S' Button.\n");
    printf("  4. For Move  Right used 'D' Button.\n");
    printf("  5. For Move Left used  Button.\n\n");
    printf("** Your Live Score Show Top Upper Out Side Of The Box **\n\n");
    printf("** Press Enter To Play Game ** \n");
    getch();
}