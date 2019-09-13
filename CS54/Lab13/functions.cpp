//Thomas Dolan
//CS54, 6pm Tues
//Brian Goldman
//functions.cpp

//include statements
#include<iostream>
#include"functions.h"

using namespace std;

//default constructor
Vector3d::Vector3d()
{
  m_xCoord=0.0;
  m_yCoord=0.0;
  m_zCoord=0.0;
}

//custom constructor
Vector3d::Vector3d(double x, double y, double z)
{
  setXcoord(x);
  setYcoord(y);
  setZcoord(z);
}

//* operator overload
double Vector3d::operator*(const Vector3d& rhs) const
{
  return ( m_xCoord * rhs.m_xCoord + m_yCoord * rhs.m_yCoord +
           m_zCoord * rhs.m_zCoord);
}

//+ operator overload
Vector3d Vector3d::operator+(const Vector3d& rhs) const
{
  Vector3d temp;
  temp.m_xCoord = m_xCoord + rhs.m_xCoord;
  temp.m_yCoord = m_yCoord + rhs.m_yCoord;
  temp.m_zCoord = m_zCoord + rhs.m_zCoord;
  return temp;
}

//* operator overload for the friend function
Vector3d operator*(const double scalar, const Vector3d& rhs)
{
  Vector3d temp;
  temp.m_xCoord = scalar * rhs.m_xCoord;
  temp.m_yCoord = scalar * rhs.m_yCoord;
  temp.m_zCoord = scalar * rhs.m_zCoord;
  return temp;
}

//Assesor functions
double Vector3d::getXcoord() const
{
  return m_xCoord;
}

double Vector3d::getYcoord() const
{
  return m_yCoord;
}

double Vector3d::getZcoord() const
{
  return m_zCoord;
}

//Mutator functions
void Vector3d::setXcoord(const double x)
{
  m_xCoord = x;
}

void Vector3d::setYcoord(const double y)
{
  m_yCoord = y;
}

void Vector3d::setZcoord(const double z)
{
  m_zCoord = z;
}

//<< operator overload to output a vector
ostream& operator<<(ostream& oots, const Vector3d& vec)
{
  oots <<"["<<vec.getXcoord()<<", "<<vec.getYcoord()<<", "
       <<vec.getZcoord()<<"]";
  return oots;
}







