#define _CRT_SECURE_NO_WARNINGS
#include<time.h>
//将时间的格式进行转换
void timeToString(time_t t, char* pBuf) {
	struct tm* pTimeInfo;
	pTimeInfo = localtime(&t);
	strftime(pBuf, 20, "%Y-%m-%d %H:%M", pTimeInfo);
}