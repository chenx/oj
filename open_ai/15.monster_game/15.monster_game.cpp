// 4:02 - 4:35

#include <iostream>

using namespace std;

enum MonsterType {
    MonsterType1,
    MonsterType2,
    MonsterType3,
};

struct Monster {
    string name;
    int health;
    int attack;
    MonsterType type;

    Monster(string name, int health, int attack, MonsterType monsterType) : 
        name(name), health(health), attack(attack), type(monsterType) {
    }
};

class Team {
public:
    vector<Monster> members;
    Team(vector<Monster>& membersValue) : members(membersValue) {
        // sort in reverse order of attack.
        auto comp = [](Monster &a, Monster& b) {
            return a.attack > b.attack;
        };
        sort(members.begin(), members.end(), comp);
    }
};

class BattleResult {
public:
    vector<string> logs;
    string winner;

    void log(string& msg) {
        logs.push_back(msg);
    }
};

class BattleEngine {
    BattleResult battleResult;

    void log(string msg) {
        battleResult.log(msg);
        // cout << msg << endl;
    }
public:
    BattleEngine() {

    }

    int getAttackByType(Monster& monster) {
        if (monster.type == MonsterType2) return monster.attack * 2;
        if (monster.type == MonsterType3) return monster.attack * 3;
        return monster.attack;
    }
    
    BattleResult run(Team& teamA, Team& teamB) {
        auto &A = teamA.members, &B = teamB.members;
        int m = A.size(), n = B.size();
        int i = 0, j = 0, h1, h2, attack;

        bool curIsA = true;
        for (; i < m && j < n; ) {
            if (curIsA) {
                attack = getAttackByType(A[i]);
                h1 = B[j].health;
                B[j].health -= attack;
                h2 = B[j].health;

                log("A[" + to_string(i) + "]:" + A[i].name + " attacks B[" + to_string(j) + "]:" + "attack=" + to_string(attack) + 
                    ": " + B[j].name + "(health: " + to_string(h1) + "->" + to_string(h2) + ")");
                if (B[j].health <= 0) {
                    log("B[" + to_string(j) + "]:" + B[j].name + " is dead");
                    ++ j;
                }
            } else {
                attack = getAttackByType(B[j]);
                h1 = A[i].health;
                A[i].health -= attack;
                h2 = A[i].health;

                log("B[" + to_string(j) + "]:" + B[j].name + " attacks A[" + to_string(i) + "]:" + "attack=" + to_string(attack) + 
                    ": " + A[i].name + "(health: " + to_string(h1) + "->" + to_string(h2) + "");
                if (A[i].health <= 0) {
                    log("A[" + to_string(i) + "]:" + A[i].name + " is dead");
                    ++ i;
                }
            }
            curIsA = ! curIsA;
        }

        string winner = (i < m) ? "A" : "B";
        log("==Game over: Team " + winner + " wins");
        battleResult.winner = winner;
        return battleResult;
    }
};

class GameTest {
    void test1() {
        cout << "hi" << endl;
        BattleEngine game;

        vector<Monster> A, B;
        A = {
            Monster("a1", 10, 2, MonsterType1),
            Monster("a2", 12, 4, MonsterType3),
            Monster("a3", 13, 5, MonsterType1),
        };
        B = {
            Monster("b1", 12, 3, MonsterType1),
            Monster("b2", 9, 2, MonsterType2),
            Monster("b3", 16, 5, MonsterType1),
        };
        Team teamA(A), teamB(B);
    
        BattleResult result = game.run(teamA, teamB);
        for (auto& log : result.logs) {
            cout << log << endl;
        }
    }
public:
    void run_tests() {
        test1();
    }
};

int main() {
    GameTest test;
    test.run_tests();
    return 0;
}
