void maxSubArraySum(int a[], int size)
{
    int max_so_far = INT_MIN, max_ending_here = 0,
        start = 0, end = 0, s = 0;

    for (int i = 0; i < size; i++)
    {
        max_ending_here += a[i];

        if (max_so_far < max_ending_here)
        {
            max_so_far = max_ending_here;
            start = s;
            end = i;
        }

        if (max_ending_here < 0)
        {
            max_ending_here = 0;
            s = i + 1;
        }
    }
    cout << max_so_far << start << end << endl;
}

int maxSubarraySumCircular(vector<int> &nums)
{
    int mxsf = -30000, mnsf = 30000, sum = 0, csum = 0;

    for (int x : nums)
    {
        csum += x;
        sum += x;
        mxsf = max(mxsf, csum);
        csum = max(csum, 0);
    }
    csum = 0;
    for (int x : nums)
    {
        csum += x;
        mnsf = min(mnsf, csum);
        if (csum > 0)csum = 0;
    }

    if (mnsf == sum) mnsf = 0;
    return max(mxsf, sum - mnsf);
}