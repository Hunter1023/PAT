﻿import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {

	public static boolean isPrime(int num) {
		
		for (int i = 2; i <= Math.sqrt(num); i++) {
			if(num % i == 0) {
				return false;
			}
		}		
		return true;		
	}
	
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String str[] = br.readLine().split(" ");

		int M = Integer.parseInt(str[0]);
		int N = Integer.parseInt(str[1]);
		br.close();

		int[] arr = new int[N-M+1];
		
		int num = 2;
		int cnt = 0;

		while (cnt < N) {
	        if (isPrime(num)) {
	            cnt++;
	            if (cnt >= M) 
	            	arr[cnt-M] = num;
	        }
	        num++;
	    }

		cnt = 0;
		for (int i = 0; i < arr.length; i++) {
			cnt++;
			if (cnt % 10 != 1) {
				System.out.print(" " + arr[i]);
			} else {
				System.out.print(arr[i]);
			}
			if (cnt % 10 == 0) {
				System.out.println("");
			}
		}
	}
}