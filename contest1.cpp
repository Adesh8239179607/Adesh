#include <iostream>
#include <map>
#include<cmath>

int main() {
    int t;
    std::cin >> t;

    while (t--) {
        int n;
        std::cin >> n;

        std::map<int, int> mpp;
        for (int i = 0; i < n; i++) {
            int c;
            std::cin >> c;

            mpp[c]++;
        }

        int count = 0;

        for (auto it : mpp) {
            if (it.second >= 3) {
                int r = 3;
                int n = it.second;
                count +=  std::tgamma(n + 1) / (std::tgamma(r + 1) * std::tgamma(n - r + 1));
            }
            if (it.second == 2) {
                auto nextIt = std::next(mpp.begin(), std::distance(mpp.begin(), mpp.find(it.first)) + 1);
                count += std::distance(mpp.begin(), nextIt);
            }
        }

        std::cout << count << std::endl;
    }

    return 0;
}