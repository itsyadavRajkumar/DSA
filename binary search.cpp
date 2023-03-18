#include<iostream>
using namespace std;
int binSearRecFun(int [], int, int, int);
int main()
{
    int i, arr[10], num, pos;
    cout<<"Enter 10 elements (in ascending order): ";
    for(i=0; i<10; i++)
        cin>>arr[i];
    cout<<"\nEnter element to be search: ";
    cin>>num;
    pos = binSearRecFun(arr, 0, 9, num);
    if(pos==0)
        cout<<endl<<num<<" is not available in the list";
    else
        cout<<endl<<num<<" is available at Position "<<pos;
    cout<<endl;
    return 0;
}
int binSearRecFun(int arr[], int first, int last, int num)
{
    int middle;
    if(first>last)
        return 0;
    middle = (first+last)/2;
    if(arr[middle]==num)
        return (middle+1);
    else if(arr[middle]>num)
        binSearRecFun(arr, first, middle-1, num);
    else if(arr[middle]<num)
        binSearRecFun(arr, middle+1, last, num);
}
