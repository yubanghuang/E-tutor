#include <iostream>
#include <iomanip>
#include <cstring>
#include <algorithm>
double W;
double w[3], p[3];
int a, b, c;
double Sum;
void dfs(int n1, int n2, int n3, double rw,double sum)
{
    int t[3] = { 0 };
    t[0] = 1;
    for (int i = 0; i < 3; i++)
    {
        if(i) t[i] = 1, t[i - 1] = 0;
        if(rw - w[i] >= 0)
            dfs(n1+t[0], n2+t[1], n3+t[2], rw - w[i],sum+p[i]);
        if (Sum < sum)
        {
            Sum = sum;
            a = n1, b = n2, c = n3;
        }
    }
}

int main()
{
    while (std::cin >> W >> w[0] >> w[1] >> w[2] >> p[0] >> p[1] >> p[2])
    {
        Sum = 0;
        dfs(0, 0, 0, W, 0);
        if (Sum)
            std::cout << std::fixed << std::setprecision(3) << a << " " << b << " " << c << " " << Sum << std::endl;
        else
            std::cout << std::fixed << std::setprecision(3) << Sum << std::endl;
    }
}