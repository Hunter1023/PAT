import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		
		Scanner in = new Scanner(System.in);
		int num = in.nextInt();
		int cnt = 0;
		
		while(num != 1)
		{
			if(num % 2 == 0)
			{
				num /= 2;
			}
			else
			{
				num = (3*num + 1) / 2;
			}
			cnt++;
		}
		System.out.println(cnt);
	}
}
