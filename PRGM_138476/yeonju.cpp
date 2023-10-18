#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

bool cmp(int a, int b){
    return a>b;
}

int solution(int k, vector<int> tangerine) {
    int answer = 0;
    
    map<int, int> cnt;
    for(int i=0;i<tangerine.size();i++){
        cnt[tangerine[i]]++;
    }
    
    vector<int> result;
    for(auto u:cnt){
        result.push_back(u.second);
    }
    
    sort(result.begin(), result.end(),cmp);
    
    int sum=0;
    for(int i=0;i<result.size();i++){
        answer++;
        sum+=result[i];
        if(sum>=k) break;
    }
    
    return answer;
}
