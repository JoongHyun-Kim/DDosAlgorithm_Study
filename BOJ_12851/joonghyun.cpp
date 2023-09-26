#include <iostream>
#include <queue>
using namespace std;

int N, K;
int cnt = 0;
int minTime = 0;
const int MAX = 100001;
bool visited[MAX];

int bfs(int N, int K) {
    queue<pair<int, int>> q;
    q.push(make_pair(N, 0)); // 시작점(수빈의 위치, 걸린 시간)
    visited[N] = true;

    while(!q.empty()) {
        int location = q.front().first;
        int time = q.front().second;
        q.pop();
        visited[location] = true;

        // 최소 시간으로 n번째 방문
        if (location == K && cnt != 0 && minTime == time) cnt++;

        // 최초 방문
        if (location == K && cnt == 0) {
            minTime = time;
            cnt++;
        }

        if (location+1 < MAX && !visited[location+1])
            q.push(make_pair(location+1, time+1));
        if (location-1 >= 0 && !visited[location-1])
            q.push(make_pair(location-1, time+1));
        if (location*2 < MAX && !visited[location*2])
            q.push(make_pair(location*2, time+1));
    }
    return minTime;
}

int main() {
    cin >> N >> K;
    cout << bfs(N, K) << '\n';
    cout << cnt;

    return 0;
}