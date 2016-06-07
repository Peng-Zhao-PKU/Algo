import java.io.*;
import java.math.BigInteger;
import java.util.*;

public class Main {
    public static void main(String[] args) throws FileNotFoundException {
        Scanner input = new Scanner(new File("test.txt"));
//        Scanner input = new Scanner(System.in);
        String s = input.next();
        long m = input.nextLong();
        StringBuilder sb = new StringBuilder(s);
        HashMap<String, Long> map = new HashMap<String, Long>();
        HashMap<Long, String> index = new HashMap<Long, String>();
        long end = -1;
        for (long i = 0; i < m; i++) {
            char c = sb.charAt(0);
            sb.insert(c - '0', c);
            sb.deleteCharAt(0);
            if(map.containsKey(sb.toString())) {
                end = i + 1;
                break;
            }
            map.put(sb.toString(), i + 1);
            index.put(i + 1, sb.toString());
        }
        System.out.println(end);
        if(end == -1)
            System.out.println(sb.toString());
        else {
            long id = map.get(sb.toString());
            long period = end - id;
            m -= id;
            long cur = m % period;
            System.out.println(index.get(id + cur));
        }
    }
}