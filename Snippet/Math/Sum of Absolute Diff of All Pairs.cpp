int sum_of_absolute_differences_of_all_pairs_in_a_given_array(int a[], int n)
{
    int ans = 0;
    sort(a, a + n);
    for (long long i = 0; i < n; i++)
        ans += a[i] * (2 * i - n + 1);
    return ans;
}