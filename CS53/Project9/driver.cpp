//TEEEEEEEEJJJJJJJJJ Odlan
//CS53, Seciton 12
//Matt Nuckolls
//Project 9: the set-up for Project 10
//driver.cpp

//include statements
#include<iostream>
#include<time.h>
#include<stdlib.h>
#include"dragon.h"
#include"peasant.h"

//main function with very basic test of classes
int main()
{
  srandom(time(NULL));

  Dragon smaug;
  Peasant price;

  price.eat(price);
  price.starve(price);
  price.starve(price);
  price.starve(price);

  price.print(price);

  smaug.burninate(price, 2);

  smaug.print(smaug);

  return 0;
}



