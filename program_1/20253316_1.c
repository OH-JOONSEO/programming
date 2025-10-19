#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct information {
    char name[10];
    int id;
    float height;
};

struct list {
    char name_a[10];
    char id_a[10];
    char height_a[10];
    struct information student[20];
};

struct list ifm = {
    "이름", "아이디", "키", {
        {"Sophia", 20220001, 153.1}, {"Olivia", 20220010, 158.5},
        {"Riley", 20220002, 163.0}, {"Emma", 20220015, 160.3},
        {"Ava", 20220009, 155.6}, {"Isabella", 20220014, 168.8},
        {"Aria", 20220020, 150.2}, {"Amelia", 20220005, 162.5},
        {"Mia", 20220016, 170.2}, {"Liam", 20220008, 180.9},
        {"Noah", 20220012, 174.9}, {"Jackson", 20220004, 191.1},
        {"Aiden", 20220018, 188.8}, {"Elijah", 20220017, 169.7},
        {"Grayson", 20220003, 174.2}, {"Lucas", 20220013, 188.7},
        {"Oliver", 20220007, 170.5}, {"Caden", 20220019, 173.3},
        {"Mateo", 20220011, 169.9}, {"David", 20220006, 188.8}
    }
};

void sort_name();
void sort_id();
void sort_height();
void search_name();

int cmp_name(const void *a, const void *b) {
    return strcmp(((struct information*)a)->name,
                  ((struct information*)b)->name);
}

int cmp_id(const void *a, const void *b) {
    return ((struct information*)a)->id - ((struct information*)b)->id;
}

int cmp_height(const void *a, const void *b) {
    float h1 = ((struct information*)a)->height;
    float h2 = ((struct information*)b)->height;
    if (h1 < h2) return 1;
    if (h1 > h2) return -1;
    return 0;
}

int main(void) {
    int select;
    while (1) {
        printf("1. 이름 오름차순 출력          2. 아이디 오름차순 출력\n");
        printf("3. 키 내림차순 출력            4. 이름검색\n");
        printf("5. 종료\n\n번호를 선택하세요 : ");
        scanf("%d",&select);

        if (select == 1) sort_name();
        else if (select == 2) sort_id();
        else if (select == 3) sort_height();
        else if (select == 4) search_name();
        else if (select == 5) break;
        else printf("잘못된 입력입니다.\n");
		printf("\n\n");

    }
    return 0;
}

void sort_name() {
    qsort(ifm.student, 20, sizeof(struct information), cmp_name);
    printf("\n%-10s %-10s %-10s\n", ifm.name_a, ifm.id_a, ifm.height_a);
    for (int i = 0; i < 20; i++)
        printf("%-10s %-10d %-10.1f\n",
               ifm.student[i].name,
               ifm.student[i].id,
               ifm.student[i].height);
}

void sort_id() {
    qsort(ifm.student, 20, sizeof(struct information), cmp_id);
    printf("\n%-10s %-10s %-10s\n", ifm.name_a, ifm.id_a, ifm.height_a);
    for (int i = 0; i < 20; i++)
        printf("%-10s %-10d %-10.1f\n",
               ifm.student[i].name,
               ifm.student[i].id,
               ifm.student[i].height);
}

void sort_height() {
    qsort(ifm.student, 20, sizeof(struct information), cmp_height);
    printf("\n%-10s %-10s %-10s\n", ifm.name_a, ifm.id_a, ifm.height_a);
    for (int i = 0; i < 20; i++)
        printf("%-10s %-10d %-10.1f\n",
               ifm.student[i].name,
               ifm.student[i].id,
               ifm.student[i].height);
}

void search_name() {
    char search[10];
    printf("검색할 이름을 입력하세요 : ");
    scanf("%s", search);

    for (int i = 0; i < 20; i++) {
        if (strcmp(ifm.student[i].name, search) == 0) {
            printf("\n%-10s %-10s %-10s\n", ifm.name_a, ifm.id_a, ifm.height_a);
            printf("%-10s %-10d %-10.1f\n",ifm.student[i].name, ifm.student[i].id, ifm.student[i].height);
            return;
        }
    }
    printf("해당 이름이 존재하지 않습니다.\n");
}

