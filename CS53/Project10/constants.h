//TEEEEEEJJJJJJ DOLANDOLANDOLANDOLANDOLAN
//DOCUMENTATION

#ifndef CONSTANTS_H
#define CONSTANTS_H

using namespace std;

#include<iostream>
#include<stdlib.h>
#include<time.h>

//Dragon default constants
const int DEFAULT_V = 17;
const int DEFAULT_ARM = 1;
const int DEFAULT_MAJESTY = 2;
const bool DEFAULT_WING = true;
const string DEFAULT_DRAGON_NAME = "Trogdor";

//Peasant default constants
const string DEFAULT_PEASANT_NAME = "John Q. Example";

int temp = (random() % 121);
while( temp < 90)
{
  temp = random() % 121;
}

const int DEFAULT_WEIGHT = temp;
const bool DEFAULT_FIRE = false;
const bool DEFAULT_ALIVE = true;

//Miscellaneous const stuffz
const int DEFAULT_HUTS = 1;
const int DEFAULT_HUT_GEN = 15;
const int DEFAULT_EAT_CHANCE = 33;
const int DEFAULT_LOW_MAJ_BURN = 50;
const int DEFAULT_MID_MAJ_BURN = 70;
const int DEFAULT_HIGH_MAJ_BURN = 90;
const int DEFAULT_DEATH_WEIGHT = 50;
const int DEFAULT_X = 100;
const int DEFAULT_Y = 100;
const int MAX_ARRAY_SIZE = 100;


#endif



