#include <iostream>

using namespace std;

int smallfact(int );
//Divides the input by a divisor that is incremented if the result is a decimal number.
//Precondition: an integer.
//Postcondition: The first divisor,which is an integer, that divides the input without having a
//decimal number as a result.

void primefact(int );
//Calls the function smallfact() then compares the returned value of that function (fact) with\
//the result of dividing the input by "fact".
//Precondition: an integer.
//Postcondition: The function will either print an "Invalid output" message if the input is less than
//or equal 0. Or will print the prime factors in ascending order.
int main()
{
    int x;
    //"x" is to carry the input value.
    cout << "Enter integer: ";
    cin>>x;

    if(x<=0)
    {
        cout<<"Invalid input"<<endl;
    }
    else
    {
    cout<<"The prime factors of "<<x<<" are: ";
    primefact(x);//calls primefact() function.
    }
    return 0;
}

int smallfact(int x)
{
  int divisor=2;// To divide the input.
  bool flag=false;// Flag the loop when to stop.
// And starting state for the flag is false to keep the loop going at first

  do//a do while loop to start the statement first then compare after that.
  {
     if(x%divisor==0)//if the the divisor divides the input and the result is an integer
     {
         flag=true;//flag becomes true thus stopping the loop
     }
     else//if the divisor divides the input and the result is a decimal
     {
         divisor++;//increments the divisor to divide the input by a new value
     }
  }while(flag==false);//loop will continue as long as "flag" is false

    return divisor;//returns the first advisor that is able to break the loop
}

void primefact(int x)
{
    int fact,divided;
    //"fact" is to hold the smallest factor.
    //divided is to hold the input divided by the smallest factor.

    fact=smallfact(x);//fact holds the returned value from the function "smallfact()".
    divided=x/fact;//divided holds the value of dividing the input by "fact".

    if(fact==x||fact==divided)//if "fact" is the same as the input that means there are no prime factors.
        //And if "fact" is the same as "divided" means
        // that the last two prime factors are the same so we print it once.
    {
        cout<<fact<<endl;
    }

    else
    {
      cout<<fact<<" ";//print the smallest factor we have in this function.
      primefact(divided);//recur the same function but with the "divided" variable as the input.
    }

}
