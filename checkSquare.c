#include <stdio.h>

int isLoShuMagicSquare(int square[3][3]) {
    int used[10] = {0}; //save which integers have been used before

    //Check for repeat values, and if numbers are between 1 and 9
    for (int row = 0; row < 3; row++) {
        for (int col = 0; col < 3; col++) {
            int num = square[row][col];
            if (num < 1 || num > 9 || used[num]) {
                return 0; //Return value for invalid square
            }
            used[num] = 1;
        }
    }

    //Check all row sums
    for (int row = 0; row < 3; row++) {
        int rowSum = 0;
        for (int col = 0; col < 3; col++) {
            rowSum += square[row][col];
        }
        if (rowSum != 15) {
            return 0;
        }
    }

    //Check all column sums
    for (int col = 0; col < 3; col++) {
        int colSum = 0;
        for (int row = 0; row < 3; row++) {
            colSum += square[row][col];
        }
        if (colSum != 15) {
            return 0;
        }
    }

    //Check both diagonal sums
    int diag1 = square[1][1] + square[2][2] + square[0][0];
    int diag2 = square[0][2] + square[1][1] + square[2][0];

    if (diag1 != 15 || diag2 != 15) {
        return 0;
    }

    return 1;
}
/*
void testSquare(int square[3][3], const char *label) {
    printf("%s:\n", label);
    for (int i = 0; i < 3; i++) {
        printf("[%d %d %d]\n", square[i][0], square[i][1], square[i][2]);
    }

    if (isLoShuMagicSquare(square)) {
        printf("Result: VALID Lo Shu Magic Square\n\n");
    } else {
        printf("Result: INVALID\n\n");
    }
}

int main() {
    int valid[3][3] = {
        {4, 9, 2},
        {3, 5, 7},
        {8, 1, 6}
    };

    int wrongSum[3][3] = {
        {4, 9, 2},
        {3, 6, 7},
        {8, 1, 5}
    };

    int duplicate[3][3] = {
        {4, 9, 2},
        {3, 5, 7},
        {8, 1, 2}
    };

    int outOfRange[3][3] = {
        {4, 9, 2},
        {3, 5, 10},
        {8, 1, 6}
    };

    testSquare(valid, "Test Case 1: Valid Square");
    testSquare(wrongSum, "Test Case 2: Incorrect Sum");
    testSquare(duplicate, "Test Case 3: Duplicate Numbers");
    testSquare(outOfRange, "Test Case 4: Out-of-Range Numbers");

    return 0;
}
*/
