#ifndef WAZ_H
#define WAZ_H

#include "zmienne.h"

class waz /* klasa odpowiadaj�ca ze poruszanie sie i wyswietlanie w�a */
{
    public:

	struct sogon /*struktura umo�liwia zczytywanie kolejnych pozycji w�a dzieki temu mozna okra�lic gdzie do��czy� kolejn� cz�� w�a */
	{
	  int x,y;
	};


        waz(); /* konstruktor klasy */
        virtual ~waz(); /* wirtualny destruktor klasy */
        void loadw();  /*funkcja odpowiada za ��dowanie sie kolejnych bitmap wykorzystanych w tej klasie */
        bool glowa();  /*funkcja boolowska maj�ca za zadanie sterowanie g�ow� w�a oraz wy�wietla i zlicza punkty tj. kolejne cz�ci w�a przyczepione do jego g�owy */
        void destroy3(); /*funkcja ma za zadanie usuwanie z pami�ci uzytach bitmap oraz bufor�w w danej klasie */
        void oblicz(int x, int y,int s); /*funkcja zlicza oraz wy�wietla kolejne cz�ci ogona w�a i za odpowiednie skr�canie si� w�a */
        void losuj();/* funkcja losuj�ca pozycje na jakiej ma si� wyswietlic kolejna cz�� w�a */
        BITMAP *ogon; /*wska�nik umo�liwa wy�wietlenie oraz za�adowanie kolejnych cz�ci ogona w�a */
        BITMAP *glowa1;/*wska�nik umo�liwa wy�wietlenie oraz za�adowanie g�owy skr�conej w odpowiedni� strone */
        BITMAP *glowa2;/*wska�nik umo�liwa wy�wietlenie oraz za�adowanie g�owy skr�conej w odpowiedni� strone */
        BITMAP *glowa3;/*wska�nik umo�liwa wy�wietlenie oraz za�adowanie g�owy skr�conej w odpowiedni� strone */
        BITMAP *glowa4;/*wska�nik umo�liwa wy�wietlenie oraz za�adowanie g�owy skr�conej w odpowiedni� strone */
        BITMAP *tmp; /* wska�nik przechowuje czery powy�sze wska�niki co umo�liwia wi�ksz� swobode podczas wykonywanych operacji */
        BITMAP *koniecgry;/*wska�nik umo�liwa wy�wietlenie oraz za�adowanie bitmapy odpowiadajacej za zako�czenie gry poczas skucia si� */


        sogon ogony[100];
        sogon dodajogon(sogon ble);
        int rozmiar;
        int tx;
        int ty;
        bool dodano;
        bool kolizja1(int x1,int y1,int s1,int w1,int x2,int y2,int s2,int w2);
        bool kolizja2(int x,int y);
        int frame2;
        int x;
        int y;
        int ogon_h;
        int ogon_w;
        int glowa1_w;
        int glowa1_h;
        int xx;
        int yy;
    protected:
    private:
};

#endif // WAZ_H
