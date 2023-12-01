#ifndef FOOD_H
#define FOOD_H

#include <cstdlib>
#include <time.h>

#include "objPos.h"
#include "objPosArrayList.h"
#include "GameMechs.h"

using namespace std;

class Food
{
    private:
        objPos foodPos;
        GameMechs* MechsRef;
 
    public:
        Food(GameMechs* thisGMRef);
        void generateFood(objPosArrayList* blockOff); // upgrade this somehow
        void getFoodPos(objPos &returnPos);   
};
#endif