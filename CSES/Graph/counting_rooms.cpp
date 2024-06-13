#include <iostream>


class Solution {
  private:
    char building[1001][1001] = {{0}};
    bool visited[1001][1001] = {{false}};
    int m = 0; 
    int n = 0;
  public: 
    void Solve() {

      int n, m;
      std::cin >> n >> m;

      this->n = n;
      this->m = m;

      char c = 0;
      for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
          std::cin >> c;
          building[i][j] = c;
        }
      }

      int count = 0;
      for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
          if (building[i][j] == '.' && !visited[i][j]) {
            DFS(i, j);
            count++;
          }
        }
      }

      std::cout << count;
      return;
    }

    void DFS(int i, int j) {
      visited[i][j] = true;

      if (i + 1 <= n && building[i + 1][j] == '.' && !visited[i + 1][j]) {
        DFS(i + 1, j);
      }

      if (i - 1 >= 1 && building[i - 1][j] == '.' && !visited[i - 1][j]) {
          DFS(i - 1, j);
        }
      
      if (j + 1 <= m && building[i][j + 1] == '.' && !visited[i][j + 1]) {
          DFS(i, j + 1);
        }
      if (j - 1 >= 1 && building[i][j - 1] == '.' && !visited[i][j - 1]) {
        DFS(i, j - 1);
      }

      return;
    }
};

int main() {
  Solution().Solve(); 
}
