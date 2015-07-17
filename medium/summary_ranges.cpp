#include <vector>
#include <string>
#include <iostream>

using std::cout;
using std::vector;
using std::string;
using std::to_string;

class Solution {
public:
  vector<string> summaryRanges(vector<int>& nums) {
    vector<string> ans;
    int size = nums.size();

    if (size == 0) return ans;

    //  set sentinel
    nums.push_back(nums[size-1]);
    int pre = 0, post = 0;

    for (int i = 1; i <= size; ++i) {
      if (nums[i] - nums[i-1] != 1 || nums[i] == nums[i-1]) {
        post = i-1;

        //  insert range string
        if (pre == post) {
          ans.push_back(to_string(nums[pre]));
        } else {
          ans.push_back(to_string(nums[pre]) + "->" + to_string(nums[post]));
        }

        //  update the position of pre, post
        pre = post = i;
      }
    }

    return ans;
  }
};

int main() {
  Solution a;
  int exam[7] = {1, 2, 3, 5, 6, 7, 9};
  vector<int> example(exam, exam + 7);
  vector<string> ans;
  ans = a.summaryRanges(example);
  for (vector<string>::iterator it = ans.begin();
       it != ans.end(); ++it) {
    cout << *it << " ";
  }
  cout << std::endl;
}
