//CSCI 301
//Computer Science

//File: Project1.2.cbp

//This program merges two sorted sequences taking each sequence and adding them to a third sorted sequence.
//This program reads two input files, that the user chooses, then adds them to an initial array.
//Then, the array is sorted ascendingly in order to start moving the integers in the initial array to the new and final array.
//During this process, the program compares an integer from the initial array with the integers in the final array,
//if the program found a similar integer in the final array it moves to the next number,
//if no similar integer was found then the program adds this integer to the final array and then it moves on.
//Finally, after successfully moving all the integers to the final array,
//the program shows the output on the compiler then writes the final array to an output folder.
#include <iostream>
#include <fstream>

using namespace std;

bool searchSim(int[],int,int );
//Searches for a similar integer within an array.
//Precondition: An array, an integer for the size and an integer to be searched for.
//postcondition: A boolean value of true or false.
void swap(int&,int&);
//Swaps two values between two variables.
//Precondition: Two integer variables.
//Postcondition: values of two variables have been swapped.
void sort(int[],int);
//Sorts values of an array in an ascending order.
//Precondition: An array and an integer variable for the size of the array.
//Postcondition: Values of the array have been sorted in ascending order.
int main()
{
    int temp;//Temporary variable for holding a value from the input file to the array.
    int counter=0;//Keeps track of how many integers are there in both input files.
    int allArr[100];//Initial array to hold integers from both input files.
    int finalArr[100];//Final array to hold sorted and non-repeated integers.
    int distinctcount=0;//Keeps track of how many unrepeated integers are there.
    bool result=false;//To hold the boolean value of the search function.
    char fileName[80];//To hold the input file name.
    ifstream infileValues;//To hold the first input file.
    ifstream infileNumbers;//To hold the second input file.
    fstream outFile;//To hold the output file where we will write the results on.

    cout<<"Enter the first file name: ";//ask user for the first file name.
    cin>>fileName;//holds the name of the first input file.
    infileValues.open(fileName);//opens first input file.
    cout<<"Enter the second file name: ";//asks user for the second file name.
    cin>>fileName;//holds the name of the second file.
    infileNumbers.open(fileName);//opens second input file.
    cout<<"Enter the name of the ouput file: ";
    cin>>fileName;
    outFile.open(fileName);//opens output file.

   while(!infileValues.eof())//starts loop with the condition that the first input file still has data on it.
   {
       infileValues>>temp;//holds the value of integer in temp variable.
       allArr[counter]=temp;//assigns that value to the array.
       counter++;//increments counter variable to move to the next array.
   }

   while(!infileNumbers.eof())//starts loop with the condition that the second input file still has data on it.
   {
       infileNumbers>>temp;//holds the value of integer in temp variable.
       allArr[counter]=temp;//assigns that value to the array.
       counter++;//increments counter variable to move to the next
   }

   sort(allArr,counter);//Sorts the values of the array in ascending order.
   for(int i=0;i<counter;i++)//loop for locating repeated integers,
//and moving the integers from the initial array to the final array
      {
      result=searchSim(finalArr,distinctcount+1,allArr[i]);//the search function is called to locate repeated integers
//within the initial array,
// and returns a boolean value to the result variable
      if(result==false)//if the search function did not find a similar integer in the initial array then...
      {
          finalArr[distinctcount]=allArr[i];//value of initial array is assign to the final array
          distinctcount++;//increments distinct counter variable to move to the next final array location
      }

   }

    for(int i=0;i<distinctcount;i++)//loop to output the results in the terminal and the output file
    {
        cout<<finalArr[i]<<endl;//writes the output in the terminal
        outFile<<finalArr[i]<<endl;//writes the output in the output file
    }
     cout<<"There are "<<distinctcount<<" distinct numbers."<<endl;//informs the user of how many unrepeated integer were there
//in both input files.
     outFile<<"There are "<<distinctcount<<" distinct numbers."<<endl;//informs the user how many unrepeated integers were there
//in both files inside the output file.
    infileNumbers.close();//closes second input file.
    infileValues.close();//closes first input file.
    outFile.close();//closes output file.


    return 0;
}

bool searchSim(int arr[],int SIZE, int num)
{
    int first=0,last=SIZE-1,mid;

    while(first<=last)
    {
        mid=(first+last)/2;
        if(arr[mid]==num)
        {
            return true;
        }
        else if(arr[mid]>num)
        {
            last=mid-1;
        }
        else
        {
            first=mid+1;
        }
    }
    return false;
}

void sort(int arr[], int SIZE)
{
    int minIndex,minValue;
    for(int start=0;start<(SIZE-1);start++)
    {
        minIndex=start;
        minValue=arr[start];

        for(int index=start+1;index<SIZE;index++)
        {
            if(arr[index]<minValue)
            {
                minValue=arr[index];
                minIndex=index;
            }
        }
        swap(arr[minIndex],arr[start]);

    }
}

void swap(int &a,int &b)
{
    int temp=a;
    a=b;
    b=temp;
}

