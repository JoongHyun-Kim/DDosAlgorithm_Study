// 1초 후에 X-1 / X+1 / 2*X
// BFS // 순서대로

// N이 K와 같은 경우
// 0초, 현재 위치만 출력하면 됨


#include <iostream>
#include <queue>
#include <vector>
#define MAX 100005
using namespace std;
int N, K; // 수빈이 위치, 동생 위치
vector<int> answer;
int visited[MAX];
int pastLocation[MAX]; // idx로 오기 직전의 위치

void findSister(vector<int> path) {

  queue<pair<int, int>> q; // 현재 위치와 소요 시간
  q.push({N, 0});

  while (!q.empty()) {
    int cur = q.front().first;
    int curTime = q.front().second;
    visited[cur] = 1; 
    q.pop();

    if (cur == K) {
      // 역추적을 통해 경로 입력
      int idx = cur;
      while (idx != N) {
        answer.push_back(idx);
        idx = pastLocation[idx];
      }
      answer.push_back(N);
      break;
    }

    if (2 * cur < MAX && !visited[2 * cur]) {
      q.push({2 * cur, curTime + 1});
      pastLocation[2 * cur] = cur;
      visited[cur * 2] = 1;
    }

    if (cur + 1 < MAX && !visited[cur + 1]) {
      q.push({cur + 1, curTime + 1});
      pastLocation[cur + 1] = cur;
      visited[cur + 1] = 1;
    }

    if (cur - 1 >= 0 && !visited[cur - 1]) {
      q.push({cur - 1, curTime + 1});
      pastLocation[cur - 1] = cur;
      visited[cur - 1] = 1;
    }
  }
}

int main() {
  cin >> N >> K;

  findSister({N});
  cout << answer.size() - 1 << '\n';
  for (int i = answer.size() - 1; i >= 0; i--) {
    cout << answer.at(i) << ' ';
  }
}

// [NOTE] BFS, 위치 범위 잘 찾았다!
// [NOTE] BFS에서 방문 배열은 큐에 넣을 때마다 바로바로 확인해줘서 중복 카운트를 줄이자
// [POINT] 경로를 다 저장해놓고 찾으려고 하니까 시간초과가 난다!
// 그러니까 간단하게 이전 위치 하나만 저장해놓고 연결해서 찾아갈 수 있도록 한다
