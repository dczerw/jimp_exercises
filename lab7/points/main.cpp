//
// Created by Kuba on 21.04.2017.
//

#include "Points.h"

/*
 * Odpowiedzi:
 *
 * Zad 5:
 * Dla wywołania Point3D a(2,3,4): Najpierw wykonuje się konstruktor bezparametryczny klasy Point,
 * później konstruktor parametryczny klasy Point3D. Na końcu programu wykonuje się destruktor klasy
 * Point3D, a później destruktor klasy Point.
 * Dla wywołania Point3D a(): Najpierw wykonuje się konstruktor bezparametryczny klasy Point,
 * później konstruktor bezparametryczny klasy Point3D. Na końcu programu wykonuje się destruktor klasy
 * Point3D, a później destruktor klasy Point.
 *
 * Zad 6:
 * Obiekt klasy Point3D został niejawnie zrzutowany w górę na klasę Point i taki obiekt został użyty
 * przy wywołaniue metody Distance klasy Point. Przykładowo point3d(4,5,6) został potraktowany jako
 * point2d(4,5), zatem metoda Distance zwróciła nam odległość pomiędzy dwoma punktami2d.
 *
 * Zad 7:
 * Klasa Point3D dziedziczy operator przeciążony operator "<<" od klasy Point. Operator ten ma za zadanie
 * jedynie wypisać składową x i y i dokładnie to robi z obiektem p3d, pomijając jego składową z.
 * Czyli dla p3d(1,2,3) wypisze jedynie (1,2).
 */

int main()
{
    geometry::Point point2d(2,3);
    geometry::Point3D point3d(4,5,6);
    geometry::Point other(4,5);
    std::cout<<point2d.Distance(point3d)<<std::endl;
    std::cout<<point2d.Distance(other)<<std::endl;

    geometry::Point3D p3d(1,2,3);
    std::cout << p3d << std::endl;

    return 0;
}