#include <iostream>
#include <limits>
#include <queue>

// Todo: rewrite with vector
class Solution {
  public:
    Solution() {
      parent = new Node*[1001];

      for (int i = 0; i < 1001; i++) {
        parent[i] = new Node[1001];
      }
    }

    ~Solution() {
      for (int i = 0; i < 1001; i++) {
        delete [] parent[i];
      }
      delete [] parent;
    }
    void Solve(char** map, int n, int m, int start_row, int start_col){

      int min_distance = std::numeric_limits<int>::max(); 
      int end_row = 0, end_col = 0;
      bool success = false;

      std::queue<Node> queue;
      Node start = {start_row, start_col, 0};
      queue.push(start);
      visited[start_row][start_col] = true;

      while (!queue.empty()) {
        Node node = queue.front();
        queue.pop();
        int row = node.row;
        int col = node.col;
        int distance = node.distance;


        if (map[row][col] == 'B') {
          end_row = row;
          end_col = col;
          min_distance = distance; 
          success = true;
          break;
        }

        if (row - 1 >= 1 && (map[row - 1][col] == '.' || map[row - 1][col] == 'B') &&
            !visited[row - 1][col]) {
          Node new_node = {row - 1, col, distance + 1};
          parent[row - 1][col] = node;
          queue.push(new_node);
          visited[row - 1][col] = true;
        }
        
        if (row + 1 <= n && (map[row + 1][col] == '.' || map[row + 1][col] == 'B') &&
            !visited[row + 1][col]) {
          Node new_node = {row + 1, col, distance + 1};
          parent[row + 1][col] = node;
          queue.push(new_node);
          visited[row + 1][col] = true;
        }
        
        if (col - 1 >= 1 && (map[row][col - 1] == '.' || map[row][col - 1] == 'B') &&
            !visited[row][col - 1]) {
          Node new_node = {row, col - 1, distance + 1};
          parent[row][col - 1] = node;
          queue.push(new_node);
          visited[row][col - 1] = true;
        }

        if (col + 1 <= m && (map[row][col + 1] == '.' || map[row][col + 1] == 'B') &&
            !visited[row][col + 1]) {
          Node new_node = {row, col + 1, distance + 1};
          parent[row][col + 1] = node;
          queue.push(new_node);
          visited[row][col + 1] = true;
        }
      }

      if (!success) {
        std::cout << "NO";
        return;
      }

      std::vector<char> operations;
      int i = end_row, j = end_col;

      while (!(i == start_row && j == start_col)) {
        Node parent_node = parent[i][j];

        if (parent_node.row == i - 1) {
          operations.push_back('D');
        }
        else if (parent_node.row == i + 1) {
          operations.push_back('U');
        }
        else if (parent_node.col == j - 1) {
          operations.push_back('R');
        }
        else if (parent_node.col == j + 1) {
          operations.push_back('L');
        }

        i = parent_node.row;
        j = parent_node.col;
      }

      std::cout << "YES" << std::endl;
      std::cout << min_distance << std::endl;
      for (auto it = operations.rbegin(); it != operations.rend(); it++) {
        std::cout << *it;
      }
    }
  private:
    struct Node {
      int row;
      int col;
      int distance;
    };

    Node** parent;
    bool visited[1001][1001] = {{false}};
};

int main() {

  int n, m;
  std::cin >> n >> m;

  int start_row = 0, start_col = 0;

  char **map = new char*[1001];

  for (int i = 0; i < 1001; i++) {
    map[i] = new char[1001];
  }

  char c;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      std::cin >> c;
      map[i][j] = c;

      if (c == 'A') {
        start_row = i;
        start_col = j;
      }
    }
  }

  Solution s;

  s.Solve(map, n, m, start_row, start_col);

  for (int i = 0; i < 1001; i++) {
    delete map[i];
  }
  delete [] map;
  return 0;
}
