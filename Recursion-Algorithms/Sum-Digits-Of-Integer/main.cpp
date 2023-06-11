#include <iostream>

using namespace std;

int digsum(int n);
//This function takes the every number in an integer and adds them up together
//Precondition: an integer.
//Postcondition: The sum of the numbers in an integer, or -1 of the input is negative

int main()
{
    int result,n;
    //"result" variable is to hold the returned value of the "digsum()" function.
    //"n" variable is to hold the value of the user input

    cout<<"Enter integer: ";
    //asks user for input

    cin>>n;
    //holds the user input

    result=digsum(n);
    //holds the returned value of the "digsum()" function.

    if(result==-1)//if sum is -1 then the program will print "Invalid input"
    {
        cout<<"Invalid input"<<endl;
    }
    else// if the sum is not -1 then the program will input the value of the "sum" variable
    {
    cout<<"The sum of "<<n<<"'s digits is "<<result<<endl;
    }

    return 0;
}

int digsum(int n)
{
    int sum;
    //"sum" variable is to hold the first number in an integer,
    //and to be added to the returned value of the recurred "digsum()" function

    if(n<0)//if the input is less than 0 then the function return -1
    {
        return -1;
    }
    else if(n<10)//if the input is less than 10 then the function returns the input again
    {
        return n;
    }
    else
    {
      sum=n%10;//"sum" variable holds the first number in the input
      sum+=digsum(n/10);//"sum" variable is added to the returned value of the "digsum()" function
      //with the rest of the integer except the first one as the new input of the function
      return sum;//function returns the "sum" value
    }
}
