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
        objPosArrayList* foodBucket;
        int foodIndex;
 
    public:
        Food(GameMechs* thisGMRef);
        ~Food();

        void setFoodIndex(int l);
        int getFoodIndex();

        void generateFood(objPosArrayList* blockOff); // upgrade this somehow
        objPosArrayList* getFoodBucket(); 
        
};
#endif