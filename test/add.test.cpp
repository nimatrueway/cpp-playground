#include <catch2/catch_all.hpp>
#include "../include/add.h"

TEST_CASE("SingleTest") {
    const auto result = add(1, 2);
    const auto expected = 1 + 2;
    CHECK(expected == result);
}