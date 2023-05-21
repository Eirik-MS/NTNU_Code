#include "Gameoflife.h"

#include <algorithm>
#include <cassert>
#include <exception>
#include <fstream>
#include <iostream>
#include <vector>
#include <vector>
#include <cmath>

#include "AnimationWindow.h"

using namespace TDT4102;

Cell::Cell(Point pos, int size = 30)
    : state(State::Dead), pos{pos}, size{size} {}

// TASK
int Cell::get_value() const {
    // BEGIN: C1

    return static_cast<int>(this->state);
    // END: C1
}

// TASK
void Cell::kill() {
    // BEGIN: C3
    state = State::Dead;
    // END: C3
}

// TASK
void Cell::resurrect() {
    // BEGIN: C4
    state = State::Live;
    // END: C4
}

// TASK
void Cell::set_state(char c) {
    // BEGIN: C5
    state = char_to_state.at(c);
    // END: C5
}

// TASK
std::istream& operator>>(std::istream& is, Cell& cell) {
    // BEGIN: C6
    char c;
    is >> c;
    cell.set_state(c);
    return is;
    // END: C6
}

// TASK
bool Cell::is_alive() const {
    // BEGIN: C7
    int i = 0;
    i++;
    return this->state == State::Live;
    // END: C7
}

// TASK
char Cell::as_char() const {
    // BEGIN: C8
    return chars[(int)state];
    // END: C8
}

// TASK
Gameoflife::Gameoflife(int x_cells,
                       int y_cells,
                       const std::string& window_title)
    : AnimationWindow{50, 50, x_cells * cell_size + 5 * button_width + 2 * margin,
                      y_cells * cell_size + 2 * margin,
                      window_title},
      x_cells{x_cells},
      y_cells{y_cells},

      step_btn{{x_cells * cell_size + 2 * margin + 3 * button_width, 3 * margin}, button_width, button_height, "Step"},
      steps_input{{x_cells * cell_size + 2 * margin + button_width, 3 * margin}, button_width * 2, button_height, "Number of steps"},
      filename_input{{x_cells * cell_size + 2 * margin + button_width, button_height + 5 * margin}, button_width * 2, button_height, "Filename"},
      load_btn{{x_cells * cell_size + 2 * margin + 3 * button_width, button_height + 5 * margin}, button_width, button_height, "Load"},
      save_btn{{x_cells * cell_size + 2 * margin + 3 * button_width, 2 * button_height + 7 * margin}, button_width, button_height, "Save"},
      play_pause_btn{{x_cells * cell_size + margin + button_width, 2 * button_height + 7 * margin}, button_width * 2, button_height, "Play/Pause"} {
    // Provided (asserts and attach() calls)
    // Asserts are here to make sure any unintended changes to
    // compile-time constants makes the exercise less hard to debug.
    assert(x_cells > 0);
    assert(y_cells > 0);
    assert(button_width > 0);
    assert(margin > 0);

    step_btn.setCallback(std::bind(&Gameoflife::step_pressed, this));
    add(step_btn);
    play_pause_btn.setCallback(std::bind(&Gameoflife::play_pause, this));
    add(play_pause_btn);
    load_btn.setCallback(std::bind(&Gameoflife::load_state, this));
    add(load_btn);
    save_btn.setCallback(std::bind(&Gameoflife::save_state, this));
    add(save_btn);

    add(filename_input);
    add(steps_input);

    // BEGIN: G1
    for (int i = 0; i < x_cells; i++){
        std::vector<Cell> col;  
        for (int j = 0; j < y_cells; j++){
            int xPos = i*cell_size+margin;
            int yPos = j*cell_size+margin;
            col.emplace_back(Cell(TDT4102::Point{xPos,yPos},cell_size));
        }
        grid[0].push_back(col);
    }
   
    get_scratch_grid() = get_current_grid();

    //grid[0].push_back(Cell(TDT4102::Point{i,j},cell_size));
    // END: G1
}

// TASK
std::istream& operator>>(std::istream& is, Gameoflife& gameoflife) {
    // BEGIN: G2
    std::string line;
    int rows = 0;
    while(std::getline(is, line)){
        for (int i = 0; i < line.length();i++){
            gameoflife.get_current_grid()[i][rows].set_state(line[i]);
        }
        rows++; 
    }
    return is;
    // END: G2
}

// TASK
void Gameoflife::load(const std::string& filename) {
    // BEGIN: G3
    try{
        std::filesystem::path file{filename};
        std::ifstream input_stream{file};
        !input_stream.good() ? throw(std::runtime_error("File not found")): 
        input_stream >> *this;
    }
    catch (std::exception& ex){
        std::cerr << "Exception caught: " << ex.what() << std::endl;
    }
    return;
    // END: G3
}

// TASK

void Gameoflife::drawState() {
    //C2
    for (int i = 0; i < x_cells; i++){ 
        for (int j = 0; j < y_cells; j++){
            Cell current = get_current_grid()[i][j];
            draw_rectangle(current.get_pos(), current.get_size(), current.get_size(), current.colors[current.get_value()]);
        }
        
    }
    //C2
}

void Gameoflife::step() {
    // BEGIN: G4
    for (int x = 0; x < x_cells; x++){
        for (int y = 0; y < y_cells; y++){
            Cell currentCell = get_current_grid().at(x).at(y);
            Cell scratchCell = get_scratch_grid().at(x).at(y);
            // Check how many Cells is alive around current cell
            int alive_around = 0;
            //Colum to the left
            if(get_current_grid().back().back().is_alive()) { alive_around++;}
            //if(get_current_grid()[x-1][y  ].is_alive()) { alive_around++;}
            //if(get_current_grid()[x-1][y+1].is_alive()) { alive_around++;}
            ////Colum to the rigth
            //if(get_current_grid()[x+1][y-1].is_alive()) { alive_around++;}
            //if(get_current_grid()[x+1][y  ].is_alive()) { alive_around++;}
            //if(get_current_grid()[x+1][y+1].is_alive()) { alive_around++;}
            ////above and below
            //if(get_current_grid()[x  ][y-1].is_alive()) { alive_around++;}
            //if(get_current_grid()[x  ][y+1].is_alive()) { alive_around++;}

            if (currentCell.is_alive()){
                //if it has 2 or 3 live naighbordas it lives
                if(alive_around == 2 || alive_around == 3){
                    scratchCell.resurrect();
                }else{
                //if not it dies
                    scratchCell.kill();
                }
            }else{
                //if 3 friends its alive again
                if(alive_around == 3){
                    scratchCell.resurrect();
                }else{
                //if not it stays dead
                    scratchCell.kill();
                }
            }
        }
    }

    std::swap(current_grid, scratch_grid);
    // END: G4
}

// TASK
void Gameoflife::step(int steps) {
    // BEGIN: G5
    for (int i = 0; i < steps; i++){
        Gameoflife::step();
    }
    // END: G5
}

// TASK
Cell* Gameoflife::cell_at_pos(Point pos) {
    // BEGIN: E1
    bool validX = margin <= pos.x && pos.x <= cell_size*x_cells;
    bool validY = margin <= pos.y && pos.y <= cell_size*y_cells;
    if (validX && validY){
        int indexX = static_cast<int>(std::floor((pos.x-margin)/cell_size));
        int indexY = static_cast<int>(std::floor((pos.y-margin)/cell_size));
        Cell* cellptr = &get_current_grid().at(indexX).at(indexY);
        return cellptr;
    }else{
        return nullptr;
    }

    
    // END: E1
}

// TASK
void Cell::toggle() {
    // BEGIN: E2
    if(is_alive()){
        state = State::Dead;
    }else{
        state = State::Live;
    }
    // END: E2
}

// TASK
bool Gameoflife::toggle_cell(Point pos) {
    // BEGIN: E3
    Cell* cellptr = cell_at_pos(pos);
    if (cellptr == nullptr){
        return false;
    }else{
        cellptr->toggle();
        return true;
    }
    
    // END: E3
}

// Provided
std::ostream& operator<<(std::ostream& os, const Cell& cell) {
    return os << cell.as_char();
}

// Provided
void Gameoflife::save(const std::string& filename) {
    constexpr std::string_view ext = ".cgol";
    if (filename.size() < ext.size() ||
        filename.substr(filename.size() - 5, 5) != ext) {
        throw std::runtime_error{"'" + filename +
                                 "' does not have the correct file extension: "
                                 "'.cgol' or is too short."};
    }

    std::ofstream ofs{filename};
    if (!ofs) {
        throw std::runtime_error{"Could not save the CGoL state to '" +
                                 filename + "'."};
    }

    ofs << *this;
}

// Provided
std::ostream& operator<<(std::ostream& os, const Gameoflife& gameoflife) {
    for (auto& row : gameoflife.get_current_grid()) {
        for (auto&& cell : row) {
            os << cell;
        }
        os << '\n';
    }

    return os;
}

// Provided
void Gameoflife::step_pressed() {
    int steps;
    try {
        steps = stoi(steps_input.getText());
    } catch (std::invalid_argument) {
        steps = 1;
    }
    steps = std::clamp(steps, min_steps, max_steps);
    step(steps);
}

// Provided
void Gameoflife::load_state() {
    const std::string& filename = filename_input.getText();
    try {
        load(filename);
    } catch (const std::runtime_error& e) {
        alert(e.what());
    }
}

// Provided
void Gameoflife::save_state() {
    const std::string& filename = filename_input.getText();
    try {
        save(filename);
    } catch (const std::runtime_error& e) {
        alert(e.what());
    }
}

// Provided
Gameoflife::Grid& Gameoflife::get_current_grid() { return grid[current_grid]; }
Gameoflife::Grid& Gameoflife::get_scratch_grid() { return grid[scratch_grid]; }
const Gameoflife::Grid& Gameoflife::get_current_grid() const {
    return grid[current_grid];
}
const Gameoflife::Grid& Gameoflife::get_scratch_grid() const {
    return grid[scratch_grid];
}

// Provided
void Gameoflife::alert(const std::string& message) {
    AnimationWindow::show_info_dialog(message);
}

// Provided
int Gameoflife::click_handler(Point pos) { return toggle_cell(pos); }

// Provided
void Gameoflife::play_pause() {
    playing = !playing;
}

// Provided
void Gameoflife::run() {
    Uint64 last_updated = 0;
    while (!should_close()) {
        if (left_mouse_clicked()) {
            click_handler(get_mouse_coordinates());
        }
        drawState();
        next_frame();
        if (playing) {
            Uint64 current = SDL_GetTicks64();
            if (current - last_updated > animation_interval) {
                step(1);
                last_updated = current;
            }
        }
    }
}

// Provided
bool Gameoflife::left_mouse_clicked() {
    static bool was_down = false;
    bool is_down = is_left_mouse_button_down();
    if (is_down && was_down) {
        return false;
    } else if (is_down) {
        was_down = true;
        return true;
    } else {
        was_down = false;
        return false;
    }
}

// Provided
Gameoflife::~Gameoflife() {
    playing = false;
}
