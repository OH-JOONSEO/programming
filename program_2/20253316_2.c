#include <stdio.h>

int main(void) {
    long long BASE = 1000000000000000LL;
    int doing = 1;

    while (doing) {
        int c, a = 0, b = 0, plus = 0, fail = 0;
        long long num1 = 0, num2 = 0, num3 = 0, num4 = 0;
        long long num5 = 0, num6 = 0;

        printf("수식 : ");
        while ((c = getchar()) != '\n' && c >= 0) {
            if (c >= '0' && c <= '9') {
                if (!plus) {
                    if (a < 15)      num1 = num1*10 + (c-'0');
                    else if (a < 30) num2 = num2*10 + (c-'0');
                    a++;
                } else {
                    if (b < 15)      num3 = num3*10 + (c-'0');
                    else if (b < 30) num4 = num4*10 + (c-'0');
                    b++;
                }
            } else if (c == '+') {
                if (plus || fail) fail = 1;
                else plus = 1;
            } else if (c != ' ' && c != '\t') {
                fail = 1;
            }
        }

        if (fail || !plus) {
            printf("결과 : 잘못된 연산자입니다.\n");
        } else {
            num6 = num2 + num4;
            if (num6 >= BASE) {
                num6 -= BASE;
                num5 = num1 + num3 + 1;
            } else {
                num5 = num1 + num3;
            }

            if (num5 >= BASE) {
                printf("결과 : 오버플로우가 발생했습니다.\n");
            } else {
                long long t = num5;
                int numnum = 1;
                while (t >= 10) { t /= 10; numnum++; }
                int total_num = numnum + 15;
                int remain = total_num;

                long long cal = 1;
                for (int i = 1; i < numnum; i++) cal *= 10;
                for (int i = 0; i < numnum; i++) {
                    int digit = (num5 / cal) % 10;
                    printf("%d", digit);
                    remain--;
                    if (remain > 0 && remain % 3 == 0) printf(",");
                    cal /= 10;
                }

                cal = 1000000000000000LL / 10;
                for (int i = 0; i < 15; i++) {
                    int digit = (num6 / cal) % 10;
                    printf("%d", digit);
                    remain--;
                    if (remain > 0 && remain % 3 == 0) printf(",");
                    cal /= 10;
                }
                printf("\n");
            }
        }

        while (1) {
            char choice;
            printf("계속 하시겠습니까? ");
            choice = getchar();
            while (getchar() != '\n');
            if (choice == 'y') break;
            if (choice == 'n') {
                doing = 0;
                break;
            }
        }
    }
    return 0;
}

