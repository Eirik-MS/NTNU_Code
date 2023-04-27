#pragma once
#include "subprojects/animationwindow/include/AnimationWindow.h"
#include "Tetromino.h"
#include "widgets/TextInput.h"
#include "widgets/Button.h"
#include <vector>

class TetrisWindow : public TDT4102::AnimationWindow {
private:
    

    

    void handleInput();

public:
    std::vector<std::vector<TetrominoType>> gridMatrix;
    Tetromino currentTetromino;
    int gridWidth;
    int gridHeight;

    static constexpr int blockSize {30};
    TetrisWindow();
    void run();

    

    Tetromino generateRandomTetromino();
    void drawCurrentTetromino();
    void moveTetrominoDown();

    void drawGridMatrix();
    void fastenTetromino();
    bool hasChrashed();




};