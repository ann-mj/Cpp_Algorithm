#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Stage {
    public:
    int num;
    double failure;
    
    Stage(int a) {
        num = a;
    }
    
    void cal_failure(vector<int> &stages) {
        int cnt = 0;
        int same = 0;
        for(int s : stages) {
            if(s >= this->num) {
                if(s == this->num) {
                    same++;
                }
                cnt++;
            }
        }
        if(cnt == 0) {
            this->failure = 0;
        } else {
            this->failure = (double) same/cnt;
        }
    }
    
    bool operator<(Stage f){
      if(this->failure == f.failure) return this->num < f.num; //주의할 점 적용
      return this->failure > f.failure; //내림차순으로 정렬
    }
};

vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    vector<Stage> candi;
    for(int i=1; i<=N; i++) {
        Stage sg(i);
        sg.cal_failure(stages);
        candi.push_back(sg);
    }

    sort(candi.begin(), candi.end());

    for(auto& a : candi){
        answer.push_back(a.num);
    }
    return answer;
}

int main(){
  vector<int> stages = {2, 1, 2, 6, 2, 4, 3, 3};
  //vector<int> stages = {4,4,4,4,4};
  vector<int> s = solution(5,stages);
  for(auto& a : s){
    cout << a;
  }
}