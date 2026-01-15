class Solution {
public:
    vector<string> ipToCIDR(string ip, int range) {
        vector<string> result;
        int curIp = ipToInt(ip);
        int count; // number of IP addresses to include in each step.

        while(range) {
            if (curIp == 0) { 
                count = 1;
                while (count * 2 <= range) count *= 2;
            }
            else { 
                count = curIp & -curIp; // get the least significant 1-bit (LSB)
                while (count > range) count /= 2; 
            }

            result.push_back(numberToIp(curIp, count));
            range -= count;
            curIp += count;
        }

        return result;
    }

    unsigned int ipToInt(string ip) {
        unsigned int result = 0;

        stringstream ss(ip);
        string out;
        while (getline(ss, out, '.')) {
            result = (result << 8) + stoi(out);
        }

        return result;
    }

    string numberToIp(unsigned int ip, int count) {
        string ans = to_string(ip>>24) + "." +
                     to_string(ip>>16 & 255) + "." +
                     to_string(ip>>8 & 255)  + "." +
                     to_string(ip & 255);

        int maskLen = 33;
        for (; count > 0; count /= 2) {
            maskLen --;
        }

        return ans + "/" + to_string(maskLen);
    }
};
