#include"model.h"
#include<string.h>
#include"global.h"
Card aCard[50];//卡信息存放数组
int nCount = 0;//实际卡数目
//添加新用户时先检查密码是否已存在
int isPwdExist(const char* pPwd) {
	int i;
	for (i = 0; i < nCount; i++) {
		if (strcmp(pPwd, aCard[i].aPwd) == 0) {
			return TURE;
		}
	}
	return FALAE;
}
//添加新用户卡号信息
int addCard(Card card) {
	int i;
	// 检查重复卡号或重复密码
	for (i = 0; i < nCount; i++) {
		if (strcmp(card.aName, aCard[i].aName) == 0) {
			// 卡号重复
			return FALAE;
		}
		if (strcmp(card.aPwd, aCard[i].aPwd) == 0) {
			// 密码重复
			return FALAE;
		}
		aCard[nCount] = card;
		nCount++;
		return TURE;
		// 检查用户是否已达到上限
		if (nCount >= (int)(sizeof(aCard) / sizeof(aCard[0]))) {
			return FALAE;
		}
		aCard[nCount++] = card;
		return TURE;
	}
}
//添加新用户卡号信息
int addCard(Card card) {
	aCard[nCount] = card;
	nCount++;
	return TURE;
}
//查找输入的卡用户
Card* queryCard(const char* pName) {
	int i = 0;
	for (i = 0; i < nCount; i++) {
		if (strcmp(pName, aCard[i].aName) == 0) {
			return &aCard[i];
		}
	}
	return NULL;
}
