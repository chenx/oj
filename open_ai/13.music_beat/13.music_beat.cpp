// 7:50 - 8:42

#include <iostream>
#include <vector>
#include <set>

using namespace std;

class Music {
public:
    string combineBeats(vector<string> instruments, vector<vector<int>>& beats) {
        string result;
        int TotalBeats = beats[0].size(), K = instruments.size();

        int beatsSoFar = 0;
        bool hasOne = false;
        set<string> names;
        for (int i = 0; i < TotalBeats; ++ i) {
            // cout << "beat: " << i << endl;
            hasOne = false;
            set<string> curBeatNames;
            for (int j = 0; j < K; ++ j) {
                if (beats[j][i] == 1) {
                    hasOne = true;
                    curBeatNames.insert(instruments[j]);
                }
            }

            if (hasOne && beatsSoFar > 0) { // output the previous segment with 1.
                string nameStr = join(names);

                if (result != "") result += " ";
                // result += nameStr + to_string(TotalBeats / beatsSoFar);
                result += nameStr + writeBeat(TotalBeats, beatsSoFar);
        
                beatsSoFar = 1;
                names = curBeatNames;
            } else {
                beatsSoFar += 1;
                for (auto ins : curBeatNames) {
                    if (! names.count(ins)) names.insert(ins);
                }
            }
        }

        if (! names.empty()) { // output the last segment.
            string nameStr = join(names);
            if (result != "") result += " ";
            // result += nameStr + to_string(TotalBeats / beatsSoFar);
            result += nameStr + writeBeat(TotalBeats, beatsSoFar);

            beatsSoFar = 0;
            hasOne = false;
            names.clear();
        }

        return result;
    }

private:
    string writeBeat(int TotalBeats, int beatsSoFar) {
        if (TotalBeats % beatsSoFar == 0) return to_string(TotalBeats / beatsSoFar);
        else return to_string(beatsSoFar) + "/" + to_string(TotalBeats);
    }
    string join(set<string>& vec) {
        string result = "";
        for (auto v : vec) {
            if (result != "") result += ",";
            result += v;
        }
        if (vec.size() > 1) return "<" + result + ">";
        return result;
    }
};

class MusicTest {
    void assert(string result, string expect) {
        if (result == expect) {
            cout << "Pass: result = " << result << endl;
        } else {
            cout << "Fail: result = " << result << ", expect = " << expect << endl;
        }
    }

    void test1() {
        Music music;
        vector<string> instruments = {"a", "b"};
        vector<vector<int>> beats = {
            {1, 0, 1, 1},
            {0, 0, 1, 0},
        };
        string result = music.combineBeats(instruments, beats);
        assert(result, "a2 <a,b>4 a4");
    }

    void test2() {
        Music music;
        vector<string> instruments = {"a"};
        vector<vector<int>> beats = {
            {1, 0, 1, 1, 0, 0, 0, 1},
        };
        string result = music.combineBeats(instruments, beats);
        assert(result, "a4 a8 a2 a8");
    }

    void test3() {
        Music music;
        vector<string> instruments = {"a"};
        vector<vector<int>> beats = {
            {1, 0, 0, 1, 0, 0, 0, 1},
        };
        string result = music.combineBeats(instruments, beats);
        assert(result, "a3/8 a2 a8");
    }
public:
    void run_tests() {
        test1();
        test2();
        test3();
    }
};

int main() {
    MusicTest test;
    test.run_tests();
    return 0;
}
