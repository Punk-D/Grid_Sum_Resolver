#include <iostream>
#include <vector>
#include <climits> // For INT_MAX
#include <cstdlib> // For rand() and srand()
#include <ctime>   // For time()

const int SIZE = 5;
const int MAX_RANDOM_VALUE = 9;

// Function to generate a random 5x5 array
void generateRandomArray(std::vector<std::vector<int>>& grid) {
    srand(time(0));
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            grid[i][j] = rand() % (MAX_RANDOM_VALUE + 1);
        }
    }
}

// Recursive function to find the minimum sum path
int findMinSumPath(const std::vector<std::vector<int>>& grid, int row, int col) {
    if (row < 0 || row >= SIZE || col < 0 || col >= SIZE) {
        return INT_MAX; // Return a large value for out-of-bounds cells
    }

    if (row == SIZE - 1 && col == SIZE - 1) {
        return grid[row][col]; // Return the value for the destination cell
    }

    // Move right and down recursively
    int moveRight = findMinSumPath(grid, row, col + 1);
    int moveDown = findMinSumPath(grid, row + 1, col);

    // Choose the minimum value between the two paths
    return grid[row][col] + std::min(moveRight, moveDown);
}

int main() {
    std::vector<std::vector<int>> grid(SIZE, std::vector<int>(SIZE, 0));

    // Generate a random 5x5 array
    generateRandomArray(grid);

    // Print the generated array
    std::cout << "Generated array:" << std::endl;
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            std::cout << grid[i][j] << " ";
        }
        std::cout << std::endl;
    }

    // Find the minimum sum path from (0, 0) to (4, 4)
    int minSumPath = findMinSumPath(grid, 0, 0);

    std::cout << "\nMinimum sum path: " << minSumPath << std::endl;

    return 0;
}
