#include <allegro.h>
#include <time.h>
#include <stdlib.h>
#define rozmiar_pilka 25
#define deska_rozmiar 57

void rysuj_panele(BITMAP * bufor)
{

    rect(bufor, 0, 0, 640, 52, makecol(30, 30, 30));
    floodfill(bufor, 10, 10, makecol(20, 120, 20));

    //rysujemy dolny pasek i go wypełniamy kolorem
    rect(bufor, 0, 450, 640, 480, makecol(30, 30, 30));
    floodfill(bufor, 635, 470, makecol(20, 120, 20));

}

void rysuj_wynik(BITMAP * bufor, int wynik1, int wynik2)
{
    FONT *myfont;
    PALETTE palette;
    myfont = load_font("24.pcx", palette, NULL);
    //rysujemy górny pasek i go wypełniamy kolorem
    textprintf_ex(bufor, myfont, 290, 7, makecol(200, 200, 200), -1,
		  "%d : %d", wynik1, wynik2);

}

void rysuj_deske(BITMAP * bufor, int nr_gracza, int srodek)
{

    if (nr_gracza == 1) {
	rect(bufor, 0, srodek - deska_rozmiar, 10, srodek + deska_rozmiar, makecol(30, 30, 30));
	floodfill(bufor, 5, srodek, makecol(245, 185, 0));
    } else {
	rect(bufor, 630, srodek - deska_rozmiar, 640, srodek + deska_rozmiar, makecol(30, 30, 30));
	floodfill(bufor, 635, srodek, makecol(245, 185, 0));
    }

}

void rysuj_pilke(BITMAP * bufor, int x_pilka, int y_pilka)
{
	circle(bufor, x_pilka, y_pilka, rozmiar_pilka, makecol(255,64,64));
	circlefill(bufor, x_pilka, y_pilka, rozmiar_pilka-5, makecol(255,112,41));
	floodfill(bufor, x_pilka, y_pilka+rozmiar_pilka-1, makecol(255,230,102));
}

int losuj() 
{
	srand(time(0));
	return rand()%2;
}

