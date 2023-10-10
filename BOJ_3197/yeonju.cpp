// 한꺼번에 삭제해야한다
// X로 탐색하면서
// 한쪽에 .(물 공간)이 닿아있으면
// 표시 해둔다.
// 한꺼번에 지운다.

// .으로 탐색하면서 L을 찾아나간다.
// 못 찾으면 다시 반복

#include <iostream>
#include <queue>
#include <string>
#include <vector>
using namespace std;
int R, C, answer = 0;
vector<string> lake;
int visited[1505][1505];
int dirR[4] = {1, -1, 0, 0}, dirC[4] = {0, 0, -1, 1};
int swanR = -1, swanC = -1;
queue<pair<int, int>> iceQ,iceNQ, swanQ, swanNQ;

void initiateVisited() {
  for (int i = 0; i < R; i++) {
    for (int j = 0; j < C; j++) {
      visited[i][j] = 0;
    }
  }
}

bool meetSwan() {

  while (!swanQ.empty()) {
    int curR = swanQ.front().first;
    int curC = swanQ.front().second;
    swanQ.pop();

    for (int i = 0; i < 4; i++) {
      int nextR = curR + dirR[i];
      int nextC = curC + dirC[i];
      if (nextR < 0 || nextR >= R || nextC < 0 || nextC >= C)
        continue;
      if (visited[nextR][nextC] == 1)
        continue;

      // 물 공간이면 이동 가능
      if (lake[nextR][nextC] == '.') {
        swanQ.push({nextR, nextC});
        visited[nextR][nextC] = 1;
      }
        // 백조를 찾으면 종료
      else if (lake[nextR][nextC] == 'L') {
        visited[nextR][nextC] = 1;
        return true;
      }
      else if(lake[nextR][nextC] == 'X'){
        visited[nextR][nextC] = 1;
        swanNQ.push({nextR,nextC}); // 백조가 있을 수 없는 공간 표시?
      }
    }
  }
  return false;
}

void melt() {

  while (!iceQ.empty()) {
    int curR = iceQ.front().first;
    int curC = iceQ.front().second;
    iceQ.pop();

    for (int i = 0; i < 4; i++) {
      int nextR = curR + dirR[i];
      int nextC = curC + dirC[i];
      if (nextR < 0 || nextR >= R || nextC < 0 || nextC >= C)
        continue;

      // 녹은 부분 표시하기
      if (lake[nextR][nextC] == 'X') {
        lake[nextR][nextC] = '.';
        iceNQ.push({nextR,nextC}); // 얼음이 없는 공간 표시
      }
    }
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> R >> C;
  for (int i = 0; i < R; i++) {
    string temp;
    cin >> temp;
    lake.push_back(temp);
    for (int j = 0; j < lake[i].size(); j++) {
      // 빙판 공간 표시
      if (lake[i][j] != 'X') {
        iceQ.push({i, j});
      }
      // 백조 위치 표시
      if (lake[i][j] == 'L' && swanQ.empty()) {
          swanQ.push({i,j});
          visited[i][j]=1;
      }
    }
  }

  while (1) {
    // 백조가 만날 수 있는지 확인
    if (meetSwan() == true) {
      cout << answer;
      break;
    }
    melt();
    iceQ = iceNQ;
    swanQ = swanNQ;

    while(!iceNQ.empty()){
      iceNQ.pop();
    }
    while(!swanNQ.empty()){
      swanNQ.pop();
    }
    answer++;
  }
}

// [NOTE] 풀이 과정은 맞는데 시간초과가 났다
// [POINT] BFS를 전체 한 번만 하는 것이 시간초과 해결 방법
// 처음에는 얼음 녹는 것과 백조의 이동을 각각 BFS로 풀어서 시간초과가 발생했다.
