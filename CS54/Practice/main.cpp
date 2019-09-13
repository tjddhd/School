//tjddhd
//STUUUUUUUFFFFFFF

#include<math.h>
#include<iostream>

using namespace std;

int main()
{
  float answer, result;
  bool done = false;
  for(answer = 1; !done; answer++)
   {
    result = pow(sqrt(74844*answer), 2);
    if(result == 74844*answer)
      done = true;
   }
   cout<<answer<<endl;
}


