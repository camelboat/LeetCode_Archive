#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> answer;
        if (words.size() == 0 || s.size() == 0 || s.size() < (words[0].size() * words.size())) return answer;
        int word_size = words[0].size();
        typedef unordered_map<string, int> hashmap;
        hashmap wor;
        for (const auto& word: words) ++wor[word];


        // should use more optimization here
        // split it into word_size() groups, start from i = 0 / 1 /2
        // then for each groups, only need to delete the first element
        // no need to construct a new hashmap
        for (int i = 0; i <= (s.size() - word_size * words.size());++i)
        {
            hashmap tar;
            bool result = true;
            for (int j = 0; j < words.size(); ++j)
            {
                string word_tmp = s.substr(i+j*word_size, word_size);
                tar[word_tmp]++;
                int val_tmp = tar[word_tmp];
                if (tar[word_tmp] > wor[word_tmp]) result = false;
            }
            // cout << i << '\n';
            // for (auto& x: tar) std::cout << " " << x.first << ":" << x.second << '\n';
            if (result) answer.emplace_back(i);
        }
        return answer;
    }
};

//// tricky answer
//class Solution {
//public:
//    vector<int> findSubstring(string s, vector<string>& words) {
//        vector<int> ans;
//        if(s.empty()||words.empty()||s.substr(0,10)=="ababababab")
//            return ans;
//        int n=words.size(), l=words[0].size(),target=0;
//        for(int i=0;i<n;i++)
//            target+=sum(words[i]);
//        int tag[n],valid=1,ls=s.size(),L=n*l,sum_cur;
//        string cur;
//        memset(tag,0,n*sizeof(int));
//        for(int i=0;i+L-1<ls;i++){
//            valid=1;
//            if(i==0)
//                sum_cur=sum(s.substr(0,L));
//            else{
//                sum_cur-=s[i-1];
//                sum_cur+=s[i+L-1];
//            }
//            if(sum_cur!=target)  continue;
//            for(int j=0;j<n;j++){
//                if(valid==0){
//                    memset(tag,0,n*sizeof(int));
//                    break;
//                }
//                cur=s.substr(i+j*l,l);
//                for(int k=0;k<n;k++){
//                    if(cur==words[k]&&tag[k]==0){
//                        tag[k]=1;
//                        break;}
//                    if(k==n-1)  valid=0;
//                }
//            }
//            if(valid)   ans.push_back(i);
//            memset(tag,0,n*sizeof(int));
//        }
//        return ans;
//    }
//    int sum(string s){
//        int ans=0;
//        for(int i=0;i<s.size();i++)
//            ans+=s[i];
//        return ans;
//    }
//};