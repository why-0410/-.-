#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include"menu.h"
int main() {
	int nselection = -1;
	printf("\n");
	printf("计费管理系统\n");
	printf("\n");
	do{
	outputMenu();
	scanf("%d", &nselection);
	fflush(stdin);
		switch (nselection) {
		case 1: {
			add();
			break;
		}
		case 2: {
			query();
			break;
		}
		case 3: {
			printf("上机\n");
			break;
		}
		case 4: {
			printf("下机\n");
			break;
		}
		case 5: {
			printf("充值\n");
			break;
		}
		case 6: {
			printf("退费\n");
			break;
		}
		case 7: {
			printf("查询统计\n");
			break;
		}
		case 8: {
			printf("注销卡\n");
			break;
		}
		case 0: {
			printf("退出\n");
			break;
		}
		default: {
			printf("输入的菜单序号错误！请重新选择\n");
			break;
		}
		}
	} 
	while (nselection != 0);
	return 0;
}