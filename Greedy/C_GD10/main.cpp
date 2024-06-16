#include <bits/stdc++.h>
using namespace std;
int main()
{
    int N;
    while(cin >> N)
    {
        bool hasSolution = false;
        for(int n2 = 1234;n2<=98765;n2++)
        {
            if(n2 % N != 0) continue;
            int n1 = n2 / N;
            int arr[10] = {0};
            for(int j=0,tmp1=n1,tmp2=n2;j<5;j++)
            {
                arr[tmp1%10]++;
                arr[tmp2%10]++;
                tmp1 /= 10;
                tmp2 /= 10;
            }
            bool pass = false;
            for(int j=0;j<10;j++)
                if(arr[j] != 1) 
                {
                    pass=true;
                    break;
                }
            if(!pass)
            {
                printf("%05d / %05d = %d\n",n2,n1,N);
                hasSolution = true;
            }
        }
        if(!hasSolution)
            printf("No solutions for %d.\n",N);
    }
}