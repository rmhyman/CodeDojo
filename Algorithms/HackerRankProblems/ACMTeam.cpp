/*
 * ACMTeam.cpp
 *
 *  Created on: Aug 25, 2015
 *      Author: rmhyman
 */
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <functional>
using namespace std;
char KnowTopic(const char p1, const char p2){
    if(p1 == '1' || p2 == '1'){
        return '1';
    }
    else{
        return '0';
    }

    return '0';
}
int MaxTeamTopic(const string& p1, const string& p2){
    string s(p1.size(),'c');
    std::function<char(const char, const char)> f1(KnowTopic);
    std::transform(p1.begin(),p1.end(),p2.begin(),s.begin(),f1);
    int max_topics = std::count_if(s.begin(),s.end(),[](const char c){return c == '1';});
    return max_topics;
}
std::pair<int,int> ComputeMaxTeamsAndTopics(const vector<string>& ppl, const int size){
    int result = 0;
    int max_teams = 0;
    int max_topics = 0;
    for(int i = 0; i < size; ++i){
        for(int j = 0; j < size; ++j){
            if(i != j){
                result = MaxTeamTopic(ppl[i], ppl[j]);

                if(result > max_topics){
                    max_topics = result;
                    max_teams = 1;
                }
                else if(result == max_topics){
                    ++max_teams;
                }

    //cout << max_topics << endl << max_teams << endl;
            }
        }
    }
    max_teams /= 2;
    return std::make_pair(max_topics,max_teams);
}
vector<string> ConstructPplVec(const int num_ppl, const int num_of_topics){
    string s;
    s.reserve(num_of_topics);
    vector<string> ppl;
    ppl.reserve(num_ppl);
    for(int i = 0; i < num_ppl; ++i){
        cin >> s;
        ppl.push_back(s);

    }
    return ppl;
}


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n, m;
    cin >>n>>m;
    vector<string> ppl = ConstructPplVec(n,m);
    std::pair<int,int> results = ComputeMaxTeamsAndTopics(ppl,  n);
    cout << results.first << endl << results.second << endl;
    return 0;
}




