#pragma once
#include "subprojects/animationwindow/include/Point.h"
#include <vector>
#include <map>
#include "subprojects/animationwindow/include/AnimationWindow.h"


enum class TetrominoType{J, L, T, S, Z, O, I, NONE};

const std::map<TetrominoType, TDT4102::Color> colorMap {
    {TetrominoType::J, TDT4102::Color::blue},
    {TetrominoType::L, TDT4102::Color::orange},
    {TetrominoType::T, TDT4102::Color::purple},
    {TetrominoType::S, TDT4102::Color::green},
    {TetrominoType::Z, TDT4102::Color::red},
    {TetrominoType::O, TDT4102::Color::yellow},
    {TetrominoType::I, TDT4102::Color::cyan}
};

class Tetromino {
    private: 
    int matrixSize;
    TDT4102::Point topLeftCorner;
    std::vector<std::vector<TetrominoType>> blockMatrix;
    TDT4102::Color  color;
public:
    static constexpr int blockSize {30};

    Tetromino(TDT4102::Point startingPoint, TetrominoType tetType);
    Tetromino();
    TetrominoType getTetType();
    
    void rotateClockwise();
    void rotateCounterClockwise();
    bool blockExists(int row, int col);
    int getMatrixSize();
    TetrominoType getBlock(int row, int col);
    TDT4102::Point getPosition();
    TDT4102::Color getColor(){return color;};


    void moveDown();
    void moveLeft();
    void moveRight();
    void moveUp();

    Tetromino& operator=(const std::vector<std::vector<int>>& other);


};  