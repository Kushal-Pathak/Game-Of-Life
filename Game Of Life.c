// Game Of Life Simulation By Kushal Pathak
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <windows.h>
#define h 49
#define w 49
#define alive 'X'
#define dead ' '
char present[h][w];
char next[h][w];

void maximizeWindow();
void birth(int, int);
void die(int, int);
int isAlive(int, int);
void evolve();
void display();
void init(int);
void delay(float);
void set(int, int);
void pattern(int, int, int);
void menu();
void custom();

void main()
{
	maximizeWindow();
	init(0);
	menu();
	getch();
}
void evolve()
{
	int i, j, left, right, top, down, n;
	init(1); // reset next
	for (i = 0; i < h; i++)
	{
		for (j = 0; j < w; j++)
		{
			n = 0; // reset neighbours
			left = j - 1;
			right = j + 1; // j=xMid
			top = i - 1;
			down = i + 1; // i=yMid
			// if(left>-1&&left<w&&top>-1&&top<h){
			if (isAlive(left, top))
				n++;
			if (isAlive(j, top))
				n++;
			if (isAlive(right, top))
				n++;
			if (isAlive(left, i))
				n++;
			if (isAlive(right, i))
				n++;
			if (isAlive(left, down))
				n++;
			if (isAlive(j, down))
				n++;
			if (isAlive(right, down))
				n++;

			if (isAlive(j, i))
			{
				if (n < 2 || n > 3)
					die(j, i);
				else
					birth(j, i);
			}
			else
			{
				if (n == 3)
					birth(j, i);
			}
		}
	}
	init(0); // reset present
	init(2); // transfer to present
}
void birth(int x, int y)
{
	next[y][x] = alive;
}
void die(int x, int y)
{
	next[y][x] = dead;
}
void set(int x, int y)
{
	if (x > -1 && x < w && y > -1 && y < h)
		present[y][x] = alive;
}
int isAlive(int x, int y)
{
	if (present[y][x] == alive)
		return 1;
	return 0;
}
void display()
{
	system("cls");
	int i, j;
	for (i = 0; i < h; i++)
	{
		for (j = 0; j < w; j++)
		{
			printf("%c ", present[i][j]);
		}
		printf("\n");
	}
}
void delay(float n)
{
	int i, j, k;
	for (i = 0; i < 10000; i++)
	{
		for (j = 0; j < 1000; j++)
		{
			for (k = 0; k < 50 * n; k++)
				;
		}
	}
}
void init(int n)
{
	int i, j;
	switch (n)
	{
	case 0:
		for (i = 0; i < h; i++)
		{
			for (j = 0; j < w; j++)
			{
				present[i][j] = dead;
			}
		}
		break;
	case 1:
		for (i = 0; i < h; i++)
		{
			for (j = 0; j < w; j++)
			{
				next[i][j] = dead;
			}
		}
		break;
	case 2:
		for (i = 0; i < h; i++)
		{
			for (j = 0; j < w; j++)
				present[i][j] = next[i][j];
		}

	default:
		break;
	}
}

void pattern(int n, int x, int y)
{
	switch (n)
	{
	case 1: // glider
		set(2 + x, 2 + y);
		set(2 + x, 3 + y);
		set(2 + x, 4 + y);
		set(1 + x, 4 + y);
		set(0 + x, 3 + y);
		break;
	case 2: // blinker period 2
		set(3 + x, 2 + y);
		set(3 + x, 3 + y);
		set(3 + x, 4 + y);
		break;
	case 3: // toad period 2
		set(4 + x, 4 + y);
		set(5 + x, 4 + y);
		set(6 + x, 4 + y);
		set(3 + x, 5 + y);
		set(4 + x, 5 + y);
		set(5 + x, 5 + y);
		break;
	case 4: // beacon period 2
		set(1 + x, 1 + y);
		set(1 + x, 2 + y);
		set(2 + x, 1 + y);
		set(2 + x, 2 + y);
		set(3 + x, 3 + y);
		set(3 + x, 4 + y);
		set(4 + x, 3 + y);
		set(4 + x, 4 + y);
		break;
	case 5: // light weight spaceship
		set(3 + x, 2 + y);
		set(4 + x, 2 + y);
		set(5 + x, 2 + y);
		set(6 + x, 2 + y);
		set(6 + x, 3 + y);
		set(6 + x, 4 + y);
		set(5 + x, 5 + y);
		set(2 + x, 5 + y);
		set(2 + x, 3 + y);
		break;
	case 6: // middle weight spaceship
		set(4 + x, 3 + y);
		set(5 + x, 3 + y);
		set(6 + x, 3 + y);
		set(7 + x, 3 + y);
		set(8 + x, 3 + y);
		set(8 + x, 4 + y);
		set(8 + x, 5 + y);
		set(7 + x, 6 + y);
		set(5 + x, 7 + y);
		set(3 + x, 6 + y);
		set(3 + x, 4 + y);
		break;
	case 7: // heavy weight spaceship
		set(4 + x, 3 + y);
		set(5 + x, 3 + y);
		set(6 + x, 3 + y);
		set(7 + x, 3 + y);
		set(8 + x, 3 + y);
		set(9 + x, 3 + y);
		set(9 + x, 4 + y);
		set(9 + x, 5 + y);
		set(8 + x, 6 + y);
		set(6 + x, 7 + y);
		set(5 + x, 7 + y);
		set(3 + x, 6 + y);
		set(3 + x, 4 + y);
		break;
	case 8: // Penta-decathlon (period 15)
		set(9 + x, 8 + y);
		set(9 + x, 9 + y);
		set(8 + x, 10 + y);
		set(10 + x, 10 + y);
		set(9 + x, 11 + y);
		set(9 + x, 12 + y);
		set(9 + x, 13 + y);
		set(9 + x, 14 + y);
		set(8 + x, 15 + y);
		set(10 + x, 15 + y);
		set(9 + x, 16 + y);
		set(9 + x, 17 + y);
		break;
	case 9: // pulsar (period 3)
		set(5 + x, 3 + y);
		set(6 + x, 3 + y);
		set(7 + x, 3 + y); // top
		set(5 + x, 8 + y);
		set(6 + x, 8 + y);
		set(7 + x, 8 + y); // bottom
		set(3 + x, 5 + y);
		set(3 + x, 6 + y);
		set(3 + x, 7 + y); // left
		set(8 + x, 5 + y);
		set(8 + x, 6 + y);
		set(8 + x, 7 + y); // right

		set(5 + x + 6, 3 + y);
		set(6 + x + 6, 3 + y);
		set(7 + x + 6, 3 + y); // x+6
		set(5 + x + 6, 8 + y);
		set(6 + x + 6, 8 + y);
		set(7 + x + 6, 8 + y); // x+6
		set(3 + x + 7, 5 + y);
		set(3 + x + 7, 6 + y);
		set(3 + x + 7, 7 + y); // x+7
		set(8 + x + 7, 5 + y);
		set(8 + x + 7, 6 + y);
		set(8 + x + 7, 7 + y); // x+7

		set(5 + x, 3 + y + 7);
		set(6 + x, 3 + y + 7);
		set(7 + x, 3 + y + 7); // y+7
		set(5 + x, 8 + y + 7);
		set(6 + x, 8 + y + 7);
		set(7 + x, 8 + y + 7); // y+7
		set(3 + x, 5 + y + 6);
		set(3 + x, 6 + y + 6);
		set(3 + x, 7 + y + 6); // y+6
		set(8 + x, 5 + y + 6);
		set(8 + x, 6 + y + 6);
		set(8 + x, 7 + y + 6); // y+6

		set(5 + x + 6, 3 + y + 7);
		set(6 + x + 6, 3 + y + 7);
		set(7 + x + 6, 3 + y + 7); // x+6 y+7
		set(5 + x + 6, 8 + y + 7);
		set(6 + x + 6, 8 + y + 7);
		set(7 + x + 6, 8 + y + 7); // x+6 y+7
		set(3 + x + 7, 5 + y + 6);
		set(3 + x + 7, 6 + y + 6);
		set(3 + x + 7, 7 + y + 6); // x+7 y+6
		set(8 + x + 7, 5 + y + 6);
		set(8 + x + 7, 6 + y + 6);
		set(8 + x + 7, 7 + y + 6); // x+7 y+6
		break;
	case 10: // block (still life)
		set(x, y);
		set(1 + x, y);
		set(x, 1 + y);
		set(1 + x, 1 + y);
		break;
	case 11: // beehive (still life)
		set(1 + x, y);
		set(2 + x, y);
		set(x, 1 + y);
		set(3 + x, 1 + y);
		set(1 + x, y + 2);
		set(2 + x, y + 2);
		break;
	case 12: // loaf (still life)
		set(1 + x, y);
		set(2 + x, y);
		set(x, 1 + y);
		set(3 + x, 1 + y);
		set(1 + x, 2 + y);
		set(3 + x, 2 + y);
		set(2 + x, 3 + y);
		break;
	case 13: // boat (still life)
		set(x, y);
		set(1 + x, y);
		set(x, 1 + y);
		set(2 + x, 1 + y);
		set(1 + x, 2 + y);
		break;
	case 14: // tub (still life)
		set(1 + x, y);
		set(1 + x, 2 + y);
		set(x, 1 + y);
		set(2 + x, 1 + y);
		break;
	case 15: // infinite growth
		set(7 + x, 1 + y);
		set(7 + x, 2 + y);
		set(7 + x, 3 + y);
		set(8 + x, 2 + y);
		set(5 + x, 2 + y);
		set(5 + x, 3 + y);
		set(5 + x, 4 + y);
		set(3 + x, 5 + y);
		set(3 + x, 6 + y);
		set(1 + x, 6 + y);
		break;
	}
}
void menu()
{
	int choice, x, y, step, i, n;
	float d;
	char c;
	while (1)
	{
		i = 0;
		system("cls");
		printf("Game Of Life By Kushal Pathak\n");
		printf("1. Glider\n2. Blinker\n3. Toad\n4. Beacon\n");
		printf("5. Light Weight Spaceship\n6. Middle Weight Spaceship\n7. Heavy Weight Spaceship\n");
		printf("8. Penta-decathlon\n9. Pulsar\n10. Block\n11. Beehive\n12. Loaf\n13. Boat\n14: Tub\n");
		printf("15. Infinite Growth\n16. Custom Pattern\n17. Exit\nEnter CHOICE: ");
		scanf("%d", &choice);
		init(0);
		if (choice == 16)
			exit(1);
		if (choice == 16)
			custom();
		if (choice < 16)
		{
			printf("Enter position X, Y: ");
			scanf("%d %d", &x, &y);
			printf("Enter DELAY (eg 0.1): ");
			scanf("%f", &d);
			printf("Enter STEPS: ");
			scanf("%d", &step);
			pattern(choice, x, y);
			i = 0;
			while (i < step)
			{
				display();
				delay(d);
				evolve();
				i++;
			}
			getch();
		}
	}
}
void custom()
{
	int i, n, x, y, step;
	float d;
	system("cls");
	printf("Enter number of cells: ");
	scanf("%d", &n);
	for (i = 0; i < n; i++)
	{
		printf("Enter X Y: ");
		scanf("%d %d", &x, &y);
		set(x, y);
	}
	printf("Enter delay: ");
	scanf("%f", &d);
	printf("Enter steps: ");
	scanf("%d", &step);
	i = 0;
	while (i < step)
	{
		display();
		delay(d);
		evolve();
		i++;
	}
	getch();
}
void maximizeWindow()
{
	HWND hwnd = GetConsoleWindow();
	ShowWindow(hwnd, SW_SHOWMAXIMIZED);
}
