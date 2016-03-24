// Should work. Not tested.
class Codec4 {
public:
    string encode(vector<string>& strs) {
        string ans;
        for (int i = 0; i < strs.size(); ++ i) {
            ans += to_string(strs[i].length()) + "#" + strs[i];
        }
        return ans;
    }
    
    // Decodes a single string to a list of strings.
    vector<string> decode(string s) {
        vector<string> ans;
        int i = 0;
        while (true) {
            int pos = findPound(s, i);
            if (pos == -1) break;
            int len = stoi(s.substr(i, pos - i));
            ans.push_back(s.substr(pos + 1, len));
            i = pos + len + 1;
        }
        return ans;
    }
    
    int findPound(string s, int p) {
        for (int i = p; i < s.length(); ++ i) {
            if (s[i] == '#') return i;
        }
        return -1;
    }
    
};

// Works. Tested. 
// Idea:
// Encode a string like len#string this way, for example 
// {"", "abc", "ab", "2#"}, it will encode it to "0#3#abc2#ab2#2#", 
// then decode it by reading the length first, followed by reading 
// the string with the length.
// From: https://leetcode.com/discuss/84046/pretty-easy-solution
class Codec3 {
public:
    string encode(vector<string> strs) {
        if(strs.size() == 0) return "";
        
        string sb;
        for(int i = 0; i< strs.size();i++){
            sb += to_string(strs[i].length()) + "#" + strs[i];
        }
        return sb;
    }
    
    // Decodes a single string to a list of strings.
    vector<string> decode(string s) {
        vector<string> res;
        if(s == "") return res;

        int i = 0;
        while(i < s.length()){
           int seperatorIndex = s.find("#",i);
           int len = stoi(s.substr(i,seperatorIndex - i));
           res.push_back(s.substr(seperatorIndex+1, len)); 
           i = seperatorIndex + len + 1;
        }
        return res;
    }
};


// Works too. Tested.
// Same idea as Codec, different implementation.
// From: https://leetcode.com/discuss/59840/clean-code-standard-way-of-serialization-deserialization
class Codec2 {
public:
    string encode(vector<string>& strs) {
        string rst;
        rst += formatNumber( strs.size() ); 
        for(string& s: strs) {
            rst+= formatNumber( s.size() ); 
        }
    
        for(string& s: strs) {
            rst+= s;
        }
        return rst;
    }
    
    // Decodes a single string to a list of strings.
    vector<string> decode(string s) {
        int n = stoi( s.substr(0, 4) );
        vector<string> rst;
        vector<int> lens;
        int st = 4;         
        for(int i=0; i< n; i++) {
            int tmp = stoi(s.substr(st, 4));
            lens.push_back(tmp);
            st = st + 4;
        }
    
        for(int i=0; i<n; i++) {
            string tmp;
            tmp = s.substr(st, lens[i] ); //Note: ["", ""]
            rst.push_back(tmp);
            st = st + lens[i];
        }
        return rst;
    }
    
    string formatNumber(int n) {
        stringstream ss;
        ss << setw(4) << setfill('0') << n;
        return ss.str();
    }
};

// Works. Tested. 
// Idea: 
// Convert string length to a string. Because an int is four bytes in C++, 
// this string's length will always be four.
// The encoded vector will look like: CONVERTED5(len=4) abcde CONVERTED3(len=4) abc ...
// From: https://leetcode.com/discuss/85189/a-solution-without-delimiter
class Codec {
public:
    // Encodes a list of strings to a single string.
    string encode(vector<string>& strs) {
        string ret;
        for (const auto& e: strs) {
            ret += int2string(e.length()) + e;
        }
        return ret;
    }

    // Decodes a single string to a list of strings.
    vector<string> decode(string s) {
        int i = 0;
        vector<string> ret;
        while (i < s.length()) {
            int len = string2int(s.substr(i, 4));
            i += 4;
            ret.push_back(s.substr(i, len));
            i += len;
        }
        return ret;
    }
private:
    static string int2string(const int x) {
        char* s = (char* ) &x;
        string ret;
        for (int i = 0; i < 4; ++i) {
            ret += s[i];
        }
        return ret;
    }
    static int string2int(const string s) {
        char t[4];
        for (int i = 0; i < 4; ++i) {
            t[i] = s[i];
        }
        return *(int *) t;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.decode(codec.encode(strs));


/**
Encode and Decode Strings
Difficulty: Medium

Design an algorithm to encode a list of strings to a string. 
The encoded string is then sent over the network and is 
decoded back to the original list of strings.

Machine 1 (sender) has the function:

string encode(vector<string> strs) {
  // ... your code
  return encoded_string;
}
Machine 2 (receiver) has the function:
vector<string> decode(string s) {
  //... your code
  return strs;
}
So Machine 1 does:

string encoded_string = encode(strs);
and Machine 2 does:

vector<string> strs2 = decode(encoded_string);
strs2 in Machine 2 should be the same as strs in Machine 1.

Implement the encode and decode methods.

Note:
1. The string may contain any possible characters out of 256 valid 
   ascii characters. Your algorithm should be generalized enough 
   to work on any possible characters.
2. Do not use class member/global/static variables to store states. 
   Your encode and decode algorithms should be stateless.
3. Do not rely on any library method such as eval or serialize methods. 
   You should implement your own encode/decode algorithm.
 */
