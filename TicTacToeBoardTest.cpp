/**
 * Unit Tests for TicTacToeBoard
**/

#include <gtest/gtest.h>
#include "TicTacToeBoard.h"
 
class TicTacToeBoardTest : public ::testing::Test
{
	protected:
		TicTacToeBoardTest() {
        } //constructor runs before each test
		virtual ~TicTacToeBoardTest(){} //destructor cleans up after tests
		virtual void SetUp(){} //sets up before each test (after constructor)
		virtual void TearDown(){} //clean up after each test, (before destructor) 
};

TEST(TicTacToeBoardTest, sanityCheck)
{
	ASSERT_TRUE(true);
}

TEST(TicTacToeBoardTest, initBoard) {
    TicTacToeBoard myBoard;

    // ensure all locations initialized to zero
    for(int r=0; r<3; r++) {
        for(int c=0; c<3; c++) {
            EXPECT_EQ(' ', myBoard.getPiece(r, c));
        }
    }
}

TEST(TicTacToeBoardTest, toggleTurn) {
    TicTacToeBoard myBoard;

    // turn should flip after each piece is placed
    EXPECT_EQ('X', char(myBoard.placePiece(0, 0)));
    EXPECT_EQ('O', char(myBoard.placePiece(0, 1)));
    EXPECT_EQ('X', char(myBoard.placePiece(0, 2)));
    EXPECT_EQ('O', char(myBoard.placePiece(1, 0)));
}

TEST(TicTacToeBoardTest, placePieces) {
    TicTacToeBoard myBoard;

    // basic piece placement
    EXPECT_EQ('X', char(myBoard.placePiece(0, 0)));
    EXPECT_EQ('O', char(myBoard.placePiece(1, 0)));

    // place piece in nonempty location
    EXPECT_EQ('O', char(myBoard.placePiece(1, 0)));
    EXPECT_EQ('X', char(myBoard.placePiece(0, 0)));

    // out of bounds
    EXPECT_EQ('?', char(myBoard.placePiece(3, 2)));
    EXPECT_EQ('?', char(myBoard.placePiece(-3, 2)));
    EXPECT_EQ('?', char(myBoard.placePiece(2, -1)));
    EXPECT_EQ('?', char(myBoard.placePiece(-1, -1)));
}

TEST(TicTacToeBoardTest, getPieces) {
    TicTacToeBoard myBoard;

    // place pieces
    myBoard.placePiece(0, 0);
    myBoard.placePiece(1, 0);

    // check piece values are consistent with placement
    EXPECT_EQ('X', myBoard.getPiece(0, 0));
    EXPECT_EQ('O', myBoard.getPiece(1, 0));
}

TEST(TicTacToeBoardTest, winnerHoriz) {
    TicTacToeBoard myBoard;

    // X win     
    myBoard.placePiece(0, 0);
    myBoard.placePiece(1, 0); // ignore O
    myBoard.placePiece(0, 1);
    myBoard.placePiece(1, 1); // ignore O
    myBoard.placePiece(0, 2);

    EXPECT_EQ('X', char(myBoard.getWinner()));

    // O win
    myBoard.clearBoard();
    myBoard.placePiece(2, 2);
    myBoard.placePiece(0, 0); // ignore X
    myBoard.placePiece(2, 0);
    myBoard.placePiece(0, 0); // ignore X
    myBoard.placePiece(2, 1);

    EXPECT_EQ('O', char(myBoard.getWinner()));
}

TEST(TicTacToeBoardTest, winnerDiag) {
    TicTacToeBoard myBoard;

    // X win
    myBoard.placePiece(0, 0);
    myBoard.placePiece(1, 0); // ignore O
    myBoard.placePiece(1, 1);
    myBoard.placePiece(1, 2); // ignore O
    myBoard.placePiece(2, 2);

    EXPECT_EQ('X', char(myBoard.getWinner()));

    // O win
    myBoard.clearBoard();
    myBoard.placePiece(0, 2);
    myBoard.placePiece(0, 0); // ignore X
    myBoard.placePiece(1, 1);
    myBoard.placePiece(0, 1); // ignore X
    myBoard.placePiece(2, 0);

    EXPECT_EQ('O', char(myBoard.getWinner()));
}

TEST(TicTacToeBoardTest, winnerVert) {
    TicTacToeBoard myBoard;

    // X win
    myBoard.placePiece(0, 0);
    myBoard.placePiece(1, 1); // ignore O
    myBoard.placePiece(1, 0);
    myBoard.placePiece(2, 1); // ignore O
    myBoard.placePiece(2, 0);

    EXPECT_EQ('X', char(myBoard.getWinner()));

    // O win
    myBoard.clearBoard();
    myBoard.placePiece(2, 2);
    myBoard.placePiece(1, 0); // ignore X
    myBoard.placePiece(0, 2);
    myBoard.placePiece(1, 1); // ignore X
    myBoard.placePiece(1, 2);

    EXPECT_EQ('O', char(myBoard.getWinner()));
}

TEST(TicTacToeBoardTest, noWin) {
    TicTacToeBoard myBoard;

    // ensure no win on empty board
    EXPECT_EQ('?', char(myBoard.getWinner()));

    // place some pieces (with no winner)
    myBoard.placePiece(1, 0);
    myBoard.placePiece(1, 1);
    myBoard.placePiece(1, 2);

    EXPECT_EQ('?', char(myBoard.getWinner()));
}

TEST(TicTacToeBoardTest, catsGame) {
    TicTacToeBoard myBoard;

    // create a full board with no winner
    myBoard.placePiece(0, 0);
    myBoard.placePiece(0, 2);
    myBoard.placePiece(0, 1);
    myBoard.placePiece(1, 0);
    myBoard.placePiece(1, 2);
    myBoard.placePiece(1, 1);
    myBoard.placePiece(2, 0);
    myBoard.placePiece(2, 1);
    myBoard.placePiece(2, 2);

    EXPECT_EQ(' ', char(myBoard.getWinner()));
}
