#include <iostream>
#include "MacUILib.h"
#include "objPos.h"
#include "GameMechs.h"
#include "Player.h"


using namespace std;

#define DELAY_CONST 100000
#define ROWS 15
#define COLS 30

bool exitFlag;
char board[ROWS][COLS];
int i;
int j;

objPos food;
GameMechs *myGM; 
Player *myPlayer;


void Initialize(void);
void GetInput(void);
void RunLogic(void);
void DrawScreen(void);
void LoopDelay(void);
void CleanUp(void);



int main(void)
{

    Initialize();

    while(myGM->getExitFlagStatus() == false)  
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

    myGM = new GameMechs(30, 15);
    myPlayer = new Player(myGM);
}

void GetInput(void)
{

}

void RunLogic(void)
{
    myPlayer->updatePlayerDir(); // Gets input already
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

    objPos tempPos;
    myPlayer->getPlayerPos(tempPos);

    MacUILib_printf("BoardSize: %dx%d, Player Pos: <%d, %d> + %c\n", myGM->getBoardSizeX(), 
                                                                    myGM->getBoardSizeY(),
                                                                    tempPos.x, tempPos.y, tempPos.symbol );
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
