#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <queue>
using namespace std;


// Works too. Tested. 
// From: https://leetcode.com/discuss/41689/88ms-accepted-solution-with-68ms-word-ladder-88ms-word-ladder
class Solution {
public:
    vector<vector<string>> findLadders(string start, string end, unordered_set<string> &dict) {
        vector<vector<string> > ladders;
        vector<string> ladder;
        ladder.push_back(start);
        unordered_set<string> startWords, endWords;
        startWords.insert(start);
        endWords.insert(end);
        unordered_map<string, vector<string> > children;
        bool flip = true;
        if (searchLadders(startWords, endWords, dict, children, flip))
            genLadders(start, end, children, ladder, ladders);
        return ladders;
    }
    
private:
    bool searchLadders(unordered_set<string>& startWords, unordered_set<string>& endWords, 
                 unordered_set<string>& dict, unordered_map<string, vector<string> >& children, bool flip) {
        flip = !flip;
        if (startWords.empty()) return false;
        if (startWords.size() > endWords.size())
            return searchLadders(endWords, startWords, dict, children, flip);
        for (string word : startWords) dict.erase(word);
        for (string word : endWords) dict.erase(word);
        unordered_set<string> intermediate;
        bool done = false;
        for (string word : startWords) {
            int n = word.length();
            string temp = word;
            for (int p = 0; p < n; p++) {
                char letter = word[p];
                for (int i = 0; i < 26; i++) {
                    word[p] = 'a' + i;
                    if (endWords.find(word) != endWords.end()) {
                        done = true;
                        flip ? children[word].push_back(temp) : children[temp].push_back(word);
                    }
                    else if (!done && dict.find(word) != dict.end()) {
                        intermediate.insert(word);
                        flip ? children[word].push_back(temp) : children[temp].push_back(word);
                    }
                }   
                word[p] = letter;
            }
        }
        return done || searchLadders(endWords, intermediate, dict, children, flip);
    }
    
    void genLadders(string& start, string& end, unordered_map<string, vector<string> >& children, 
                    vector<string>& ladder, vector<vector<string> >& ladders) {
        if (start == end) {
            ladders.push_back(ladder);
            return;
        }
        for (string child : children[start]) {
            ladder.push_back(child);
            genLadders(child, end, children, ladder, ladders);
            ladder.pop_back();
        }
    }
};


// This works!
// Modified/Optimized from Solution4.
class Solution5 {
public:
    vector<vector<string>> findLadders(string start, string end, unordered_set<string> &dict) {
        vector<vector<string> > ans;
        if (start == end) return ans;
        
        map<string, vector<string> > rev; // reverse mapping.

        queue<pair<string, int> > q;
        q.push(pair<string, int>(start, 1));

        set<string> used;
        used.insert(start);
        
        int min_len = 0;

        while (! q.empty()) {
            string t = q.front().first;
            string t2 = t; // backup.
            int d = q.front().second;
            q.pop();
            
            for (int i = 0, n = end.length(); i < n; ++ i) {
                char c = t[i];
                for (int j = 0; j < 26; ++ j) {
                    if (c == j + 'a') continue;
                    t[i] = j + 'a';
                    
                    if (t == end) { //cout << "found. min_len = " << d+1 << endl;
                        if (min_len == 0 || min_len > d + 1) { 
                            min_len = d + 1; 
                            rev[end].clear();
                            rev[end].push_back(t2);
                        } 
                        else if (min_len == d + 1) {
                            rev[end].push_back(t2);
                        }
                    }
                    else if (dict.find(t) != dict.end()) {
                        if (used.find(t) == used.end()) {
                            q.push(pair<string, int>(t, d+1));
                            used.insert(t);    
                            rev[t].push_back(t2);            
                        } 
                        else if (find(rev[t].begin(), rev[t].end(), t2) == rev[t].end()
                                && find(rev[t2].begin(), rev[t2].end(), t) == rev[t2].end()) { /* avoid cycle. */
                            rev[t].push_back(t2); // t has been used. But relation t2->t was not recorded.
                        }
                    }
                } // end for
                t[i] = c; // recover t. Don't forget this!
            }
        }
        
        vector<string> path;
        path.push_back(end);
        getAllPath(ans, rev, path, start, end, min_len);
        
        return ans;
    }
    
    void getAllPath(vector<vector<string> > &ans, map<string, vector<string> > &rev, 
           vector<string> path, string start, string s, int min_len) {
        if (s == start) {
            ans.push_back(path);
            return;
        }
        if (min_len == 1) return;
        
        for (int i = 0; i < rev[s].size(); ++ i) {
            string x = rev[s][i];
            vector<string> p = path;
            p.insert(p.begin(), x);
            getAllPath(ans, rev, p, start, x, min_len - 1);
        }
    }
    
    // getAllPath2() is optimized from getAllPath() by passing path as reference,
    // and use only 1 copy of path in the process. This saves space. X.C. 1/28/2015
    void getAllPath2(vector<vector<string> > &ans, map<string, vector<string> > &rev, 
           vector<string> &path, string start, string s, int min_len) {
        if (s == start) {
            ans.push_back(path);
            return;
        }
        if (min_len == 1) return;
        
        for (int i = 0; i < rev[s].size(); ++ i) {
            string x = rev[s][i];
            path.insert(path.begin(), x);
            getAllPath2(ans, rev, path, start, x, min_len - 1);
            path.erase(path.begin());
        }
    }    
};



class WW {
public:
    string w;
    WW * prev;
    set<WW *> prevs;
    WW(string _w, WW * p) : w(_w), prev(p) { }
};

// works. But memory limit exceeded.
class Solution2 {
public:
    vector<vector<string> > findLadders(string start, string end, set<string> &dict) {
        vector<vector<string> > ans;
        //if (start == end) return ans;
        
        queue<WW *> words;
        set<string> words_used, words_cur;
        map<string, WW *> path;
        int min_len = INT_MAX;
        
        words.push(new WW(start, NULL));
        words_cur.insert(start);
        
        while (words.size() > 0) {
            WW * z = words.front();
            words.pop();
            words_cur.erase(words_cur.find(z->w));
            words_used.insert(z->w);
            string w = z->w;
            
            int len = w.length();
            for (int i = 0; i < len; ++ i) {
                char c = w[i];
                for (int j = 0; j < 26; ++ j) {
                    if (c == 'a' + j) continue;
                    
                    w[i] = 'a' + j;
                    if (w == end) {
                        WW * s = new WW(end, z);
                        if (path[end] == NULL) {
                            path[end] = s;
                        }
                        path[end]->prevs.insert(z);
                        
cout << "find target: " << z->w << " -> " << end << endl;

                        for (WW * x = z; x->prev; x = x->prev) {
                            if (path[x->w] == NULL) {
                                path[x->w] = x;
                            }
                            path[x->w]->prevs.insert(x->prev);
                        }

                        break;
                    }
                    else {
                        if (dict.find(w) != dict.end() 
                            && words_used.find(w) == words_used.end() 
                            && words_cur.find(w) == words_cur.end() ) {
                                                 
cout << "push: " << z->w << " -> " << w << endl;
if (path[w] == NULL) path[w] = new WW(w, z);
path[w]->prevs.insert(z);
                            words.push(new WW(w, z));
                            //((WW *) words.front())->next = z;
                            words_cur.insert(w);
                        }
                        else if (path[w] != NULL 
                            && words_cur.find(w) != words_cur.end()
                            && words_used.find(z->w) != words_used.end()
                        ) {
cout << "is on path: " << w << " <- " << z->w << endl;
//if (path[w] == NULL) path[w] = new WW(w, z);
path[w]->prevs.insert(z);

                        }
                        else {
//cout << "w = " << w << endl;
                        }
                    }
                    
                } // end of for
                w[i] = c;
            } // end of for
        }
        
        /*for (map<string, WW*>::iterator it = path.begin(); it != path.end(); ++ it) {
            WW * ww = (*it).second;
            if (ww) {
                cout << (*it).first << " => WW(" << ww->w << " <- " << 
                (ww->prev ? ww->prev->w : "NULL") << ", " << getPrevs(ww)
                << ")" << endl;
            }
        }*/
        
        if (path[end] != NULL) {
            vector<string> v;
            ans.clear();
            dump2(start, end, path, v, ans);
        }
        
        return ans;
    }
    
    void dump2(string start, string word, map<string, WW *> &path, vector<string> v, vector<vector<string> > &ans) {
        WW * w = path[word];

        if (w == NULL) {
           v.insert(v.begin(), start);
           ans.push_back(v);
           return;
        }

        v.insert(v.begin(), w->w);
        set<WW *> &ww = w->prevs;
        for (set<WW *>::iterator it = ww.begin(); it != ww.end(); ++ it) {
            dump2(start, ((WW*)(*it))->w, path, v, ans);
        }
    }
    
    string getPrevs(WW * w) {
        string s = "(prevs: ";
        set<WW *> &ww = (w->prevs);
        for (set<WW *>::iterator it = ww.begin(); it != ww.end(); ++ it) {
            s += ((WW*)(*it))->w + " ";
        }
        s += ")";
        return s;
    }
};

// modified from Solution2. works. But memory limit exceeded.
class Solution3 {
public:
    vector<vector<string> > findLadders(string start, string end, set<string> &dict) {
        vector<vector<string> > ans;
        
        queue<WW *> words;
        set<string> words_used, words_cur;
        map<string, WW *> path;
        int min_len = INT_MAX;
        
        words.push(new WW(start, NULL));
        words_cur.insert(start);
        
        while (words.size() > 0) {
            WW * z = words.front();
            words.pop();
            words_cur.erase(words_cur.find(z->w));
            words_used.insert(z->w);
            string w = z->w;
            
            int len = w.length();
            for (int i = 0; i < len; ++ i) {
                char c = w[i];
                for (int j = 0; j < 26; ++ j) {
                    if (c == 'a' + j) continue;
                    
                    w[i] = 'a' + j;
                    if (w == end) {
                        WW * s = new WW(end, z);
                        if (path[end] == NULL) path[end] = s;
                        path[end]->prevs.insert(z);
                    }
                    else {
                        if (dict.find(w) != dict.end() 
                            && words_used.find(w) == words_used.end() 
                            && words_cur.find(w) == words_cur.end() ) {
                                                 
                            if (path[w] == NULL) path[w] = new WW(w, z);
                            path[w]->prevs.insert(z);
                            words.push(new WW(w, z));
                            words_cur.insert(w);
                        }
                        else if (path[w] != NULL 
                            && words_cur.find(w) != words_cur.end()
                            && words_used.find(z->w) != words_used.end() ) {
                            path[w]->prevs.insert(z);
                        }
                    }
                } // end of for
                w[i] = c;
            } // end of for
        }
                
        if (path[end] != NULL) {
            vector<string> v;
            dump(start, end, path, v, ans, min_len);
        }
        
        return ans;
    }
    
    void dump(string start, string word, map<string, WW *> &path, 
              vector<string> v, vector<vector<string> > &ans, int &min_len) {
        WW * w = path[word];

        if (w == NULL) {
           v.insert(v.begin(), start);
           if (min_len >= v.size()) {
               if (min_len > v.size()) {
                   ans.clear();
                   min_len = v.size();
               }
               ans.push_back(v);
           }
           return;
        }

        v.insert(v.begin(), w->w);
        set<WW *> &ww = w->prevs;
        for (set<WW *>::iterator it = ww.begin(); it != ww.end(); ++ it) {
            dump(start, ((WW*)(*it))->w, path, v, ans, min_len);
        }
    }
};

/*
//////////////////////////////////////////////////////////////
// This works!! Passes all test cases.
//////////////////////////////////////////////////////////////

class Solution {
public:
    vector<vector<string>> findLadders(string start, string end, unordered_set<string> &dict) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<string>> ans;
        if (start == end) return ans;
        
        unordered_map<string, vector<string>> rev; // reverse mapping.
        unordered_set<string> used;
        queue<pair<string, int>> q;
        
        q.push(pair<string, int>(start, 1));
        used.insert(start);
        
        int min_len = 0;
        while (! q.empty()) {
            string t = q.front().first;
            string t2 = t; // backup.
            int d = q.front().second;
            q.pop();
            
            for (int i = 0, n = end.length(); i < n; ++ i) {
                char c = t[i];
                for (int j = 0; j < 26; ++ j) {
                    if (c == j + 'a') continue;
                    t[i] = j + 'a';
                    
                    if (t == end) {
                        if (min_len == 0) { 
                            min_len = d + 1; 
                            rev[end].push_back(t2);
                        } 
                        else if (min_len == d + 1) {
                            rev[end].push_back(t2);
                        }
                        else if (min_len > d + 1) {
                            min_len = d + 1;
                            //rev[end].clear(); // use this or not, both ok.
                            rev[end].push_back(t2);
                        }
                    }
                    else if (dict.find(t) != dict.end()) {
                        if (used.find(t) == used.end()) {
                            q.push(pair<string, int>(t, d+1));
                            used.insert(t);    
                            rev[t].push_back(t2);            
                        } 
                        else 
                        { // t has been used. But relation t2->t was not recorded.
                          // Strangely the first check is not needed to pass, but it's safe to do. 
                            if (//find(rev[t].begin(), rev[t].end(), t2) == rev[t].end() && 
                                find(rev[t2].begin(), rev[t2].end(), t) == rev[t2].end()
                            ) 
                            {
                                rev[t].push_back(t2);
                            }
                        }
                    }
                } // end for
                t[i] = c; // recover t. Don't forget this!
            }
        }
        
        vector<string> path;
        path.push_back(end);
        F(ans, rev, path, start, end, min_len);
        
        return ans;
    }
    
    // Get path reversely.
    void F(vector<vector<string>> &ans, unordered_map<string, vector<string>> &rev, 
           vector<string> path, string start, string s, int min_len) {
        if (s == start) {
            ans.push_back(path);
            return;
        }
        if (min_len == 1) return;
        
        for (int i = 0; i < rev[s].size(); ++ i) {
            string x = rev[s][i];
            vector<string> p = path;
            p.insert(p.begin(), x);
            F(ans, rev, p, start, x, min_len - 1);
        }
    }
};

*/

// This works. 
// This is adapted from above, not use C++11 feature.
class Solution4 {
public:
    vector<vector<string> > findLadders(string start, string end, set<string> &dict) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<string> > ans;
        if (start == end) return ans;
        
        map<string, vector<string> > rev; // reverse mapping.
        set<string> used;
        queue<pair<string, int> > q;
        
        q.push(pair<string, int>(start, 1));
        used.insert(start);
        
        int min_len = 0;
        //F(end, dict, used, q, min_len);
        
        while (! q.empty()) {
            string t = q.front().first;
            string t2 = t; // backup.
            int d = q.front().second;
            q.pop();
            
            for (int i = 0, n = end.length(); i < n; ++ i) {
                char c = t[i];
                for (int j = 0; j < 26; ++ j) {
                    if (c == j + 'a') continue;
                    t[i] = j + 'a';
                    
                    if (t == end) {
                        cout << "found. min_len = " << d+1 << endl;
                        if (min_len == 0) { 
                            min_len = d + 1; 
                            rev[end].push_back(t2);
                        } 
                        else if (min_len == d + 1) {
                            rev[end].push_back(t2);
                        }
                        else if (min_len > d + 1) {
                            min_len = d + 1;
                            //rev[end].clear();
                            rev[end].push_back(t2);
                        }
                    }
                    else if (dict.find(t) != dict.end()) {
                        if (used.find(t) == used.end()) {
                            q.push(pair<string, int>(t, d+1));
                            used.insert(t);    
                            rev[t].push_back(t2);            
                        } 
                        else 
                        { // t has been used. But relation t2->t was not recorded.
                            if (find(rev[t].begin(), rev[t].end(), t2) == rev[t].end()
                              && find(rev[t2].begin(), rev[t2].end(), t) == rev[t2].end()
                            ) 
                            {
                                rev[t].push_back(t2);
                            }
                        }
                    }
                } // end for
                t[i] = c; // recover t. Don't forget this!
            }
        }
        cout << "min_len = " << min_len << endl;
        
        if (1)
        for (map<string, vector<string> >::iterator it = rev.begin(); it != rev.end(); ++ it) {
            cout << (*it).first << "[";
            for (int i = 0; i < (*it).second.size(); ++ i) {
                cout << (*it).second[i] << " ";
            }
            cout << "]" << endl;
        }
        
        
        vector<string> path;
        path.push_back(end);
        F(ans, rev, path, start, end, min_len);
        
        return ans;
    }
    
    void F(vector<vector<string> > &ans, map<string, vector<string> > &rev, 
           vector<string> path, string start, string s, int min_len) {
        if (s == start) {
            ans.push_back(path);
            return;
        }
        if (min_len == 1) return;
        
        for (int i = 0; i < rev[s].size(); ++ i) {
            string x = rev[s][i];
            vector<string> p = path;
            p.insert(p.begin(), x);
            F(ans, rev, p, start, x, min_len - 1);
        }
    }
};


void dump(vector<vector<string> > ans) {
    //cout << "result: ans.size() = " << ans.size() << endl;
    for (int i = 0; i < ans.size(); ++ i) {
        vector<string> a = ans[i];
        for (int j = 0; j < a.size(); ++ j) {
            cout << a[j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

void test1() {
    string start = "hot", end = "dog";
    set<string> s;
    string dic[] = {"hot","cog","dog","tot","hog","hop","pot","dot"};
    for (int i = 0; i < 8; ++ i) {
        s.insert(dic[i]);
    }
    Solution4 so;
    dump( so.findLadders(start, end, s) );    
}

void test2() {
    string start = "hit", end = "cog";
    set<string> s;
    string dic[] = {"hot","cog","dot","dog","hit","lot","log"};
    for (int i = 0; i < 7; ++ i) {
        s.insert(dic[i]);
    }
    Solution3 so;
    dump( so.findLadders(start, end, s) );    
}

void test3() {
    string start = "red", end = "tax";
    set<string> s;
    string dic[] = {"ted","tex","red","tax","tad","den","rex","pee"};
    for (int i = 0; i < 8; ++ i) {
        s.insert(dic[i]);
    }
    Solution4 so;
    dump( so.findLadders(start, end, s) );    
}

void test4() {
    string start = "nanny", end = "aloud";
    set<string> s;
    string dic[] = {"ricky","grind","cubic","panic","lover","farce","gofer","sales","flint","omens","lipid","briny","cloth","anted","slime","oaten","harsh","touts","stoop","cabal","lazed","elton","skunk","nicer","pesky","kusch","bused","kinda","tunis","enjoy","aches","prowl","babar","rooms","burst","slush","pines","urine","pinky","bayed","mania","light","flare","wares","women","verne","moron","shine","bluer","zeros","bleak","brief","tamra","vasts","jamie","lairs","penal","worst","yowls","pills","taros","addle","alyce","creep","saber","floyd","cures","soggy","vexed","vilma","cabby","verde","euler","cling","wanna","jenny","donor","stole","sakha","blake","sanes","riffs","forge","horus","sered","piked","prosy","wases","glove","onset","spake","benin","talks","sites","biers","wendy","dante","allan","haven","nears","shaka","sloth","perky","spear","spend","clint","dears","sadly","units","vista","hinds","marat","natal","least","bough","pales","boole","ditch","greys","slunk","bitch","belts","sense","skits","monty","yawns","music","hails","alien","gibes","lille","spacy","argot","wasps","drubs","poops","bella","clone","beast","emend","iring","start","darla","bells","cults","dhaka","sniff","seers","bantu","pages","fever","tacky","hoses","strop","climb","pairs","later","grant","raven","stael","drips","lucid","awing","dines","balms","della","galen","toned","snips","shady","chili","fears","nurse","joint","plump","micky","lions","jamal","queer","ruins","frats","spoof","semen","pulps","oldie","coors","rhone","papal","seals","spans","scaly","sieve","klaus","drums","tided","needs","rider","lures","treks","hares","liner","hokey","boots","primp","laval","limes","putts","fonda","damon","pikes","hobbs","specs","greet","ketch","braid","purer","tsars","berne","tarts","clean","grate","trips","chefs","timex","vicky","pares","price","every","beret","vices","jodie","fanny","mails","built","bossy","farms","pubic","gongs","magma","quads","shell","jocks","woods","waded","parka","jells","worse","diner","risks","bliss","bryan","terse","crier","incur","murky","gamed","edges","keens","bread","raced","vetch","glint","zions","porno","sizes","mends","ached","allie","bands","plank","forth","fuels","rhyme","wimpy","peels","foggy","wings","frill","edgar","slave","lotus","point","hints","germs","clung","limed","loafs","realm","myron","loopy","plush","volts","bimbo","smash","windy","sours","choke","karin","boast","whirr","tiber","dimes","basel","cutes","pinto","troll","thumb","decor","craft","tared","split","josue","tramp","screw","label","lenny","apses","slept","sikhs","child","bouts","cites","swipe","lurks","seeds","fists","hoard","steed","reams","spoil","diego","peale","bevel","flags","mazes","quart","snipe","latch","lards","acted","falls","busby","holed","mummy","wrong","wipes","carlo","leers","wails","night","pasty","eater","flunk","vedas","curse","tyros","mirth","jacky","butte","wired","fixes","tares","vague","roved","stove","swoon","scour","coked","marge","cants","comic","corns","zilch","typos","lives","truer","comma","gaily","teals","witty","hyper","croat","sways","tills","hones","dowel","llano","clefs","fores","cinch","brock","vichy","bleed","nuder","hoyle","slams","macro","arabs","tauts","eager","croak","scoop","crime","lurch","weals","fates","clipt","teens","bulls","domed","ghana","culls","frame","hanky","jared","swain","truss","drank","lobby","lumps","pansy","whews","saris","trite","weeps","dozes","jeans","flood","chimu","foxes","gelds","sects","scoff","poses","mares","famed","peers","hells","laked","zests","wring","steal","snoot","yodel","scamp","ellis","bandy","marry","jives","vises","blurb","relay","patch","haley","cubit","heine","place","touch","grain","gerry","badly","hooke","fuchs","savor","apron","judge","loren","britt","smith","tammy","altar","duels","huber","baton","dived","apace","sedan","basts","clark","mired","perch","hulks","jolly","welts","quack","spore","alums","shave","singe","lanny","dread","profs","skeet","flout","darin","newed","steer","taine","salvo","mites","rules","crash","thorn","olive","saves","yawed","pique","salon","ovens","dusty","janie","elise","carve","winds","abash","cheep","strap","fared","discs","poxed","hoots","catch","combo","maize","repay","mario","snuff","delve","cored","bards","sudan","shuns","yukon","jowls","wayne","torus","gales","creek","prove","needy","wisps","terri","ranks","books","dicky","tapes","aping","padre","roads","nines","seats","flats","rains","moira","basic","loves","pulls","tough","gills","codes","chest","teeny","jolts","woody","flame","asked","dulls","hotly","glare","mucky","spite","flake","vines","lindy","butts","froth","beeps","sills","bunny","flied","shaun","mawed","velds","voled","doily","patel","snake","thigh","adler","calks","desks","janus","spunk","baled","match","strip","hosed","nippy","wrest","whams","calfs","sleet","wives","boars","chain","table","duked","riped","edens","galas","huffs","biddy","claps","aleut","yucks","bangs","quids","glenn","evert","drunk","lusts","senna","slate","manet","roted","sleep","loxes","fluky","fence","clamp","doted","broad","sager","spark","belch","mandy","deana","beyer","hoist","leafy","levee","libel","tonic","aloes","steam","skews","tides","stall","rifts","saxon","mavis","asama","might","dotes","tangs","wroth","kited","salad","liens","clink","glows","balky","taffy","sided","sworn","oasis","tenth","blurt","tower","often","walsh","sonny","andes","slump","scans","boded","chive","finer","ponce","prune","sloes","dined","chums","dingo","harte","ahead","event","freer","heart","fetch","sated","soapy","skins","royal","cuter","loire","minot","aisle","horny","slued","panel","eight","snoop","pries","clive","pored","wrist","piped","daren","cells","parks","slugs","cubed","highs","booze","weary","stain","hoped","finny","weeds","fetid","racer","tasks","right","saint","shahs","basis","refer","chart","seize","lulls","slant","belay","clots","jinny","tours","modes","gloat","dunks","flute","conch","marts","aglow","gayer","lazes","dicks","chime","bears","sharp","hatch","forms","terry","gouda","thins","janet","tonya","axons","sewed","danny","rowdy","dolts","hurry","opine","fifty","noisy","spiky","humid","verna","poles","jayne","pecos","hooky","haney","shams","snots","sally","ruder","tempe","plunk","shaft","scows","essie","dated","fleet","spate","bunin","hikes","sodas","filly","thyme","fiefs","perks","chary","kiths","lidia","lefty","wolff","withe","three","crawl","wotan","brown","japed","tolls","taken","threw","crave","clash","layer","tends","notes","fudge","musky","bawdy","aline","matts","shirr","balks","stash","wicks","crepe","foods","fares","rotes","party","petty","press","dolly","mangy","leeks","silly","leant","nooks","chapt","loose","caged","wages","grist","alert","sheri","moody","tamps","hefts","souls","rubes","rolex","skulk","veeps","nonce","state","level","whirl","bight","grits","reset","faked","spiny","mixes","hunks","major","missy","arius","damns","fitly","caped","mucus","trace","surat","lloyd","furry","colin","texts","livia","reply","twill","ships","peons","shear","norms","jumbo","bring","masks","zippy","brine","dorks","roded","sinks","river","wolfs","strew","myths","pulpy","prank","veins","flues","minus","phone","banns","spell","burro","brags","boyle","lambs","sides","knees","clews","aired","skirt","heavy","dimer","bombs","scums","hayes","chaps","snugs","dusky","loxed","ellen","while","swank","track","minim","wiled","hazed","roofs","cantu","sorry","roach","loser","brass","stint","jerks","dirks","emory","campy","poise","sexed","gamer","catty","comte","bilbo","fasts","ledge","drier","idles","doors","waged","rizal","pured","weirs","crisp","tasty","sored","palmy","parts","ethel","unify","crows","crest","udder","delis","punks","dowse","totes","emile","coded","shops","poppa","pours","gushy","tiffs","shads","birds","coils","areas","boons","hulls","alter","lobes","pleat","depth","fires","pones","serra","sweat","kline","malay","ruled","calve","tired","drabs","tubed","wryer","slung","union","sonya","aided","hewed","dicey","grids","nixed","whits","mills","buffs","yucky","drops","ready","yuppy","tweet","napes","cadre","teach","rasps","dowdy","hoary","canto","posed","dumbo","kooks","reese","snaky","binge","byron","phony","safer","friar","novel","scale","huron","adorn","carla","fauna","myers","hobby","purse","flesh","smock","along","boils","pails","times","panza","lodge","clubs","colby","great","thing","peaks","diana","vance","whets","bergs","sling","spade","soaks","beach","traps","aspen","romps","boxed","fakir","weave","nerds","swazi","dotty","curls","diver","jonas","waite","verbs","yeast","lapel","barth","soars","hooks","taxed","slews","gouge","slags","chang","chafe","saved","josie","syncs","fonds","anion","actor","seems","pyrex","isiah","glued","groin","goren","waxes","tonia","whine","scads","knelt","teaks","satan","tromp","spats","merry","wordy","stake","gland","canal","donna","lends","filed","sacks","shied","moors","paths","older","pooch","balsa","riced","facet","decaf","attic","elder","akron","chomp","chump","picky","money","sheer","bolls","crabs","dorms","water","veers","tease","dummy","dumbs","lethe","halls","rifer","demon","fucks","whips","plops","fuses","focal","taces","snout","edict","flush","burps","dawes","lorry","spews","sprat","click","deann","sited","aunts","quips","godly","pupil","nanny","funks","shoon","aimed","stacy","helms","mints","banks","pinch","local","twine","pacts","deers","halos","slink","preys","potty","ruffs","pusan","suits","finks","slash","prods","dense","edsel","heeds","palls","slats","snits","mower","rares","ailed","rouge","ellie","gated","lyons","duded","links","oaths","letha","kicks","firms","gravy","month","kongo","mused","ducal","toted","vocal","disks","spied","studs","macao","erick","coupe","starr","reaps","decoy","rayon","nicks","breed","cosby","haunt","typed","plain","trays","muled","saith","drano","cower","snows","buses","jewry","argus","doers","flays","swish","resin","boobs","sicks","spies","bails","wowed","mabel","check","vapid","bacon","wilda","ollie","loony","irked","fraud","doles","facts","lists","gazed","furls","sunks","stows","wilde","brick","bowed","guise","suing","gates","niter","heros","hyped","clomp","never","lolls","rangy","paddy","chant","casts","terns","tunas","poker","scary","maims","saran","devon","tripe","lingo","paler","coped","bride","voted","dodge","gross","curds","sames","those","tithe","steep","flaks","close","swops","stare","notch","prays","roles","crush","feuds","nudge","baned","brake","plans","weepy","dazed","jenna","weiss","tomes","stews","whist","gibed","death","clank","cover","peeks","quick","abler","daddy","calls","scald","lilia","flask","cheer","grabs","megan","canes","jules","blots","mossy","begun","freak","caved","hello","hades","theed","wards","darcy","malta","peter","whorl","break","downs","odder","hoofs","kiddo","macho","fords","liked","flees","swing","elect","hoods","pluck","brook","astir","bland","sward","modal","flown","ahmad","waled","craps","cools","roods","hided","plath","kings","grips","gives","gnats","tabby","gauls","think","bully","fogey","sawed","lints","pushy","banes","drake","trail","moral","daley","balds","chugs","geeky","darts","soddy","haves","opens","rends","buggy","moles","freud","gored","shock","angus","puree","raves","johns","armed","packs","minis","reich","slots","totem","clown","popes","brute","hedge","latin","stoke","blend","pease","rubik","greer","hindi","betsy","flows","funky","kelli","humps","chewy","welds","scowl","yells","cough","sasha","sheaf","jokes","coast","words","irate","hales","camry","spits","burma","rhine","bends","spill","stubs","power","voles","learn","knoll","style","twila","drove","dacca","sheen","papas","shale","jones","duped","tunny","mouse","floss","corks","skims","swaps","inned","boxer","synch","skies","strep","bucks","belau","lower","flaky","quill","aural","rufus","floes","pokes","sends","sates","dally","boyer","hurts","foyer","gowns","torch","luria","fangs","moats","heinz","bolts","filet","firth","begot","argue","youth","chimp","frogs","kraft","smite","loges","loons","spine","domes","pokey","timur","noddy","doggy","wades","lanes","hence","louts","turks","lurid","goths","moist","bated","giles","stood","winos","shins","potts","brant","vised","alice","rosie","dents","babes","softy","decay","meats","tanya","rusks","pasts","karat","nuked","gorge","kinks","skull","noyce","aimee","watch","cleat","stuck","china","testy","doses","safes","stage","bayes","twins","limps","denis","chars","flaps","paces","abase","grays","deans","maria","asset","smuts","serbs","whigs","vases","robyn","girls","pents","alike","nodal","molly","swigs","swill","slums","rajah","bleep","beget","thanh","finns","clock","wafts","wafer","spicy","sorer","reach","beats","baker","crown","drugs","daisy","mocks","scots","fests","newer","agate","drift","marta","chino","flirt","homed","bribe","scram","bulks","servo","vesta","divas","preps","naval","tally","shove","ragas","blown","droll","tryst","lucky","leech","lines","sires","pyxed","taper","trump","payee","midge","paris","bored","loads","shuts","lived","swath","snare","boned","scars","aeons","grime","writs","paige","rungs","blent","signs","davis","dials","daubs","rainy","fawns","wrier","golds","wrath","ducks","allow","hosea","spike","meals","haber","muses","timed","broom","burks","louis","gangs","pools","vales","altai","elope","plied","slain","chasm","entry","slide","bawls","title","sings","grief","viola","doyle","peach","davit","bench","devil","latex","miles","pasha","tokes","coves","wheel","tried","verdi","wanda","sivan","prior","fryer","plots","kicky","porch","shill","coats","borne","brink","pawed","erwin","tense","stirs","wends","waxen","carts","smear","rival","scare","phase","bragg","crane","hocks","conan","bests","dares","molls","roots","dunes","slips","waked","fours","bolds","slosh","yemen","poole","solid","ports","fades","legal","cedes","green","curie","seedy","riper","poled","glade","hosts","tools","razes","tarry","muddy","shims","sword","thine","lasts","bloat","soled","tardy","foots","skiff","volta","murks","croci","gooks","gamey","pyxes","poems","kayla","larva","slaps","abuse","pings","plows","geese","minks","derby","super","inked","manic","leaks","flops","lajos","fuzes","swabs","twigs","gummy","pyres","shrew","islet","doled","wooly","lefts","hunts","toast","faith","macaw","sonia","leafs","colas","conks","altos","wiped","scene","boors","patsy","meany","chung","wakes","clear","ropes","tahoe","zones","crate","tombs","nouns","garth","puked","chats","hanks","baked","binds","fully","soaps","newel","yarns","puers","carps","spelt","lully","towed","scabs","prime","blest","patty","silky","abner","temps","lakes","tests","alias","mines","chips","funds","caret","splat","perry","turds","junks","cramp","saned","peary","snarl","fired","stung","nancy","bulge","styli","seams","hived","feast","triad","jaded","elvin","canny","birth","routs","rimed","pusey","laces","taste","basie","malls","shout","prier","prone","finis","claus","loops","heron","frump","spare","menus","ariel","crams","bloom","foxed","moons","mince","mixed","piers","deres","tempt","dryer","atone","heats","dario","hawed","swims","sheet","tasha","dings","clare","aging","daffy","wried","foals","lunar","havel","irony","ronny","naves","selma","gurus","crust","percy","murat","mauro","cowed","clang","biker","harms","barry","thump","crude","ulnae","thong","pager","oases","mered","locke","merle","soave","petal","poser","store","winch","wedge","inlet","nerdy","utter","filth","spray","drape","pukes","ewers","kinds","dates","meier","tammi","spoor","curly","chill","loped","gooey","boles","genet","boost","beets","heath","feeds","growl","livid","midst","rinds","fresh","waxed","yearn","keeps","rimes","naked","flick","plies","deeps","dirty","hefty","messy","hairy","walks","leper","sykes","nerve","rover","jived","brisk","lenin","viper","chuck","sinus","luger","ricks","hying","rusty","kathy","herds","wider","getty","roman","sandy","pends","fezes","trios","bites","pants","bless","diced","earth","shack","hinge","melds","jonah","chose","liver","salts","ratty","ashed","wacky","yokes","wanly","bruce","vowel","black","grail","lungs","arise","gluts","gluey","navel","coyer","ramps","miter","aldan","booth","musty","rills","darns","tined","straw","kerri","hared","lucks","metes","penny","radon","palms","deeds","earls","shard","pried","tampa","blank","gybes","vicki","drool","groom","curer","cubes","riggs","lanky","tuber","caves","acing","golly","hodge","beard","ginny","jibed","fumes","astor","quito","cargo","randi","gawky","zings","blind","dhoti","sneak","fatah","fixer","lapps","cline","grimm","fakes","maine","erika","dealt","mitch","olden","joist","gents","likes","shelf","silts","goats","leads","marin","spire","louie","evans","amuse","belly","nails","snead","model","whats","shari","quote","tacks","nutty","lames","caste","hexes","cooks","miner","shawn","anise","drama","trike","prate","ayers","loans","botch","vests","cilia","ridge","thugs","outed","jails","moped","plead","tunes","nosed","wills","lager","lacks","cried","wince","berle","flaws","boise","tibet","bided","shred","cocky","brice","delta","congo","holly","hicks","wraps","cocks","aisha","heard","cured","sades","horsy","umped","trice","dorky","curve","ferry","haler","ninth","pasta","jason","honer","kevin","males","fowls","awake","pores","meter","skate","drink","pussy","soups","bases","noyes","torts","bogus","still","soupy","dance","worry","eldon","stern","menes","dolls","dumpy","gaunt","grove","coops","mules","berry","sower","roams","brawl","greed","stags","blurs","swift","treed","taney","shame","easel","moves","leger","ville","order","spock","nifty","brian","elias","idler","serve","ashen","bizet","gilts","spook","eaten","pumas","cotes","broke","toxin","groan","laths","joins","spots","hated","tokay","elite","rawer","fiats","cards","sassy","milks","roost","glean","lutes","chins","drown","marks","pined","grace","fifth","lodes","rusts","terms","maxes","savvy","choir","savoy","spoon","halve","chord","hulas","sarah","celia","deems","ninny","wines","boggy","birch","raved","wales","beams","vibes","riots","warty","nigel","askew","faxes","sedge","sheol","pucks","cynic","relax","boers","whims","bents","candy","luann","slogs","bonny","barns","iambs","fused","duffy","guilt","bruin","pawls","penis","poppy","owing","tribe","tuner","moray","timid","ceded","geeks","kites","curio","puffy","perot","caddy","peeve","cause","dills","gavel","manse","joker","lynch","crank","golda","waits","wises","hasty","paves","grown","reedy","crypt","tonne","jerky","axing","swept","posse","rings","staff","tansy","pared","glaze","grebe","gonna","shark","jumps","vials","unset","hires","tying","lured","motes","linen","locks","mamas","nasty","mamie","clout","nader","velma","abate","tight","dales","serer","rives","bales","loamy","warps","plato","hooch","togae","damps","ofter","plumb","fifes","filmy","wiper","chess","lousy","sails","brahe","ounce","flits","hindu","manly","beaux","mimed","liken","forts","jambs","peeps","lelia","brews","handy","lusty","brads","marne","pesos","earle","arson","scout","showy","chile","sumps","hiked","crook","herbs","silks","alamo","mores","dunce","blaze","stank","haste","howls","trots","creon","lisle","pause","hates","mulch","mined","moder","devin","types","cindy","beech","tuned","mowed","pitts","chaos","colds","bidet","tines","sighs","slimy","brain","belle","leery","morse","ruben","prows","frown","disco","regal","oaken","sheds","hives","corny","baser","fated","throe","revel","bores","waved","shits","elvia","ferns","maids","color","coifs","cohan","draft","hmong","alton","stine","cluck","nodes","emily","brave","blair","blued","dress","bunts","holst","clogs","rally","knack","demos","brady","blues","flash","goofy","blocs","diane","colic","smile","yules","foamy","splay","bilge","faker","foils","condo","knell","crack","gallo","purls","auras","cakes","doves","joust","aides","lades","muggy","tanks","middy","tarps","slack","capet","frays","donny","venal","yeats","misty","denim","glass","nudes","seeps","gibbs","blows","bobbi","shane","yards","pimps","clued","quiet","witch","boxes","prawn","kerry","torah","kinko","dingy","emote","honor","jelly","grins","trope","vined","bagel","arden","rapid","paged","loved","agape","mural","budge","ticks","suers","wendi","slice","salve","robin","bleat","batik","myles","teddy","flatt","puppy","gelid","largo","attar","polls","glide","serum","fundy","sucks","shalt","sewer","wreak","dames","fonts","toxic","hines","wormy","grass","louse","bowls","crass","benny","moire","margo","golfs","smart","roxie","wight","reign","dairy","clops","paled","oddly","sappy","flair","shown","bulgy","benet","larch","curry","gulfs","fends","lunch","dukes","doris","spoke","coins","manna","conga","jinns","eases","dunno","tisha","swore","rhino","calms","irvin","clans","gully","liege","mains","besot","serge","being","welch","wombs","draco","lynda","forty","mumps","bloch","ogden","knits","fussy","alder","danes","loyal","valet","wooer","quire","liefs","shana","toyed","forks","gages","slims","cloys","yates","rails","sheep","nacho","divan","honks","stone","snack","added","basal","hasps","focus","alone","laxes","arose","lamed","wrapt","frail","clams","plait","hover","tacos","mooch","fault","teeth","marva","mucks","tread","waves","purim","boron","horde","smack","bongo","monte","swirl","deals","mikes","scold","muter","sties","lawns","fluke","jilts","meuse","fives","sulky","molds","snore","timmy","ditty","gasps","kills","carey","jawed","byers","tommy","homer","hexed","dumas","given","mewls","smelt","weird","speck","merck","keats","draws","trent","agave","wells","chews","blabs","roves","grieg","evens","alive","mulls","cared","garbo","fined","happy","trued","rodes","thurs","cadet","alvin","busch","moths","guild","staci","lever","widen","props","hussy","lamer","riley","bauer","chirp","rants","poxes","shyer","pelts","funny","slits","tinge","ramos","shift","caper","credo","renal","veils","covey","elmer","mated","tykes","wooed","briar","gears","foley","shoes","decry","hypes","dells","wilds","runts","wilts","white","easts","comer","sammy","lochs","favor","lance","dawns","bushy","muted","elsie","creel","pocks","tenet","cagey","rides","socks","ogled","soils","sofas","janna","exile","barks","frank","takes","zooms","hakes","sagan","scull","heaps","augur","pouch","blare","bulbs","wryly","homey","tubas","limbo","hardy","hoagy","minds","bared","gabby","bilks","float","limns","clasp","laura","range","brush","tummy","kilts","cooed","worms","leary","feats","robes","suite","veals","bosch","moans","dozen","rarer","slyer","cabin","craze","sweet","talon","treat","yanks","react","creed","eliza","sluts","cruet","hafts","noise","seder","flies","weeks","venus","backs","eider","uriel","vouch","robed","hacks","perth","shiny","stilt","torte","throb","merer","twits","reeds","shawl","clara","slurs","mixer","newts","fried","woolf","swoop","kaaba","oozed","mayer","caned","laius","lunge","chits","kenny","lifts","mafia","sowed","piled","stein","whack","colts","warms","cleft","girds","seeks","poets","angel","trade","parsi","tiers","rojas","vexes","bryce","moots","grunt","drain","lumpy","stabs","poohs","leapt","polly","cuffs","giddy","towns","dacha","quoth","provo","dilly","carly","mewed","tzars","crock","toked","speak","mayas","pssts","ocher","motel","vogue","camps","tharp","taunt","drone","taint","badge","scott","scats","bakes","antes","gruel","snort","capes","plate","folly","adobe","yours","papaw","hench","moods","clunk","chevy","tomas","narcs","vonda","wiles","prigs","chock","laser","viced","stiff","rouse","helps","knead","gazer","blade","tumid","avail","anger","egged","guide","goads","rabin","toddy","gulps","flank","brats","pedal","junky","marco","tinny","tires","flier","satin","darth","paley","gumbo","rared","muffs","rower","prude","frees","quays","homes","munch","beefs","leash","aston","colon","finch","bogey","leaps","tempo","posts","lined","gapes","locus","maori","nixes","liven","songs","opted","babel","wader","barer","farts","lisps","koran","lathe","trill","smirk","mamma","viler","scurf","ravel","brigs","cooky","sachs","fulls","goals","turfs","norse","hauls","cores","fairy","pluto","kneed","cheek","pangs","risen","czars","milne","cribs","genes","wefts","vents","sages","seres","owens","wiley","flume","haded","auger","tatty","onion","cater","wolfe","magic","bodes","gulls","gazes","dandy","snags","rowed","quell","spurn","shore","veldt","turns","slavs","coach","stalk","snuck","piles","orate","joyed","daily","crone","wager","solos","earns","stark","lauds","kasey","villa","gnaws","scent","wears","fains","laced","tamer","pipes","plant","lorie","rivet","tamed","cozen","theme","lifer","sunny","shags","flack","gassy","eased","jeeps","shire","fargo","timer","brash","behan","basin","volga","krone","swiss","docks","booed","ebert","gusty","delay","oared","grady","buick","curbs","crete","lucas","strum","besom","gorse","troth","donne","chink","faced","ahmed","texas","longs","aloud","bethe","cacao","hilda","eagle","karyn","harks","adder","verse","drays","cello","taped","snide","taxis","kinky","penes","wicca","sonja","aways","dyers","bolas","elfin","slope","lamps","hutch","lobed","baaed","masts","ashes","ionic","joyce","payed","brays","malts","dregs","leaky","runny","fecal","woven","hurls","jorge","henna","dolby","booty","brett","dykes","rural","fight","feels","flogs","brunt","preen","elvis","dopey","gripe","garry","gamma","fling","space","mange","storm","arron","hairs","rogue","repel","elgar","ruddy","cross","medan","loses","howdy","foams","piker","halts","jewel","avery","stool","cruel","cases","ruses","cathy","harem","flour","meted","faces","hobos","charm","jamar","cameo","crape","hooey","reefs","denny","mitts","sores","smoky","nopes","sooty","twirl","toads","vader","julep","licks","arias","wrote","north","bunks","heady","batch","snaps","claws","fouls","faded","beans","wimps","idled","pulse","goons","noose","vowed","ronda","rajas","roast","allah","punic","slows","hours","metal","slier","meaty","hanna","curvy","mussy","truth","troys","block","reels","print","miffs","busts","bytes","cream","otter","grads","siren","kilos","dross","batty","debts","sully","bares","baggy","hippy","berth","gorky","argon","wacko","harry","smoke","fails","perms","score","steps","unity","couch","kelly","rumps","fines","mouth","broth","knows","becky","quits","lauri","trust","grows","logos","apter","burrs","zincs","buyer","bayer","moose","overt","croon","ousts","lands","lithe","poach","jamel","waive","wiser","surly","works","paine","medal","glads","gybed","paint","lorre","meant","smugs","bryon","jinni","sever","viols","flubs","melts","heads","peals","aiken","named","teary","yalta","styes","heist","bongs","slops","pouts","grape","belie","cloak","rocks","scone","lydia","goofs","rents","drive","crony","orlon","narks","plays","blips","pence","march","alger","baste","acorn","billy","croce","boone","aaron","slobs","idyls","irwin","elves","stoat","doing","globe","verve","icons","trial","olsen","pecks","there","blame","tilde","milky","sells","tangy","wrack","fills","lofty","truce","quark","delia","stowe","marty","overs","putty","coral","swine","stats","swags","weans","spout","bulky","farsi","brest","gleam","beaks","coons","hater","peony","huffy","exert","clips","riven","payer","doped","salas","meyer","dryad","thuds","tilts","quilt","jetty","brood","gulch","corps","tunic","hubby","slang","wreck","purrs","punch","drags","chide","sulks","tints","huger","roped","dopes","booby","rosin","outer","gusto","tents","elude","brows","lease","ceres","laxer","worth","necks","races","corey","trait","stuns","soles","teems","scrip","privy","sight","minor","alisa","stray","spank","cress","nukes","rises","gusts","aurae","karma","icing","prose","biked","grand","grasp","skein","shaky","clump","rummy","stock","twain","zoned","offed","ghats","mover","randy","vault","craws","thees","salem","downy","sangs","chore","cited","grave","spinx","erica","raspy","dying","skips","clerk","paste","moved","rooks","intel","moses","avers","staid","yawls","blast","lyres","monks","gaits","floor","saner","waver","assam","infer","wands","bunch","dryly","weedy","honey","baths","leach","shorn","shows","dream","value","dooms","spiro","raped","shook","stead","moran","ditto","loots","tapir","looms","clove","stops","pinks","soppy","ripen","wench","shone","bauds","doric","leans","nadia","cries","camus","boozy","maris","fools","morns","bides","greek","gauss","roget","lamar","hazes","beefy","dupes","refed","felts","larry","guile","ables","wants","warns","toils","bathe","edger","paced","rinks","shoos","erich","whore","tiger","jumpy","lamas","stack","among","punts","scalp","alloy","solon","quite","comas","whole","parse","tries","reeve","tiled","deena","roomy","rodin","aster","twice","musts","globs","parch","drawn","filch","bonds","tells","droop","janis","holds","scant","lopes","based","keven","whiny","aspic","gains","franz","jerri","steel","rowel","vends","yelps","begin","logic","tress","sunni","going","barge","blood","burns","basks","waifs","bones","skill","hewer","burly","clime","eking","withs","capek","berta","cheap","films","scoot","tweed","sizer","wheat","acton","flung","ponds","tracy","fiver","berra","roger","mutes","burke","miked","valve","whisk","runes","parry","toots","japes","roars","rough","irons","romeo","cages","reeks","cigar","saiph","dully","hangs","chops","rolls","prick","acuff","spent","sulla","train","swell","frets","names","anita","crazy","sixth","blunt","fewer","large","brand","slick","spitz","rears","ogres","toffy","yolks","flock","gnawn","eries","blink","skier","feted","tones","snail","ether","barbs","noses","hears","upset","awash","cloud","trunk","degas","dungs","rated","shall","yeahs","coven","sands","susan","fable","gunny","began","serfs","balls","dinky","madge","prong","spilt","lilly","brawn","comet","spins","raids","dries","sorts","makes","mason","mayra","royce","stout","mealy","pagan","nasal","folds","libby","coups","photo","mosey","amens","speed","lords","board","fetal","lagos","scope","raked","bonus","mutts","willy","sport","bingo","thant","araby","bette","rebel","gases","small","humus","grosz","beset","slays","steve","scrap","blahs","south","pride","heels","tubes","beady","lacey","genus","mauls","vying","spice","sexes","ester","drams","today","comae","under","jests","direr","yoked","tempi","early","boats","jesus","warts","guppy","gilda","quota","token","edwin","ringo","gaped","lemon","hurst","manor","arrow","mists","prize","silas","blobs","diets","ervin","stony","buddy","bates","rabid","ducat","ewing","jaunt","beads","doyen","blush","thoth","tiles","piper","short","peron","alley","decks","shunt","whirs","cushy","roils","betty","plugs","woken","jibes","foray","merak","ruing","becks","whale","shoot","dwelt","spawn","fairs","dozed","celts","blond","tikes","sabin","feint","vamps","cokes","willa","slues","bills","force","curst","yokel","surer","miler","fices","arced","douse","hilly","lucio","tongs","togas","minty","sagas","pates","welsh","bruno","decal","elate","linux","gyros","pryor","mousy","pains","shake","spica","pupal","probe","mount","shirk","purus","kilns","rests","graze","hague","spuds","sweep","momma","burch","maces","samar","brace","riser","booms","build","camel","flyer","synge","sauna","tonga","tings","promo","hides","clair","elisa","bower","reins","diann","lubed","nulls","picks","laban","milch","buber","stomp","bosom","lying","haled","avert","wries","macon","skids","fumed","ogles","clods","antic","nosey","crimp","purge","mommy","cased","taxes","covet","clack","butch","panty","lents","machs","exude","tooth","adore","shuck","asses","after","terra","dices","aryan","regor","romes","stile","cairo","maura","flail","eaves","estes","sousa","visas","baron","civet","kitty","freed","ralph","tango","gawks","cheat","study","fancy","fiber","musks","souse","brims","claim","bikes","venue","sired","thymi","rivas","skimp","pleas","woman","gimpy","cawed","minos","pints","knock","poked","bowen","risky","towel","oinks","linus","heals","pears","codas","inner","pitch","harpy","niger","madly","bumpy","stair","files","nobel","celli","spars","jades","balmy","kooky","plums","trues","gloss","trims","daunt","tubby","dared","wadis","smell","darby","stink","drill","dover","ruler","laden","dikes","layla","fells","maker","joked","horns","these","baize","spahn","whens","edged","mushy","plume","tucks","spurs","husky","dried","bigot","pupas","drily","aware","hagar","newly","knots","pratt","feces","sabik","watts","cooke","riles","seamy","fleas","dusts","barfs","roans","pawns","vivid","kirks","tania","feral","tubae","horne","aries","brits","combs","chunk","stork","waned","texan","elide","glens","emery","autos","trams","dosed","cheri","baits","jacks","whose","fazed","matte","swans","maxed","write","spays","orion","traci","horse","stars","strut","goods","verge","scuff","award","dives","wires","burnt","dimly","sleds","mayan","biped","quirk","sofia","slabs","waste","robby","mayor","fatty","items","bowel","mires","swarm","route","swash","sooth","paved","steak","upend","sough","throw","perts","stave","carry","burgs","hilts","plane","toady","nadir","stick","foist","gnarl","spain","enter","sises","story","scarf","ryder","glums","nappy","sixes","honed","marcy","offer","kneel","leeds","lites","voter","vince","bursa","heave","roses","trees","argos","leann","grimy","zelma","crick","tract","flips","folks","smote","brier","moore","goose","baden","riled","looks","sober","tusks","house","acmes","lubes","chows","neath","vivas","defer","allay","casey","kmart","pests","proms","eying","cider","leave","shush","shots","karla","scorn","gifts","sneer","mercy","copes","faxed","spurt","monet","awoke","rocky","share","gores","drawl","tears","mooed","nones","wined","wrens","modem","beria","hovel","retch","mates","hands","stymy","peace","carat","coots","hotel","karen","hayed","mamet","cuing","paper","rages","suave","reuse","auden","costs","loner","rapes","hazel","rites","brent","pumps","dutch","puffs","noons","grams","teats","cease","honda","pricy","forgo","fleck","hired","silos","merge","rafts","halon","larks","deere","jello","cunts","sifts","boner","morin","mimes","bungs","marie","harts","snobs","sonic","hippo","comes","crops","mango","wrung","garbs","natty","cents","fitch","moldy","adams","sorta","coeds","gilds","kiddy","nervy","slurp","ramon","fuzed","hiker","winks","vanes","goody","hawks","crowd","bract","marla","limbs","solve","gloom","sloop","eaton","memos","tames","heirs","berms","wanes","faint","numbs","holes","grubs","rakes","waist","miser","stays","antis","marsh","skyed","payne","champ","jimmy","clues","fatal","shoed","freon","lopez","snowy","loins","stale","thank","reads","isles","grill","align","saxes","rubin","rigel","walls","beers","wispy","topic","alden","anton","ducts","david","duets","fries","oiled","waken","allot","swats","woozy","tuxes","inter","dunne","known","axles","graph","bumps","jerry","hitch","crews","lucia","banal","grope","valid","meres","thick","lofts","chaff","taker","glues","snubs","trawl","keels","liker","stand","harps","casks","nelly","debby","panes","dumps","norma","racks","scams","forte","dwell","dudes","hypos","sissy","swamp","faust","slake","maven","lowed","lilts","bobby","gorey","swear","nests","marci","palsy","siege","oozes","rates","stunt","herod","wilma","other","girts","conic","goner","peppy","class","sized","games","snell","newsy","amend","solis","duane","troop","linda","tails","woofs","scuds","shies","patti","stunk","acres","tevet","allen","carpi","meets","trend","salty","galls","crept","toner","panda","cohen","chase","james","bravo","styed","coals","oates","swami","staph","frisk","cares","cords","stems","razed","since","mopes","rices","junes","raged","liter","manes","rearm","naive","tyree","medic","laded","pearl","inset","graft","chair","votes","saver","cains","knobs","gamay","hunch","crags","olson","teams","surge","wests","boney","limos","ploys","algae","gaols","caked","molts","glops","tarot","wheal","cysts","husks","vaunt","beaus","fauns","jeers","mitty","stuff","shape","sears","buffy","maced","fazes","vegas","stamp","borer","gaged","shade","finds","frock","plods","skied","stump","ripes","chick","cones","fixed","coled","rodeo","basil","dazes","sting","surfs","mindy","creak","swung","cadge","franc","seven","sices","weest","unite","codex","trick","fusty","plaid","hills","truck","spiel","sleek","anons","pupae","chiba","hoops","trash","noted","boris","dough","shirt","cowls","seine","spool","miens","yummy","grade","proxy","hopes","girth","deter","dowry","aorta","paean","corms","giant","shank","where","means","years","vegan","derek","tales"};
    for (int i = 0; i < 4565; ++ i) {
        s.insert(dic[i]);
    }
    Solution4 so;
    dump( so.findLadders(start, end, s) );         
}

void test5() {
    string start = "nape", end = "mild";
    set<string> s;
    string dic[] = {"dose","ends","dine","jars","prow","soap","guns","hops","cray","hove","ella","hour","lens","jive","wiry","earl","mara","part","flue","putt","rory","bull","york","ruts","lily","vamp","bask","peer","boat","dens","lyre","jets","wide","rile","boos","down","path","onyx","mows","toke","soto","dork","nape","mans","loin","jots","male","sits","minn","sale","pets","hugo","woke","suds","rugs","vole","warp","mite","pews","lips","pals","nigh","sulk","vice","clod","iowa","gibe","shad","carl","huns","coot","sera","mils","rose","orly","ford","void","time","eloy","risk","veep","reps","dolt","hens","tray","melt","rung","rich","saga","lust","yews","rode","many","cods","rape","last","tile","nosy","take","nope","toni","bank","jock","jody","diss","nips","bake","lima","wore","kins","cult","hart","wuss","tale","sing","lake","bogy","wigs","kari","magi","bass","pent","tost","fops","bags","duns","will","tart","drug","gale","mold","disk","spay","hows","naps","puss","gina","kara","zorn","boll","cams","boas","rave","sets","lego","hays","judy","chap","live","bahs","ohio","nibs","cuts","pups","data","kate","rump","hews","mary","stow","fang","bolt","rues","mesh","mice","rise","rant","dune","jell","laws","jove","bode","sung","nils","vila","mode","hued","cell","fies","swat","wags","nate","wist","honk","goth","told","oise","wail","tels","sore","hunk","mate","luke","tore","bond","bast","vows","ripe","fond","benz","firs","zeds","wary","baas","wins","pair","tags","cost","woes","buns","lend","bops","code","eddy","siva","oops","toed","bale","hutu","jolt","rife","darn","tape","bold","cope","cake","wisp","vats","wave","hems","bill","cord","pert","type","kroc","ucla","albs","yoko","silt","pock","drub","puny","fads","mull","pray","mole","talc","east","slay","jamb","mill","dung","jack","lynx","nome","leos","lade","sana","tike","cali","toge","pled","mile","mass","leon","sloe","lube","kans","cory","burs","race","toss","mild","tops","maze","city","sadr","bays","poet","volt","laze","gold","zuni","shea","gags","fist","ping","pope","cora","yaks","cosy","foci","plan","colo","hume","yowl","craw","pied","toga","lobs","love","lode","duds","bled","juts","gabs","fink","rock","pant","wipe","pele","suez","nina","ring","okra","warm","lyle","gape","bead","lead","jane","oink","ware","zibo","inns","mope","hang","made","fobs","gamy","fort","peak","gill","dino","dina","tier"};
    for (int i = 0; i < 336; ++ i) {
        s.insert(dic[i]);
    }
    Solution4 so;
    dump( so.findLadders(start, end, s) );    
}

int main() {
    test1();
//    test2();
    test3();
    test5();
    return 0;
}


/*
This does not work yet.
The version using unordered_set:
    
class WW {
public:
    string w;
    WW * prev;
    WW(string _w, WW * p) : w(_w), prev(p) { }
};

class Solution {
public:
    vector<vector<string>> findLadders(string start, string end, unordered_set<string> &dict) {
        vector<vector<string>> ans;
        //if (start == end) return ans;
        
        queue<WW *> words;
        unordered_set<string> words_used, words_cur;
        int min_len = INT_MAX;
        
        words.push(new WW(start, NULL));
        words_cur.insert(start);
        
        while (words.size() > 0) {
            WW * z = words.front();
            words.pop();
            words_cur.erase(words_cur.find(z->w));
            words_used.insert(z->w);
            string w = z->w;
            
            int len = w.length();
            for (int i = 0; i < len; ++ i) {
                char c = w[i];
                for (int j = 0; j < 26; ++ j) {
                    if (c == 'a' + j) continue;
                    
                    w[i] = 'a' + j;
                    if (w == end) {
                        vector<string> a;
                        a.insert(a.begin(), end);

                        for (WW * x = z; x->prev; x = x->prev) {
                            a.insert(a.begin(), x->w);
                        }
                        a.insert(a.begin(), start);
                        
                        if (min_len >= a.size()) {
                            if (min_len > a.size()) {
                                ans.clear();
                                min_len = a.size();
                            }
                            ans.push_back(a);
                        }
                        break;
                    }
                    else {
                        if (dict.find(w) != dict.end() 
                            && words_used.find(w) == words_used.end() 
                            && words_cur.find(w) == words_cur.end() ) {
                            words.push(new WW(w, z));
                            words_cur.insert(w);
                        }
                    }
                    
                } // end of for
                w[i] = c;
            } // end of for
        }
        
        return ans;
    }
    
};
 */


/* 
Given two words (start and end), and a dictionary, find all shortest transformation sequence(s) from start to end, such that:

    Only one letter can be changed at a time
    Each intermediate word must exist in the dictionary

For example,

Given:
start = "hit"
end = "cog"
dict = ["hot","dot","dog","lot","log"]

Return

  [
    ["hit","hot","dot","dog","cog"],
    ["hit","hot","lot","log","cog"]
  ]

Note:

    All words have the same length.
    All words contain only lowercase alphabetic characters.
*/
