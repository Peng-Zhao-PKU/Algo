import java.io.*;
import java.math.BigInteger;
import java.util.*;

public class Main {

    public static boolean dfs(int id, Circle[] circle, boolean[] visit) {
        visit[id] = true;
        for(int i = 0; i < visit.length; i++) {
            if(!visit[i] && cross(circle, i, id)) {
                if(circle[i].down)
                    return false;
                if(!dfs(i, circle, visit))
                    return false;
            }
        }
//        visit[id] = false;
        return true;
    }

    public static boolean cross(Circle[] circle, int i, int j) {
        long dis1 = (circle[i].x - circle[j].x) * (circle[i].x - circle[j].x) + (circle[i].y - circle[j].y) * (circle[i].y - circle[j].y);
        long dis2 = (circle[i].r + circle[j].r) * (circle[i].r + circle[j].r);
        return dis1 <= dis2;
    }

    public static void main(String[] args) throws FileNotFoundException {
//        Scanner input = new Scanner(new File("test.txt"));
        Scanner input = new Scanner(System.in);
        int T = input.nextInt();
        for(int t = 0; t < T; t++) {
            int w = input.nextInt(), h = input.nextInt(), n = input.nextInt();
            Circle[] circle = new Circle[n];
            for(int i = 0; i < n; i++) {
                int x = input.nextInt(), y = input.nextInt(), r = input.nextInt();
                circle[i] = new Circle(i, x, y, r, y + r >= h, y - r <= 0);
            }
            boolean[] visit = new boolean[n];
            boolean can = true;
            for(int i = 0; i < n; i++) {
                if(circle[i].up) {
                    if(circle[i].down) {
                        can = false;
                        break;
                    }
                    boolean found = dfs(i, circle, visit);
                    if(!found) {
                        can = false;
                        break;
                    }
                }
            }
            if(can)
                System.out.println("YES");
            else
                System.out.println("NO");
        }

    }
}
class Circle {
    int id;
    long x, y, r;
    boolean up, down;
    Circle(int id, long x, long y, long r, boolean up, boolean down) {
        this.id = id;
        this.x = x;
        this.y = y;
        this.r = r;
        this.up = up;
        this.down = down;
    }
}