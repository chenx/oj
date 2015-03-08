/**
 * 一个Cube有6个面，每一个面有一个color，这6个面的color是可以
 * 任意的，而且可以重复。输入一系列的cube，判断这些cube能否组成一个四面都是同样
 * 颜色的tower(这些cube一个接一个竖着摞，没有并排的cube)。
 */
 
class Solution {
public:
    // entry point.
    bool solve(cube[] input, int n) {
        return can(input, n, 0);
    }
    
    // DFS
    bool can(cube[] input, int n, int cur) {
        if (cur == n) return true;
    
        while ( input[cur].getNextConfig() ) {
            if ( color_match(input, cur) ) {
                if ( can(input, n, cur + 1) ) return true;
            }
        }
    
        return false;
    }
    
    // Check color match. 
    // Only need to compare with first cube (input[0]) in tower.
    bool color_match(cube[] input, int cur) {
        if (cur == 0) return true;
    
        for (int i = 1; i < 4; ++ i) {
            if (input[0].side[i] != input[cur].side[i]) return false;
        }
        return true;
    }
};

// Cube class. Color of cube is given in constructor.
class cube {
public:
    int sides[6]; // {top, side1, side2, side3, side4, bottom}
    int colors[6];
    int config;

    cube(int color[6]) {
        for (int i = 0; i < 6; ++ i) colors[i] = color[i];
        config = 0;
    }

    // given a cube of 6 sides, first choose top (6 choices),
    // then choose side orientation (4 choices). 
    // Total 6x4 = 24 configurations.
    bool getNextConfig() {
        if (config == 24) return false;

        switch(config) {
            case 0: ... break;
            ...
            case 23: … break;
        }

        ++ config;
        return true;
    }
};

void test1() {
    const int n = 10;
    cube cubes[n];
    
    // initialize..
    cubes[0] = new cube({1,2,3,4,5,6});
    // ...
    
    Solution so;
    cout << so.solve(cubes, n) ? "Yes" : "No";
}

int main() {
    test1();
    return 0;
}
