#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

#include <HellSolver/Test/Test.hpp>

TEST_CASE("Simple Test")
{
    CHECK(Add(2, 3) == 5);
}
