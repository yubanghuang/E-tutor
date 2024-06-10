#include <bits/stdc++.h>
using namespace std;
int main()
{
    int tcase; cin >> tcase;
    while(tcase--)
    {
        int n;cin >> n;
        char str[n];
        for(int i=0;i<n;i++)
            cin >> str[i];
        int i=0,ans=0;
        while(i<n)
        {
            if(str[i] == '.')
                i+=3,ans++;
            else
                i++;
        }
        cout << ans << endl;
    }
}
