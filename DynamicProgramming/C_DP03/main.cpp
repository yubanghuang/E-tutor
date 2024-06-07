#include <iostream>
using namespace std;
int main()
{
    int tcase; cin >> tcase;
    while (tcase--)
    {
        int x, y;
        cin >> x >> y;
        long long int days[6] = { 0 };
        days[1] = x;
        for (int i = 2; i <= y; i++)
        {
            for (int j = 5; j >= 1; j--)
                if (j == 1)
                    days[j] = days[4] + days[5];
                else
                    days[j] = days[j - 1];
        }
        long long int sum = 0;
        for (int i = 1; i <= 5; i++)
            sum += days[i];
        cout << sum << endl;
    }

}