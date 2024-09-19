#include <iostream>
#include <map>
#include <queue>
#include <sstream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>
#include <unordered_map>

using namespace std;
int cost(int from, int to) {
    if (from == to) {
        return 1;
    }
    if (from == 0) {
        return 2;
    }
    if ((from + to) % 2 == 0) {
        return 4;
    }
    return 3;
}
int dp[10001][5][5];
int main() {
    
    int len = 0;
    vector<int> seq;
    while (true) {
        int n;
        cin >> n;
        if (n == 0) {
            break;
        }
        seq.push_back(n);
        len++;
    }
    fill(&dp[0][0][0], &dp[100000][4][5], INT_MAX);
    dp[0][0][0] = 0;
    
    for (int i = 0; i < len-1; i++) {
        int next = seq[i];
        for (int x = 0; x < 5; x++) {
            for (int y = 0; y < 5; y++) {
                dp[i + 1][x][next] = min(dp[i][x][y] + cost(y, next), dp[i + 1][x][next]);
                dp[i+1][next][y] = min(dp[i][x][])
            }
        }
    }
}
