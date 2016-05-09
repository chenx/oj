//
// Report a value counter in the past hour/minute/second.
// The set(value) method can be called multiple times per second.
//
// Two approaches are given below:
// 1) use a circular array.
// 2) use a deque. 
// Method 2 seems simpler. 
// Method 2 is also more general, if time granularity is smaller than 1 second.
//
// @by: X.C.
// @on: 5/8/2016
//

#include <iostream>
#include <vector>
#include <ctime>
#include <unistd.h>
#include <queue>
using namespace std;


class Solution2 {
    deque<pair<int, long> > val; // (value, time_stamp)
    long last_set_time;
public:
    Solution2() {
        last_set_time = current_time();
    }

    // Note: new items are added to front(). So in report_last_k(),
    // going from begin() to end() is going to new to old.
    // i.e., in deque, begin() is front(), end() is back().
    void set(int value) {
        long t = current_time();
        if (val.empty() || t > last_set_time) {
            val.push_front(pair<int, long>(value, t));
        }
        else { // val is not empty, and t == last_set_time.
            val.front().first += value;
        }

        while (! val.empty() && val.back().second - t >= 3600) {
            val.pop_back();
        }

        last_set_time = t;
    }

    double report_second() {
        return report_last_k(1); // this is incorrect. why?
        long t = current_time();
        if (t == last_set_time) return val.back().first;
        else return 0;
    }

    double report_minute() {
        return report_last_k(60);
    }

    double report_hour() {
        return report_last_k(3600);
    }

    // report average of last k seconds;
    double report_last_k(int k) {
        if (k <= 0) return 0;

        long t = current_time();
        int sum = 0;
        for (deque<pair<int, long> >::iterator it = val.begin(); it != val.end(); ++ it) {
            if (t - it->second >= k) {  // note: >=
                //cout << t << " - " << it->second << " >= " << k << ". break\n"; 
                break; 
            }
            sum += it->first;
        }
        return (double) sum / k;
    }

    long current_time() {
        time_t timer = time(NULL);
        return timer;
    }

    void dump() {
        cout << "last_set_time: " << last_set_time << endl;
        cout << "report_second: " << report_second() << endl;
        cout << "report_minute: " << report_minute() << endl;
        cout << "report_hour:   " << report_hour() << endl;

        for (deque<pair<int, long> >::iterator it = val.begin(); it != val.end(); ++ it) {
            cout << it->second << ": " << it->first << endl;
        }
    }
};

class Solution {
    long last_set_time;
    int SIZE;
    vector<int> val;

    void clear(long time) {
        int time_elapsed = time - last_set_time;
        if (time_elapsed >= SIZE) {
            fill(val.begin(), val.end(), 0);
        }
        else {
            int pre = (1 + last_set_time) % SIZE,  // note: 1 + last_set_time
                cur = time % SIZE;
            if (pre <= cur)  // note: <=
                fill(val.begin() + pre, val.begin() + cur, 0);
            else {
                fill(val.begin(), val.begin() + cur, 0);
                fill(val.begin() + pre, val.end(), 0);
            }
        }
    }
public:
    Solution() {
        last_set_time = current_time();
        SIZE = 3600;
        val.resize(SIZE, 0);
    }

    void set(int value) {
        set(current_time(), value);
    }

    void set(long time, int value) {
        if (time == last_set_time) {
            val[time % SIZE] += value;
        }
        else {
            clear(time);
            val[time % SIZE] = value;
        }
        last_set_time = time;
    }

    double report_second() {
        long t = current_time();
        set(t, 0);
        return val[t % SIZE];
    }

    double report_minute() {
        long t = current_time();
        set(t, 0);
        
        int sum = 0, cur = t % SIZE, ct = 60;
        for (; cur >= 0 && ct > 0; -- cur, -- ct) {
            sum += val[cur];
        }
        // assume SIZE >= 60.
        if (ct > 0) {
            for (cur = SIZE - 1; ct > 0; -- cur, -- ct) {
                sum += val[cur];
            }
        }

        return (double) sum / 60;
    }

    double report_hour() {
        set(current_time(), 0);
        int sum = 0;
        // assume SIZE >= 3600.
        for (int i = 0; i < 3600; ++ i) {
            sum += val[i];
        }
        return (double) sum / SIZE;
    }

    long current_time() {
        time_t timer = time(NULL);
        return timer;
    }

    void dump() {
        cout << "last_set_time: " << last_set_time << endl;
        cout << "report_second: " << report_second() << endl;
        cout << "report_minute: " << report_minute() << endl;
        cout << "report_hour:   " << report_hour() << endl;

        for (int i = 0; i < SIZE; ++ i) {
            if (val[i] != 0) {
                cout << (i+1) << ": " << val[i] << endl;
            }
        }
    }
};



void test(int vals[], double sleeps[], int len) {
    cout << "==== Solution ====" << endl;
    Solution so;
    for (int i = 0; i < len; ++ i) {
        so.set(vals[i]);
        so.dump();
        cout << "... now sleep " << sleeps[i] << " seconds" << endl << endl;
        usleep(sleeps[i] * 1000000);
    }

    cout << "==== Solution 2 ====" << endl;
    Solution2 s2;
    for (int i = 0; i < len; ++ i) {
        s2.set(vals[i]);
        s2.dump();
        cout << "... now sleep " << sleeps[i] << " seconds" << endl << endl;
        usleep(sleeps[i] * 1000000);
    }
}

void test1() {
    int vals[] = {60, 60, 30, 30};
    double sleeps[] = {0.1, 1, 2, 0.5};
    int len = sizeof(vals) / sizeof(int);

    test(vals, sleeps, len);
/*
    // http://www.cplusplus.com/reference/climits/
    cout << INT_MAX << endl;    // 2147483647
    cout << LONG_MAX << endl;   // 9223372036854775807
    cout << LLONG_MAX << endl;  // 9223372036854775807
    cout << ULLONG_MAX << endl; // 18446744073709551615
*/
}

int main() {
    test1();
    return 0;
}


/**
Output:

==== Solution ====
last_set_time: 1462771839
report_second: 60
report_minute: 1
report_hour:   0.0166667
1840: 60
... now sleep 0.1 seconds

last_set_time: 1462771839
report_second: 120
report_minute: 2
report_hour:   0.0333333
1840: 120
... now sleep 1 seconds

last_set_time: 1462771840
report_second: 30
report_minute: 2.5
report_hour:   0.0416667
1840: 120
1841: 30
... now sleep 2 seconds

last_set_time: 1462771842
report_second: 30
report_minute: 3
report_hour:   0.05
1840: 120
1841: 30
1843: 30
... now sleep 0.5 seconds


==== Solution 2 ====
last_set_time: 1462771843
report_second: 60
report_minute: 1
report_hour:   0.0166667
1462771843: 60
... now sleep 0.1 seconds

last_set_time: 1462771843
report_second: 120
report_minute: 2
report_hour:   0.0333333
1462771843: 120
... now sleep 1 seconds

last_set_time: 1462771844
report_second: 30
report_minute: 2.5
report_hour:   0.0416667
1462771844: 30
1462771843: 120
... now sleep 2 seconds

last_set_time: 1462771846
report_second: 30
report_minute: 3
report_hour:   0.05
1462771846: 30
1462771844: 30
1462771843: 120
... now sleep 0.5 seconds

 */
