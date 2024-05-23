void update(int i, int val, int n, int *tree)
{
    while (i <= n)
    {
        tree[i] += val;
        i += (i & -i);
    }
}
//sum from 1 to i
int getSum(int i, int *tree)
{
    int sum = 0;
    while (i > 0)
    {
        sum += tree[i];
        i ^= (i & -i);
    }
    return sum;
}