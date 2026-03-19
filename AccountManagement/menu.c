#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<time.h>
#include "model.h"
#include"card_service.h"
#include "tool.h"
int getSize(const char* pinfo);
void copy(const char aInput[], char aOutput[], int nSize);
void outputMenu() {
	printf("----------菜单----------\n");
	printf("1.添加卡\n2.查询卡\n3.上机\n4.下机\n5.充值\n6.退费\n7.查询统计\n8.注销卡\n0.退出\n");
	printf("请选择菜单项编号（0~8）:");
}
void add() {		//添加卡功能
	struct Card card;
	struct tm* Starttime;
	struct tm* Endtime;
	char aName[32] = { '\0' };
	char aPwd[20] = { '\0' };
	int nNameSize = 0;
	int  nPwdSize = 0;
	printf("----------添加卡----------\n");
	printf("请输入卡号（0~18）：");
	scanf("%s", aName);
	printf("请输入密码（0~8）：");
	scanf("%s", aPwd);
	while (getchar() != '\n');
					//判断卡号或者密码长度
	nNameSize = getSize(aName);
	nPwdSize = getSize(aPwd);
	if (nNameSize > 18) {
		printf("卡号超过规定长度\n");
		return;
	}

	if (nPwdSize > 8) {
		printf("密码超过规定长度\n");
		return;
	}
	// 检查卡号是否已存在
	if (queryCard(aName) != NULL) {
		printf("卡号已存在，请使用其他卡号。\n");
		return;
	}
	// 检查密码是否已被其他卡使用
	if (isPwdExist(aPwd) == 1) {
		printf("该密码已被其他卡使用，请更换密码。\n");
		return;
	}
					//将按规定输入的正确密码保存到结构体中保存信息
	copy(aName, card.aName, nNameSize);
	copy(aPwd, card.aPwd, nPwdSize);
		printf("请输入开卡金额：");
		scanf(" %f", &card.fBalance);
		while (getchar() != '\n');
		if (card.fBalance < 0) {
			printf("输入金额不能为负数，请重新输入！\n");
			return;
		}
		card.fTotalUse = card.fBalance;//累计金额
		card.nUseCount = 0;//删除标识
		card.nStatus = 0;//卡状态
		card.nDel = 0;//使用次数
		card.tStart = card.tEnd = card.tLast = time(NULL);//开卡时间，截止时间，最后使用时间
		Starttime = localtime(&card.tStart);//开卡时间
		Endtime = localtime(&card.tEnd);//卡失效时间
		Endtime->tm_year = Starttime->tm_year + 1;
		card.tEnd = mktime(Endtime);
		addCard(card);
		printf("\n");
		printf("------------------添加的卡信息如下------------------\n");
		printf("+-----------------+----------+--------+------------+\n");
		printf("| %-15s | %-8s | %-6s | %-10s |\n", "卡号", "密码", "卡状态", "开卡金额");
		printf("+-----------------+----------+--------+------------+\n");
		printf("| %-15s | %-8s | %-6d | %-10.1f |\n",card.aName,card.aPwd,card.nStatus,card.fBalance);
	    printf("+-----------------+----------+--------+------------+\n");
	}
int getSize(const char* pinfo) {
	int nSize = 0;
	while (*(pinfo + nSize) != '\0') {
		nSize++;
	}
	return nSize;
}
void copy(const char aInput[],char aOutput[], int nSize) {
	int i;
	for (i = 0; i < nSize; i++) {
		aOutput[i] = aInput[i];
	}
	aOutput[nSize] = '\0';
}
void query() {
	char aName[18] = {0};
	char aTime[20] = {0};
	Card* pCard = NULL;
	printf("请输入查询的卡号：");
	scanf("%s", aName);
	pCard = queryCard(aName);
	if (pCard != NULL) {
		timeToString(pCard->tLast, aTime);
		printf("----------------------查询到的用户卡信息如下------------------------\n");
		printf("+----------+------+-------+-----------+----------+--------------------+\n");
		printf("| %-8s | %-4s | %-5s | %-9s | %-8s | %-18s |\n", "卡号", "状态", "余额",
			"累计使用", "使用次数", "上次使用时间");
		printf("+----------+------+-------+-----------+----------+--------------------+\n");
		printf("| %-8s | %-4d | %-5.1f | %-9.1f | %-8d | %-18s |\n", pCard->aName, pCard->nStatus,
			pCard->fBalance, pCard->fTotalUse, pCard->nUseCount, aTime);
		printf("+----------+------+-------+-----------+----------+--------------------+\n");
	}
	else
		printf("未找到相关用户,请重新输入\n");
}