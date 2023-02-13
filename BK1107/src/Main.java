import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    static String N;
    static int[] R = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    static int[] digits;
    static int result = 999999;

    // 목표 숫자에 가장 가까운 숫자를 조합해서
    // 그런 다음 +, - 를 이용해 답을 구하는 문제
    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        N = br.readLine();

//        digits = new int[N.length()];
//
//        for(int i = 0; i < N.length(); i++){
//            digits[i] = N.charAt(i) - '0';
//        }

        int M = Integer.parseInt(br.readLine());

        if(M != 0){
            // 입력받으면서 찢어주는거
            StringTokenizer st = new StringTokenizer(br.readLine(), " ");

            for(int i = 0; i < M; i++){
                // 찢으면서 넣어주는거
                int x = Integer.parseInt(st.nextToken());
                R[x] = -1;
            }
        }
        result = Math.min(result, Math.abs(100 - Integer.parseInt(N)));

        nahoon_a_change("");
        System.out.println(result);

    }

    public static void nahoon_a_change(String target){
        for (int j : R) {
            if (j != -1) {
                String current = target + j;
                result = Math.min(result, Math.abs(Integer.parseInt(N) - Integer.parseInt(current)) + current.length());

                if (current.length() < 6) {
                    nahoon_a_change(current);
                }
            }

        }
    }
}