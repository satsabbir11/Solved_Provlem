#include <bits/stdc++.h>
using namespace std;

struct Item
{
    double profit, weight;
};

int main()
{
    Item a[] = {{60, 20}, {134, 34}, {345, 23}};
    int W = 50;
    int n = sizeof(a) / sizeof(a[0]);
    sort(a, a + n, [](Item a, Item b)
         { return (a.profit / a.weight) > (b.profit / b.weight); });

    double max_profit = 0;

    for (int i = 0; i < n; i++)
    {
        if (a[i].weight <= W)
        {
            W -= a[i].weight;
            max_profit += a[i].profit;
        }
        else
            max_profit += a[i].profit * (double)W / a[i].weight;
    }

    cout << max_profit << endl;
}
