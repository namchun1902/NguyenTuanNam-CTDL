//tim cap co tong bang sum
#include <iostream>
#include <algorithm>

using namespace std;

void findpair(int nums[], int n, int sum) {
    int high = n-1;
    int low = 0;
    int k = 0;
    sort(nums, nums+n);
    while(high > low) {
        if(nums[high] + nums[low] == sum){
            cout << "Pair found (" << nums[high] << ", " << nums[low] <<")" << endl;
            if(k>0) cout << "or\n";
            k++;
            low++;
        }
        else if(nums[high] + nums[low] > sum){
            high--;
        }
        else low++;
    }
    if(k==0) cout << "No pair found" << endl;
}
int main(){
    int n;
    int sum;
    cin >> sum;
    int nums[]= {8, 7, 2, 5, 3, 1};
    n = sizeof(nums)/sizeof(nums[0]);
    findpair(nums, n, sum);
}