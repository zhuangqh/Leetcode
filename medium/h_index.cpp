class Solution {
public:
  int hIndex(vector<int>& citations) {
    sort(citations.begin(), citations.end(), [](const int& a, const int& b) {
        return a > b;
      });

    int h = 0;
    for (int i = 0; i < citations.size(); ++i) {
      if (i + 1<= citations[i])
        h = i + 1;
    }

    return h;
  }
};
