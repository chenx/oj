class Solution:
    def ipToCIDR(self, ip: str, n: int) -> List[str]:
        def getCidr(intIp, step):
            ip = str((intIp >> 24) & 0xFF) + '.' + \
                str((intIp >> 16) & 0xFF) + '.' + \
                str((intIp >> 8) & 0xFF) + '.' + \
                str((intIp) & 0xFF)
            
            maskLen = 33
            while step > 0:
                maskLen -= 1
                step //= 2
            return ip + '/' + str(maskLen)


        intIp = 0
        for item in ip.split('.'):
            intIp = (intIp << 8) + int(item)
        
        result = []
        while n > 0:
            if intIp == 0:
                step = 1
                while step * 2 <= n:
                    step *= 2
            else:
                step = intIp & -intIp # get last '1' and after.
                while step > n:
                    step //= 2
            result.append(getCidr(intIp, step))
            intIp += step
            n -= step

        return result


/**
751. IP to CIDR
Solved
Medium
Topics
conpanies iconCompanies
Hint

An IP address is a formatted 32-bit unsigned integer where each group of 8 bits is printed as a decimal number 
and the dot character '.' splits the groups.

    For example, the binary number 00001111 10001000 11111111 01101011 (spaces added for clarity) formatted as 
an IP address would be "15.136.255.107".

A CIDR block is a format used to denote a specific set of IP addresses. It is a string consisting of a base IP 
address, followed by a slash, followed by a prefix length k. The addresses it covers are all the IPs whose 
first k bits are the same as the base IP address.

    For example, "123.45.67.89/20" is a CIDR block with a prefix length of 20. Any IP address whose binary 
    representation matches 01111011 00101101 0100xxxx xxxxxxxx, where x can be either 0 or 1, is in the set 
    covered by the CIDR block.

You are given a start IP address ip and the number of IP addresses we need to cover n. Your goal is to use as 
few CIDR blocks as possible to cover all the IP addresses in the inclusive range [ip, ip + n - 1] exactly. 
No other IP addresses outside of the range should be covered.

Return the shortest list of CIDR blocks that covers the range of IP addresses. If there are multiple answers, 
return any of them.

 

Example 1:

Input: ip = "255.0.0.7", n = 10
Output: ["255.0.0.7/32","255.0.0.8/29","255.0.0.16/32"]
 */
