// NOTE THAT ANSWER #10 IS NOT CORRECT
// ACSL All-Stars 2002 Problem 8: Karnough
// by Steven Sivek, age 7 1/2, TJHSST
// 31337 |-|4x0|^z r0x0r j00r b0x0r!!!@#%@$&%

#include <stdio.h>

void getInput(int A);
void run();
int getSquare(int x, int y, int len, int wid);
int checkRegion(int x, int y, int len, int wid);
void fillRegion(int x, int y, int len, int wid);
void printRegion3(int x, int y, int len, int wid);
void printRegion4(int x, int y, int len, int wid);
void fixList();

void printBigMap();
void print3(int a, int b, int c);
void print4(int a, int b, int c, int d);

int nVar, width;
int table[100][100];
int doable[10][10][10][10];
int checkedRegion[10][10][10][10];
int visited[10][10][10][10];
const int gray[] = { 0, 1, 3, 2 };
int ILOVEACSL;
int list[1000][4], nList;

int main() {
	for (int i = 0; i < 5; i++) { getInput(i+1); run(); }
	return 0;
}

void getInput(int A)
{
	char str[100];

	printf("%d: ", A);
	scanf("%d", &nVar);
	width = (nVar == 3) ? 2 : 4;

	for (int i = 0; i < 4; i++)
	{
		scanf("%s", str);
		for (int j = 0; str[j]; j++)
			table[i][j] = (str[j] == '0') ? 0 : 1;
	}
}

void run()
{
	printBigMap();

	for (int I = 0; I <= 4; I++)
	for (int J = 0; J <= 4; J++)
	for (int K = 0; K <= 4; K++)
	for (int M = 0; M <= 4; M++)
	{
		checkedRegion[I][J][K][M] = 0;
		doable[I][J][K][M] = 0;
		visited[I][J][K][M] = 0;
	}

	//
	// Identify squares
	//
	for (int i = 0; i < 4; i++)
	for (int j = 0; j < width; j++)
	if (table[i][j])
		int foo = getSquare(i, j, 1, 1);

	//
	// Print output
	//

	if (doable[0][0][4][(nVar==3) ? 2 : 4]) // just in case
		printf("1");
	else
	{
		int baz = 0;
		nList = 0;

		for (int a = 0; a < 4; a++)
		for (int b = 0; b < width; b++)
			for (int c = 1; c <= 4; c++)
			for (int d = 1; d <= width; d++)
				if (doable[a][b][c][d])
				{
					list[nList][0] = a;
					list[nList][1] = b;
					list[nList][2] = c;
					list[nList][3] = d;
					nList++;
				}
		fixList();

		for (int e = 0; e < nList; e++)
		{
			if (baz) printf(" + ");
			
			if (nVar == 3)
				printRegion3(list[e][0], list[e][1], list[e][2], list[e][3]);
			else
				printRegion4(list[e][0], list[e][1], list[e][2], list[e][3]);
			
			baz = 1;
		}

		if (!baz) printf("0");
	}

	printf("\n\n");
}

int getSquare(int x, int y, int len, int wid)
{
	int bar = 0;

	if (visited[x][y][len][wid]) return checkRegion(x, y, len, wid);
	visited[x][y][len][wid] = 1;

	if (len > 4 || wid > width) return 0;
	if (!checkRegion(x, y, len, wid)) return 0;

	//
	// We have a valid rectangle of 1's; do stuff with it
	//

	// Check the possible bigger squares to see if this is the biggest possible
	int sq1 = getSquare(x, y, len*2, wid);
	int sq2 = getSquare(x, y, len, wid*2);
	
	if (!sq1 && !sq2 && !checkedRegion[x][y][len][wid])
	// This is as big as it gets - mark it doable
		bar = 1;
		
	if (!checkedRegion[x][y][len][wid])
	{
		if (len == 4)
			for (int i = 0; i < 4; i++)
				fillRegion(i, y, len, wid);

		if (wid == width)
			for (int j = 0; j < width; j++)
				fillRegion(x, j, len, wid);

		if (len==4 && wid==width)
			for (int m = 0; m < 4; m++)
			for (int n = 0; n < width; n++)
				fillRegion(m, n, len, wid);
	}

	fillRegion(x, y, len, wid);
	if (bar) doable[x][y][len][wid] = 1;

	return 1;
}

int checkRegion(int x, int y, int len, int wid)
{
	for (int i = x; i < x+len; i++)
		for (int j = y; j < y+wid; j++)
			if (!table[i%4][j%width]) return 0;

	return 1;
}

void fillRegion(int x, int y, int len, int wid)
// Mark everything excessively small as untouchable
{
	for (int i = len; i > 0; i /= 2)
	for (int j = wid; j > 0; j /= 2)
		for (int m = x; m+i <= x+len; m++)
		for (int n = y; n+j <= y+wid; n++)
		{
			checkedRegion[m%4][n%width][i][j] = 1;
			doable[m%4][n%width][i][j] = 0;
		}
}

//
// Given a rectangular region, print out the expression
// which it represents in (X,Y,C) or in (W,X,Y,Z)
//

void printRegion3(int x, int y, int len, int wid)
{
	int useX=0, valX;
	int useY=0, valY;
	int useC=0, valC;

	if ((x == 0 && (len == 1 || len == 2)) || (x == 1 && (len == 1)))
		{ useX = 1; valX = 0; }
	if ((x == 2 && (len == 1 || len == 2)) || (x == 3 && (len == 1)))
		{ useX = 1; valX = 1; }

	if ((x == 3 && (len == 1 || len == 2)) || (x == 0 && (len == 1)))
		{ useY = 1; valY = 0; }
	if ((x == 1 && (len == 1 || len == 2)) || (x == 2 && (len == 1)))
		{ useY = 1; valY = 1; }

	if (y == 0 && wid == 1) { useC = 1; valC = 0; }
	if (y == 1 && wid == 1) { useC = 1; valC = 1; }

	if (useX) printf("X%s", (valX) ? "" : "'");
	if (useY) printf("Y%s", (valY) ? "" : "'");
	if (useC) printf("C%s", (valC) ? "" : "'");
}

void printRegion4(int x, int y, int len, int wid)
{
	int useW=0, valW;
	int useX=0, valX;
	int useY=0, valY;
	int useZ=0, valZ;

	if ((x == 0 && (len == 1 || len == 2)) || (x == 1 && (len == 1)))
		{ useW = 1; valW = 0; }
	if ((x == 2 && (len == 1 || len == 2)) || (x == 3 && (len == 1)))
		{ useW = 1; valW = 1; }

	if ((x == 3 && (len == 1 || len == 2)) || (x == 0 && (len == 1)))
		{ useX = 1; valX = 0; }
	if ((x == 1 && (len == 1 || len == 2)) || (x == 2 && (len == 1)))
		{ useX = 1; valX = 1; }

	if ((y == 0 && (wid == 1 || wid == 2)) || (y == 1 && (wid == 1)))
		{ useY = 1; valY = 0; }
	if ((y == 2 && (wid == 1 || wid == 2)) || (y == 3 && (wid == 1)))
		{ useY = 1; valY = 1; }

	if ((y == 3 && (wid == 1 || wid == 2)) || (y == 0 && (wid == 1)))
		{ useZ = 1; valZ = 0; }
	if ((y == 1 && (wid == 1 || wid == 2)) || (y == 2 && (wid == 1)))
		{ useZ = 1; valZ = 1; }


	if (useW) printf("W%s", (valW) ? "" : "'");
	if (useX) printf("X%s", (valX) ? "" : "'");
	if (useY) printf("Y%s", (valY) ? "" : "'");
	if (useZ) printf("Z%s", (valZ) ? "" : "'");
}

void fixList()
{
	int ok, array[10][10], good;

	do
	{
		ok = 1;
		int i;

		// Check a piece for redundancy
		for (i = 0; i < nList; i++)
		{
			for (int m = 0; m < 4; m++)
			for (int n = 0; n < width; n++)
				array[m][n] = 0;

			for (int j = 0; j < nList; j++) if (i != j)
			{
				int X = list[j][0], Y = list[j][1];
				int dx = list[j][2], dy = list[j][3];
				for (int p = 0; p < dx; p++)
				for (int q = 0; q < dy; q++)
					array[(X+p)%4][(Y+q)%width] = 1;
			}

			int x = list[i][0], y = list[i][1];
			int Dx = list[i][2], Dy = list[i][3];
			good = 0;

			for (int u = 0; u < Dx; u++)
			for (int v = 0; v < Dy; v++)
				if (!array[(x+u)%4][(y+v)%width])
					good = 1;

			if (!good) break;
		}

		if (!good) // Swap out number i
		{
			--nList;
			list[i][0] = list[nList][0];
			list[i][1] = list[nList][1];
			list[i][2] = list[nList][2];
			list[i][3] = list[nList][3];
			ok = 0;
		}
	} while (!ok);
}

//////////////////////////////////////////////////
//////////////////////////////////////////////////
// For 5 points: Unsimplified expressions       //
// For great justice: Move `zig'!               //
//////////////////////////////////////////////////
//////////////////////////////////////////////////
void printBigMap()
{
	ILOVEACSL = 0;

	for (int i = 0; i < 4; i++)
	{
		int is0 = (gray[i] & 2) ? 1 : 0;
		int is1 = (gray[i] & 1) ? 1 : 0;
		int is2, is3;

		if (nVar == 3)
		{
			for (int j = 0; j < 2; j++)
			{
				is2 = (j) ? 1 : 0;
				if (table[i][j])
				{
					if (ILOVEACSL)
						printf(" + ");
					print3(is0, is1, is2);
					ILOVEACSL = 1;
				}
			}
		}

		else
		{
			for (int j = 0; j < 4; j++)
			{
				is2 = (gray[j] & 2) ? 1 : 0;
				is3 = (gray[j] & 1) ? 1 : 0;

				if (table[i][j])
				{
					if (ILOVEACSL)
						printf(" + ");
					print4(is0, is1, is2, is3);
					ILOVEACSL = 1;
				}
			}
		}
	}

	if (!ILOVEACSL)
		printf("0");

	printf("\n");
}


void print3(int a, int b, int c)
{
	printf("X%sY%sC%s", (a) ? "" : "'", (b) ? "" : "'", (c) ? "" : "'");
}

void print4(int a, int b, int c, int d)
{
	printf("W%sX%sY%sZ%s",
		(a) ? "" : "'", (b) ? "" : "'", (c) ? "" : "'", (d) ? "" : "'");
}