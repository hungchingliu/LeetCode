#include <iostream>
#include <utility>
#include <queue>
#include <algorithm>
#include <limits>

class Solution {
  int n_;
  int m_;
  std::vector<std::vector<int>> monsters_distance_;

 public:
  void Solve(int n, int m, std::vector<std::vector<char>> &map,
             std::vector<std::pair<int, int>> &monsters, std::pair<int, int> start) {
    
    // initialization
    n_ = n;
    m_ = m;
    monsters_distance_.resize(n_ + 1);
    for (int i = 1; i <= n_; i++) {
      monsters_distance_[i].resize(m_ + 1, std::numeric_limits<int>::max());
    }

    // bfs start from monsters' location to constuct distance map
    BfsMonsters(map, monsters);

    // bfs from start to find exit, avoid monsters
    BfsStart(map, start);
    
    return;
  }
 private:
  void BfsMonsters(std::vector<std::vector<char>> &map, std::vector<std::pair<int, int>> &monsters) {

    std::vector<std::vector<int>> visited;
    visited.resize(n_ + 1);
    for (int i = 1; i <= n_; i++) {
      visited[i].resize(m_ + 1, false);
    }

    std::queue<std::pair<int, int>> queue;

    for (auto &monster: monsters) {
      queue.push(monster);
      visited[monster.first][monster.second] = true;
      monsters_distance_[monster.first][monster.second] = 0;
    }

    while (!queue.empty()) {
      std::pair<int, int> node = queue.front();
      queue.pop();
      int r = node.first;
      int c = node.second;
      int distance = monsters_distance_[r][c];

      // up
      if (r - 1 >= 1 && map[r - 1][c] == '.' && !visited[r - 1][c]) {
        visited[r - 1][c] = true;
        if (distance + 1 < monsters_distance_[r - 1][c]) {
          monsters_distance_[r - 1][c] = distance + 1;
          queue.push({r - 1, c});
        }

      }
      // down
      if (r + 1 <= n_ && map[r + 1][c] == '.' && !visited[r + 1][c]) {
        visited[r + 1][c] = true;
        if (distance + 1 < monsters_distance_[r + 1][c]) {
          monsters_distance_[r + 1][c] = distance + 1;
          queue.push({r + 1, c});
        }
      }
      // left
      if (c - 1 >= 1 && map[r][c - 1] == '.' && !visited[r][c - 1]) {
        visited[r][c - 1] = true;
        if (distance + 1 < monsters_distance_[r][c - 1]) {
          monsters_distance_[r][c - 1] = distance + 1;
          queue.push({r, c - 1});
        }
      }

      // right
      if (c + 1 <= m_ && map[r][c + 1] == '.' && !visited[r][c + 1]) {
        visited[r][c + 1] = true;
        if (distance + 1 < monsters_distance_[r][c + 1]) {
          monsters_distance_[r][c + 1] = distance + 1;
          queue.push({r, c + 1});
        }
      }
    }
    return;
  }

  void BfsStart(std::vector<std::vector<char>> &map, std::pair<int, int> start) {
    bool success = false;

    std::vector<std::vector<bool>> visited;
    std::vector<std::vector<int>> distance;
    std::vector<std::vector<std::pair<int, int>>> parent;

    visited.resize(n_ + 1);
    parent.resize(n_ + 1);
    distance.resize(n_ + 1);

    for (int i = 1; i <= n_; i++) {
      visited[i].resize(m_ + 1, false);
      distance[i].resize(m_ + 1, 0);
      parent[i].resize(m_ + 1, {0, 0});
    }

    std::queue<std::pair<int, int>> queue;

    queue.push(start);
    visited[start.first][start.second] = true;


    int exit_r, exit_c;
    while (!queue.empty()) {
      std::pair<int, int> node = queue.front();
      queue.pop();
      int r = node.first;
      int c = node.second;
      int dist = distance[r][c];

      if (r == 1 || r == n_ || c == 1 || c == m_) {
        success = true;
        exit_r = r;
        exit_c = c;
        break;
      }

      if (r - 1 >= 1 && map[r - 1][c] == '.' && !visited[r - 1][c]) {
        visited[r - 1][c] = true;
        if (dist + 1 < monsters_distance_[r - 1][c]) {
          distance[r - 1][c] = dist + 1;
          parent[r - 1][c] = std::make_pair(r, c);
          queue.push({r - 1, c});
        }
      }

      if (r + 1 <= n_ && map[r + 1][c] == '.' && !visited[r + 1][c]) {
        visited[r + 1][c] = true;
        if (dist + 1 < monsters_distance_[r + 1][c]) {
          distance[r + 1][c] = dist + 1;
          parent[r + 1][c] = std::make_pair(r, c);
          queue.push({r + 1, c});
        }
      }

      if (c - 1 >= 1 && map[r][c - 1] == '.' && !visited[r][c - 1]) {
        visited[r][c - 1] = true;
        if (dist + 1 < monsters_distance_[r][c - 1]) {
          distance[r][c - 1] = dist + 1;
          parent[r][c - 1] = std::make_pair(r, c);
          queue.push({r, c - 1});
        }
      }

      if (c + 1 <= m_ && map[r][c + 1] == '.' && !visited[r][c + 1]) {
        visited[r][c + 1] = true;
        if (dist + 1 < monsters_distance_[r][c + 1]) {
          distance[r][c + 1] = dist + 1;
          parent[r][c + 1] = std::make_pair(r, c);
          queue.push({r, c + 1});
        }
      }
    }

    if (!success) {
      std::cout << "NO";
    }
    else {
      std::vector<char> path;

      int r = exit_r;
      int c = exit_c;

      while (!(r == start.first && c == start.second)) {
        std::pair<int, int> parent_node = parent[r][c];
        int parent_r = parent_node.first;
        int parent_c = parent_node.second;

        if (parent_r - 1 == r) {
          path.push_back('U');
        }
        else if (parent_r + 1 == r) {
          path.push_back('D');
        }
        else if (parent_c - 1 == c) {
          path.push_back('L');
        }
        else if (parent_c + 1 == c) {
          path.push_back('R');
        }

        r = parent_r;
        c = parent_c;
      }

      std::reverse(path.begin(), path.end());

      std::cout << "YES" << std::endl;
      std::cout << path.size() << std::endl;
      for (auto &c: path) {
        std::cout << c;
      }
      return;
    }
  }
};

int main() {
  int n, m;
  std::cin >> n >> m;
  
  std::vector<std::vector<char>> map;
  std::vector<std::pair<int, int>> monsters;
  std::pair<int, int> start;

  map.resize(n + 1);

  char c;
  for (int i = 1; i <= n; i++) {
    map[i].resize(m + 1);
    for (int j = 1; j <= m; j++) {
      std::cin >> c;
      map[i][j] = c;

      if (c == 'M') {
        monsters.push_back(std::make_pair(i, j));
      }

      if (c == 'A') {
        start = std::make_pair(i, j);
      }
    }
  }

  Solution().Solve(n, m, map, monsters, start);


  return 0;
}
