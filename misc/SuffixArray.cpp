//
// @By: Xin Chen
// @Created On: 6/26/2013
// @Last modified: 6/26/2013
//
// See: http://en.wikipedia.org/wiki/Suffix_array
//

#include <vector>
#include <iostream>
using namespace std;


bool cmp(const pair<int, char *> &a, const pair<int, char *> &b) {
    //cout << " compare: " << a.second << ", " << b.second << endl;
    return strcmp(a.second, b.second) < 0;
}

void dumpVec(vector<pair<int, char *> > & v) {
    for (int i = 0; i < v.size(); ++ i) {
        cout << "{" << v[i].first << " " << v[i].second << "}" << endl;
    }     
    cout << endl;
}

//
// The function to build a suffix array, given input string s.
// @parameters:
//  - char * s : input string.
//  - int *& a : pointer to the suffix array to build. To return.
//
void buildSA(char * s, int *& sa) {
    if (! s) {
        sa = NULL;
        return;
    }
    
    int len = strlen(s) + 1;
    
    vector<pair<int, char *> > v;
    for (int i = 0; i < len; ++ i) {
        v.push_back(pair<int, char *>(i+1, s+i));
    }

    //dumpVec(v);
    sort(v.begin(), v.end(), cmp);
    dumpVec(v);
    
    sa = new int[len];
    for (int i = 0; i < len; ++ i) {
        sa[i] = v[i].first;
    }
 }

void dumpSA(int * sa, int len) {
    if (sa == NULL) {
        cout << "suffix array is empty" << endl;
        return;
    }
    
    cout << "suffix array (len = " << len << "): ";
    for (int i = 0; i < len; ++ i) {
        cout << sa[i] << " ";
    }
    cout << endl;
}

int main() {
    char * s = "banana";
    int * a = NULL;
    int len = strlen(s)+1;
    
    buildSA(s, a);
    dumpSA(a, len);
    
    return 0;
}
