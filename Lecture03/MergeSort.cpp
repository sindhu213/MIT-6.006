#include <iostream>
#include <vector>

void merge(std::vector<int>& v, int low, int mid, int high){
    int n1 = mid - low + 1;
    int n2 = high - mid;
    std::vector<int> L(n1),R(n2);
    for (int i = 0; i < n1; i++){
        L[i] = v[low + i];
    }
    for (int i = 0; i < n2; i++){
        R[i] = v[mid + i + 1];
    }
    int i = 0;
    int j = 0;
    int idx = low;
    while(i < n1 && j < n2){
        if(L[i] < R[j]){
            v[idx] = L[i];
            i++;
        }else{
            v[idx] = R[j];
            j++;
        }
        idx++;
    }
    while(i < n1){
        v[idx] = L[i];
        i++;
        idx++;
    }
    while(j < n2){
        v[idx] = R[j];
        j++;
        idx++;
    }
}

void mergeSort(std::vector<int>& v,int low, int high){
    int mid = (high + low)/2;
    if(high > low){
        mergeSort(v,low,mid);
        mergeSort(v,mid+1,high);
        merge(v,low,mid,high);
    }
}

int main(){
    std::vector<int> v{8,2,4,9,3,6};
    mergeSort(v,0,v.size()-1);
    for(auto elem: v){
        std::cout<<elem<<" ";
    }
    return 0;
}