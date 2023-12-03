#include "Player.h"

Player::Player(GameMechs* thisGMRef, Food* FoodRef)
{
    mainGameMechsRef = thisGMRef;
    mainFoodRef = FoodRef;
    myDir = STOP;

    // more actions to be included
    objPos tempPos;
    tempPos.setObjPos(mainGameMechsRef->getBoardSizeX() / 2, mainGameMechsRef->getBoardSizeY()/2, '@');

    playerPosList = new objPosArrayList();
    playerPosList->insertHead(tempPos);

}

Player::~Player()
{
    // delete any heap members here
    delete playerPosList;
}

objPosArrayList* Player::getPlayerPos()
{
    return playerPosList;
    // return the reference to the playerPos arrray list
}

// need game mechanism to get input
// method in game mechanism class that collectively check input 

void Player::updatePlayerDir()
{
    char input = mainGameMechsRef->getInput(); 

    switch(input) // changes player direction based on input
    {
        case 'w':
            if (myDir != DOWN){
                    myDir = UP;
                break;
            } else {
                break;
            }
    
        case 'a':
            if (myDir != RIGHT){
                    myDir = LEFT;
                break;
            } else {
                break;
            }

        case 's':
            if (myDir != UP){
                    myDir = DOWN;
                break;
            } else {
                break;
            }
        

        case 'd':
            if (myDir != LEFT){
                    myDir = RIGHT;
                break;
            } else {
                break;
            }
        input = 0;
    }
    
    // PPA3 input processing logic        
}

void Player::movePlayer()
{
    // PPA3 Finite State Machine logic

    objPos currentHead; // holding the pos information of current head
    playerPosList->getHeadElement(currentHead);

    switch (myDir)
    {
        case DOWN:
            currentHead.y++;
            if(currentHead.y >= mainGameMechsRef->getBoardSizeY() - 1){ // Wraparound logic
                currentHead.y = 1;
            }
            break;
        case UP:
            currentHead.y--;
            if(currentHead.y <= 0){ // Wraparound logic
                currentHead.y = mainGameMechsRef->getBoardSizeY() - 2; 
            }
            break;
        case LEFT:
            currentHead.x--;
            if(currentHead.x <= 0){ // Wraparound logic
                currentHead.x = mainGameMechsRef->getBoardSizeX() - 2;
            }
            break;
        case RIGHT:
            currentHead.x++;
            if(currentHead.x >= mainGameMechsRef->getBoardSizeX() - 1){ // Wraparound logic
                currentHead.x = 1;
            }
            break;
        case STOP:
        default:
            break;
    }

    // new current head should be inserted to the head of the list
    playerPosList->insertHead(currentHead);
    //then, remove tail
    playerPosList->removeTail();
}

bool Player::checkFoodConsumption()
{
    objPos tempHead;
    objPos tempFood;

    objPosArrayList* foodBucket = mainFoodRef->getFoodBucket();
    playerPosList->getHeadElement(tempHead);

    for(int l = 0; l < foodBucket->getSize(); l++) // checks all food positions.
                                                    // if any food position matches player head position, return true 
    {
        foodBucket->getElement(tempFood, l);
        if(tempFood.isPosEqual(&tempHead))
        {
            for(int g = 0; g < 5; g++) // empties food bucket
            {
                foodBucket->removeTail();
            }
            mainFoodRef->setFoodIndex(l); // determines which type of food the player hit
            return true;
        }
    }
    return false;

}

void Player::increasePlayerLength()
{
    objPos tempHead;
    playerPosList->getHeadElement(tempHead);
    playerPosList->insertHead(tempHead);
}

bool Player::checkSelfCollision()
{
    objPos tempHead;
    objPos tempBody;
    playerPosList->getHeadElement(tempHead);
    for(int i = 1; i < playerPosList->getSize(); i++)
    {
        playerPosList->getElement(tempBody, i+1);
        if(tempHead.isPosEqual(&tempBody))
        {
            return true;
        }
    }
    
    return false;
}