#include"model.h"
#include<string.h>
#include<stdlib.h>
#include"global.h"
Card aCard[50];//卡信息存放数组
int nCount = 0;//实际卡数目
lpCardNode cardList = NULL;
//初始化链表
int initCardList() {
	lpCardNode head = (lpCardNode)malloc(sizeof(CardNode));
	head=(lpCardNode)malloc(sizeof(CardNode));
	if (head != NULL) {
		head->next = NULL;
		cardList = head;
		return TURE;
	}
	return FALSE;
}
//添加新用户时先检查新设置密码是否已存在
int isPwdExist(const char* pPwd) {
	int i;
	for (i = 0; i < nCount; i++) {
		if (strcmp(pPwd, aCard[i].aPwd) == 0) {
			return TURE;
		}
	}
	return FALSE;
}
//添加新用户卡号信息
int addCard(Card card) {
	lpCardNode cur = NULL;
	lpCardNode tail = NULL;
	if (cardList == NULL) {
		initCardList();
	}
	//将数据保存到结点中
	cur = (lpCardNode)malloc(sizeof(CardNode));
	if (cur != NULL) {
		cur->data = card;
		cur->next = NULL;
		//遍历链表找到最后一个结点
		tail = cardList;
		while (tail->next != NULL) {
			tail = tail->next;
		}
		tail->next = cur;
		return TURE;
	}
	return FALSE;
}
//释放内存
void releaseCardList() {
	lpCardNode cur;
	lpCardNode next;
	if (cardList != NULL) {
		cur = cardList;
		while (cur != NULL) {
			next = cur->next;
			free(cur);
			cur = next;
		}
		cardList = NULL;
	}
}
//查找输入的卡用户
Card* queryCard(const char* pName) {
	lpCardNode cur = NULL;
	if (cardList != NULL) {
		cur = cardList->next;
		while (cur != NULL) {
			if (strcmp(cur->data.aName, pName) == 0) {
				return &cur->data;
			}
			cur = cur->next;
		}
	}
	return NULL; 
}
//模糊查询
Card* queryCards(const char* pName, int* pIndex) {
	lpCardNode cur = NULL;
	Card* pCard = (Card*)malloc(sizeof(Card));
	if (pCard == NULL) {
		return NULL;
	}
	if (cardList != NULL) {
		cur = cardList->next;
		while (cur != NULL) {
			if (strstr(cur->data.aName, pName) !=NULL) {
				pCard[*pIndex] = cur->data;
				(*pIndex)++;
				pCard = (Card*)realloc(pCard, ((*pIndex) + 1) * sizeof(Card));
			}
			cur = cur->next;
		}
	return pCard;
}
	return NULL;
}

