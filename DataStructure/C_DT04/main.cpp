#include <iostream>
using namespace std;
bool isFSnumber(int x)
{
    if(x >0)
    {
        if( x%5==0 || x%7==0)
            return true;
        else
            return isFSnumber(x-5);
    }
    else 
        return false;
}
int main()
{
    int arr[105]={0};
    arr[0]=0;
    for(int number=0,p=1;p<=100;number++)
        if(isFSnumber(number))
        {
            arr[p] = number;
            p++;
        }
    int n;
    while(cin >> n) 
        cout << arr[n-1] << endl;
}