#ifndef MENU_H
#define MENU_H
#include "zmienne.h"

class menu /*klasa menu gry*/
{
    public:
        menu(); /*kontruktor klasy*/
        virtual ~menu(); /* wirtualny destruktor klasy */
        void load(); /*funkcja odpowiadajaca za �adowanie wykorzystywanych bitmap i tworzenie potrzebnych bufor�w dzi�ki*/
        void menu_tlo(); /*funkcja ospowiada za wyswietlenie podstawowego meunu oraz jego t�a */
        void menu_glowne(); /*funkcja odpowiada za g��wne menu steruj�ce za pomoc� kt�rego wybieram interesuj�c� nas opcje*/
        void destroy2();   /*funkcja odpowiada za usuwanie z pamieci nie potrzebnych juz bitmap i bufor�w */
         int frame;  /*zmienna integer umo�liwia odpowiednie poruszanie sie po menu*/

        BITMAP *tlo_menu; /*wska�nik umo�liwia wyswietlenie i za�adowanie bitmapy z t�em w menu gry*/
        BITMAP *menu1; /*wska�nik umo�liwia wyswietlenie i za�adowanie bitmapy z niebieskim napisem Nowa Gra */
        BITMAP *menu3; /*wska�nik umo�liwia wyswietlenie i za�adowanie bitmapy z niebieskim napisem Wyj�cie */
        BITMAP *menu4; /*wska�nik umo�liwia wyswietlenie i za�adowanie bitmapy z pomara�czowym napisem Nowa Gra */
        BITMAP *menu6; /*wska�nik umo�liwia wyswietlenie i za�adowanie bitmapy z pomara�czowym napisem Wyj�cie */
};

#endif // MENU_H
