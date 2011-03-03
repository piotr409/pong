#include <allegro.h>
//kompilacja gcc -o test main.c `allegro-config --cflags --libs`

int main()
{
    allegro_init();
    install_keyboard();
    set_color_depth(24);
    set_gfx_mode(GFX_AUTODETECT_WINDOWED, 640, 480, 0, 0);
    set_palette(default_palette);
    //Kod powyżej będziemy używać zawsze do naszego projektu
    clear_to_color(screen, makecol(0, 255, 0));	//ustawianie koloru tła
	BITMAP *bufor = NULL;
    bufor = create_bitmap(640, 480);	// stosujemy podwójne buforowanie by nie migał ekran
    if (!bufor) {
	set_gfx_mode(GFX_TEXT, 0, 0, 0, 0);
	allegro_message("Nie mogę utworzyć bufora !");
	allegro_exit();
	return 0;
    }
    while (!key[KEY_ESC]) {   //pętla dopóki nikt nie wciśnie ESC
	clear_to_color(bufor, makecol(150,150,150));

	//rysujemy górny pasek i go wypełniamy kolorem
	//rect(bufor,0,0, 640, 50, makecol(30,30,30));
	//floodfill(bufor,10,10,makecol(20,120,20));

	//rysujemy dolny pasek i go wypełniamy kolorem
	//rect(bufor,0,450, 640, 480, makecol(30,30,30));
	//floodfill(bufor,635,470,makecol(20,120,20));
	rysuj_panele();
	blit( bufor, screen, 0,0,0,0, 640,480); //kopiujemy bufor na ekran
    }
    readkey();			// Program oczekuje na dowolny klawisz

    allegro_exit();
    return 0;
}

END_OF_MAIN();
