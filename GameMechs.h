// Dictates the mechanics of the game such as board size, score, exit mechanic, input.

#ifndef GAMEMECHS_H
#define GAMEMECHS_H

#include <cstdlib>
#include <time.h>
#include "objPos.h"
#include "objPosArrayList.h"

using namespace std;


class GameMechs
{

    private:
        char input;
        bool exitFlag;
        bool loseFlag;
        
        int boardSizeX;
        int boardSizeY;
        int score;

    public:
        

        GameMechs();
        GameMechs(int boardX, int boardY);
        
        //Getters
        bool getExitFlagStatus();
        bool getLoseFlagStatus();
        char getInput();
        int getBoardSizeX();
        int getBoardSizeY();
        int getScore();

        //Setters
        void setExitTrue();
        void setLoseFlag();
        void setInput();
        void clearInput();
        void incrementScore();

};

#endif