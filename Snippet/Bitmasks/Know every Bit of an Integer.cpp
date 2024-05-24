void keepBit(vector<int> &b, int n, int h = 1)
{
    int i = 25;
    for (i = 25; i >= 0; i--)
    {
        if (n >= (2 << i))
        {
            n -= (2 << i);
            b[i + 1] = b[i + 1] + h;
        }
    }
    if (n)
        b[i + 1] = b[i + 1] + h;
}

// for array b
//for 12 it keeps 0 0 1 1 0 0 0 0 0 0 0 0 0 0 
//for 13 it keeps 1 0 1 1 0 0 0 0 0 0 0 0 0 0 