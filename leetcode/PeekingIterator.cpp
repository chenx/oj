// Works. Single out a getNext() method.
class PeekingIterator3 : public Iterator {
public:
	PeekingIterator(const vector<int>& nums) : Iterator(nums) {
	    // Initialize any member here.
	    // **DO NOT** save a copy of nums and manipulate it directly.
	    // You should only use the Iterator interface methods.
        getNext();
	}

    // Returns the next element in the iteration without advancing the iterator.
	int peek() {
        return _data;
	}

	// hasNext() and next() should behave the same as in the Iterator interface.
	// Override them if needed.
	int next() {
	    int val = _data;
        getNext();
	    return val;
	}

	bool hasNext() const {
       return _hasNext;
	}
private:
    bool _hasNext;
    int  _data;
    
    void getNext() {
        _hasNext = Iterator::hasNext();
	    if (_hasNext) _data = Iterator::next();
    }
};


// Solution 2. Works. Tested.
// Slightly better function next().
class PeekingIterator2 : public Iterator {
public:
    PeekingIterator(const vector<int>& nums) : Iterator(nums) {
	// Initialize any member here.
	// **DO NOT** save a copy of nums and manipulate it directly.
	// You should only use the Iterator interface methods.
        _hasNext = Iterator::hasNext();
        if (_hasNext) _data = Iterator::next();
    }

    // Returns the next element in the iteration without advancing the iterator.
    int peek() {
        return _data;
    }

    // hasNext() and next() should behave the same as in the Iterator interface.
    // Override them if needed.
    int next() {
	int data = _data;
	    
	_hasNext = Iterator::hasNext();
	if (_hasNext) _data = Iterator::next();
	    
        return data;
    }

    bool hasNext() const {
       return _hasNext;
    }
private:
    bool _hasNext;
    int _data;
};

// Below is the interface for Iterator, which is already defined for you.
// **DO NOT** modify the interface for Iterator.
class Iterator {
        struct Data;
	Data* data;
public:
	Iterator(const vector<int>& nums);
	Iterator(const Iterator& iter);
	virtual ~Iterator();
	// Returns the next element in the iteration.
	int next();
	// Returns true if the iteration has more elements.
	bool hasNext() const;
};


class PeekingIterator : public Iterator {
private:
    //Iterator iterator;
    int m_next;
    bool m_hasNext;
    
public:
	PeekingIterator(const vector<int>& nums) : Iterator(nums) {
	    // Initialize any member here.
	    // **DO NOT** save a copy of nums and manipulate it directly.
	    // You should only use the Iterator interface methods.
	    m_hasNext = Iterator::hasNext();
	    if (m_hasNext) next();
	}

    // Returns the next element in the iteration without advancing the iterator.
	int peek() {
        return m_next;
	}

	// hasNext() and next() should behave the same as in the Iterator interface.
	// Override them if needed.
	int next() {
	    int cur = m_next;
	    if (Iterator::hasNext()) {
	        m_next = Iterator::next();
	        m_hasNext = true;
	    }
	    else {
	        m_hasNext = false;
	    }
	    return cur;
	}

	bool hasNext() const {
	    return m_hasNext;
	}
};


/**
Peeking Iterator
Difficulty: Medium

Given an Iterator class interface with methods: next() and hasNext(), 
design and implement a PeekingIterator that support the peek() operation -- 
it essentially peek() at the element that will be returned by the next call to next().

Here is an example. Assume that the iterator is initialized to the beginning of the list: [1, 2, 3].

Call next() gets you 1, the first element in the list.

Now you call peek() and it returns 2, the next element. 
Calling next() after that still return 2.

You call next() the final time and it returns 3, the last element. 
Calling hasNext() after that should return false.

Hint:

    Think of "looking ahead". You want to cache the next element.
    Is one variable sufficient? Why or why not?
    Test your design with call order of peek() before next() vs next() before peek().
    For a clean implementation, check out Google's guava library source code. 

Follow up: How would you extend your design to be generic and work with all types, not just integer?
 */
