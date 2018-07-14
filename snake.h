#pragma once
#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include <conio.h>
#include <graphics.h>
#include <stdlib.h>
#include <time.h>
#include<string.h>
#include<math.h>
#include <windows.h>
#pragma comment(lib, "winmm.lib")

#define LEFT  0x4B
#define RIGHT 0x4D
#define UP    0x48
#define DOWN  0x50
#define ESC   0x1B
#define ENTER 0x0D

#define H 32
#define W 32
#define Pi 3.14

#define WALL 1
#define BODY 2
#define POSION 3
#define FOOD 4
#define BOMB 5
#define LIGHT 6
#define HOLE 7
#define WIS 8

IMAGE background;
IMAGE Menu;
IMAGE Menu2;
IMAGE rank;
IMAGE MenuEle;
IMAGE gameDie;
IMAGE gameWin;
IMAGE gameFinish;

IMAGE bombimg;
IMAGE posionimg;
IMAGE lightimg;
IMAGE light2img;
IMAGE foodimg;
IMAGE holeimg;
IMAGE wisimg;

IMAGE faceimg;
IMAGE deadimg;
IMAGE bombfaceimg;
IMAGE posionfaceimg;
IMAGE foodfaceimg;
IMAGE wisfaceimg;

int direction;
int nodes;
int score;
int seed;
int Step;
int Timer;
int Timer0;

bool flag;
bool flagP;
bool flagW;
bool flagWA;
bool wis;
bool live;
char startx, starty;
char tx, ty;
char Scene;
char mode;
char progress;
char elect;
char key;
char speed;
char tempX;
char tempY;
int tailw, headw;

TCHAR num[5];
int Rscore[6];
TCHAR s[10];
TCHAR sname[10][10];
TCHAR sprogress[10];
char map[W][H] = { 0 };     //  0->null  1->wall  2->body  3->posion  4->food  5->bomb  6->Tposion  7->hole  8->wis
bool book[H][W] = { 0 };
char WISxy[900][2];

int next[4][2] = { { 0,1 },//ср
{ 1,0 },//об
{ 0,-1 },//вС
{ -1,0 } };//ио

FILE *fp;

struct snake {
	int x;
	int y;
	struct snake *prev;
	struct snake *next;
}*head, *tail;

struct note
{
	int x;
	int y;
	int father;
	int step;
};
struct note que[H*W];

void init();
void GameStart();
void FirstLevel();
void addHead();
void cutTail();
void GetCommand();
void Elect();
void makeXY();
void showMap();
void foodAct();
void GameOver();
void Rank();
void newPlayer();
void make(char n);
void makeStuff();
void makeLight();
void detect();
void wisdom();
void BFS();
void del();
void ifBump();
void ifDead();
void Sort(int a[], int size);
void SaveScore(int score);