/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Constructor initializes an empty nested list.
 *     NestedInteger();
 *
 *     // Constructor initializes a single integer.
 *     NestedInteger(int value);
 *
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Set this NestedInteger to hold a single integer.
 *     void setInteger(int value);
 *
 *     // Set this NestedInteger to hold a nested list and adds a nested integer to it.
 *     void add(const NestedInteger &ni);
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */

//// 72.84%, 12.50%
class Solution {
public:
    int depthSumInverse(vector<NestedInteger>& nestedList) {
        int max_depth = helper(nestedList);
        return helper_2(nestedList, max_depth);
    }

    // return the max depth of the input NestedList, update ans
    int helper(vector<NestedInteger>& nestedList)
    {
        int level = 1;
        for (int i = 0; i < nestedList.size(); ++i)
        {
            NestedInteger cur = nestedList[i];
            if (!cur.isInteger())
            {
                vector<NestedInteger> next = cur.getList();
                int tmp = helper(next)+1;
                level = level > tmp ? level : tmp;
            }
        }
        return level;
    }

    int helper_2(vector<NestedInteger>& nestedList, int max_depth)
    {
        int ans = 0;
        for (int i = 0; i < nestedList.size(); ++i)
        {
            NestedInteger cur = nestedList[i];
            if (!cur.isInteger())
            {
                vector<NestedInteger> next = cur.getList();
                ans+=helper_2(next, max_depth-1);
            }
            else ans+=cur.getInteger() * max_depth;
        }
        return ans;
    }

};