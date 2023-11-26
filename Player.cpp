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

    if (playerPos.x < 1){
        playerPos.x = (mainGameMechsRef->getBoardSizeX() - 2);
    }
    if (playerPos.x >= (mainGameMechsRef->getBoardSizeX() - 1)){
        playerPos.x = 1;
    }
    if (playerPos.y >= (mainGameMechsRef->getBoardSizeY() - 1)){
        playerPos.y = 1;
    }

    if (playerPos.y < 1){
        playerPos.y = mainGameMechsRef->getBoardSizeY() - 2;
    }
}

