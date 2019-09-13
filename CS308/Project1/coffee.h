#ifndef COFFEE_H
#define COFFEE_H

using namespace std;

class Coffee
{
  public:
    Coffee():white(false),sugar(false) {}
	
    Coffee(bool isWhite, bool hasSugar):white(isWhite),sugar(hasSugar) {}
	
  private:
    bool white;
	bool sugar;
};

#endif