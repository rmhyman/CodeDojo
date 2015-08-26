/*
 * AngryProfessor.cpp
 *
 *  Created on: Aug 25, 2015
 *      Author: rmhyman
 */
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

vector<int> InitStudentTimes(const int num_students){
    vector<int> times;
    int val = 0;
    times.reserve(num_students);
    for(int i = 0; i < num_students; ++i){
        cin >> val;
        times.push_back(val);
    }
    return times;
}
string DetermineCancellation(const vector<int>& arrivals,const int threshold){
   int count = std::count_if(arrivals.begin(),arrivals.end(),[](const int val){return val <= 0;});
   if(count >= threshold){
       return "NO";
   }
    else {
        return "YES";
    }

    return "YES";
}
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int num_test_cases = 0;
    int num_students = 0;
    int cancelled_threshold = 0;
    vector<int> student_times;
    cin >> num_test_cases;
    for(int i = 0; i < num_test_cases; ++i ){
        cin >> num_students;
        cin >> cancelled_threshold;
        student_times = InitStudentTimes(num_students);
        cout << DetermineCancellation(student_times,cancelled_threshold) << endl;
    }
    return 0;
}




