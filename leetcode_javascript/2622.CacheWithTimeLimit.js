var TimeLimitedCache = function() {
    this.cache = new Map(); // <key, <value, duration>>
};

TimeLimitedCache.prototype.getEpochTimeInMS = function() {
    return Date.now();
}

/** 
 * @param {number} key
 * @param {number} value
 * @param {number} duration time until expiration in ms
 * @return {boolean} if un-expired key already existed
 */
TimeLimitedCache.prototype.set = function(key, value, duration) {
    if (!this.cache.has(key)) {
        this.cache.set(key, [value, Date.now() + duration]);
        return false;
    }
    const expired = Date.now() >= this.cache.get(key)[1];
    this.cache.set(key, [value, Date.now() + duration]);
    return ! expired;
};

/** 
 * @param {number} key
 * @return {number} value associated with key
 */
TimeLimitedCache.prototype.get = function(key) {
    if (!this.cache.has(key)) {
        return -1;
    }
    if (Date.now() >= this.cache.get(key)[1]) {
        this.cache.delete(key);
        return -1;
    } else {
        return this.cache.get(key)[0];
    }
};

/** 
 * @return {number} count of non-expired keys
 */
TimeLimitedCache.prototype.count = function() {
    let count = 0;
    const curTime = Date.now();
    for (const item of this.cache.values()) {
        if (curTime < item[1]) ++ count;
    }
    return count;
};

/**
 * const timeLimitedCache = new TimeLimitedCache()
 * timeLimitedCache.set(1, 42, 1000); // false
 * timeLimitedCache.get(1) // 42
 * timeLimitedCache.count() // 1
 */

/**
2622. Cache With Time Limit
Medium

Write a class that allows getting and setting key-value pairs, however a time until expiration is 
associated with each key.

The class has three public methods:

set(key, value, duration): accepts an integer key, an integer value, and a duration in milliseconds. 
Once the duration has elapsed, the key should be inaccessible. The method should return true if the 
same un-expired key already exists and false otherwise. Both the value and duration should be 
overwritten if the key already exists.

get(key): if an un-expired key exists, it should return the associated value. Otherwise it should return -1.

count(): returns the count of un-expired keys.
 */
