#include <iostream>
#include <vector>

void insertionSort(std::vector<int>& v){
    for (int j = 1; j < v.size(); j++){
        int key = v[j];
        int i = j-1;
        while(key < v[i] && i >= 0){
            v[i+1] = v[i];
            i--;
        }
        v[i+1] = key;
    }
}

int main(){
    std::vector<int> v {8,2,4,9,3,6};
    insertionSort(v);
    for(auto elem: v){
        std::cout<<elem<<" ";
    }
    return 0;
}