#pragma once
#include"model.h"
int addCard(Card card);
Card* queryCard(const char* pName);
int isPwdExist(const char* pPwd);
void releaseCardList();
int initCardList();
Card* queryCards(const char* pName, int* pIndex);