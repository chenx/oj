// Time: O(1)
// Space: O(n)
class SnakeGame {
    int COLS, ROWS;
    deque<vector<int>> snake; // head: snake.front()
    set<vector<int>> used;
    vector<vector<int>> food;
    int foodIndex;
    int score;

public:
    SnakeGame(int width, int height, vector<vector<int>>& food) : COLS(width), ROWS(height), food(food) {
        snake.push_back({0, 0});
        used.insert({0, 0});
        score = 0;
        foodIndex = 0;
    }
    
    int move(string direction) {
        vector<int> head = snake.front();
        int i = head[0], j = head[1];

        if (direction == "U") {
            -- i;
        } else if (direction == "D") {
            ++ i;
        } else if (direction == "L") {
            -- j;
        } else if (direction == "R") {
            ++ j;
        } else {
            throw exception();
        }

        if (i < 0 || i >= ROWS || j < 0 || j >= COLS) return -1;

        if (foodIndex < food.size() && i == food[foodIndex][0] && j == food[foodIndex][1]) {
            ++ foodIndex;
            ++ score;
        } else { // NOTE: must erase tail first before adding head, to avoid the bug of self crossing.
            used.erase(snake.back());
            snake.pop_back();
        }

        if (used.contains({i, j})) {
            return -1;
        }
        snake.push_front({i, j});
        used.insert({i, j});

        return score;
    }
};

/**
 * Your SnakeGame object will be instantiated and called as such:
 * SnakeGame* obj = new SnakeGame(width, height, food);
 * int param_1 = obj->move(direction);
 */


/**
353. Design Snake Game
Medium

Design a Snake game that is played on a device with screen size height x width. Play the game online if you are 
not familiar with the game.

The snake is initially positioned at the top left corner (0, 0) with a length of 1 unit.

You are given an array food where food[i] = (ri, ci) is the row and column position of a piece of food that the 
snake can eat. When a snake eats a piece of food, its length and the game's score both increase by 1.

Each piece of food appears one by one on the screen, meaning the second piece of food will not appear until the 
snake eats the first piece of food.

When a piece of food appears on the screen, it is guaranteed that it will not appear on a block occupied by the snake.

The game is over if the snake goes out of bounds (hits a wall) or if its head occupies a space that its body 
occupies after moving (i.e. a snake of length 4 cannot run into itself).

Implement the SnakeGame class:

    SnakeGame(int width, int height, int[][] food) Initializes the object with a screen of size height x width 
        and the positions of the food.
    int move(String direction) Returns the score of the game after applying one direction move by the snake. 
        If the game is over, return -1.

 

Example 1:

Input
["SnakeGame", "move", "move", "move", "move", "move", "move"]
[[3, 2, [[1, 2], [0, 1]]], ["R"], ["D"], ["R"], ["U"], ["L"], ["U"]]
Output
[null, 0, 0, 1, 1, 2, -1]
 */
