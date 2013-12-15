//
// Given a dictionary of words, compress like internationalization -> i18n.
// Also implement isUnique() method.
//
// @Author: Xin Chen
// @Created on: 3/21/2013
// @Last modified: 3/21/2013
//
#include <iostream>
#include <sstream>
#include <map>
#include <vector>
using namespace std;

class Dic {
    map<string, string> dic; // map from full word to abbreviation.
    map<string, vector<string> > dic_rev; // map from abbreviation to full word(s)
    Dic() {}
    
public:
    Dic(vector<string> words) {
        string abr;
        //char len[10];
        for (int i = 0; i < words.size(); ++ i) {
            string w = words[i];
            
            if (w.length() <= 2) {
                abr = w;
            }
            else {
                stringstream ss;
                ss << w.length() - 2;
                //sprintf(len, "%d", w.length() - 2);
                //abr = w[0] + len + w[w.length() - 1];
                abr = w[0] + ss.str() + w[w.length() - 1];
            }
            
            if (dic.find(w) == dic.end()) {
                dic[w] = abr;
                dic_rev[abr].push_back(w);
            }
        }
    }
    
    // Given full word, return abbreviation.
    // Note: if w does not exist in dic, return will be empty string "".
    string getAbr(string w) {
        return dic[w];
    }
    
    // Given abbreviation, return full word.
    vector<string> getFullWord(string abr) {
        return dic_rev[abr];
    }
    
    // Given full word, return whether it's abbreviation is unique in dic.
    // Note if w does not exist in dic, it's also regarded as unique.
    bool isUnique(string w) {
        return dic_rev[dic[w]].size() <= 1;
    }
    
    void dump() {
        for (map<string, string>::iterator it = dic.begin(); it != dic.end(); ++ it) {
            cout << (*it).first << " -> " << (*it).second << endl;
        }
        cout << endl;
    }
};

void test(Dic &d, string w) {
    string abr = d.getAbr(w);
    cout << "abr of " << w << " is: " << abr << endl;
    cout << "full word of " << abr << " can be: ";
    
    if (abr == "") {
        cout << endl;
        cout << "string " << w << " does not exist in dictionary" << endl << endl;
        return;
    }
    
    vector<string> ws = d.getFullWord(abr);
    for (int i = 0; i < ws.size(); ++ i) {
        cout << ws[i] << " ";
    }
    cout << endl;
    cout << w << "'s abr is unique: " << (d.isUnique(w) ? "true" : "false") << endl;    
    cout << endl;
}

int main() {
    string words[] = {"internationalization", "food", "tea", "food", "fold"};
    vector<string> wds;
    for (int i = 0; i < 5; ++ i) {
        wds.push_back(words[i]);
    }
    
    Dic d(wds);    
    d.dump();
    
    test(d, "food");
    test(d, "fod");    
    
    return 0;
}
