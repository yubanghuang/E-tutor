#include <bits/stdc++.h>
using namespace std;

void min_heapify(int arr[],int start,int end);
void printarray(int arr[],int len,bool reverse);
void heap_sort(int arr[], int len);

int main()
{
    int len; cin >> len;
    int arr[len];
    for(int i=0;i<len;i++)
        cin >> arr[i];
    heap_sort(arr,len);
}

void min_heapify(int arr[],int start, int end)
{
    int parent = start;
    int left = 2*parent + 1;
    int right = 2*parent + 2;
    int smallest = parent;
    while(left < end)
    {
        if(arr[left] < arr[smallest])
            smallest = left;
        if(right < end && arr[right] < arr[smallest])
            smallest = right;
        if(parent == smallest) 
            break;
        else
        {
            arr[parent] ^= arr[smallest] ^= arr[parent] ^= arr[smallest];
            parent = smallest;
            left = 2*parent + 1;
            right = 2*parent + 2;
        }
    }
   
}
void printarray(int arr[],int len,bool reverse=false)
{
    if(reverse)
    {
        for(int i = len-1; i >=0 ; i--)
            if(i) cout << arr[i] << " ";
            else cout << arr[i];
    }
    else
    {
        for(int i = 0; i < len; i++)
            if(i) cout << " " << arr[i];
            else cout << arr[i];
    }
    cout << endl;
}
void heap_sort(int arr[], int len) 
{
    for(int n = 2;n<=len;n++)
        for(int i=n/2-1; i>=0; i--)
            min_heapify(arr,i,n);
    printarray(arr,len);
    for (int i = len - 1; i > 0; i--)
    {
        arr[0] ^= arr[i] ^= arr[0] ^= arr[i];
        min_heapify(arr, 0, i);
        printarray(arr,len);
    }
    printarray(arr,len,true);
}