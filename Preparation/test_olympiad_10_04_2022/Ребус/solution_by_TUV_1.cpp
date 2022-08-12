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

    public char nextChar() {
        while(st == null || !st.hasMoreElements()) {
            try {
                st = new StringTokenizer(String.valueOf((char) br.read()));
            } catch(IOException e) {
                e.printStackTrace();
            }
        }
        return st.nextToken().charAt(0);
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

    private static class Square {
        public int x;
        public int y;

        public Square(int x, int y) {
            this.x = x;
            this.y = y;
        }
    }

    // '' -> white
    // '#' -> black
    public static String solve(
            char[][] matrix,
            Map<Integer, String> words,
            int startSquareNumber) {

        Map<Integer, Square> numberedWhiteSquares = new HashMap<>();
        int currNumber = 1;

        for(int row = 0; row < matrix.length; row++) {
            for(int col = 0; col < matrix[0].length; col++) {
                
                if(row == 0 || col == 0) {
                    if(isWhite(matrix[row][col])) {
                        numberedWhiteSquares.put(currNumber++ ,new Square(row, col));
                    }
                    continue;
                }
                
                if(isWhite(matrix[row][col])
                        && (isBlack(matrix[row - 1][col])
                        || isBlack(matrix[row][col - 1]))) {
                    numberedWhiteSquares.put(currNumber++, new Square(row, col));
                }
            }
        }

        for(Map.Entry<Integer, String> entry : words.entrySet()) {
            char[] chars = entry.getValue().toCharArray();
            Square square = numberedWhiteSquares.get(entry.getKey());

            int row = square.x;
            int currCol = square.y;
            for(char c : chars) {
                matrix[row][currCol++] = c;
            }
        }

        Square startSquare = numberedWhiteSquares.get(startSquareNumber);
        StringBuilder wordBuilder = new StringBuilder();

        int currRow = startSquare.x;
        int col = startSquare.y;

        while(currRow < matrix.length && !isBlack(matrix[currRow][col])) {
            char c = matrix[currRow][col];
            wordBuilder.append(isWhite(c) ? '*' : c);
            currRow++;
        }

        return wordBuilder.toString();
    }

    // '' -> white
    private static boolean isWhite(char c) {
        return c == 0;
    }

    // '#' -> black
    private static boolean isBlack(char c) {
        return c == '#';
    }

    public static void main(String[] args) {
        FastReader fr = new FastReader();
        StringBuilder res = new StringBuilder();
        int n, m;
        int row, col;


        while(true) {
            try {
                n = fr.nextInt();
                m = fr.nextInt();

            } catch (Exception e) {
                break;
            }

            char[][] matrix = new char[n][m];
            Map<Integer, String> words = new HashMap<>();

            while(true) {
                row = fr.nextInt();
                col = fr.nextInt();

                if(row == -1 && col == -1) break;

                matrix[row - 1][col - 1] = '#';
            }

            while(true) {
                String word = fr.nextLine();
                if(word.equals("0")) break;

                int lastDigitIndex = 0;
                for(int i = 0; i < word.length(); i++) {
                    if(!Character.isDigit(word.charAt(i))) {
                        break;
                    }

                    lastDigitIndex++;
                }

                words.put(Integer.parseInt(word.substring(0, lastDigitIndex)),
                        word.substring(lastDigitIndex));
            }

            res.append(solve(matrix, words, fr.nextInt())).append("\n");
        }

        System.out.println(res.toString());
        fr.close();

    }
}
