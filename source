#include "snake.h"

int main()
{
	init();
	BeginBatchDraw();
	Elect();
	EndBatchDraw();
	Sleep(3000);
	return 0;
}
//ÓÎÏ·ÔËÐÐ
void FirstLevel()	
{
	GameStart();
	while ((live&&mode == 4) || (live&&nodes < 25))
	{
		for (int i = 0; i < 6; i++)
			GetCommand();
		cleardevice();
		showMap();
		detect();
		FlushBatchDraw();
		Timer = clock() - Timer0;
		ifDead();
		if(nodes>=8)	ifBump();
		makeStuff();
		makeLight();
	}
	FlushBatchDraw();
	cleardevice();
	showMap();
	if(live)		putimage(head->x - 10, head->y - 10, &foodfaceimg);
	else		putimage(head->x - 10, head->y - 10, &deadimg);
	FlushBatchDraw();
	Sleep(1000);
	del();
	GameOver();
}
//²Ëµ¥Ñ¡Ôñº¯Êý£¬¹©ÓÎÏ·³¡¾°ÒÔÍâËùÓÐ³¡¾°Ê¹ÓÃ
void Elect()							
{
	cleardevice();
	if (Scene==1)	
		putimage(0, 0, &Menu);
	else if(Scene==2)
		putimage(0, 0, &Menu2);
	while (true)
	{
		char temp = 99;
		if (GetAsyncKeyState(VK_ESCAPE) & 0x8000)
		{
			if (Scene == 2)
			{
				Scene = 1;
				Sleep(500);
				Elect();
			}
			else if (Scene == 3)
			{
				Scene = 2;
				Sleep(500);
				Elect();
			}
			else if (Scene == 4)
			{
				Scene = 1;
				Sleep(500);
				Elect();
			}
			else if (Scene == 1)
				exit(0);
		}
		else if (GetAsyncKeyState(VK_RETURN) & 0x8000)
		{
			switch (elect)
			{
			case 0:
				if (Scene == 1)
					newPlayer();
				else if (Scene == 2)
				{
					mode = 1;
					FirstLevel();
				}
				break;
			case 1:
				if (Scene == 2)
				{
					if (progress>elect)
					{
						mode = 2;
						FirstLevel();
					}
					else
					{
						MessageBox(NULL, TEXT("ÇëÏÈÍê³ÉÖ®Ç°¹Ø¿¨"), TEXT("ÌáÊ¾"), MB_OK | MB_SYSTEMMODAL);
						Sleep(50);
					}
				}
				break;
			case 2:
				if (Scene == 1) {
					Rank();
				}
				else if (Scene == 2)
				{
					if (progress>elect)
					{
						mode = 3;
						FirstLevel();
					}
					else
					{
						MessageBox(NULL, TEXT("ÇëÏÈÍê³ÉÖ®Ç°¹Ø¿¨"), TEXT("ÌáÊ¾"), MB_OK | MB_SYSTEMMODAL);
						Sleep(50);
					}
				}
				break;
			case 3:
				if (Scene == 1)
					exit(0);
				else if (Scene == 2)
				{
					if (progress>elect)
					{
						mode = 4;
						FirstLevel();
					}
					else
					{
						MessageBox(NULL, TEXT("ÇëÏÈÍê³ÉÖ®Ç°¹Ø¿¨"), TEXT("ÌáÊ¾"), MB_OK | MB_SYSTEMMODAL);
						Sleep(50);
					}
				}
				break;
			}
		}
		else if (GetAsyncKeyState(VK_UP) & 0x8000)
			elect = (elect + 3) % 4;
		else if (GetAsyncKeyState(VK_DOWN) & 0x8000)
			elect = (elect + 1) % 4;		
		if (temp != elect&&Scene != 4)
		{
			putimage(225, 280, 45, 180, &Menu, 225, 280);
			switch (elect)
			{
			case 0:
				putimage(225, 280, 45, 50, &MenuEle, 225, 280);
				break;
			case 1:
				putimage(225, 330, 45, 45, &MenuEle, 225, 330);
				break;
			case 2:
				putimage(225, 375, 45, 45, &MenuEle, 225, 375);
				break;
			case 3:
				putimage(225, 420, 45, 40, &MenuEle, 225, 420);
				break;
			}
			temp = elect;
		}
		FlushBatchDraw();
		Sleep(50);
	}
}
//Ò»¾ÖÓÎÏ·¿ªÊ¼Ç°µÄ³õÊ¼»¯
void GameStart()							
{
	speed = 15;
	live = 1;
	nodes = 2;
	direction = 0;
	score = 0;
	Scene = 3;
	flag = 0;
	flagP = 0;
	flagWA = 0;
	wis = 0;
	Timer0 = clock();

	head = (snake*)malloc(sizeof(snake));
	tail = (snake*)malloc(sizeof(snake));

	head->x = 187;
	head->y = 157;
	head->next = tail;
	head->prev = NULL;

	tail->x = 172;
	tail->y = 157;
	tail->next = NULL;
	tail->prev = head;

	for (int i = 0; i < W; i++)
	{
		for (int j = 0; j < H; j++)
		{
			if (i == 0 || j == 0 || i == W - 1 || j == H - 1)
				map[i][j] = 1;
		}
	}
	map[12][10] = 2;
	map[11][10] = 2;
	addHead();
	make(FOOD);

	if ((fp = fopen("usersdata/Record.txt", "r")) == NULL)//Èç¹ûÃ»ÓÐÅÅÐÐ°ñÎÄ¼þ
	{
		fp = fopen("usersdata/Record.txt", "w");
		for (int i = 0; i < 6; i++)
		{      
			fprintf(fp, "0 ", NULL);
		}
		fclose(fp);
	}
	fp = fopen("usersdata/Record.txt", "r+");
	for (int i = 0; i < 6; i++)
		fscanf(fp, "%d", &Rscore[i]);
	fclose(fp);
}
//Ò»¾ÖÓÎÏ·½áÊøºóµ÷ÓÃµÄº¯Êý
void GameOver()				
{
	cleardevice();
	if (live == 1)
	{
		if (progress < (mode + 1))
			progress = (mode + 1);
		if (mode==3)
			putimage(0, 0, &gameFinish);
		else
			putimage(0, 0, &gameWin);
		FlushBatchDraw();
		while (true)
		{
			if ((GetAsyncKeyState('y') & 0x8000) || (GetAsyncKeyState('Y') & 0x8000))
			{
				if (mode != 4)
					mode++;
				FirstLevel();
			}
			else if ((GetAsyncKeyState('n') & 0x8000) || (GetAsyncKeyState('N') & 0x8000))
			{
				Scene = 2;
				Elect();
			}
			Sleep(100);
		}
	}
	else if (live == 0)
	{
		putimage(0, 0, &gameDie);
		FlushBatchDraw();
		if (mode==4)
		{
			SaveScore(score);
		}
		while (true)
		{
				if ((GetAsyncKeyState('y') & 0x8000) || (GetAsyncKeyState('Y') & 0x8000))
					FirstLevel();
				else if ((GetAsyncKeyState('n') & 0x8000) || (GetAsyncKeyState('N') & 0x8000))
				{
					Scene = 2;
					Elect();
				}
			Sleep(100);
		}
	}
}
//ÅÅÐÐ°ñ·ÖÊý½øÐÐÅÅÐò
void Sort(int a[], int size) {                     
	int i, j, temp;
	for (j = 0; j<size - 1; j++)
		for (i = 0; i<size - j - 1; i++)
			if (a[i]<a[i + 1]) {
				temp = a[i];
				a[i] = a[i + 1];
				a[i + 1] = temp;
			}
}
//ÏÔÊ¾ÅÅÐÐ°ñ
void Rank() {                           
	if ((fp = fopen("usersdata/Record.txt", "r")) == NULL)//Èç¹ûÃ»ÓÐÅÅÐÐ°ñÎÄ¼þ
	{
		fp = fopen("usersdata/Record.txt", "w");
		for (int i = 0; i < 6; i++)
		{
			fprintf(fp, "0 ", NULL);
		}
		fclose(fp);
	}
	fp = fopen("usersdata/Record.txt", "r+");
	for (int i = 0; i < 6; i++)
		fscanf(fp, "%d", &Rscore[i]);
	fclose(fp);
	Scene = 4;
	cleardevice();
	putimage(0, 0, &rank);
	settextstyle(40, 0, _T("Î¢ÈíÑÅºÚ"));
	_stprintf_s(num, TEXT("%d"), Rscore[0]);
	outtextxy(200, 210, num);
	_stprintf_s(num, TEXT("%d"), Rscore[1]);
	outtextxy(200, 270, num);
	_stprintf_s(num, TEXT("%d"), Rscore[2]);
	outtextxy(200, 330, num);
	_stprintf_s(num, TEXT("%d"), Rscore[3]);
	outtextxy(550, 210, num);
	_stprintf_s(num, TEXT("%d"), Rscore[4]);
	outtextxy(550, 270, num);
	_stprintf_s(num, TEXT("%d"), Rscore[5]);
	outtextxy(550, 330, num);
	FlushBatchDraw();
}
//ÎÞ¾¡Ä£Ê½½áÊøºóÈç¹û·Ö¹»¸ß±ã½«·ÖÊý´æÈëÅÅÐÐ°ñ
void SaveScore(int score) {				
	if (score>Rscore[5]) {
		Rscore[5] = score;
		Sort(Rscore, 6);
		fp = fopen("usersdata/Record.txt", "w");
		for (int i = 0; i<6; i++)
			fprintf(fp, "%d ", Rscore[i]);
		fclose(fp);
	}
}
//ÐÂÍæ¼Ò³õÊ¼»¯£¨Ä¿Ç°ÎÞ´æµµ×÷ÓÃ£©
void newPlayer()				
{
	int t=0;
	progress = 1;
	Scene = 2;
	InputBox(s, 10, TEXT("ÇëÊäÈëÄãµÄÃû×Ö"),TEXT("ÐÂÓÃ»§"),TEXT("ÓÎ¿Í"));
	if (fopen_s(&fp, "usersdata/user.txt", "r"))
	{
		while (fscanf_s(fp, "%s %d*c", sname[t], 10, &sprogress[t]) != EOF)//ÕâÀïÓÃ²»ÁË
		{
			if (wcscmp(s, sname[t]) == 0)
			{
				MessageBox(NULL, TEXT("ÓÃ»§ÃûÒÑ´æÔÚ"), TEXT("ÌáÊ¾"), MB_OK | MB_SYSTEMMODAL);
				t = -1;
				break;
			}
			t++;
		}
	}
	if (t != -1)
		fprintf_s(fp, "%s %d\n", s, progress);
	fclose(fp);
	Sleep(500);
	Elect();
}
//ÓÎÏ·ÔËÐÐÊ±µÄ²Ù¿Ø
void GetCommand()  
{
	key = 0;
	speed = 15;
	if (GetAsyncKeyState(80) & 0x8000)
		system("pause");
	else if (GetAsyncKeyState(VK_ESCAPE) & 0x8000)
	{
		del();
		Elect();
	}
	if (GetAsyncKeyState(VK_LEFT) & 0x8000)
		key = 1;
	else if (GetAsyncKeyState(VK_RIGHT) & 0x8000)
		key = -1;
	if (GetAsyncKeyState(VK_UP) & 0x8000)
		speed = 30;
	if (GetAsyncKeyState(VK_DOWN) & 0x8000)
		speed = 10;
	direction += 5 * key;
	Sleep(20);
}
//³ÌÐòÆô¶¯Ê±µÄ³õÊ¼»¯
void init()  
{
	initgraph(720, 480);

	srand(time(0));
	seed = rand() % 1000;
	srand(seed);
	elect = 0;
	Scene = 1;
	progress = 1;

	
	loadimage(&background, TEXT("Resource\\bg.jpg"));
	loadimage(&Menu, TEXT("Resource\\menu.jpg"));
	loadimage(&Menu2, TEXT("Resource\\menu3.jpg"));
	loadimage(&MenuEle, TEXT("Resource\\menu2.jpg"));
	loadimage(&rank, TEXT("Resource\\rank.jpg"));
	loadimage(&gameDie, TEXT("Resource\\gamedie.jpg"));
	loadimage(&gameWin, TEXT("Resource\\gamewin.jpg"));
	loadimage(&gameFinish, TEXT("Resource\\gamefinish.jpg"));

	loadimage(&foodimg, TEXT("Resource\\food.jpg"));
	loadimage(&posionimg, TEXT("Resource\\posion.jpg"));
	loadimage(&bombimg, TEXT("Resource\\bomb.jpg"));
	loadimage(&lightimg, TEXT("Resource\\light.jpg"));
	loadimage(&light2img, TEXT("Resource\\light2.jpg"));
	loadimage(&holeimg, TEXT("Resource\\hole.jpg"));
	loadimage(&wisimg, TEXT("Resource\\wis.jpg"));

	loadimage(&deadimg, TEXT("Resource\\dead.jpg"));
	loadimage(&faceimg, TEXT("Resource\\face.jpg"));
	loadimage(&bombfaceimg, TEXT("Resource\\bombface.jpg"));
	loadimage(&foodfaceimg, TEXT("Resource\\foodface.jpg"));
	loadimage(&posionfaceimg, TEXT("Resource\\posionface.jpg"));
	loadimage(&wisfaceimg, TEXT("Resource\\wisface.jpg"));

	setfillcolor(LIGHTRED);
	setbkmode(TRANSPARENT);
	settextcolor(BLACK);

	if (fopen_s(&fp, "usersdata/user.txt", "r"))
	{
		int t = 0;
		while (fscanf_s(fp, "%s %d*c", sname[t], 10, &sprogress[t]) != EOF)
		{
			t++;
		}
		fclose(fp);
	}
}
//Ç°½ø
void addHead() 
{
	if (flagWA == 0 && head != nullptr&&head->next != nullptr)
	{
		snake*node = (snake*)malloc(sizeof(snake));
		node->x = head->x;
		node->y = head->y;
		node->next = head->next;
		head->next->prev = node;
		head->next = node;
		node->prev = head;

		head->x += speed * cos(direction / 180.0*Pi);
		head->y -= speed * sin(direction / 180.0*Pi);

		if (mode != 3)
		{
			head->x = ((head->x - 15) + 450) % 450 + 15;
			head->y = ((head->y - 15) + 450) % 450 + 15;
		}
		nodes++;
	}
}
//È¥³ýÎ²°Í½áµã
void cutTail()
{
	if (tail != nullptr&&tail->prev != nullptr)
	{
		map[tail->x/15][tail->y/15] = 0;
		tail = tail->prev;
		free(tail->next);
		tail->next = NULL;
		nodes--;
	}
}
//´òÓ¡µØÍ¼£¨Ã¿²½¶¼µ÷ÓÃ£©
void showMap()
{
	putimage(0, 0, &background);
//	setfillcolor(0x247cff);
	for (int i = 0; i < W; i++)
	{
		for (int j = 0; j < H; j++)
		{
			if (map[i][j] == 1 && mode == 3)
				solidrectangle(15 * i, 15 * j, 15 * (i + 1), 15 * (j + 1));
			else if (map[i][j] == 3)
				putimage(15 * i, 15 * j, &posionimg);
			else if (map[i][j] == 4)
				putimage(15 * i, 15 * j, &foodimg);
			else if (map[i][j] == 5)
				putimage(15 * i, 15 * j, &bombimg);
			else if (map[i][j] == 6)
			{
				if (((Timer % 10000) / 100) % 2 == 0)
					putimage(15 * i, 15 * j, &lightimg);
				else
					putimage(15 * i, 15 * j, &light2img);
			}
			else if (map[i][j] == 7)
				putimage(15 * i, 15 * j, &holeimg);
			else if (map[i][j] == 8)
				putimage(15 * i, 15 * j, &wisimg);
		}
	}

	snake*p = head->next;
	while (p != NULL)
	{
		solidcircle(p->x, p->y, 6);
		p = p->next;
	}

	settextstyle(20, 0, _T("Î¢ÈíÑÅºÚ"));
	_stprintf_s(num, TEXT("%d"), Timer/1000);
	outtextxy(580, 65, num);
	_stprintf_s(num, TEXT("%d"), score);
	outtextxy(645, 150, num);
	_stprintf_s(num, TEXT("%d"), nodes);
	outtextxy(645, 110, num);
}
//Éú³ÉËæ»ú×ø±ê
void makeXY()
{
	tempX = rand() % (W - 2) + 1, seed++;
	tempY = rand() % (H - 2) + 1, seed++;
}
//ÖÆ×÷µÀ¾ß£¨³ýÁËÉÁµç£©
void make(char n)
{
	makeXY();
	while (map[tempX][tempY] != 0)
		makeXY();
	map[tempX][tempY] = n;

}
//¶¨Ê±³öµÀ¾ß
void makeStuff()
{
	if (((Timer % 60000) / 1000) % 30 == 5 && flag == 0)
	{
		make(POSION);
		if ((((Timer % 60000) / 1000) == 5)&&mode!=1)
		{
			make(BOMB);
			make(HOLE);
		}
		flag = 1;
	}
	if (((Timer % 60000) / 1000) % 30 != 5)
		flag = 0;
}
//ÖÆ×÷ÉÁµç
void makeLight()
{
	char cout;
	if (mode != 4)
		cout = 20 * mode;
	else if (mode == 4)
		cout = 30;
	if (((Timer % 60000) / 1000) == 50 && flagP == 0)
	{
		for (int i = 0; i < cout; i++)
		{
			make(LIGHT);
		}
		make(WIS);
		flagP = 1;
	}
	else if (((Timer % 60000) / 1000) == 0 && flagP == 1)
	{
		for (int i = 0; i < W; i++)
		{
			for (int j = 0; j < H; j++)
			{
				if (map[i][j] == LIGHT || map[i][j] == WIS)
				{
					map[i][j] = 0;
				}
			}
		}
		flagP = 0;
	}
}
//³ÔÊ³ÎïµÄº¯Êý
void foodAct()
{
	putimage(head->x - 10, head->y - 10, &foodfaceimg);
	mciSendString(TEXT("play Resource\\chomp.mp3"), NULL, 0, NULL);
	addHead();
	make(FOOD);
	score += 5;
}
//Ñ°Â·º¯Êý
void BFS()
{

	startx = head->x/15;
	starty = head->y/15;

	headw = 1;
	tailw = 1;

	que[tailw].x = startx;
	que[tailw].y = starty;
	que[tailw].father = 0;
	que[tailw].step = 0;
	tailw++;
	book[startx][starty] = 1;

	flagW = 0;

	while (headw<tailw) {
		for (int k = 0; k <= 3; k++)
		{
			tx = que[headw].x + next[k][0];
			ty = que[headw].y + next[k][1];
			if (tx == 0 || tx == H - 1 || ty == 0 || ty == W - 1 || (map[tx][ty] != 0 && map[tx][ty] != FOOD))
			{
				continue;
			}
			if ((map[tx][ty] == 0 || map[tx][ty] == FOOD ) && book[tx][ty] == 0)
			{
				book[tx][ty] = 1;
				que[tailw].x = tx;
				que[tailw].y = ty;
				que[tailw].father = headw;
				que[tailw].step = que[headw].step + 1;
				tailw++;
			}
			if (map[tx][ty] == 4)
			{
				flagW = 1;
				break;
			}
		}
		if (flagW == 1)
		{
			break;
		}
		headw++;
	}
	Step = tailw - 1;
	for (int i = que[tailw - 1].step ; i > 0; i--)
	{
		WISxy[i][0] = que[Step].x;
		WISxy[i][1] = que[Step].y;
		Step = que[Step].father;
	}
}
//ÖÇ»Û²Ýº¯Êý
void wisdom()
{
	flagWA = 1;
	for (int j = 1; j <= que[tailw-1].step ; j++)
	{
		snake*node = (snake*)malloc(sizeof(snake));
		node->x = head->x;
		node->y = head->y;
		node->next = head->next;
		head->next->prev = node;
		head->next = node;
		node->prev = head;

		head->x = WISxy[j][0] * 15 + 5;
		head->y = WISxy[j][1] * 15 + 5;
		nodes++;
	
		cleardevice();
		showMap();
		putimage(head->x - 10, head->y - 10, &wisfaceimg);
		FlushBatchDraw();
		detect();
		Timer = clock() - Timer0;
		makeStuff();
		makeLight();
		if (GetAsyncKeyState(80) & 0x8000)
			system("pause");
		Sleep(50);
	}
	memset(que, 0, sizeof(note) * H * W);
	memset(book, 0, sizeof(book));
	memset(WISxy, 0, sizeof(WISxy));
	flagWA = 0;
}
//¼ì²âµ±Ç°³Ôµ½ÁËÊ²Ã´
void detect()
{
	switch (map[head->x/15][head->y/15])
	{
	case 0:
			if (map[(head->x + 10) / 15][(head->y) / 15] == 4)
			{
				map[(head->x + 10) / 15][(head->y) / 15] = 0;
				foodAct();
			}
			else if (map[(head->x - 10) / 15][(head->y) / 15] == 4)
			{
				map[(head->x - 10) / 15][(head->y) / 15] = 0;
				foodAct();
			}
			else if (map[(head->x) / 15][(head->y - 10) / 15] == 4)
			{
				map[(head->x) / 15][(head->y - 10) / 15] = 0;
				foodAct();
			}
			else if (map[(head->x) / 15][(head->y + 10) / 15] == 4)
			{
				map[(head->x) / 15][(head->y + 10) / 15] = 0;
				foodAct();
			}
			else if (map[(head->x + 8) / 15][(head->y + 8) / 15] == 4)
			{
				map[(head->x + 8) / 15][(head->y + 8) / 15] = 0;
				foodAct();
			}
			else if (map[(head->x + 8) / 15][(head->y - 8) / 15] == 4) 
			{
				map[(head->x + 8) / 15][(head->y - 8) / 15] = 0;
				foodAct();
			}
			else if (map[(head->x - 8) / 15][(head->y + 8) / 15] == 4)
			{
				map[(head->x - 8) / 15][(head->y + 8) / 15] = 0;
				foodAct();
			}
			else if (map[(head->x - 8) / 15][(head->y - 8) / 15] == 4)
			{
				map[(head->x - 8) / 15][(head->y - 8) / 15] = 0;
				foodAct();
			}
			else
			{
				putimage(head->x - 10, head->y - 10, &faceimg);
				map[head->x / 15][head->y / 15] = 2;
				addHead();
				cutTail();
			}
		break;
	case WALL:
		live = 0;
		break;
	case BODY:
		putimage(head->x - 10, head->y - 10, &faceimg);
		addHead();
		cutTail();
		break;
	case POSION:
		map[head->x / 15][head->y / 15] = 2;
		putimage(head->x - 10, head->y - 10, &posionfaceimg);
		mciSendString(TEXT("play Resource\\chomp.mp3"), NULL, 0, NULL);
		addHead();
		cutTail();
		cutTail();
		score -= 3;
		break;
	case FOOD:
		map[head->x / 15][head->y / 15] = 2;
		putimage(head->x - 10, head->y - 10, &foodfaceimg);
		mciSendString(TEXT("play Resource\\chomp.mp3"), NULL, 0, NULL);
		addHead();
		make(FOOD);
		score += 5;
		break;
	case BOMB:
		map[head->x / 15][head->y / 15] = 2;
		putimage(head->x - 10, head->y - 10, &bombfaceimg);
		mciSendString(TEXT("play Resource\\bomb.mp3"), NULL, 0, NULL);
		for (int i = 0; i < nodes; i++)
			cutTail();
		addHead();
		score -= 10;
		break;
	case LIGHT:
		map[head->x / 15][head->y / 15] = 2;
		putimage(head->x - 10, head->y - 10, &posionfaceimg);
		mciSendString(TEXT("play Resource\\thunder.mp3"), NULL, 0, NULL);
		addHead();
		cutTail();
		cutTail();
		score -= 2;
		break;
	case HOLE:
		cutTail();
		break;
	case WIS:
		map[head->x / 15][head->y / 15] = 2;
		for (int i = 0; i < 8; i++)
		{
			BFS();
			wisdom();
		}
		direction = 45;
		break;
	}
}
//·µ»Ø²Ëµ¥Ê±É¾³ýÓÎÏ·Êý¾Ý
void del()
{
	snake* p=head;
	while (p->next != nullptr)
	{
		p = p->next;
		free(p->prev);
	}
	free(p);
	
	for (int i = 0; i < W; i++)
	{
		for (int j = 0; j < H; j++)
		{
			if (i == 0 || j == 0 || i == W - 1 || j == H - 1)
				map[i][j] = 1;
			else
				map[i][j] = 0;
		}
	}
}
//ÊÇ·ñ×²×Ô¼º
void ifBump()
{
	snake*p = head->next->next->next->next;
	while (p != NULL)
	{
		int distance;
		distance = (head->x - p->x)*(head->x - p->x) + (head->y - p->y)*(head->y - p->y);
		if (distance < 150)
		{
			live = 0;
			break;
		}
		p = p->next;
	}
}
//ÊÇ·ñ¹ý¶Ì
void ifDead()
{
	if (nodes < 2)
		live = 0;
}
