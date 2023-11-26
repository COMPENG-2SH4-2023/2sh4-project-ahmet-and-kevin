#include <iostream>
#include "MacUILib.h"
#include "objPos.h"
#include "GameMechs.h"
#include "Player.h"


using namespace std;

#define DELAY_CONST 100000
#define ROWS 15
#define COLS 30

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
    // yo since updatePlayerDir calls getInput alr, 
    // calling it here would cause double input 
    // so thats why this is section is empty 
}

void RunLogic(void)
{
    myPlayer->updatePlayerDir(); 
    myPlayer->movePlayer();
    
    myGM->getExitFlagStatus();
    myGM->clearInput();
}

void DrawScreen(void)
{
    MacUILib_clearScreen();   
    int i;
    int j;
    char board[ROWS][COLS];
    objPos tempPos;
    myPlayer->getPlayerPos(tempPos);
    

    for (i = 0; i < ROWS; i++){
        for(j = 0; j < COLS; j++){
            if(i == 0 || i == (ROWS - 1) || j == 0 || j == (COLS - 1)){
                board[i][j] = '#';
            }
            else if ((tempPos.x % (COLS - 1)) == j && (tempPos.y % (ROWS - 1)) == i)
            {

                board[i][j] = tempPos.symbol;
            }
            else
            {
                board[i][j] = ' ';
            }
        }
    }

    for(i = 0; i < ROWS; i++){ 
        for(j = 0; j < COLS; j++){
            MacUILib_printf("%c", board[i][j]);
            
        }
        MacUILib_printf("\n");
    }

    MacUILib_printf("BoardSize: %dx%d, Player Pos: <%d, %d> + %c\n", myGM->getBoardSizeX(), 
                                                                    myGM->getBoardSizeY(),
                                                                    tempPos.x, tempPos.y, tempPos.symbol );
     MacUILib_printf("Press ESC to quit");
}

void LoopDelay(void)
{
    MacUILib_Delay(DELAY_CONST); // 0.1s delay
}


void CleanUp(void)
{
    MacUILib_clearScreen();    
  
    MacUILib_uninit();

    // remove heap instance 
    delete myGM;
    delete myPlayer;
}
