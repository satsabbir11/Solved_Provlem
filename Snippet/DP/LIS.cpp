int lengthOfLIS(vector<int>& nums)
{
    short totalNums = nums.size();
    int lisSize = 0;
    vector<short>lis(totalNums+1,totalNums+10);
    lis[0] *= -1;
    for(int x:nums)
    {
        short lo = 0, high = lisSize;
        while(lo!=high)
        {
            short mid = (lo + high)/2;
            if(lis[mid]<x)
            {
                lo = mid + 1;
            }
            else
            {
                high = mid;
            }
        }
        lis[lo] = x;
        lisSize += (lo==lisSize);
    }
    return lisSize;
}