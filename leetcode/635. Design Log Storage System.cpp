// Not working yet. 34 / 65 testcases passed. 
class LogSystem {
    map<int, int> timeIdMap;
    map<string, int> granularityMap = {
        {"Year", 5}, {"Month", 4}, {"Day", 3}, {"Hour", 2}, {"Minute", 1}, {"Second", 0}, };
public:
    LogSystem() {
    }

    // int getEpochTime(string time) {
    int getEpochTime(vector<int> tokens) {
        // vector<int> tokens = split(time);
        struct tm t = {}; // Initialize to zero
        t.tm_year = tokens[0] - 1900; // Years since 1900
        t.tm_mon = tokens[1] - 1;       // Months 0-11
        t.tm_mday = tokens[2];          // Day of month
        t.tm_hour = tokens[3];
        t.tm_min = tokens[4];
        t.tm_sec = tokens[5];
        // t.tm_isdst = -1;         // Let system decide DST

        std::time_t timestamp = std::mktime(&t); // 1735122615
        // cout << "timestamp: " << timestamp << endl;
        // std::cout << std::ctime(&timestamp); // Wed Dec 25 10:30:15 2024
        return timestamp;
    }

    vector<int> split(string& s) {
        vector<int> tokens;
        stringstream ss(s);
        string out;
        while (getline(ss, out, ':')) {
            tokens.push_back(stoi(out));
        }
        return tokens;
    }
    
    void put(int id, string timestamp) {
        cout << "put: id = " << id << ", timestamp = " << getEpochTime(split(timestamp)) << endl;
        timeIdMap[getEpochTime(split(timestamp))] = id;
    }
    
    vector<int> retrieve(string start, string end, string granularity) {
        cout << "retrieve: start = " << start << ", end = " << end << ", granularity = " << granularity << endl;
        vector<int> result;
        vector<int> startTime = split(start);
        vector<int> endTime = split(end);

        int index = granularityMap[granularity];
        for (int i = 0; i < index; ++ i) {
            startTime[5-i] = 0;
            endTime[5-i] = 0;
        }
        endTime[5 - index] ++;
        cout << "granularity: " << granularity << endl;
        printVec(startTime, "startTimeVector");
        printVec(endTime, "endTimeVector");

        int startTimeValue = getEpochTime(startTime);
        int endTimeValue = getEpochTime(endTime);

        // lower_bound: 1st e k >= startTimeValue
        // upper_bound: 1st e k > endTimeValue
        auto startIt = timeIdMap.lower_bound(startTimeValue);
        auto endIt = timeIdMap.lower_bound(endTimeValue);
        // if (startIt == timeIdMap.rend()) startIt = timeIdMap.begin();
        // if (endIt == timeIdMap.end()) endIt --;
        // if (endIt->first != endTimeValue) -- endIt;
 
        // cout << "start Index: " << startIt->second << endl;
        // cout << "end Index: " << endIt->second << endl;
        // if (endIt != timeIdMap.end()) ++ endIt;

        for (auto it = startIt; it != endIt; ++ it) {
            result.push_back(it->second);
        }

        return result;
    }

    void printVec(vector<int>& v, string name) {
        cout << name << ": ";
        for (int i : v) cout << i << ",";
        cout << endl;
    }
};

/**
 * Your LogSystem object will be instantiated and called as such:
 * LogSystem* obj = new LogSystem();
 * obj->put(id,timestamp);
 * vector<int> param_2 = obj->retrieve(start,end,granularity);
 */


/**
635. Design Log Storage System
Attempted
Medium
Topics
conpanies iconCompanies

You are given several logs, where each log contains a unique ID and timestamp. Timestamp is a string that 
has the following format: Year:Month:Day:Hour:Minute:Second, for example, 2017:01:01:23:59:59. All domains 
are zero-padded decimal numbers.

Implement the LogSystem class:

    LogSystem() Initializes the LogSystem object.
    void put(int id, string timestamp) Stores the given log (id, timestamp) in your storage system.
    int[] retrieve(string start, string end, string granularity) Returns the IDs of the logs whose timestamps 
are within the range from start to end inclusive. start and end all have the same format as timestamp, and 
granularity means how precise the range should be (i.e. to the exact Day, Minute, etc.). For example, 
start = "2017:01:01:23:59:59", end = "2017:01:02:23:59:59", and granularity = "Day" means that we need to 
find the logs within the inclusive range from Jan. 1st 2017 to Jan. 2nd 2017, and the Hour, Minute, and 
Second for each log entry can be ignored.

 

Example 1:

Input
["LogSystem", "put", "put", "put", "retrieve", "retrieve"]
[[], [1, "2017:01:01:23:59:59"], [2, "2017:01:01:22:59:59"], [3, "2016:01:01:00:00:00"], 
["2016:01:01:01:01:01", "2017:01:01:23:00:00", "Year"], ["2016:01:01:01:01:01", "2017:01:01:23:00:00", "Hour"]]
Output
[null, null, null, null, [3, 2, 1], [2, 1]]
 */
