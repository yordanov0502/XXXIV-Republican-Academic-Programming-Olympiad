import java.io.*;
import java.util.*;

public class Solution {
    
    public static class FastReader {

    BufferedReader br;
    StringTokenizer st;

    public FastReader() {
        br = new BufferedReader(new InputStreamReader(System.in));
    }

    public String next() {
        while(st == null || !st.hasMoreElements()) {
            try {
                st = new StringTokenizer(br.readLine());
            } catch(IOException e) {
                e.printStackTrace();
            }
        }

        return st.nextToken();
    }

    public String nextChar() {
        while(st == null || !st.hasMoreElements()) {
            try {
                st = new StringTokenizer(String.valueOf((char) br.read()));
            } catch(IOException e) {
                e.printStackTrace();
            }
        }
        return st.nextToken();
    }

    public int nextInt() {
        return Integer.parseInt(next());
    }

    public long nextLong() {
        return Long.parseLong(next());
    }

    public double nextDouble() {
        return Double.parseDouble(next());
    }

    public String nextLine() {
        String str = "";
        try {
            str = br.readLine();
        } catch (IOException e) {
            e.printStackTrace();
        }
        return str;
    }

    public void close() {
        try {
            br.close();

        } catch(IOException e) {

           e.printStackTrace();
        }
    }
}


    private static class Point {
        public int row;
        public int col;

        public Point(int x, int y) {
            this.row = x;
            this.col = y;
        }
    }

    public static boolean canFit(char[][] key, char[][] lock) {

        int n = lock.length;
        List<Point> list = new LinkedList<>();

        boolean canFit = true;
        int lockSize = 0;
        for(int row = 0; row < n; row++) {
            for(int col = 0; col < n; col++) {

                if(key[row][col] == '1') {
                    list.add(new Point(row, col));

                    if(lock[row][col] != '1') {
                        canFit = false;
                    }
                }  
                if(lock[row][col] == '1') {
                    canFit = false;
                    lockSize++;
                }
            }
        }
        
        if(lockSize != list.size()) {
            return false;
        }

        if(canFit) {
            return true;
        }

        for(int i = 0; i < 3; i++) {

            canFit = true;
            for(Point p : list) {

                int rowSpinned = p.col;
                int colSpinned = n - p.row - 1;
                p.row = rowSpinned;
                p.col = colSpinned;

                if(lock[rowSpinned][colSpinned] != '1') {
                    canFit = false;
                }
            }
            if(canFit) {
                return true;
            }
        }

        return false;
    }

    public static void main(String[] args) {
        FastReader reader = new FastReader();
        StringBuilder result = new StringBuilder();
        int T = reader.nextInt();
        int N;

        for(int t = 0; t < T; t++) {
            N = Integer.parseInt(reader.nextLine());

            char[][] key = new char[N][N];
            char[][] lock = new char[N][N];

            String line;
            for(int row = 0; row < N; row++) {
                line = reader.nextLine();
                key[row] = line.toCharArray();
            }

            for(int row = 0; row < N; row++) {
                line = reader.nextLine();
                lock[row] = line.toCharArray();
            }

            result.append(canFit(key, lock) ? "YES" : "NO").append("\n");
        }

        System.out.println(result);
        reader.close();
    }
}