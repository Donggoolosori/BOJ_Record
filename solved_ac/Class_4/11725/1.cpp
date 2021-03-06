// dfs 사용
// 10050kb 52ms
#include <iostream>
#include <vector>

using namespace std;

int N;
int parent[100001];
vector<int> graph[100001];

void setParent(int curr)
{
    for (const int &adj : graph[curr])
    {
        if (parent[adj] == 0)
        {
            parent[adj] = curr;
            setParent(adj);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    int a, b;
    for (int i = 0; i < N - 1; i++)
    {
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    parent[1] = 1;
    setParent(1);

    for (int i = 2; i <= N; i++)
        cout << parent[i] << '\n';
    return 0;
}