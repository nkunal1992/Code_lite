// Section 19
// Challenge 2
// Automated Grader
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <iomanip>
using namespace std;

int calc_score(const string &responses, const string &stud_resp){
    size_t l = responses.length();
    unsigned int score {0};
    for(size_t i {0}; i<l; i++){
        if(responses.at(i)==stud_resp.at(i))
            score++;
    }
    return score;
}
int main() {
    ifstream in_file;
    in_file.open("../responses.txt");
    if(!in_file){
        cerr<<"Error opening file"<<endl;
        exit(1);
    }
    string responses {};
    in_file>>responses;
    
    vector <string> students {};
    vector <string> response {};
    
    string stud {};
    string stud_res {};
    while(in_file>>stud>>stud_res)
    {
        students.push_back(stud);
        response.push_back(stud_res);
    }
    in_file.close();
    
    size_t l = students.size();
    unsigned int total {0};
    
    cout<<setw(20)<<left<<"Student"<<setw(10)<<left<<"Score"<<endl;
    cout<<setw(30)<<setfill('-')<<""<<endl;
    cout<<setfill(' ');
    
    for(size_t i {0}; i<l; i++){
        unsigned int score = calc_score(responses,response.at(i));
        cout<<setw(20)<<left<<students.at(i)<<setw(10)<<left<<score<<endl;
        total += score;
    }
    
    cout<<setw(30)<<setfill('-')<<""<<endl;
    cout<<setfill(' ');
    
    double avg = static_cast<double>(total)/l;
    cout<<setw(20)<<left<<"Average score"<<setw(10)<<left<<avg<<endl;
    return 0;
}

