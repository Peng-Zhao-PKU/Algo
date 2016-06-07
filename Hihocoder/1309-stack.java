import java.io.*;
import java.math.BigInteger;
import java.util.*;

public class Main {

    public static void main(String[] args) throws FileNotFoundException {
//        Scanner input = new Scanner(new File("test.txt"));
        Scanner input = new Scanner(System.in);
        int n = input.nextInt();
        Interval[] interval = new Interval[n * 2];
        for(int i = 0; i < 2 * n; i += 2) {
            interval[i] = new Interval(input.nextInt(), true);
            interval[i + 1] = new Interval(input.nextInt(), false);
        }
        Arrays.sort(interval, new Comparator<Interval>(){
            public int compare(Interval i1, Interval i2) {
                if(i1.time == i2.time)
                    return i1.start != true ? -1 : 1;
                else
                    return i1.time - i2.time;
            }
        });
       Stack<Integer> s = new Stack<Integer>();
        int ret = 0;
        for(int i = 0; i < 2 * n; i++) {
           if(interval[i].start) {
               s.push(i);
               ret = Math.max(ret, s.size());
           }
           else
               s.pop();
        }
        System.out.println(ret);
    }
}
class Interval {
    int time;
    boolean start;
    Interval(int time, boolean start) {
        this.start = start;
        this.time = time;
    }
}