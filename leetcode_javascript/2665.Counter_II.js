// From: https://leetcode.com/problems/counter-ii/editorial/
var createCounter = function(init) {
  let currentCount = init;
  return {
    increment: function() {
       currentCount += 1;
       return currentCount;
    },
    decrement: function() {
       currentCount -= 1;
       return currentCount;
    },
    reset: function() {
       currentCount = init;
       return currentCount;
    },
  }
};

/**
 * @param {integer} init
 * @return { increment: Function, decrement: Function, reset: Function }
 */
var createCounter = function(init) {
    var cur = init;

    var increment = () => { return ++ cur; };
    var decrement = () => { return -- cur; };
    var reset = () => { cur = init; return cur; };

    // These also work:
    // function increment() {
    //     return ++ cur;
    // }
    // function decrement() {
    //     return -- cur;
    // }
    // function reset() {
    //     cur = val;
    //     return cur;
    // }

    return {increment, decrement, reset};
};

/**
 * const counter = createCounter(5)
 * counter.increment(); // 6
 * counter.reset(); // 5
 * counter.decrement(); // 4
 */

/**
2665. Counter II
Easy

Write a function createCounter. It should accept an initial integer init. 
It should return an object with three functions.

The three functions are:

    increment() increases the current value by 1 and then returns it.
    decrement() reduces the current value by 1 and then returns it.
    reset() sets the current value to init and then returns it.
 */
