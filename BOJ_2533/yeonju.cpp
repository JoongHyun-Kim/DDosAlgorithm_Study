#include <iostream>
#include <vector>
using namespace std;

int N;
vector<int> graph[1000001];

// cur가 루트일 때의 서브트리에서 얼리아답터의 최소 수
// DP[노드번호][0]: 노드번호가 일반인일 때 최소 얼리어답터 수
// DP[노드번호][1] : 노드번호가 얼리어답터일 때 최소 얼리어답터 수
int DP[1000001][2];
int visited[1000001];

void dfs(int cur) {
  visited[cur] = 1;

  DP[cur][0] = 0;
  DP[cur][1] = 1;

  for (int i = 0; i < graph[cur].size(); i++) {
    int next = graph[cur][i];
    if (visited[next] == 1)
      continue;
    dfs(next);
    // cur이 얼리어답터가 아닌 경우, 자식은 반드시 얼리어답터
    DP[cur][0] += DP[next][1];
    // cur이 얼리어답터인 경우, 자식은 얼리어답터여도 되고 아니어도 OK
    DP[cur][1] += min(DP[next][0], DP[next][1]);
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie();

  cin >> N;

  for (int i = 0; i < N - 1; i++) {
    int u, v;
    cin >> u >> v;
    graph[u].push_back(v);
    graph[v].push_back(u);
  }
  dfs(1);
  // 트리는 어느 점을 잡아도 Root가 될 수 있다.
  // 그러므로 어느 점을 잡아도 똑같은 값을 반환한다.
  cout << min(DP[1][0], DP[1][1]);
  return 0;
}
