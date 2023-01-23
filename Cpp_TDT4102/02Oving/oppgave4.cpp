

#include "oppgave4.h"

void pythagoras(){
    int w = 600;
    int h = 600;

    AnimationWindow win{100,100, w, h, "Pythagoras"};
    Point p1{100, 100};
    Point p2{180, 250};
    Point p3{100, 250};

    win.draw_triangle(p1, p2, p3, Color::red);

    win.draw_quad(p1, p2, Point{100,100}, Point{100,100}, Color::blue);
    win.draw_quad(p2, p3, Point{100,100}, Point{100,100}, Color::blue);
    win.draw_quad(p3, p1, Point{100,100}, Point{100,100}, Color::blue);

    


    win.wait_for_close();
}