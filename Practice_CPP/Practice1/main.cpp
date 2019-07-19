#include <iostream>
#include <cstring>
#include <string>
using namespace std;

size_t strnlen(const char *str){
    if(str==nullptr)
        return 0;
    int i {0};
    while(str[i++]!='\0');
    return i-1;
}

int strncmp(const char *str1, const char *str2){
    size_t l1 {strnlen(str1)}, l2 {strnlen(str2)};
    
    if(l1==0 && l2==0)
        return 0;
        
    while(*str1!='\0' && *str2!='\0')
    {
        if(*str1<*str2)
            return -1;
        else if(*str1>*str2)
            return 1;
        else{
            str1++;
            str2++;
        }
    }
    
    if(l1==l2)
        return 0;
    else if(l1>l2)
        return 1;
    else
        return -1;
}

char* strncat1(char *dest, const char*source){
    size_t buff_size = strnlen(dest)+strnlen(source);
    char *temp = new char [buff_size];
    
    size_t i {0},j {0};
    for(;i<strnlen(dest);i++)
        temp[i]=dest[i];
        
    for(;i<buff_size;i++)
        temp[i]=source[j++];
    
    temp[i]='\0';
    
    dest = temp;
    
    temp = nullptr;
    
    return dest;
}

char* strncat(char *dest, const char*source){
    size_t buff_size = strnlen(dest)+strnlen(source)+1;
    
    size_t i {strnlen(dest)},j {0};
    for(;i<buff_size;i++)
        dest[i]=source[j++];
     
    return dest;
}

char* strncpy(char *dest, const char *src){
    size_t buff_size {strnlen(src)+1};
    for(size_t i {0}; i<buff_size; i++)
        dest[i]=src[i];
        
    return dest;
}

int tolower1(int c){
    if(c>=65 && c<=90)
        return c+32;
    
    return c;
}

int toupper1(int c){
    if(c>=97 && c<=122)
        return c-32;
    return c;
}

int strcmp_ig_case(const char *str1, const char *str2){
    size_t l1 {strnlen(str1)+1},l2 {strnlen(str2)+1};
    char *temp1 {new char[l1]},*temp2 {new char[l2]};
    
    for(size_t i{0}; i<l1; i++)
        temp1[i]=tolower1(str1[i]);
    for(size_t i{0}; i<l2; i++)
        temp2[i]=tolower1(str2[i]);
        
    int ret = strncmp(temp1,temp2);
    delete [] temp1;
    delete [] temp2;
    
    return ret;
}
int isalnum(int c){
    if((c>=65 && c<=90) || (c>=97 && c<=122) || (c>=48 && c<=57))
        return 1;
    return 0;
}

int isPalindrome(string A) {
    char * temp1 = new char [A.length()+1],c;
    int j {0};
    for(size_t i {0}; i<A.length() ; i++){
        c=A[i];
        if((c>=65 && c<=90) || (c>=97 && c<=122) || (c>=48 && c<=57)){
            if((c>=65 && c<=90))
                temp1[j++]=A[i]+32;
            else
                temp1[j++]=A[i];
        }
    }
        
    temp1[j]='\0';

    j=0;
    
    string temp {temp1};
    delete [] temp1;

    char* rev1 = new char [temp.length()+1];
    for(int i {temp.length()-1}; i>=0; i--)
        rev1[j++]=temp[i];
    
    rev1[j]='\0';

    string rev {rev1};
    delete [] rev1;
    
    if(temp==rev)
        return 1;
    else 
        return 0;
}


int main()
{
    char name[] {"abba"}, name1[] {"def"};
    string A {name}, B{"abba"};
//	cout << strnlen(name1) << sizeof(name)<<endl;
//    cout << strncat(name,name1) <<endl;
//    cout << strcmp_ig_case("ABC__im","aBc__Im") <<endl;
//    cout << A.length() <<endl;
    cout << isPalindrome(A) <<endl;
	return 0;
}
