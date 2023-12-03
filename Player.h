// This is the class that controls the movement of player and its interaction with food

#ifndef PLAYER_H
#define PLAYER_H

#include "GameMechs.h"
#include "objPos.h"
#include "objPosArrayList.h"
#include "Food.h"

class Player
{
    public:
        enum Dir {UP, DOWN, LEFT, RIGHT, STOP};  // This is the direction state

        Player(GameMechs* thisGMRef, Food* FoodRef);
        ~Player();

        objPosArrayList* getPlayerPos(); 
        void updatePlayerDir();
        void movePlayer();
        bool checkFoodConsumption();
        void increasePlayerLength();       
        bool checkSelfCollision();

    private:
        objPosArrayList *playerPosList;       
        enum Dir myDir;

        GameMechs* mainGameMechsRef;
        Food* mainFoodRef;
};

#endif