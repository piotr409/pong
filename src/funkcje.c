#include <allegro.h>


void rysuj_panele(BITMAP *bufor) {
	
	//rysujemy górny pasek i go wypełniamy kolorem
	rect(bufor,0,0, 640, 50, makecol(30,30,30));
	floodfill(bufor,10,10,makecol(20,120,20));

	//rysujemy dolny pasek i go wypełniamy kolorem
	rect(bufor,0,450, 640, 480, makecol(30,30,30));
	floodfill(bufor,635,470,makecol(20,120,20));
	
}

