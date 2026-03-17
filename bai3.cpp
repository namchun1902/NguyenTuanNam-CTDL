//in mang con co tong bang 0
#include <iostream>
#include <unordered_map>

using namespace std;

void printAllSubarrays(int nums[], int n){
    unordered_multimap<int, int> map;
    
    map.insert({0, -1});
    
    int sum = 0;
    for(int i=0; i<n; i++){
        sum += nums[i];
        
        if(map.find(sum) != map.end()){
            auto k = map.find(sum);
            while(k != map.end() && k->first == sum){
                for(int j = k->second + 1; j <= i; j++) {
                    cout << nums[j] << " ";
                }
                cout << "\n";
                k++;
            }
        }
        map.insert({sum, i});
    }
}
 int main() {
    int nums[] = { 3, 4, -7, 3, 1, 3, 1, -4, -2, -2 };
    int n = sizeof(nums)/sizeof(nums[0]);
 
    printAllSubarrays(nums, n);
 
    return 0;
 }