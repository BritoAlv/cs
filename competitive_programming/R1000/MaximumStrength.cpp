#include <bits/stdc++.h>
#define endl '\n'
#define wp ' '
#define forn for (int i = 0; i < n; i++)
using namespace std;

/*
this is about to get corner cases like 9999 0000
*/

int compute_answer(string &A, string &B)
{
    int answer = 0;
    for (int i = 0; i < max(A.size(), B.size()); i++)
    {
        answer += abs((A[i] - '0') - (B[i] - '0'));
    }
    return answer;
}

int test_cases;

void Solve()
{
    string A, B;
    cin >> A >> B;
    while (A.size() != B.size())
    {
        A = "0" + A;
    }
    int index = 0;
    while (A[index] == B[index] && index < A.size())
    {
        index++;
    }

    if (index == (int)A.size())
    {
        cout << 0 << endl;
        return;
    }

    else
    {
        // index is located at the first position where they differ.
        if (index == A.size() - 1)
        {
            cout << compute_answer(A, B) << endl;
            return;
        }
        else
        {
            // we can construct two numbers.
            int answer = compute_answer(A, B);
            string C = A;
            C[index] = C[index] + 1;
            for (int i = index + 1; i < C.size(); i++)
            {
                C[i] = '0';
            }
            string D = B;
            D[index] = B[index] - 1;
            for (int i = index + 1; i < D.size(); i++)
            {
                D[i] = '9';
            }
            answer = max(answer, compute_answer(C, D));

            C[index]--;
            for (int i = index + 1; i < C.size(); i++)
            {
                C[i] = '9';
            }

            D[index]++;
            for (int i = index + 1; i < D.size(); i++)
            {
                D[i] = '0';
            }
            answer = max(answer, compute_answer(C, D));
            cout << answer << endl;
        }
    }

    return;
}

int main()
{
    cin >> test_cases;
    while (test_cases > 0)
    {
        Solve();
        test_cases--;
    }
    return 0;
}
