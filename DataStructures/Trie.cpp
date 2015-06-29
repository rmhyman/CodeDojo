/*
 * Trie.cpp
 *
 *  Created on: Jun 28, 2015
 *      Author: rmhyman
 */
#include <string>
#include <vector>
using namespace std;
class TrieNode {
public:
    // Initialize your data structure here.
    TrieNode()
    :branches(26,nullptr)
    {

    }
    TrieNode* BranchTo(char c){
        int index = c % 26;
        return branches[index];
    };
    void AddBranchTo(char c){
      int index = c % 26;
      TrieNode* tmp(new TrieNode);
      branches[index] = std::move(tmp);
    };
    bool AllEmptyBranches(){
      for(auto & branch : branches){
          if(branch != nullptr)
            return false;
      }
      return true;
    };
    ~TrieNode(){
        for(auto & branch : branches){
            delete branch;
        }
    }
    private:
    vector<TrieNode*> branches;
};

class Trie {
public:
    Trie()
    : root(new TrieNode())
    {

    };

    // Inserts a word into the trie.
    void insert(string word) {
    TrieNode* ptr = root;
    for(auto & c : word){
        if(ptr->BranchTo(c) == nullptr){
            ptr->AddBranchTo(c);
            ptr = ptr->BranchTo(c);
        }
        else{
            ptr = ptr->BranchTo(c);
        }
    }

    };

    // Returns if the word is in the trie.
    bool search(string word) {
        TrieNode* ptr = root;
    for(auto & c : word){
        if(ptr->BranchTo(c) == nullptr){
            return false;
        }
        else{
            ptr = ptr->BranchTo(c);
        }
    }
        if(ptr->AllEmptyBranches()){
          return true;
        }
        else{
            return false;
        }

            return false;
    };

    // Returns if there is any word in the trie
    // that starts with the given prefix.
    bool startsWith(string prefix) {
        TrieNode* ptr = root;
    for(auto & c : prefix){
        if(ptr->BranchTo(c) == nullptr){
            return false;
        }
        else{
            ptr = ptr->BranchTo(c);
        }
    }
    return true;
    };

private:
    TrieNode* root;
};

// Your Trie object will be instantiated and called as such:
// Trie trie;
// trie.insert("somestring");
// trie.search("key");

int main (){

	Trie trie;
	trie.insert("ab");
	trie.search("a");
	return 0;
}
