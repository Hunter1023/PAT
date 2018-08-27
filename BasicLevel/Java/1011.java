import java.util.Scanner;

public class Main {
	private static Scanner in;
	private int numOfCase;
	private long A,B,C;
	private String titleOfResult = "Case #";
	private String colon = ":";
	private boolean[] isCLess;
	public Main(int numOfCase) {
		this.numOfCase = numOfCase;
		isCLess = new boolean[this.numOfCase+1];
	}
	
	public void judgeSize() {
		for(int i = 1; i <= numOfCase; i++) {
				A = in.nextInt();
				B = in.nextInt();
				C = in.nextInt();
				if((A+B) > C) {
					isCLess[i] = true;
				}else {
					isCLess[i] = false;
				}
		}
	}
	
	public void output() {
		for(int i = 1; i <= numOfCase; i++) {
			System.out.println(titleOfResult+i+colon+" "+isCLess[i]);
		}
	}
	
	public static void main(String[] args) {
		in = new Scanner(System.in);
		Main compare = new Main(in.nextInt());
		compare.judgeSize();
		compare.output();
	}
}