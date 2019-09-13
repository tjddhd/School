//Thomas Dolan
//CS54, 6pm tues
//Brian Goldman
//functions.h

#ifndef FUNCTIONS_H
#define FUNCITONS_H

#include<iostream>

using namespace std;

//vector class
class Vector3d
{
  public:
    //Desc: Default constructor
    //Pre:  none
    //Post: creates a default Vector3d variable 
    Vector3d();
 
    //Desc: custom constructor
    //Pre:  inputs are doubles
    //Post: creates a custom Vector3d variable
    Vector3d(double x, double y, double z);

    //Desc: overloads the * operator
    //Pre:  vectors have values assigned in all member variables
    //Post: vectors have been multiplied together
    double operator*(const Vector3d& rhs) const;

    //Desc: overloads the + operator
    //Pre:  vectors have values assigned in all member variables
    //Post: vectors ahve been added together
    Vector3d operator+(const Vector3d& rhs) const;

    //Desc: friend function that overloads the * operator
    //pre:  vector has values assigned in all member varaibles
    //Post: scalar has been multiplied throughthe vector
    friend Vector3d operator*( const double scalar, const Vector3d& rhs);
  
    //Desc: calls the values of m_xCoord
    //Pre: none
    //Post: m_xCoord has been returned
    double getXcoord() const;

    //desc: calls the value of m_yCoord
    //Pre:  none
    //Post: m_yCoord has been returned
    double getYcoord() const;

    //desc: calls the value of m_zCoord
    //Pre:  none
    //Post: m_zCoord has been returned
    double getZcoord() const;
   
    //desc: sets the value of m_xCoord
    //Pre:  correct type inputted
    //Post: m_xCoord has been assigned
    void setXcoord(const double x);
  
    //desc: sets the value of m_yCoord
    //Pre:  correct type inputted
    //Post: m_yCoord has been assigned
    void setYcoord(const double y);
  
    //desc: sets the value of m_zCoord
    //Pre:  correct type inputted
    //Post: m_zCoord has been assigned
    void setZcoord(const double z);

  private:
    double m_xCoord, m_yCoord, m_zCoord;
};

//Desc: overloads the << operator so as to output a vector
//Pre:  iostream is open
//Post: vector has been outputted
ostream& operator<<(ostream& oots, const Vector3d& vec);

#endif

