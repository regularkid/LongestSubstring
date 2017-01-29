#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include <vector>
#include <map>

using namespace std;

class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        set<char> chars;
        int maxLength = 0;
        int curLength = 0;

        // O(n) approach
        int strLength = s.size();
        for (int i = 0; i < strLength; i++)
        {
            char c = s[i];
            if (chars.find(c) != chars.end())
            {
                chars.clear();
                maxLength = max(maxLength, curLength);
                curLength = 0;
            }

            curLength++;            
            chars.insert(c);
        }

        return max(maxLength, curLength);
    }
};

TEST_CASE("LongestSubstring", "[tests]")
{
    Solution solution;

    REQUIRE(solution.lengthOfLongestSubstring("abcabcbb") == 3);
    REQUIRE(solution.lengthOfLongestSubstring("bbbbb") == 1);
    REQUIRE(solution.lengthOfLongestSubstring("pwwkew") == 3);
    REQUIRE(solution.lengthOfLongestSubstring("") == 0);
    REQUIRE(solution.lengthOfLongestSubstring("a") == 1);
    REQUIRE(solution.lengthOfLongestSubstring("ab") == 2);
    REQUIRE(solution.lengthOfLongestSubstring("abab") == 2);
}