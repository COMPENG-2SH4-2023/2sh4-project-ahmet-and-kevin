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
}

GameMechs::GameMechs(int boardX, int boardY)
{
    boardSizeX = boardX;
    boardSizeY = boardY;
    exitFlag = false;
    input = 0;
    score = 0;
    loseFlag = false;

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

void GameMechs::setInput()
{
    if(MacUILib_hasChar()){
        input = MacUILib_getChar();
    }else{
        clearInput();// Resets the input after every loop if no input was detected.
    } 
}

void GameMechs::clearInput()
{
    input=0;
}

void GameMechs::incrementScore(){
    score++;
}