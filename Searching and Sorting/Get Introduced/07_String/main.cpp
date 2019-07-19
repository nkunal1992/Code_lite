#include <iostream>
#include <string>
#include <cstring>
#include <stack>
#include <iomanip>
#include <vector>
#include <list>
#include <iterator>

void compute_lps(int *lps, const std::string &pattern, int l){
    int i {1}, j {0};
    
    while(i < l){
        if(pattern[i]==pattern[j]){
            j++;
            lps[i]=j;
            i++;
        }
        else{// pattern[i]!=pattern[j]
            if(j!=0)
                j = lps[j-1];
            else{// j==0
                lps[i] = 0;
                i++;
            }
        }
    }
}

void KMP(const std::string text, const std::string pattern, int * const lps, int m, int n){
    int i {0},j {0};
    while(i<n){
        if(text[i]==pattern[j]){
            j++;
            i++;
        }
        if(j==m){
            std::cout<<"kunal found at index "<<i-j<<std::endl;
            j = lps[j-1];
        }
        else if(i<n && text[i] != pattern[j]){
            if(j!=0)
                j = lps[j-1];
            else
                i++;
        }
    }
}

//swap values at two pointer
void swap(char *a, char *b){
    char temp = *a;
    *a = *b;
    *b = temp;
}

void permute(char *str, int start, int end){
    int i;
    if(start == end)
        std::cout<<str<<std::endl;
    else{
        for(i=start; i<=end; i++){
            swap((str+start),(str+i));
            permute(str, start+1, end);
            swap((str+start),(str+i));//backtrack
        }
    }
}

//Fix a center and expand in both direction
void longest_palindrome_subsequence(const std::string &str){
    int len {static_cast<int>(str.length())}, maxlen {1},low,high,start;
    
    for(int i {1}; i<len; i++){
        //even palindrome check
        low = i-1;
        high = i;
        while(low>=0 && high<len && str[low]==str[high]){
            if(maxlen < high-low+1){
                maxlen = high-low+1;
                start = low;
            }
            low--;
            high++;
        }
        //odd palindrome check
        low = i-1;
        high = i+1;
        while(low>=0 && high<len && str[low]==str[high]){
            if(maxlen < high-low+1){
                maxlen = high-low+1;
                start = low;
            }
            low--;
            high++;
        }
    }
    std::cout<<"Longest palindromic substring is "<<str.substr(start,maxlen)
        <<" and length = "<<maxlen<<std::endl;
}

void reverse_string_using_stack(std::string &str){
    std::stack<char> s;
    for(size_t i {0}; i<str.length(); i++){
        s.push(str[i]);
    }
    for(size_t i {0}; i<str.length(); i++){
        str[i] = s.top();
        s.pop();
    }
}

void reverse_string_without_temp(std::string &str){
    int start {0}, end {static_cast<int>(str.length()-1)};
    while(start < end){
        str[start] ^= str[end];
        str[end] ^= str[start];
        str[start] ^= str[end];
        ++start;
        --end;
    }
}

//count no of binary string without consecutive 1's
int count_binary_string(int n){
    /*
     * let a[i] be the no of binary strings of length i without consecutive 1's and which ends in 0.
     * let b[i] be no of such strings which end in 1.
     * we can append either 0 or 1 to a string ending in 0, but we can only append 0 to a string ending
     * in 1. this yields the recurrence relation:
     * a[i] = a[i-1] + b[i-1]
     * b[i] = a[i-1]
     */ 
     int a[n],b[n];
     a[0] = b[0] = 1;
     for(int i {1}; i<n; i++){
         a[i] = a[i-1] + b[i-1];
         b[i] = a[i-1];
     }
     
     return a[n-1]+b[n-1];
}

bool match_wildcard(char *first, char *second){
    //if we reach at end of both string
    if(*first == '\0' && *second == '\0')
        return true;
        
    //Make sure that the char after * are present in second string
    if(*first == '*' && *(first+1) != '\0' && *second == '\0')
        return false;
        
    if(*first == '?' || *first == *second)
        return match_wildcard(first+1, second+1);
        
    //If there is *, then there are 2 possibilities
    //a) We consider current char of second string
    //b) We ignore current char of second string
    if(*first == '*')
        return match_wildcard(first+1,second) || match_wildcard(first,second+1);
    
    return false;
}

void max_occuring_char(const std::string &str){
    int count[256] {0}, max_count {0}, i, len {static_cast<int>(str.length())};
    for(i = 0; i<len; i++)
        count[static_cast<int>(str[i])]++;
        
    char ch;
    for(i = 0; i<len; i++)
        if(count[static_cast<int>(str[i])] > max_count){
            max_count = count[static_cast<int>(str[i])];
            ch = str[i];
        }
    
    std::cout<<"Max occuring char in "<<str<<" is "<<ch<<" "<<max_count<<" times"<<std::endl;
}

//Function to count no of substrings with exactly k unique characters
void countKDistinct(std::string str, int k){
    int n {static_cast<int>(str.length())}, res {0};
    std::vector<std::string> substring;
    
    //Consider all substring starting with str[i]
    for(int i = 0; i < n; i++){
        int dist_count {0},cnt[256] {0};
        //consider all substrigs between str[i...j]
        for(int j = i;j < n; j++){
            //if this is a new char for this substring,
            //increment dist_count
            if(cnt[static_cast<int>(str[j])] == 0)
                dist_count++;
            
            //increment count of current character
            cnt[static_cast<int>(str[j])]++;
            
            //if distinct character count becomes k,
            //then increment result
            if(dist_count == k){
                res++;
                substring.push_back(str.substr(i,j-i+1));
            }
        }
    }
    
    std::cout << "\nNo of substrings with exactly "<<k<<" unique characters is : "<<res<<std::endl; 
    std::cout<<"Possible substrings are : ";
    for(auto &str1:substring)
        std::cout<<str1<<"  ";
    std::cout<<"\n"<<std::endl;
}

void max_depth_of_paranthesis(const std::string &str){
    int max {0}, current_max {0};
    
    for(size_t i {0}; i<str.length(); i++){
        if(str[i] == '(')
            current_max++;
        
        if(current_max > max)
            max = current_max;
        
        if(str[i] == ')'){
            if(current_max > 0)
                current_max--;
            else{
                std::cout << "\nParanthesis are not balanced\n"<<std::endl;
                return;
            }
        }
        
    }
    if(current_max != 0)
        std::cout << "\nParanthesis are not balanced\n"<<std::endl;
    else
        std::cout << "\nBalanced paranthesis with max depth : "<<max<<"\n"<<std::endl;
}

void convert_to_opposite_case(std::string &str){
    //Ascii values of alphabets: A-Z = 65 to 90, a-z = 97 to 122
    std::cout<<"Original string : "<<str<<std::endl;
    int len = static_cast<int>(str.length());
    for(int i {0}; i < len; i++){
        if(str[i] >= 'a' && str[i] <= 'z')
            str[i] = str[i]-32;
        else if(str[i] >= 'A' && str[i] <= 'Z')
            str[i] = str[i]+32;
    }
    std::cout<<"Resultant string : "<<str<<"\n"<<std::endl;
}

void addBinary(std::string a, std::string b){
    std::string res {""};
    int sum {0};
    
    //Traverse both string from end
    int i = a.size()-1, j = b.size()-1;
    while(i >= 0 || j >= 0 || sum == 1){
        //compute sum of last digits and carry
        sum += ((i>=0)?a[i]-'0':0);
        sum += ((j>=0)?b[j]-'0':0);
        
        //if current digit sum is 1 or 3, add 1 to result
        res = char(sum%2 + '0') + res;
        
        //carry
        sum /= 2;
        //move to next digit
        j--;i--;
    }
    std::cout<<"i/p1 :"<<a<<" i/p2 : "<<b<<std::endl;
    std::cout<<"sum : "<<res<<"\n"<<std::endl;
}

void encrypt(std::string &str, int s){
    //Ascii values of alphabets: A-Z = 65 to 90, a-z = 97 to 122
    std::cout<<"\nOriginal string : "<<str<<std::endl;
    std::string res {""};
    
    for(size_t i {0}; i < str.length(); i++){
        if(isupper(str[i]))
            res += char(int(str[i]+s-65)%26+65);
        else if(islower(str[i]))
            res += char(int(str[i]+s-97)%26+97);
        else
            res += str[i];
    }
    std::cout<<"Encrypted string : "<<res<<"\n"<<std::endl;
}

void getsecondMostFrequent(const std::string &str){
    int count[256] {0}, i;
    
    for(i = 0; str[i]; i++)
        count[static_cast<int>(str[i])]++;
        
    int first {0}, second {0};
    for(i=0;i<256;i++){
        if(count[i] > count[first]){
            second = first;
            first = i;
        }
        else if(count[i] > count[second] &&
                count[i] != count[first])
            second = i;
    }
    
    std::cout<<"\nSecond most frequent occuring char is : "<<char(second)<<"\n"<<std::endl;
}

int compare(const std::list<char> &list1, const std::list<char> &list2){
    auto it1 = list1.begin(), it2 = list2.begin();
    while( (it1 != list1.end()) && (it2 != list2.end()) && *it1 == *it2 ){
        it1++;
        it2++;
    }
    
    if( (it1 != list1.end()) && (it2 != list2.end()) )
        return (*it1 > *it2) ? 1:-1;
        
    if( (it1 != list1.end()) && (it2 == list2.end()) )
        return 1;
        
    if( (it1 == list1.end()) && (it2 != list2.end()) )
        return -1;
        
    return 0;
}

void printCommonCharacters(const std::string &str1, const std::string &str2){
    int a1[256] {0}, a2[256] {0};
    int l1 {static_cast<int>(str1.length())}, l2 {static_cast<int>(str2.length())};
    
    for(int i {0}; i < l1; i++)
        a1[static_cast<int>(str1[i])]++;
    
    for(int i {0}; i < l2; i++)
        a2[static_cast<int>(str2[i])]++;
        
    for(int i {0}; i < 256; i++){
        if(a1[i] != 0 && a2[i] != 0){
            int max_count = (a1[i] > a2[i])?a1[i]:a2[i];
            for(int j {0}; j < max_count; j++)
                std::cout<<char(i);
        }
    }
    std::cout<<"\n"<<std::endl;
}

void remove_spaces(std::string &str){
    std::cout<<"\nInput : "<<str<<std::endl;
    int i {0}, j {0};
    while(str[i]){
        if(str[i]!=' ')
            str[j++] = str[i];
        i++;
    }
    while(j < i)
    str[j++] = '\0';
    std::cout<<"Output : "<<str<<"\n"<<std::endl;
}

void isSubSequence(const std::string &str1, const std::string &str2){
    int j {0};
    
    for(int i {0}; i < static_cast<int>(str2.length()) && j < static_cast<int>(str1.length()); i++){
        if(str1[j] == str2[i])
            j++;
    }
    
    if(j == static_cast<int>(str1.length()))
        std::cout<<"\n"<<str1<<" is subsequence of "<<str2<<"\n"<<std::endl;
    else
        std::cout<<"\n"<<str1<<" is not a subsequence of "<<str2<<"\n"<<std::endl;
}

void printQueen(const std::vector<std::vector<int>> &ChessTable,int n) const{
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(ChessTable[i][j]==1)
                std::cout<<" Q ";
            else
                std::cout<<" - ";
        }
        std::cout<<"\n";
    }
}

void solve_queen(int n){
    std::vector<std::vector<int>> ChessTable(n,0);
    for(auto i; i<n; i++)
        ChessTable[i] = std::vector<int>(n,0);
        
    if(setQueens(ChessTable,0,n))
        printQueen(ChessTable,n);
    else
        std::cout<<"No solution exist\n"<<std::endl;
}

bool isPlaceValid(const std::vector<std::vector<int>> &ChessTable, int row, int col, int n){
    //check row 
    for(int i=0; i<col; i++)
        if(ChessTable[row][i]==1)
            return false;
            
    //check top left to bottom right diagonal
    for(int i=row,j=col; i>=0 && j>=0; i--,j--){
        if(ChessTable[i][j]==1)
            return false;
    }
    
    //check top right to bottom left
    for(int i=row,j=col; i<n && j>=0; i++,j--){
        if(ChessTable[i][j]==1)
            return false;
    }
    return true;
}

bool setQueens(std::vector<std::vector<int>> &ChessTable, int col, int n){
    if(col == n)
        return true;
    
    for(int row = 0; row < n; ++row){
        
        if(isPlaceValid(ChessTable,row,col)){
            
            chessTable[row][col] = 1;
            
            if(setQueens(col+1))
                return true;
                
            chessTable[row][col] = 0;
        }
    }
    
    return false;
}

int main(){
	std::cout << "Hello testing" << std::endl;
    std::string pattern {"kun"}, text {"my name is kunalku. He is kunalku's brother"};
    int m {static_cast<int>(pattern.length())}, n {static_cast<int>(text.length())};
    int lps[m];
    char a[] {"AB*d*C"}, b[] {"AByytdv4vy5C"};
    lps[0] = 0;
    std::string p {"forgeeksskeegfor"};
    compute_lps(lps,pattern,m);
    
    KMP(text, pattern, lps, m, n);
    
    std::cout<<pattern<<std::endl;
        
    std::cout<<std::endl;
    
    permute(a,0,2);
    longest_palindrome_subsequence(p);
    //reverse_string_using_stack(pattern);
    reverse_string_without_temp(pattern);
    std::cout<<pattern<<std::endl;
    std::cout<<count_binary_string(5)<<std::endl;
    std::cout<<std::boolalpha<<a<<" == "<<b<<" : "<<match_wildcard(a,b)<<std::endl;
    max_occuring_char(p);
    countKDistinct(std::string("+b+"),2);
    max_depth_of_paranthesis(std::string("(b)((c(t)))()"));
    std::string orig {"geeksForgEeks"};
    convert_to_opposite_case(orig);
    addBinary(std::string("11"),std::string("1"));
    std::string original {"ATTACKATONCE123"};
    encrypt(original,4);
    getsecondMostFrequent(original);
    
    std::list<char> list1 {'g','e','e','k','s'};
    std::list<char> list2 {'g','e','e','k','s','a'};
    std::cout<<"\nResult : "<<compare(list1, list2)<<"\n"<<std::endl;
    printCommonCharacters(std::string("geeks12*"), std::string("f*o2rgee1ks"));
    orig = "g e e k s   t";
    remove_spaces(orig);
//    std::cout<<"Output : "<<orig<<"\n"<<std::endl;
    isSubSequence(std::string("AXY"),std::string("YADXCP"));
    solve_queen(4);
	return 0;
}
