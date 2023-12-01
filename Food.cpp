#include "Food.h"


Food::Food(GameMechs* thisGMRef)
{
    MechsRef = thisGMRef;
    foodPos.setObjPos(-1, -1, 'o');
}
void Food::generateFood(objPosArrayList* blockOff){
    
    // generate random x and y coord and make sure they are not boarder or blockOff
    srand(time(NULL));
    // check x and y against 0 and boardSizeX and Y

    // remember, in objpos class you have an isPosEqual() method
    // Use this instead of comparing element by element
    
    int repeat = 1;

    int sizeX = MechsRef->getBoardSizeX();
    int sizeY = MechsRef->getBoardSizeY();

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
    
    

}

void Food::getFoodPos(objPos &returnPos){
    returnPos.setObjPos(foodPos.x, foodPos.y, foodPos.symbol);
}