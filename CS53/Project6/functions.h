//Teej-kun Dolan-san
//Project 6
//functions.h

//Guard statements
#ifndef FUNCTIONS_H
#define FUNCITONS_H

//Desc: Greets the user
//Pre:  None
//Post: Displays greeting message
void greeting();

//Desc: Displays the menu
//Pre:  Computer-box turned on (None)
//Post: Returns menu choice
int menu();

//Desc: Evaluates the selected menu option and then continues through the program
//Pre:  Menu selection, first and second choice bools, studentID, assets, and aid
//Post: Will calculate the aid for the selected student
void evaluator(int a, bool& x, bool& y, int& stuID, int& assets, int& aid);

//Desc: Evaluates the max of 3 inputted ints
//Pre:  3 ints, nonnegative
//Post: Returns max number
int max(int a, int b, int c);

//Desc: Says goodbye to the user
//Pre:  none
//Post: Displays signoff message
void signoff();


#endif

