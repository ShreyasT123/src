#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define N 4
#define MAX 100000

int rowMove[] = {-1, 1, 0, 0}; // Up, Down, Left, Right
int colMove[] = {0, 0, -1, 1};

typedef struct {
    int board[N][N];
    int row, col;
    int cost;   // total cost = level + manhattan
    int level;  // moves so far
} Node;

Node queue[MAX];
int front = 0, rear = 0;

char visited[MAX][1000];
int visitedCount = 0;

// Goal position lookup
int goalPos[16][2];

void printBoard(int b[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            printf("%2d ", b[i][j]);
        printf("\n");
    }
    printf("\n");
}

void boardToString(int b[N][N], char *s) {
    int pos = 0;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            pos += sprintf(&s[pos], "%d,", b[i][j]);
}

int alreadySeen(int b[N][N]) {
    char temp[1000];
    boardToString(b, temp);
    for (int i = 0; i < visitedCount; i++)
        if (strcmp(visited[i], temp) == 0)
            return 1;
    strcpy(visited[visitedCount++], temp);
    return 0;
}

int manhattan(int b[N][N]) {
    int dist = 0;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++) {
            int val = b[i][j];
            if (val != 0) {
                dist += abs(i - goalPos[val][0]) + abs(j - goalPos[val][1]);
            }
        }
    return dist;
}

void enqueue(Node n) {
    queue[rear++] = n;
}

Node dequeueMinCost() {
    int minIndex = front;
    for (int i = front + 1; i < rear; i++) {
        if (queue[i].cost < queue[minIndex].cost)
            minIndex = i;
    }
    Node res = queue[minIndex];
    for (int i = minIndex; i < rear - 1; i++)
        queue[i] = queue[i + 1];
    rear--;
    return res;
}

int isSolved(Node n) {
    return manhattan(n.board) == 0;
}

void solve(int init[N][N], int goal[N][N]) {
    // Map goal values to positions
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            goalPos[goal[i][j]][0] = i, goalPos[goal[i][j]][1] = j;

    Node start;
    memcpy(start.board, init, sizeof(start.board));
    start.level = 0;
    start.cost = manhattan(init);
    // Find blank
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            if (init[i][j] == 0)
                start.row = i, start.col = j;

    enqueue(start);
    alreadySeen(start.board);

    while (front < rear) {
        Node curr = dequeueMinCost();

        printf("Level: %d | Cost: %d\n", curr.level, curr.cost - curr.level);
        printBoard(curr.board);

        if (isSolved(curr)) {
            printf("Puzzle Solved!\n");
            return;
        }

        for (int d = 0; d < 4; d++) {
            int nr = curr.row + rowMove[d];
            int nc = curr.col + colMove[d];
            if (nr < 0 || nr >= N || nc < 0 || nc >= N)
                continue;

            Node next = curr;
            next.board[curr.row][curr.col] = next.board[nr][nc];
            next.board[nr][nc] = 0;
            next.row = nr;
            next.col = nc;
            next.level = curr.level + 1;
            next.cost = manhattan(next.board) + next.level;

            if (!alreadySeen(next.board))
                enqueue(next);
        }
    }
    printf("No solution found.\n");
}

int main() {
    int init[N][N] = {
        {1, 2, 3, 4},
        {5, 6, 0, 8},
        {9, 10, 7, 12},
        {13, 14, 11, 15}
    };

    int goal[N][N] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 0}
    };

    printf("Initial State:\n");
    printBoard(init);
    printf("Goal State:\n");
    printBoard(goal);

    solve(init, goal);
    return 0;
}
