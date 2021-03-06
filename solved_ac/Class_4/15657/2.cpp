#include <iostream>
#include <algorithm>

using namespace std;

int N, M;
int arr[8], made[8];

void pmt(int L, int idx)
{
    if (L == M)
    {
        for (int i = 0; i < M; i++)
            cout << made[i] << ' ';
        cout << '\n';
        return;
    }

    for (int i = idx; i < N; i++)
    {
        made[L] = arr[i];
        pmt(L + 1, i);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;
    for (int i = 0; i < N; i++)
        cin >> arr[i];

    sort(arr, arr + N);
    pmt(0, 0);

    return 0;
}