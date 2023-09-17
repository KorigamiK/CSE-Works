import java.util.Arrays;
import java.util.Scanner;

public class TicTacToe {
  private static char[][] board = new char[3][3];
  private static char currentPlayer = 'X';
  static Scanner scanner = new Scanner(System.in);

  public static void main(String[] args) {
    initializeBoard();
    boolean gameIsRunning = true;

    while (gameIsRunning) {
      printBoard();
      int[] move = getPlayerMove();

      if (isValidMove(move)) {
        board[move[0]][move[1]] = currentPlayer;
        if (checkWin()) {
          printBoard();
          System.out.println("Player " + currentPlayer + " wins!");
          gameIsRunning = false;
        } else if (isBoardFull()) {
          printBoard();
          System.out.println("It's a draw!");
          gameIsRunning = false;
        } else {
          currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
        }
      } else {
        System.out.println("Invalid move. Try again.");
      }
    }
  }

  private static void initializeBoard() {
    for (char[] row : board)
      Arrays.fill(row, ' ');
  }

  private static void printBoard() {
    System.out.println("-------------");
    for (char[] row : board) {
      System.out.println("| " + row[0] + " | " + row[1] + " | " + row[2] + " |");
      System.out.println("-------------");
    }
  }

  private static int[] getPlayerMove() {
    System.out.print("Player " + currentPlayer + ", enter your move (row and column): ");
    return new int[] { scanner.nextInt(), scanner.nextInt() };
  }

  private static boolean isValidMove(int[] move) {
    int row = move[0];
    int col = move[1];
    return row >= 0 && row < 3 && col >= 0 && col < 3 && board[row][col] == ' ';
  }

  private static boolean checkWin() {
    for (int i = 0; i < 3; i++) {
      if (board[i][0] == currentPlayer && board[i][1] == currentPlayer &&
          board[i][2] == currentPlayer ||
          board[0][i] == currentPlayer && board[1][i] == currentPlayer &&
              board[2][i] == currentPlayer) {
        return true;
      }
    }
    return board[0][0] == currentPlayer && board[1][1] == currentPlayer &&
        board[2][2] == currentPlayer ||
        board[0][2] == currentPlayer && board[1][1] == currentPlayer &&
            board[2][0] == currentPlayer;
  }

  private static boolean isBoardFull() {
    for (char[] row : board) {
      for (char cell : row)
        if (cell == ' ')
          return false;
    }
    return true;
  }
}
