// Use expireTime instead of timestamp.
class AuthenticationManager2 {
    int ttl;
    map<string, int> map; // <tokenId, expireTime>

public:
    AuthenticationManager(int timeToLive) {
        ttl = timeToLive;
    }
    
    void generate(string tokenId, int currentTime) {
        map[tokenId] = currentTime + ttl;
    }
    
    void renew(string tokenId, int currentTime) {
        if (map.contains(tokenId) && currentTime < map[tokenId]) {
            map[tokenId] = currentTime + ttl;
        }
    }
    
    int countUnexpiredTokens(int currentTime) {
        set<string> toRemove;
        int ct = 0;
        for (auto [tokenId, expireTime] : map) {
            if (currentTime < expireTime) ++ ct;
            else toRemove.insert(tokenId);
        }
        for (string tokenId : toRemove) map.erase(tokenId);

        return ct;
    }
};

// Works.
class AuthenticationManager {
    int ttl;
    map<string, int> map; // <tokenId, time>

public:
    AuthenticationManager(int timeToLive) {
        ttl = timeToLive;
    }
    
    void generate(string tokenId, int currentTime) {
        map[tokenId] = currentTime;
    }
    
    void renew(string tokenId, int currentTime) {
        if (map.contains(tokenId) && currentTime - map[tokenId] < ttl) {
            map[tokenId] = currentTime;
        }
    }
    
    int countUnexpiredTokens(int currentTime) {
        int ct = 0;
        for (auto [tokenId, timestamp] : map) {
            // Note this map.erase in for loop causes discrepancy and error.
            // if (currentTime - timestamp >= ttl) map.erase(tokenId);
            // else ++ ct;
            if (currentTime - timestamp < ttl) ++ ct;
        }
        return ct;
    }

    // This version removes expired entries.
    int countUnexpiredTokens2(int currentTime) {
        set<string> toRemove;
        int ct = 0;
        for (auto [tokenId, timestamp] : map) {
            if (currentTime - timestamp < ttl) ++ ct;
            else toRemove.insert(tokenId);
        }
        for (string tokenId : toRemove) map.erase(tokenId);

        return ct;
    }
};

/**
 * Your AuthenticationManager object will be instantiated and called as such:
 * AuthenticationManager* obj = new AuthenticationManager(timeToLive);
 * obj->generate(tokenId,currentTime);
 * obj->renew(tokenId,currentTime);
 * int param_3 = obj->countUnexpiredTokens(currentTime);
 */

/**
1797. Design Authentication Manager

There is an authentication system that works with authentication tokens. For each session, the user will receive 
a new authentication token that will expire timeToLive seconds after the currentTime. If the token is renewed, 
the expiry time will be extended to expire timeToLive seconds after the (potentially different) currentTime.

Implement the AuthenticationManager class:

    AuthenticationManager(int timeToLive) constructs the AuthenticationManager and sets the timeToLive.
    generate(string tokenId, int currentTime) generates a new token with the given tokenId at the given 
        currentTime in seconds.
    renew(string tokenId, int currentTime) renews the unexpired token with the given tokenId at the given 
        currentTime in seconds. If there are no unexpired tokens with the given tokenId, the request is ignored, 
        and nothing happens.
    countUnexpiredTokens(int currentTime) returns the number of unexpired tokens at the given currentTime.

Note that if a token expires at time t, and another action happens on time t (renew or countUnexpiredTokens), 
the expiration takes place before the other actions.
 */
