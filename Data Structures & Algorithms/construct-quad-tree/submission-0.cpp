/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/

class Solution {
public:
    Node* check(int sr, int sc, int er, int ec,
                vector<vector<int>>& grid) {
        bool same = true;
        for (int i = sr; i < er; i++) {
            for (int j = sc; j < ec; j++) {
                if (grid[i][j] != grid[sr][sc]) {
                    same = false;
                    break;
                }
            }

            if (!same) break;
        }
        if (same) {
            return new Node(grid[sr][sc] == 1, true);
        }
        int midR = sr + (er - sr) / 2;
        int midC = sc + (ec - sc) / 2;
        Node* topLeft = check(sr, sc, midR, midC, grid);
        Node* topRight = check(sr, midC, midR, ec, grid);
        Node* bottomLeft = check(midR, sc, er, midC, grid);
        Node* bottomRight = check(midR, midC, er, ec, grid);
        return new Node(false, false,
                        topLeft, topRight,
                        bottomLeft, bottomRight);
    }
    Node* construct(vector<vector<int>>& grid) {
        int n = grid.size();
        return check(0, 0, n, n, grid);
    }
};