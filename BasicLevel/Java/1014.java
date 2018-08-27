/*
字条上奇怪的乱码实际上是时间“星期四 14:04”。  

因为前面两字符串中**第1对相同的大写英文字母（大小写有区分）**是第4个字母'D'，代表星期四；**第2对相同的字符**是'E'，那是第5个英文字母，代表一天里的第14个钟头（于是一天的0点到23点由数字0到9、以及大写字母A到N表示）；  

后面两字符串**第1对相同的英文字母**'s'出现在第4个位置（从0开始计数）上，代表第4分钟。现给定两对字符串，请帮助福尔摩斯解码得到约会的时间。
 */
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.HashMap;

public class Main {	

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		String line1 = br.readLine();
		String line2 = br.readLine();
		String line3 = br.readLine();
		String line4 = br.readLine();
		
		br.close();
		
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
				}else if( (( line1.charAt(i) >= 'A' && line1.charAt(i) <= 'N' ) 
						|| Character.isDigit(line1.charAt(i))) && isJudgeHour) {
					if(Character.isDigit(line1.charAt(i))) {
						time += "0" + line1.charAt(i);
					}else {
						time += line1.charAt(i) - 'A' + 10;
					}
					isJudgeHour = false;
					break;
				}	
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