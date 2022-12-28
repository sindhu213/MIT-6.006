#include <iostream>
#include <vector>
#include <cmath>

void swap(int& a, int& b){
    int temp = a;
    a = b;
    b = temp;
}

void max_heapify(std::vector<int>& v, int index, int heapsize){
    int largest = index,
        left = 2*index + 1,
        right = 2*index + 2;
    if(v[left] > v[index] && left <= heapsize){
        largest = left;
    }
    if(v[right] > v[largest] && right <= heapsize){
        largest = right; 
    }
    if(index != largest){
        swap(v[index],v[largest]);
        max_heapify(v,largest,heapsize);
    }
}

void build_max_heap(std::vector<int>& v){
    int size = v.size()/2;
    for (int i = size-1; i >= 0; i--){
        max_heapify(v,i,v.size()-1);
    }
}

void heapSort(std::vector<int>& v){
    build_max_heap(v);
    int heapsize = v.size() - 1;
    while(heapsize >= 0){
        swap(v[0],v[heapsize]);
        heapsize--;
        max_heapify(v,0,heapsize);
    }
}

int main(){
    std::vector<int> v = {16,4,10,14,7,9,3,2,8,1};
    heapSort(v);
    for(auto elem:v){std::cout<<elem<<" ";};
    return 0;
}