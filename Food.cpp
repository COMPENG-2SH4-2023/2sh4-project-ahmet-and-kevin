#include "Food.h"


Food::Food(GameMechs* thisGMRef)
{
    MechsRef = thisGMRef;
    //objPos tempFoodIndex;
    foodPos.setObjPos(-1, -1, 'o');

    foodBucket = new objPosArrayList();
    foodBucket->insertHead(foodPos);

}

Food::~Food()
{
    delete foodBucket;
}

objPosArrayList* Food::getFoodBucket()
{
    return foodBucket;
    // return the reference to the playerPos arrray list
}
void Food::setFoodIndex(int l)
{
    foodIndex = l;
}
int Food::getFoodIndex()
{
    return foodIndex;
}
void Food::generateFood(objPosArrayList* blockOff){
    
    // generate random x and y coord and make sure they are not boarder or blockOff
    srand(time(NULL));
    // check x and y against 0 and boardSizeX and Y

    // remember, in objpos class you have an isPosEqual() method
    // Use this instead of comparing element by element
    int sizeX = MechsRef->getBoardSizeX();
    int sizeY = MechsRef->getBoardSizeY();
    int bitV[sizeY][sizeX] = {0};
    
    for(int b = 0; b < 5; b++)
    {
        char symRandChar;
        int repeat = 1;
        int past;
        if(b < 3){
            foodPos.symbol = 'o';
        } 
        else
        {
            while(repeat == 1)
            {
                symRandChar = 33 + rand() % 93;
                if(symRandChar != 111 && symRandChar != 32)
                {
                    foodPos.symbol = symRandChar;
                    break;
                }
            }
        }
        
        while (repeat == 1)
        {
            int yRand = 1 + rand() % (sizeY - 2);
            int xRand = 1 + rand() % (sizeX - 2);

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

        foodBucket->insertTail(foodPos);
    }

}

