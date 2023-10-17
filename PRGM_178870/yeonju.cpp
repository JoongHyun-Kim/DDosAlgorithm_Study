#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <climits>
#include <utility>

// 1. 투포인터로 가능한 경우를 모두 찾아보자
// 정답이 될 수 있을만한 수열을 찾고
// 그 중에서 길이(두 인덱스 간의 차)가 가장 짧은 것을 리턴하자

// 2. DP로 합을 다 찾아보자
// 그리고 k와 같은 곳의 인덱스를 찾아서 출력하자

using namespace std;

bool cmp(pair<int,int> a, pair<int,int>b){
    int tempA = abs(a.second - a.first);
    int tempB = abs(b.second - b.first);
    
    if(tempA < tempB){
        return a>b;
    }
    else if(tempA == tempB){
        if(a.first < b.first){
            return a>b;
        }
    }
    else{
        return a < b;
    }
    
}

vector<int> solution(vector<int> sequence, int k) {
vector<int> answer;
    
    int left = 0, right = 0;
    int len = sequence.size()+1;
    int sum = sequence[0];
    pair<int, int> result;
    
    while(left <= right && right < sequence.size()){
        if(sum == k){
//             길이가 더 짧은 수열이면 갱신
//             어차피 앞에서부터 보기 시작한다 
            if (right-left+1 < len) {
                len = right-left+1;
                result = {left, right};
            } 
            sum-=sequence[left];
            left++;
            
        }
        else if(sum < k){
            right++;
            sum+=sequence[right];
        }
        else if(sum > k ){
            sum-=sequence[left];
            left++;
        }  
    }
    
    answer.push_back(result.first);
    answer.push_back(result.second);
    

    return answer;
}
