#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
    static int cur_num(vector<int> &array, int K, int start)
    {
        return array[start]*1000+array[start+1]*100+array[start+2]*10+array[start+3];
    }
public:
    vector<int> largest_subarray_length_K(vector<int> &array, int K)
    {
        int max_index=0;
        vector<int> answer = vector<int>(K, 0);
        int max_tmp = cur_num(array, K, 0);
        for (int i = 0; i < array.size()-K+1; ++i)
        {
            int tmp = cur_num(array, K, i);
            max_index = tmp > max_tmp ? i : max_index;
            max_tmp = tmp > max_tmp ? tmp : max_tmp;
        }
        for (int i = 0; i < K; ++i) answer[i] = array[max_index+i];
        return answer;
    }
};


int main()
{
    Solution test;
    vector<int> array = {1,2,3,4,5};
    int K = 4;
    vector<int> result = test.largest_subarray_length_K(array, K);
    for (auto &x: result) cout << x << " ";
}