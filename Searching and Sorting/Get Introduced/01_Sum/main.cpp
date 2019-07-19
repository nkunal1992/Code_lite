#include <iostream>

int rec_sum(unsigned int n){
    if(n==0)
        return 0;
        
    if(n==1)
        return 1;
        
    return n+rec_sum(n-1);
}

int iter_sum(unsigned int n){
    int  s {0};
    for(int i {1}; i<=n; i++)
        s += i;
        
    return s;
}

int main()
{
    int sum = rec_sum(10);
	std::cout << "Sum : " << sum << std::endl;
    
    sum = iter_sum(10);
	std::cout << "Sum : " << sum << std::endl;
	return 0;
}
