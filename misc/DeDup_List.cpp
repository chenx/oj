/**
 * Given 1 million email list:
 *
 * list 1: a@a.com, b@b.com
 * list 2: b@b.com, c@c.com
 * list 3: e@e.com
 * list 4: a@a.com
 * ...
 *
 * Combine lists with identical emails, and output tuples:
 *
 * (list 1, list 2, list 4) (a@a.com, b@b.com, c@c.com)
 * (list 3) (e@e.com)
 *
 * Solution:
   - getTuples() {
         T := ();
         while (! IDList.empty()) {
             t = ((), ()); // ((id list), (email list))
             G1(IDs, EMs, t, IDs.begin);
             T.add(t);
         }
     }

   - G1(IDs, EMs, t, id) {
         add id to t.first;
         IDs_id = IDs[id];
         remove id from IDs;
         foreach (em in IDs[id]) {
             if (em not in t.second()) {
                 G2(IDs, EMs, t, em);
             }
         }
     }

   - G2(IDs, EMs, t, em) {
         add em to t.second;
         EMs_s = EMs[em];
         remove em from EMs;
         foreach (id in EMs[em]) {
             if (id not in t.first()) {
                 G1(IDs, EMs, t, id);
             }
         }
     }
     
   For example: input is:
   1: a b
   2: b c
   3: d
   4: c d
   5: e f
   
   first we get the reverse list:
   a: 1
   b: 1 2
   c: 2 4
   d: 3 4
   e: 5
   f: 5
   
   then the cycle is:
   1 -> a -> (1) stop 
        b -> (1) stop
             2 -> (b) stop
                  c -> (2) stop
                       4 -> (c) stop
                            d -> 3 -> (d) stop
                              -> (4) stop
   In the end, output is:
   (1, 2) (a, b, c, d)
   (5) (e, f)
 *
 * Solution by: X.C. On 2/26/2015. (FB)
 */

#include <iostream>
#include <vector>
#include <map>
using namespace std;


// This works for test1().
class Solution {
public:
    void dumpTuples(vector<pair<vector<int>, vector<string> > > & T) {
        cout << "==============" << endl;
        for (int i = 0; i < T.size(); ++ i) {
            vector<int> & ids = T[i].first;
            cout << "("; 
            for (int j = 0; j < ids.size(); ++ j) {
                if (j > 0) cout << ", ";
                cout << ids[j];
            }
            cout << ") ";
            
            vector<string> & ems = T[i].second;
            cout << "("; 
            for (int j = 0; j < ems.size(); ++ j) {
                if (j > 0) cout << ", ";
                cout << ems[j];
            }
            cout << ") " << endl;
        }
    }
    
    static void dumpMap(map<string, vector<int> > &m) {
        cout << "--------------" << endl;
        for (map<string, vector<int> >::iterator it = m.begin(); it != m.end(); ++ it) {
            cout << "(" << (*it).first << ") (";
            for (int i = 0; i < (*it).second.size(); ++ i) {
                if (i > 0) cout << ", ";
                cout << (*it).second[i];
            }
            cout << ")" << endl;
        }
    }
    
    static void dumpMap(map<int, vector<string> >  &m) {
        cout << "--------------" << endl;
        for (map<int, vector<string> >::iterator it = m.begin(); it != m.end(); ++ it) {
            cout << "(" << (*it).first << ") (";
            for (int i = 0; i < (*it).second.size(); ++ i) {
                if (i > 0) cout << ", ";
                cout << (*it).second[i];
            }
            cout << ")" << endl;
        }
    }

    
    void G1(map<int, vector<string> > & IDList, map<string, vector<int> > & EMList,
            pair<vector<int>, vector<string> > & tuple, int id) {
        //cout << "G1(" << id << ")" << endl;
        tuple.first.push_back(id);
        vector<string> ems = IDList[id];
        IDList.erase( IDList.find(id) );
        //dumpMap(IDList);
        
        for (int i = 0; i < ems.size(); ++ i) {
            if (find(tuple.second.begin(), tuple.second.end(), ems[i]) == tuple.second.end()) {
                G2(IDList, EMList, tuple, ems[i]);
            }
        }
    }
    
    void G2(map<int, vector<string> > & IDList, map<string, vector<int> > & EMList,
            pair<vector<int>, vector<string> > & tuple, string em) {
        //cout << "G2(" << em << ")" << endl;
        tuple.second.push_back(em);
        vector<int> ids = EMList[em]; 
        EMList.erase( EMList.find(em) );
        
        for (int i = 0; i < ids.size(); ++ i) {
            if (find(tuple.first.begin(), tuple.first.end(), ids[i]) == tuple.first.end()) {
                G1(IDList, EMList, tuple, ids[i]);
            }
        }
    }

public:
    vector<pair<vector<int>, vector<string> > > getTuples(map<int, vector<string> > & IDList) {
        vector<pair<vector<int>, vector<string> > > ans;
        map<string, vector<int> > EMList;
        
        for (map<int, vector<string> >::iterator it = IDList.begin(); it != IDList.end(); ++ it) {
            int id = (*it).first; 
            vector<string> & em = (*it).second;
            for (int i = 0; i < em.size(); ++ i) {
                EMList[em[i]].push_back(id);
            }
        }
        dumpMap(EMList);
        
        while (! IDList.empty()) {
            pair<vector<int>, vector<string> > tuple;
            G1(IDList, EMList, tuple, (*IDList.begin()).first);
            ans.push_back(tuple);
        }
        dumpTuples(ans);
        
        return ans;
    }
};


// Assign array to vector.
void assign(vector<string> &v, string a[], int n) {
    for (int i = 0; i < n; ++ i) v.push_back(a[i]);
}

/**
 * Expected result for test1():
 * (1, 2, 5, 4) (a, b, c, f)
 * (3, 6) (e, g)
 */
void test1() {
    map<int, vector<string> > m;

    string a[] = {"a", "b"};
    assign(m[1], a, 2);

    string a2[] = {"b", "c"};
    assign(m[2], a2, 2);

    string a3[] = {"e"};
    assign(m[3], a3, 1);

    string a4[] = {"f"};
    assign(m[4], a4, 1);

    string a5[] = {"c", "f"};
    assign(m[5], a5, 2);

    string a6[] = {"g", "e"};
    assign(m[6], a6, 2);

    Solution::dumpMap(m);

    Solution so;
    so.getTuples(m);
}

int main() {
    test1();
    return 0;
}
