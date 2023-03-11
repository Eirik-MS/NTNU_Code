#include "/home/eirik/Documents/NTNU_Code/Cpp_TDT4102/07Oving/subprojects/animationwindow/include/AnimationWindow.h"
#include "Emoji.h"
#include "animal.hpp"


// Definer størrelse på vindu og emoji
constexpr int xmax = 1000;
constexpr int ymax = 600;
constexpr int emojiRadius = 50;

int main()
{
	testAnimal();

	const Point tl{100, 100};
	const string win_label{"Emoji factory"};
	AnimationWindow win{tl.x, tl.y, xmax, ymax, win_label};
	SmileyFace smiley(Point{xmax/4, ymax/3}, emojiRadius);
	smiley.draw(win);
	SadFace sad(Point{2*xmax/4, ymax/3}, emojiRadius);
	sad.draw(win);
	LaughingFace laughing(Point{3*xmax/4, ymax/3}, emojiRadius);
	laughing.draw(win);
	AngryFace angry(Point{xmax/2, 2*ymax/3}, emojiRadius);
	angry.draw(win);

	/* TODO:
	 *  - initialiser emojiene
	 *  - Tegn emojiene til vinduet
	 **/

	win.wait_for_close();

	return 0;
}
