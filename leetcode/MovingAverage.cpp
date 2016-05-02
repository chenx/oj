// Should work. Not tested.
class MovingAverage2 {
public:
    /** Initialize your data structure here. */
    queue<int> q;
    int capacity, sum;

    MovingAverage(int size) {
        if (size < 0) size = 0;
        capacity = size;
        sum = 0;
    }

    double next(int val) {
        q.push(val);
        sum += val;

        if (q.size() > capacity) {
          sum -= q.front();
          q.pop();
        }
        
        return 1.0 * sum / q.size();
    }
};


// From: https://leetcode.com/discuss/100516/very-easy-c-solution-using-queue
class MovingAverage {
public:
    /** Initialize your data structure here. */
    queue<int> que;
    int length;
    int count;
    int sum;
    MovingAverage(int size) {
        length = size;
        count = 0;
        sum = 0;
    }

    double next(int val) {
        if(count < length){
            count++;
            que.push(val);
            sum+=val;
            return sum/count;
        }
        else{
            sum -= que.front();
            que.pop();
            que.push(val);
            sum+=val;
            return sum/count;
        }
    }
};


/**
Moving Average from Data Stream
Difficulty: Easy

Given a stream of integers and a window size, calculate the moving average 
of all integers in the sliding window.
 */
