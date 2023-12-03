#include "objPosArrayList.h"

objPosArrayList::objPosArrayList()
{
    aList = new objPos[ARRAY_MAX_CAP]; // 200 elements on the heap
    listSize = 0; // no valid element in the list upon startup
    arrayCapacity = ARRAY_MAX_CAP; //array capacity should be max
}

objPosArrayList::~objPosArrayList()
{
    delete[] aList;
}

int objPosArrayList::getSize()
{
    return listSize;
}

void objPosArrayList::insertHead(objPos thisPos)
{
    if(listSize < arrayCapacity){
        for(int i = listSize; i > 0; i--)
        {
            aList[i].setObjPos(aList[i-1]); 
        }

        aList[0].setObjPos(thisPos);

        listSize++;
    }
}

void objPosArrayList::insertTail(objPos thisPos)
{
    if(listSize < arrayCapacity){
        aList[listSize].setObjPos(thisPos);
        listSize++;
    }
}

void objPosArrayList::removeHead()
{
    if(listSize < arrayCapacity){
        for(int i = 0; i < listSize; i++)
        {
            aList[i].setObjPos(aList[i+1]); 
        }
        listSize--;
    }
}

void objPosArrayList::removeTail()
{
    if(listSize < arrayCapacity){
        listSize--;
    }
}

void objPosArrayList::getHeadElement(objPos &returnPos)
{
    returnPos.setObjPos(aList[0]);
}

void objPosArrayList::getTailElement(objPos &returnPos)
{
    returnPos.setObjPos(aList[listSize-1]);
}

void objPosArrayList::getElement(objPos &returnPos, int index)
{
    returnPos.setObjPos(aList[index]);
}