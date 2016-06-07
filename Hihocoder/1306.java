import java.io.*;
import java.math.BigInteger;
import java.util.*;

public class Main {
    public static void modifyMax(int[] maxv, int root, int left, int right, int val, int id) {
        if(left > right)
            return ;
        if(left == id && right == id) {
            maxv[root] = val;
            return ;
        }
        int mid = left + (right - left) / 2;
        if(id <= mid)
            modifyMax(maxv, root * 2 + 1, left, mid, val, id);
        else
            modifyMax(maxv, root * 2 + 2, mid + 1, right, val, id);
        maxv[root] = Math.max(maxv[root * 2 + 1], maxv[root * 2 + 2]);
    }
    public static void modifyMin(int[] minv, int root, int left, int right, int val, int id) {
        if(left > right)
            return ;
        if(left == id && right == id) {
            minv[root] = val;
            return ;
        }
        int mid = left + (right - left) / 2;
        if(id <= mid)
            modifyMin(minv, root * 2 + 1, left, mid, val, id);
        else
            modifyMin(minv, root * 2 + 2, mid + 1, right, val, id);
        minv[root] = Math.min(minv[root * 2 + 1], minv[root * 2 + 2]);
    }
    public static int queryMax(int[] maxv, int root, int start, int end, int left, int right) {
        if(left >= start && right <= end)
            return maxv[root];
        int mid = left + (right - left) / 2;
        if(end <= mid)
            return queryMax(maxv, root * 2 + 1, start, end, left, mid);
        else if(mid < start)
            return queryMax(maxv, root * 2 + 2, start, end, mid + 1, right);
        else
            return Math.max(queryMax(maxv, root * 2 + 1, start, mid, left, mid), queryMax(maxv, root * 2 + 2, mid + 1, end, mid + 1, right));
    }
    public static int queryMin(int[] minv, int root, int start, int end, int left, int right) {
        if(left >= start && right <= end)
            return minv[root];
        int mid = left + (right - left) / 2;
        if(end <= mid)
            return queryMin(minv, root * 2 + 1, start, end, left, mid);
        else if(mid < start)
            return queryMin(minv, root * 2 + 2, start, end, mid + 1, right);
        else
            return Math.min(queryMin(minv, root * 2 + 1, start, mid, left, mid), queryMin(minv, root * 2 + 2, mid + 1, end, mid + 1, right));
    }

    public static void main(String[] args) throws FileNotFoundException {
//       Scanner input = new Scanner(new File("test.txt"));
        Scanner input = new Scanner(System.in);
        int n = input.nextInt();
        String P = "P", R = "R", Q = "Q";
        int start = 0, end = 0;
        int total = 10000000, N = 500000;
        int[] max = new int[N * 4 + 10], min = new int[N * 4 + 10];
        int[] time = new int[N], price = new int[N];
        for(int i = 0; i < n; i++) {
            String op = input.next();
            if(op.equals(P)) {
                time[end] = input.nextInt();
                price[end] = input.nextInt();
                modifyMax(max, 0, 0, N - 1, price[end], end);
                modifyMin(min, 0, 0, N - 1, price[end], end);
                end++;
            }
            else if(op.equals(R)) {
                int id = input.nextInt();
                while(time[start] <= id)
                    start++;
            }
            else {
                int qmax = queryMax(max, 0, start, end - 1, 0, N - 1);
                int qmin = queryMin(min, 0, start, end - 1, 0, N - 1);
                System.out.println(qmax + " " + qmin + " " + price[end - 1]);
            }
        }
    }
}
