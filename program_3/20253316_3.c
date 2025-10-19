#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <termio.h>
#define A 5
#define N 6
int getch(void) {
    int ch;
    struct termios buf;
    struct termios save;

    tcgetattr(0, &save);
    buf = save;
    buf.c_lflag &= ~(ICANON | ECHO);
    buf.c_cc[VMIN] = 1;
    buf.c_cc[VTIME] = 0;
    tcsetattr(0, TCSAFLUSH, &buf);
    ch = getchar();
    tcsetattr(0, TCSAFLUSH, &save);
    return ch;
}

void clear_screen() {
    system("clear");
}

int main(void)
{
    int lotto[A][N] =
        {
        {1, 2, 3, 4, 5, 6},
        {10, 15, 25, 35, 40, 42},
        {1, 9, 11, 22, 23, 25},
        {9, 28, 31, 34, 35, 36},
        {1, 9, 23, 28, 33, 35}
    };
    int my[N], bonus;

    clear_screen();
    printf("로또 당첨을 기원합니다.\n");
    printf("프로그램을 로딩 중입니다.\n");
    sleep(2);
    clear_screen();
    printf("일반 번호를 입력하세요 : ");
    for (int i = 0; i < N; i++) {
        scanf("%d", &my[i]);
    }
    printf("보너스 번호를 입력하세요 : ");
    scanf("%d", &bonus);
    sleep(2);
    clear_screen();
    printf("로또 당첨 결과는 다음과 같습니다.\n\n");

    for (int i = 0; i < A; i++) {
        int hit = 0, bonus_game = 0;

        printf("%d세트 번호 (", i + 1);
        for (int j = 0; j < N; j++) {
            printf("%d", lotto[i][j]);
            if (j < N - 1) printf(" ");
        }
        printf(") -> ");

        for (int j = 0; j < N; j++) {
            int bingo = 0;
            for (int k = 0; k < N; k++) {
                if (lotto[i][j] == my[k]) {
                    bingo = 1;
                    hit++;
                    break;
                }
            }
            if (bingo)
                printf("%d ", lotto[i][j]);
            else
                printf("X ");
        }
        if (hit == 6)
            printf("(1등 당첨)");
        else if (hit == 5) {
            for (int j = 0; j < N; j++) {
                if (lotto[i][j] == bonus) {
                    bonus_game = 1;
                    break;
                }
            }
            if (bonus_game)
                printf("(2등 당첨)");
            else
                printf("(3등 당첨)");
        } else if (hit == 4)
            printf("(4등 당첨)");
        else if (hit == 3)
            printf("(5등 당첨)");
        else
            printf("(낙첨)");

        printf("\n\n");
    }
    printf("프로그램을 종료하시려면 esc 키를 누르세요.\n");

ESC:
    int esc = getch();
    if (esc == 27) {
        clear_screen();
    } else {
        goto ESC;
    }

    return 0;
}

