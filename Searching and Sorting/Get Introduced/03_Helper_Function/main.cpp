#include <iostream>
#include <string>

void swap1(int *a, int *b){
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

void swap2(int &a, int &b){
    int temp;
    temp = a;
    a = b;
    b = temp;
}

// without extra variable
void swap3(int &a, int &b){
    a = a^b;
    b = a^b;
    a = a^b;
}

// without extra variable
void swap4(int &a, int &b){
    a = a+b;
    b = a-b;
    a = a-b;
}

void swap5(std::string &a, std::string &b){
    std::string temp = a;
    a = b;
    b = temp;
}

int main()
{
    int a {10}, b{20};
	std::cout << a << "\t" <<b << std::endl;
    swap1(&a,&b);
    std::cout << a << "\t" <<b << std::endl;
    
    a=20;
    b=30;
    std::cout << a << "\t" <<b << std::endl;
    swap4(a,b);
    std::cout << a << "\t" <<b << std::endl;
    
    std::string s1 {"Narayan"}, s2 {"Nikki"};
    std::cout << s1 << "\t" << s2 << std::endl;
    swap5(s1,s2);
    std::cout << s1 << "\t" << s2 << std::endl;
	return 0;
}
