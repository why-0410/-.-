#include"model.h"
#include<string.h>
#include"global.h"
Card aCard[50];//卡信息存放数组
int nCount = 0;//实际卡数目
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
}