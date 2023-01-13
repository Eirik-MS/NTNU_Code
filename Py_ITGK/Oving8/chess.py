
def make_board():
    """Makes a new chess board"""
    board = []
    for i in range(8):
        board.append([])
        for j in range(8):
            board[i].append(None)

    blackRow= ['♖', '♘', '♗', '♕', '♔', '♗', '♘', '♖']
    whiteRow= ['♜', '♞', '♝', '♛', '♚', '♝', '♞', '♜']

    for i in range(len(board)):
        board[0][i] = blackRow[i]
        board[1][i] = '♙'
        board[6][i] = '♟'
        board[7][i] = whiteRow[i]

    return board

def print_board(board):
    """Prints the chess board"""
    for i in range(len(board)):
        print(1+i, end=' ')
        for j in range(len(board[i])):
            if board[i][j] == None:
                print(' ', end=' ')
            else:
                print(board[i][j], end=' ')
        print()
    print('  a b c d e f g h')

    print(board[6][0])

def move_piece(piece, newPos):
    
    return 0

def check_ocupied(board, position):
    if board[position[0]][position[1]] != None:
        return True
    else: 
        return False

def check_legal_move(board, piece, move):
    match board[piece[0]][piece[1]]:
        case '♜' | '♖':
            if piece[0] == move[0] or piece[1] == move[1]:
                if piece[0] == move[0]:
                    for i in range(piece[1], move[1]):
                        if board[piece[0]][i] != None: raise ValueError
                
                return True
        case '♞' | '♘':
            pass
        case '♝' | '♗':
            pass
        case '♛' | '♕':
            pass
        case '♚' | '♔':
            pass
        case '♟' | '♙':
            if piece[1] == move[1]:
                return True
            elif piece[0] + 1 == move[0] or piece[0] - 1 == move[0]:
                if check_ocupied(move):
                    
            
            pass
        case _:
            raise ValueError
    return 0

def input_move():
    print("Enter all moves with format a2")
    piece = input("please enter witch pice you wold like to move:\n")
    move = input("Please enter where to move the pice:\n")

    char = piece[0]
    piece = [int(piece[1])-1, ord(char)-97]
    char = move[0]
    move = [ int(move[1])-1, ord(char)-97]

    return piece,move

def check_mate(board):
    
    return False



def main():
    Win = False
    board = make_board()
    print_board(board)
    while not Win:
        try:
            piece,move = input_move()
            if not check_ocupied(board,piece): raise ValueError
            check_legal_move(board, piece, move)
            move_piece(board, piece, move)
            Win = check_mate(board)
            print_board(board)
        except ValueError:
            print("The input does not match the fromat a7")
            pass
        except IndexError: 
            print("index error")
            pass
        finally:
            print('other error')
            exit()


if __name__ == "__main__":
    main()
