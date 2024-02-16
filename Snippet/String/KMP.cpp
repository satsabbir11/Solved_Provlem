vector<int> lps(string pattern)
{
    int n = pattern.size();
    vector<int> v(n);
    int index = 0;
 
    for (int i = 1; i < n;)
    {
        if (pattern[i] == pattern[index])
        {
            v[i] = index + 1;
            i++;
            index++;
        }
        else
        {
            if (index)
                index = v[index - 1];
            else
            {
                v[i] = 0;
                i++;
            }
        }
    }
    return v;
}
 
int kmp(string s, string pattern)
{
    int n = s.size(), m = pattern.size();
    int i = 0, j = 0;
    int ans = 0;
 
    vector<int> v = lps(pattern);
 
    while (i < n)
    {
        if (s[i] == pattern[j])
        {
            i++;
            j++;
        }
        else
        {
            if (j)
                j = v[j - 1];
            else
                i++;
        }
 
        if (j == m) //to count how many pattern match
        {
            ans++;
            j = v[j - 1];
        }
    }
 
    return ans;
}