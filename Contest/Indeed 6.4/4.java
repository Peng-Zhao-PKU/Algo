import java.io.*;
import java.math.BigInteger;
import java.util.*;

public class Main {

    public static int sumRegion(int row1, int col1, int row2, int col2, int[][] sum) {
        int ret = sum[row2 + 1][col2 + 1] - sum[row1][col2 + 1] - sum[row2 + 1][col1] + sum[row1][col1];
        return ret;
    }

    public static void main(String[] args) throws FileNotFoundException {
//        Scanner input = new Scanner(new File("test.txt"));
        Scanner input = new Scanner(System.in);
        int h = input.nextInt(), w = input.nextInt();
        int[][] weight = new int[h][w];
        for(int i = 0; i < h; i++) {
            String cur = input.next();
            for(int j = 0; j < w; j++) {
                weight[i][j] = cur.charAt(j) - '0';
            }
        }
//        for(int i = 0; i < h; i++) {
//            for(int j = 0; j < w; j++)
//                System.out.print(weight[i][j]);
//            System.out.println();
//        }
        int[][] sum = new int[h + 1][w + 1];
        for(int i = 1; i <= h; i++)
        {
            for(int j = 1; j <= w; j++)
            {
                sum[i][j] = weight[i - 1][j - 1] + sum[i][j - 1] + sum[i - 1][j] - sum[i - 1][j - 1];
            }
        }
        long[][][][] dp = new long[Math.max(h, w)][Math.max(h, w)][Math.max(h, w)][Math.max(h, w)];
        for(int lenh = 1; lenh <= h; lenh++) {
            for(int i = 0; i + lenh - 1 < h; i++) {
                int p = i + lenh - 1;
                for(int lenw = 1; lenw <= w; lenw++) {
                    for(int j = 0; j + lenw - 1 < w; j++) {
                        int q = j + lenw - 1;
                        if(i == p && j == q)
                            continue;
                        long ret = Long.MAX_VALUE;
                        for(int k = i; k < p; k++) {
                            ret = Math.min(ret, dp[i][j][k][q] + dp[k + 1][j][p][q]);
                        }
                        for(int k = j; k < q; k++) {
                            ret = Math.min(ret, dp[i][j][p][k] + dp[i][k + 1][p][q]);
                        }
                        dp[i][j][p][q] = ret + sumRegion(i, j, p, q, sum);
                    }
                }
            }
        }
        System.out.println(dp[0][0][h - 1][w - 1]);
    }
}