// You might break and that's okay.
// Tags:
#include <bits/stdc++.h>

#define fori(a, b) for (int i = a; i <= b; i++)
#define forj(a, b) for (int j = a; j <= b; j++)
#define wp " "
#define pb push_back
#define ull unsigned long long
#define pi pair<int, int>
#define ll long long
#define pl pair<ll, ll>
#define vi vector<int>
#define vl vector<ll>

int test_cases;
using namespace std;

template <typename T> struct rmq
{
    vector<T> v;
    int n;
    static const int b = 30; // block size
    vector<int> mask, t;     // mask and sparse table

    int op(int x, int y)
    {
        return v[x] < v[y] ? x : y;
    }
    // least significant set bit
    int lsb(int x)
    {
        return x & -x;
    }
    // index of the most significant set bit
    int msb_index(int x)
    {
        return __builtin_clz(1) - __builtin_clz(x);
    }
    // answer query of v[r-size+1..r] using the masks, given size <= b
    int small(int r, int size = b)
    {
        // get only 'size' least significant bits of the mask
        // and then get the index of the msb of that
        int dist_from_r = msb_index(mask[r] & ((1 << size) - 1));

        return r - dist_from_r;
    }
    rmq(const vector<T> &v_) : v(v_), n(v.size()), mask(n), t(n)
    {
        int curr_mask = 0;
        for (int i = 0; i < n; i++)
        {

            // shift mask by 1, keeping only the 'b' least significant bits
            curr_mask = (curr_mask << 1) & ((1 << b) - 1);

            while (curr_mask > 0 and op(i, i - msb_index(lsb(curr_mask))) == i)
            {
                // current value is smaller than the value represented by the
                // last 1 in curr_mask, so we need to turn off that bit
                curr_mask ^= lsb(curr_mask);
            }
            // append extra 1 to the mask
            curr_mask |= 1;

            mask[i] = curr_mask;
        }

        // build sparse table over the n/b blocks
        // the sparse table is linearized, so what would be at
        // table[j][i] is stored in table[(n/b)*j + i]
        for (int i = 0; i < n / b; i++)
            t[i] = small(b * i + b - 1);
        for (int j = 1; (1 << j) <= n / b; j++)
            for (int i = 0; i + (1 << j) <= n / b; i++)
                t[n / b * j + i] = op(t[n / b * (j - 1) + i], t[n / b * (j - 1) + i + (1 << (j - 1))]);
    }
    // query(l, r) returns the actual minimum of v[l..r]
    // to get the index, just change the first and last lines of the function
    T query(int l, int r)
    {
        // query too small
        if (r - l + 1 <= b)
            return v[small(r, r - l + 1)];

        // get the minimum of the endpoints
        // (there is no problem if the ranges overlap with the sparse table query)
        int ans = op(small(l + b - 1), small(r));

        // 'x' and 'y' are the blocks we need to query over
        int x = l / b + 1, y = r / b - 1;

        if (x <= y)
        {
            int j = msb_index(y - x + 1);
            ans = op(ans, op(t[n / b * j + x], t[n / b * j + y - (1 << j) + 1]));
        }

        return v[ans];
    }
};

int n;
vi a;

vl build_array(int splitter)
{
    vl c(n);
    fori(0, n - 1)
    {
        if (a[i] < splitter)
        {
            c[i] = -1;
        }
        else if (a[i] >= splitter)
        {
            c[i] = 1;
        }
        if (i > 0)
        {
            c[i] += c[i - 1];
        }
    }
    return c;
}

int solve(int cur_med, rmq<int> &A)
{
    vl c = build_array(cur_med);
    int ans = 0;
    vector<int> N(2 * n + 1, -1);
    forj(0, n - 1)
    {
        N[c[j] + n] = j;
    }
    forj(0, n - 1)
    {
        int prev_sum = 0;
        if (j > 0)
            prev_sum = c[j - 1];
        // find largest index with prev_sum.
        for (int zz = 0; zz <= 1; zz++)
        {
            // even number of elements.
            if (N[prev_sum + n + zz] != -1)
            {
                int largest_pos = N[prev_sum + n + zz];
                if (largest_pos >= j)
                {
                    ans = max(ans, cur_med - A.query(j, largest_pos));
                }
            }
        }
    }
    return ans;
}

void Solve()
{
    cin >> n;
    a = vi(n);
    fori(0, n - 1) cin >> a[i];
    rmq<int> A(a);
    int max_med = min(n, 100);
    int ans = solve(1, A);
    fori(2, max_med) ans = max(ans, solve(i, A)); // O(100 * n)
    cout << ans << endl;
}

int main()
{
    cin >> test_cases;
    while (test_cases--)
    {
        Solve();
    }
    return 0;
}