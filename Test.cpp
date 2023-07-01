#include "doctest.h"
#include "string"

TEST_CASE("hello") {
    std::string text = "Dont worry be happy";
    CHECK_THROWS(anagram::find(text, "DOnt"));
    CHECK_EQ(anagram::find(text, "worry"), "worry");

}
