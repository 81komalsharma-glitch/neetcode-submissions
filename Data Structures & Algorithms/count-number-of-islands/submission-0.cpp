class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {

        int m = grid.size();
        int n = grid[0].size();

        int count = 0;

        // 4 directions: up, down, left, right
        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};

        for (int i = 0; i < m; i++) {

            for (int j = 0; j < n; j++) {

                // Found a new island
                if (grid[i][j] == '1') {

                    count++;

                    queue<pair<int, int>> q;

                    q.push({i, j});

                    // Mark visited
                    grid[i][j] = '0';

                    while (!q.empty()) {

                        int row = q.front().first;
                        int col = q.front().second;

                        q.pop();

                        // Check 4 directions
                        for (int k = 0; k < 4; k++) {

                            int newRow = row + dr[k];
                            int newCol = col + dc[k];

                            // Check boundaries
                            if (newRow >= 0 && newRow < m &&
                                newCol >= 0 && newCol < n &&
                                grid[newRow][newCol] == '1') {

                                q.push({newRow, newCol});

                                // Mark visited
                                grid[newRow][newCol] = '0';
                            }
                        }
                    }
                }
            }
        }

        return count;
    }
};