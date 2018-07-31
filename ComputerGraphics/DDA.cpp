/**
 * Name: Meet Mangukiya
 * Roll Number: 1614023
 * Batch: A2
 */

#include<stdio.h>
#include<string.h>
#include<conio.h>
#include<graphics.h>

void draw_line(int, int, int, int);
void draw_character(char, int, int, int);
void draw_string(char*, int, int, int);

int main()
{
	int gd = DETECT, gm;

	initgraph(&gd,&gm,"C:\\TurboC\\TC\\BGI");

	draw_string("meet", 0, 0, 15);

	getch();
	closegraph();
	return 1;
}

/** Draw a line using DDA algorithm */
void draw_line(int x1, int y1, int x2, int y2)
{
	int dx = (x2 > x1) ? x2 - x1 : x1 - x2;
	int dy = (y2 > y1) ? y2 - y1 : y1 - y2;

	int steps = (dx > dy) ? dx : dy;

	float xinc = (float)dx / steps;
	float yinc = (float)dy / steps;

	float tx = x1, ty = y1;
	int sx = (x1 < x2) ? 1 : -1, sy = (y1 < y2) ? 1 : -1;

	for(int i = 0; i < steps; i++)
	{
		putpixel(tx, ty, WHITE);
		tx += sx * xinc;
		ty += sy * yinc;
	}
}

/** Draw a string(character by character) with given stroke. */
void draw_string(char* string, int x, int y, int stroke)
{
	int tx = x, ty = y;
	for(int i = 0; i < strlen(string); i++)
	{
		char a = string[i];
		draw_character(a, tx, ty, stroke);
		tx += stroke;
		tx += 5;
	}
}

/**
 * Draw a given character with given stroke.
 *
 * NOTE: Currently only a subset of characters' rendering is implemented
 */
void draw_character(char a, int x , int y, int stroke)
{
	switch (a) {
		case 'a':
			draw_line(x, y, x + stroke, y);
			draw_line(x, y, x, y + stroke * 2);
			draw_line(x + stroke, y, x + stroke, y + stroke * 2);
			draw_line(x, y + stroke, x + stroke, y + stroke);
			break;
		case 'e':
			draw_line(x, y, x, y + 2 * stroke);
			draw_line(x, y, x + stroke, y);
			draw_line(x, y + stroke, x + stroke, y + stroke);
			draw_line(x, y + 2 * stroke, x + stroke, y + 2 * stroke);
			break;
		case 'h':
			draw_line(x + stroke, y, x + stroke, y + 2 * stroke);
			draw_line(x, y, x, y + 2 * stroke);
			draw_line(x, y + stroke, x + stroke, y + stroke);
			break;
		case 'i':
			draw_line(x, y, x + stroke, y);
			draw_line(x, y + 2 * stroke, x + stroke, y + 2 * stroke);
			draw_line(x + stroke / 2, y, x + stroke / 2, y + 2 * stroke);
			break;
		case 'l':
			draw_line(x, y, x, y + 2 * stroke);
			draw_line(x, y + 2 * stroke, x + stroke, y + 2 * stroke);
			break;
		case 'm':
			draw_line(x, y, x, y + 2 * stroke);
			draw_line(x + stroke, y, x + stroke, y + 2 * stroke);
			draw_line(x, y, x + stroke / 2, y + stroke);
			draw_line(x + stroke / 2, y + stroke, x + stroke, y);
			break;
		case 'o':
			draw_line(x, y, x + stroke, y);
			draw_line(x, y, x, y + 2 * stroke);
			draw_line(x + stroke, y, x + stroke, y + 2 * stroke);
			draw_line(x, y + 2 * stroke, x + stroke, y + 2 * stroke);
			break;
		case 'r':
			draw_line(x, y, x, y + 2 * stroke);
			draw_line(x, y, x + stroke, y);
			draw_line(x + stroke, y, x + stroke, y + stroke);
			draw_line(x, y + stroke, x + stroke, y + stroke);
			draw_line(x + stroke / 2, y + stroke, x + stroke, y + 2 * stroke);
			break;
		case 's':
			draw_line(x, y, x + stroke, y);
			draw_line(x, y, x, y + stroke);
			draw_line(x, y + stroke, x + stroke, y + stroke);
			draw_line(x + stroke, y + stroke, x + stroke, y + 2 * stroke);
			draw_line(x, y + 2 * stroke, x + stroke, y + 2 * stroke);
			break;
		case 't':
			draw_line(x, y, x + stroke, y);
			draw_line(x + stroke / 2, y, x + stroke / 2, y + 2 * stroke);
			break;
		case 'u':
			draw_line(x, y, x, y + 2 * stroke);
			draw_line(x + stroke, y, x + stroke, y + 2 * stroke);
			draw_line(x, y + 2 * stroke, x + stroke, y + 2 * stroke);
			break;
		case 'v':
			draw_line(x, y, x + stroke / 2, y + 2 * stroke);
			draw_line(x + stroke, y, x + stroke / 2, y + 2 * stroke);
			break;
		case 'y':
			draw_line(x, y, x, y + stroke);
			draw_line(x + stroke, y, x + stroke, y + stroke);
			draw_line(x, y + stroke, x + stroke, y + stroke);
			draw_line(x + stroke / 2, y + stroke, x + stroke / 2, y + 2 * stroke);
			break;
		case '<':
			draw_line(x, y + stroke, x + stroke, y);
			draw_line(x, y + stroke, x + stroke, y + 2 * stroke);
			break;
		case '3':
			draw_line(x, y, x + stroke / 2, y);
			draw_line(x, y + 2 * stroke, x + stroke / 2, y + 2 * stroke);
			draw_line(x, y + stroke, x + stroke / 2, y + stroke);
			draw_line(x + stroke / 2, y, x + stroke, y + stroke / 2);
			draw_line(x + stroke / 2, y + stroke, x + stroke, y + stroke / 2);
			draw_line(x + stroke / 2, y + stroke, x + stroke, y + stroke * 1.5);
			draw_line(x + stroke / 2, y + 2 * stroke, x + stroke, y + stroke * 1.5);
			break;
	}
}
