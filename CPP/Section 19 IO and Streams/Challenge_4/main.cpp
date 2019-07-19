// Section 19
// Challenge 4
// Copy Romeo and Juliet with line numbers
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

bool is_white(const std::string &line){
    if(line.find_first_not_of(' ') == std::string::npos || line=="\r")
        return true;
    return false;
}

int main() {
    std::ifstream in_file;
    std::ofstream out_file;
    
    in_file.open("../romeoandjuliet");
    if(!in_file){
        std::cerr<<"Error opening file"<<std::endl;
        exit(1);
    }
    
    out_file.open("../out1.txt");
    if(!out_file){
        std::cerr<<"Error opening/creating file"<<std::endl;
        exit(1);
    }
    
    std::string line {};
    unsigned int lnum {0};
    
    while(std::getline(in_file,line)){
        if(is_white(line)){
            out_file<<line<<std::endl;
        }
        else{
            lnum++;
            out_file<<std::setw(8)<<std::left<<lnum;
            out_file<<line<<std::endl;
        }
        
    }
    in_file.close();
    out_file.close();
    return 0;
}

