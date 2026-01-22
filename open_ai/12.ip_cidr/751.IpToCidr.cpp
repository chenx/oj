class Solution {
public:
    vector<string> ipToCIDR(string ip, int n) {
        vector<string> result;
        unsigned int curIp = converIpToInt(ip);
        int count; // number of IP addresses to include in each step.

        while (n > 0) {
            if (curIp == 0) {
                count = 1;
                while (count * 2 <= n) count *= 2;
            } else {
                count = curIp & -curIp; // get last 1-bit.
                while (count > n) count /= 2;
            }
            result.push_back(getCidr(curIp, count));
            curIp += count;
            n -= count;
        }
        return result;
    }

    string getCidr(unsigned int curIp, int count) {
        string ip = to_string((curIp >> 24) & 255) + "."
                    + to_string((curIp >> 16) & 255) + "."
                    + to_string((curIp >> 8) & 255) + "."
                    + to_string(curIp & 255);
        
        int maskLen = 33;
        for (; count > 0; count /= 2) maskLen --;

        return ip + "/" + to_string(maskLen);
    }

    unsigned int converIpToInt(string& ip) {
        stringstream ss(ip);
        string out;
        unsigned int result = 0;
        while(getline(ss, out, '.')) {
            result = (result << 8) + stoi(out);
        }
        return result;
    }
};
