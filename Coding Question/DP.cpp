/*
    
*/

// Recursion with Memoization
int go(int currCol, int index, int n, vector<vector<int>> &pts,
      vector<vector<int>> &dp) {
    if(index == n) return 0;
    if(dp[index][currCol] != -1) return dp[index][currCol];
    int res = 0;
    
    for(int i = 0; i < 3; i++) {
        if(i != currCol) {
            int d = pts[index][i] + go(i, index + 1, n, pts, dp);
            res = max(res, d);
        }
    }
    return dp[index][currCol] = res;
}

int ninjaTraining(int n, vector<vector<int>> &points)
{
    vector<vector<int>> dp;
    dp.resize(n + 1, vector<int>(4, -1));
    
    int res = go(3, 0, n, points, dp);
    return res;
}

// Tabulation
int ninjaTraining(int n, vector<vector<int>> &points)
{
    vector<vector<int>> dp;
    dp.resize(n + 1, vector<int>(4, -1));
    dp[n - 1][0] = max(points[n -1][2], points[n - 1][1]);
    dp[n - 1][1] = max(points[n - 1][0], points[n - 1][2]);
    dp[n - 1][2] = max(points[n - 1][0], points[n - 1][1]);
    for(int i = n - 2; i >= 0; i--) {
        for(int last = 0; last < 3; last++) {
            dp[i][last] = 0;
            for(int col = 0; col < 3; col++) {
                if(last != col) {
                    int pt = points[i][col] + dp[i + 1][col];
                    dp[i][last] = max(dp[i][last], pt);
                }
            }
        }
    }
    int res = dp[0][0];
    for(int i = 0; i < 3; i++) res = max(res, dp[0][i]);
    return res;
}


/*
    Unique Paths 2 : With obstacles
*/

int uniquePathsWithObstacles(vector<vector<int>>& gd) {
    int rows = gd.size();
    int cols = gd[0].size();
    
    vector<vector<int>> dp(rows, vector<int>(cols, 0));
    
    for(int col = 0; col < cols; col++) {
        if(gd[0][col]) break;
        dp[0][col] = 1;
    }
    for(int row = 0; row < rows; row++) {
        if(gd[row][0]) break;
        dp[row][0] = 1;
    }

    for(int i = 1; i < rows; i++) {
        for(int j = 1; j < cols; j++) {
            if(gd[i][j]) continue;
            dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
        }
    }
    return dp[rows - 1][cols - 1];
}