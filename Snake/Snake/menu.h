#ifndef MENU_H
#define MENU_H
#include "zmienne.h"

class menu /*klasa menu gry*/
{
    public:
        menu(); /*kontruktor klasy*/
        virtual ~menu(); /* wirtualny destruktor klasy */
        void load(); /*funkcja odpowiadajaca za ³adowanie wykorzystywanych bitmap i tworzenie potrzebnych buforów dziêki*/
        void menu_tlo(); /*funkcja ospowiada za wyswietlenie podstawowego meunu oraz jego t³a */
        void menu_glowne(); /*funkcja odpowiada za g³ówne menu sterujêce za pomoc¹ którego wybieram interesuj¹c¹ nas opcje*/
        void destroy2();   /*funkcja odpowiada za usuwanie z pamieci nie potrzebnych juz bitmap i buforów */
         int frame;  /*zmienna integer umo¿liwia odpowiednie poruszanie sie po menu*/

        BITMAP *tlo_menu; /*wskaŸnik umo¿liwia wyswietlenie i za³adowanie bitmapy z t³em w menu gry*/
        BITMAP *menu1; /*wskaŸnik umo¿liwia wyswietlenie i za³adowanie bitmapy z niebieskim napisem Nowa Gra */
        BITMAP *menu3; /*wskaŸnik umo¿liwia wyswietlenie i za³adowanie bitmapy z niebieskim napisem Wyjœcie */
        BITMAP *menu4; /*wskaŸnik umo¿liwia wyswietlenie i za³adowanie bitmapy z pomarañczowym napisem Nowa Gra */
        BITMAP *menu6; /*wskaŸnik umo¿liwia wyswietlenie i za³adowanie bitmapy z pomarañczowym napisem Wyjœcie */
};

#endif // MENU_H
