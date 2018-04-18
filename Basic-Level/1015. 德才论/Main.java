import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

/*输入格式：

输入第1行	给出3个正整数，分别为：
	N（<=10^5），即考生总数；
	L（>=60），为录取最低分数线，即德分和才分均不低于L的考生才有资格被考虑录取；
	H（<100），为优先录取线——德分和才分均不低于此线的被定义为“才德全尽”。// *此类考生按德才总分从高到低排序； 第一类
	*才分不到但德分到H的考生	按总分排序 // 第二类
	*德才分均低于H，但是德分>=才分的考生 //按总分排序，第三类；
	*其他达到最低线L的考生				按总分排序，第四类。

	随后N行，每行给出一位考生的信息，包括：
	准考证号   (准考证号为8位整数)
	德分、才分(德才分为区间[0, 100]内的整数。数字间以空格分隔)
	
	输出格式：
	
	输出第1行 给出达到最低分数线的考生人数M，
	
	随后M行，每行按照输入格式输出一位考生的信息，考生按输入中说明的规则从高到低排序。
	当某类考生中有多人总分相同时，按其德分降序排列；若德分也并列，则按准考证号的升序输出。
	
	
	创建记录达标的考生人数 int M； political >= L && ability >= L； M++；
	
	创建考生类，
	HashMap<Integer,HashMap<Integer,Integer>>
			准考证号			德分		才分
	筛选

*/
public class Main {

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String[] str = br.readLine().split(" ");//获取考生总数、录取最低分数线、优先录取线
		

	}

}
