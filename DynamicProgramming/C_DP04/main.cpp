#include <bits/stdc++.h>

using namespace std;
int main()
{
    int tcase; cin >> tcase;
    while(tcase--)
    {
        int n; cin >> n;
        int arr[101][101] = {0};
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                cin >> arr[i][j];
		bool visited[n]; 
        memset(visited,false,sizeof(visited)); 
        int cost[n]; // 記錄目前認識的住戶與其他住戶的最小介紹費
		memset(cost,0x3f3f3f3f,sizeof(cost));
		cost[0] = 0; // 第一位住戶不收費;
		int ans = 0;
		for(int i=0;i<n;i++)
		{
			int min = INT_MAX;
			int index;
			// 找出目前認識的住戶與其他住戶的最小介紹費
			// index : 有著最小介紹費的住戶
			for(int j=0;j<n;j++)
				if( cost[j] < min && !visited[j])
					min = cost[j],index=j;
			visited[index] = true;
			ans += min;
			// 因為多了 index 這位住戶，可以透過這位住戶介紹其他住戶，所以更新cost[n]
			for(int j=0;j<n;j++) 
				if(arr[index][j] != 0 && cost[j] > arr[index][j])
					cost[j] = arr[index][j];
		}
        cout << ans << endl;
    }
}