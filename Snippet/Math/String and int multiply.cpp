string multyply(string a, int b)
{
    int carry = 0, l = a.size();

    string ans = "";

    for (int i = l - 1; i >= 0; i--)
    {
        carry = ((a[i] - '0') * b + carry);
        ans += carry % 10 + '0';
        carry /= 10;
    }
    while (carry != 0)
    {
        ans += carry % 10 + '0';
        carry /= 10;
    }
    reverse(ans.begin(), ans.end());
    return ans;
}