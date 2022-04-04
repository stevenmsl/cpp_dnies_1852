#include "solution.h"

#include <unordered_map>
#include <functional>

using namespace sol1852;
using namespace std;

/*takeaways
  - examine within the window of size k how many distinct numbers you
    can have. Use map to help keep track of distinct numbers.
  - the very last position of the windows can be k-1,k,...,n-1
    so there are (n-1)-(k-1)+1 = n-k+1 windows you can slide
    through
  - when you are sliding out of a window, look at the number of at
    the very first index within that window as it won't be included
    in the new window you are sliding into. Reduce the occurrences
    of that number by one, and if the count reaches zero that means
    possibly that number will not be in the new window so just
    remove it from the map. If the newly added number is the same
    we just add it back in to the map later
*/

vector<int> Solution::find(vector<int> &nums, int k)
{
  const int n = nums.size();
  auto result = vector<int>(n - k + 1);

  /* record the occurrences of each distinct
     number within the window starting at index
    0 with size k
     - why not using a set? we need the occurrences
       to decided if we need to keep a certain
       number in the map once we start moving
       the window to the right one number at a time
  */
  auto map = unordered_map<int, int>();
  for (auto i = 0; i < k; i++)
    map[nums[i]]++;

  result[0] = map.size();

  for (int i = k; i < n; i++)
  {
    /* remove the number at the first index
       from the current window we are sliding
       out of
    */
    if (--map[nums[i - k]] == 0)
      /* if count reaches zero remove it from the map */
      map.erase(nums[i - k]);

    map[nums[i]]++;
    /* record how many distinct numbers we have */
    result[i - k + 1] = map.size();
  }

  return result;
}