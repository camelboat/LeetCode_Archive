#include <iostream>
#include <regex>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

// compare two subarrays in array N started at index a and b with
// length K; if the one started with a is larger than the one
// started with b, return true; otherwise return false
bool is_vector_larger(const vector<int> &N, int a, int b, int K)
{
    // compare each digit of two subarrays
    for (int i = 0; i < K; ++i)
    {
        if (N[a+i] > N[b+i]) return true;
        if (N[a+i] < N[b+i]) return false;
    }
    return false;
}

vector<int> solution(vector<int> N, int K)
{
    // Your solution goes here.
    vector<int> answer = vector<int>(K, 0);

    // use unordered_map to store the index
    // of max digit, faster then using a vector
    // to store the index since it doesn't require
    // the erase operation each time the max value
    // is updated
    unordered_map<int, vector<int>> bas;

    // use max_first to store the max digit value
    int max_first = 0;

    // traverse N to find the max digit value
    // store the index of max digit into the map
    for (int i = 0; i < N.size()-K+1; ++i)
    {
        // if N[i] is larger than current max digit
        // value, update the value and add new entry
        // to the map
        if (N[i] > max_first)
        {
            max_first = N[i];
            bas[max_first] = vector<int>(1,i);
        }
            // if N[i] is equal to the max digit value, add
            // the index to the map
        else if (N[i] == max_first) bas[max_first].emplace_back(i);
    }

    // for each vector of length K with the max digit value,
    // find out the largest one
    int max_index = bas[max_first][0];

    // traverse all index of the max digit
    for (int i = 1; i < bas[max_first].size(); ++i)
    {
        // if the vector is larger than the current largest vector
        // update the max_index
        max_index = is_vector_larger(N, bas[max_first][i], max_index, K) ? bas[max_first][i] : max_index;
    }

    // return the subarray started from the max_index with length K
    return vector<int>(N.begin()+max_index, N.begin()+max_index+K);
}

vector<int> toIntVector(string str)
{
    std::vector<int> out;
    std::string i;
    std::istringstream tokenStream(str);
    while (std::getline(tokenStream, i, ','))
    {
        out.push_back(atoi(i.c_str()));
    }
    return out;
}

string fromIntVector(vector<int> arr)
{
    string out = "";
    for (int i=0; i<arr.size(); i++) {
        out += to_string(arr[i]);
        if (i != arr.size() - 1) {
            out += ",";
        }
    }
    return out;
}

int main()
{
    // Read from stdin, solve the problem, write answer to stdout.
    string arrS;
    int K;
    cin >> arrS >> K;
    vector<int> N = toIntVector(arrS);
    cout << fromIntVector(solution(N, K));
}
