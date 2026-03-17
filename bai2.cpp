//xem co mang con co tong bang 0 hay khong
#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

bool subsumzero(const vector<int>& nums) {
    unordered_set<int> seen_sums;
    int sum = 0;
    for(int num : nums) {
        sum += num;
        if(sum == 0 || seen_sums.find(sum) != seen_sums.end()){
            return true;
        }
        
        seen_sums.insert(sum);
    }
    return false;
}

int main() {
    vector<int> arr1 = { 4, 2, -3, -1, 0, 4 };
    subsumzero(arr1) ?
        cout << "Subarray exists" :
        cout << "Subarray does not exist";
    return 0;
}
