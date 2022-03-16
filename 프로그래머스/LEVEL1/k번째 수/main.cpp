#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    vector<int> candi;
    for(vector<int> command : commands) {
        candi.clear();
        int from = command[0];
        int to = command[1];
        int seq = command[2];
        for(int i=0; i<to-from+1; i++) {
            candi.push_back(array[from+i-1]);
        }
        sort(candi.begin(), candi.end());
        answer.push_back(candi[seq-1]);
    }
    return answer;
}