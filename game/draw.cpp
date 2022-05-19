#include"draw.h"

void DrawString(SDL_Surface *screen, int x, int y, const std::string text, SDL_Surface *charset){
	int px, py, c;
	SDL_Rect s, d;
	s.w = 31;
	s.h = 31;
	d.w = 8;
	d.h = 8;
	for(int i=0;i<text.size();i++) {
		c = text[i];
		px = (c % 16) * 32;
		py = (c / 16) * 32;
		s.x = px;
		s.y = py;
		d.x = x;
		d.y = y;
		SDL_BlitSurface(charset, &s, screen, &d);
		if(text[i]>='0' && text[i]<='9') x+=15;
		else x+=21;
		};
}





void DrawPixel(SDL_Surface *surface, int x, int y, Uint32 color){
	int bpp = surface->format->BytesPerPixel;
	Uint8 *p = (Uint8 *)surface->pixels + y * surface->pitch + x * bpp;
	*(Uint32 *)p = color;
}




void DrawLine(SDL_Surface *screen, int x, int y, int l, int dx, int dy, Uint32 color){
	for(int i = 0; i < l; i++) {
		DrawPixel(screen, x, y, color);
		x += dx;
		y += dy;
		}
	}


void DrawRectangle(SDL_Surface *screen, int x, int y, int l, int k,
                   Uint32 outlineColor, Uint32 fillColor) {
	int i;
	DrawLine(screen, x, y, k, 0, 1, outlineColor);
	DrawLine(screen, x + l - 1, y, k, 0, 1, outlineColor);
	DrawLine(screen, x, y, l, 1, 0, outlineColor);
	DrawLine(screen, x, y + k - 1, l, 1, 0, outlineColor);
	for(i = y + 1; i < y + k - 1; i++)
		DrawLine(screen, x + 1, i, l - 2, 1, 0, fillColor);
	}


void DrawPoint(SDL_Surface *screen, int X, int Y, int width, const std::string number, SDL_Surface *charset) {
	int length = number.size();
	DrawString(screen, (X + width / 2) -15 -length*6, Y + width / 2 - 15, number, charset);
}

void DrawBoard(SDL_Surface *screen, int **tab, int size, Uint32 outlineColor, Uint32 fillColor, SDL_Surface *charset, int BOARD_WIDTH , int x,int y) {
	int width = (BOARD_WIDTH / size) -2;
	int X, Y;
	std::string number;
	char n[5];
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			X = x + (BOARD_WIDTH / size)*i;
			Y = y + (BOARD_WIDTH / size)*j;
			int color_power = get_power(tab[i][j]);
			DrawRectangle(screen, Y, X, width, width, outlineColor, SDL_MapRGB(screen->format, 120, 120 + 10 * color_power, 196 + 10*color_power));
			if(tab[i][j] == 0) number="";
			else {
				sprintf(n, "%d", tab[i][j]);
				number+=n;
			}
			DrawPoint(screen, Y, X, width, number, charset);
			number="";
		}
	}
}

void DrawScore(SDL_Surface *screen, unsigned int score, SDL_Surface *charset,int x,int y) {
	int width = 60;
	char n[18];
	std::string number;
	sprintf(n, "score: %u", score);
	number += n;
	DrawPoint(screen, x, y, width, number, charset);
}
