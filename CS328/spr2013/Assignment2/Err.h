///////////////////////////////////////////////////////////////////////////////
// Programmer :  Thomas Dolan
// Assignment :  Program 2
//
// Instructor :  Clayton Price
// Course     :  CS328
// Semester   :  Spring 2013
///////////////////////////////////////////////////////////////////////////////

class Err
{
	public:
		RangeErr();
		void badSubscr();
	private:
		int subscr;
};

class SizeErr
{
	public:
		SizeErr();
		void badSubscr();
	private:
		int subscr;
};