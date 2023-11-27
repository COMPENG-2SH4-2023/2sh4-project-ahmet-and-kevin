#ifndef GAMEMECHS_H
#define GAMEMECHS_H

#include <cstdlib>
#include <time.h>

#include "objPos.h"
#include "objPosArrayList.h"

using namespace std;


class GameMechs
{
    // Construct the remaining declaration from the project manual.

    // Only some sample members are included here

    // You will include more data members and member functions to complete your design.

    private:
        objPos foodPos;
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
        void setInput(char this_input);
        void clearInput();
        void incrementScore();

        //Extra Methods

        // need to accept the player body array list
        // go through each array list element to make sure they are 
        // blocked off from random food location

        void generateFood(objPosArrayList* blockOff); // upgrade this somehow
        void getFoodPos(objPos &returnPos);
        

};

#endif