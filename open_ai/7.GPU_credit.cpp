

/**
Operations:
Add credit: At time t, add x credits, which will expire at time t_expire.
Expire credit: Credits added earlier should automatically expire when their expiration time is reached.
Cost: At time t, deduct x credits if available. If insufficient credits exist at that time, return False.

Requirements:
Maintain all events (add, expire, cost) in chronological order.

When processing a cost event:
First check if the current balance is sufficient.
If not, return False.
If yes, deduct credits by adjusting the future expire entries accordingly (consume the oldest credits first).

The system should support multiple adds, expires, and costs interleaved at different timestamps.

Example:
Add(10, 5, expire=20)   # at timestamp=10, add 5 credits, which expire at 20
Cost(15, 3)             # at timestamp=15, consume 3 credits → valid
After this operation, the future expire at (20, 5) should be updated to (20, 2).
 */
