// When pop, be careful of the case when the queue to pop is empty.

class FrontMiddleBackQueue {
    deque<int> q1, q2;

public:
    FrontMiddleBackQueue() {
        
    }
    
    void pushFront(int val) {
        q1.push_front(val);
        if (q1.size() - q2.size() == 2) {
            q2.push_front(q1.back());
            q1.pop_back();
        }
    }
    
    void pushMiddle(int val) {
        int diff = q1.size() - q2.size();
        if (diff == 0) {
            q1.push_back(val);
        } else if (diff == 1) {
            q2.push_front(q1.back());
            q1.pop_back();
            q1.push_back(val);
        } else { // -1
            q1.push_back(val);
        }
    }
    
    void pushBack(int val) {
        q2.push_back(val);
        if (q2.size() - q1.size() == 2) {
            q1.push_back(q2.front());
            q2.pop_front();
        }
    }
    
    int popFront() {
        if (empty()) return -1;

        if (q1.empty()) {
            int val = q2.front();
            q2.pop_front();
            return val;
        }

        int val = q1.front();
        q1.pop_front();
        if (q1.size() - q2.size() == -2) {
            q1.push_back(q2.front());
            q2.pop_front();
        }
        return val;
    }
    
    int popMiddle() {
        if (empty()) return -1;

        int diff = q1.size() - q2.size();
        if (diff == 0 || diff == 1) {
            if (q1.empty()) {
                int val = q2.front();
                q2.pop_front();
                return val;
            }
            int val = q1.back();
            q1.pop_back();
            return val;
        } else { // -1
            int val = q2.front();
            q2.pop_front();
            return val;
        }
    }
    
    int popBack() {
        if (empty()) return -1;

        if (q2.empty()) {
            int val = q1.back();
            q1.pop_back();
            return val;
        }

        int val = q2.back();
        q2.pop_back();

        if (q1.size() - q2.size() == 2) {
            q2.push_front(q1.back());
            q1.pop_back();
        }

        return val;
    }

    int empty() {
        return q1.empty() && q2.empty();
    }
};

/**
 * Your FrontMiddleBackQueue object will be instantiated and called as such:
 * FrontMiddleBackQueue* obj = new FrontMiddleBackQueue();
 * obj->pushFront(val);
 * obj->pushMiddle(val);
 * obj->pushBack(val);
 * int param_4 = obj->popFront();
 * int param_5 = obj->popMiddle();
 * int param_6 = obj->popBack();
 */

/**
1670. Design Front Middle Back Queue
Solved
Medium
Topics
conpanies iconCompanies
Hint

Design a queue that supports push and pop operations in the front, middle, and back.

Implement the FrontMiddleBack class:

    FrontMiddleBack() Initializes the queue.
    void pushFront(int val) Adds val to the front of the queue.
    void pushMiddle(int val) Adds val to the middle of the queue.
    void pushBack(int val) Adds val to the back of the queue.
    int popFront() Removes the front element of the queue and returns it. If the queue is empty, return -1.
    int popMiddle() Removes the middle element of the queue and returns it. If the queue is empty, return -1.
    int popBack() Removes the back element of the queue and returns it. If the queue is empty, return -1.

Notice that when there are two middle position choices, the operation is performed on the 
frontmost middle position choice. For example:

    Pushing 6 into the middle of [1, 2, 3, 4, 5] results in [1, 2, 6, 3, 4, 5].
    Popping the middle from [1, 2, 3, 4, 5, 6] returns 3 and results in [1, 2, 4, 5, 6].
 */
