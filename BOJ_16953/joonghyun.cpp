#include <iostream>
#include <queue>
using namespace std;

int bfs(long long A, long long B) {
    queue<pair<long long, long long>> q; // 숫자, 연산횟수
    q.push(make_pair(A,1));

    while(!q.empty()){
        long long cur = q.front().first;
        long long cnt = q.front().second;
        q.pop();

        if(cur == B) return cnt;
        if(cur*2 <= B) q.push(make_pair(cur*2, cnt+1));
        if(cur*10+1 <= B) q.push(make_pair(cur*10+1, cnt+1));
    }
    return -1;
}

int main(){
    long long A, B;
    cin >> A >> B;
    cout << bfs(A, B);

    return 0;
}
