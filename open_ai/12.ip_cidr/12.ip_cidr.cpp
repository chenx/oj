#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

class CIDR {
public:
    unsigned int getIpIntValue(string& ip) {
        stringstream ss(ip);
        string out;
        unsigned int intIp = 0;
        while (getline(ss, out, '.')) {
            intIp = (intIp << 8) + stoi(out);
        }
        return intIp;
    }

    string getIpStringValue(unsigned int intIp) {
        return to_string(intIp >> 24) + "." +
                    to_string((intIp >> 16) & 255) + "." +
                    to_string((intIp >> 8) & 255) + "." +
                    to_string(intIp & 255);
    }

    void iteratorInc(string ip) {
        // (1 << 31) - 1: 2'147'483'647, 127.255.255.255, INT_MAX
        // (1 << 32) - 1: 4'294'967'295, 255.255.255.255, ~0
        // long long x = ((long long) 1 << 32) - 1;
        // cout << "INT_MAX = " << INT_MAX << ", ?= " << x  << endl;

        // MAX_IP = 4294967295. If type of MAX_IP is long long, it'll be -1.
        unsigned int MAX_IP = ~0;
        cout << "MAX_IP = " << MAX_IP << ", " << getIpStringValue(MAX_IP) << endl;

        // Type of i must be long long. Type of ipInt must be unsiged int.
        unsigned int ipInt = getIpIntValue(ip);
        for (long long i = ipInt; i <= MAX_IP; ++ i) {
            cout << getIpStringValue(i) << endl;
           // if (i - ipInt >= 2) break;
        }
    }

    void iteratorDec(string ip) {
        unsigned int ipInt = getIpIntValue(ip);
        for (long long i = ipInt; i >= 0; -- i) {
            // result.push_back(getIpStringValue(i));
            cout << getIpStringValue(i) << endl;
            if (ipInt - i >= 100) break;
        }
    }

    void iteratorCidr(string cidr) {
        int index = cidr.find("/");
        if (index == string::npos) return;
        string ipStr = cidr.substr(0, index);
        int maskLen = stoi(cidr.substr(index + 1));

        unsigned int ipInt = getIpIntValue(ipStr);
        unsigned int inverseMask = (1 << (32 - maskLen)) - 1;
        unsigned int mask = ~inverseMask; // ((1 << (32 - maskVal)) - 1);
        cout << "ip = " << ipStr << ", maskLen = " << maskLen 
             << ", mask = " << getIpStringValue(mask) << ", inverseMask = " << inverseMask << endl;

        unsigned int startIp = ipInt, startMask = ipInt - (ipInt & inverseMask), endIp = startMask + inverseMask;
        cout << "start = " << getIpStringValue(startIp) << ", startMask = " << getIpStringValue(startMask) << ", end = " << getIpStringValue(endIp) << endl;

        for (long long i = startIp; i <= endIp; ++ i) {
            cout << getIpStringValue(i) << endl;
        }
    }

    void dump(vector<string> & vec, string name="name") {
        for (auto val : vec) {
            cout << val << endl;
        }
    }
};

class CIDRTest {
    void test1() {
        CIDR cidr;
        cidr.iteratorInc("255.255.255.241");
        cidr.iteratorDec("0.0.0.10");
        cidr.iteratorCidr("2.255.255.240/29");

        // long long a = 0;
        // unsigned int b = 0;
        // cout << "sizeof(a) = " << sizeof(a) << endl; // 8
        // cout << "sizeof(b) = " << sizeof(b) << endl; // 4
    }
public:
    void run_tests() {
        test1();
    }
};

int main() {
    CIDRTest test;
    test.run_tests();
    return 0;
}
