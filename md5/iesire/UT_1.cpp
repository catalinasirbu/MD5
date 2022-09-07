#include "../includes/md5.h"
#include "../includes/md5.CPP"

#include "string"

#include "gtest/gtest.h"

using namespace std;
namespace {

TEST(md5, test_md5_output_function) {
  // This test is named "Negative", and belongs to the "FactorialTest"
  // test case.
  std::string iesire = "95acbab2949334ac0869b966628acc0c";
  std::string intrare = md5("portocale");
  bool result = iesire == intrare;
  EXPECT_TRUE(result);
}

}  // namespace

// Step 3. Call RUN_ALL_TESTS() in main().
//
// We do this by linking in src/gtest_main.cc file, which consists of
// a main() function which calls RUN_ALL_TESTS() for us.
//
// This runs all the tests you've defined, prints the result, and
// returns 0 if successful, or 1 otherwise.
//
// Did you notice that we didn't register the tests?  The
// RUN_ALL_TESTS() macro magically knows about all the tests we
// defined.  Isn't this convenient?