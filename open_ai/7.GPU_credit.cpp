//
// Stores credits using a priority_queue so items that will expire first stay at the top.
//
#include <iostream>
#include <ctime>

using namespace std;

typedef function<bool(vector<int>&, vector<int>&)> Comp;

class GpuCredit {
    priority_queue<vector<int>, vector<vector<int>>, Comp> minHeap;
public:
    GpuCredit() {
        Comp comp = [&](vector<int>& a, vector<int>& b) {
            return a[0] > b[0];
        };
        minHeap = priority_queue<vector<int>, vector<vector<int>>, Comp>(comp);
    }

    void add(int timestamp_sec, int expire_duration_sec, int credit) {
        cout << "=> add (" << timestamp_sec << ", " << expire_duration_sec << ", " << credit << ")" << endl;
        minHeap.push({timestamp_sec + expire_duration_sec, timestamp_sec, credit});
    }

    bool cost(int timestamp_sec, int credit) {
        cout << "=> cost (" << timestamp_sec << ", " << credit << ")" << endl;
        removeExpiredCredit(timestamp_sec);

        if (! checkIsSufficient(timestamp_sec, credit)) {
            cout << "Not sufficient balance" << endl;
            return false;
        }

        while (! minHeap.empty()) {
            vector<int> cur = minHeap.top();
            minHeap.pop();

            if (cur[0] <= timestamp_sec) {
                continue; // expired.
            }

            if (credit >= cur[2]) {
                credit -= cur[2];
            } else {
                cur[2] -= credit;
                minHeap.push(cur);
                break;
            }
        } 

        return true;
    }

    bool checkIsSufficient(int timestamp_sec, int credit) {
        int balance = 0;
        auto copy = minHeap;
        while (! copy.empty()) {
            vector<int> cur = copy.top();
            copy.pop();

            if (cur[0] <= timestamp_sec) continue; // expired.
            balance += cur[2];
        } 
        return balance >= credit;
    }

    void dump(int timestamp_sec) {
        cout << "=> dump (" << timestamp_sec << ")" << endl;
        auto copy = minHeap;
        while (! copy.empty()) {
            vector<int> cur = copy.top();
            copy.pop();

            if (cur[0] <= timestamp_sec) {
                cout << "exp: " << cur[0] << ", timestamp: " << cur[1] << ", credit: " << cur[2] << " [expired] " << endl;
            } else {
                cout << "exp: " << cur[0] << ", timestamp: " << cur[1] << ", credit: " << cur[2] << endl;
            }
        }
        cout << endl;
    }

    void removeExpiredCredit(int timestamp_sec) {
        while (! minHeap.empty()) {
            vector<int> cur = minHeap.top();

            if (cur[0] <= timestamp_sec) {
                minHeap.pop();
                cout << "exp: " << cur[0] << ", timestamp: " << cur[1] << ", credit: " << cur[2] << " [expired => removed] " << endl;
                continue; // expired.
            } else {
                break;
            }
        }
    }
};

class GpuCreditTest {
public:
    void test_real_time() {
        int t = time(NULL);
        cout << "epock: " << t << endl;       // 1766727893
        cout << "maxint:" << INT_MAX << endl; // 2147483647
    }

    void test() {
        GpuCredit gpuCredit;
        gpuCredit.add(100, 10, 50);
        gpuCredit.dump(105);
        gpuCredit.add(200, 20, 50);
        gpuCredit.dump(200);

        gpuCredit.cost(200, 30);
        gpuCredit.dump(200);
        
        gpuCredit.dump(220);
    }
};

int main() {
    GpuCreditTest gpuTest;
    gpuTest.test();
    return 0;
}


/**
Operations:
Add credit: At time t, add x credits, which will expire at time t_expire.
Expire credit: Credits added earlier should automatically expire when their expiration time is reached.
Cost: At time t, deduct x credits if available. If insufficient credits exist at that time, return False.

Requirements:
Maintain all events (add, expire, cost) in chronological order.

When processing a cost event:
First check if the current balance is sufficient.
If not, return False.
If yes, deduct credits by adjusting the future expire entries accordingly (consume the oldest credits first).

The system should support multiple adds, expires, and costs interleaved at different timestamps.

Example:
Add(10, 5, expire=20)   # at timestamp=10, add 5 credits, which expire at 20
Cost(15, 3)             # at timestamp=15, consume 3 credits → valid
After this operation, the future expire at (20, 5) should be updated to (20, 2).
 */
