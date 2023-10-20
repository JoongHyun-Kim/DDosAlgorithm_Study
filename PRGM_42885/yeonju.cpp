#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

// 무조건 몸무게가 큰 사람부터 태운다
// 10 20 30 80 80 90 100
// ! 최대 2명씩 밖에 탈 수 없다는 제한 ! 나중에 확인ㅜㅜ

bool cmp (int a, int b){
    return a>b;
}

int solution(vector<int> people, int limit) {
    int answer = 0;
    
    sort(people.begin(), people.end());
    int left =0, right = people.size()-1;
    
    while(left <=right){
        int sum= people[left] + people[right];
        if(sum > limit){
            right--;
            answer++;
        }
        else{
            left++;
            right--;
            answer++;
        }
    }
    
    return answer;
}
