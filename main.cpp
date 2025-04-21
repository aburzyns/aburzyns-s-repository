#include <iostream>
#include <math.h>
#include <vector>
#include "geometry.cpp"

int main() {
    int answer;
    double a1, a2, b1, b2, c1, c2;

    cout << "Wybierz funkcje:" << endl << "1 - Liczenie odleglosci miedzy punktami" << endl;
    cout << "2 - Czy podane punkty tworza trojkat" << endl << "3 - Pole dowolnego trojkata w ukladzie wspolrzednych" << endl;
    cout << "4 - Pole dowolnego wieloboku wypuklego" << endl << "5 - Czy punkt znajduje sie w obrebie trojkata" << endl;

    cin >> answer;
    switch(answer) {
        case 1: {
            cin >> a1 >> a2 >> b1 >> b2;
            point A = {a1, a2};
            point B = {b1, b2};
        
            cout << distance(A, B);
            break;
        }
        case 2: {
            cin >> a1 >> a2 >> b1 >> b2 >> c1 >> c2;
            point A = {a1, a2};
            point B = {b1, b2};
            point C = {c1, c2};

            if(is_triangle(A, B, C) == 1) {
                cout << "Podane punkty tworza trojkat." << endl;
            }
            else {
                cout << "Podane punkty nie tworza trojkata." << endl;
            }
            break;
        }
        case 3: {
            cin >> a1 >> a2 >> b1 >> b2 >> c1 >> c2; 
            point A = {a1, a2};
            point B = {b1, b2};
            point C = {c1, c2};

            cout << "Pole trojkata wynosi" << area_triangle(A, B, C) << endl;
            break;
        }
        case 4: {
            vector<point> pts = get_points();
            cout << "Podales:" << endl;
            for(auto p : pts) {
              write_point(p);
            }

            point centre = get_pol_centre(pts);
            cout << "Srodek to: ";
            write_point(centre);
            
            cout << "Powierzchnia podanego wielokatu to: " << area_of_polygon(pts, centre) << endl;
            
        }  
        case 5: {
            point a, b, c, d;
            cin >> a.x >> a.y;
            cin >> b.x >> b.y;
            cin >> c.x >> c.y;
            cin >> d.x >> d.y;

            if(point_in_triangle(a, b, c, d) == 1) {
                cout << "punkt jest zawarty w trojkacie" << endl;
            }
            else {
                cout << "punkt nie znajduje sie w obrebie trojkata" << endl;
            }
        }
    }
    system("pause");
    return 0;
}