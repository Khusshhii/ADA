#include <bits/stdc++.h>
using namespace std;
#define V 10

vector<int> icosiangame(bool graph[][V], int s)
{
    vector<int> vertex;
    int flag;
    for (int i = 0; i < V; i++)
        if (i != s)
            vertex.push_back(i);
    do
    {
        if (graph[s][vertex[0]] && graph[vertex[V - 2]][s])
        {
            flag = 0;
            int count = 0;
            for (int i = 0; i < V - 2; i++)
            {
                if (!graph[vertex[i]][vertex[i + 1]])
                {
                    flag = -1;
                    break;
                }
            }
            if (flag != -1)
            {
                return vertex;
            }
        }

    } while (next_permutation(vertex.begin(), vertex.end()));
    vector<int> empty;
    return empty;
}

int main()
{
    bool graph[V][V] = {
        {0, 1, 0, 0, 1, 1, 0, 0, 0, 0},
        {1, 0, 1, 0, 0, 0, 1, 0, 0, 0},
        {0, 1, 0, 1, 0, 0, 0, 1, 0, 0},
        {0, 0, 1, 0, 1, 0, 0, 0, 1, 0},
        {1, 0, 0, 1, 0, 0, 0, 0, 0, 1},
        {1, 0, 0, 0, 0, 0, 0, 1, 1, 0},
        {0, 1, 0, 0, 0, 0, 0, 0, 1, 1},
        {0, 0, 1, 0, 0, 1, 0, 0, 0, 1},
        {0, 0, 0, 1, 0, 1, 1, 0, 0, 1},
        {0, 0, 0, 0, 1, 0, 1, 1, 1, 0},
    };

    cout << "Solution Exists:" << endl
         << "Following is one of the Hamiltonian Cyles\n";
    int s = 0;

    vector<int> ans = icosiangame(graph, s);
    cout << s << " ";
    for (int i = 0; i < V - 1; i++)
    {
        cout << ans[i] << " ";
    }
    cout << s << "\n";
}
