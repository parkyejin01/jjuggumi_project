// 2023-2 ������α׷��� ����: �޲ٹ� ����
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include "jjuggumi.h"

#define	DATA_FILE	"jjuggumi.dat"

//��Ʈ��
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
	printf("                                       �޲ٹ� ���ӿ� ���� ������ ȯ���մϴ�\n");
	printf("=====================================================================================================================\n");
	Sleep(2100);
	system("cls");

	printf("�̴ϰ��� ������");
	for (int i = 0; i < 5; i++)
	{
		printf(" . ");
		Sleep(100);
	}
	system("cls");
	printf("���ݺ��� ������ �����մϴ�\n");
	Sleep(500);
	system("cls");
}

void intro(void)
{
	intro_1();
	intro_2();
	intro_3();
}

// low �̻� high ���� ������ �߻���Ű�� �Լ�
int randint(int low, int high) {
	int rnum = rand() % (high - low + 1) + low;
	return rnum;
}

int jjuggumi_init(void) {
	srand((unsigned int)time(NULL));

	printf("�÷��̾� ��: ");
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