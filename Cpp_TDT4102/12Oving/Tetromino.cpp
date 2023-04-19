#include "Tetromino.h"

    
const std::map<TetrominoType, std::vector<std::vector<int>>> initialMatrixMap {
    {
    TetrominoType::J,
        {
        {0, 0, 0},
        {1, 1, 1},
        {0, 0, 1}
        }
    },
    {
    TetrominoType::L,
        {
        {0, 0, 0},
        {1, 1, 1},
        {1, 0, 0}
        }
    },
    {
    TetrominoType::T,
        {
        {0, 0, 0},
        {1, 1, 1},
        {0, 1, 0}
        }
    },
    {
    TetrominoType::S,
        {
        {0, 0, 0},
        {0, 1, 1},
        {1, 1, 0}
        }
    },
    {
    TetrominoType::Z,
        {
        {0, 0, 0},
        {1, 1, 0},
        {0, 1, 1}
        }
    },
    {
    TetrominoType::O,
        {
        {1, 1},
        {1, 1}
        }
    },
    {
    TetrominoType::I,
        {
        {0, 0, 0, 0},
        {1, 1, 1, 1},
        {0, 0, 0, 0},
        {0, 0, 0, 0}
        }
    }
};



Tetromino::Tetromino(TDT4102::Point startingPoint, TetrominoType tetType) : topLeftCorner{startingPoint}
{
    matrixSize = initialMatrixMap.at(tetType).size();
    color = colorMap.at(tetType);
    for (int i = 0; i < matrixSize; i++) {
        std::vector<TetrominoType> row;
        for (int j = 0; j < matrixSize; j++) {
            row.push_back((initialMatrixMap.at(tetType)[i][j] == 1) ? tetType : TetrominoType::NONE);
        }
        blockMatrix.push_back(row);
    }
}


Tetromino::Tetromino() {
    matrixSize = 0;
    topLeftCorner = TDT4102::Point{0,0};
}

TetrominoType Tetromino::getTetType() {
    return blockMatrix[1][1];
}

void Tetromino::rotateCounterClockwise() {
    //Første rotasjon, med hensyn på diagonalen
    for(int row = 0; row < matrixSize; row++){
        for(int column = 0; column < row; column++){
            std::swap(blockMatrix[row][column], blockMatrix[column][row]);
        }
    }

    //Andre rotasjon, med hensyn på den midtre raden
    for(int row = 0; row < matrixSize/2; row++){
        for(int column = 0; column < matrixSize; column++){
            std::swap(blockMatrix[row][column], blockMatrix[matrixSize-row-1][column]);
            
        }
    }
}

void Tetromino::rotateClockwise() {
    //Første rotasjon, med hensyn på diagonalen
    for(int row = 0; row < matrixSize; row++){
        for(int column = 0; column < row; column++){
            std::swap(blockMatrix[row][column], blockMatrix[column][row]);
        }
    }
     
    //Andre rotasjon, med hensyn på den midtre kolonnen
    for(int row = 0; row < matrixSize; row++){
        for(int column = 0; column < matrixSize/2; column++){
            std::swap(blockMatrix[row][column], blockMatrix[row][matrixSize-column-1]);
        }
    }
}

void Tetromino::moveDown() {
    topLeftCorner.y += blockSize;
}

void Tetromino::moveLeft() {
    topLeftCorner.x -= blockSize;
}

void Tetromino::moveRight() {
    topLeftCorner.x += blockSize;
}

bool Tetromino::blockExists(int row, int col) {
    return blockMatrix[row][col] != TetrominoType::NONE;
}

int Tetromino::getMatrixSize() {
    return matrixSize;
}

TetrominoType Tetromino::getBlock(int row, int col) {
    return blockMatrix[row][col];
}

TDT4102::Point Tetromino::getPosition() {
    return topLeftCorner;
}

//
//
//Tetromino& Tetromino::operator=(const std::vector<std::vector<int>>& other) {
//        for (int i = 0; i < matrixSize; i++) {
//            for (int j = 0; j < matrixSize; j++) {
//                blockMatrix[i][j] = (other[i][j] == 1) ? other.getTetType() : TetrominoType::NONE;
//            }
//        }
//    return *this;
//}
//
