#include <stdio.h>
int main(void)
{
	int category;
	int i;
	char ch;
	int bit, first = 0, second = 0, third = 0, result;
	int min1 =0, min2 = 0, min3 = 0;

choice :
	printf("1. 이진수 변환기     2. 이진수 덧셈기     3. 이진수 뺄셈기\n");
	printf("번호를 선택하세요 : ");
	scanf("%d", &category);
	getchar();   //버퍼 개행문자 방해 없앰

category_fir :
	if (category == 1) {
		printf("8비트 이진수를 입력하세요. : ");
		
		first = 0;
		for (i = 0; i <8; i++){
			ch = getchar();
			if (ch == '\n') continue;  //개행문자 들어갈시 무시
			if (ch != '0' && ch != '1') {
				printf("잘못된 입력.\n");  //오류 알림
				goto category_fir;  //다시 입력받게함
			}
			if (i == 0 && ch == '1') min1 =1;   //min1,2,3 변수는 부호비트가 1인 수일때 구분
		
			bit = ch - '0';
			first = first*2 + bit;
		}
			if (min1 == 1) {
				first = first - 256;  //2의 보수 전환
			}
		
		printf("십진수로 %d입니다.\n", first);
	}


	else if (category == 2 || category == 3) {
category_sec:
		printf("첫번째 8비트 이진수를 입력하세요. : " );
		second = 0;

		for (i = 0; i < 8; i++) {
			ch = getchar();
			if (ch == '\n') continue;
			if (ch != '0' && ch != '1') {
				printf("잘못된 입력. \n");
				goto category_sec;    //다시 입력받게함
			}
			if (i == 0 && ch == '1') min2 = 1;

			bit = ch - '0';
			second = second * 2  + bit;
		}	
			if (min2 == 1) second = second - 256;
			

		getchar ();    // 버퍼속 개행문자를 다음 과정에 방해 안되게함.

category_thi : 
		printf("두번째 8비트 이진수를 입력하세요. : ");
		third = 0;

		for (i=0; i <8; i++) {
			ch = getchar();
			if (ch == '\n') continue;
			if (ch != '0' && ch != '1') {
				printf("잘못된 입력.\n");
				goto category_thi;
			}
			if (i == 0 && ch == '1') min3 = 1;

			bit = ch - '0';
			third = third * 2 + bit;
		}
			if (min3 == 1) third = third - 256;
		
		if (category == 2) result = second + third;
		else result = second - third;

		int real = result; //결과 값 정수로 남김

		printf("결과는 이진수로 ");
		int bef = 128;
		int num = result;

		for (i=0; i < 8; i++) {
			if (num >= bef) {
				printf("1");
				num -= bef;
			}
			else printf("0");
			
			bef /= 2;
		}
		printf("이고, 십진수로 %d입니다.\n", real);	
	}
	else { 
		printf("잘못된 입력\n");
		goto choice;  //category 값이 1,2,3이 아닐경우 다시 입력받게함
	}
		return 0;
		}
