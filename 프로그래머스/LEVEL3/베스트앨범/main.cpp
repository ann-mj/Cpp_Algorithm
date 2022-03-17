#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <iostream>

using namespace std;

class genre {
    public:
    string name;
    int plays;
    
    genre(string name, int plays) {
        this->name = name;
        this->plays = plays;
    }
    
    bool operator<(genre& o) {
        return plays > o.plays;
    }
};

class song {
    public:
    int id;
    int plays;
    
    song(int id, int plays) {
        this->id = id;
        this->plays = plays;
    }
    
    bool operator<(song& o) {
        if(plays == o.plays) {
            return id < o.id;
        } else {
            return plays > o.plays;
        }
    }
};

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    
    // 장르별 재생횟수 누적
    unordered_map<string,int> gmap;
    unordered_map<string,vector<int>> gmap_plays;
    for(int i=0; i<plays.size(); i++) {
        gmap[genres[i]] += plays[i];
        gmap_plays[genres[i]].push_back(i);
    }
    
    // value 기준 정렬 ..
    vector<genre> gvector;
    for(auto a : gmap) {
        genre g(a.first, a.second);
        gvector.push_back(g);
    }
    
    sort(gvector.begin(), gvector.end());
    
    for(int i=0; i<gvector.size(); i++) {
        // 가장 많은 장르
        genre mem = gvector[i];
        
        vector<song> songs;
        for(auto b : gmap_plays[mem.name]) {
           song s(b, plays[b]);
           songs.push_back(s);
        }
        sort(songs.begin(), songs.end());

        int size = 0;
        if(songs.size() > 1) {
            size = 2;
        } else {
            size = 1;
        }
        for(int i=0; i<size; i++) {
            answer.push_back(songs[i].id);
        }
    }
    return answer;
}