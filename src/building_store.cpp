#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Point {
    int x, y;

    Point(int x, int y) : x(x), y(y) {
    }

    [[nodiscard]] int distance(const Point p) const {
        return abs(x - p.x) + abs(y - p.y);
    }
};

int solution(const int K, const vector<vector<int> > &A) {
    vector<Point> homes{};

    for (unsigned y = 0; y < A.size(); ++y) {
        for (unsigned x = 0; x < A[y].size(); ++x) {
            if (A[y][x] == 1) {
                homes.emplace_back(x, y);
            }
        }
    }
    auto isHome = [&](Point &p) { return A[p.y][p.x] == 1; };
    auto isValid = [&](Point &p) {
        return ranges::all_of(homes, [&](auto &home) {
            return home.distance(p) <= K;
        });
    };

    int max = 0;
    for (unsigned y = 0; y < A.size(); ++y) {
        for (unsigned x = 0; x < A[y].size(); ++x) {
            Point p{static_cast<int>(x), static_cast<int>(y)};
            if (!isHome(p) && isValid(p)) {
                max++;
            }
        }
    }

    return max;
}
