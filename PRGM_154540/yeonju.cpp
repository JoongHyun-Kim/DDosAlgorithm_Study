#include <string>
#include <vector>
#include <queue>
#include <utility>
#include <algorithm>
#include <iostream>

using namespace std;

// BFS를 통해 연결된 섬 마다의 식량의 양을 구하자
// 마지막으로 오름차순으로 정렬하자

int visited[105][105];
int dirR[4]={1,-1,0,0} , dirC[4] = {0,0,-1,1}; 

int countHoliday(vector<string> maps, int r,  int c){
    int sum = 0;
    queue<pair<int,int>> q;
    q.push({r,c});
    visited[r][c] = 1;
    
    while(!q.empty()){
        pair<int,int> cur = q.front();
        q.pop();
        
//         식량 계산
        sum+=maps[cur.first][cur.second]-'0';
        
        for(int i=0;i<4;i++){
            int nextR = cur.first + dirR[i];
            int nextC = cur.second + dirC[i];
            
//             범위를 벗어나는 경우 패스
            if(nextR < 0 || nextR >= maps.size() || nextC < 0 || nextC >= maps[0].length()) continue;
//             바다인 경우 패스
            if(maps[nextR][nextC] == 'X') continue;
//             이미 방문한 경우 패스
            if(visited[nextR][nextC] != 0) continue;
            
            q.push({nextR,nextC});
            visited[nextR][nextC] = 1;
        }
    }
    
    return sum;
}

vector<int> solution(vector<string> maps) {
    vector<int> answer;
    
//     visited 배열 초기화
    for(int i=0;i<maps.size(); i++){
        for(int j=0;j<maps[i].size();j++){
            visited[i][j] = 0;
        }
    }
    
    for(int i=0;i<maps.size();i++){
        for(int j=0;j<maps[i].size();j++){
            if(maps[i][j] != 'X' && visited[i][j] == 0){
                // cout << maps[i][j]<<' ';
                int result = countHoliday(maps, i,j);
                answer.push_back(result);
            }
        }
    }
    
    if(answer.size() == 0){
        answer.push_back(-1);
    }
    else{
        sort(answer.begin(), answer.end());
    }
    
    
    return answer;
}
