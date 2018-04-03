import java.util.HashMap;
import java.util.Scanner;

public class Main {	
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		String line1 = in.nextLine();
		String line2 = in.nextLine();
		String line3 = in.nextLine();
		String line4 = in.nextLine();
		in.close();
		
		HashMap<Character, String> week = new HashMap<Character, String>();
		week.put('A', "MON");
		week.put('B', "TUE");
		week.put('C', "WED");
		week.put('D', "THU");
		week.put('E', "FRI");
		week.put('F', "SAT");
		week.put('G', "SUN");
		
		String time = "";
		boolean isJudgeDay = true;
		boolean isJudgeHour = false;
		for (int i = 0; i < line1.length() && i < line2.length(); i++) {
			if(line1.charAt(i) == line2.charAt(i)) {
				if(isJudgeDay && line1.charAt(i) >= 'A' && line1.charAt(i) <= 'G') {
					time += week.get(line1.charAt(i))+" ";
					isJudgeDay = false;
					isJudgeHour = true;
				}else if( ( line1.charAt(i) >= 'A' && line1.charAt(i) <= 'N' ) 
						|| Character.isDigit(line1.charAt(i)) && isJudgeHour) {
					if(Character.isDigit(line1.charAt(i))) {
						time += 0 + line1.charAt(i);
					}else {
						time += line1.charAt(i) - 'A' + 10;
					}
					isJudgeHour = false;
				}	
			}
			if(!isJudgeDay && !isJudgeHour) {
				break;
			}
		}
		
		for(int i = 0; i < line3.length() && i < line4.length(); i++) {
			if( line3.charAt(i) == line4.charAt(i) && 
					( Character.isUpperCase(line3.charAt(i)) || Character.isLowerCase(line3.charAt(i)) ) ) {
				time += String.format(":%02d", i);
				break;
			}
		}
		
		System.out.println(time);
	}
}
