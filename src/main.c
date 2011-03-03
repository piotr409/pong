#include <allegro.h>
#include "funkcje.h"
//kompilacja gcc -o test main.c `allegro-config --cflags --libs`

volatile long speed = 0;
void increment_speed()
{
    speed++;
}

END_OF_FUNCTION(increment_speed);

LOCK_VARIABLE(speed);
LOCK_FUNCTION(increment_speed);


int main()
{

    allegro_init();
    install_keyboard();
    set_color_depth(24);
    set_gfx_mode(GFX_AUTODETECT_WINDOWED, 640, 480, 0, 0);
    set_palette(default_palette);
	install_timer();
    install_int_ex(increment_speed, BPS_TO_TIMER(120));
    //Kod powyżej będziemy używać zawsze do naszego projektu
    clear_to_color(screen, makecol(0, 255, 0));	//ustawianie koloru tła
    BITMAP *bufor = NULL;
    bufor = create_bitmap(640, 480);	// stosujemy podwójne buforowanie by nie migał ekran
	int x = losuj();
    if (!bufor) {
	set_gfx_mode(GFX_TEXT, 0, 0, 0, 0);
	allegro_message("Nie mogę utworzyć bufora !");
	allegro_exit();
	return 0;
    }
    int wynik1 = 0;
    int wynik2 = 0;
    int srodek1 = 244;
    int srodek2 = 244;

    while (!key[KEY_ESC]) {	//pętla dopóki nikt nie wciśnie ESC
	clear_to_color(bufor, makecol(150, 150, 150));

	while (speed > 0) {

	    if (key[KEY_W] && srodek2 > 110)
		srodek2--;
	    if (key[KEY_S] && srodek2 < 390)
		srodek2++;
	    if (key[KEY_UP]  && srodek1 > 110)
		srodek1--;
	    if (key[KEY_DOWN] && srodek1 < 390)
		srodek1++;

	    speed--;
	}
	rysuj_deske(bufor, 1, srodek1);	
	rysuj_deske(bufor, 2, srodek2);
	rysuj_panele(bufor);
	rysuj_wynik(bufor, wynik1, wynik2);
	rysuj_pilke(bufor, 300, 250);
	blit(bufor, screen, 0, 0, 0, 0, 640, 480);	//kopiujemy bufor na ekran

	
    }

    allegro_exit();
    return 0;
}

END_OF_MAIN();
