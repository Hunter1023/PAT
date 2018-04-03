import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
	    int M=in.nextInt();
	    int N=in.nextInt();
	    in.close();
		int[] arr = new int[N];
		arr[0] = 2;
		int numOfPrime = 1;
		
		exciting:
		for(int i = 3; numOfPrime < N; i += 2) {
			for(int j = 0; j < numOfPrime; j++) {
				if(i % arr[j] == 0) {
					continue exciting;
				}
			}
			arr[numOfPrime++] = i;
		}
		
		int numOfLine = 0;
		for(int i = M -1; i < N; i++) {
			if(i == N-1) {
				System.out.println(arr[i]);
			}else if(numOfLine !=9) {
				System.out.print(arr[i]+" ");
				numOfLine++;
			}else {
				System.out.println(arr[i]);
				numOfLine = 0;
			}
		}
	}
}
