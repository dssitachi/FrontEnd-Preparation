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


/*
    Longest subarray with zero sum
*/

int LongestSubsetWithZeroSum(vector < int > arr) {
    int n = arr.size();
    unordered_map<int, int> mp;
    mp[0] = -1;
    int sum = 0;
    int res = 0;
    for(int i = 0; i < n; i++) {
        sum += arr[i];
        if(mp.find(sum) == mp.end()) {
            mp[sum] = i;
            continue;
        }
        res = max(res, i - mp[sum]);
    }
    return res;
}

/*
    3sum problem
    T.C = O(n^2)
*/

vector<vector<int>> threeSum(vector<int>& nums) {
vector <vector <int>> res;
int n = nums.size();
sort(nums.begin(), nums.end());
int i = 0;
while(i < n - 2) {
    int sum = -1 * nums[i];
    int j = i + 1;
    int k = n - 1;
    
    while(j < k) {
        if(nums[k] + nums[j] < sum) j++;
        else if(nums[j] + nums[k] > sum) k--;
        else {
            res.push_back({nums[i], nums[j], nums[k]});
            j++; k--;
            while(j < k && (nums[j] == nums[j - 1])) j++;
            while(j < k && nums[k] == nums[k + 1]) k--;
        }
    }
    i++;
    while(i < n - 2 && nums[i - 1] == nums[i]) i++;
}
return res;
}