#include <iostream>
#include "MacUILib.h"
#include "objPos.h"


using namespace std;

#define DELAY_CONST 100000
#define ROWS 10
#define COLS 20

bool exitFlag;
char board[ROWS][COLS];
int i;
int j;

objPos food;

void Initialize(void);
void GetInput(void);
void RunLogic(void);
void DrawScreen(void);
void LoopDelay(void);
void CleanUp(void);



int main(void)
{

    Initialize();

    while(exitFlag == false)  
    {
        GetInput();
        RunLogic();
        DrawScreen();
        LoopDelay();
    }

    CleanUp();

}


void Initialize(void)
{
    MacUILib_init();
    MacUILib_clearScreen();

    exitFlag = false;
}

void GetInput(void)
{
   
}

void RunLogic(void)
{
    
}

void DrawScreen(void)
{
    MacUILib_clearScreen();   
    for (i = 0; i < ROWS; i++){
        for(j = 0; j < COLS; j++){
            if(i == 0 || i == (ROWS - 1) || j == 0 || j == (COLS - 1)){
                board[i][j] = '#';
            }
            else
            {
                board[i][j] = ' ';
            }
        }
    }

    food.setObjPos(5, 5, 'a');
    food.getObjPos(food);
    board[food.x][food.y] = food.getSymbol(); // sets locations of all letters
    

    for(i = 0; i < ROWS; i++){ 
        for(j = 0; j < COLS; j++){
            MacUILib_printf("%c", board[i][j]);
            
        }
        MacUILib_printf("\n");
    }

}

void LoopDelay(void)
{
    MacUILib_Delay(DELAY_CONST); // 0.1s delay
}


void CleanUp(void)
{
    MacUILib_clearScreen();    
  
    MacUILib_uninit();
}
