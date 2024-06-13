#include <iostream>
#include <chrono>
#include <ctime>
#include <vector>
#include <unordered_map>
// 8
// 1 2 1 3 2 7 4 2

struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = std::chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};
 
int main() {
  std::ios::sync_with_stdio(0);
  std::cin.tie(0);

  int n;
  std::cin >> n;
 
  std::vector<int> songs;
 
  songs.resize(n);
 
  for (int& song: songs) {
    std::cin >> song;
  }
 
  int longest_unique_sequence = 0;
  int count = 0;
  int left = 0;
  std::unordered_map<int, int, custom_hash> last_occurence;
 
  for (auto i = 0; i < songs.size(); i++) {
    if (last_occurence.find(songs[i]) != last_occurence.end() && left <= last_occurence[songs[i]] ) {
        count = i - last_occurence[songs[i]];
        left = last_occurence[songs[i]] + 1;
        last_occurence[songs[i]] = i;
    }
    else {
      last_occurence[songs[i]] = i;
      count++;
      longest_unique_sequence = std::max(longest_unique_sequence, count);
    }
  }
 
  std::cout << longest_unique_sequence;
 
  return 0;
}
