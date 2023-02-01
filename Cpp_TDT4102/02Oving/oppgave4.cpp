

#include "oppgave4.h"

void pythagoras(){
    int w = 600;
    int h = 600;

    AnimationWindow win{100,100, w, h, "Pythagoras"};
    Point p1{200, 200};
    Point p2{200, 400};
    Point p3{300, 400};

    win.draw_triangle(p1, p2, p3, Color::red);

    win.draw_quad(p1, p2, Point{0,400}, Point{0,200}, Color::blue);
    win.draw_quad(p2, p3, Point{300,500}, Point{200,500}, Color::blue);
    win.draw_quad(p3, p1, Point{400,100}, Point{500,300}, Color::blue);

    


    win.wait_for_close();
}