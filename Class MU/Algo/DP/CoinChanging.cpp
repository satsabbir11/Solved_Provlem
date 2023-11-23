#include <bits/stdc++.h>
using namespace std;

int minCoins(int coins[], int m, int V)
{
    int table[V + 1];
    int coinUsed[V + 1]; // To store the used coins for each value.

    table[0] = 0;
    coinUsed[0] = -1; // Initialize the used coins for value 0 to -1.

    for (int i = 1; i <= V; i++)
    {
        table[i] = INT_MAX;
        coinUsed[i] = -1; // Initialize the used coins for value i to -1.
    }

    for (int i = 1; i <= V; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (coins[j] <= i)
            {
                int sub_res = table[i - coins[j]];
                if (sub_res != INT_MAX && sub_res + 1 < table[i])
                {
                    table[i] = sub_res + 1;
                    coinUsed[i] = j; // Store the index of the coin used.
                }
            }
        }
    }

    if (table[V] == INT_MAX)
    {
        cout << "It is not possible to make the sum " << V << " with the given coins." << endl;
        return -1;
    }

    cout << "Minimum coins required is " << table[V] << ". The coins used are: ";

    int value = V;
    while (value > 0)
    {
        int coinIndex = coinUsed[value];
        cout << coins[coinIndex] << " ";
        value -= coins[coinIndex];
    }
    cout << endl;

    return table[V];
}

int main()
{
    int coins[] = {9, 6, 5, 1};
    int m = sizeof(coins) / sizeof(coins[0]);
    int V = 11;
    minCoins(coins, m, V);
    return 0;
}