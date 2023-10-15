// [NOTE] 경우의 수 탐색 -> DFS나 BFS

#include <string>
#include <vector>
#include <map>

#include <iostream>
using namespace std;

map<string, int>mineralMap;                //광물 이름과 숫자 매핑
int stress[3][3]={{1,1,1},{5,1,1},{25,5,1}}; // 각각 피로도

vector<int>mineralList;

int mineralNum=0;
int answer = 1250;

void dfs(vector<int> &picks, int cur,int sum){ // 곡괭이들, 현재 위치
    int sumList[3]={0,}; // 피로도 저장
    int calc=0;
    
    if(cur == mineralNum || picks[0]+picks[1]+picks[2]==0){ // 광물을 다 캤거나 곡괭이 다 씀
        answer=min(answer,sum);
        return;
    }
    
    for(int i=cur;i<cur+5;i++){
        if(i>=mineralNum){ // 끝까지 다 채굴한 경우
            calc=i;
            break;
        }
//         곡괭이 별 사용 후 피로도 계산
        sumList[0]+=stress[0][mineralList[i]];
        sumList[1]+=stress[1][mineralList[i]];
        sumList[2]+=stress[2][mineralList[i]];  
        
        calc=i;
    }
    
//     곡괭이를 사용하는 모든 경우의 수 탐색
    for(int i=0;i<3;i++){
        if(picks[i]!=0){
            picks[i]-=1;
//             현재까지 계산한 위치 다음부터 계산 시작
            dfs(picks,calc+1,sum+sumList[i]);
            picks[i]+=1;
        }
    }
}

int solution(vector<int> picks, vector<string> minerals) {
    
    mineralMap["diamond"]=0; //단어 처리
    mineralMap["iron"]=1;
    mineralMap["stone"]=2;
    
    mineralNum=minerals.size();
    
    for(string i : minerals){
        mineralList.push_back(mineralMap[i]);
    }
    
    dfs(picks,0,0);
    
    return answer;
}
