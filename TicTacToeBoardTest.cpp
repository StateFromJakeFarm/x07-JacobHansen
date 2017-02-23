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

TEST_F(TicTacToeBoardTest, canBuild) {
    TicTacToeBoard myBoard;

    for(int r=0; r<3; r++) {
        for(int c=0; c<3; c++) {
            EXPECT_EQ(' ', myBoard.getPiece(r, c));
        }
    }
}

TEST_F(TicTacToeBoardTest, placePieces) {
    TicTacToeBoard myBoard;

    EXPECT_EQ('X', myBoard.placePiece(0, 0));
    EXPECT_EQ('X', myBoard.placePiece(0, 0));
    EXPECT_EQ('?', myBoard.placePiece(3, 2));
}

TEST_F(TicTacToeBoardTest, toggleTurn) {
    TicTacToeBoard myBoard;

    EXPECT_EQ('X', myBoard.placePiece(0, 0));
    EXPECT_EQ('O', myBoard.placePiece(0, 1));
    EXPECT_EQ('X', myBoard.placePiece(0, 2));
    EXPECT_EQ('O', myBoard.placePiece(1, 0));
}

TEST_F(TicTacToeBoardTest, getPieces) {
    TicTacToeBoard myBoard;

    myBoard.placePiece(0, 0);
    myBoard.placePiece(1, 0);

    EXPECT_EQ('X', myBoard.getPiece(0, 0));
    EXPECT_EQ('O', myBoard.getPiece(1, 0));
}

TEST_F(TicTacToeBoardTest, getWinnerHoriz) {
    TicTacToeBoard myBoard;

    myBoard.placePiece(0, 0);
    myBoard.placePiece(1, 0);
    myBoard.placePiece(0, 1);
    myBoard.placePiece(1, 1);
    myBoard.placePiece(0, 2);

    EXPECT_EQ('X', myBoard.getWinner());
}

TEST_F(TicTacToeBoardTest, getWinnerDiag) {
    TicTacToeBoard myBoard;

    myBoard.placePiece(0, 0);
    myBoard.placePiece(1, 0);
    myBoard.placePiece(1, 1);
    myBoard.placePiece(1, 2);
    myBoard.placePiece(2, 2);

    EXPECT_EQ('X', myBoard.getWinner());
}

TEST_F(TicTacToeBoardTest, getWinnerVert) {
    TicTacToeBoard myBoard;

    myBoard.placePiece(0, 0);
    myBoard.placePiece(1, 1);
    myBoard.placePiece(1, 0);
    myBoard.placePiece(2, 1);
    myBoard.placePiece(2, 0);

    EXPECT_EQ('X', myBoard.getWinner());
}
