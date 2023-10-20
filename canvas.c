#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include "jjuggumi.h"
#include "canvas.h"

#define DIALOG_DURATION_SEC		4

char rmb_buf[ROW_MAX][COL_MAX];

void end_win(void);
void end_no_win(void);

void end_win(void)
{
	printf("===========================================================================\n");
	printf("       ~$:          #-  .=         *,!;           \n");
	printf("      .* ;~        -~!- =.*       ~~ .*           \n");
	printf("      .!  $.    .  ~. =$  :       #  =,           \n");
	printf("       !  ,~    *!!*      ~.      ..*-            \n");
	printf("       -!  *     ! .      -:      *               \n");
	printf("         ;~.     $.-:;!!!!!!!!:,                  \n");
	printf("              *.                 *                \n");
	printf("            .*-                    :~    .,~;;    \n");
	printf("   .!-      :-                      $  $#=!-      ##    ##    ##    ###  ##\n");
	printf("  .$-:!~   ,*               ,       *.            ## ## ##    ##     ### ##\n");
	printf("  .$   ;;  ;-        .      #!      --            ##  ## #    ##    # #####\n");
	printf("   ,=~  :  *         #!             ,~             ## ##      ##    ## ####\n");
	printf("    .;***~ !          . ~##=\'       .:             ## ##      ##    ##  ###\n");
	printf("           *            *##/        .:             ##  ##     ##    ##   ##\n");
	printf("            *                       ,:~:;-        \n");
	printf("         .::*:.                    :;     :~      \n");
	printf("        -                                 ;       \n");
	printf("       !       ;                    =.  ~:-       \n");
	printf("       ;,      *                    $ ,,,,;       \n");
	printf("         ~$==~ ,:                    ~#           \n");
	printf("          *,. .$.     -      -,       !.          \n");
	printf("              $.      #,     ;-       ~,          \n");
	printf("             .!      -*~    .#!:     ,*           \n");
	printf("              *.;!*,,* *-.,.!- ~$*::;=            \n");
}

void end_no_win(void)
{
	printf("###  ##   ## ##            ## ## ##    ##    ###  ##  ###  ##  ## ###   ## ####\n");
	printf(" ### ##  ### ###           ## ## ##    ##     ### ##   ### ##  ##       ##   ##\n");
	printf("# #####  ##   ##           ##  ## #    ##    # #####  # #####  ## ###   ## ####\n");
	printf("## ####  ##   ##            ## ##      ##    ## ####  ## ####  ## ###   ## ### \n");
	printf("##  ###  ### ###            ## ##      ##    ##  ###  ##  ###  ##       ##    #\n");
	printf("##   ##   ## ##             ##  ##     ##    ##   ##  ##   ##  ## ###   ##   ## \n");
}

void ending(void)
{
	system("cls");
	if (n_alive >= 2)
	{
		printf("우승자를 가리지 못했습니다. \n");
		printf("===============================================================================\n");
		printf("player ");
		int k = 1;
		for (int p = 0; p < n_player; p++)
		{
			if (player[p] == true)
			{
				printf("%d", p);
				if (k < n_alive)
				{
					printf(", ");
				}
				k++;
			}
		}
		printf(" alive\n\n");
		end_no_win();
	}
	else
	{
		printf("우승자가 나왔습니다!\n");
		printf("===========================================================================\n");
		printf("우승자는 player ");
		for (int p = 0; p < n_player; p++)
		{
			if (player[p] == true)
			{
				printf("%d", p);
			}
		}
		printf(" 입니다! Congratulations~~!\n");
		end_win();
	}

	exit(0);
}

// (zero-base) row행, col열로 커서 이동
void gotoxy(int row, int col) {
	COORD pos = { col,row };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

// row행, col열에 ch 출력
void printxy(char ch, int row, int col) {
	gotoxy(row, col);
	printf("%c", ch);
}

void map_init(int n_row, int n_col) {
	// 두 버퍼를를 완전히 비우기
	for (int i = 0; i < ROW_MAX; i++) {
		for (int j = 0; j < COL_MAX; j++) {
			back_buf[i][j] = front_buf[i][j] = ' ';
		}
	}

	N_ROW = n_row;
	N_COL = n_col;
	for (int i = 0; i < N_ROW; i++) {
		// 대입문 이렇게 쓸 수 있는데 일부러 안 가르쳐줬음
		back_buf[i][0] = back_buf[i][N_COL - 1] = '*';

		for (int j = 1; j < N_COL - 1; j++) {
			back_buf[i][j] = (i == 0 || i == N_ROW - 1) ? '*' : ' ';
		}
	}
}

// back_buf[row][col]이 이동할 수 있는 자리인지 확인하는 함수
bool placable(int row, int col) {
	if (row < 0 || row >= N_ROW ||
		col < 0 || col >= N_COL ||
		back_buf[row][col] != ' ') {
		return false;
	}
	return true;
}

// 상단에 맵을, 하단에는 현재 상태를 출력
void display(void) {
	draw();
	gotoxy(N_ROW + 4, 0);  // 추가로 표시할 정보가 있으면 맵과 상태창 사이의 빈 공간에 출력
	print_status();
}

void draw(void) {
	for (int row = 0; row < N_ROW; row++) {
		for (int col = 0; col < N_COL; col++) {
			if (front_buf[row][col] != back_buf[row][col]) {
				front_buf[row][col] = back_buf[row][col];
				printxy(front_buf[row][col], row, col);
			}
		}
	}
}

void print_status(void) {
	printf("no. of players left: %d\n", n_alive);
	for (int p = 0; p < n_player; p++) {
		printf("player %2d: %5s\n", p, player[p] ? "alive" : "DEAD");
	}
}

void dialog(char message[]) {

}

void dialog_mgh(char message[])
{
	int k = 0;
	if (bye >= 16)
	{
		k += 24;
	}
	else if (bye >= 12)
	{
		k += 16;
	}
	else if (bye >= 8)
	{
		k += 8;
	}


	for (int i = 0; i < ROW_MAX; i++) {
		for (int j = 0; j < COL_MAX; j++) {
			rmb_buf[i][j] = back_buf[i][j];
		}
	}

	for (int i = 3; i < 8; i++) {
		for (int j = 5; j < 30 + k; j++) {
			back_buf[i][j] = ' ';
		}
	}

	for (int i = 3; i < 8; i++) {
		back_buf[i][5] = back_buf[i][29 + k] = '*';

		for (int j = 6; j < 29 + k; j++) {
			back_buf[i][j] = (i == 3 || i == 7) ? '*' : ' ';
		}
	}

	for (int i = 3; i < 8; i++) {
		for (int j = 5; j < 30 + k; j++) {
			gotoxy(i, j);
			printf("%c", back_buf[i][j]);
		}
	}


	for (int i = DIALOG_DURATION_SEC; i > 0; i--)
	{
		gotoxy(5, 7);
		printf("%d player ", i);

		for (int j = 0; j <= bye - 2; j++)
		{
			printf("%c", message[j]);
			if (j % 2 == 1)
			{
				printf(" ");
			}
		}
		printf(" dead!");


		Sleep(1000);
	}

	for (int i = 0; i < ROW_MAX; i++) {
		for (int j = 0; j < COL_MAX; j++) {
			back_buf[i][j] = rmb_buf[i][j];
		}
	}

	for (int i = 3; i < 8; i++) {
		for (int j = 5; j < 30 + k; j++) {
			gotoxy(i, j);
			printf("%c", back_buf[i][j]);
		}
	}

}