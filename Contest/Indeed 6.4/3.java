import java.io.*;
import java.math.BigInteger;
import java.util.*;
 
public class Main {
    public static int bfs(HashMap<Integer, HashSet<Integer>> edge, int from, int to, int n) {
        Queue<Integer> q = new LinkedList<>();
        boolean[] visit = new boolean[n + 1];
        visit[0] = true;
        q.add(from);
        int dis = 1;
        visit[from] = true;
        while(!q.isEmpty()) {
            for(int k = q.size(); k > 0; k--) {
                int cur = q.poll();
                if(edge.containsKey(cur)) {
                    for(int tmp: edge.get(cur)) {
                        if(tmp == to)
                            return dis;
                        else if(!visit[tmp]){
                            visit[tmp] = true;
                            q.add(tmp);
                        }
                    }
                }
            }
            dis++;
        }
        return -1;
    }
    public static void main(String[] args) throws FileNotFoundException {
//        Scanner input = new Scanner(new File("test.txt"));
        Scanner input = new Scanner(System.in);
       int v = input.nextInt(), q = input.nextInt();
        HashMap<Integer, HashSet<Integer>> edge = new HashMap<Integer,  HashSet<Integer>>();
        for(int i = 1; i < v; i++) {
            edge.putIfAbsent(i, new  HashSet<>());
            edge.get(i).add(i + 1);
        }
        for(int i = 0; i < q; i++) {
            int from = input.nextInt(), to = input.nextInt();
            int dis = bfs(edge, from, to, v);
            System.out.println(dis);
            edge.putIfAbsent(from, new HashSet<>());
            edge.get(from).add(to);
        }
    }
}