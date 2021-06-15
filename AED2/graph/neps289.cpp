#include <bits/stdc++.h>
#define MAX 100000
using namespace std;
int v, queries;
int op, a, b;
vector<int> graph[MAX];
bool hasVertex(vector<int>* gr, int a, int b)
{
  for (int x: gr[a]) {
    if (x == b)
      return true;
  }
  return false;
}

int main()
{
  cin >> v >> queries;
  for (int i = 0; i < queries; i++)
  {
    cin >> op >> a >> b;
    if (op == 0)
    {
      if (hasVertex(graph, a - 1, b - 1))
        cout << 1 << endl;
      else
        cout << 0 << endl;
    }
    else
    {
      graph[a - 1].push_back(b - 1);
      graph[b - 1].push_back(a - 1);
    }
  }
  return 0;
}