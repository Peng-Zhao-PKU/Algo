import java.io.*;
import java.math.BigInteger;
import java.util.*;

public class Main {

    public int ret = 0;
    public HashSet<Integer> diff = new HashSet<Integer>();
    public HashSet<String> type = new HashSet<String>();

    public void bfs(char[][] grid, boolean[][] visit, int x, int y, int m, int n) {
        int[][] dir = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        Queue<Node> q = new LinkedList<Node>();
        q.add(new Node(x, y));
        visit[x][y] = true;
        int cnt = 1;
        StringBuilder code = new StringBuilder();
        code.append(-1);
        while(!q.isEmpty()) {
            Node cur = q.poll();
            x = cur.x;
            y = cur.y;
            code.append(-1);
            for(int i = 0; i < 4; i++) {
                int nx = x + dir[i][0];
                int ny = y + dir[i][1];
                if(nx >= 0 && ny >= 0 && nx < m && ny < n && !visit[nx][ny] && grid[nx][ny] == '#') {
                    visit[nx][ny] = true;
                    q.add(new Node(nx, ny));
                    code.append(i);
                    cnt++;
                }
            }
        }
        diff.add(cnt);
        type.add(code.toString());
    }
    public static void main(String[] args) throws FileNotFoundException {
//        Scanner input = new Scanner(new File("test.txt"));
        Scanner input = new Scanner(System.in);
        int m = input.nextInt(), n = input.nextInt();
        Main solution = new Main();
        char[][] grid = new char[m][n];
        boolean[][] visit = new boolean[m][n];
        for(int i = 0; i < m; i++) {
            String cur = input.next();
            grid[i] = cur.toCharArray();
        }
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == '#' && !visit[i][j]) {
                    solution.ret++;
                    solution.bfs(grid, visit, i, j, m, n);
                }
            }
        }
        System.out.println(solution.ret + " " + solution.diff.size() + " " + solution.type.size());
    }
}
class Node{
    int x, y;
    Node(int x, int y) {
        this.x = x;
        this.y = y;
    }
}