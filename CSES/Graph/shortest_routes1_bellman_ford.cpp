#include <iostream>
#include <vector>
#include <limits>

class Solution {
 public:
   struct Edge {
     int start;
     int end;
     int weight;
   };

   void Solve(int n, std::vector<Edge> edges) {
     std::vector<long long int> distance(n + 1, -1);

     distance[1] = 0;

     for (int i = 1; i <= n - 1; i++) {
       for (auto &edge: edges) {
         int start = edge.start;
         int end = edge.end;
         int weight = edge.weight;

         if (distance[start] == -1) {
           continue;
         } else if(distance[end] == -1) {
           distance[end] = distance[start] + weight;
         }
         else {
           distance[end] = std::min(distance[end], distance[start] + weight);
         }
       }
     }

     for (int i = 1; i <= n; i++) {
       std::cout << distance[i] << " ";
     }

     return;
   }

};

int main() {
  int n, m;
  std::cin >> n >> m;

  std::vector<Solution::Edge> edges;

  int a, b, c;

  for (int i = 0; i < m; i++) {
    std::cin >> a >> b >>  c;
    edges.push_back({a, b, c});
  }

  Solution().Solve(n, edges);
  return 0;
}
