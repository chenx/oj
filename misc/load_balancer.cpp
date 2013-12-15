/*
Load balancer: array:

get random server: O(1)
label as busy: swap to end. O(1)
reset as free: advance end pointer: O(1)

 */