#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int isLoShuMagicSquare(int square[3][3]);

void shuffle(int *arr, int size) {
    for (int i = size-1; i > 0; i--) {
        int j = rand() % (i + 1);
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
}

int main() {
    srand(time(NULL)); //sets the seed to the amount of seconds since like 1970 or something, makes it more random
    int count = 0;
    int square[3][3];
    int nums[9];

    while (1) {
        count++;

        for (int i = 0; i < 9; i++) {
            nums[i] = i + 1;
        }

        shuffle(nums, 9);

        int index = 0;
        for (int row = 0; row < 3; row++) {
            for (int col = 0; col < 3; col++) {
                square[row][col] = nums[index];
                index++;
            }
        }

        if (isLoShuMagicSquare(square)) {
            printf("Success after %d attempts!\n", count);
            printf("[%d %d %d]\n", square[0][0], square[0][1], square[0][2]);
            printf("[%d %d %d]\n", square[1][0], square[1][1], square[1][2]);
            printf("[%d %d %d]\n", square[2][0], square[2][1], square[2][2]);
            break;
        }
    }

    return 0;
}
