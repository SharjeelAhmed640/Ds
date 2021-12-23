
#include <iostream>
#include <sstream>

#include <string>

using namespace std;

class Board
{
    int squares[3][3];

public:
    Board();
    string toString();
    void play_square(int, int, int);
    int get_square(int, int);
    int winner();
    bool full_board();
};

Board::Board()
{
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            squares[i][j] = 0;
}

void Board::play_square(int row, int col, int val)
{

    squares[row - 1][col - 1] = val;
}

bool Board::full_board()
{
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (squares[i][j] == 0)
                return false;
    return true;
}

int Board::winner()
{

    for (int row = 0; row < 3; row++)
        if (squares[row][0] != 0 && squares[row][0] == squares[row][1] && squares[row][0] == squares[row][2])
            return squares[row][0];

    for (int col = 0; col < 3; col++)
        if (squares[0][col] != 0 && squares[0][col] == squares[1][col] && squares[0][col] == squares[2][col])
            return squares[0][col];

    if (squares[0][0] != 0 && squares[0][0] == squares[1][1] && squares[0][0] == squares[2][2])
        return squares[0][0];
    if (squares[2][0] != 0 && squares[2][0] == squares[1][1] && squares[2][0] == squares[0][2])
        return squares[2][0];
    return 0;
}

int Board::get_square(int row, int col)
{
    return squares[row - 1][col - 1];
}

bool makemove(Board *b, int cpuval)
{
    for (int i = 1; i < 4; i++)
        for (int j = 1; j < 4; j++)
            if (b->get_square(i, j) == 0)
            {
                b->play_square(i, j, cpuval);
                return true;
            }
    return false;
}

int main()
{
    Board *b = new Board();
    int player1 = 1;
    int player2 = -1;
    int count, p1 = 0, p2 = 0;
    for (int i = 1; i <= 3; i++)
    {
        for (int j = 1; j <= 3; j++)
        {
            cin >> count;
            if (count == 2)
                count = -1;
            b->play_square(i, j, count);
            if (count == 1)
                p1++;
            else if (count == -1)
                p2++;
        }
    }
    if (abs(p1 - p2) == 0 || abs(p1 - p2) == 1)
        ;
    else
    {
        cout << "-1";
        exit(1);
    }

    while (!b->full_board() && b->winner() == 0)
    {
        {
            makemove(b, player1);
            if (b->full_board() || b->winner() != 0)
                break;
            else
            {

                makemove(b, player2);
            }
        }
    }
    if (b->winner() == 0)
        cout << "0" << endl;
    else if (b->winner() == player1)
        cout << "2" << endl;
    else if (b->winner() == player2)
        cout << "1" << endl;
    // char a;
    // cin >> a;
    return 0;
}