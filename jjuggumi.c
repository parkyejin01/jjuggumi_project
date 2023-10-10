// 2023-2 고급프로그래밍 과제: 쭈꾸미 게임
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include "jjuggumi.h"

#define	DATA_FILE	"jjuggumi.dat"

//인트로
void intro_1(void);
void intro_2(void);
void intro_3(void);
void intro(void);
//
int jjuggumi_init(void);


void intro_1(void)
{
	system("cls");
	printf("             .;!!;!;,=#@#=*#@$                  \n");
	printf("           #!    ,#=.         -@                \n");
	printf("          $     #,              #.              \n");
	printf("           #    @                 !,            \n");
	printf("           ~@@@@                   #            \n");
	printf("              ,-             #      =           \n");
	printf("              @                     =           \n");
	printf("    ====      ~         #    =,     ;           \n");
	printf("             .,            ,,=      ~           \n");
	printf(" ======      ,,                     *           \n");
	printf("          .:=**,                    #$          \n");
	printf("        ~@,     !@*                .-!          \n");
	printf("       ~,          =:              @ ,.         \n");
	printf("       @             @            #@$=          \n");
	printf("       @      .       =.             -#         \n");
	printf("        #@#=~,.-$@;    $               #        \n");
	printf("                   ~@,  ;              ~        \n");
	printf("   =========         ,,                 :       \n");
	printf("                     #                  ;       \n");
	printf("                     !       !    ;    -        \n");
	printf("=========            !      =     =    #        \n");
	printf("                     *.    ;@     #, .@         \n");
	printf("                      :@*;@, @*;$= ,$~          \n");
	Sleep(500);
	system("cls");
}

void intro_2(void)
{
	printf("         .~:~-.                                   \n");
	printf("       =$~....-*#,                                \n");
	printf("     ;=          !=                               \n");
	printf("    !:            .$              ;#=!*#~         \n");
	printf("   !~              ,!          .$$.     ;:!$######\n");
	printf("   =                $        ,#;         $        \n");
	printf("  =                 .;      #:           *        \n");
	printf("  #                  #    **      $      *,       \n");
	printf(" .;                  =  ,#.      *@      #,       \n");
	printf(" :              ~.   : :*       @.!~    ;;        \n");
	printf(" =       ==    / !   !;;      =@   :@$##~         \n");
	printf(" !      /  *         *:    ,$*:-                  \n");
	printf(" ~          . ~      #   .#:  #                   \n");
	printf(" .:          $/     .!  ;*   !.                   \n");
	printf("  #                 #  $-    @   @.               \n");
	printf("  #                 #  $-    @   @.               \n");
	printf("   @              ,# @      *   @,@,              \n");
	printf("   .#               #       #   -#~               \n");
	printf("    .#*            ,@       =           ,=:,      \n");
	printf("    :*.              =     .:   ,           =@@##-\n");
	printf("   ,!                #     --   ,,          ,=,.@,\n");
	printf("   #           #     $     ~,  *.*           !!#,,\n");
	printf("   #    =,     @#*. $.     :,  $.#            -,,,\n");
	printf("   @   ,*#     *  ,-       ~,                     \n");
	printf("   .@@#= ,@. -@            ,~                     \n");
	printf("           ~:,              *                     \n");
	Sleep(500);
	system("cls");
}

void intro_3(void)
{
	printf("=====================================================================================================================\n");
	printf("      ##       ##    ##  #    #####    #####    ##  #    ##  #      ##              #####     ###     ##  #    ##### \n");
	printf("     ##       ##    ##  ##   ##       ##       ##  ##   ### ##     ##              ##       ### ##   ### ##   ##     \n");
	printf("     ##       ##    ##  ##   ##       ##       ##  ##   ######     ##              ##       ##  ##   ######   ##     \n");
	printf(" #  ##    #  ##    ##  ##   ### ##   ### ##   ##  ##   ##  ##     ##              ### ##   ######   ##  ##   #####   \n");
	printf("##  ##   ##  ##    #   ##   ##  ##   ##  ##   #   ##   ##  ##     ##              ##  ##   ##  ##   ##  ##   ##      \n");
	printf("## ##    ## ##    ##  ##   ##  ##   ##  ##   ##  ##   ##  ##     ##              ##  ##   ##  ##   ##  ##   ##       \n");
	printf("#####    #####    ######   ######   ######   ######   ##  ##     ##              ######   ##  ##   ##  ##   ######   \n");
	printf("=====================================================================================================================\n");
	printf("                                       쭈꾸미 게임에 오신 여러분 환영합니다\n");
	printf("=====================================================================================================================\n");
	Sleep(2100);
	system("cls");

	printf("미니게임 생성중");
	for (int i = 0; i < 5; i++)
	{
		printf(" . ");
		Sleep(100);
	}
	system("cls");
	printf("지금부터 게임을 시작합니다\n");
	Sleep(500);
	system("cls");
}

void intro(void)
{
	intro_1();
	intro_2();
	intro_3();
}

// low 이상 high 이하 난수를 발생시키는 함수
int randint(int low, int high) {
	int rnum = rand() % (high - low + 1) + low;
	return rnum;
}

int jjuggumi_init(void) {
	srand((unsigned int)time(NULL));

	printf("플레이어 수: ");
	scanf_s("%d", &n_player);

	n_alive = n_player;
	for (int i = 0; i < n_player; i++) {
		player[i] = true;
	}
	return 0;
}

int main(void) {
	jjuggumi_init();
	intro();
	//sample();
	mugunghwa();
	//nightgame();
	//juldarigi();
	//jebi();
	ending();
	return 0;
}