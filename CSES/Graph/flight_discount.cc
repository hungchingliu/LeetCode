#include <iostream>
#include <queue>
#include <vector>
#include <limits>

class Solution {
 public:
  static void Solve(int n, std::vector<std::vector<std::pair<int, long long int>>> &adjacent_list, 
                    std::vector<std::vector<std::pair<int, long long int>>> &adjacent_list_reverse) {

    std::vector<long long int> min_price_from_start(n + 1, -1);
    std::vector<long long int> min_price_from_end(n + 1, -1);

    Dijksta(n, 1, adjacent_list, min_price_from_start);
    Dijksta(n, n, adjacent_list_reverse, min_price_from_end);

    long long int min_price = -1;
    for (int i = 1; i <= n; ++i) {
      for (auto &edge: adjacent_list[i]) {
        int edge_start = i;
        int edge_end = edge.first;
        long long int weight = edge.second;

        if (min_price_from_start[edge_start] == -1 ||
            min_price_from_end[edge_end] == -1) {
          continue;
        }

        long long int price = min_price_from_start[edge_start] + min_price_from_end[edge_end] + weight / 2;

        if (min_price == -1) {
          min_price = price;
        } else {
          min_price = std::min(min_price, price);
        }
      }
    }

    std::cout << min_price << std::endl;
  }
 private:
  struct ComparePair {
    bool operator() (std::pair<int, long long int> &below, std::pair<int, long long int> &above) {
      if (below.second > above.second) {
        return true;
      }
      return false;
    }
  };

  static void Dijksta(int n, int start, std::vector<std::vector<std::pair<int, long long int>>> const &adjacent_list,
                      std::vector<long long int> &distance) {
    std::vector<bool> visited(n + 1, false);
    std::priority_queue<
      std::pair<int, long long int>,
      std::vector<std::pair<int, long long int>>,
      Solution::ComparePair> priority_queue; 

    distance[start] = 0;
    priority_queue.push(std::make_pair(start, 0));
    

    while (!priority_queue.empty()) {
      std::pair<int, long long int> edge = priority_queue.top();
      priority_queue.pop();
      
      int node = edge.first;

      if (visited[node]) continue;
      visited[node] = true;

      // relax all edges connect to processed node
      for (auto &next: adjacent_list[node]) {
        int next_node = next.first;
        long long int weight = next.second;

        if (distance[next_node] == -1) {
          distance[next_node] = distance[node] + weight;
          priority_queue.push(std::make_pair(next_node, distance[next_node]));
        }
        else if (distance[node] + weight < distance[next_node]) {
          distance[next_node] = distance[node] + weight;
          priority_queue.push(std::make_pair(next_node, distance[next_node]));
        }
      }
    }
    return;
  }
};


int main () {
  int n, m;
  std::cin >> n >> m;

  std::vector<std::vector<std::pair<int, long long int>>> adjacent_list;
  std::vector<std::vector<std::pair<int, long long int>>> adjacent_list_reverse;
  adjacent_list.resize(n + 1);
  adjacent_list_reverse.resize(n + 1);

  int a, b;
  long long int c;
  for (int i = 0; i < m; ++i) {
    std::cin >> a >> b >> c;
    adjacent_list[a].push_back(std::make_pair(b, c));
    adjacent_list_reverse[b].push_back(std::make_pair(a, c));
  }

  Solution().Solve(n, adjacent_list, adjacent_list_reverse);

  return 0;
}
