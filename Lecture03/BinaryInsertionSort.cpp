#include <iostream>
#include <vector>

int iterativeBinarySearch(std::vector<int>& v,int key,int high){
    int low = 0;
    while(high > low){
        int mid = (high + low)/2;
        if(v[mid] > key){
            high = mid;
        }else{
            low = mid+1;
        }
    }
    return low;  
}

void binaryInsertionSort(std::vector<int>& v){
    for (int j = 1; j < v.size(); j++){
        int key = v[j];
        int pos = iterativeBinarySearch(v,key,j);
        int i = j-1;
        while(i >= pos){
            v[i+1] = v[i];
            i--;
        }
        v[i+1] = key;
    }
}

int main(){
    std::vector<int> v {8,2,4,9,3,6};
    binaryInsertionSort(v);
    for(auto elem:v){
        std::cout<<elem<<" ";
    }
    return 0;
}