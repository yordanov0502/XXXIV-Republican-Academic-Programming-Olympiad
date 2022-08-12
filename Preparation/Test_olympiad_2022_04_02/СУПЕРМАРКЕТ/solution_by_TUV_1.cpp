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
    
    public static long solve(long[] prices, int k) {
        Arrays.sort(prices);

        long currentPrice = 0;
        for(int i = prices.length - 1; i >= 0; i--) {
            if((prices.length - i) % k == 0) {
                continue;
            }

            currentPrice += prices[i];
        }

        return currentPrice;
    }

    public static void main(String[] args) {
        FastReader reader = new FastReader();
        int T = reader.nextInt();
        StringBuilder result = new StringBuilder();
        int N, K;

        for(int t = 0; t < T; t++) {
            N = reader.nextInt();
            K = reader.nextInt();

            long[] prices = new long[N];
            for(int i = 0; i < N; i++) {
                prices[i] = reader.nextLong();
            }

            result.append(solve(prices, K)).append("\n");
        }

        System.out.println(result);
        reader.close();

    }

}