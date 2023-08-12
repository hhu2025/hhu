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
	//��ʼ�����̺���
	InitBoard(board, ROW, COL);
	DisplayBoard(board, ROW, COL);
	//����
	while (1) {
		PlayerMove(board, ROW, COL);
		ret = IsWin(board, ROW, COL);
		if (ret != 'c')
			break;
		DisplayBoard(board, ROW, COL);
		//��Ӯ�ж�

		ComputerMove(board, ROW, COL);
		ret = IsWin(board, ROW, COL);
		if (ret != 'c')
			break;
		DisplayBoard(board, ROW, COL);
		//��Ӯ�ж�
	}
	if (ret == '*') {
		printf("���win,��ϲ�� 2333333\n");
	}
	else if (ret == '#') {
		printf("����win ɵ�ƣ��˹�����\n");
	}else {
		printf("ƽ��\n");

	}
	DisplayBoard(board, ROW, COL);


	}
	

int main(){
	int input=0;
	srand((unsigned int)time(NULL));//���������
	do {

		menu();
		printf("��ѡ��:>");
			scanf_s("%d", &input);
			switch (input) {
			case 1:
				game();
				break;
			case 0:
				printf("�˳���Ϸ\n");
				break;
			default:
				printf("ɵ�ƣ���ѡ\n");
				break;
			
			}

	} while (input);

	return 0;
}