#include <iostream>
#include "MacUILib.h"
#include "objPos.h"
#include "objPosArrayList.h"
#include "GameMechs.h"
#include "Player.h"
#include "Food.h"

using namespace std;

#define DELAY_CONST 100000

// Declaring
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

    objPosArrayList* playerBody = myPlayer->getPlayerPos();
    objPosArrayList* foodBucket = myFood->getFoodBucket();

    myFood->generateFood(playerBody); // initalizes food 
}
void GetInput(void)
{
    // MovePlayer gets input already
    myGM->setInput();
}

void RunLogic(void)
{
    myPlayer->updatePlayerDir(); 
    myPlayer->movePlayer(); 

    if(myPlayer->checkSelfCollision() == true) 
    {
        myGM->setLoseFlag();
        myGM->setExitTrue();
    }

    if(myPlayer->checkFoodConsumption() == true){
        // checking which "food" you ate
        if(myFood->getFoodIndex() < 4) // Increase score by 1 and length by 1
        {
            myPlayer->increasePlayerLength();
            myGM->incrementScore();
        }
        else if(myFood->getFoodIndex() == 4) // Increase score by 10 but no length increase
        {
            for(int s = 0; s < 10; s++)
            {
                myGM->incrementScore();
            }
        }
        else if(myFood->getFoodIndex() == 5) // Increase score by 5 and length by 5 
        {
            for(int s = 0; s < 5; s++)
            {
                myGM->incrementScore();
            }

            for(int s = 0; s < 5; s++)
            {
                myPlayer->increasePlayerLength();
            }           
        }

        objPosArrayList* playerBody = myPlayer->getPlayerPos();
        myFood->generateFood(playerBody); // if food is picked up, all food is regenerated
    }

    myGM->getExitFlagStatus(); // checks if input is exit key
                                // if so, exit the code
    myGM->clearInput();
}

void DrawScreen(void)
{
    MacUILib_clearScreen();   

    bool drawn; 
    objPos tempBody;
    objPos tempFoodPos;
    objPosArrayList* playerBody = myPlayer->getPlayerPos();
    objPosArrayList* foodBucket = myFood->getFoodBucket();

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

            for(int l = 0; l < foodBucket->getSize(); l++)
            {
                foodBucket->getElement(tempFoodPos, l);
                if(tempFoodPos.x == j && tempFoodPos.y == i)
                {
                    MacUILib_printf("%c", tempFoodPos.symbol);
                    drawn = true;
                }
            }

            if(drawn) continue;
            // if letter was drawn, don't draw anything below

            // draw border
            if(i == 0 || i == (myGM->getBoardSizeY() - 1)|| j == 0 || j == (myGM->getBoardSizeX() - 1))
            {
                MacUILib_printf("%c", '#');
            }
            else 
            {
                MacUILib_printf("%c", ' ');
            }
            
        }
        MacUILib_printf("\n");
    }

    MacUILib_printf("Press ESC to quit\n");
    MacUILib_printf("Normal Food = 'o': +1 score, +1 length \n");
    MacUILib_printf("Mystery Food = not 'o': (+10 score, +0 length) OR (+5 score, +5 length) \n");
    MacUILib_printf("Score: %d\n", myGM->getScore());
    
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
    delete myFood;
}
