#include <stdio.h>
#include <string.h>
#define GND    9
#define ABS(X)    ((X) >= 0 ? (X) : (X) * (-1))

typedef struct pair {
    int idx;
    int value;
} Pair;

int N, K, start, ans;
int tank[10][100];
int diff[10][100];
Pair sorted[100];
int height[100];

void swap(Pair arr[], int id1, int id2) {
    Pair tmp = arr[id1];
    arr[id1] = arr[id2];
    arr[id2] = tmp;
}

int divide(Pair arr[], int l, int r) {
    int pivot = arr[l].value;
    int low = l + 1;
    int high = r;

    while (low <= high) {
        while (pivot >= arr[low].value && low <= r) ++low;
        while (pivot <= arr[high].value && high >= (l + 1)) --high;

        if (low <= high) swap(arr, low, high);
    }

    swap(arr, l, high);
    return high;
}

void quickSort(Pair arr[], int l, int r) {
    if (l <= r) {
        int pivot = divide(arr, l, r);
        quickSort(arr, l, pivot - 1);
        quickSort(arr, pivot + 1, r);
    }
}

int getDiff() {
    for (int i = 0; i < N; ++i) sorted[i].idx = i, sorted[i].value = tank[GND][i];
    quickSort(sorted, 0, N - 1);
    return sorted[N - 1].value - sorted[0].value;
}

void addFish() {
    for (int i = 0; i < N && sorted[i].value == sorted[0].value; ++i) {
        ++tank[GND][sorted[i].idx];
    }
}

void stackTank() {
    start = 0;
    tank[GND - 1][start + 1] = tank[GND][start];
    --height[start++];
    ++height[start];
    int cols = 1;

    while (height[start] <= N - start - cols) {
        int tmp = height[start];
        for (int i = 0; i < cols; ++i) {
            for (int j = 0; j < tmp; ++j) {
                tank[GND - cols + i][start + cols + j] = tank[GND - j][start + i];
                ++height[start + cols + j];
            }

            height[start + i] = 0;
        }

        start += cols;
        cols = tmp;
    }
}

void adjustFish() {
    memset(diff, 0, sizeof(diff));

    for (int i = GND - height[start] + 1; i <= GND; ++i) {
        for (int j = start; j < N && i >= GND - height[j] + 1; ++j) {
            if (j + 1 < N && i >= GND - height[j + 1] + 1) {
                int tmp = ABS(tank[i][j + 1] - tank[i][j]) / 5;
                if (tank[i][j] < tank[i][j + 1]) diff[i][j] += tmp, diff[i][j + 1] -= tmp;
                else diff[i][j] -= tmp, diff[i][j + 1] += tmp;
            }

            if (i + 1 <= GND) {
                int tmp = ABS(tank[i + 1][j] - tank[i][j]) / 5;
                if (tank[i][j] < tank[i + 1][j]) diff[i][j] += tmp, diff[i + 1][j] -= tmp;
                else diff[i][j] -= tmp, diff[i + 1][j] += tmp;
            }
        }
    }

    for (int i = GND - height[start] + 1; i <= GND; ++i) {
        for (int j = start; j < N && i >= GND - height[j] + 1; ++j) {
            tank[i][j] += diff[i][j];
        }
    }
}

void arrange() {
    int idx = 0;
    for (int i = start; i < N; ++i) {
        for (int j = GND; j > GND - height[i]; --j) {
            tank[GND][idx++] = tank[j][i];
        }
    }

    for (int i = 0; i < N; ++i) height[i] = 1;
    start = 0;
}

void stackTank2() {
    for (int i = 0; i < N / 2; ++i) {
        tank[GND - 1][N - i - 1] = tank[GND][i];
    }

    for (int i = 0; i < N / 4; ++i) {
        tank[GND - 2][N - i - 1] = tank[GND - 1][N / 2 + i];
        tank[GND - 3][N - i - 1] = tank[GND][N / 2 + i];
    }

    start = N / 4 * 3;
    for (int i = start; i < N; ++i) height[i] = 4;
}

int main() {
    scanf("%d %d", &N, &K);
    for (int i = 0; i < N; ++i) {
        scanf("%d", &tank[GND][i]);
        ++height[i];
    }

    while (getDiff() > K) {
        addFish();
        stackTank();
        adjustFish();
        arrange();
        stackTank2();
        adjustFish();
        arrange();
        ++ans;
    }

    printf("%d", ans);
    return 0;
}