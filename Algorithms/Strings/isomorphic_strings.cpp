/*
 * isomorphic_strings.cpp
 *
 *  Created on: Aug 25, 2015
 *      Author: rmhyman
 */
#include<string>
using namespace std;

class Solution {
public:
bool isNoMapping(const unordered_map<char,char>& table, const array<bool,127>& mapped, const char c1, const char c2){
	//int index1 = c1 %127;
	int index2 = c2 % 127;
	auto tmp = table.find(c1);
	bool key_not_found = (tmp == table.end());
	//bool c1_mapped = mapped[index1];
	bool c2_mapped = mapped[index2];
	return (key_not_found && !c2_mapped);
	//return (key_not_found && !c1_mapped && !c2_mapped);
}

bool isPreviousMapping(const unordered_map<char,char>& table,const char c1, const char c2){
	auto tmp = table.find(c1);
	if(tmp == table.end())
		return false;
	else{
		if(tmp->second == c2)
			return true;
		else
			return false;
	}

	return false;
}
bool isIsomorphic(string s, string t) {

        std::unordered_map<char,char> table;
        const int array_size = 127;
        std::array<bool,array_size> mapped_already = {false};
        int max = s.size();
        if(max == 0){
            return true;
        }
        for(int i = 0; i < max; ++i){
            int index = t[i] % array_size;
            if(isNoMapping(table,mapped_already,s[i], t[i])){
            	table.insert({s[i],t[i]});
            	mapped_already[index] = true;
            }
            else if(!isPreviousMapping(table,s[i], t[i])){
            	return false;
            }
        }
        return true;
    }

};



