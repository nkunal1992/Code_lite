#include <iostream>
#include <regex>
#include <string>
#include <vector>

using namespace std;

vector<double> findreal(string subject){
    vector<double> real;
    std::regex re("[-+]?(\\d+)?[.]\\d+([eE][+-]?\\d+)?");
    std::sregex_iterator next(subject.begin(), subject.end(), re);
    std::sregex_iterator end;
    while (next != end) {
        std::smatch match = *next;
        real.push_back(stod(match.str()));
        next++;
    }
    return real;
}

vector<int> findint(string subject){
    vector<int> integer;
    std::regex re("[-+]?\\d+");
    std::sregex_iterator next(subject.begin(), subject.end(), re);
    std::sregex_iterator end;
    while (next != end) {
        std::smatch match = *next;
        integer.push_back(stoi(match.str()));
        next++;
    }
    return integer;
}

vector<string> tokenize(const string subject){
    vector<string> str;
    std::regex re("[\\S]+");
    std::sregex_iterator next(subject.begin(), subject.end(), re);
    std::sregex_iterator end;
    while (next != end) {
        std::smatch match = *next;
        str.push_back(match.str());
        next++;
    }
    return str;
}

int main()
{
	std::string subject("123This is a -.789 test 123 *67*   1237.89e-1 123.h78");
    
    vector<double> res = findreal(subject);
    vector<int> res1 = findint(subject);
    vector<string> res2 = tokenize(subject);
//    int total {0};
    for(auto num:res2){
        cout<<num<<endl;
//        total += num;
    }
//    cout<<total<<endl;
    
	return 0;
}
