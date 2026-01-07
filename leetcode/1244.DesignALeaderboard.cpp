// Time: O(log n) for addScore and reset, O(k) for top
// Space: O(n)
class Leaderboard {
    map<int, int> scores; // playerId, score
    map<int, int> scoreCount; // score, count
public:
    Leaderboard() {
        
    }
    
    void addScore(int playerId, int score) {
        if (scores.contains(playerId)) {
            int oldScore = scores[playerId];
            scoreCount[oldScore] --;
            if (scoreCount[oldScore] == 0) scoreCount.erase(oldScore);

            score += oldScore;
            scores[playerId] = score;
            scoreCount[score] ++;
        } else {
            scores[playerId] = score;
            scoreCount[score] ++;
        }
    }
    
    int top(int K) {
        int sum = 0;
        for (auto it = scoreCount.rbegin(); it != scoreCount.rend(); ++it) {
            if (it->second >= K) {
                sum += it->first * K;
                break;
            } else {
                sum += it->first * it->second;
                K -= it->second;
            }
        }
        return sum;
    }
    
    void reset(int playerId) {
        int score = scores[playerId];
        scoreCount[score] --;
        if (scoreCount[score] == 0) scoreCount.erase(score);

        scores.erase(playerId);
    }
};

/**
 * Your Leaderboard object will be instantiated and called as such:
 * Leaderboard* obj = new Leaderboard();
 * obj->addScore(playerId,score);
 * int param_2 = obj->top(K);
 * obj->reset(playerId);
 */


/**
1244. Design A Leaderboard
Medium

Design a Leaderboard class, which has 3 functions:

    addScore(playerId, score): Update the leaderboard by adding score to the given player's score. 
        If there is no player with such id in the leaderboard, add him to the leaderboard with the given score.
    top(K): Return the score sum of the top K players.
    reset(playerId): Reset the score of the player with the given id to 0 (in other words erase it from the 
        leaderboard). It is guaranteed that the player was added to the leaderboard before calling this function.

Initially, the leaderboard is empty.
 */
