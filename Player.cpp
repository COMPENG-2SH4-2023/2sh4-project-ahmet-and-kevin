#include "Player.h"


Player::Player(GameMechs* thisGMRef)
{
    mainGameMechsRef = thisGMRef;
    myDir = STOP;

    // more actions to be included
    playerPos.setObjPos(mainGameMechsRef->getBoardSizeX() / 2, mainGameMechsRef->getBoardSizeY()/2, '@');

}


Player::~Player()
{
    // delete any heap members here
}

void Player::getPlayerPos(objPos &returnPos)
{
    returnPos.setObjPos(playerPos.x, playerPos.y, playerPos.symbol);
    // return the reference to the playerPos arrray list
}

// need game mechanism to get input
// method in game mechanism class that collectively check input 

void Player::updatePlayerDir()
{
    char input = mainGameMechsRef->getInput(); 
    switch(input)
    {
        case 'w':
            if (myDir != UP || myDir != DOWN){
                    myDir = UP;
                break;
            }
    
        case 'a':
            if (myDir != LEFT || myDir != RIGHT){
                    myDir = LEFT;
                break;
            }

        case 's':
            if (myDir != UP|| myDir != DOWN){
                    myDir = DOWN;
                break;
            }
        

        case 'd':
            if (myDir != LEFT || myDir != RIGHT){
                    myDir = RIGHT;
                break;
            }
    }
    
    // PPA3 input processing logic        
}

void Player::movePlayer()
{
    // PPA3 Finite State Machine logic

    switch (myDir)
    {
        case DOWN:
            playerPos.y++;
            break;
        case UP:
            playerPos.y--;
            break;
        case LEFT:
            playerPos.x--;
            break;
        case RIGHT:
            playerPos.x++;
            break;
        default:
            break;
    }
}

