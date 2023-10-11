#include <cstring>
#include <iostream>
#include <queue>
using namespace std;
int S;
int visited[1005][1005];

int calcTime(){
  queue<pair<int, int>> q;
  q.push({1, 0}); // 화면, 클립보드
  visited[1][0] = 0;

  while (!q.empty()) {
    int screen = q.front().first;
    int clipboard = q.front().second;
    q.pop();

    if (screen == S) {
      return visited[screen][clipboard];
    }

    // 화면에 있는 이모티콘을 모두 복사해서 클립보드에 저장
    if (visited[screen][screen] == -1) {
      q.push({screen, screen});
      visited[screen][screen] = visited[screen][clipboard] + 1;
    }

    // 클립보드에 있는 모든 이모티콘을 화면에 붙여넣기
    if (screen + clipboard < 1005 && visited[screen + clipboard][clipboard] == -1) {
      q.push({screen + clipboard, clipboard});
      visited[screen + clipboard][clipboard] = visited[screen][clipboard] + 1;
    }

    // 화면에 있는 이모티콘 중 하나를 삭제
    if (screen > 0 && visited[screen - 1][clipboard] == -1) {
      q.push({screen - 1, clipboard});
      visited[screen - 1][clipboard] = visited[screen][clipboard] + 1;
    }
  }
}

int main(void) {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  cin >> S;

  // visited 배열 초기화
  for(int i=0;i<=S;i++){
    for(int j=0;j<=S;j++){
      visited[i][j] = -1;
    }
  }
  
  cout << calcTime();
}
