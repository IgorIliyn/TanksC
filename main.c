#include <stdio.h>
#include <stdbool.h>
#include <windows.h>
#include <pthread.h>
#include <source.h>
#include <conio.h>
// Defines

#define hCon GetStdHandle(STD_OUTPUT_HANDLE)
#define NUM_THREADS     5
#define UP 72
#define DOWN 80
#define LEFT 75
#define RIGHT 77
#define SHOT 32
#define EXIT 27

// Datatypes

typedef enum {
    SOUTH = 0,
    NORTH,
    EAST,
    WEST
}TankDirection;

typedef struct  {
    COORD position;
    TankDirection direction;
    bool isFirstTurn;
}Tank;

// Functions
void *PrintHello(void *threadid)
{
   long tid;
   tid = (long)threadid;
   printf("Hello World! It's me, thread #%ld!\n", tid);
   pthread_exit(NULL);
}

void func_map(const int *mapa)
{
    int i;
    for (i = 0; i < 9074; i++)
    {
        switch(mapa[i]) {
        case 0:
            printf("%c",32);
            break;
        case 1:
            printf("%c", 178);
            break;
        case 2:
            printf("%c", 177);
            break;
        case 3:
            printf("%c", 187);
            break;
        case 4:
            printf("%c", 200);
            break;
        case 5:
            printf("%c", 188);
            break;
        case 6:
            printf("%c", 205);
            break;
        case 7:
            printf("%c", 186);
            break;
        }
    }
}

void drawTank(Tank *tank) {

    switch(tank->direction)
    {
        case SOUTH:
        {
            SetConsoleCursorPosition(hCon,tank->position);
            printf("  %c  \n",220);
            tank->position.Y++;
            SetConsoleCursorPosition(hCon,tank->position);
            printf("  %c  \n",186);
            tank->position.Y++;
            SetConsoleCursorPosition(hCon,tank->position);
            if(tank->position.Y % 2 == 0)
            {
                printf("%c%c%c%c%c\n",178,178,202,178,178);
            }else{
                printf("%c%c%c%c%c\n",176,176,202,176,176);
            }
            tank->position.Y++;
            SetConsoleCursorPosition(hCon,tank->position);
            if(tank->position.Y % 2 == 0)
            {
                printf("%c%c %c%c\n",178,178,178,178);
            }else{
                printf("%c%c %c%c\n",176,176,176,176);
            }
            tank->position.Y++;
            SetConsoleCursorPosition(hCon,tank->position);
            if(tank->position.Y % 2 == 0)
            {
                printf("%c%c %c%c\n",178,178,178,178);
            }else{
                printf("%c%c %c%c\n",176,176,176,176);
            }
            tank->position.Y++;
            SetConsoleCursorPosition(hCon,tank->position);
            if(tank->position.Y % 2 == 0)
            {
                printf("%c%c%c%c%c\n",178,178,205,178,178);
            }else{
                printf("%c%c%c%c%c\n",176,176,205,176,176);
            }
            tank->position.Y -= 5;
            break;
        }
        case NORTH:
        {
            SetConsoleCursorPosition(hCon,tank->position);
            if(tank->position.Y % 2 == 0)
            {
                printf("%c%c%c%c%c\n",178,178,205,178,178);
            }else{
                printf("%c%c%c%c%c\n",176,176,205,176,176);
            }
            tank->position.Y++;
            SetConsoleCursorPosition(hCon,tank->position);
            if(tank->position.Y % 2 == 0)
            {
                printf("%c%c %c%c\n",178,178,178,178);
            }else{
                printf("%c%c %c%c\n",176,176,176,176);
            }
            tank->position.Y++;
            SetConsoleCursorPosition(hCon,tank->position);
            if(tank->position.Y % 2 == 0)
            {
                printf("%c%c %c%c\n",178,178,178,178);
            }else{
                printf("%c%c %c%c\n",176,176,176,176);
            }
            tank->position.Y++;
            SetConsoleCursorPosition(hCon,tank->position);
            if(tank->position.Y % 2 == 0)
            {
                printf("%c%c%c%c%c\n",178,178,203,178,178);
            }else{
                printf("%c%c%c%c%c\n",176,176,203,176,176);
            }
            tank->position.Y++;
            SetConsoleCursorPosition(hCon,tank->position);
            printf("  %c  \n",186);
            tank->position.Y++;
            SetConsoleCursorPosition(hCon,tank->position);
            printf("  %c  \n",223);
            tank->position.Y -= 5;
            break;
        }
        case WEST:
        {
            SetConsoleCursorPosition(hCon,tank->position);
            if(tank->position.X % 2 == 0)
            {
                printf("  %c%c%c%c%c%c\n",178,176,178,176,178,176);
            }else{
                printf("  %c%c%c%c%c%c\n",176,178,176,178,176,178);
            }
            tank->position.Y++;
            SetConsoleCursorPosition(hCon,tank->position);
            printf("%c%c%c    %c\n",254,205,185,186);
            tank->position.Y++;
            SetConsoleCursorPosition(hCon,tank->position);
            if(tank->position.X % 2 == 0)
            {
                printf("  %c%c%c%c%c%c\n",178,176,178,176,178,176);
            }else{
                printf("  %c%c%c%c%c%c\n",176,178,176,178,176,178);
            }
            tank->position.Y -= 2;
            break;
        }
        case EAST:
        {
            SetConsoleCursorPosition(hCon,tank->position);
            if(tank->position.X % 2 == 0)
            {
                printf("%c%c%c%c%c%c  \n",178,176,178,176,178,176);
            }else{
                printf("%c%c%c%c%c%c  \n",176,178,176,178,176,178);
            }
            tank->position.Y++;
            SetConsoleCursorPosition(hCon,tank->position);
            printf("%c    %c%c%c\n",186,204,205,254);
            tank->position.Y++;
            SetConsoleCursorPosition(hCon,tank->position);
            if(tank->position.X % 2 == 0)
            {
                printf("%c%c%c%c%c%c  \n",178,176,178,176,178,176);
            }else{
                printf("%c%c%c%c%c%c  \n",176,178,176,178,176,178);
            }
            tank->position.Y -= 2;
            break;
        }
    }
}

void init(){
    system("mode con cols=165 lines=55");
    CONSOLE_CURSOR_INFO cci;
    cci.dwSize = 1;
    cci.bVisible = false;
    SetConsoleCursorInfo(hCon ,&cci);
}

bool isFreeWay(Tank *tank, TankDirection direction) {
    switch (direction) {
        case SOUTH:{
            int one = MAP[165 * (tank->position.Y - 1) + tank->position.X];
            int two = MAP[165 * (tank->position.Y - 1) + tank->position.X + 1];
            int three = MAP[165 * (tank->position.Y - 1) + tank->position.X + 2];
            int four = MAP[165 * (tank->position.Y - 1) + tank->position.X + 3];
            int five = MAP[165 * (tank->position.Y - 1) + tank->position.X + 4];
            if (one != 1 && two != 1 && three != 1 && four != 1 && five != 1) {
                return true;
            } else {
                return false;
            }
        }
        break;
        case NORTH:{
            int one = MAP[165 * (tank->position.Y + 6) - (165 - tank->position.X)];
            int two = MAP[165 * (tank->position.Y + 6) + tank->position.X + 1];
            int three = MAP[165 * (tank->position.Y + 6) + tank->position.X + 2];
            int four = MAP[165 * (tank->position.Y + 6) + tank->position.X + 3];
            int five = MAP[165 * (tank->position.Y + 6) + tank->position.X + 4];
            if (one != 1 && two != 1 && three != 1 && four != 1 && five != 1) {
                return true;
            } else {
                return false;
            }
        }

        break;
        case WEST:{
            int up = MAP[165 * tank->position.Y + (tank->position.X - 1)];
            int middle = MAP[165 * (tank->position.Y + 1) + (tank->position.X + 1)];
            int down = MAP[165 * (tank->position.Y + 2) + (tank->position.X + 1)];

            if (up != 1 && middle != 1 && down != 1)
                return true;
            else
                return false;
        }
        break;
        case EAST:{
            int up = MAP[165 * tank->position.Y + (tank->position.X + 8)];
            int middle = MAP[165 * (tank->position.Y + 1) + (tank->position.X + 8)];
            int down = MAP[165 * (tank->position.Y + 2) + (tank->position.X + 8)];

            if (up != 1 && middle != 1 && down != 1)
                return true;
            else
                return false;

        }
        break;
    }
}

void ereasePreviousPosition(Tank *tank)
{
    COORD pos = tank->position;

    if (tank->isFirstTurn)
    {
        switch (tank->direction)
        {
            case NORTH:
            case SOUTH:
            {
                pos.Y += 3;
                SetConsoleCursorPosition(hCon,pos);
                printf("     ");
                pos.Y++;
                SetConsoleCursorPosition(hCon,pos);
                printf("     ");
                pos.Y++;
                SetConsoleCursorPosition(hCon,pos);
                printf("     ");
                break;
            }
            case EAST:
            case WEST:
            {
                pos.X += 5;
                SetConsoleCursorPosition(hCon,pos);
                printf("   ");
                pos.Y++;
                SetConsoleCursorPosition(hCon,pos);
                printf("   ");
                pos.Y++;
                SetConsoleCursorPosition(hCon,pos);
                printf("   ");
                break;
            }
        }
    }
    else
    {
        switch (tank->direction)
        {
            case NORTH:
            {
                pos.Y;
                SetConsoleCursorPosition(hCon,pos);
                printf("     ");
                break;
            }
            case SOUTH:
            {
                pos.Y += 5;
                SetConsoleCursorPosition(hCon,pos);
                printf("     ");
                break;
            }
            case WEST:
            {
                pos.X += 7;
                SetConsoleCursorPosition(hCon,pos);
                printf(" ");
                pos.Y++;
                SetConsoleCursorPosition(hCon,pos);
                printf(" ");
                pos.Y++;
                SetConsoleCursorPosition(hCon,pos);
                printf(" ");
                break;
            }
            case EAST:
            {
                pos.X;
                SetConsoleCursorPosition(hCon,pos);
                printf(" ");
                pos.Y++;
                SetConsoleCursorPosition(hCon,pos);
                printf(" ");
                pos.Y++;
                SetConsoleCursorPosition(hCon,pos);
                printf(" ");
                break;
            }
        }
    }
}

void moveTankWithDirection(Tank *tank, TankDirection direction) {



    if (tank->direction == direction) {
        tank->isFirstTurn = false;
    } else {
        tank->isFirstTurn = true;
    }
    ereasePreviousPosition(tank);
    if (tank->isFirstTurn) {
        tank->direction = direction;
    } else {
        switch (direction) {
            case SOUTH:
            if (isFreeWay(tank, direction)) {
                tank->position.Y--;
            }
            break;
            case NORTH:
            if (isFreeWay(tank, direction)) {
                tank->position.Y++;
            }
            break;
            case WEST:
            if (isFreeWay(tank, direction)) {
                tank->position.X--;
            }
            break;
            case EAST:
            if (isFreeWay(tank, direction)) {
                tank->position.X++;
            }
            break;
        }
        tank->direction = direction;
    }
    drawTank(tank);
}


int main()
{

    init();

    Tank tank;
    tank.direction = SOUTH;
    tank.position.X = 80;
    tank.position.Y = 48;
    tank.isFirstTurn = false;

    func_map(MAP);

    drawTank(&tank);

    while(true) {
        int key = getch();
        switch (key) {
            case UP:
            moveTankWithDirection(&tank, SOUTH);
            break;
            case DOWN:
            moveTankWithDirection(&tank, NORTH);
            break;
            case LEFT:
            moveTankWithDirection(&tank, WEST);
            break;
            case RIGHT:
            moveTankWithDirection(&tank, EAST);
            break;
            case SHOT:

            break;
            case EXIT:

            break;
        }
        drawTank(&tank);
    }

//    pthread_t threads[NUM_THREADS];
//      int rc;
//      long t;
//      for(t=0; t<NUM_THREADS; t++){
//         printf("In main: creating thread %ld\n", t);
//         rc = pthread_create(&threads[t], NULL, PrintHello, (void *)t);
//         if (rc){
//            printf("ERROR; return code from pthread_create() is %d\n", rc);
//            exit(-1);
//         }
//      }

//      /* Last thing that main() should do */
//      pthread_exit(NULL);
    return 0;
}
