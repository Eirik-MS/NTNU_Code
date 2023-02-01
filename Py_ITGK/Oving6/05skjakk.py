
def make_board():
    board = []
    for i in range(8):
        board.append([])
        for j in range(8):
            board[i].append(" ")
    return board