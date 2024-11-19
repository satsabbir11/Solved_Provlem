int maxSubarraySumCircular(vector<int> &nums)
{
    int mxsf = -30000, mnsf = 30000,  sum = 0, csum = 0;
    for (int x : nums)
    {
        csum += x; sum += x;
        mxsf = max(mxsf, csum);
        csum = max(csum, 0);
    }
    csum = 0;
    for (int x : nums)
    {
        csum += x;
        mnsf = min(mnsf, csum);
        if (csum > 0) csum = 0;
    }
    if (mnsf == sum) mnsf = 0;
    return max(mxsf, sum - mnsf);
}