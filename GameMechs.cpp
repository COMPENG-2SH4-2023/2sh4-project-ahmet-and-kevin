#include "GameMechs.h"
#include "MacUILib.h"




GameMechs::GameMechs()
{
    input = 0;
    score = 0;
    exitFlag = false;
    loseFlag = false;
    boardSizeX = 30;
    boardSizeY = 15;

    foodPos.setObjPos(-1, -1, 'o'); // Initialize foodPos outside game board
}

GameMechs::GameMechs(int boardX, int boardY)
{
    boardSizeX = boardX;
    boardSizeY = boardY;
    exitFlag = false;
    input = 0;
    score = 0;
    loseFlag = false;

    foodPos.setObjPos(-1, -1, 'o'); // Initialize foodPos outside game board

}

// do you need a destructor?

//Getter Definitionst
bool GameMechs::getExitFlagStatus()
{
    if(input == 27){
        exitFlag = true;
    }
    return exitFlag;
}

bool GameMechs::getLoseFlagStatus(){
    return loseFlag;
}

char GameMechs::getInput()
{
    if(MacUILib_hasChar()){
        input = MacUILib_getChar();
    }else{
        clearInput();// Resets the input after every loop if no input was detected.
    }  
    return input;
}

int GameMechs::getBoardSizeX()
{
    return boardSizeX;

}

int GameMechs::getBoardSizeY()
{
    return boardSizeY;
}

int GameMechs::getScore(){
    return score;
}



//Setters

void GameMechs::setExitTrue()
{
    
    exitFlag = true;
}

void GameMechs::setLoseFlag()
{
    
    loseFlag=true;
}

void GameMechs::setInput(char this_input)
{
    input=this_input;
}

void GameMechs::clearInput()
{
    input=0;
}

void GameMechs::incrementScore(){
    score++;
}

void GameMechs::generateFood(objPosArrayList* blockOff){
    // generate random x and y coord and make sure they are not boarder or blockOff
    srand(time(NULL));
    // check x and y against 0 and boardSizeX and Y

    // remember, in objpos class you have an isPosEqual() method
    // Use this instead of comparing element by element
    
    int repeat = 1;
    while (repeat == 1)
    {
        int yRand = 1 + rand() % (boardSizeY - 2);
        int xRand = 1 + rand() % (boardSizeX - 2);

        for(int i = 0; i < blockOff->getSize(); i++)
        {
            objPos tempBody;
            blockOff->getElement(tempBody, i);

            if(tempBody.x == xRand && tempBody.y == yRand)
            {
                repeat = 1; 
                break;

            } else {
                foodPos.setObjPos(xRand, yRand, foodPos.symbol);
                repeat = 0;
            }
        }
    }
    
    

}

void GameMechs::getFoodPos(objPos &returnPos){
    returnPos.setObjPos(foodPos.x, foodPos.y, foodPos.symbol);
}



