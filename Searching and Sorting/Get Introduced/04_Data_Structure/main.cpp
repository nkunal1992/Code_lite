#include <iostream>

void printArray(int *arr, int n){
    for(int i {0}; i<n; i++)
        std::cout << arr[i] << "\t";
    std::cout << std::endl;
}

size_t strlen(const char *str){
    size_t i {0};    
    while(str!=NULL && *str++!='\0')
            i++;
    return i;
}

int main()
{
	int arr[10] {5,10};
    char name[25] {"Nikki Narayan"};
    printArray(arr,10);
    std::cout <<strlen(name)<<std::endl;
	return 0;
}
