import java.util.Scanner;

public class Main {
	private static Scanner in;
	private String[] poly;
	private int[] arr;
	private String derivative = "";
	
	public void setPolynomial(String poly) {
		this.poly = poly.split("\\s+");
		arr = new int[this.poly.length];
		for(int i = 0; i < arr.length; i++) {
			arr[i] = Integer.parseInt(this.poly[i]);
		}
	}
	
	public void getDerivative() {
		if(arr[1] == 0) {
			derivative = "0 0";
		}else {
			for(int i = 0; i < arr.length; i += 2) {
				if(arr[i+1] != 0) {
				derivative += arr[i]*arr[i+1]+" "+(arr[i+1]-1)+" ";
				}
			}
		}
	}
	
	public void output() {
		System.out.println(derivative.trim());
	}
	
	public static void main(String[] args) {
		in = new Scanner(System.in);
		Main pD = new Main();
		pD.setPolynomial(in.nextLine());
		pD.getDerivative();
		pD.output();
	}
}