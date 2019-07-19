// Section 19
// Challenge 3
// Word counter
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    ifstream in_file;
    in_file.open("../romeoandjuliet.txt");
    
    if(!in_file){
        cerr<<"Error opening file"<<endl;
        exit(1);
    }
    string search {};
    cout<<"Enter the word to search : ";
    cin>>search;
    cout<<endl;
    
    unsigned int scount {0}, total {0};
    string word {};
    while(in_file>>word){
        size_t found = word.find(search);
        if(found!=string::npos)
            scount++;
        total++;
    }
    in_file.close();
    
    cout<<"Total words searched : "<<total<<endl;
    cout<<search<<" found "<<scount<<" times."<<endl;
    cout << endl;
    return 0;
}

