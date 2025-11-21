// From: https://leetcode.com/problems/my-calendar-i/editorial/
// Sorted List + Binary Search
//
// The std::set::lower_bound() method in C++ finds the first element that is >= specified value. 
// std::prev takes an iterator and an optional integer n (defaulting to 1). It returns a new iterator 
// that is n positions before the original iterator. Essentially, it performs std::advance(it, -n) and 
// returns the resulting iterator.
//
class MyCalendar {
private:
    set<pair<int, int>> calendar;

public:
    bool book(int start, int end) {
        const pair<int, int> event{start, end};
        const auto nextEvent = calendar.lower_bound(event);
        if (nextEvent != calendar.end() && nextEvent->first < end) {
            return false;
        }

        if (nextEvent != calendar.begin()) {
            const auto prevEvent = prev(nextEvent);
            if (prevEvent->second > start) {
                return false;
            }
        }

        calendar.insert(event);
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(startTime,endTime);
 */


/**
729. My Calendar I
Medium

You are implementing a program to use as your calendar. We can add a new event if adding the event 
will not cause a double booking.

A double booking happens when two events have some non-empty intersection (i.e., some moment is 
common to both events.).

The event can be represented as a pair of integers startTime and endTime that represents a booking 
on the half-open interval [startTime, endTime), the range of real numbers x such that startTime <= x < endTime.

Implement the MyCalendar class:

    MyCalendar() Initializes the calendar object.
    boolean book(int startTime, int endTime) Returns true if the event can be added to the calendar 
        successfully without causing a double booking. Otherwise, return false and do not add the event to the calendar.
 */
