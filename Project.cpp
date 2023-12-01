#include <iostream>
#include "MacUILib.h"
#include "objPos.h"
#include "objPosArrayList.h"
#include "GameMechs.h"
#include "Player.h"
#include "Food.h"



using namespace std;

// changed delay to 10000 from 100000
#define DELAY_CONST 1000000


GameMechs *myGM; 
Player *myPlayer;
Food *myFood;




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
    myFood = new Food(myGM);
    myPlayer = new Player(myGM, myFood);

    // this is a makeshift setup so i dont have to touch generate item yet
    objPosArrayList* playerBody = myPlayer->getPlayerPos();
    //myGM->generateFood(playerBody);
    myFood->generateFood(playerBody);

}

void GetInput(void)
{

}

void RunLogic(void)
{
    myPlayer->updatePlayerDir(); 
    myPlayer->movePlayer();

    if(myPlayer->checkFoodConsumption() == true){
        myPlayer->increasePlayerLength();
        myGM->incrementScore();
        objPosArrayList* playerBody = myPlayer->getPlayerPos();
        //myGM->generateFood(playerBody);
        myFood->generateFood(playerBody);


    }

    if(myPlayer->checkSelfCollision() == true)
    {
        myGM->setLoseFlag();
        myGM->setExitTrue();

    }

    myGM->getExitFlagStatus();
    myGM->clearInput();
}

void DrawScreen(void)
{
    MacUILib_clearScreen();   

    bool drawn; 
    objPosArrayList* playerBody = myPlayer->getPlayerPos();
    objPos tempBody;

    objPos tempFoodPos;
    //myGM->getFoodPos(tempFoodPos);
    //myFood->generateFood(playerBody);
    myFood->getFoodPos(tempFoodPos);


    for (int i = 0; i < myGM->getBoardSizeY(); i++)
    {
        for(int j = 0; j < myGM->getBoardSizeX(); j++)
        {
            drawn = false;
            
            // iterate through every element in the list
            for(int k = 0; k < playerBody->getSize(); k++)
            {
                playerBody->getElement(tempBody, k);

                if(tempBody.x == j && tempBody.y == i)
                {
                    MacUILib_printf("%c", tempBody.symbol);
                    drawn = true;
                    break;
                }
            }

            if(drawn) continue;
            // if player body was drawn, don't draw anything below
            
            // draw border
            if(i == 0 || i == (myGM->getBoardSizeY() - 1)|| j == 0 || j == (myGM->getBoardSizeX() - 1))
            {
                MacUILib_printf("%c", '#');
            }
            else if (j == tempFoodPos.x && i == tempFoodPos.y)
            {
                MacUILib_printf("%c", tempFoodPos.symbol);
            }
            else 
            {
                MacUILib_printf("%c", ' ');
            }
            
        }
        MacUILib_printf("\n");
    }

    MacUILib_printf("Press ESC to quit\n");
    MacUILib_printf("Score: %d\n", myGM->getScore());
    MacUILib_printf("Player Positions:\n");
    for(int l = 0; l < playerBody->getSize(); l++)
    {
        playerBody->getElement(tempBody, l);
        MacUILib_printf("<%d, %d> ", tempBody.x, tempBody.y);
    }
    MacUILib_printf("\n");
    MacUILib_printf("Food Pos: <%d, %d>\n", tempFoodPos.x, tempFoodPos.y);
    

}

void LoopDelay(void)
{
    MacUILib_Delay(DELAY_CONST); // 0.1s delay
}


void CleanUp(void)
{
    MacUILib_clearScreen();    

    if(myGM->getLoseFlagStatus() == true){
        MacUILib_printf("You Lose! You ate yourself! \n");
    } else {
        MacUILib_printf("You Quit! You left the game! \n");

    }

    MacUILib_uninit();

    // remove heap instance 
    delete myGM;
    delete myPlayer;
}
