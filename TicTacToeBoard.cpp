#include "TicTacToeBoard.h"
#include <iostream>
using namespace std;
/**
 * Class for representing a 3x3 Tic-Tac-Toe game board, using the Piece enum
 * to represent the spaces on the board.
**/

//Switches turn member variable to represent whether it's X's or O's turn
void TicTacToeBoard::toggleTurn()
{
    if(turn == X)
        turn = O;
    else
        turn = X;
}

//Constructor sets an empty board and specifies it is X's turn first
TicTacToeBoard::TicTacToeBoard()
{
    turn = X;
    clearBoard();
}

//Resets each board location to the Blank Piece value
void TicTacToeBoard::clearBoard()
{
   for(int r=0; r<BOARDSIZE; r++) {
        for(int c=0; c<BOARDSIZE; c++) {
            board[r][c] = Blank;
        }
    } 
}

/**
 * Places the piece of the current turn on the board, returns what
 * piece is placed, and toggles which Piece's turn it is. placePiece does 
 * NOT allow to place a piece in a location where there is already a piece.
 * In that case, placePiece just returns what is already at that location. 
 * Out of bounds coordinates return the Piece Invalid value
**/ 
Piece TicTacToeBoard::placePiece(int row, int column)
{
    Piece toReturn;
    if(row >= 0 && column >= 0 && row < BOARDSIZE && column < BOARDSIZE) {
        if(board[row][column] == Blank) {
            board[row][column] = turn;

            toReturn = turn;
        } else {
            toReturn = board[row][column];
        }
    } else {
        toReturn = Invalid;
    }


    toggleTurn();

    return toReturn;
}

/**
 * Returns what piece is at the provided coordinates, or Blank if there
 * are no pieces there, or Invalid if the coordinates are out of bounds
**/
Piece TicTacToeBoard::getPiece(int row, int column)
{
    if(row >= 0 && column >= 0 && row < BOARDSIZE && column < BOARDSIZE) {
        return board[row][column];
    }

    return Invalid;
}

/**
 * Returns which Piece has won, if there is a winner, Invalid if the game
 * is not over, or Blank if the board is filled and no one has won.
**/
Piece TicTacToeBoard::getWinner()
{
    int xH = 0;
    int xV = 0;
    int xD = 0;

    int oH = 0;
    int oV = 0;
    int oD = 0;

    int numFilled = 0;

    for(int r=0; r<=BOARDSIZE; r++) {
        for(int c=0; c<=BOARDSIZE; c++) {
            Piece cur  = getPiece(r, c);
            Piece up   = getPiece(r-1, c);
            Piece back = getPiece(r, c-1);
            Piece diag = getPiece(r-1, c-1);

            if(cur != Blank) {
                ++numFilled;

                if(back == cur) {
                    if(cur == X)
                        ++xH;
                    else
                        ++oH;
                }
                if(up == cur) {
                    if(cur == X)
                        ++xV;
                    else
                        ++oV;
                }
                if(diag == cur) {
                    if(cur == X)
                        ++xD;
                    else
                        ++oD;
                }
            }
        }
    }

    if(xH == BOARDSIZE-1 || xV == BOARDSIZE-1 || xD == BOARDSIZE-1)
        return X;
    else if(oH == BOARDSIZE-1 || oV == BOARDSIZE-1 || oD == BOARDSIZE-1)
        return O;
    else if(numFilled == BOARDSIZE * BOARDSIZE)
        return Blank;
    else
        return Invalid;
}
