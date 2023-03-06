#include "Emoji.h"

void Face::draw(AnimationWindow& win){
    win.draw_circle(center, radius, Color::yellow);
}

void EmptyFace::draw(AnimationWindow& win){
    Face::draw(win);
    win.draw_circle(Point{center.x - radius/2, center.y - radius/3}, radius/4, Color::black);
    win.draw_circle(Point{center.x + radius/2, center.y - radius/3}, radius/4, Color::black);
}

void SmileyFace::draw(AnimationWindow& win){
    EmptyFace::draw(win);
    win.draw_arc(Point{center.x, center.y + radius/3}, radius/2, radius/2, 360, 180, Color::black);
}

void SadFace::draw(AnimationWindow& win){
    EmptyFace::draw(win);
    win.draw_arc(Point{center.x, center.y + radius/2}, radius/2, radius/2, 180, 0, Color::black);
}

void LaughingFace::draw(AnimationWindow& win){
    EmptyFace::draw(win);
    win.draw_arc(Point{center.x, center.y + radius/3}, radius/2, radius/2, 360, 180, Color::black);
    win.draw_arc(Point{center.x, center.y + radius/4}, radius/2, radius/2, 360, 180, Color::black);
}

void AngryFace::draw(AnimationWindow& win){
    SadFace::draw(win);
    win.draw_line(Point{center.x - radius, center.y-radius}, Point{center.x - radius/7, center.y - radius/3}, Color::black);
    win.draw_line(Point{center.x + radius, center.y-radius}, Point{center.x + radius/7, center.y - radius/3}, Color::black);
}