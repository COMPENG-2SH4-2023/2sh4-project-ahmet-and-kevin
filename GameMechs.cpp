#include "GameMechs.h"
#include "MacUILib.h"

GameMechs::GameMechs()
{
    boardSizeX = 30;
    boardSizeY = 15;
    exitFlag = false;
    input = 0;
    loseFlag=false;
    incval=1;
}

GameMechs::GameMechs(int boardX, int boardY)
{
    boardSizeX=boardX;
    boardSizeY=boardY;
    exitFlag=false;
    input=0;
    loseFlag=false;
    incval=1;
}

// do you need a destructor?


//Getter Definitionst
bool GameMechs::getExitFlagStatus()
{
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
    input=0;
}

void GameMechs::incrementScore(){
    score+=incval;
}




