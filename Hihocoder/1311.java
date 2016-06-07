import java.io.*;
import java.math.BigInteger;
import java.util.*;

public class Main {

    public static void main(String[] args) throws FileNotFoundException {
//        Scanner input = new Scanner(new File("test.txt"));
        Scanner input = new Scanner(System.in);
        int n = input.nextInt();
        for(int i = 0; i < n; i++) {
            StringBuilder cur = new StringBuilder(input.next());
            if(cur.charAt(cur.length() - 1) != '0' && cur.charAt(cur.length() - 1) != '5') {
                System.out.println("NO");
                continue;
            }
            //delete the dot
            cur.deleteCharAt(1);
            StringBuilder ret = new StringBuilder("0.");
            boolean limit = true;
            int last = 0, len = cur.length(), tail = -1;//the last none zero from begin and tail
            char[] nums = cur.toString().toCharArray();
            while(last != len) {
                int id = len - 1, carry = 0;
                last = len;
                tail = -1;
                while(id >= 0) {
                    int tmp = (nums[id] - '0') * 2 + carry;
                    carry = tmp / 10;
                    char val = (char)((tmp % 10) + '0');
                    nums[id] = val;
                    if(nums[id] != '0')
                        last = id;
                    if(tail == -1 && nums[id] != '0') {
                        if(nums[id] == '5' || id == 0)
                            tail = id;
                        else {
                            limit = false;
                            break;
                        }
                    }
                    id--;
                }
                if(!limit)
                    break;
//                System.out.println(cur.toString());
                if(last == len) {
                    break;
                }
                if(nums[0] == '0')
                    ret.append(0);
                else {
                    ret.append(1);
                    nums[0] = '0';
                }
            }
            if(limit)
                System.out.println(ret.toString());
            else
                System.out.println("NO");
        }

    }
}