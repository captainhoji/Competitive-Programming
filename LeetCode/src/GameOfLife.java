
public class GameOfLife {
	public static void main(String[] args) {
		GameOfLife game = new GameOfLife();
		int[][] board = {{0, 1, 0}, {0, 0, 1}, {1, 1, 1}, {0, 0, 0}};
		game.gameOfLife(board);
		for (int i = 0; i < board.length; i++) {
			for (int j = 0; j < board[0].length; j++) {
				System.out.print(board[i][j] + " ");
			}
			System.out.println("");
		}
		
	}
	public void gameOfLife(int[][] board) {
        int rows = board.length;
        int cols = board[0].length;
        
        int[][] ans = new int[rows+2][cols+2];
        for (int i = 0; i < rows+2; i++) {
        	ans[i][0] = 0;
        	ans[i][cols+1] = 0;
        }
        for (int i = 0; i < cols+2; i++) {
        	ans[0][i] = 0;
        	ans[rows+1][i] = 0;
        }
        for (int i = 1; i < rows + 1; i++) {
        	for (int j = 1; j < cols+1; j++) {
        		ans[i][j] = board[i-1][j-1];
        	}
        }
        
        for (int i = 1; i < rows+1; i++) {
        	for (int j = 1; j < cols+1; j++) {
        		int count = 0;
        		for (int k = i-1; k <= i+1; k++) {
        			for (int l = j-1; l <=j+1; j++) {
        				if ((k!=i || l!=j) && ans[k][l] == 1) {
        					count++;
        				}
        			}
        		}
        		if (ans[i][j] == 1) {
        			if (count < 2) board[i-1][j-1] = 0;
        			else if (count > 3) board[i-1][j-1] = 0;
        		}
        		else if (count == 3) {
        			board[i-1][j-1] = 1;
        		}
        	}
        }
    }
}
