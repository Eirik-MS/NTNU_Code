#pragma once
#include "/home/eirik/Documents/NTNU_Code/Cpp_TDT4102/07Oving/subprojects/std_lib_facilities/std_lib_facilities.h"
#include "/home/eirik/Documents/NTNU_Code/Cpp_TDT4102/07Oving/subprojects/animationwindow/include/AnimationWindow.h"

// Abstrakt klasse. Arvende konkrete klasser må implementere funksjonen draw()
// som tegner former i vinduet de skal bli vist i.
class Emoji
{
public:
    virtual void draw(AnimationWindow& win) = 0;
    virtual ~Emoji(){}; //destruktør
};

class Face : public Emoji
{   
    protected:
    Point center;
    int radius;
    public:
    Face(Point center, int radius) : center{center}, radius{radius} {};
    virtual void draw(AnimationWindow& win) override;
};

class EmptyFace : public Face
{
    public:
    EmptyFace(Point center, int radius) : Face(center, radius) {};
    virtual void draw(AnimationWindow& win) override;
};

class SmileyFace : public EmptyFace
{
    public:
    SmileyFace(Point center, int radius) : EmptyFace(center, radius) {};
    virtual void draw(AnimationWindow& win) override;
};

class SadFace : public EmptyFace
{
    public:
    SadFace(Point center, int radius) : EmptyFace(center, radius) {};
    virtual void draw(AnimationWindow& win) override;
};

class LaughingFace : public EmptyFace
{
    public:
    LaughingFace(Point center, int radius) : EmptyFace(center, radius) {};
    virtual void draw(AnimationWindow& win) override;
};

class AngryFace : public SadFace
{
    public:
    AngryFace(Point center, int radius) : SadFace(center, radius) {};
    virtual void draw(AnimationWindow& win) override;
};