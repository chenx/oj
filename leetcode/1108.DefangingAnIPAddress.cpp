class Solution {
public:
    string defangIPaddr(string address) {
        string result;
        for (char ch : address) {
            // result += ch == '.' ? "[.]" : string(1, ch);
            if (ch == '.') result += "[.]";
            else result += ch;
        }
        return result;
    }
};


/**
1108. Defanging an IP Address
Easy

Given a valid (IPv4) IP address, return a defanged version of that IP address.

A defanged IP address replaces every period "." with "[.]".
 */
