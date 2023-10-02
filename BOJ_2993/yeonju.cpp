#include <iostream>
#include <vector>
#include <string.h>
#include <queue>
#define Left 1
#define Right 2

using namespace std;

typedef pair<int,int> pii;

int R, C, N;
char cave[105][105];
bool visited[105][105];
int height[105];
int dirR[4] = {1,-1,0,0};
int dirC[4] = {0,0,1,-1};

bool findIsGround(pii p) {
    memset(visited,false,sizeof(visited));
    queue<pii> q;
    bool isGround = false;
    visited[p.first][p.second] = true;
    q.push(p);
    if(p.first==R) isGround = true;
    
    while(!q.empty()) {
        pii cur = q.front();
        int x = cur.first, y = cur.second; 
        q.pop();
        for(int i = 0; i< 4; i++) {
            int nx = x + dirR[i], ny = y + dirC[i];
            if(cave[nx][ny] == 'x' && visited[nx][ny] == false) {
                visited[nx][ny] = true;
                q.push({nx,ny});
                if(nx == R) isGround = true;
            }
        }
    }
    return isGround;
}

bool fallMineral() {
    bool isGround = false;

    for(int i = R; i > 0; i--) {
        for(int j = 1; j <= C; j++) {
            if(visited[i-1][j]) {
                visited[i-1][j] = false;
                visited[i][j] = true;
                cave[i-1][j] = '.';
                cave[i][j] = 'x';
                if((i+1 <= C && cave[i+1][j] == 'x' && visited[i+1][j] == false) || i==R) {
                    isGround =true;
                }
            }
        }
    }

    return isGround;
}

void fight(int dir, int height) {
    pii dest = {-1,-1};
    
    for(int i = 1; i <= C; i++) {
        if(cave[height][i] == 'x' && dir == Left) {
            dest = {height,i};
            cave[height][i] = '.';
            break;
        }
        if(cave[height][C-i+1] == 'x' && dir == Right) {
            dest = {height, C-i+1};
            cave[height][C-i+1] = '.';
            break;
        }
    }

    // 아무것도 사라지지 않은 경우
    if(dest.first == -1) return;

    //위쪽으로 분리된 경우
    int h = dest.first-1, w = dest.second;
    if(cave[h][w] == 'x') {
        bool isGround = findIsGround({h,w});
        while(!isGround) {
            isGround = fallMineral();
        }
    }
    
    //옆쪽으로 분리된 경우
    h = dest.first, w = (dir==Left)? dest.second+1 : dest.second-1;
    if(cave[h][w] == 'x') {
        bool isGround = findIsGround({h,w});
        while(!isGround) {
            isGround = fallMineral();
        }
    }

    //아래쪽으로 분리된 경우
    h = dest.first+1, w = dest.second;
    if(cave[h][w] == 'x') {
        bool isGround = findIsGround({h,w});
        while(!isGround) {
            isGround = fallMineral();
        }
    }

}

int main(void) {
  cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(false);
    
  cin >> R>>C;
  for(int i = 1; i <= R; i++){
    cin>>&cave[i][1];
  }
  
  cin>>N;
  for(int i = 1; i <= N; i++){
    cin>>height[i];
  }
        
  for(int i = 1; i<= N; i++){
    fight((i%2==1)?Left:Right, R - height[i]+1);
  }
    
  for(int i = 1; i <= R; i++) {
    for(int j = 1; j <= C; j++){
      cout<<cave[i][j];
    }
    cout<<'\n';       
  }
}

// [POINT] 이동시키는 부분이 어려웠다...
