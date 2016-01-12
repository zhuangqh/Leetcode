// create on 2016-1-12

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
  int coinChange(vector<int>& coins, int amount) {
    const int INF = 10000000;
    vector<int> dp(amount + 1, INF);
    sort(coins.begin(), coins.end());

    dp[0] = 0;
    for (int i = 0; i <= amount; ++i) {
      //cout << "begin " << dp[i] << endl;

      for (int j = 0; j < coins.size() && coins[j] + i <= amount; ++j) {
        if (dp[i] + 1 < dp[coins[j] + i])
          dp[coins[j] + i] = dp[i] + 1;
      }

      //cout << "end " << dp[i] << endl << endl;
    }

    return dp[amount] == INF ? -1 : dp[amount];
  }
};
