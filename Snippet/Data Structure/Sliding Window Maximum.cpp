vector<int> maxSlidingWindow(vector<int> &nums, int k)
{
    int n = nums.size();
    deque<int> dq;
    vector<int> ans;
    for (int i = 0; i < n; i++)
    {
        while (dq.size() > 0 && nums[dq.back()] < nums[i])
            dq.pop_back();
        dq.push_back(i);
        if (i >= k - 1)
        {
            ans.push_back(dq.front());
            if (dq.front() < i - k + 2)
                dq.pop_front();
        }
    }
    for (int i = 0; i < ans.size(); i++)
    {
        ans[i] = nums[ans[i]];
    }
    return ans;
}
