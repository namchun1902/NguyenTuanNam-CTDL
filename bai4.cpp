#include <iostream>
using namespace std;

// void sort(int arr[], int n){
//     int k=0;
//     for(int i=0; i<n; i++){
//         if(arr[i]==0){
//             arr[k++]=0;
//         }
//     }
//     for(int i=k; i<n; i++){
//         arr[i]=1;
//     }
// }
// int main(){
//     int arr[]= {0,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,1,0};
//     int n= sizeof(arr)/sizeof(int);
//     sort(arr, n);
//     for(int i=0; i<n; i++){
//         cout << arr[i] << " ";
//     }
//     return 0;
// }

int sort(int arr[], int low, int high){
    int temp;
    int pivot = arr[high];
    int j = low - 1;
    for(int i=low; i <= high - 1; i++){
        if(arr[i]<=pivot){
            j++;
            if(i==j) continue;
            else if(i>j){
                temp=arr[j];
                arr[j]=arr[i];
                arr[i]=temp;
            }
        }
    }
    arr[high]=arr[j+1];
    arr[j+1]=pivot;
    
    return j+1;
}
void QuickSort(int arr[], int low, int high){
    if(low<high){
    int pi = sort(arr, low, high);
    QuickSort(arr, low, pi-1);
    QuickSort(arr, pi+1, high);
    }
}

int main(){
    int arr[]= {0,0,1,1,0,0,1,0,1,0,1,0,1,0,0,1,0,1,0,1,0,0,0,1,0,0,1};
    int low = 0;
    int high = sizeof(arr)/sizeof(int) - 1;
    QuickSort(arr, low, high);
    for(int i=0; i<sizeof(arr)/sizeof(int);i++){
        cout << arr[i] << " ";
    }
}