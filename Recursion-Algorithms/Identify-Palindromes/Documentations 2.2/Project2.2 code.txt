#include <iostream>
#include<string>
using namespace std;

bool pal(char a[],int low,int high);
// A function that compares the first value of an array with the last value of that array
//Precondition:An array, two integers with low<high.
//Postcondition: returns a boolean value of true or false
int main()
{
    int low=0,high;
    //"Low" is initialized with 0 because all arrays start with 0
    //"high" to hold the number of the characters that the user inputs
    char a[20];
    //the array that will hold each character the user inputs
    bool result;
    //"result" is to know if the outcome of the function "pal()" is a palindrome number or not
    string candi;
    //"candi" is to hold the sting value of the user input.

    cout << "Enter candidate: ";
    //asks user for input
    cin>>candi;
    high=candi.length();
    //the number of characters that the user inputs is held in the "high" variable using the ".length()" function.

    for(int i=0;i<high;i++)//loop to assign each character to the array.
    {
        a[i]=candi.at(i);//each character is assign to the array using the ".at()" function.
    }
    high--;//decrement the value of high because it has an additional value that holds trash code.
    result=pal(a,low,high);//calls the "pal()" function and holds the returned value of that function to the "result" variable

    if(result==true)//if the result true then the input is a palindrome.
    {
        cout<<"The string is a palindrome."<<endl;
    }
    else// if not then the input is not a palindrome
    {
        cout<<"The string is not a palindrome."<<endl;
    }
    return 0;
}

bool pal(char a[],int low, int high)
{
    bool flag=true;
    //"flag" variable is to be returned as a signal for identifying the input as a palindrome or not,
    //with the initial value as true
    if(low==high||low>high)//if the value of the "low" input is the same as the value of the "high" input,
        //or the value of the "low" input is larger than the value of the "high" input,
        //then this means we went through all the characters and it is time to return the "flag" variable.
    {
        return flag;
    }
    else//if the past conditions are not true
    {
    if(a[low]!=a[high])//if the value of the array at location "low" is not the same as the variable as the location "high"
    //then the value of the "flag" variable is false and is returned
    {
        flag=false;
        return flag;
    }
    else if(a[low]==a[high])//if the value of the array at the location "low" is the same as the variable
    //at the location "high" then we increment the value of the "low" variable and decrement  the value
    //of the "high" variable to decrease the number of character we are comparing.
    //then we recur the "pal()" function and hold its value in the "flag" variable.
    //Then the "flag" variable is returned.
    {
        low++;
        high--;
        flag=pal(a,low,high);
        return flag;

    }
    }

}
