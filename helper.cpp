#include "helper.h"

vector<int> helper::vectorGenerator(int len) {
  vector<int> vec;
  for (int i = 0; i < len; ++i) {
    vec.push_back(i + 1);
  }
  return vec;
}

void helper::printVector(vector<int>& vec) {
  for (int i = 0; i < vec.size(); ++i) {
    cout << vec[i] << " ";
  }
  cout << endl;
}
