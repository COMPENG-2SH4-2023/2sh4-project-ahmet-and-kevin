#include "GameMechs.h"

GameMechs::GameMechs()
{
    boardSizeX=30;
    boardSizeY=15;
    exitFlag=false;
    input=0;//NULL
    loseFlag=false;
    incval=1;
}

GameMechs::GameMechs(int boardX, int boardY)
{
    boardSizeX=boardX;
    boardSizeY=boardY;
    exitFlag=false;
    input=0;//NULL
    loseFlag=false;
    incval=1;

}

GameMechs::GameMechs(int boardX, int boardY, int increment)
{
    boardSizeX=boardX;
    boardSizeY=boardY;
    exitFlag=false;
    input=0;//NULL
    loseFlag=false;
    incval=increment;

}

// do you need a destructor?


//Getter Definitionst
bool GameMechs::getExitFlagStatus()
{
    return exitFlag;
}
bool GameMechs::getLoseFlagStatus(){
    return getLoseFlagStatus;
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

void GameMech::setExitTrue()
{
    exitFlag=true;
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
    input=NULL;
}

void GameMechs::incrementScore(){
    score+=incval;
}




