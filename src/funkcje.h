#ifndef funkcje_h
#define funkcje_h

	void rysuj_panele(BITMAP * bufor); // Funkcja rysująca panele w grze
	void rysuj_wynik(BITMAP * bufor, int wynik1, int wynik2);  // Funkcja pokazująca dotychczasowy wynik 
	void rysuj_deske(BITMAP * bufor, int nr_gracza, int srodek); // Funkcja rysująca deskę każdego graczas
	int losuj(); // Funkcja losująca liczbę z przedziała (0,1)
	void rysuj_pilke(BITMAP * bufor, int x_pilka, int y_pilka); // Funkcja rysująca piłkę

#endif
