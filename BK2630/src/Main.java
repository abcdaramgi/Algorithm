import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main{

    static int[][] RC;

    static int N;
    static int t;
    static int white = 0;
    static int blue = 0;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        N = Integer.parseInt(br.readLine());

        RC = new int[N][N];

        StringTokenizer st;

        for(int i = 0; i < N; i++){
            st = new StringTokenizer(br.readLine(), " ");
            for(int j = 0; j < N; j++){
                RC[i][j] = Integer.parseInt(st.nextToken());
//                System.out.print(RC[i][j] + "[" + i + "][" + j + "]");
            }
//            System.out.println(" "+ i);

        }
        cutting(0,0, N);
        System.out.println(white);
        System.out.println(blue);
    }

    public static void cutting(int x, int y, int n){
        int sum = 0;
        for(int i = x; i < n + x; i++){
            for(int j = y; j < n + y; j++){
                sum += RC[i][j];
            }
        }

        if(sum == n*n){
//            System.out.println("all blue");
            blue++;
        } else if(sum == 0){
//            System.out.println("all white");
            white++;
        } else {
            cutting(x, y, n/2);
            cutting(x, y + n/2, n/2);
            cutting(x + n/2, y, n/2);
            cutting(x + n/2, y + n/2, n/2);
        }
    }
}