import java.util.Scanner;

public class Main {
	private static Scanner in;
	private String[] arr;
	private String sentence = "";
	
	public Main(String sentence) {
		arr = sentence.split(" ");
	}
	
	public void output() {
		for(int i = arr.length -1; i >= 0; i--) {
			sentence += arr[i]+" ";
		}
		System.out.println(sentence.trim());
	}
	
	public static void main(String[] args) {
		in = new Scanner(System.in);
		Main invertedSentence = new Main(in.nextLine());
		invertedSentence.output();
	}
}
