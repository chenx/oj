class Solution3 {
public:
    int reverse(int x) {
        bool neg = false;
        if (x < 0) {
            neg = true;
            x = -x;
        }

        long long y = 0, y0;
        while (x > 0) {
            y0 = y * 10 + (x % 10);
            if (y0 / 10 != y) return 0;
            x /= 10;
            y = y0;
        }

        return neg ? -y : y;
    }
};

// This works. Overflow value is now 0, not INT_MAX in the past.
class Solution2 {
public:
    int reverse(int x) {
        //if (x == Integer.MIN_VALUE) return 0; // not needed.
        bool neg = (x < 0);
        if (neg) x = -x;
        
        int y0, y = 0;
        while (x > 0) {
            y0 = y;
            y = y * 10 + (x % 10);
            if (y / 10 != y0) return 0;
            x /= 10;
        }
        
        if (neg) y = -y;
        return y;        
    }
};

class Solution {
public:
    int reverse(int x) {
        return (x < 0) ? - rev(-x) : rev(x);        
    }
    
    int rev(int x) {
        int r = 0, r0;
        while (x) {
            r0 = r;
            r = r * 10 + x % 10;
            if (r / 10 != r0) return 0; //INT_MAX; // overflowed
            x = x / 10;
        }
        return r;
    }


    // This doesn't consider about overflow, so cannot pass.
    int reverse_v2(int x) {
        int neg = (x < 0) ? -1 : 1;        
        x = x * neg;
        
        int y = 0;
        while (x > 0) {
            y = y * 10 + x % 10;
            x /= 10;
        }
        
        return y * neg;
    }

};
