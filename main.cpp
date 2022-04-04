#include <iostream>
#include <vector>
#include <string>
#include <tuple>
#include <unordered_map>
#include "solution.h"
#include "util.h"

using namespace std;
using namespace sol1852;

/*
Input: nums = [1,2,3,2,2,1,3], k = 3
Output: [3,2,2,2,3]
Explanation: The number of distinct elements
in each subarray goes as follows:
- nums[0:2] = [1,2,3] so ans[0] = 3
- nums[1:3] = [2,3,2] so ans[1] = 2
- nums[2:4] = [3,2,2] so ans[2] = 2
- nums[3:5] = [2,2,1] so ans[3] = 2
- nums[4:6] = [2,1,3] so ans[4] = 3
*/

tuple<vector<int>, int, vector<int>> testFixture1()
{
  return make_tuple(vector<int>{1, 2, 3, 2, 2, 1, 3},
                    3, vector<int>{3, 2, 2, 2, 3});
}

/*
Input: nums = [1,1,1,1,2,3,4], k = 4
Output: [1,2,3,4]
Explanation: The number of distinct elements in each subarray goes as follows:
- nums[0:3] = [1,1,1,1] so ans[0] = 1
- nums[1:4] = [1,1,1,2] so ans[1] = 2
- nums[2:5] = [1,1,2,3] so ans[2] = 3
- nums[3:6] = [1,2,3,4] so ans[3] = 4
*/

tuple<vector<int>, int, vector<int>> testFixture2()
{
  return make_tuple(vector<int>{1, 1, 1, 1, 2, 3, 4},
                    4, vector<int>{1, 2, 3, 4});
}

void test1()
{
  auto f = testFixture1();
  cout << "Test 1 - expect to see " << Util::toString(get<2>(f)) << endl;
  cout << "result: " << Util::toString(Solution::find(get<0>(f), get<1>(f))) << endl;
}

void test2()
{
  auto f = testFixture2();
  cout << "Test 1 - expect to see " << Util::toString(get<2>(f)) << endl;
  cout << "result: " << Util::toString(Solution::find(get<0>(f), get<1>(f))) << endl;
}

main()
{
  test1();
  test2();
  return 0;
}