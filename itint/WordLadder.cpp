class WW {
public:
    string w;
    WW * prev;
    WW(string _w, WW * p) : w(_w), prev(p) { }
};

vector<string> transform(set<string> &dict, string start, string end) {
    vector<string> ans;
    if (start == end) {
        ans.push_back(end);
        return ans;
    }
    
        queue<WW *> words;
        set<string> words_used;
        int min_len = 0;
        
        words.push(new WW(start, NULL));
        words_used.insert(start);
        
        while (words.size() > 0) {
            WW * z = words.front();
            words.pop();
            string w = z->w;
            
            int len = w.length();
            for (int i = 0; i < len; ++ i) {
                char c = w[i];
                for (int j = 0; j < 26; ++ j) {
                    if (c == 'A' + j) continue;
                    
                    w[i] = 'A' + j;
                    if (w == end) {
                        vector<string> a;
                        a.insert(a.begin(), end);

                        for (WW * x = z; x->prev; x = x->prev) {
                            a.insert(a.begin(), x->w);
                        }
                        a.insert(a.begin(), start);
                        
                        if (min_len == 0 || min_len > a.size()) {
                            min_len = a.size();
                            ans = a;
                        }
                        // break; // if only need to find one path, can just stop here.
                    }
                    else {
                        if (dict.find(w) != dict.end() 
                            && words_used.find(w) == words_used.end() ) {
                            words.push(new WW(w, z));
                            words_used.insert(w);
                        }
                    }
                    
                } // end of for
                w[i] = c;
            } // end of for
        }
        
        //return min_len;    
    return ans;
}

// same as leetcode wordLadder, but use upper case letters.