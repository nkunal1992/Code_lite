#include <iostream>

long inefficient_power(int x, unsigned int n){
    if(1==x || 0==n)
        return 1;
    if(x==0)
        return 0;
        
    return x*inefficient_power(x,n-1);
}

// "Complexity - O(n)"
long iter_power(int x, unsigned int n){
    long res {1};
    for(unsigned int i {1}; i<=n; i++)
        res *= x;
        
    return res;
}

// "Complexity- O(log(n))"
long efficient_power(int x, unsigned int n){
    if(0==n || 1==x)
        return 1;
    if(0==x)
        return 0;
    // "& has less precedence than == "    
    if((n&1)==0) //even
        return efficient_power(x*x, n/2);
    else //odd
        return x*efficient_power(x*x, n/2);
}

int main()
{
    long pow = inefficient_power(2,4);
	std::cout << "pow(2,4) : " << pow << std::endl;
    
    pow = efficient_power(2,4);
	std::cout << "pow(2,4) : " << pow << std::endl;
    
    pow = efficient_power(2,5);
	std::cout << "pow(2,5) : " << pow << std::endl;
    
    pow = iter_power(2,6);
	std::cout << "pow(2,6) : " << pow << std::endl;
    
	return 0;
}
