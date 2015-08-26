/*
 * SnakesAndLadders.cpp
 *
 *  Created on: Aug 25, 2015
 *      Author: rmhyman
 */
#include<vector>
#include<iostream>
#include<algorithm>
#include <array>
#include <stack>
#include<memory>
#include <queue>
using namespace std;

struct Square{
	unsigned short num = 0;
	bool visited = false;
	array<std::shared_ptr<Square>,2> neighbors = {{nullptr, nullptr}};
	unsigned short shortest_path_node_num = 0;
    bool has_ladder = false;
    bool has_snake = false;

};

vector<std::shared_ptr<Square>> ConstructBoard(const int num_ladders_, const int num_snakes_){
	vector<std::shared_ptr<Square>> board;
	board.reserve(100);
	for(int i = 0; i < 100; ++i){
		std::shared_ptr<Square> p(new Square);
		p->num = i + 1;
		board.push_back(std::move(p));
	}
	int num_ladders(num_ladders_);
	int num_snakes(num_snakes_);
	for(int i = 0; i < board.size(); ++i){
		if(i < board.size() - 1){
			board[i]->neighbors[0] = board[i+1];
		}

	}

	return board;
}
vector<std::shared_ptr<Square>> ConstructLaddersAndSnakes(const vector<std::shared_ptr<Square>>& board_,const int n_, bool is_snakes){

	vector<std::shared_ptr<Square>> board(board_);
	int start,end;
	int n(n_);
		while(n--){
			cin >> start;
			cin >> end;
             if(is_snakes){

			board[start-1]->neighbors[1] = board[end-1];
               board[start-1]->has_snake = true;
             }
            else{
			board[start-1]->neighbors[1] = board[end-1];

            board[start-1]->has_ladder = true;
            }
		}
		return board;
}

vector<std::shared_ptr<Square>> ComputeShortestPath(const vector<std::shared_ptr<Square>>& board_){
	vector<std::shared_ptr<Square>> board(board_);
	queue<std::shared_ptr<Square>> tmp;
	tmp.push(board[0]);
	while(!tmp.empty()){
		auto square = tmp.front();
		tmp.pop();
		if(!square->visited){
			square->visited = true;
			if(square->neighbors[0] != nullptr && square->neighbors[0]->shortest_path_node_num == 0){
				square->neighbors[0]->shortest_path_node_num = square->num;
              //  cout << "node with num " << square->neighbors[0]->num  << " is visited first by " << square->num << endl;
				tmp.push(square->neighbors[0]);
			}
			if(square->neighbors[1] != nullptr&& square->neighbors[1]->shortest_path_node_num == 0){
				square->neighbors[1]->shortest_path_node_num = square->num;
               // cout << "node with num " << square->neighbors[1]->num << " is visited first by " << square->num << endl;
				tmp.push(square->neighbors[1]);
			}

		}
	}

		return board;
}
std::stack<int> ExecuteRoll(const vector<std::shared_ptr<Square>>& board, const std::stack<int>& path){
    std::stack<int> new_path(path);
    int pos = 0;
    for(int i = 0; i < 6; ++i){
        if(new_path.empty()){
            return std::stack<int>();
        }
        pos = new_path.top();
       //cout << " pos is " << pos << endl;
        if(i == 5 && board[pos-1]->has_snake ){
            /*
            int tmp =  new_path.top();
            new_path.pop();
            if(!new_path.empty() && (tmp != board[pos-1]->neighbors[1]->num)){
                //We have a false path thus no solution
                std::stack<int> no_path;
                no_path.push(-1);
                return no_path;
            }
            else{
                new_path.push(tmp);
            }
            */
            break;
        }
        else if(board[pos-1]->has_ladder ){
            int tmp =  new_path.top();
            //cout << "tmp is " << tmp << endl;
            new_path.pop();
           //cout << "next top is " << new_path.top() << endl;
            if(!new_path.empty() && (new_path.top() - tmp) > 1){
            new_path.pop();
           //cout << "path.empty is " << new_path.empty() << endl;
            break;
            }
        }
        else if( board[pos-1]->has_snake){
            int tmp =  new_path.top();
            new_path.pop();
            if(!new_path.empty() && ( new_path.top() - tmp) < 1){
            new_path.pop();
            break;
            }
        }
        else{
            new_path.pop();

        }
    }
    //cout << endl;
    return new_path;

}
int CalculateMinRolls(const vector<std::shared_ptr<Square>>& board){
    int num_snakes = 0;
    int pos = 98;
    for(int i = 0; i < 6; ++i){
        if(board[pos-i]->has_snake)
            ++num_snakes;
    }
    if(num_snakes == 6){
        return -1;
    }
    std::stack<int> path;
    path.push(100);
    int tmp = 0;
    int min_rolls = 0;
    int i = 100;
    //cout << "tos is " << path.top() << endl;
    int node =board[i-1]->shortest_path_node_num;
    while(path.top() != 1 && i > 0){
        path.push(node);
    //cout << "tos is " << path.top() << endl;
        node =board[node-1]->shortest_path_node_num;
        --i;

    }
    i = 100;
    path.pop();
    while(!path.empty()  && i > 0 && (path.top() != -1)){
    path = ExecuteRoll(board,path);
        ++min_rolls;
    --i;
    }
    if(!path.empty() && path.top() == -1)
        return -1;

    return min_rolls;
}

int main(){
	int t;
	cin >> t;
	int m;
	int n;
	while(t--){
		vector<std::shared_ptr<Square>> tmp = ConstructBoard(m,n);
		cin >> m;
		tmp = ConstructLaddersAndSnakes(tmp,m,false);

		cin >> n;
		tmp = ConstructLaddersAndSnakes(tmp,n,true);
		tmp =ComputeShortestPath(tmp);

        cout << CalculateMinRolls(tmp)  << endl;

	}
	return 0;
}



