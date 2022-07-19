/* Two sum problem 
    TC : O(n)
*/

vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int, int> mp;
    
    int n = nums.size();
    vector <int> res;
    for(int i = 0; i < n; i++) {
        if(mp.find(target - nums[i]) != mp.end()) {
            res.push_back(i);
            res.push_back(mp[target - nums[i]]);
            return res;
        }
        mp[nums[i]] = i;
    }
    return res;
}