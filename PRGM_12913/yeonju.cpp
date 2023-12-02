#include <iostream>
#include <vector>
using namespace std;

int solution(vector<vector<int> > land){
    int answer = -1;
    int DP[100005][4];
    
    DP[0][0]=land[0][0];
    DP[0][1]=land[0][1];
    DP[0][2]=land[0][2];
    DP[0][3]=land[0][3];

    for(int i=1;i<land.size();i++){
        for(int j=0;j<4;j++){
            DP[i][j] = -1;
            for(int k=0;k<4;k++){
                if(j == k) continue;
                DP[i][j] = max(DP[i][j], DP[i-1][k]+land[i][j]);
            }
        }
    }
    
    for(int i=0;i<4;i++){
        answer = max(answer, DP[land.size()-1][i]);
    }

    return answer;
}
