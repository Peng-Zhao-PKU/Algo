import java.io.*;
import java.math.BigInteger;
import java.util.*;
 
public class Main {
    public static void dfs(char[] nums, boolean[] used, StringBuilder cur, TreeSet<String> ret)
    {
        int n = nums.length;
        if(cur.length() == n)
        {
            ret.add(cur.toString());
            return ;
        }
        for(int i = 0; i < n; i++)
        {
            if(used[i] || (i != 0 && used[i - 1] && nums[i] == nums[i - 1]))
                continue;
            cur.append(nums[i]);
            used[i] = true;
            dfs(nums, used, cur, ret);
            used[i] = false;
            cur.deleteCharAt(cur.length() - 1);
        }
    }
 
    public static void main(String[] args) throws FileNotFoundException {
//        Scanner input = new Scanner(new File("test.txt"));
        Scanner input = new Scanner(System.in);
        String s = input.next();
        char[] dict = {'a', 'b', 'c', 'd'};
        char[] chars = s.toCharArray();
        int n = s.length();
        TreeSet<String> ret = new TreeSet<String>();
        if(n  < 3) {
            for(int i = 0; i < n; i++) {
                chars = s.toCharArray();
                for(int j = 0; j < 4; j++) {
                    chars[i] = dict[j];
                    StringBuilder tmp = new StringBuilder(String.valueOf(chars));
                    ret.add(String.valueOf(chars));
                    ret.add(tmp.reverse().toString());
                }
            }
        }
        else {
            for(int i = 0; i < n; i++) {
                chars = s.toCharArray();
                for(int j = 0; j < 4; j++) {
                    chars[i] = dict[j];
                    boolean[] used = new boolean[n];
                    dfs(chars, used, new StringBuilder(), ret);
                }
            }
        }
 
        for(String cur: ret) {
            System.out.println(cur);
        }
    }
}