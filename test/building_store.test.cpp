#include <vector>
#include <catch2/catch_all.hpp>
#include "../src/building_store.cpp"

using namespace std;

TEST_CASE("example #1") {
    const auto K = 2;
    const vector<vector<int>> A{{0, 0, 0, 0},
                                {0, 0, 1, 0},
                                {1, 0, 0, 1}};
    CHECK(solution(K, A) == 2);
}

TEST_CASE("example #2") {
    const auto K = 1;
    const vector<vector<int>> A{{0, 1},
                                {0, 0}};
    CHECK(solution(K, A) == 2);
}

TEST_CASE("example #3") {
    const auto K = 4;
    const vector<vector<int>> A{{0, 0, 0, 1},
                                {0, 1, 0, 0},
                                {0, 0, 1, 0},
                                {1, 0, 0, 0},
                                {0, 0, 0, 0}};
    CHECK(solution(K, A) == 8);
}