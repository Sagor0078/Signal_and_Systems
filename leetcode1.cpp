//https://leetcode.com/problems/max-sum-of-rectangle-no-larger-than-k/

// another solution exits kore kadanes algorithm with binarysearch (**) time paini pore korte hobe
class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        int r = matrix.size(), c = matrix[0].size();
        
        int pref[r+1][c+1];
        memset(pref,0,sizeof(pref));
        
        for(int i=1; i<=r; ++i) pref[i][1] = pref[i-1][1] + matrix[i-1][0];
        for(int i=1; i<=c; ++i) pref[1][i] = pref[1][i-1] + matrix[0][i-1];
        
        for(int i=2; i<=r; ++i){
            for(int j=2; j<=c; ++j){
                pref[i][j] = pref[i-1][j] + pref[i][j-1] - pref[i-1][j-1] + matrix[i-1][j-1];
            }
        }
       int ans = INT_MIN;
       for (int x1 = 1; x1 <= r; ++x1) {
			 for (int y1 = 1; y1 <= c; ++y1) {
				for (int x2 = x1; x2 <= r; ++x2) { /// find submatrix which sum <=k
					for (int y2 = y1; y2 <= c; ++y2) {
						int sum = pref[x2][y2] - pref[x1-1][y2] - pref[x2][y1-1] + pref[x1-1][y1-1];
						if (sum <= k) {
							ans = max(ans, sum);
						}
					}
				}

			}
		}

     return ans;
    }
};
