#include <iostream>
#include <vector>

class Solution {
 public:
  std::vector<std::vector<long long int>> distance;
  void Solve(int n, std::vector<std::vector<int>> &adjacent_matrix) {
    distance.resize(n + 1);

    for (int i = 1; i <= n; i++) {
      distance[i].resize(n + 1);
    }

    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++) {
        if (i == j) {
          distance[i][j] = 0;
        }
        else if (adjacent_matrix[i][j] > 0) {
          distance[i][j] = adjacent_matrix[i][j];
        }
        else {
          distance[i][j] = -1;
        }
      }
    }

    // Floyd-Warshall
    
    for (int k = 1; k <= n; k++) {
      for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
          if (distance[i][k] == -1 || distance[k][j] == -1) {
            continue;
          }

          if (distance[i][j] == -1) {
            distance[i][j] = distance[i][k] + distance[k][j];
          } else {
            distance[i][j] = std::min(distance[i][j], distance[i][k] + distance[k][j]);
          }
        }
      }
    }
    return;
  }

};
int main() {
  int n, m, q;
  std::cin >> n >> m >> q;
  std::vector<std::vector<int>> adjacent_matrix;
  adjacent_matrix.resize(n + 1);


  for (int i = 1; i <= n; i++) {
    adjacent_matrix[i].resize(n + 1, -1);
  }

  int a, b, c;
  for (int i = 0; i < m; i++) {
    std::cin >> a >> b >> c;

    if (adjacent_matrix[a][b] == -1) {
      adjacent_matrix[a][b] = c;
      adjacent_matrix[b][a] = c;
    }
    else {
      adjacent_matrix[a][b] = std::min(adjacent_matrix[a][b], c);
      adjacent_matrix[b][a] = std::min(adjacent_matrix[b][a], c);
    }
  }

  Solution s = Solution();
  s.Solve(n, adjacent_matrix);

  for (int i = 0; i < q; i++) {
    std::cin >> a >> b;
    std::cout << s.distance[a][b] << std::endl;
  }
  return 0;
}
