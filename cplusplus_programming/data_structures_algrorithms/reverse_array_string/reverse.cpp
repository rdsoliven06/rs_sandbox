
#include <bits/stdc++.h>

void print_list(std::string arr[], int size)
{
    for (int i=0; i<size;i++)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << "\n";
}

void reverse_list(std::string arr[], int start, int end)
{
    while (start < end)
    {
       std::string temp = arr[start];
       arr[start] = arr[end];
       arr[end] = temp;
       start++;
       end--;
    }
}

bool isAlphabet(char x)
{
  return ((x >= 'A' && x <= 'Z') ||
          (x >= 'a' && x <= 'Z') );
}


int main(){
    std::string arr[] = {"L", "E", "A"};

    //n = size of the array
    int n = sizeof(arr)/sizeof(arr[0]);
    
    //print original list
    print_list(arr,n);
    
    //reverse list
    reverse_list(arr,0,n-1);
    
    //print reverse list
    print_list(arr,n);
   
    return 0;
}
