vector<ll> p_sum(n + 1, 0);
vector<ll> s_sum(n + 1, 0);
forn
{
    p_sum[i + 1] = p_sum[i] + arr[i];
}
for (int i = n - 1; i >= 0; i--)
{
    s_sum[i] = s_sum[i + 1] + arr[i];
}