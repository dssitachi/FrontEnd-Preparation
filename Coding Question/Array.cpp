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

/* Longest Consecutive Sequence
    TC : O(n)
  
    Input: nums = [100,4,200,1,3,2]
    Output: 4
    Explanation: The longest consecutive elements sequence is [1, 2, 3, 4]. Therefore its length is 4.
*/

unordered_set<int> s;

for(auto x: nums) s.insert(x);
int res = 0;
for(int i = 0; i < nums.size(); i++) {
    if(s.find(nums[i] - 1) != s.end()) continue;
    int cnt = 1;
    int c = nums[i] + 1;
    while(s.find(c) != s.end()) {
        cnt++;
        c++;
    }
    res = max(res, cnt);
}
return res;
