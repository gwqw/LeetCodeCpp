/**
    1041. Robot Bounded In Circle
On an infinite plane, a robot initially stands at (0, 0) and faces north. The robot can receive one of three instructions:
- "G": go straight 1 unit;
- "L": turn 90 degrees to the left;
- "R": turn 90 degrees to the right.
The robot performs the instructions given in order, and repeats them forever.

Return true if and only if there exists a circle in the plane such that the robot never leaves the circle.

Example 1:
Input: instructions = "GGLLGG"
Output: true
Explanation: The robot moves from (0,0) to (0,2), turns 180 degrees, and then returns to (0,0).
When repeating these instructions, the robot remains in the circle of radius 2 centered at the origin.

Example 2:
Input: instructions = "GG"
Output: false
Explanation: The robot moves north indefinitely.

Example 3:
Input: instructions = "GL"
Output: true
Explanation: The robot moves from (0, 0) -> (0, 1) -> (-1, 1) -> (-1, 0) -> (0, 0) -> ...

Constraints:
1 <= instructions.length <= 100
instructions[i] is 'G', 'L' or, 'R'.

Algo1: like cycle in linked list: hare and tortoise (very long, but it works)
- one speed
- double speed
- if in same point -- cycle
- else has max steps

Algo2: analyse end direction: O(N), O(1)mem
if same:
    infinite
else:
    will be cycle
*/

class Solution {
    struct Point {
        int x = 0;
        int y = 0;
        friend bool operator==(const Point& lhs, const Point& rhs) {
            return lhs.x == rhs.x && lhs.y == rhs.y;
        }
        friend bool operator!=(const Point& lhs, const Point& rhs) {
            return !(lhs == rhs);
        }
    };
    
    enum class Direction {
        North, South, East, West
    };
    
public:
    bool isRobotBounded(string_view instructions) {
        Point t_pos;
        Direction t_dir = Direction::North;
        make_step(instructions, t_pos, t_dir);
        Point h_pos;
        Direction h_dir = Direction::North;
        make_step(instructions, h_pos, h_dir);
        make_step(instructions, h_pos, h_dir);
        int iterations = 0;
        while (t_pos != h_pos || t_dir != h_dir) {
            make_step(instructions, t_pos, t_dir);
            make_step(instructions, h_pos, h_dir);
            make_step(instructions, h_pos, h_dir);
            iterations++;
            if (iterations >= 1'000'000) return false;
        }
        return true;
    }
    
private:
    void make_step(string_view instructions, Point& p, Direction& d) {
        for (char i : instructions) {
            if (i == 'L') {
                changeDirectionLeft(d);
            } else if (i == 'R') {
                changeDirectionRight(d);
            } else {
                moveForvard(p, d);
            }
        }
    }
    
    void changeDirectionLeft(Direction& d) {
        switch (d) {
            case Direction::North:
                d = Direction::West;
                break;
            case Direction::West:
                d = Direction::South;
                break;
            case Direction::South:
                d = Direction::East;
                break;
            case Direction::East:
                d = Direction::North;
                break;
        }
    }
    
    void changeDirectionRight(Direction& d) {
        switch (d) {
            case Direction::North:
                d = Direction::East;
                break;
            case Direction::West:
                d = Direction::North;
                break;
            case Direction::South:
                d = Direction::West;
                break;
            case Direction::East:
                d = Direction::South;
                break;
        }
    }
    
    void moveForvard(Point& p, Direction d) {
        switch (d) {
            case Direction::North:
                ++p.y;
                break;
            case Direction::West:
                --p.x;
                break;
            case Direction::South:
                --p.y;
                break;
            case Direction::East:
                ++p.x;
                break;
        }
    }
};

class Solution {
    struct Point {
        int x = 0;
        int y = 0;
        friend bool operator==(const Point& lhs, const Point& rhs) {
            return lhs.x == rhs.x && lhs.y == rhs.y;
        }
        friend bool operator!=(const Point& lhs, const Point& rhs) {
            return !(lhs == rhs);
        }
    };
    
    enum class Direction {
        North, South, East, West
    };
    
public:
    bool isRobotBounded(string_view instructions) {
        Point p;
        Direction d = Direction::North;
        make_step(instructions, p, d);
        return d != Direction::North || p == Point{0,0};
    }
    
private:
    void make_step(string_view instructions, Point& p, Direction& d) {
        for (char i : instructions) {
            if (i == 'L') {
                changeDirectionLeft(d);
            } else if (i == 'R') {
                changeDirectionRight(d);
            } else {
                moveForvard(p, d);
            }
        }
    }
    
    void changeDirectionLeft(Direction& d) {
        switch (d) {
            case Direction::North:
                d = Direction::West;
                break;
            case Direction::West:
                d = Direction::South;
                break;
            case Direction::South:
                d = Direction::East;
                break;
            case Direction::East:
                d = Direction::North;
                break;
        }
    }
    
    void changeDirectionRight(Direction& d) {
        switch (d) {
            case Direction::North:
                d = Direction::East;
                break;
            case Direction::West:
                d = Direction::North;
                break;
            case Direction::South:
                d = Direction::West;
                break;
            case Direction::East:
                d = Direction::South;
                break;
        }
    }
    
    void moveForvard(Point& p, Direction d) {
        switch (d) {
            case Direction::North:
                ++p.y;
                break;
            case Direction::West:
                --p.x;
                break;
            case Direction::South:
                --p.y;
                break;
            case Direction::East:
                ++p.x;
                break;
        }
    }
};