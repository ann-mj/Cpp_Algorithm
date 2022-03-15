#include <iostream>
#include <string>
#include <vector>

using namespace std;
bool isok(char x) {
    if (islower(x) || isdigit(x) || x == '-' || x == '_' || x == '.') return 1;
    return 0;
}

string solution(string new_id) {
    string tmp ="";
    for (char &c : new_id) if (isupper(c)) c = tolower(c);
    for (char c : new_id) if (isok(c)) tmp += c;
    new_id = "";
    for (int i = 0; i < tmp.size(); i++) 
        if (tmp[i] != '.' || (!new_id.empty() && new_id.back() != '.')) new_id += tmp[i];
    if (new_id.back() == '.') new_id.pop_back();
    if (new_id.front() == '.') new_id = new_id.substr(1);
    if (new_id.empty()) new_id.push_back('a');
    if (new_id.size() >= 16) new_id = new_id.substr(0, 15);
    while (new_id.back() == '.') new_id.pop_back();
    while (new_id.size() <= 2) new_id += new_id.back();
    return new_id;
}

int main(void) {
    return 0;
}