import java.util.Scanner;

public class Main {
	
	public static void main(String[] args) {
		
		Scanner in = new Scanner(System.in);
	    int M=in.nextInt();
	    int N=in.nextInt();
	    in.close();
		
	    //创建能存放N个素数的数组，并对素数计数
		int[] arr = new int[N];
		arr[0] = 2;
		int numOfPrime = 1;
		
		exciting:
		for(int i = 3; numOfPrime < N; i += 2) {
			for(int j = 0; j < numOfPrime; j++) {//如果一个数不能被比自己小的素数整除，那么这个数就是素数
				if(i % arr[j] == 0) {
					continue exciting;
				}
			}
			arr[numOfPrime++] = i;
		}
		
		
		int numOfLine = 0;
		for(int i = M -1; i < N; i++) {
			if(numOfLine !=9) {//如果一行还没有满9个数字，就输出数字+空格
				System.out.print(arr[i]+" ");
				numOfLine++;
			}else {//如果一行已经满了9个数字，就输出数字并换行
				System.out.println(arr[i]);
				numOfLine = 0;
			}
		}
	}
}
