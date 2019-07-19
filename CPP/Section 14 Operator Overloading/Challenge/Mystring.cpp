#include <iostream>
#include <cstring>
#include "Mystring.h"

 // No-args constructor
Mystring::Mystring() 
    : str{nullptr} {
    str = new char[1];
    *str = '\0';
}

// Overloaded constructor
Mystring::Mystring(const char *s) 
    : str {nullptr} {
        if (s==nullptr) {
            str = new char[1];
            *str = '\0';
        } else {
            str = new char[strlen(s)+1];
            strcpy(str, s);
        }
}

// Copy constructor
Mystring::Mystring(const Mystring &source) 
    : str{nullptr} {
        str = new char[strlen(source.str)+ 1];
        strcpy(str, source.str);
 //       std::cout << "Copy constructor used" << std::endl;

}

// Move constructor
Mystring::Mystring( Mystring &&source) 
    :str(source.str) {
        source.str = nullptr;
//        std::cout << "Move constructor used" << std::endl;
}

 // Destructor
Mystring::~Mystring() {
    delete [] str;
}

 // Copy assignment
Mystring &Mystring::operator=(const Mystring &rhs) {
//    std::cout << "Using copy assignment" << std::endl;

    if (this == &rhs) 
        return *this;
    delete [] str;
    str = new char[strlen(rhs.str) + 1];
    strcpy(str, rhs.str);
    return *this;
}

// Move assignment
Mystring &Mystring::operator=( Mystring &&rhs) {
 //   std::cout << "Using move assignment" << std::endl;
    if (this == &rhs) 
        return *this;
    delete [] str;
    str = rhs.str;
    rhs.str = nullptr;
    return *this;
}


// Display method
void Mystring::display() const {
    std::cout << str << " : " << get_length() << std::endl;
}

 // getters
 int Mystring::get_length() const { return strlen(str); }
 const char *Mystring::get_str() const { return str; }

// overloaded insertion operator
std::ostream &operator<<(std::ostream &os, const Mystring &rhs) {
    os << rhs.str;
    return os;
}

// overloaded extraction operator
std::istream &operator>>(std::istream &in, Mystring &rhs) {
    char *buff = new char[1000];
    in >> buff;
    rhs = Mystring{buff};
    delete [] buff;
    return in;
}

//added by me for member method
/*
Mystring Mystring::operator - (){
    char * buff;
    buff = new char [std::strlen(str) + 1];
    std::strcpy(buff,str);
    
    for(size_t i {0};i<std::strlen(buff);i++)
        buff[i] = std::tolower(buff[i]);
        
    Mystring temp {buff};
    
    delete [] buff;
    return temp;
}

bool Mystring::operator == (const Mystring &rhs)const{
    return (std::strcmp(str,rhs.str) == 0);
}

bool Mystring::operator != (const Mystring &rhs)const{
    return (std::strcmp(str,rhs.str) != 0);
}

bool Mystring::operator < (const Mystring &rhs)const{
    return (std::strcmp(str,rhs.str) < 0);
}

bool Mystring::operator > (const Mystring &rhs)const{
    return (std::strcmp(str,rhs.str) > 0);
}
Mystring Mystring::operator + (const Mystring &rhs){
    char *buff;
    buff = new char [std::strlen(str) + std::strlen(rhs.str) + 1];
    std::strcat(buff,str);
    std::strcat(buff,rhs.str);
    
    Mystring temp {buff};
    delete [] buff;
    return temp;
}

void Mystring::operator += (const Mystring &rhs){
    char *buff;
    buff = new char [std::strlen(str) + std::strlen(rhs.str) + 1];
    std::strcpy(buff,str);
    std::strcat(buff,rhs.str);
    
    delete [] str;
    str = buff;
    buff = nullptr;
    delete [] buff;
}

Mystring Mystring::operator * (unsigned int n){
    char *buff;
    buff = new char [std::strlen(str)*n + 1];
    
    strcpy(buff,str);
    for(size_t i {0};i<n-1;i++)
        std::strcat(buff,str);
    
    Mystring temp {buff};
    delete [] buff;
    return temp;
}

void Mystring::operator *= (unsigned int n){
    char *buff;
    buff = new char [std::strlen(str)*n + 1];
    
    strcpy(buff,str);
    for(size_t i {0};i<n-1;i++)
        std::strcat(buff,str);
        
    delete [] str;
    str = buff;
    buff = nullptr;
    delete [] buff;
}

Mystring &Mystring::operator ++(){
    for(size_t i {0};i<std::strlen(str);i++)
        str[i]=std::toupper(str[i]);
    return *this;
}

Mystring Mystring::operator++(int) {   // post-increment
   Mystring temp (*this);       // make a copy
   operator++();                    // call pre-increment - make sure you call pre-increment!
   return temp;                     // return the old value
}
*/
//added by me for global method
Mystring operator - (const Mystring &rhs){
    char * buff;
    buff = new char [std::strlen(rhs.str) + 1];
    std::strcpy(buff,rhs.str);
    
    for(size_t i {0};i<std::strlen(buff);i++)
        buff[i] = std::tolower(buff[i]);
        
    Mystring temp {buff};
    
    delete [] buff;
    return temp;
}

bool operator == (const Mystring &lhs,const Mystring &rhs){
    return (std::strcmp(lhs.str,rhs.str) == 0);
}

bool operator != (const Mystring &lhs,const Mystring &rhs){
    return (std::strcmp(lhs.str,rhs.str) != 0);
}

bool operator < (const Mystring &lhs,const Mystring &rhs){
    return (std::strcmp(lhs.str,rhs.str) < 0);
}

bool operator > (const Mystring &lhs,const Mystring &rhs){
    return (std::strcmp(lhs.str,rhs.str) > 0);
}
Mystring operator + (const Mystring &lhs,const Mystring &rhs){
    char *buff;
    buff = new char [std::strlen(lhs.str) + std::strlen(rhs.str) + 1];
    std::strcpy(buff,lhs.str);
    std::strcat(buff,rhs.str);
    
    Mystring temp {buff};
    delete [] buff;
    return temp;
}

void operator += (Mystring &lhs,const Mystring &rhs){
    char *buff;
    buff = new char [std::strlen(lhs.str) + std::strlen(rhs.str) + 1];
    std::strcpy(buff,lhs.str);
    std::strcat(buff,rhs.str);
    
    delete [] lhs.str;
    lhs.str = buff;
    buff = nullptr;
    delete [] buff;
}

Mystring operator * (const Mystring &lhs,unsigned int n){
    char *buff;
    buff = new char [std::strlen(lhs.str)*n + 1];
    
    strcpy(buff,lhs.str);
    for(size_t i {0};i<n-1;i++)
        std::strcat(buff,lhs.str);
    
    Mystring temp {buff};
    delete [] buff;
    return temp;
}

void operator *= (Mystring &lhs,unsigned int n){
    char *buff;
    buff = new char [std::strlen(lhs.str)*n + 1];
    
    strcpy(buff,lhs.str);
    for(size_t i {0};i<n-1;i++)
        std::strcat(buff,lhs.str);
        
    delete [] lhs.str;
    lhs.str = buff;
    buff = nullptr;
    delete [] buff;
}

Mystring & operator ++(Mystring &obj){
    for(size_t i {0};i<std::strlen(obj.str);i++)
        obj.str[i]=std::toupper(obj.str[i]);
    return obj;
}

Mystring operator++(Mystring &obj,int) {   // post-increment
   Mystring temp {obj};       // make a copy
   ++obj;                    // call pre-increment - make sure you call pre-increment!
   return temp;                     // return the old value
}