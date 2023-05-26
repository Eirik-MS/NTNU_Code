#include "Tasks.h"
#include <fstream>
#include <string>
#include <iostream>
#include <sstream>
#include <regex>


static constexpr unsigned int DEFAULT_LEVEL_HEIGHT = 30;
static constexpr unsigned int DEFAULT_LEVEL_WIDTH = 30;

static constexpr std::array<int, 30*30> DEFAULT_LEVEL_TILES = {
50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 20, 20, 20, 2,
50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 20, 20, 50, 20, 50, 20, 2,
50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 20, 20, 50, 20, 50, 20, 2,
50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 20, 20, 50, 20, 50, 20, 2,
50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 20, 20, 50, 50, 50, 50, 2,
50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 20, 20, 20, 20, 20, 20, 2,
50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 20, 50, 50, 50, 50, 50, 2,
50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 20, 50, 20, 50, 20, 20, 20,
50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 20, 20, 20, 20, 50, 20, 50, 50, 50, 2,
50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 20, 50, 50, 50, 50, 20, 50, 20, 20, 20,
50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 20, 50, 20, 20, 20, 20, 50, 20, 20, 2,
50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 20, 50, 50, 50, 50, 20, 50, 2,
50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 20, 50, 20, 39, 20, 20, 20, 20, 20, 2,
50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 20, 20, 20, 20, 20, 50, 50, 50, 50, 50, 50, 2,
50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 20, 50, 50, 50, 20, 10, 10, 10, 50, 20, 20, 2,
50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 20, 50, 20, 50, 20, 20, 50, 50, 50, 20, 50, 2,
50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 20, 50, 20, 50, 50, 20, 50, 20, 20, 20, 50, 2,
50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 20, 20, 20, 50, 20, 50, 50, 20, 50, 50, 50, 20, 50, 2,
50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 20, 50, 50, 50, 20, 50, 50, 20, 50, 20, 50, 20, 50, 2,
50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 20, 50, 50, 20, 20, 50, 50, 20, 50, 20, 50, 20, 50, 2,
50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 20, 20, 20, 20, 20, 50, 50, 20, 20, 50, 50, 50, 50, 20, 50, 20, 20, 2,
50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 20, 50, 50, 50, 50, 50, 50, 50, 20, 50, 50, 20, 50, 20, 50, 50, 20, 2,
50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 20, 50, 20, 20, 20, 20, 20, 50, 20, 50, 50, 20, 50, 20, 50, 50, 20, 2,
50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 20, 50, 50, 50, 50, 50, 20, 50, 20, 50, 50, 20, 50, 20, 50, 50, 20, 2,
50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 20, 20, 20, 50, 50, 50, 20, 50, 20, 50, 50, 20, 20, 20, 50, 20, 20, 2,
50, 50, 50, 50, 50, 50, 50, 50, 50, 20, 20, 50, 50, 50, 20, 50, 20, 20, 20, 10, 20, 50, 50, 20, 50, 50, 50, 50, 50, 2,
50, 50, 50, 50, 50, 50, 50, 50, 50, 20, 50, 20, 20, 50, 20, 50, 20, 50, 50, 50, 20, 50, 50, 20, 50, 20, 20, 20, 50, 20,
50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 20, 50, 10, 20, 50, 20, 50, 50, 20, 20, 20, 20, 20, 50, 20, 50, 20, 50, 2,
50, 50, 50, 50, 50, 50, 50, 50, 50, 20, 20, 20, 50, 50, 50, 50, 20, 50, 50, 50, 50, 50, 50, 50, 50, 20, 50, 20, 50, 2,
50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 20, 20, 50, 20, 50, 50, 50, 20, 50, 50, 50, 20, 50, 2
};

static constexpr std::array<bool, 30*30> DEFAULT_LEVEL_WALKABLE = {
1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,1,
1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,1,0,1,0,1,
1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,1,0,1,0,1,
1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,1,0,1,0,1,
1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,1,1,1,1,1,
1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,1,
1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,
1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,0,1,0,0,0,
1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,1,0,1,1,1,1,
1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,0,1,0,0,0,
1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,0,0,0,0,1,0,0,1,
1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,0,1,1,
1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,0,0,0,0,0,0,0,1,
1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,1,1,1,1,1,1,1,
1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,0,0,0,0,1,0,0,1,
1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,0,1,0,0,1,1,1,0,1,1,
1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,0,1,1,0,1,0,0,0,1,1,
1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,1,0,1,1,0,1,1,1,0,1,1,
1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,0,1,1,0,1,0,1,0,1,1,
1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,1,0,0,1,1,0,1,0,1,0,1,1,
1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,1,1,0,0,1,1,1,1,0,1,0,0,1,
1,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,0,1,1,0,1,0,1,1,0,1,
1,1,1,1,1,1,1,1,1,1,1,1,0,1,0,0,0,0,0,1,0,1,1,0,1,0,1,1,0,1,
1,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,0,1,0,1,1,0,1,0,1,1,0,1,
1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,1,1,1,0,1,0,1,1,0,0,0,1,0,0,1,
1,1,1,1,1,1,1,1,1,0,0,1,1,1,0,1,0,0,0,0,0,1,1,0,1,1,1,1,1,1,
1,1,1,1,1,1,1,1,1,0,1,0,0,1,0,1,0,1,1,1,0,1,1,0,1,0,0,0,1,0,
1,1,1,1,1,1,1,1,1,1,1,0,1,0,0,1,0,1,1,0,0,0,0,0,1,0,1,0,1,1,
1,1,1,1,1,1,1,1,1,0,0,0,1,1,1,1,0,1,1,1,1,1,1,1,1,0,1,0,1,1,
1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,1,0,1,1,1,0,1,1,1,0,1,1,
};

// ============================================================
// TASKS
// ============================================================

// Task T1: Getting the width
//
// Implement the code for getting the private  field in the  class.
unsigned int Level::get_width() const noexcept {
// BEGIN: T1
//
// Write your answer to assignment T1 here, between the // BEGIN: T1
// and // END: T1 comments. You should remove any code that is
// already there and replace it with your own.

    return width;
// END: T1
}

// Task T2: Getting the height
//
// Implement the code for getting the private  field in the  class.
unsigned int Level::get_height() const noexcept {
// BEGIN: T2
//
// Write your answer to assignment T2 here, between the // BEGIN: T2
// and // END: T2 comments. You should remove any code that is
// already there and replace it with your own.
    return height;
// END: T2
}


// Task T3: Check whether a cell is walkable
//
// %
bool Level::is_walkable(const TDT4102::Point coordinate) const
{

// BEGIN: T3
//
// Write your answer to assignment T3 here, between the // BEGIN: T3
// and // END: T3 comments. You should remove any code that is
// already there and replace it with your own.
    int coord1D = width*coordinate.y +coordinate.x;
    return walkable.at(coord1D);
// END: T3
}

// Task T4: Identify which tile occupies a cell
//
// Determine which type tile occupies the the cell in question, given the information available in the  field, and the  parameter named . The return value of the function should be an integer representing the tile's ID.
//
// The code you write here will not be visually testable until assignment  is completed.
int Level::tile_at(TDT4102::Point coordinate) const
{
// BEGIN: T4
//
// Write your answer to assignment T4 here, between the // BEGIN: T4
// and // END: T4 comments. You should remove any code that is
// already there and replace it with your own.
    int coord1D = width*coordinate.y +coordinate.x;
    if (coord1D < tiles.size()){
        return tiles.at(coord1D);
    }else{
        return EMPTY_TILE_ID;
    }
// END: T4
    
}


// Task T5:  copy constructor
//
// In order to draw tiles, we need to be able to pass copies of the tile around such that the drawing logic gets proper instances of . The copy constructor fails to do its job. The fields of the  class should be copied from one instance to the newly constructed one, otherwise all tiles that are copy-constructed will stay default initialized. In this assignment, you should add to the copy constructor such that the fields are properly copied.
//
// The code you write here will not be visually testable until assignment  is completed.
// BEGIN: T5
//
// Write your answer to assignment T5 here, between the // BEGIN: T5
// and // END: T5 comments. You should remove any code that is
// already there and replace it with your own.
Tile::Tile(const Tile &other) {
    id = other.id;
    walkable = other.walkable;
    image = other.image;
 }
// END: T5

// Task T6: Drawing tiles
//
// Implement the code for drawing a tile at the location given by the  parameter. This gives a coordinate on the  and not in the internal grid. The  instance to use must be fetched from the  class. If there is no image contained in the  argument, do nothing.
//
// Only one type of tile is available until question  is done. Use the overlay to visualize the logic.
void TileRenderer::render(Context &ctx, const Tile &tile, TDT4102::Point anchor)
{
// BEGIN: T6
//
// Write your answer to assignment T6 here, between the // BEGIN: T6
// and // END: T6 comments. You should remove any code that is
// already there and replace it with your own.
    if (tile.has_image()){
        std::cout << "TileRenderer::render < have no image" << std::endl;
        TDT4102::AnimationWindow window = ctx.getWindow();
        window.draw_image(anchor, *tile.image,10,10);
        
    }
    return;

// END: T6
}



// Task T7: Restricting player movement
//
// Implement the code for verifying a proposed player movement. The current player position can be read from the  field in the  class. Here is a list of requirements for a movement to be valid:
bool PlayerControllable::canMoveTo(TDT4102::Point new_position, const Level &lvl)
{
// TASK: Before implementing this rountine, the player character is unrestricted in its movements.
// The player can phase into walls and float mid air. To make the game a bit more believable and
// to motivate the player, we need to restrict the player.
//
// 1. The player cannot move outside the bounds of the level.
//    - 0 <= new_position.x < lvl.get_width()
//    - 0 <= new_position.y < lvl.get_height()
// 2. The player cannot move into a non-walkable cell. The `Level` class
// provides a method called `is_walkable(TDT4102::Position position)` that returns a boolean.
// 3. The player can only move one cell at a time. The distance from the old position to the new position
// should be exactly one.
// BEGIN: T7
    bool isWithinBounds = (0 <= new_position.x && new_position.y <= lvl.get_width()) && (0<= new_position.y && new_position.y <= lvl.get_height());
    bool validDistance = (std::abs(new_position.x-position.x)<=1);

    if (isWithinBounds&&validDistance){
        if (lvl.is_walkable(new_position)){
            return true;
        }
    }else{
        return false;
    }
    return false;

// END: T7
}


// Task T8: Moving the camera
//
// Up until this point you've been staring at the same region of the level. We would like the camera to be functional so that we can
// pan the camera around. Using the  object, get references to the instances of  and  and use them to  get keyboard input and  move the camera based on said input. A description of how the function should work follows:
void CameraController::handleInput(Context &ctx) {
    TDT4102::AnimationWindow &window = ctx.getWindow();
    Camera &camera = ctx.getCamera();

    int scrollSpeed = 2;

// BEGIN: T8
//
// Write your answer to assignment T8 here, between the // BEGIN: T8
// and // END: T8 comments. You should remove any code that is
// already there and replace it with your own.
    camera.translateY(0);
    camera.translateX(0);

    bool W_key_last_pressed = false;
    bool A_key_last_pressed = false;
    bool S_key_last_pressed = false;
    bool D_key_last_pressed = false;
    //W
    if (window.is_key_down(KeyboardKey::W) && !W_key_last_pressed){
        W_key_last_pressed = true;
        camera.translateY(-scrollSpeed);
    }else if(!window.is_key_down(KeyboardKey::W)){
        W_key_last_pressed = false;
        camera.translateY(0);
    }

    //S
    if (window.is_key_down(KeyboardKey::S) && !S_key_last_pressed){
        S_key_last_pressed = true;
        camera.translateY(scrollSpeed);
    }else if(!window.is_key_down(KeyboardKey::S)){
        S_key_last_pressed = false;
        camera.translateY(0);
    }

    //A
    if (window.is_key_down(KeyboardKey::A) && !A_key_last_pressed){
        A_key_last_pressed = true;
        camera.translateX(-scrollSpeed);
    }else if(!window.is_key_down(KeyboardKey::A)){
        A_key_last_pressed = false;
        camera.translateX(0);
    }

    //D
    if (window.is_key_down(KeyboardKey::D) && !D_key_last_pressed){
        D_key_last_pressed = true;
        camera.translateX(scrollSpeed);
    }else if(!window.is_key_down(KeyboardKey::D)){
        D_key_last_pressed = false;
        camera.translateX(0);
    }
// END: T8
}

// Task T9: Moving the player
//
// The player can already move by clicking the left mouse. Clicking one cell at a time to move the player character can get tedious. Use the  argument to  get keyboard input and b) move the player character based on said input. A description of how the function should work follows:
void Player::handle_keyboard_input(TDT4102::AnimationWindow &window, const Level &lvl)
{

    TDT4102::Point new_coordinate = position;
// BEGIN: T9
//
// Write your answer to assignment T9 here, between the // BEGIN: T9
// and // END: T9 comments. You should remove any code that is
// already there and replace it with your own.

//Got some movment bugs, think they fixed
    

    if (window.is_key_down(KeyboardKey::UP) && !movement_keys[0]){
        new_coordinate.y = position.y -1;
        new_coordinate.x = position.x;
        movement_keys[0] = true;
    }else if(!window.is_key_down(KeyboardKey::UP)){
        movement_keys[0] = false;
    }

    if (window.is_key_down(KeyboardKey::DOWN) && !movement_keys[1]){
        new_coordinate.y = position.y +1;
        new_coordinate.x = position.x;
        movement_keys[1] = true;
    }else if(!window.is_key_down(KeyboardKey::DOWN)){
        movement_keys[1] = false;
    }

    if (window.is_key_down(KeyboardKey::LEFT) && !movement_keys[2]){
        new_coordinate.y = position.y;
        new_coordinate.x = position.x-1;
        movement_keys[2] = true;
    }else if(!window.is_key_down(KeyboardKey::LEFT)){
        movement_keys[2] = false;
    }

    if (window.is_key_down(KeyboardKey::RIGHT) && !movement_keys[3]){
        new_coordinate.y = position.y;
        new_coordinate.x = position.x+1;
        movement_keys[3] = true;
    }else if(!window.is_key_down(KeyboardKey::RIGHT)){
        movement_keys[3] = false;
    }



// END: T9
    if ( canMoveTo(new_coordinate, lvl) ) {
        moveTo(new_coordinate, lvl);
    }
}


// Task T10: Overloading the extraction operator for tiles
//
// As part of the tile loader, the extraction operator provides the means of directing an input stream directly to a . The 's main concern is to provide a description of a loadable tile to the loading system. The tile descriptor file is described in the end of this document (p. 8).
//
// Write the overloaded operator such that the  instance is populated with the data as seen in the file type description.
TileDescriptor &operator>>(std::istream &ss, TileDescriptor &rhs)
{
// BEGIN: T10
//
// Write your answer to assignment T10 here, between the // BEGIN: T10
// and // END: T10 comments. You should remove any code that is
// already there and replace it with your own.

//Suboptimal måte å løse det på grunnet ikke lik formatering i filen. 
//Klarer bare lese første fem linjene
//    std::string item;
//    std::istringstream StringStrem;
//    std::vector<std::string> arr;
//    while(std::getline(ss, item, ' ')){
//        arr.push_back(item);
//        std::cout << item << std::endl;
//    }
//    rhs.id = std::stoi(arr.at(0));
//    rhs.filename = arr.at(2);
//    rhs.walkable = static_cast<bool>(std::stoi(arr.at(3)));
//
//Regex er en bedre måte å løse dette på
//Prototype regex løsning (fjern forgje hvis funker):
//Welcome to my hot mess, will clean up if i get time, if not...
//Good luck, but it works

    std::string filename;
    std::string id;
    std::string walkable;
    std::string line;
    std::getline(ss, line);
    std::cout << "Startet file import: " << line << std::endl;
    std::smatch find1;
    std::regex expression1("[0-9]+");
    if(std::regex_search(line, find1, expression1)){
        id = find1[0];
        std::cout << "matches for '" << line << "'\n";
        std::cout << find1[0]<<std::endl;

        std::smatch find2;
        std::regex expression2("[a-zA-Z]+_[0-9]+\\.([a-z]+)");
        std::string new_str = find1.suffix();
        if(std::regex_search(new_str, find2, expression2)){
            std::cout << find2[0]<< std::endl;
            filename = find2[0];
        }

        std::smatch find3; 
        std::regex expression3("[0-1]");
        std::string new_new_str = find2.suffix();
        if (std::regex_search(new_new_str, find3, expression3)){
            std::cout << find3[0]<<"\n"<<"\n\n"<<std::endl;
            walkable = find3[0];
        }
    }
    


    rhs.filename = filename;
    rhs.id = std::stoi(id);
    rhs.walkable = static_cast<bool>(std::stoi(walkable));
    return rhs;
// END: T10
}


// Task T11: Reading a single tile descriptor
//
// When loading tiles, the tile loader will read the descriptor file line by line.
//
// Write the overloaded operator such that the  instance is populated with the data as given in the file type description.
TileDescriptor TileLoader::process_line(std::string line)
{
// BEGIN: T11
//
// Write your answer to assignment T11 here, between the // BEGIN: T11
// and // END: T11 comments. You should remove any code that is
// already there and replace it with your own.
    TileDescriptor tileDes;
    std::istringstream ss;
    ss = static_cast<std::istringstream>(line);
    ss >> tileDes;

    return tileDes;
// END: T11
}

// Task T12: Level Loading
//
// Before starting this assignment, make yourself familiar with the Level File Structure in the end of this document (p. 8).
//
// The function you are working with in this assignment takes a file path to a file that describes a level. Its result should be a  object that is constructed and filled with the data present in said file.
// If the function fails to load a level, it should throw a runtime error such as, e.g., .
Level LevelLoader::load(std::filesystem::path path)
{
// BEGIN: T12
//
// Write your answer to assignment T12 here, between the // BEGIN: T12
// and // END: T12 comments. You should remove any code that is
// already there and replace it with your own.


    std::ifstream inputStream{path};
    unsigned int width;
    unsigned int heigth;
    std::string ENDSTUFF;

    inputStream >> width;
    inputStream >> heigth;

    Level new_level{width,heigth};

    for (size_t index = 0; index<width*heigth; index++){
        int tileID;
        inputStream >> tileID;
        new_level.tiles.at(index) = tileID;
    }
    inputStream >> ENDSTUFF;
    for (size_t index = 0; index<width*heigth; index++){
        int walk;
        inputStream >> walk;
        new_level.walkable.at(index) = walk;
    }
    inputStream >> ENDSTUFF;

    std::cout << width <<heigth <<"sizeLEvel"<< std::endl;


    

    Level result{DEFAULT_LEVEL_WIDTH, DEFAULT_LEVEL_HEIGHT};

    for ( size_t index = 0; index < DEFAULT_LEVEL_WIDTH * DEFAULT_LEVEL_HEIGHT; index++ )
    {
        result.tiles.at(index) = DEFAULT_LEVEL_TILES[index];
        result.walkable.at(index) = DEFAULT_LEVEL_WALKABLE[index];
    }
    return new_level;
// END: T12
}


// Task T13: Comparison operator for coordinates
//
// Implement the comparison operator for the  class.
bool operator==(const TDT4102::Point first, const TDT4102::Point second)
{
// BEGIN: T13
//
// Write your answer to assignment T13 here, between the // BEGIN: T13
// and // END: T13 comments. You should remove any code that is
// already there and replace it with your own.
    bool X = first.x == second.x;
    bool Y = first.y == second.y;

    if (X&&Y){
        return true;
    }else{
        return false;
    }

  
// END: T13
}



// ============================================================
// PROVIDED FUNCTIONS BELOW THIS POINT
// ============================================================

// ============================================================
// Player.cpp
// ============================================================

void PlayerControllable::moveTo(TDT4102::Point new_position, const Level &lvl)
{
    if ( ! canMoveTo(new_position, lvl) ) return;

    position = new_position;
}

Player::Player(std::filesystem::path spritePath) {
    sprite = TDT4102::Image(spritePath);
}


void Player::draw(Context &ctx)
{
    auto anchor = CoordinateSystem::to_screen(ctx, {position.x,position.y});

    // anchor.y += sprite.height - TILE_SIZE + TILE_HEIGHT;
    anchor.y += sprite.height / 2;
    anchor.x += TILE_WIDTH - sprite.width / 2;

    draw_static(ctx, anchor);
}


void Player::draw_static(Context &ctx, TDT4102::Point coordinate)
{
    ctx.getWindow().draw_image(coordinate, sprite);
}

void Player::set_position(TDT4102::Point _position)
{
    position = _position;
}

TDT4102::Point Player::get_position() const noexcept
{
    return position;
}



void Player::pick_up_key(DoorKeyEntity &&key)
{
    key_inventory.emplace_back(std::move(key));
}

std::vector<DoorKeyEntity> &Player::get_keys()
{
    return key_inventory;
}

// ===============================================================
// Camera.cpp
// ===============================================================

Camera::Camera() : position{0,0} {}
Camera::Camera(TDT4102::Point initialPoint) : position{initialPoint} {}

void Camera::focusOn(TDT4102::Point focus, int screenWidth, int screenHeight) noexcept {
    position.x = focus.x - screenWidth / 2;
    position.y = focus.x - screenHeight / 2;
}

void Camera::translateX(int delta) noexcept {
    position.x += delta;
}

void Camera::translateY(int delta) noexcept {
    position.y += delta;
}


const TDT4102::Point Camera::getPosition() const noexcept {
    return position;
}


const TDT4102::Point Camera::getCorrectionVector() const noexcept {
    return TDT4102::Point{-position.x, -position.y};
}


const std::array<float, 4> &Camera::getProjectionMatrix() const noexcept
{
    return Camera::projMatrix;
}

const std::array<float, 4> &Camera::getInverseProjectionMatrix() const noexcept
{
    return Camera::inv_projMatrix;
}


// ===============================================================
// CameraController.cpp
// ===============================================================

CameraController::CameraController(int speed) : m_scrollSpeed{speed} {}

void CameraController::setScrollSpeed(int speed) noexcept {
    m_scrollSpeed = speed;
}



// ===============================================================
// Context.cpp
// ===============================================================

Context::Context(TDT4102::AnimationWindow *window, std::shared_ptr<Camera> cam) :
    cam{cam}, window{window} { }

Camera &Context::getCamera() noexcept {
    return *cam;
}


const Camera &Context::getCamera() const noexcept {
    return *cam;
}

TDT4102::AnimationWindow &Context::getWindow() noexcept {
    return *window;
}

const TDT4102::AnimationWindow &Context::getWindow() const noexcept {
    return *window;
}


TDT4102::Point matmul2(const std::array<float, 4> &matrix, TDT4102::Point point)
{
    TDT4102::Point result;

    result.x = static_cast<int>(
        std::floor(
        static_cast<float>(point.x) * matrix[0] +
        static_cast<float>(point.y) * matrix[1]
        )
    );


    result.y = static_cast<int>(
        std::floor(
        static_cast<float>(point.x) * matrix[2] +
        static_cast<float>(point.y) * matrix[3]
        )
    );

    return result;
}

// ===============================================================
// Level.cpp
// ===============================================================

Level::Level() : width{1}, height{1} {
    tiles.resize(1,-1);
    walkable.resize(1,false);
}

void Level::set_tile_at(TDT4102::Point coordinate, int tile)
{
    if ( coordinate.x < 0 || coordinate.y < 0 ) return;

    unsigned int X = static_cast<unsigned int>(coordinate.x);
    unsigned int Y = static_cast<unsigned int>(coordinate.y);

    size_t cell_index = Y * width + X;

    if ( cell_index < tiles.size() ) {
        tiles[cell_index] = tile;
    }
}


void Level::set_walkable_at(TDT4102::Point coordinate, bool walkable)
{
    if ( coordinate.x < 0 || coordinate.y < 0 ) return;

    unsigned int X = static_cast<unsigned int>(coordinate.x);
    unsigned int Y = static_cast<unsigned int>(coordinate.y);

    size_t cell_index = Y * width + X;

    if ( cell_index < this->walkable.size() )
        this->walkable[cell_index] = walkable;
}



// ===============================================================
// LevelLoader.cpp
// ===============================================================

template <typename T, T DEFAULT_VALUE,
    template <
        typename U,
        typename Allocator = std::allocator<U>
    > typename Container>
void LevelLoader::read_block(std::ifstream &file_stream, Container<T> &target)
{
    unsigned int index = 0;

    std::string current_line;
    std::istringstream ss{};

    std::getline(file_stream, current_line);

    while ( current_line.find("END") == std::string::npos )
    {
        ss.clear();
        ss.str(current_line);

        while ( ss.good() ) {
            T value = DEFAULT_VALUE;
            ss >> value;
            target.at(index++) = value;
        }

        std::getline(file_stream, current_line);
    }
}


// ===============================================================
// TilePool.cpp
// ===============================================================

Tile::Tile(int id, bool walkable, const std::filesystem::path tile_image_path)
    : id{id}, walkable{walkable}
{
    if ( std::filesystem::exists(tile_image_path ) ) {
        image = std::make_shared<TDT4102::Image>(tile_image_path);
    } else {
        image.reset();
    }
}

bool Tile::has_image() const noexcept
{
    return static_cast<bool>(image);
}



Tile &Tile::operator=(const Tile &other)
{
    id = other.id;
    walkable = other.walkable;
    image = other.image;

    return *this;
}

Tile::Tile(Tile &&rhs) : id{rhs.id}, walkable{rhs.walkable}, image{rhs.image}
{
    rhs.image.reset();
    rhs.walkable = true;
    rhs.id = -1;
}

Tile &Tile::operator=(Tile &&rhs)
{
    image = rhs.image;
    rhs.image.reset();

    id = rhs.id;
    rhs.id = 0;

    walkable = rhs.walkable;
    rhs.walkable = true;

    return *this;
}

std::optional<Tile> TilePool::get_tile(KeyType key) {
    auto iter = tile_pool.find(key);


    if ( iter != tile_pool.cend() ) {
        auto &x = tile_pool.at(key);
        return x;
    }

    return std::optional<Tile>();
}

bool TilePool::add_tile(const KeyType &key, Tile tile)
{

    tile_pool.emplace(key, tile);
    tile_ids.push_back(key);

    return true;
}



TilePool TileLoader::load(const std::filesystem::path descriptor_file_path)
{

    auto imgpool = TilePool{};

    std::ifstream df{descriptor_file_path};

    if ( ! df.is_open() )
    {
        throw std::runtime_error("Failed to open descriptor file: " + descriptor_file_path.filename().string());
    }


    std::istringstream ss{};
    std::string current_line{};


    while ( std::getline(df, current_line) )
    {
        auto line_content = process_line(current_line);

        auto [id, filename, walkable] = line_content;

        Tile currently_loaded_tile{id, static_cast<bool>(walkable), "tiles/" + filename};

        imgpool.add_tile(id, currently_loaded_tile);
    }

    return imgpool;
}


const std::vector<int> &TilePool::get_tile_ids() const
{
    return tile_ids;
}


// ===============================================================
// MiscOperators.cpp
// ===============================================================


TDT4102::Point operator+(const TDT4102::Point p1, const TDT4102::Point p2) {
    return TDT4102::Point{ p1.x+p2.x, p1.y+p2.y };
}


TDT4102::Point operator-(const TDT4102::Point p1, const TDT4102::Point p2) {
    return TDT4102::Point{ p1.x - p2.x, p1.y - p2.y };
}

TDT4102::Point operator-(const TDT4102::Point p1)
{
    return TDT4102::Point{-p1.x, -p1.y};
}

int chebyshev_distance(TDT4102::Point p1, TDT4102::Point p2)
{
    int distance_x = std::abs(p1.x - p2.x);
    int distance_y = std::abs(p1.y - p2.y);

    return std::max(distance_x, distance_y);
}


std::ostream &operator<<(std::ostream &stream, const TDT4102::Point &point) {
    stream << "{Point: (" << point.x << ", " << point.y << ")}";
    return stream;
}



// ===============================================================
// LevelRenderer.cpp
// ===============================================================


void QuadRenderer::render(Context &ctx, TDT4102::Point anchor, TDT4102::Color color)
{
    std::array<TDT4102::Point, 4> quad;

    quad[0] = {anchor.x + TILE_WIDTH, anchor.y};
    quad[1] = {anchor.x + TILE_SIZE, anchor.y + TILE_HEIGHT};
    quad[2] = {anchor.x + TILE_WIDTH, anchor.y + TILE_HEIGHT * 2};
    quad[3] = {anchor.x, anchor.y + TILE_HEIGHT};

    ctx.getWindow().draw_quad(quad[0], quad[1], quad[2], quad[3], color);

    ctx.getWindow().draw_line(quad[0], quad[1], TDT4102::Color{255,0,0,255});
    ctx.getWindow().draw_line(quad[1], quad[2], TDT4102::Color{255,0,0,255});
    ctx.getWindow().draw_line(quad[2], quad[3], TDT4102::Color{255,0,0,255});
    ctx.getWindow().draw_line(quad[3], quad[0], TDT4102::Color{255,0,0,255});

}

LevelRenderer::LevelRenderer(Context &ctx, Level &lvl, TilePool &pool) : ctx{ctx}, lvl{lvl}, pool{pool}
{ }

void LevelRenderer::render() const
{
    const int width =  static_cast<int>(lvl.get_width());
    const int height = static_cast<int>(lvl.get_height());

    int screen_width = ctx.getWindow().width();
    int screen_height = ctx.getWindow().height();

    for ( int y = 0; y < height; y++ )
        for ( int x = 0; x < width; x++ )
        {

            auto render_position = CoordinateSystem::to_screen(ctx, TDT4102::Point{x,y});

            if ( render_position.x < -2*TILE_WIDTH || render_position.x > screen_width ) continue;
            if ( render_position.y < -2*TILE_WIDTH || render_position.y > screen_height ) continue;

            const auto tile_id = lvl.tile_at({x,y});
            auto opt_tile = pool.get_tile(tile_id);

            const bool has_tile = opt_tile.has_value();

            if ( has_tile ) {
                TileRenderer::render(ctx, opt_tile.value(), render_position);
            }
            else {
                render_position.y += TILE_WIDTH;
                QuadRenderer::render(ctx, render_position, TDT4102::Color{255,255,255,255});
            }
        }
}

TDT4102::Point CoordinateSystem::to_screen(const Context &ctx, const TDT4102::Point grid_point)
{
    auto correction = ctx.getCamera().getCorrectionVector();

    return matmul2(ctx.getCamera().getProjectionMatrix(), grid_point) + correction;
}

TDT4102::Point CoordinateSystem::to_grid(const Context &ctx, const TDT4102::Point screen_coordinate)
{
    const Camera &cam = ctx.getCamera();
    const auto correction = cam.getCorrectionVector();

    auto adjusted_coordinate = screen_coordinate - correction - TDT4102::Point{TILE_WIDTH,TILE_WIDTH};

    TDT4102::Point inverse = matmul2(
            ctx.getCamera().getInverseProjectionMatrix(),
            adjusted_coordinate);

    return inverse;
}

// =======================================================
// ================== Placement Overlay ==================
// =======================================================
PlacementOverlay::PlacementOverlay(Context &ctx) : ctx{ctx} {}

void PlacementOverlay::reset_tile()
{
    active_tile = Tile(-1, false, "");
}

void PlacementOverlay::render()
{
    bool has_image = active_tile.has_image();

    auto min_y = std::min(begin.y, end.y);
    auto max_y = std::max(begin.y, end.y);
    auto min_x = std::min(begin.x, end.x);
    auto max_x = std::max(begin.x, end.x);

    for ( int y = min_y; y <= max_y; y++ )
    {
        for ( int x = min_x; x <= max_x; x++ ) {
            auto anchor = CoordinateSystem::to_screen(ctx, {x,y});

            if ( has_image ) {
                TileRenderer::render(ctx, active_tile, anchor);
            } else {
                anchor = anchor + TDT4102::Point{0, TILE_WIDTH};
                QuadRenderer::render(ctx, anchor, TDT4102::Color{255,255,255,255});
            }
        }
    }
}


void PlacementOverlay::set_tile(Tile _tile)
{
    active_tile = _tile;
}

void PlacementOverlay::set_tile(std::optional<Tile> _tile)
{
    if ( _tile.has_value() )
        set_tile(_tile.value() );
}


void PlacementOverlay::set_begin(TDT4102::Point _begin)
{
    begin = _begin;
}
void PlacementOverlay::set_end(TDT4102::Point _end)
{
    end = _end;
}


WalkableOverlay::WalkableOverlay(const Level &lvl) : lvl{lvl}
{ }

void WalkableOverlay::render(Context &ctx)
{

    auto render_position = [&ctx] (int grid_x, int grid_y) {
        return CoordinateSystem::to_screen(
                ctx, TDT4102::Point{grid_x,grid_y})
            + TDT4102::Point{0, TILE_WIDTH};
    };

    TDT4102::Color overlay_color{255,0,0,255};
    const int width =  static_cast<int>(lvl.get_width());
    const int height = static_cast<int>(lvl.get_height());

    for ( int y = 0; y < height; y++ )
        for ( int x = 0; x < width; x++ )
        {
            if ( lvl.is_walkable({x,y}) ) {
                overlay_color = TDT4102::Color{0,255,0,255};
            } else {
                overlay_color = TDT4102::Color{255,0,0,255};
            }

            QuadRenderer::render(ctx, render_position(x,y), overlay_color);
    }
}



// ===============================================================
// Door.cpp
// ===============================================================

Door::Door(TDT4102::Point _position) : position{_position}
{ }

void Door::unlock() noexcept
{
    locked = false;
}

bool Door::is_locked() const noexcept {
    return locked;
}

const TDT4102::Point Door::get_position()  const noexcept
{
    return position;
}

DoorKey::DoorKey(std::shared_ptr<Door> door) : associated_door{door}
{ }

DoorKey::DoorKey(const DoorKey &other) : associated_door{other.associated_door}
{}

std::shared_ptr<Door> DoorKey::getDoor()
{
    return associated_door;
}



std::pair<std::shared_ptr<Door>, std::unique_ptr<DoorKey>> Locksmith::make_door(TDT4102::Point position)
{
    auto door = std::make_shared<Door>(position);

    DoorKey *key_ptr = new DoorKey{door};
    std::unique_ptr<DoorKey> key;
    key.reset(key_ptr);


    return std::make_pair(door, std::move(key));
}


TDT4102::Point DoorKeyEntity::get_position() const noexcept
{
    return position;
}


void DoorKeyEntity::set_position(TDT4102::Point _position)
{
    position = _position;
}

std::unique_ptr<DoorKey> DoorKeyEntity::get_key()
{
    return std::move(key);
}

DoorKey &DoorKeyEntity::get_key_ref()
{
    return *key;
}

TDT4102::Color DoorKeyEntity::get_color() const noexcept
{
    return color;
}


void DoorKeyEntity::draw(Context &ctx)
{

        TDT4102::AnimationWindow &window = ctx.getWindow();

        TDT4102::Point screen_coord = CoordinateSystem::to_screen(ctx, get_position());

        draw_static(ctx, screen_coord);
}


void DoorKeyEntity::draw_static(Context &ctx, TDT4102::Point coordinate)
{

        TDT4102::AnimationWindow &window = ctx.getWindow();


        window.draw_arc(coordinate + TDT4102::Point{10,10}, 8, 8, 0, 360, color);
        window.draw_arc(coordinate + TDT4102::Point{10,10}, 7, 7, 0, 360, color);
        window.draw_arc(coordinate + TDT4102::Point{10,10}, 6, 6, 0, 360, color);

        window.draw_line(coordinate + TDT4102::Point{10, 18}, coordinate + TDT4102::Point{10, 36}, color);
        window.draw_line(coordinate + TDT4102::Point{11, 18}, coordinate + TDT4102::Point{11, 36}, color);
        window.draw_line(coordinate + TDT4102::Point{12, 18}, coordinate + TDT4102::Point{12, 36}, color);
        window.draw_line(coordinate + TDT4102::Point{9, 18}, coordinate + TDT4102::Point{9, 36}, color);
        window.draw_line(coordinate + TDT4102::Point{9, 18}, coordinate + TDT4102::Point{9, 36}, color);
        window.draw_line(coordinate + TDT4102::Point{8, 18}, coordinate + TDT4102::Point{8, 36}, color);

        window.draw_line(coordinate + TDT4102::Point{8, 36}, coordinate + TDT4102::Point{17, 36}, color);
        window.draw_line(coordinate + TDT4102::Point{8, 35}, coordinate + TDT4102::Point{17, 35}, color);
        window.draw_line(coordinate + TDT4102::Point{8, 34}, coordinate + TDT4102::Point{17, 34}, color);


        window.draw_line(coordinate + TDT4102::Point{8, 30}, coordinate + TDT4102::Point{15, 30}, color);
        window.draw_line(coordinate + TDT4102::Point{8, 29}, coordinate + TDT4102::Point{15, 29}, color);
        window.draw_line(coordinate + TDT4102::Point{8, 28}, coordinate + TDT4102::Point{15, 28}, color);
}

