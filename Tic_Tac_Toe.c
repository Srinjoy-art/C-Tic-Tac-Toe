
#include <stdio.h>

char board[3][3];

void initializeBoard() {
    char position = '1';

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            board[i][j] = position++;
        }
    }
}

void displayBoard() {
    printf("\n");

    for (int i = 0; i < 3; i++) {
        printf(" %c | %c | %c \n",
               board[i][0], board[i][1], board[i][2]);

        if (i < 2) {
            printf("---+---+---\n");
        }
    }

    printf("\n");
}

int checkWinner() {
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == board[i][1] &&
            board[i][1] == board[i][2]) {
            return 1;
        }

        if (board[0][i] == board[1][i] &&
            board[1][i] == board[2][i]) {
            return 1;
        }
    }

    if (board[0][0] == board[1][1] &&
        board[1][1] == board[2][2]) {
        return 1;
    }

    if (board[0][2] == board[1][1] &&
        board[1][1] == board[2][0]) {
        return 1;
    }

    return 0;
}

int main() {
    int position;
    int moves = 0;
    char player = 'X';
    char playAgain;

    do {
        initializeBoard();
        moves = 0;
        player = 'X';

        while (moves < 9) {
            displayBoard();

            printf("Player %c, enter position (1-9): ", player);

            if (scanf("%d", &position) != 1) {
                printf("Invalid input! Enter a number.\n");

                while (getchar() != '\n');
                continue;
            }

            if (position < 1 || position > 9) {
                printf("Invalid position! Choose 1 to 9.\n");
                continue;
            }

            int row = (position - 1) / 3;
            int col = (position - 1) % 3;

            if (board[row][col] == 'X' ||
                board[row][col] == 'O') {
                printf("Position already occupied! Try again.\n");
                continue;
            }

            board[row][col] = player;
            moves++;

            if (checkWinner()) {
                displayBoard();
                printf("Player %c wins!\n", player);
                break;
            }

            if (player == 'X') {
                player = 'O';
            } else {
                player = 'X';
            }
        }

        if (moves == 9 && !checkWinner()) {
            displayBoard();
            printf("It's a draw!\n");
        }

        printf("\nPlay again? (y/n): ");
        scanf(" %c", &playAgain);

    } while (playAgain == 'y' || playAgain == 'Y');

    printf("\nThanks for playing!\n");

    return 0;
}
