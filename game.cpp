#include <iostream>
#include <ctime>
#include <thread>
#include <cstdlib>
#include <cstdio>
#include "graphics.h"
#pragma comment(lib,"winmm.lib")
#define pi 3.141592

using namespace std;

void giris();
void playSound();
void game();
void howToPlay();
void character();
void difficulty();
void easyLeftUp();
void normalLeftUp();
void hardLeftUp();
void easyLeftDown();
void normalLeftDown();
void hardLeftDown();
void easyRightUp();
void normalRightUp();
void hardRightUp();
void easyRightDown();
void normalRightDown();
void hardRightDown();
void normalLeftEgikAtis();
void hardLeftEgikAtis();
void normalRightEgikAtis();
void hardRightEgikAtis();
void hardLeftSinus();
void hardRightSinus();
void hack();
void dravenTime();
void easyHighControl();
void normalHighControl();
void hardHighControl();
void easyGame();
void normalGame();
void hardGame();
void winScreen();
void loseScreen();

char *karakterNormal[100];
char *karakterAttack[100];
char zamanE[10], zamanN[10], zamanH[10];
char easySayi[10], normalSayi[10], hardSayi[10];
char easyHighScoreChar[10], normalHighScoreChar[10], hardHighScoreChar[10];
char degisken;

int easyTime = 60, normalTime = 60, hardTime = 60;
int easyPuan = 0, normalPuan = 0, hardPuan = 0, sayac = 0;
int easyHighScore, normalHighScore, hardHighScore;
int z;

void main()
{
	system("color F");
	setlocale(LC_ALL, "Turkish");

	FILE *easy;
	easy = fopen("easyHighScore.txt", "r");
	fgets(easyHighScoreChar, 4, easy);
	easyHighScore = atoi(easyHighScoreChar);
	fclose(easy);

	FILE *normal;
	normal = fopen("normalHighScore.txt", "r");
	fgets(normalHighScoreChar, 4, normal);
	normalHighScore = atoi(normalHighScoreChar);
	fclose(normal);

	FILE *hard;
	hard = fopen("hardHighScore.txt", "r");
	fgets(hardHighScoreChar, 4, hard);
	hardHighScore = atoi(hardHighScoreChar);
	fclose(hard);

	string sifre;
	string password = "Target Attack";

	/*
	do
	{
		system("cls");
		cout << "Þifreyi giriniz:";
		getline(cin, sifre);
	} while (sifre != password);
	*/

	giris();
}

void giris()
{
	srand(time(NULL));

	initwindow(1000, 600, "TARGET ATTACK", 183, 50);
	FreeConsole();

	readimagefile("picture/logo2.jpg", 0, 0, 1000, 600);
	delay(1000);

	game();
}

void playSound()
{
	PlaySound("music.wav", NULL, SND_SYNC);
}

void game()
{
	thread deneme(playSound);
	readimagefile("picture/background.jpg", 0, 0, 1000, 600);
	readimagefile("picture/targetAttack.gif", 200, 0, 800, 300);
	readimagefile("picture/startgame.gif", 650, 200, 850, 400);
	readimagefile("picture/howtoplay.gif", 650, 300, 850, 500);
	readimagefile("picture/exitgame.gif", 650, 400, 850, 600);

	while (true)
	{
		int x, y;

		x = mousex();
		y = mousey();

		while (ismouseclick(WM_LBUTTONDOWN))
		{
			if (x > 650 & x < 850 & y>210 & y < 290)
			{
				clearmouseclick(WM_LBUTTONDOWN);
				character();
			}
			if (x > 650 & x < 850 & y>310 & y < 390)
			{
				clearmouseclick(WM_LBUTTONDOWN);
				howToPlay();
			}
			if (x > 650 & x < 850 & y>410 & y < 490)
			{
				clearmouseclick(WM_LBUTTONDOWN);
				exit(0);
			}
		}
	}
}

void howToPlay()
{
	readimagefile("picture/background.jpg", 0, 0, 1000, 600);
	readimagefile("picture/parsomen.gif", 500, 50, 950, 600);
	readimagefile("picture/back.gif", 30, 500, 230, 700);

	while (true)
	{
		int x, y;

		x = mousex();
		y = mousey();

		while (ismouseclick(WM_LBUTTONDOWN))
		{
			if (x > 30 && x < 230 && y>500 && y < 700)
			{
				clearmouseclick(WM_LBUTTONDOWN);
				game();
			}
		}
	}
}

void character()
{
	readimagefile("picture/background.jpg", 0, 0, 1000, 600);
	readimagefile("picture/choosecharacter.gif", 200, 30, 770, 250);
	readimagefile("picture/caitlynsecim.gif", 80, 180, 280, 480);
	readimagefile("picture/luciansecim.gif", 380, 180, 580, 480);
	readimagefile("picture/misssecim.gif", 680, 180, 880, 480);
	readimagefile("picture/back.gif", 30, 500, 230, 700);

	while (true)
	{
		int x, y;

		x = mousex();
		y = mousey();

		while (ismouseclick(WM_LBUTTONDOWN))
		{
			if (x > 80 && x < 280 && y>180 && y < 480)
			{
				clearmouseclick(WM_LBUTTONDOWN);
				*karakterNormal = "picture/caitlyn1.gif";
				*karakterAttack = "picture/caitlyn2.gif";
				difficulty();
			}
			if (x > 380 && x < 580 && y>180 && y < 480)
			{
				clearmouseclick(WM_LBUTTONDOWN);
				*karakterNormal = "picture/lucian1.gif";
				*karakterAttack = "picture/lucian2.gif";
				difficulty();
			}
			if (x > 680 && x < 880 && y>180 && y < 480)
			{
				clearmouseclick(WM_LBUTTONDOWN);
				*karakterNormal = "picture/miss1.gif";
				*karakterAttack = "picture/miss2.gif";
				difficulty();
			}
			if (x > 30 && x < 230 && y>500 && y < 700)
			{
				clearmouseclick(WM_LBUTTONDOWN);
				game();
			}
		}
	}
}

void difficulty()
{
	readimagefile("picture/background.jpg", 0, 0, 1000, 600);
	readimagefile("picture/easy.gif", 650, 200, 850, 400);
	readimagefile("picture/normal.gif", 650, 300, 850, 500);
	readimagefile("picture/hard.gif", 650, 400, 850, 600);
	readimagefile("picture/back.gif", 30, 500, 230, 700);

	while (true)
	{
		int x, y;

		x = mousex();
		y = mousey();

		readimagefile("picture/nolock.gif", 550, 200, 650, 250);
		if (easyHighScore < 200)
			readimagefile("picture/lock.gif", 550, 300, 650, 350);
		else
			readimagefile("picture/nolock.gif", 550, 300, 650, 350);
		if (normalHighScore < 200)
			readimagefile("picture/lock.gif", 550, 400, 650, 450);
		else
			readimagefile("picture/nolock.gif", 550, 400, 650, 450);

		while (ismouseclick(WM_LBUTTONDOWN))
		{
			if (x > 650 && x < 845 && y > 200 && y < 280)
			{
				clearmouseclick(WM_LBUTTONDOWN);
				easyGame();
			}
			if (x>650 && x < 845 && y>300 && y < 380)
			{
				clearmouseclick(WM_LBUTTONDOWN);
				normalGame();
			}
			if (x>650 && x < 845 && y>400 && y < 480)
			{
				clearmouseclick(WM_LBUTTONDOWN);
				hardGame();
			}
			if (x > 30 && x < 230 && y>500 && y < 700)
			{
				clearmouseclick(WM_LBUTTONDOWN);
				character();
			}
		}
	}
}

void timeControlEasy()
{
	for (easyTime = 60; easyTime >= 0; easyTime--)
	{
		sprintf(zamanE, "%d", easyTime);
		Sleep(1000);
	}
}

void timeControlNormal()
{
	for (normalTime = 60; normalTime >= 0; normalTime--)
	{
		sprintf(zamanN, "%d", normalTime);
		Sleep(1000);
	}
}

void timeControlHard()
{
	for (hardTime = 60; hardTime >= 0; hardTime--)
	{
		sprintf(zamanH, "%d", hardTime);
		Sleep(1000);
	}
}

void easyLeftUp()
{
	while (true)
	{
		int x1, y1, a, b;

		x1 = -100;
		y1 = rand() % 400 + 100;

		while (true)
		{
			a = mousex();
			b = mousey();

			readimagefile("picture/arkaplan.jpg", 0, 0, 1000, 700);
			readimagefile("picture/dragonLeft.gif", x1, y1, x1 + 100, y1 + 100);
			readimagefile("picture/wood.jpg", 0, 500, 1000, 600);
			readimagefile(*karakterNormal, 250, 450, 750, 700);

			if (ismouseclick(WM_LBUTTONDOWN))
			{
				if (a > x1 && a < x1 + 100 && b > y1 && b < y1 + 100)
				{
					Beep(400, 50);

					readimagefile("picture/arkaplan.jpg", 0, 0, 1000, 700);
					readimagefile("picture/patlama1.gif", x1, y1, x1 + 70, y1 + 70);
					readimagefile("picture/wood.jpg", 0, 500, 1000, 600);
					readimagefile(*karakterAttack, 250, 450, 750, 700);

					settextstyle(4, 0, 15);
					outtextxy(895, 500, "TIME");
					outtextxy(0, 500, "SCORE");
					outtextxy(50, 550, easySayi);
					outtextxy(920, 550, zamanE);
					outtextxy(920, 550, zamanN);
					outtextxy(920, 550, zamanH);

					swapbuffers();
					sayac++;
					easyPuan += 10;
					break;
				}
			}

			sprintf(easySayi, "%d", easyPuan);
			settextstyle(4, 0, 15);
			outtextxy(895, 500, "TIME");
			outtextxy(0, 500, "SCORE");
			outtextxy(50, 550, easySayi);
			outtextxy(920, 550, zamanE);
			outtextxy(920, 550, zamanN);
			outtextxy(920, 550, zamanH);

			x1 += 30;
			y1 -= 10;
			swapbuffers();
			cleardevice();
			clearmouseclick(WM_LBUTTONDOWN);
			clearviewport();

			if (x1 > 1000 || y1 < -100)
			{
				break;
			}
		}
		break;
	}
}

void normalLeftUp()
{
	while (true)
	{
		int x1, y1, a, b;

		x1 = -100;
		y1 = rand() % 400 + 100;

		while (true)
		{
			a = mousex();
			b = mousey();

			readimagefile("picture/arkaplan.jpg", 0, 0, 1000, 700);
			readimagefile("picture/dragonLeft.gif", x1, y1, x1 + 100, y1 + 100);
			readimagefile("picture/wood.jpg", 0, 500, 1000, 600);
			readimagefile(*karakterNormal, 250, 450, 750, 700);

			if (ismouseclick(WM_LBUTTONDOWN))
			{
				if (a > x1 && a < x1 + 100 && b > y1 && b < y1 + 100)
				{
					Beep(400, 50);

					readimagefile("picture/arkaplan.jpg", 0, 0, 1000, 700);
					readimagefile("picture/patlama1.gif", x1, y1, x1 + 70, y1 + 70);
					readimagefile("picture/wood.jpg", 0, 500, 1000, 600);
					readimagefile(*karakterAttack, 250, 450, 750, 700);

					settextstyle(4, 0, 15);
					outtextxy(895, 500, "TIME");
					outtextxy(0, 500, "SCORE");
					outtextxy(50, 550, normalSayi);
					outtextxy(920, 550, zamanE);
					outtextxy(920, 550, zamanN);
					outtextxy(920, 550, zamanH);

					swapbuffers();
					sayac++;
					normalPuan += 10;
					break;
				}
			}

			sprintf(normalSayi, "%d", normalPuan);
			settextstyle(4, 0, 15);
			outtextxy(895, 500, "TIME");
			outtextxy(0, 500, "SCORE");
			outtextxy(50, 550, normalSayi);
			outtextxy(920, 550, zamanE);
			outtextxy(920, 550, zamanN);
			outtextxy(920, 550, zamanH);

			x1 += 40;
			y1 -= 15;
			swapbuffers();
			cleardevice();
			clearmouseclick(WM_LBUTTONDOWN);
			clearviewport();

			if (x1 > 1000 || y1 < -100)
			{
				break;
			}
		}
		break;
	}
}

void hardLeftUp()
{
	while (true)
	{
		int x1, y1, a, b;

		x1 = -100;
		y1 = rand() % 400 + 100;

		while (true)
		{
			a = mousex();
			b = mousey();

			readimagefile("picture/arkaplan.jpg", 0, 0, 1000, 700);
			readimagefile("picture/dragonLeft.gif", x1, y1, x1 + 100, y1 + 100);
			readimagefile("picture/wood.jpg", 0, 500, 1000, 600);
			readimagefile(*karakterNormal, 250, 450, 750, 700);

			if (ismouseclick(WM_LBUTTONDOWN))
			{
				if (a > x1 && a < x1 + 100 && b > y1 && b < y1 + 100)
				{
					Beep(400, 50);

					readimagefile("picture/arkaplan.jpg", 0, 0, 1000, 700);
					readimagefile("picture/patlama1.gif", x1, y1, x1 + 70, y1 + 70);
					readimagefile("picture/wood.jpg", 0, 500, 1000, 600);
					readimagefile(*karakterAttack, 250, 450, 750, 700);

					settextstyle(4, 0, 15);
					outtextxy(895, 500, "TIME");
					outtextxy(0, 500, "SCORE");
					outtextxy(50, 550, hardSayi);
					outtextxy(920, 550, zamanE);
					outtextxy(920, 550, zamanN);
					outtextxy(920, 550, zamanH);

					swapbuffers();
					sayac++;
					hardPuan += 15;
					break;
				}
				else
				{
					hardPuan -= 5;
				}
			}

			sprintf(hardSayi, "%d", hardPuan);
			settextstyle(4, 0, 15);
			outtextxy(895, 500, "TIME");
			outtextxy(0, 500, "SCORE");
			outtextxy(50, 550, hardSayi);
			outtextxy(920, 550, zamanE);
			outtextxy(920, 550, zamanN);
			outtextxy(920, 550, zamanH);

			x1 += 50;
			y1 -= 15;
			swapbuffers();
			cleardevice();
			clearmouseclick(WM_LBUTTONDOWN);
			clearviewport();

			if (x1 > 1000 || y1 < -100)
			{
				break;
			}
		}
		break;
	}
}

void easyLeftDown()
{
	while (true)
	{
		int x1, y1, a, b;

		x1 = -100;
		y1 = rand() % 400;

		while (true)
		{
			a = mousex();
			b = mousey();

			readimagefile("picture/arkaplan.jpg", 0, 0, 1000, 700);
			readimagefile("picture/dragonLeft.gif", x1, y1, x1 + 100, y1 + 100);
			readimagefile("picture/wood.jpg", 0, 500, 1000, 600);
			readimagefile(*karakterNormal, 250, 450, 750, 700);

			if (ismouseclick(WM_LBUTTONDOWN))
			{
				if (a > x1 && a < x1 + 100 && b > y1 && b < y1 + 100)
				{
					Beep(400, 50);

					readimagefile("picture/arkaplan.jpg", 0, 0, 1000, 700);
					readimagefile("picture/patlama1.gif", x1, y1, x1 + 70, y1 + 70);
					readimagefile("picture/wood.jpg", 0, 500, 1000, 600);
					readimagefile(*karakterAttack, 250, 450, 750, 700);

					settextstyle(4, 0, 15);
					outtextxy(895, 500, "TIME");
					outtextxy(0, 500, "SCORE");
					outtextxy(50, 550, easySayi);
					outtextxy(920, 550, zamanE);
					outtextxy(920, 550, zamanN);
					outtextxy(920, 550, zamanH);

					swapbuffers();
					sayac++;
					easyPuan += 10;
					break;
				}
			}

			sprintf(easySayi, "%d", easyPuan);
			settextstyle(4, 0, 15);
			outtextxy(895, 500, "TIME");
			outtextxy(0, 500, "SCORE");
			outtextxy(50, 550, easySayi);
			outtextxy(920, 550, zamanE);
			outtextxy(920, 550, zamanN);
			outtextxy(920, 550, zamanH);

			x1 += 30;
			y1 += 10;
			swapbuffers();
			cleardevice();
			clearmouseclick(WM_LBUTTONDOWN);
			clearviewport();

			if (x1 > 1000 || y1 > 500)
			{
				break;
			}
		}
		break;
	}
}

void normalLeftDown()
{
	while (true)
	{
		int x1, y1, a, b;

		x1 = -100;
		y1 = rand() % 400;

		while (true)
		{
			a = mousex();
			b = mousey();

			readimagefile("picture/arkaplan.jpg", 0, 0, 1000, 700);
			readimagefile("picture/dragonLeft.gif", x1, y1, x1 + 100, y1 + 100);
			readimagefile("picture/wood.jpg", 0, 500, 1000, 600);
			readimagefile(*karakterNormal, 250, 450, 750, 700);

			if (ismouseclick(WM_LBUTTONDOWN))
			{
				if (a > x1 && a < x1 + 100 && b > y1 && b < y1 + 100)
				{
					Beep(400, 50);

					readimagefile("picture/arkaplan.jpg", 0, 0, 1000, 700);
					readimagefile("picture/patlama1.gif", x1, y1, x1 + 70, y1 + 70);
					readimagefile("picture/wood.jpg", 0, 500, 1000, 600);
					readimagefile(*karakterAttack, 250, 450, 750, 700);

					settextstyle(4, 0, 15);
					outtextxy(895, 500, "TIME");
					outtextxy(0, 500, "SCORE");
					outtextxy(50, 550, normalSayi);
					outtextxy(920, 550, zamanE);
					outtextxy(920, 550, zamanN);
					outtextxy(920, 550, zamanH);

					swapbuffers();
					sayac++;
					normalPuan += 10;
					break;
				}
			}

			sprintf(normalSayi, "%d", normalPuan);
			settextstyle(4, 0, 15);
			outtextxy(895, 500, "TIME");
			outtextxy(0, 500, "SCORE");
			outtextxy(50, 550, normalSayi);
			outtextxy(920, 550, zamanE);
			outtextxy(920, 550, zamanN);
			outtextxy(920, 550, zamanH);

			x1 += 40;
			y1 += 15;
			swapbuffers();
			cleardevice();
			clearmouseclick(WM_LBUTTONDOWN);
			clearviewport();

			if (x1 > 1000 || y1 > 500)
			{
				break;
			}
		}
		break;
	}
}

void hardLeftDown()
{
	while (true)
	{
		int x1, y1, a, b;

		x1 = -100;
		y1 = rand() % 400;

		while (true)
		{
			a = mousex();
			b = mousey();

			readimagefile("picture/arkaplan.jpg", 0, 0, 1000, 700);
			readimagefile("picture/dragonLeft.gif", x1, y1, x1 + 100, y1 + 100);
			readimagefile("picture/wood.jpg", 0, 500, 1000, 600);
			readimagefile(*karakterNormal, 250, 450, 750, 700);

			if (ismouseclick(WM_LBUTTONDOWN))
			{
				if (a > x1 && a < x1 + 100 && b > y1 && b < y1 + 100)
				{
					Beep(400, 50);

					readimagefile("picture/arkaplan.jpg", 0, 0, 1000, 700);
					readimagefile("picture/patlama1.gif", x1, y1, x1 + 70, y1 + 70);
					readimagefile("picture/wood.jpg", 0, 500, 1000, 600);
					readimagefile(*karakterAttack, 250, 450, 750, 700);

					settextstyle(4, 0, 15);
					outtextxy(895, 500, "TIME");
					outtextxy(0, 500, "SCORE");
					outtextxy(50, 550, hardSayi);
					outtextxy(920, 550, zamanE);
					outtextxy(920, 550, zamanN);
					outtextxy(920, 550, zamanH);

					swapbuffers();
					sayac++;
					hardPuan += 15;
					break;
				}
				else
				{
					hardPuan -= 5;
				}
			}

			sprintf(hardSayi, "%d", hardPuan);
			settextstyle(4, 0, 15);
			outtextxy(895, 500, "TIME");
			outtextxy(0, 500, "SCORE");
			outtextxy(50, 550, hardSayi);
			outtextxy(920, 550, zamanE);
			outtextxy(920, 550, zamanN);
			outtextxy(920, 550, zamanH);

			x1 += 50;
			y1 += 15;
			swapbuffers();
			cleardevice();
			clearmouseclick(WM_LBUTTONDOWN);
			clearviewport();

			if (x1 > 1000 || y1 > 500)
			{
				break;
			}
		}
		break;
	}
}

void easyRightUp()
{
	while (true)
	{
		int x1, y1, a, b;

		x1 = 1000;
		y1 = rand() % 400 + 100;

		while (true)
		{
			a = mousex();
			b = mousey();

			readimagefile("picture/arkaplan.jpg", 0, 0, 1000, 700);
			readimagefile("picture/dragonRight.gif", x1, y1, x1 + 100, y1 + 100);
			readimagefile("picture/wood.jpg", 0, 500, 1000, 600);
			readimagefile(*karakterNormal, 250, 450, 750, 700);

			if (ismouseclick(WM_LBUTTONDOWN))
			{
				if (a > x1 && a < x1 + 100 && b > y1 && b < y1 + 100)
				{
					Beep(400, 50);

					readimagefile("picture/arkaplan.jpg", 0, 0, 1000, 700);
					readimagefile("picture/patlama1.gif", x1, y1, x1 + 70, y1 + 70);
					readimagefile("picture/wood.jpg", 0, 500, 1000, 600);
					readimagefile(*karakterAttack, 250, 450, 750, 700);

					settextstyle(4, 0, 15);
					outtextxy(895, 500, "TIME");
					outtextxy(0, 500, "SCORE");
					outtextxy(50, 550, easySayi);
					outtextxy(920, 550, zamanE);
					outtextxy(920, 550, zamanN);
					outtextxy(920, 550, zamanH);

					swapbuffers();
					sayac++;
					easyPuan += 10;
					break;
				}
			}

			sprintf(easySayi, "%d", easyPuan);
			settextstyle(4, 0, 15);
			outtextxy(895, 500, "TIME");
			outtextxy(0, 500, "SCORE");
			outtextxy(50, 550, easySayi);
			outtextxy(920, 550, zamanE);
			outtextxy(920, 550, zamanN);
			outtextxy(920, 550, zamanH);

			x1 -= 30;
			y1 -= 10;
			swapbuffers();
			cleardevice();
			clearmouseclick(WM_LBUTTONDOWN);
			clearviewport();

			if (x1 < 0 || y1 < -100)
			{
				break;
			}
		}
		break;
	}
}

void normalRightUp()
{
	while (true)
	{
		int x1, y1, a, b;

		x1 = 1000;
		y1 = rand() % 400 + 100;

		while (true)
		{
			a = mousex();
			b = mousey();

			readimagefile("picture/arkaplan.jpg", 0, 0, 1000, 700);
			readimagefile("picture/dragonRight.gif", x1, y1, x1 + 100, y1 + 100);
			readimagefile("picture/wood.jpg", 0, 500, 1000, 600);
			readimagefile(*karakterNormal, 250, 450, 750, 700);

			if (ismouseclick(WM_LBUTTONDOWN))
			{
				if (a > x1 && a < x1 + 100 && b > y1 && b < y1 + 100)
				{
					Beep(400, 50);

					readimagefile("picture/arkaplan.jpg", 0, 0, 1000, 700);
					readimagefile("picture/patlama1.gif", x1, y1, x1 + 70, y1 + 70);
					readimagefile("picture/wood.jpg", 0, 500, 1000, 600);
					readimagefile(*karakterAttack, 250, 450, 750, 700);

					settextstyle(4, 0, 15);
					outtextxy(895, 500, "TIME");
					outtextxy(0, 500, "SCORE");
					outtextxy(50, 550, normalSayi);
					outtextxy(920, 550, zamanE);
					outtextxy(920, 550, zamanN);
					outtextxy(920, 550, zamanH);

					swapbuffers();
					sayac++;
					normalPuan += 10;
					break;
				}
			}

			sprintf(normalSayi, "%d", normalPuan);
			settextstyle(4, 0, 15);
			outtextxy(895, 500, "TIME");
			outtextxy(0, 500, "SCORE");
			outtextxy(50, 550, normalSayi);
			outtextxy(920, 550, zamanE);
			outtextxy(920, 550, zamanN);
			outtextxy(920, 550, zamanH);

			x1 -= 40;
			y1 -= 15;
			swapbuffers();
			cleardevice();
			clearmouseclick(WM_LBUTTONDOWN);
			clearviewport();

			if (x1 < 0 || y1 < -100)
			{
				break;
			}
		}
		break;
	}
}

void hardRightUp()
{
	while (true)
	{
		int x1, y1, a, b;

		x1 = 1000;
		y1 = rand() % 400 + 100;

		while (true)
		{
			a = mousex();
			b = mousey();

			readimagefile("picture/arkaplan.jpg", 0, 0, 1000, 700);
			readimagefile("picture/dragonRight.gif", x1, y1, x1 + 100, y1 + 100);
			readimagefile("picture/wood.jpg", 0, 500, 1000, 600);
			readimagefile(*karakterNormal, 250, 450, 750, 700);

			if (ismouseclick(WM_LBUTTONDOWN))
			{
				if (a > x1 && a < x1 + 100 && b > y1 && b < y1 + 100)
				{
					Beep(400, 50);

					readimagefile("picture/arkaplan.jpg", 0, 0, 1000, 700);
					readimagefile("picture/patlama1.gif", x1, y1, x1 + 70, y1 + 70);
					readimagefile("picture/wood.jpg", 0, 500, 1000, 600);
					readimagefile(*karakterAttack, 250, 450, 750, 700);

					settextstyle(4, 0, 15);
					outtextxy(895, 500, "TIME");
					outtextxy(0, 500, "SCORE");
					outtextxy(50, 550, hardSayi);
					outtextxy(920, 550, zamanE);
					outtextxy(920, 550, zamanN);
					outtextxy(920, 550, zamanH);

					swapbuffers();
					sayac++;
					hardPuan += 15;
					break;
				}
				else
				{
					hardPuan -= 5;
				}
			}

			sprintf(hardSayi, "%d", hardPuan);
			settextstyle(4, 0, 15);
			outtextxy(895, 500, "TIME");
			outtextxy(0, 500, "SCORE");
			outtextxy(50, 550, hardSayi);
			outtextxy(920, 550, zamanE);
			outtextxy(920, 550, zamanN);
			outtextxy(920, 550, zamanH);

			x1 -= 50;
			y1 -= 15;
			swapbuffers();
			cleardevice();
			clearmouseclick(WM_LBUTTONDOWN);
			clearviewport();

			if (x1 < 0 || y1 < -100)
			{
				break;
			}
		}
		break;
	}
}

void easyRightDown()
{
	while (true)
	{
		int x1, y1, a, b;

		x1 = 1000;
		y1 = rand() % 400;

		while (true)
		{
			a = mousex();
			b = mousey();

			readimagefile("picture/arkaplan.jpg", 0, 0, 1000, 700);
			readimagefile("picture/dragonRight.gif", x1, y1, x1 + 100, y1 + 100);
			readimagefile("picture/wood.jpg", 0, 500, 1000, 600);
			readimagefile(*karakterNormal, 250, 450, 750, 700);

			if (ismouseclick(WM_LBUTTONDOWN))
			{
				if (a > x1 && a < x1 + 100 && b > y1 && b < y1 + 100)
				{
					Beep(400, 50);

					readimagefile("picture/arkaplan.jpg", 0, 0, 1000, 700);
					readimagefile("picture/patlama1.gif", x1, y1, x1 + 70, y1 + 70);
					readimagefile("picture/wood.jpg", 0, 500, 1000, 600);
					readimagefile(*karakterAttack, 250, 450, 750, 700);

					settextstyle(4, 0, 15);
					outtextxy(895, 500, "TIME");
					outtextxy(0, 500, "SCORE");
					outtextxy(50, 550, easySayi);
					outtextxy(920, 550, zamanE);
					outtextxy(920, 550, zamanN);
					outtextxy(920, 550, zamanH);

					swapbuffers();
					sayac++;
					easyPuan += 10;
					break;
				}
			}

			sprintf(easySayi, "%d", easyPuan);
			settextstyle(4, 0, 15);
			outtextxy(895, 500, "TIME");
			outtextxy(0, 500, "SCORE");
			outtextxy(50, 550, easySayi);
			outtextxy(920, 550, zamanE);
			outtextxy(920, 550, zamanN);
			outtextxy(920, 550, zamanH);

			x1 -= 30;
			y1 += 10;
			swapbuffers();
			cleardevice();
			clearmouseclick(WM_LBUTTONDOWN);
			clearviewport();

			if (x1 < 0 || y1 > 500)
			{
				break;
			}
		}
		break;
	}
}

void normalRightDown()
{
	while (true)
	{
		int x1, y1, a, b;

		x1 = 1000;
		y1 = rand() % 400;

		while (true)
		{
			a = mousex();
			b = mousey();

			readimagefile("picture/arkaplan.jpg", 0, 0, 1000, 700);
			readimagefile("picture/dragonRight.gif", x1, y1, x1 + 100, y1 + 100);
			readimagefile("picture/wood.jpg", 0, 500, 1000, 600);
			readimagefile(*karakterNormal, 250, 450, 750, 700);

			if (ismouseclick(WM_LBUTTONDOWN))
			{
				if (a > x1 && a < x1 + 100 && b > y1 && b < y1 + 100)
				{
					Beep(400, 50);

					readimagefile("picture/arkaplan.jpg", 0, 0, 1000, 700);
					readimagefile("picture/patlama1.gif", x1, y1, x1 + 70, y1 + 70);
					readimagefile("picture/wood.jpg", 0, 500, 1000, 600);
					readimagefile(*karakterAttack, 250, 450, 750, 700);

					settextstyle(4, 0, 15);
					outtextxy(895, 500, "TIME");
					outtextxy(0, 500, "SCORE");
					outtextxy(50, 550, normalSayi);
					outtextxy(920, 550, zamanE);
					outtextxy(920, 550, zamanN);
					outtextxy(920, 550, zamanH);

					swapbuffers();
					sayac++;
					normalPuan += 10;
					break;
				}
			}

			sprintf(normalSayi, "%d", normalPuan);
			settextstyle(4, 0, 15);
			outtextxy(895, 500, "TIME");
			outtextxy(0, 500, "SCORE");
			outtextxy(50, 550, normalSayi);
			outtextxy(920, 550, zamanE);
			outtextxy(920, 550, zamanN);
			outtextxy(920, 550, zamanH);

			x1 -= 40;
			y1 += 15;
			swapbuffers();
			cleardevice();
			clearmouseclick(WM_LBUTTONDOWN);
			clearviewport();

			if (x1 < 0 || y1 > 500)
			{
				break;
			}
		}
		break;
	}
}

void hardRightDown()
{
	while (true)
	{
		int x1, y1, a, b;

		x1 = 1000;
		y1 = rand() % 400;

		while (true)
		{
			a = mousex();
			b = mousey();

			readimagefile("picture/arkaplan.jpg", 0, 0, 1000, 700);
			readimagefile("picture/dragonRight.gif", x1, y1, x1 + 100, y1 + 100);
			readimagefile("picture/wood.jpg", 0, 500, 1000, 600);
			readimagefile(*karakterNormal, 250, 450, 750, 700);

			if (ismouseclick(WM_LBUTTONDOWN))
			{
				if (a > x1 && a < x1 + 100 && b > y1 && b < y1 + 100)
				{
					Beep(400, 50);

					readimagefile("picture/arkaplan.jpg", 0, 0, 1000, 700);
					readimagefile("picture/patlama1.gif", x1, y1, x1 + 70, y1 + 70);
					readimagefile("picture/wood.jpg", 0, 500, 1000, 600);
					readimagefile(*karakterAttack, 250, 450, 750, 700);

					settextstyle(4, 0, 15);
					outtextxy(895, 500, "TIME");
					outtextxy(0, 500, "SCORE");
					outtextxy(50, 550, hardSayi);
					outtextxy(920, 550, zamanE);
					outtextxy(920, 550, zamanN);
					outtextxy(920, 550, zamanH);

					swapbuffers();
					sayac++;
					hardPuan += 15;
					break;
				}
				else
				{
					hardPuan -= 5;
				}
			}

			sprintf(hardSayi, "%d", hardPuan);
			settextstyle(4, 0, 15);
			outtextxy(895, 500, "TIME");
			outtextxy(0, 500, "SCORE");
			outtextxy(50, 550, hardSayi);
			outtextxy(920, 550, zamanE);
			outtextxy(920, 550, zamanN);
			outtextxy(920, 550, zamanH);

			x1 -= 50;
			y1 += 15;
			swapbuffers();
			cleardevice();
			clearmouseclick(WM_LBUTTONDOWN);
			clearviewport();

			if (x1 < 0 || y1 > 500)
			{
				break;
			}
		}
		break;
	}
}

void normalLeftEgikAtis()
{
	while (true)
	{
		int a, b, i;
		float x1 = -100, y1;

		i = rand() % 300 + 100;

		while (true)
		{
			x1 += 40;
			y1 = 200 * -0.7*sin(x1 / 5 * pi / 180) + i;

			a = mousex();
			b = mousey();

			readimagefile("picture/arkaplan.jpg", 0, 0, 1000, 700);
			readimagefile("picture/dragonLeft.gif", x1, y1, x1 + 100, y1 + 100);
			readimagefile("picture/wood.jpg", 0, 500, 1000, 600);
			readimagefile(*karakterNormal, 250, 450, 750, 700);

			if (ismouseclick(WM_LBUTTONDOWN))
			{
				if (a > x1 && a < x1 + 100 && b > y1 && b < y1 + 100)
				{
					Beep(400, 50);

					readimagefile("picture/arkaplan.jpg", 0, 0, 1000, 700);
					readimagefile("picture/patlama1.gif", x1, y1, x1 + 70, y1 + 70);
					readimagefile("picture/wood.jpg", 0, 500, 1000, 600);
					readimagefile(*karakterAttack, 250, 450, 750, 700);

					settextstyle(4, 0, 15);
					outtextxy(895, 500, "TIME");
					outtextxy(0, 500, "SCORE");
					outtextxy(50, 550, normalSayi);
					outtextxy(920, 550, zamanE);
					outtextxy(920, 550, zamanN);
					outtextxy(920, 550, zamanH);

					swapbuffers();
					sayac++;
					normalPuan += 10;
					break;
				}
			}

			sprintf(normalSayi, "%d", normalPuan);
			settextstyle(4, 0, 15);
			outtextxy(895, 500, "TIME");
			outtextxy(0, 500, "SCORE");
			outtextxy(50, 550, normalSayi);
			outtextxy(920, 550, zamanE);
			outtextxy(920, 550, zamanN);
			outtextxy(920, 550, zamanH);

			swapbuffers();
			cleardevice();
			clearmouseclick(WM_LBUTTONDOWN);
			clearviewport();

			if (x1 > 1000 || y1 > 600)
			{
				break;
			}
		}
		break;
	}
}

void hardLeftEgikAtis()
{
	while (true)
	{
		int a, b, i;
		float x1 = -100, y1;

		i = rand() % 300 + 100;

		while (true)
		{
			x1 += 50;
			y1 = 200 * -0.7*sin(x1 / 5 * pi / 180) + i;

			a = mousex();
			b = mousey();

			readimagefile("picture/arkaplan.jpg", 0, 0, 1000, 700);
			readimagefile("picture/dragonLeft.gif", x1, y1, x1 + 100, y1 + 100);
			readimagefile("picture/wood.jpg", 0, 500, 1000, 600);
			readimagefile(*karakterNormal, 250, 450, 750, 700);

			if (ismouseclick(WM_LBUTTONDOWN))
			{
				if (a > x1 && a < x1 + 100 && b > y1 && b < y1 + 100)
				{
					Beep(400, 50);

					readimagefile("picture/arkaplan.jpg", 0, 0, 1000, 700);
					readimagefile("picture/patlama1.gif", x1, y1, x1 + 70, y1 + 70);
					readimagefile("picture/wood.jpg", 0, 500, 1000, 600);
					readimagefile(*karakterAttack, 250, 450, 750, 700);

					settextstyle(4, 0, 15);
					outtextxy(895, 500, "TIME");
					outtextxy(0, 500, "SCORE");
					outtextxy(50, 550, hardSayi);
					outtextxy(920, 550, zamanE);
					outtextxy(920, 550, zamanN);
					outtextxy(920, 550, zamanH);

					swapbuffers();
					sayac++;
					hardPuan += 15;
					break;
				}
				else
				{
					hardPuan -= 5;
				}
			}

			sprintf(hardSayi, "%d", hardPuan);
			settextstyle(4, 0, 15);
			outtextxy(895, 500, "TIME");
			outtextxy(0, 500, "SCORE");
			outtextxy(50, 550, hardSayi);
			outtextxy(920, 550, zamanE);
			outtextxy(920, 550, zamanN);
			outtextxy(920, 550, zamanH);

			swapbuffers();
			cleardevice();
			clearmouseclick(WM_LBUTTONDOWN);
			clearviewport();

			if (x1 > 1000 || y1 > 600)
			{
				break;
			}
		}
		break;
	}
}

void normalRightEgikAtis()
{
	while (true)
	{
		int a, b, i;
		float x1 = 1000, y1;

		i = rand() % 300 + 100;

		while (true)
		{
			x1 -= 40;
			y1 = 200 * -0.7*sin(x1 / 5 * pi / 180) + i;

			a = mousex();
			b = mousey();

			readimagefile("picture/arkaplan.jpg", 0, 0, 1000, 700);
			readimagefile("picture/dragonRight.gif", x1, y1, x1 + 100, y1 + 100);
			readimagefile("picture/wood.jpg", 0, 500, 1000, 600);
			readimagefile(*karakterNormal, 250, 450, 750, 700);

			if (ismouseclick(WM_LBUTTONDOWN))
			{
				if (a > x1 && a < x1 + 100 && b > y1 && b < y1 + 100)
				{
					Beep(400, 50);

					readimagefile("picture/arkaplan.jpg", 0, 0, 1000, 700);
					readimagefile("picture/patlama1.gif", x1, y1, x1 + 70, y1 + 70);
					readimagefile("picture/wood.jpg", 0, 500, 1000, 600);
					readimagefile(*karakterAttack, 250, 450, 750, 700);

					settextstyle(4, 0, 15);
					outtextxy(895, 500, "TIME");
					outtextxy(0, 500, "SCORE");
					outtextxy(50, 550, normalSayi);
					outtextxy(920, 550, zamanE);
					outtextxy(920, 550, zamanN);
					outtextxy(920, 550, zamanH);

					swapbuffers();
					sayac++;
					normalPuan += 10;
					break;
				}
			}

			sprintf(normalSayi, "%d", normalPuan);
			settextstyle(4, 0, 15);
			outtextxy(895, 500, "TIME");
			outtextxy(0, 500, "SCORE");
			outtextxy(50, 550, normalSayi);
			outtextxy(920, 550, zamanE);
			outtextxy(920, 550, zamanN);
			outtextxy(920, 550, zamanH);

			swapbuffers();
			cleardevice();
			clearmouseclick(WM_LBUTTONDOWN);
			clearviewport();

			if (x1 < 0 || y1 > 600)
			{
				break;
			}
		}
		break;
	}
}

void hardRightEgikAtis()
{
	while (true)
	{
		int a, b, i;
		float x1 = 1000, y1;

		i = rand() % 300 + 100;

		while (true)
		{
			x1 -= 50;
			y1 = 200 * -0.7*sin(x1 / 5 * pi / 180) + i;

			a = mousex();
			b = mousey();

			readimagefile("picture/arkaplan.jpg", 0, 0, 1000, 700);
			readimagefile("picture/dragonRight.gif", x1, y1, x1 + 100, y1 + 100);
			readimagefile("picture/wood.jpg", 0, 500, 1000, 600);
			readimagefile(*karakterNormal, 250, 450, 750, 700);

			if (ismouseclick(WM_LBUTTONDOWN))
			{
				if (a > x1 && a < x1 + 100 && b > y1 && b < y1 + 100)
				{
					Beep(400, 50);

					readimagefile("picture/arkaplan.jpg", 0, 0, 1000, 700);
					readimagefile("picture/patlama1.gif", x1, y1, x1 + 70, y1 + 70);
					readimagefile("picture/wood.jpg", 0, 500, 1000, 600);
					readimagefile(*karakterAttack, 250, 450, 750, 700);

					settextstyle(4, 0, 15);
					outtextxy(895, 500, "TIME");
					outtextxy(0, 500, "SCORE");
					outtextxy(50, 550, hardSayi);
					outtextxy(920, 550, zamanE);
					outtextxy(920, 550, zamanN);
					outtextxy(920, 550, zamanH);

					swapbuffers();
					sayac++;
					hardPuan += 15;
					break;
				}
				else
				{
					hardPuan -= 5;
				}
			}

			sprintf(hardSayi, "%d", hardPuan);
			settextstyle(4, 0, 15);
			outtextxy(895, 500, "TIME");
			outtextxy(0, 500, "SCORE");
			outtextxy(50, 550, hardSayi);
			outtextxy(920, 550, zamanE);
			outtextxy(920, 550, zamanN);
			outtextxy(920, 550, zamanH);

			swapbuffers();
			cleardevice();
			clearmouseclick(WM_LBUTTONDOWN);
			clearviewport();

			if (x1 < 0 || y1 > 600)
			{
				break;
			}
		}
		break;
	}
}

void hardLeftSinus()
{
	while (true)
	{
		int a, b;
		float x1 = -100, y1;

		while (true)
		{
			x1 += 25;
			y1 = 200 * -sin(x1 * pi / 180) + 250;

			a = mousex();
			b = mousey();

			readimagefile("picture/arkaplan.jpg", 0, 0, 1000, 700);
			readimagefile("picture/dragonLeft.gif", x1, y1, x1 + 100, y1 + 100);
			readimagefile("picture/wood.jpg", 0, 500, 1000, 600);
			readimagefile(*karakterNormal, 250, 450, 750, 700);

			if (ismouseclick(WM_LBUTTONDOWN))
			{
				if (a > x1 && a < x1 + 100 && b > y1 && b < y1 + 100)
				{
					Beep(400, 50);

					readimagefile("picture/arkaplan.jpg", 0, 0, 1000, 700);
					readimagefile("picture/patlama1.gif", x1, y1, x1 + 70, y1 + 70);
					readimagefile("picture/wood.jpg", 0, 500, 1000, 600);
					readimagefile(*karakterAttack, 250, 450, 750, 700);

					settextstyle(4, 0, 15);
					outtextxy(895, 500, "TIME");
					outtextxy(0, 500, "SCORE");
					outtextxy(50, 550, hardSayi);
					outtextxy(920, 550, zamanE);
					outtextxy(920, 550, zamanN);
					outtextxy(920, 550, zamanH);

					swapbuffers();
					sayac++;
					hardPuan += 15;
					break;
				}
				else
				{
					hardPuan -= 5;
				}
			}

			sprintf(hardSayi, "%d", hardPuan);
			settextstyle(4, 0, 15);
			outtextxy(895, 500, "TIME");
			outtextxy(0, 500, "SCORE");
			outtextxy(50, 550, hardSayi);
			outtextxy(920, 550, zamanE);
			outtextxy(920, 550, zamanN);
			outtextxy(920, 550, zamanH);

			swapbuffers();
			cleardevice();
			clearmouseclick(WM_LBUTTONDOWN);
			clearviewport();

			if (x1 > 1000 || y1 > 600)
			{
				break;
			}
		}
		break;
	}
}

void hardRightSinus()
{
	while (true)
	{
		int a, b;
		float x1 = 1000, y1;

		while (true)
		{
			x1 -= 25;
			y1 = 200 * -sin(x1 * pi / 180) + 250;

			a = mousex();
			b = mousey();

			readimagefile("picture/arkaplan.jpg", 0, 0, 1000, 700);
			readimagefile("picture/dragonRight.gif", x1, y1, x1 + 100, y1 + 100);
			readimagefile("picture/wood.jpg", 0, 500, 1000, 600);
			readimagefile(*karakterNormal, 250, 450, 750, 700);

			if (ismouseclick(WM_LBUTTONDOWN))
			{
				if (a > x1 && a < x1 + 100 && b > y1 && b < y1 + 100)
				{
					Beep(400, 50);

					readimagefile("picture/arkaplan.jpg", 0, 0, 1000, 700);
					readimagefile("picture/patlama1.gif", x1, y1, x1 + 70, y1 + 70);
					readimagefile("picture/wood.jpg", 0, 500, 1000, 600);
					readimagefile(*karakterAttack, 250, 450, 750, 700);

					settextstyle(4, 0, 15);
					outtextxy(895, 500, "TIME");
					outtextxy(0, 500, "SCORE");
					outtextxy(50, 550, hardSayi);
					outtextxy(920, 550, zamanE);
					outtextxy(920, 550, zamanN);
					outtextxy(920, 550, zamanH);

					swapbuffers();
					sayac++;
					hardPuan += 15;
					break;
				}
				else
				{
					hardPuan -= 5;
				}
			}

			sprintf(hardSayi, "%d", hardPuan);
			settextstyle(4, 0, 15);
			outtextxy(895, 500, "TIME");
			outtextxy(0, 500, "SCORE");
			outtextxy(50, 550, hardSayi);
			outtextxy(920, 550, zamanE);
			outtextxy(920, 550, zamanN);
			outtextxy(920, 550, zamanH);

			swapbuffers();
			cleardevice();
			clearmouseclick(WM_LBUTTONDOWN);
			clearviewport();

			if (x1 < 0 || y1 > 600)
			{
				break;
			}
		}
		break;
	}
}

void hack()
{
	while (true)
	{
		degisken = getch();

		if (degisken == 'l')
		{
			if (getch() == 'y')
			{
				if (getch() == 'k')
				{
					if (getch() == 'i')
					{
						if (getch() == 'a')
						{
							easyPuan += 50;
							normalPuan += 50;
							hardPuan += 50;
						}
					}
				}
			}
		}
		else if (degisken == 't')
		{
			if (getch() == 'i')
			{
				if (getch() == 'm');
				{
					if (getch() == 'e')
					{
						easyTime += 20;
						normalTime += 20;
						hardTime += 20;
					}
				}
			}
		}
		else if (degisken == 'd')
		{
			if (getch() == 'r')
			{
				if (getch() == 'a')
				{
					if (getch() == 'v')
					{
						if (getch() == 'e')
						{
							if (getch() == 'n')
							{
								PlaySound("draven.wav", NULL, SND_ASYNC);
								thread zero(dravenTime);
								while (z < 3)
								{
									readimagefile("picture/draven.gif", 0, 0, 1000, 600);
								}
								zero.detach();
							}
						}
					}
				}
			}
		}
	}
}

void dravenTime()
{
	for (z = 0; z < 4; z++)
	{
		Sleep(1000);
	}
}

void easyHighControl()
{
	if (easyPuan > easyHighScore)
	{
		sprintf(easySayi, "%d", easyPuan);

		easyHighScore = easyPuan;

		FILE *dosya;
		dosya = fopen("easyHighScore.txt", "w");
		fputs(easySayi, dosya);
		fclose(dosya);
	}
}

void normalHighControl()
{
	if (normalPuan > normalHighScore)
	{
		sprintf(normalSayi, "%d", normalPuan);

		normalHighScore = normalPuan;

		FILE *dosya;
		dosya = fopen("normalHighScore.txt", "w");
		fputs(easySayi, dosya);
		fclose(dosya);
	}
}

void hardHighControl()
{
	if (hardPuan > hardHighScore)
	{
		sprintf(hardSayi, "%d", hardPuan);

		hardHighScore = hardPuan;

		FILE *dosya;
		dosya = fopen("hardHighScore.txt", "w");
		fputs(hardSayi, dosya);
		fclose(dosya);
	}
}

void easyGame()
{
	thread one(timeControlEasy);
	thread two(hack);

	int z;

	while (true)
	{
		z = rand() % 4;

		if (z == 0)
		{
			easyLeftUp();
		}
		if (z == 1)
		{
			easyLeftDown();
		}
		if (z == 2)
		{
			easyRightUp();
		}
		if (z == 3)
		{
			easyRightDown();
		}
		if (sayac == 20)
		{
			easyPuan += easyTime * 5;

			sprintf(easySayi, "%d", easyPuan);

			easyHighControl();

			delay(100);
			winScreen();
		}
		if (easyTime <= 0)
		{
			easyHighControl();

			one.detach();
			delay(100);
			loseScreen();
		}
	}
}

void normalGame()
{
	thread one(timeControlNormal);
	thread two(hack);

	int z;

	while (true)
	{
		z = rand() % 8;

		if (z == 0)
		{
			normalLeftUp();
		}
		if (z == 1)
		{
			normalLeftDown();
		}
		if (z == 2)
		{
			normalRightUp();
		}
		if (z == 3)
		{
			normalRightDown();
		}
		if (z == 4 || z == 5)
		{
			normalLeftEgikAtis();
		}
		if (z == 6 || z == 7)
		{
			normalRightEgikAtis();
		}
		if (sayac == 20)
		{
			normalPuan += normalTime * 5;

			sprintf(normalSayi, "%d", normalPuan);

			normalHighControl();

			delay(100);
			winScreen();
		}
		if (normalTime <= 0)
		{
			normalHighControl();

			one.detach();
			delay(100);
			loseScreen();
		}
	}
}

void hardGame()
{
	thread one(timeControlHard);
	thread two(hack);

	int z;

	while (true)
	{
		z = rand() % 12;
		
		if (z == 0)
		{
			hardLeftUp();
		}
		if (z == 1)
		{
			hardLeftDown();
		}
		if (z == 2)
		{
			hardRightUp();
		}
		if (z == 3)
		{
			hardRightDown();
		}
		if (z == 4 || z == 5)
		{
			hardLeftEgikAtis();
		}
		if (z == 6 || z == 7)
		{
			hardRightEgikAtis();
		}
		if (z == 8 || z == 9)
		{
			hardLeftSinus();
		}
		if (z == 10 || z == 11)
		{
			hardRightSinus();
		}
		if (sayac == 20)
		{
			hardPuan += hardTime * 5;

			sprintf(hardSayi, "%d", hardPuan);

			hardHighControl();

			delay(100);
			winScreen();
		}
		if (hardTime <= 0)
		{
			hardHighControl();

			one.detach();
			delay(100);
			loseScreen();
		}
	}
}

void winScreen()
{
	closegraph();
	initwindow(1000, 600, "TARGET ATTACK", 183, 50);

	while (true)
	{
		readimagefile("picture/winScreen.jpg", 0, 0, 1000, 600);

		outtextxy(450, 212, "Score : ");
		outtextxy(500, 212, easySayi);
		outtextxy(500, 212, normalSayi);
		outtextxy(500, 212, hardSayi);

		FILE *easy;
		easy = fopen("easyHighScore.txt", "r");
		fgets(easyHighScoreChar, 4, easy);
		fclose(easy);

		FILE *normal;
		normal = fopen("normalHighScore.txt", "r");
		fgets(normalHighScoreChar, 4, normal);
		fclose(normal);

		FILE *hard;
		hard = fopen("hardHighScore.txt", "r");
		fgets(hardHighScoreChar, 4, hard);
		fclose(hard);

		outtextxy(290, 505, easyHighScoreChar);
		outtextxy(505, 505, normalHighScoreChar);
		outtextxy(707, 505, hardHighScoreChar);

		swapbuffers();
	}
}

void loseScreen()
{
	closegraph();
	initwindow(1000, 600, "TARGET ATTACK", 183, 50);

	while (true)
	{
		readimagefile("picture/loseScreen.jpg", 0, 0, 1000, 600);

		outtextxy(450, 212, "Score : ");
		outtextxy(500, 212, easySayi);
		outtextxy(500, 212, normalSayi);
		outtextxy(500, 212, hardSayi);

		FILE *easy;
		easy = fopen("easyHighScore.txt", "r");
		fgets(easyHighScoreChar, 4, easy);
		fclose(easy);

		FILE *normal;
		normal = fopen("normalHighScore.txt", "r");
		fgets(normalHighScoreChar, 4, normal);
		fclose(normal);

		FILE *hard;
		hard = fopen("hardHighScore.txt", "r");
		fgets(hardHighScoreChar, 4, hard);
		fclose(hard);

		outtextxy(290, 505, easyHighScoreChar);
		outtextxy(505, 505, normalHighScoreChar);
		outtextxy(707, 505, hardHighScoreChar);

		swapbuffers();
	}
}