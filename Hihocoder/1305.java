import java.io.*;
import java.math.BigInteger;
import java.util.*;

public class Main {

    public static ArrayList<Interval> merge(Interval[] interval) {
        ArrayList<Interval> ret = new ArrayList<Interval>();
        int n = interval.length;
        int start = interval[0].start, end = interval[0].end;
        for(int i = 1; i < n; i++) {
            if(interval[i].start > end) {
                ret.add(new Interval(start, end));
                start = interval[i].start;
                end = interval[i].end;
            }
            else {
                end = Math.max(interval[i].end, end);
            }
        }
        ret.add(new Interval(start, end));
        return ret;
    }

    public static void main(String[] args) throws FileNotFoundException {
//        Scanner input = new Scanner(new File("test.txt"));
        Scanner input = new Scanner(System.in);
        int n = input.nextInt(), m = input.nextInt();
        Interval[] original = new Interval[n];
        Interval[] delete = new Interval[m];
        for(int i = 0; i < n; i++)
            original[i] = new Interval(input.nextInt(), input.nextInt());
        for(int i = 0; i < m; i++)
            delete[i] = new Interval(input.nextInt(), input.nextInt());
        Comparator<Interval> compare = new Comparator<Interval>(){
            public int compare(Interval i1, Interval i2) {
                if(i1.start == i2.start)
                    return i1.end - i2.end;
                else
                    return i1.start - i2.start;
            }
        };
        Arrays.sort(original, compare);
        Arrays.sort(delete, compare);

        ArrayList<Interval> inter1 = merge(original);
        ArrayList<Interval> inter2 = merge(delete);

        n = inter1.size();
        m = inter2.size();
        int i = 0, j = 0;
        int total = 0, minus = 0;
        while(i < n && j < m) {
            if(inter1.get(i).start >= inter2.get(j).end) {
                j++;
            }
            else if(inter1.get(i).end <= inter2.get(j).start) {
                total += inter1.get(i).end - inter1.get(i).start;
                i++;
            }
            else {
                minus += Math.min(inter1.get(i).end,  inter2.get(j).end) - Math.max(inter1.get(i).start, inter2.get(j).start);
                if(inter1.get(i).end < inter2.get(j).end) {
                    total += inter1.get(i).end - inter1.get(i).start;
                    i++;
                }
                else {
                    j++;
                }
            }
        }
        while(i < n) {
            total += inter1.get(i).end - inter1.get(i).start;
            i++;
        }

        System.out.println(total - minus);

    }
}
class Interval{
    int start, end;
    Interval(int start, int end) {
        this.start = start;
        this.end = end;
    }
}