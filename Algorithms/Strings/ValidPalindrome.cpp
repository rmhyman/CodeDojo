/*
 * ValidPalindrome.cpp
 *
 *  Created on: Aug 25, 2015
 *      Author: rmhyman
 */
class Solution {
public:
    bool isPalindrome(string s) {
        if(s.empty() or s == " "){
            return true;
        }

        std::locale loc("C");
        auto is_a_char = [&] (char & c) -> bool {
            return (std::isalnum(c,loc));

        };

        auto make_upper = [&] (char & c) -> char {
            return std::toupper(c);
        };

        std::string only_chars = "";
        only_chars.reserve(sizeof(s));
        for(auto & c : s){
        	if(is_a_char(c)){
        		only_chars.push_back(c);
        	}
        }

        std::transform(only_chars.begin(),only_chars.end(),only_chars.begin(),make_upper);

        std::string reverse_copy_tmp = "";
        reverse_copy_tmp.reserve(sizeof(only_chars));
        for(auto ch = only_chars.rbegin(); ch != only_chars.rend(); ++ch){
        	reverse_copy_tmp.push_back(*ch);
        }

        if(not only_chars.compare(reverse_copy_tmp)){
            return true;
        }
        else{
            return false;
        }

    }
};



