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

class SegmentTree
{
  private:
    vi st, A;
    int n;
    int left(int p)
    {
        return p << 1;
    } /*same as binary heap operations*/
    int right(int p)
    {
        return (p << 1) + 1;
    }

    /*  L - left end of the array
        R - right end of the array
        p - current node of segment tree
    */
    void build(int p, int L, int R)
    {
        // If there is one element in array, store it in current node of
        // segment tree and return
        if (L == R)
            st[p] = L;

        // If there are more than one elements, then recur for left and
        // right subtrees and store the sum of values in this node
        else
        {
            int mid = (L + R) / 2;
            build(left(p), L, mid);
            build(right(p), mid + 1, R);

            int p1 = st[left(p)];
            int p2 = st[right(p)];
            st[p] = (A[p1] <= A[p2]) ? p1 : p2;
        }
    }
    /*
        p - current node of segment tree
        L - left end of array
        R - right end of array
        i - left end of query requested
        j - right end of query requested
    */
    int rmq(int p, int L, int R, int i, int j)
    {
        if (i > R || j < L)
            return -1; /*current segment outside query range*/
        if (L >= i && R <= j)
            return st[p]; /*Completely inside query range*/

        /*compute the min position in the left and right part of the interval*/
        int mid = (L + R) / 2;
        int p1 = rmq(left(p), L, mid, i, j);
        int p2 = rmq(right(p), mid + 1, R, i, j);

        if (p1 == -1)
            return p2;
        if (p2 == -1)
            return p1;
        return (A[p1] <= A[p2]) ? p1 : p2;
    }
    /*
        p - current node of segment tree
        L - left end of array
        R - right end of array
        idx - index of the element which is upadated in array
        new_value - new value of the changed element
    */
    int update_point(int p, int L, int R, int idx, int new_value)
    {

        int i = idx, j = idx;

        /*if the current interval does not intersect the update interval, return this st node value!*/
        if (i > R || j < L)
            return st[p];

        /*if the current interval is included in the update range, update that st[node]*/
        if (L == i && R == j)
        {
            A[i] = new_value; /*update the underlying array*/
            return st[p] = L;
        }

        /*compute the minimum position in the left and right part of the interval*/
        int p1, p2;
        int mid = (L + R) / 2;
        p1 = update_point(left(p), L, mid, idx, new_value);
        p2 = update_point(right(p), mid + 1, R, idx, new_value);

        /*return the position where the overall minimum is*/
        return st[p] = (A[p1] <= A[p2]) ? p1 : p2;
    }

  public:
    SegmentTree(const vi &_A)
    {
        A = _A;
        n = (int)A.size();                     /*copy content for local usage*/
        int x = (int)(ceil(log2(n)));          /*Height of segment tree*/
        int max_size = 2 * (int)pow(2, x) - 1; /*Maximum size of segment tree*/
        st.assign(max_size, 0);                /*create large enough vector of zeroes*/
        build(1, 0, n - 1);                    /*recursive build*/
    }

    int rmq(int i, int j)
    {
        return rmq(1, 0, n - 1, i, j); /*overloading*/
    }

    int update_point(int idx, int new_value)
    {
        return update_point(1, 0, n - 1, idx, new_value);
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

vl build_array2(int cur_med)
{
    vl c(n);
    fori(0, n - 1)
    {
        c[i] = (a[i] == cur_med);
        if (i > 0)
            c[i] += c[i - 1];
    }
    return c;
}

int solve(int cur_med, SegmentTree &A)
{
    vl c = build_array(cur_med);
    vl d = build_array2(cur_med);
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
                    int exist_cur = d[largest_pos];
                    if (j > 0)
                        exist_cur -= d[j - 1];

                    if (exist_cur > 0)
                    {
                        ans = max(ans, cur_med - a[A.rmq(j, largest_pos)]);
                    }
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
    SegmentTree A(a);
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