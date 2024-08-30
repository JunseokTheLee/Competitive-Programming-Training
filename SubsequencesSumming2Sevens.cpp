#include <iostream>
#include <map>
#include <queue>
#include <sstream>
#include <string>
#include <vector>

using namespace std;


int main() {
    long long n;
    cin >> n;
    vector<long long> ID(n+1);
    long long total = 0;
    for (long long i = 1; i <= n; i++) {
        cin >> ID[i];
        total += ID[i];
        ID[i] = (ID[i] + ID[i - 1]) % 7;
    }
    if (total % 7 == 0LL) {
        cout << n;
        return 0;
    }
    vector<long long> left(7);
    vector<long long> right(7);
    for (long long i = 1; i <= n; i++) {
        right[ID[i]] = i;
    }
    for (long long i = n; i > 0; i--) {
        left[ID[i]] = i;
    }
    long long ans = 0;
    for (long long i = 0; i < 7; i++) {
        ans = max(ans, right[i] - left[i]);

    }
    cout << ans;

}
