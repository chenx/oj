# """
# This is the robot's control interface.
# You should not implement it, or speculate about its implementation
# """
#class Robot:
#    def move(self):
#        """
#        Returns true if the cell in front is open and robot moves into the cell.
#        Returns false if the cell in front is blocked and robot stays in the current cell.
#        :rtype bool
#        """
#
#    def turnLeft(self):
#        """
#        Robot will stay in the same cell after calling turnLeft/turnRight.
#        Each turn will be 90 degrees.
#        :rtype void
#        """
#
#    def turnRight(self):
#        """
#        Robot will stay in the same cell after calling turnLeft/turnRight.
#        Each turn will be 90 degrees.
#        :rtype void
#        """
#
#    def clean(self):
#        """
#        Clean the current cell.
#        :rtype void
#        """

class Solution:

    def cleanRoom(self, robot):
        """
        :type robot: Robot
        :rtype: None
        """
        def dfs(robot, i, j, direction):
            visited.add((i, j))
            robot.clean()

            for k in range(len(directions)):
                newDirection = (direction + k) % 4
                x, y = i + directions[newDirection][0], j + directions[newDirection][1]
                if not (x, y) in visited and robot.move():
                    dfs(robot, x, y, newDirection)
                    # back
                    robot.turnLeft()
                    robot.turnLeft()
                    robot.move()
                    robot.turnLeft()
                    robot.turnLeft()
                robot.turnLeft()


        visited = set()
        directions = [[-1, 0], [0, 1], [1, 0], [0, -1]]
        dfs(robot, 0, 0, 0)


/**
489. Robot Room Cleaner
Solved
Hard
Topics
conpanies iconCompanies

You are controlling a robot that is located somewhere in a room. The room is modeled as an m x n binary grid 
where 0 represents a wall and 1 represents an empty slot.

The robot starts at an unknown location in the room that is guaranteed to be empty, and you do not have access 
to the grid, but you can move the robot using the given API Robot.

You are tasked to use the robot to clean the entire room (i.e., clean every empty cell in the room). 
The robot with the four given APIs can move forward, turn left, or turn right. Each turn is 90 degrees.

When the robot tries to move into a wall cell, its bumper sensor detects the obstacle, and it stays on 
the current cell.

Design an algorithm to clean the entire room using the following APIs:

interface Robot {
  // returns true if next cell is open and robot moves into the cell.
  // returns false if next cell is obstacle and robot stays on the current cell.
  boolean move();

  // Robot will stay on the same cell after calling turnLeft/turnRight.
  // Each turn will be 90 degrees.
  void turnLeft();
  void turnRight();

  // Clean the current cell.
  void clean();
}

Note that the initial direction of the robot will be facing up. You can assume all four edges of the grid 
are all surrounded by a wall.

 

Custom testing:

The input is only given to initialize the room and the robot's position internally. You must solve this 
problem "blindfolded". In other words, you must control the robot using only the four mentioned APIs 
without knowing the room layout and the initial robot's position.

 

Example 1:

Input: room = [[1,1,1,1,1,0,1,1],[1,1,1,1,1,0,1,1],[1,0,1,1,1,1,1,1],[0,0,0,1,0,0,0,0],[1,1,1,1,1,1,1,1]], row = 1, col = 3
Output: Robot cleaned all rooms.
Explanation: All grids in the room are marked by either 0 or 1.
0 means the cell is blocked, while 1 means the cell is accessible.
The robot initially starts at the position of row=1, col=3.
From the top left corner, its position is one row below and three columns right.

Example 2:

Input: room = [[1]], row = 0, col = 0
Output: Robot cleaned all rooms.
 */
