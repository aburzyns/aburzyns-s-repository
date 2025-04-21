#include <math.h>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct point
{
    double x, y;
};

double distance(point A, point B) 
{         //x^2 + y^2 = z^2
    double length_x = abs(A.x - B.x);
    double length_y = abs(A.y - B.y);

    return sqrt(length_x*length_x + length_y*length_y);
}

bool is_triangle(point A, point B, point C)
{
    double area;
    area = 0.5 * fabs(A.x * (B.y - C.y) + B.x * (C.y - A.y) + C.x * (A.y - B.y));

    if(area == 0) {
        return false;
    }
    else {
        return true;
    }
}

double area_triangle(point A, point B, point C) 
{
    return 0.5 * fabs(A.x * (B.y - C.y) + B.x * (C.y - A.y) + C.x * (A.y - B.y));
}


vector<point> get_points(void)
{
    vector<point> vec;

    cout << "podaj punkty, 'e' linia konczy wprowadzanie" << endl;

    for(;;) {
        string x;
        cin >> x;
        if (x == "e") {
            break;
        }

        string y;
        cin >> y;
        if (y == "e") {
            break;
        }

        point p;
        p.x = stod(x);
        p.y = stod(y);
        vec.push_back(p);
    }
    return vec;
}


point get_pol_centre(vector<point> pts)
{
    double x_sum = 0, y_sum = 0;

    for(auto p : pts) {
        x_sum += p.x;
        y_sum += p.y;
    }

    point centre;
    centre.x = x_sum / pts.size();
    centre.y = y_sum / pts.size();
    
    return centre;
}

double area_of_polygon(vector<point> pts, point centre)
{
    double area = 0;
    for(int sides = 0; sides + 1 < pts.size(); ++sides) {
        area += (0.5 * fabs(pts[sides].x * (pts[sides + 1].y - centre.y) + pts[sides + 1].x * (centre.y - pts[sides].y) + centre.x * (pts[sides].y - pts[sides + 1].y)));
    }
    area += (0.5 * fabs(pts[0].x * (pts[pts.size() - 1].y - centre.y) + pts[pts.size() - 1].x * (centre.y - pts[0].y) + centre.x * (pts[0].y - pts[pts.size() - 1].y)));

    cout << area << endl;
    return area;
}

bool point_in_triangle(point a, point b, point c, point d) {
    double area_main_triangle = area_triangle(a, b, c);
    double area_rest_triangles = area_triangle(a, b, d) + area_triangle(a, c, d) + area_triangle(b, c, d);

    if(area_main_triangle == area_rest_triangles) {
        return true;
    }
    else {
        return false;
    }
}

void write_point(point p)
{
    cout << "(" << p.x << ", " << p.y << ")" << endl;
}
