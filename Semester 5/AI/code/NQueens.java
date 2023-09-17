public class NQueens {
    private int[] queens;
    private int n;

    public NQueens(int n) {
        this.n = n;
        queens = new int[n];
    }

    public void solve() {
        placeQueens(0);
    }

    private void placeQueens(int row) {
        if (row == n) {
            printQueens();
            return;
        }

        for (int col = 0; col < n; col++) {
            if (isSafe(row, col)) {
                queens[row] = col;
                placeQueens(row + 1);
            }
        }
    }

    private boolean isSafe(int row, int col) {
        for (int i = 0; i < row; i++) {
            if (queens[i] == col || queens[i] - i == col - row || queens[i] + i == col + row) {
                return false;
            }
        }
        return true;
    }

    private void printQueens() {
        for (int row = 0; row < n; row++) {
            for (int col = 0; col < n; col++)
                if (queens[row] == col)
                    System.out.print("Q ");
                else
                    System.out.print(". ");
            System.out.println();
        }
        System.out.println();
    }

    public static void main(String[] args) {
        int n = 8; // Change the value of n to the desired board size
        NQueens nQueens = new NQueens(n);
        nQueens.solve();
    }
}
