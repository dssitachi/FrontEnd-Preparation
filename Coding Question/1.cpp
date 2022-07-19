
#include <iostream>
#include <vector>

using namespace std;

int main() {

vector <int> nums(7);
for(int i = 0; i < 7; i++) cin >> nums[i];
int n = nums.size();
        int index = 0;
        for(int i = n - 1; i > 0; i--) {
            
            for(int j = i - 1; j >= 0; j--) {
                if(nums[i] > nums[j]) {
                    cout << "i = " << i << " j = " << j << endl;
                    swap(nums[i], nums[j]);
                    index = j;
                    break;
                }
            }
            if(index) break;
        }
        cout << endl;
        cout << index << endl;
        vector<int>:: iterator it = nums.begin();
        it += index;
        sort(it, nums.end());

    return 0;
}
