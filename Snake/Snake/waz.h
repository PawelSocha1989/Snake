#ifndef WAZ_H
#define WAZ_H

#include "zmienne.h"

class waz /* klasa odpowiadaj¹ca ze poruszanie sie i wyswietlanie wê¿a */
{
    public:

	struct sogon /*struktura umo¿liwia zczytywanie kolejnych pozycji wê¿a dzieki temu mozna okraœlic gdzie do³¹czyæ kolejn¹ czêœæ wê¿a */
	{
	  int x,y;
	};


        waz(); /* konstruktor klasy */
        virtual ~waz(); /* wirtualny destruktor klasy */
        void loadw();  /*funkcja odpowiada za ³¹dowanie sie kolejnych bitmap wykorzystanych w tej klasie */
        bool glowa();  /*funkcja boolowska maj¹ca za zadanie sterowanie g³ow¹ wê¿a oraz wyœwietla i zlicza punkty tj. kolejne czêœci wê¿a przyczepione do jego g³owy */
        void destroy3(); /*funkcja ma za zadanie usuwanie z pamiêci uzytach bitmap oraz buforów w danej klasie */
        void oblicz(int x, int y,int s); /*funkcja zlicza oraz wyœwietla kolejne czêœci ogona wê¿a i za odpowiednie skrêcanie siê wê¿a */
        void losuj();/* funkcja losuj¹ca pozycje na jakiej ma siê wyswietlic kolejna czêœæ wê¿a */
        BITMAP *ogon; /*wskaŸnik umo¿liwa wyœwietlenie oraz za³adowanie kolejnych czêœci ogona wê¿a */
        BITMAP *glowa1;/*wskaŸnik umo¿liwa wyœwietlenie oraz za³adowanie g³owy skrêconej w odpowiedni¹ strone */
        BITMAP *glowa2;/*wskaŸnik umo¿liwa wyœwietlenie oraz za³adowanie g³owy skrêconej w odpowiedni¹ strone */
        BITMAP *glowa3;/*wskaŸnik umo¿liwa wyœwietlenie oraz za³adowanie g³owy skrêconej w odpowiedni¹ strone */
        BITMAP *glowa4;/*wskaŸnik umo¿liwa wyœwietlenie oraz za³adowanie g³owy skrêconej w odpowiedni¹ strone */
        BITMAP *tmp; /* wskaŸnik przechowuje czery powy¿sze wskaŸniki co umo¿liwia wiêksz¹ swobode podczas wykonywanych operacji */
        BITMAP *koniecgry;/*wskaŸnik umo¿liwa wyœwietlenie oraz za³adowanie bitmapy odpowiadajacej za zakoñczenie gry poczas skucia siê */


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
