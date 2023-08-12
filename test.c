//#include<stdio.h>
#include"game.h"
void menu() {
	printf("****************************\n");
	printf("****************************\n");
	printf("*****1.play  0.exit*********\n");
	printf("****************************\n");
}
void game() {
	char ret = 0;
	char board[ROW][COL] = { 0 };
	//初始化棋盘函数
	InitBoard(board, ROW, COL);
	DisplayBoard(board, ROW, COL);
	//下棋
	while (1) {
		PlayerMove(board, ROW, COL);
		ret = IsWin(board, ROW, COL);
		if (ret != 'c')
			break;
		DisplayBoard(board, ROW, COL);
		//输赢判断

		ComputerMove(board, ROW, COL);
		ret = IsWin(board, ROW, COL);
		if (ret != 'c')
			break;
		DisplayBoard(board, ROW, COL);
		//输赢判断
	}
	if (ret == '*') {
		printf("玩家win,恭喜你 2333333\n");
	}
	else if (ret == '#') {
		printf("电脑win 傻逼，人工智能\n");
	}else {
		printf("平局\n");

	}
	DisplayBoard(board, ROW, COL);


	}
	

int main(){
	int input=0;
	srand((unsigned int)time(NULL));//设置随机数
	do {

		menu();
		printf("请选择:>");
			scanf_s("%d", &input);
			switch (input) {
			case 1:
				game();
				break;
			case 0:
				printf("退出游戏\n");
				break;
			default:
				printf("傻逼，重选\n");
				break;
			
			}

	} while (input);

	return 0;
}