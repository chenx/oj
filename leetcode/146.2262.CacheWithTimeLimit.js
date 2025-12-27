var TimeLimitedCache = function() {
    this.cache = new Map(); // <key, [value, duration]>
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
    for (const key of this.cache.keys()) {
        if (curTime < this.cache.get(key)[1]) ++ count;
        else this.cache.delete(key);
    }
    return count;
};

/**
 * const timeLimitedCache = new TimeLimitedCache()
 * timeLimitedCache.set(1, 42, 1000); // false
 * timeLimitedCache.get(1) // 42
 * timeLimitedCache.count() // 1
 */
 
