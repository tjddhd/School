#ifndef CHANGE_H
#define CHANGE_H

using namespace std;

class Change
{
  public:
    Change():total(0) {}
	
    Change(int amount):total(amount) {}
	
	bool can_pay();
	
	void coin_return();
	
	void set_total(int amount);
  private:
    int total;
};

#endif