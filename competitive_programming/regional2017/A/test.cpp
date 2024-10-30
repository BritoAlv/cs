#include <bits/stdc++.h>

#define forn for (int i = 0; i < n; i++)
#define endl '\n'
#define wp ' '
#define ll long long
#define pb push_back
#define ld long double
using namespace std;

const ld INF = 1e18;
ld transitions[14][14];

struct Point
{
    int x;
    int y;
    Point(int x, int y)
    {
        this->x = x;
        this->y = y;
    }
    Point()
    {
    }
};

int operator<(const Point &cc, const Point &other)
{
    pair<int, int> one = {cc.x, cc.y};
    pair<int, int> two = {other.x, other.y};
    return one < two;
}

struct Segment
{
    int y1;
    int y2;
    int x1;
    int x2;
    Segment()
    {
    }
    Segment(int x1, int y1, int x2, int y2)
    {
        this->x1 = x1;
        this->y1 = y1;
        this->x2 = x2;
        this->y2 = y2;
    }
};

int operator<(const Segment &cc, const Segment &other)
{
    return tie(cc.y1, cc.y2, cc.x1, cc.x2) < tie(other.y1, other.y2, other.x1, other.x2);
}

int inside_y(Segment &seg, int coord_y)
{
    return seg.y1 <= coord_y && coord_y <= seg.y2;
}

ld distance_horizontal(Segment &seg, Point &point)
{
    if (seg.x1 == seg.x2)
    {
        return abs(point.x - seg.x1);
    }
    else if (seg.y1 == seg.y2)
    {
        return min(abs(point.x - seg.x1), abs(point.x - seg.x2));
    }
    else
    {
        ld m = seg.y1 - seg.y2;
        m /= (ld)(seg.x1 - seg.x2);
        ld n = seg.y1 - m * seg.x1;
        ld y_n = point.y;
        ld x_n = (y_n - n) / m;
        return abs(point.x - x_n);
    }
}

vector<Point> rightmost(14);
vector<Point> leftmost(14);
vector<set<Segment>> segments1(14);
vector<set<Segment>> segments2(14);
vector<vector<Point>> points(14);

vector<Segment> seg_in(int polyg, int coord_y)
{
    vector<Segment> result;
    auto pt = segments1[polyg].upper_bound(Segment(0, coord_y, 0, 100000000 + 1));
    pt--;
    int k = 3;
    while (k--)
    {
        auto seg = *pt;
        if (inside_y(seg, coord_y))
            result.push_back(seg);
        if (pt == segments1[polyg].begin())
        {
            break;
        }
        pt--;
    }

    auto pt2 = segments2[polyg].upper_bound(Segment(0, coord_y, 0, 100000000 + 1));
    pt2--;
    k = 3;
    while (k--)
    {
        auto seg = *pt2;
        if (inside_y(seg, coord_y))
            result.push_back(seg);
        if (pt2 == segments2[polyg].begin())
        {
            break;
        }
        pt2--;
    }
    assert(result.size() >= 1 && result.size() <= 4);
    return result;
}

ld closest_distance(Point coord_y, vector<Segment> segs)
{
    ld result = INF;
    for (auto &seg : segs)
    {
        ld cur = distance_horizontal(seg, coord_y);
        result = min(result, cur);
    }
    return result;
}

void calc(int left, int right)
{
    ld shift = transitions[left][left];
    ld minn = INF;
    for (auto point : points[right])
    {
        point.x += shift;
        minn = min(minn, closest_distance(point, seg_in(left, point.y)));
    }
    for (auto point : points[left])
    {
        point.x -= shift;
        minn = min(minn, closest_distance(point, seg_in(right, point.y)));
    }
    transitions[left][right] = minn;
}

int main()
{
    int n;
    cin >> n;
    forn
    {
        int k;
        cin >> k;
        vector<pair<int, int>> P;
        Point max_x = Point(-100000000 - 2, 0);
        Point min_x = Point(100000000 + 2, 0);
        while (k--)
        {
            int a, b;
            cin >> a >> b;
            P.push_back({a, b});
            if (a > max_x.x)
            {
                max_x = Point(a, b);
            }
            if (a < min_x.x)
            {
                min_x = Point(a, b);
            }
        }
        rightmost[i] = max_x;
        leftmost[i] = min_x;
        int shift = -min_x.x;
        rightmost[i].x += shift;
        leftmost[i].x = 0;
        int flag = 0;
        for (int j = 0; j < P.size(); j++)
        {
            int c1 = j;
            int c2 = (j + 1) % P.size();
            if (P[c1].second == P[c2].second && P[c1].second > 0)
            {
                flag = 1;
            }
            if (P[c1].second < P[c2].second)
            {
                // printf("Segment from (%d,%d) to (%d, %d) \n", P[c1].first + shift, P[c1].second, P[c2].first +
                // shift,P[c2].second);
                if (!flag)
                {
                    segments1[i].insert(
                        Segment(P[c1].first + shift, P[c1].second, P[c2].first + shift, P[c2].second));
                }
                else
                {
                    segments2[i].insert(
                        Segment(P[c1].first + shift, P[c1].second, P[c2].first + shift, P[c2].second));
                }
            }
            else
            {
                // printf("Segment from (%d,%d) to (%d, %d) \n", P[c2].first + shift, P[c2].second, P[c1].first +
                // shift,P[c1].second);
                if (!flag)
                {
                    segments1[i].insert(
                        Segment(P[c2].first + shift, P[c2].second, P[c1].first + shift, P[c1].second));
                }
                else
                {
                    segments2[i].insert(
                        Segment(P[c2].first + shift, P[c2].second, P[c1].first + shift, P[c1].second));
                }
            }
        }
        for (int j = 0; j < P.size(); j++)
        {
            points[i].push_back(Point(P[j].first + shift, P[j].second));
        }
    }
    forn
    {
        transitions[i][i] = rightmost[i].x;
        for (int j = 0; j < n; j++)
        {
            if (j != i)
            {
                calc(i, j);
            }
            // cout << transitions[i][j] << (j == n - 1 ? endl : wp);
        }
    }
    vector<vector<ld>> dp(1 << n, vector<ld>(n, INF));
    forn
    {
        dp[1 << i][i] = transitions[i][i];
    }
    for (int mask = 0; mask < (1 << n); mask++)
    {
        for (int i = 0; i < n; i++)
        {
            bool onn = (mask & (1 << i));
            for (int j = 0; j < n; j++)
            {
                bool on = (mask & (1 << j));
                if (on && onn)
                {
                    ld update = dp[mask ^ (1 << i)][j] + transitions[i][i] - transitions[j][i];
                    if (dp[mask][i] > update)
                    {
                        dp[mask][i] = update;
                    }
                }
            }
        }
    }
    ld ans = INF;
    forn
    {
        ans = min(ans, dp[(1 << n) - 1][i]);
    }
    ans = round(ans * 1000) / 1000;
    printf("%.3Lf", ans);
}