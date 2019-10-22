

//// 94.36%, 100.00%
//// size@str
class Codec {
public:

    // Encodes a list of strings to a single string.
    string encode(vector<string>& strs) {
        string ans;
        // char tag = '%';
        for (auto &x: strs)
        {
            ans+=to_string(x.size());
            ans+="@";
            ans+=x;
        }
        return ans;
    }

    // Decodes a single string to a list of strings.
    vector<string> decode(string s) {
        vector<string> ans;
        int n = s.size();
        int num = 0;
        string num_tmp = "";
        for (int i = 0; i < s.size();)
        {
            while (s[i] != '@')
            {
                num_tmp+=s[i];
                ++i;
            }
            ++i;
            num = stoi(num_tmp);
            num_tmp = "";
            ans.emplace_back(s.substr(i, num));
            i+=num;
        }
        return ans;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.decode(codec.encode(strs));


//// 74.58%, 100%
//// str\nstr\n
class Codec {
public:

    // Encodes a list of strings to a single string.
    string encode(vector<string>& strs) {
        string ans;
        // char tag = '%';
        for (auto &x: strs)
        {
            for (int i = 0; i < x.size(); ++i)
            {
                if (x[i] == '0')
                {
                    ans+="00";
                }
                else ans+=x[i];
            }
            ans+="01";
        }
        return ans;
    }

    // Decodes a single string to a list of strings.
    vector<string> decode(string s) {
        vector<string> ans;
        string tmp = "";
        int n = s.size();
        for (int i = 0; i < s.size(); ++i)
        {
            if (i < s.size()-1 && s[i] == '0' && s[i+1] == '0')
            {
                tmp+='0';
                ++i;
            }
            else if (i < s.size()-1 && s[i] == '0' && s[i+1] == '1')
            {
                ans.emplace_back(tmp);
                tmp = "";
                ++i;
            }
            else tmp+=s[i];
        }
        return ans;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.decode(codec.encode(strs)); 
