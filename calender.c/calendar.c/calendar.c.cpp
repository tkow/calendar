// carender.c.cpp : コンソール アプリケーションのエントリ ポイントを定義します。
//

#include "stdafx.h"


int _tmain(int argc, _TCHAR* argv[])
{
	int year;
	int month;
	int daynum = 1;
	int dayslim = 31;
	int space;

	int i;

	int h=-1;
	int d = daynum;
	int m;
	int Y;
	int gamma;
	int C;

	

	printf_s("Input year:");
	scanf_s("%d", &year);
	printf_s("Input month:");
	scanf_s("%d", &month);

	if (month == 2){
		if (year % 400 == 0){
			dayslim = 29;
		}
		else if (year % 100 == 0 || year % 4!=0){
			dayslim = 28;
		}
		else{ dayslim = 29;}
	}
	else{
		if (month == 4 || month == 6 || month == 9 || month == 11) dayslim = 30; 
	}



	if (month == 1){
		year--;
		m = 13;
	}
	else if (month == 2){
		year--;
		m = 14;
	}
	else{ m = month; }

	

	C = year / 100;
	Y = year % 100;

	while (h<0){ 


	if (4 <= year && year <= 1582){
		gamma = 6*C + 5;
	}
	else{
		gamma = 5 * C + C / 4;
	}


	h = (d + 26 * (m + 1) / 10 + Y + Y / 4 + gamma);

}
	h = h % 7;
	if (h == 0)h = 7;
	space = 1 + 4 * (h-1);
	
	printf("Sun Mon Tue Wed Thr Fri Sut\n");
	for (i = 0; i < space; i++){
		printf_s(" ");
	}

	for (i = 1; i <= dayslim; i++){
			if (i / 10 < 1)  printf_s(" ");
		printf_s("%d  ",i);
		if (i % 7 == (1 + (7 - h)) % 7)printf_s("\n ");

	}

	printf_s("\n");
  

	return 0;
}

