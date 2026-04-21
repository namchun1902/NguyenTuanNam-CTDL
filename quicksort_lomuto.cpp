#include <iostream>
using namespace std;

int partition(int arr[], int low, int high){
    int pivot = arr[high];
    int j = low - 1;
    int temp;
    
    for(int i=low; i <= high-1; i++){
        if(arr[i]<=pivot){
            j++;
            if(i==j) continue;
            else if(i>j){
                temp = arr[i];
                arr[i]=arr[j];
                arr[j]=temp;
            }
        }
    }
    temp=arr[high];
    arr[high]=arr[j+1];
    arr[j+1]=temp;
    
    return j+1;
}

void QuickSort(int arr[], int low, int high){
    if(low<high){
        int pi = partition(arr, low, high);
        QuickSort(arr,low, pi-1);
        QuickSort(arr,pi+1, high);
    }
}

int main(){
    int arr[]= {1, 8, 3, 4, 9, 0, 2, 5, 7, 6};
    int low=0;
    int high=sizeof(arr)/sizeof(int) - 1;
    QuickSort(arr, low, high);
    for(int i=0; i< sizeof(arr)/sizeof(int); i++){
        cout << arr[i] << " ";
    }
}