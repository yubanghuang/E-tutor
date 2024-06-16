#include <bits/stdc++.h>
using namespace std;
int main()
{
    string str;
    while(getline(cin,str))
    {
        vector<int> v;
        stringstream  ss(str); 
        string token;
        int minimum = INT_MAX;
        while(getline(ss,token,','))
        {
            int number = stoi(token);
            v.push_back(number);
            minimum = std::min(minimum,number);
        }
        int n = v.size();
        int LIS[n]; 
        int ans[n+1];   // ans[length]=i : 在 LIS 中長度為 length 時，在數列 v 中第 i 個位置
        int max_len=0;  // 遞增子數列最大長度
        std::fill(ans,ans+n,-1);
        std::fill(LIS,LIS+n,1);
        for(int i=0;i<n;i++)
            for(int j=0;j<=i;j++)
            {
                if(v[i] > v[j])
                {
                    LIS[i] = std::max(LIS[i],LIS[j] + 1);
                    max_len = std::max(LIS[i],max_len);
                }
            }
        // 在數列中找出*LIS中有最大長度* 且 *在數列中為最大值*的數字的 index
        for(int i=0;i<n;i++)
            if(LIS[i] == max_len)
                if(ans[max_len] == -1)
                    ans[max_len] = i;
                else if(v[ans[max_len]] < v[i])
                    ans[max_len] = i;
        // len從最大長度max_len-1開始，找出在LIS中長度 == len 且 在數列 v 中比前一個數還小的數字的index
        // ex. v[4] = {6,-5,4,-3,2}
        // LIS 中長度為 3 的有 v[4]
        // LIS 中長度為 2 的有 v[2] , v[3] -> 因為 v[2] > v[4] 所以 ans[2] = 3 (LIS長度為 2 且 在 v 中第3個位置的數字) 
        for(int len=max_len-1;len>=1;len--)
            for(int i=ans[len+1]-1;i>=0;i--)
                if(LIS[i] == len)
                    if(ans[len] == -1)
                        ans[len] = i;
                    else if(v[ans[len]] < v[i] && v[i] < v[ans[len+1]])
                        ans[len] = i;
        for(int i=1;i<=max_len;i++)
            cout << v[ans[i]] << ((i!=max_len)? "," : "");
        cout << endl;
    }
}