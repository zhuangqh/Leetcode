#include <iostream>
#include <vector>
#include <cstring>
#include <queue>

struct node {
  int x, y;
  node(int xx, int yy) : x(xx), y(yy) {}
  node() {}
};
class Solution {
public:
  int numIslands(std::vector<std::vector<char> >& grid) {
    const int dir[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    bool visited[500][500];
    memset(visited, false, sizeof(visited));

    unsigned ans = 0, bx = grid.size(), by;
    if (bx == 0) return 0;
    by = grid[0].size();

    for (unsigned i = 0; i != bx; ++i) {
      for (unsigned j = 0; j != by; ++j) {

        if (!visited[i][j] && grid[i][j] != '0') {
          ++ans;
          std::queue<node> buf;
          buf.push(node(i, j));
          visited[i][j] = true;

          node tmp;

          while (!buf.empty()) {
            tmp = buf.front();
            buf.pop();
            for (int k = 0; k < 4; ++k) {
              int x = tmp.x + dir[k][0],
                y = tmp.y + dir[k][1];

              if (isok(x, y, bx, by) && !visited[x][y] && grid[x][y] == '1') {
                visited[x][y] = true;
                buf.push(node(x, y));
              }
            }
          }

        }

      }
    }

    return ans;
  }

  bool isok(int x, int y, int bx, int by) {
    return x >= 0 && x < bx && y >= 0 && y < by;
  }
};

int main() {
  std::vector<char> haha(1, '1');
  std::vector<std::vector<char> > test;
  test.push_back(haha);
  Solution a;
  std::cout << a.numIslands(test) << std::endl;
  return 0;
}
