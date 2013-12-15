#include <iostream>
#include <map>
#include <vector>
using namespace std;

typedef int JobID;


//
// timeout for large test case.
//
bool jobSchedule(const map<JobID, vector<JobID> > &deps, int n,
                                   vector<JobID> &result) {
    if (deps.size() == 0) {
        for (int i = 1; i <= n; ++ i) result[i-1] = i;
        return true;
    }
    
    map<JobID, vector<JobID> > d = deps;
    
//return true;
    
    int k = 0;
    vector<JobID> v(n);
    for (int i = 0; i < n; ++ i) { v[i] = i+1; }
    
    while (1) {
        int get = 0;
        
        for (int i = 0; i < n; ++ i) {
            cout << "i = " << i << endl;
            
            if (find(result.begin(), result.end(), v[i]) != result.end())
                continue;
            
            if (d[v[i]].size() == 0) { // in degree is 0, insert
                cout << "i = " << v[i] << ", k = " << k << endl;
                get = 1;
                result[k ++] = v[i];
                
                // remove v[i] from in-degree of other elements.
                for (map<JobID, vector<JobID> >::iterator it = d.begin();
                     it != d.end(); ++ it) {
                    vector<JobID> &w = (*it).second;
                    vector<int>::iterator wit = find(w.begin(), w.end(), v[i]);
                    if (wit != w.end()) {
                        w.erase( find(w.begin(), w.end(), v[i]) );
                    }
                }
            }
        }
        if (k == n) return true;
        if (0 == get) return false;
    }

}


//
// does not work.
//
bool jobSchedule2(const map<JobID, vector<JobID> > &deps, int n,
                                   vector<JobID> &result) {
    
    map<JobID, int> ct; // number of times JobID occur as source
    
    map<JobID, vector<JobID> > d = deps;
    
    for (map<JobID, vector<JobID> >::iterator it = d.begin();
         it != d.end(); ++ it) {
        vector<JobID> &v = (*it).second;
        for (int i = 0; i < v.size(); ++ i) {
            ++ ct[v[i]]; // get in-degree.
        }        
    }

    int k = 0;
    
    while (1) {
        int get = 0;
        for (map<JobID, vector<JobID> >::iterator it = d.begin(); 
             it != d.end(); ++ it) {
            //cout << "i = " << (*it).first << endl;
            if (ct[(*it).first] == 0) {
                get = 1;
                result[k++] = (*it).first; // get nodes whose in-degree is 0.
                
                vector<JobID> &v = (*it).second;
                for (int i = 0; i < v.size(); ++ i) {
                    -- ct[v[i]]; // decrease in-degree of its successors.
                }
            }
        }
        if (k == n) return true;
        else if (0 == get) return false;
    }

}

void test1() {
    int n = 1;
    map<JobID, vector<JobID> > deps;
    vector<JobID> result(n);
    cout << jobSchedule(deps, n, result) << endl;     
}

void test2() {
    int n = 5;
    map<JobID, vector<JobID> > deps;
    vector<JobID> result(n);
    result[0] = 10;
    result[1] = 11;
    
    deps[4].push_back(5);
//    deps[2].push_back(1);
        
    cout << jobSchedule(deps, n, result) << endl;     
    
    for (int i = 0; i < n; ++ i) {
        cout << result[i] << " ";
    }
    cout << endl;
}


int main() {
    test1();
    test2();
    return 0;
}
