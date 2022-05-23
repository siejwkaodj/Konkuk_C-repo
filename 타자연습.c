#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>
#include <string.h>
#include <conio.h>
#define SIZE 6
#define TIME_LIMIT 5
void show_string(char*);

int main(void)
{
	int st, index = 0;
	char word[SIZE], user[SIZE], ch;
	srand((unsigned)time(NULL));
	
	st = time(0);
	show_string(word);
	printf("%s\n", word);
	while (1) {
		if (index == SIZE - 1 || time(0) >= st + TIME_LIMIT) {
			// 유저 입력 마지막에 null문자 할당
			user[SIZE - 1] = '\0';
			if (index == SIZE - 1 && !strcmp(word, user)) {
				printf("\n축하합니다\n");
				Sleep(1000);
			}
			// 시간초기화, 화면 초기화, 문자열 다시할당, 문자열 출력, index 초기화 부분
			st = time(0);
			system("cls");
			show_string(word);	// 랜덤 문자 할당
			printf("%s\n", word);
			index = 0;
		}

		// 사용자 입력 받는 부분
		if (_kbhit()) {
			ch = _getch();
			if (ch == 27)	// esc 종료
				break;
			// backspace키를 입력받았을 때 index > 0이면 글자를 하나 지우고,
			// 사용자 입력 배열에서 마지막 문자를 지움.
			else if (ch == '\b' && index > 0) {
				user[index] = '\0';
				printf("\b \b");
				index--;
			}
			// 영어 대소문자 범위 안의 수일 경우에만 입력을 받음
			else if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z')) {
				user[index] = ch;
				printf("%c", ch);
				index++;
			}
		}
	}


	return 0;
}

void show_string(char* w) {
	// 현재 시간 저장
	int temp = 0;
	for (int i = 0; i < SIZE - 1; i++) {
		temp = rand() % 2;
		w[i] = rand() % 26 + 'a';
		// 대문자 추가부분. 50% 확률로 대문자 추가.
		if (temp) {
			w[i] += 'A' - 'a';
		}
	}	
	w[SIZE - 1] = '\0';
	return;
}