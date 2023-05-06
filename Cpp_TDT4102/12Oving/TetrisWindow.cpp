#include "TetrisWindow.h"
#include <iostream>
#include <subprojects/animationwindow/include/Point.h>
#include <algorithm>    // std::all_of
#include <array>

TetrisWindow::TetrisWindow(){
    gridWidth = 10;
    gridHeight = 20;
    gridMatrix = std::vector<std::vector<TetrominoType>>(gridHeight, std::vector<TetrominoType>(gridWidth, TetrominoType::NONE));
    currentTetromino = generateRandomTetromino();
}

void TetrisWindow::run() {
    unsigned int framesSinceLastTetronimoMove = 0;
    const unsigned int framesPerTetronimoMove = 20;

    while(!should_close()) { 
        framesSinceLastTetronimoMove++;
        if(framesSinceLastTetronimoMove >= framesPerTetronimoMove) {
            framesSinceLastTetronimoMove = 0;
            /********************************************************/
            moveTetrominoDown();
            /********************************************************/
        }
        handleInput();
        
        /********************************************************/
        //Kall draw-funksjonene her
        drawCurrentTetromino();
        drawGridMatrix();
        /********************************************************/

        next_frame();
    }
}

Tetromino TetrisWindow::generateRandomTetromino(){
    int random = rand() % 7;
    TetrominoType tetType;
    switch(random) {
        case 0:
            tetType = TetrominoType::J;
            break;
        case 1:
            tetType = TetrominoType::L;
            break;
        case 2:
            tetType = TetrominoType::T;
            break;
        case 3:
            tetType = TetrominoType::S;
            break;
        case 4:
            tetType = TetrominoType::Z;
            break;
        case 5:
            tetType = TetrominoType::O;
            break;
        case 6:
            tetType = TetrominoType::I;
            break;
    }
    return Tetromino(TDT4102::Point{0, 0}, tetType);
}

void TetrisWindow::drawCurrentTetromino(){
    for (int i = 0; i < currentTetromino.getMatrixSize(); i++) {
        for (int j = 0; j < currentTetromino.getMatrixSize(); j++) {
            if(currentTetromino.getBlock(i,j) != TetrominoType::NONE) {
                AnimationWindow::draw_rectangle(TDT4102::Point{currentTetromino.getPosition().x + i*currentTetromino.blockSize, currentTetromino.getPosition().y + j*currentTetromino.blockSize},
                                                currentTetromino.blockSize, 
                                                currentTetromino.blockSize, 
                                                currentTetromino.getColor());
            }
        }
    }
}

void TetrisWindow::handleInput() {

    static bool lastZKeyState = false;
    static bool lastUpKeyState = false;
    static bool lastLeftKeyState = false;
    static bool lastRightKeyState = false;
    static bool lastDownKeyState = false;

    bool currentZKeyState = is_key_down(KeyboardKey::Z);
    bool currentUpKeyState = is_key_down(KeyboardKey::UP);
    bool currentLeftKeyState = is_key_down(KeyboardKey::LEFT);
    bool currentRightKeyState = is_key_down(KeyboardKey::RIGHT);
    bool currentDownKeyState = is_key_down(KeyboardKey::DOWN);
    

    
    if(currentZKeyState && !lastZKeyState) {
        std::cout << "Hello from z\n";
        currentTetromino.rotateCounterClockwise();
        if (hasChrashed()) {
            currentTetromino.rotateClockwise();
        }
    }

    if(currentUpKeyState && !lastUpKeyState) {
        std::cout << "Hello from up\n";
        currentTetromino.rotateClockwise();
        if (hasChrashed()) {
            currentTetromino.rotateCounterClockwise();
        }
    }

    if(currentLeftKeyState && !lastLeftKeyState) {
        std::cout << "Hello from left\n";
            bool isFirstColumnZero = true;
            bool isSecondColumnZero = true;
            for (int i = 0; i < currentTetromino.getMatrixSize(); i++) {
                if (currentTetromino.getBlock(0,i) != TetrominoType::NONE) {
                    isFirstColumnZero = false;
                }
                if (currentTetromino.getBlock(1,i) != TetrominoType::NONE) {
                    isSecondColumnZero = false;
                }
            }
            if (currentTetromino.getPosition().x > 0) {
                currentTetromino.moveLeft();
                if(hasChrashed())currentTetromino.moveRight();
            }
            else if (currentTetromino.getPosition().x == 0 && isFirstColumnZero) {
                currentTetromino.moveLeft();
                if(hasChrashed())currentTetromino.moveRight();
            }
            else if (currentTetromino.getPosition().x == -blockSize && isSecondColumnZero) {
                currentTetromino.moveLeft();
                if(hasChrashed())currentTetromino.moveRight();
            }
            
            
    }

    if(currentRightKeyState && !lastRightKeyState) {
        std::cout << "Hello from right\n";
        bool isLastColumnZero = true;
            bool isSecondLastColumnZero = true;
            for (int i = 0; i < currentTetromino.getMatrixSize(); i++) {
                if (currentTetromino.getBlock(currentTetromino.getMatrixSize()-1,i) != TetrominoType::NONE) {
                    isLastColumnZero = false;
                }
                if (currentTetromino.getBlock(currentTetromino.getMatrixSize()-2,i) != TetrominoType::NONE) {
                    isSecondLastColumnZero = false;
                }
            }
            if (currentTetromino.getPosition().x < gridWidth*blockSize) {
                currentTetromino.moveRight();
                if(hasChrashed())currentTetromino.moveLeft();
            }
            else if (currentTetromino.getPosition().x == gridWidth*blockSize && isLastColumnZero) {
                currentTetromino.moveRight();
                if(hasChrashed())currentTetromino.moveLeft();
            }
            else if (currentTetromino.getPosition().x == gridWidth*blockSize+blockSize && isSecondLastColumnZero) {
                currentTetromino.moveRight();
                if(hasChrashed())currentTetromino.moveLeft();
            }
    }

    if(currentDownKeyState && !lastDownKeyState) {
        std::cout << "Hello from down\n";
        currentTetromino.moveDown();
    }



    lastZKeyState = currentZKeyState;
    lastUpKeyState = currentUpKeyState;
    lastLeftKeyState = currentLeftKeyState;
    lastRightKeyState = currentRightKeyState;
    lastDownKeyState = currentDownKeyState;
}

void TetrisWindow::moveTetrominoDown() {
    if (currentTetromino.getPosition().y+currentTetromino.getMatrixSize() < gridHeight*blockSize){
        currentTetromino.moveDown();
        if (hasChrashed()) {
            currentTetromino.moveUp();
            fastenTetromino();
            currentTetromino = generateRandomTetromino();
        }
    }
    
}

void TetrisWindow::drawGridMatrix() {
    for (int i = 0; i < gridHeight; i++) {
        for (int j = 0; j < gridWidth; j++) {
            if(gridMatrix[i][j] != TetrominoType::NONE) {
                AnimationWindow::draw_rectangle(TDT4102::Point{blockSize*j,blockSize*i},
                                                blockSize, 
                                                blockSize, 
                                                colorMap.at(gridMatrix[i][j]));
            }
        }
    }
}

void TetrisWindow::fastenTetromino(){
    for (int i = 0; i < currentTetromino.getMatrixSize(); i++) {
        for (int j = 0; j < currentTetromino.getMatrixSize(); j++) {
            if (currentTetromino.getBlock(i,j) != TetrominoType::NONE) {
                gridMatrix[currentTetromino.getPosition().y/blockSize + i]
                          [currentTetromino.getPosition().x/blockSize + j] = currentTetromino.getBlock(j,i);
            }
        }
    }
};

bool TetrisWindow::hasChrashed(){
    for (int i = 0; i < currentTetromino.getMatrixSize(); i++) {
        for (int j = 0; j < currentTetromino.getMatrixSize(); j++) {
            if (currentTetromino.getBlock(i,j) != TetrominoType::NONE) {
                if (gridMatrix[currentTetromino.getPosition().x/blockSize + i]
                    [currentTetromino.getPosition().y/blockSize + j] != TetrominoType::NONE) {
                    return true;
                }
            }
        }
    }
    return false;
}

