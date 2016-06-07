import java.io.*;
import java.math.BigInteger;
import java.util.*;

public class Main {

    public static void main(String[] args) throws FileNotFoundException {
//        Scanner input = new Scanner(new File("test.txt"));
        Scanner input = new Scanner(System.in);
        int n = input.nextInt();
        Interval[] interval = new Interval[n];
        for(int i = 0; i < n; i++) {
            interval[i] = new Interval(input.nextInt(), input.nextInt());
        }
        Arrays.sort(interval, new Comparator<Interval>(){
            public int compare(Interval i1, Interval i2) {
                if(i1.start == i2.start)
                    return i1.end - i2.end;
                else
                    return i1.start - i2.start;
            }
        });
        PriorityQueue<Integer> end = new PriorityQueue<Integer>();
        int ret = 0;
        for(int i = 0; i < n; i++) {
            Interval cur = interval[i];
            if(i == 0) {
                ret++;
                end.add(cur.end);
            }
            else {
                if(cur.start >= end.peek()) {
                    end.poll();
                }
                else
                    ret++;
                end.add(cur.end);
            }
        }
        System.out.println(ret);
    }
}
class Interval {
    int start, end;
    Interval(int start, int end) {
        this.start = start;
        this.end = end;
    }
}