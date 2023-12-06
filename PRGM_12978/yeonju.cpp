// 양방향으로 마을의 연결 관계를 표시한다
// 1번 마을을 기주능로 BFS로 탐색하면서 걸리는 시간을 탐색한다.
// 더 짧은 시간이 나오면 그것을 갱신한다

// 연결된 곳을 방문한다. 그곳까지 걸리는 시간을 기록한다.
// 기존에 저장된 값이 있다면 기존 값과 새로운 값을 비교해서 최솟값으로 갱신해주자
// [ 처음 방문했을 때 카운트 되는 시간이 최단 시간일까? ] 아니! 

// 연결된 곳 중, 1) 이미 방문하지 않았거나 2) 방문했지만 최솟값으로 갱신이 가능한 경우에만 방문하자

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

struct Village {
    int num;
    int time; 
};

vector<Village> graph[55];
int timeArr[55];

void cntTime(int K){
    queue<Village> q;
    q.push({num:1, time:0});
    
    while(!q.empty()){
        Village cur = q.front();
        q.pop();
        
//         기존 값보다 크거나 같은 값이거나 K를 초과하는 경우에는 제외하자
        if((timeArr[cur.num] != -1 && cur.time >= timeArr[cur.num])  ){
            continue;
        }
        
        timeArr[cur.num] = cur.time;
//         연결된 것들을 모두 추가하자
        for(int i=0;i<graph[cur.num].size();i++){
            if(graph[cur.num][i].num == 1) continue;
            q.push({num:graph[cur.num][i].num, time: cur.time+ graph[cur.num][i].time});
        }

        
    }

}

int solution(int N, vector<vector<int> > road, int K) {
    int answer = 0;
    
    for(int i=0;i<=N;i++){
        timeArr[i] = -1;
    }
    
    for(int i=0;i<road.size();i++){
        int a = road[i][0];
        int b = road[i][1];
        int c = road[i][2];
        graph[a].push_back({num:b, time:c});
        graph[b].push_back({num:a, time:c});
    }
    
    cntTime(K);
    
    for(int i=1;i<=N;i++){
        if(timeArr[i] <=K){
            answer++;
        }
    }

    return answer;
}
