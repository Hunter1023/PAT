/*
 * 待修改
 * 1. 不同位数的PAT数之间如何方便相加 —— 构造相同大小的字符数组，按位数存储对应的数字
 * 2. 相加时转为数字进行运算
 * 3. 结果为0，为特殊情况，单独写输出代码
 */
#include <stdio.h>
#include <string.h>

int main() {
    char table[21], num1[21], num2[21], sum[22] = {0};
    scanf("%s %s %s", table, num1, num2);//读取进制表 和 两个PAT数 
    int base, a, b;
    int len = strlen(table), len1 = strlen(num1), len2 = strlen(num2);
    for(int i = len - 1; i >= 0; i--) {//  是否还在读取num1内容 ，是的话 将对应位的值 给 a；否则将0赋给a ，同理b 
        a = (len - i) <= len1 ? num1[len1 - (len - i)] - '0' : 0;
        b = (len - i) <= len2 ? num2[len2 - (len - i)] - '0' : 0;
        base = table[i] == '0' ? 10 : table[i] - '0';//获取进制表对应位的进制 
        sum[i+1] += a + b;
        if(sum[i+1] >= base) {
        	sum[i] += 1;
		}
        sum[i+1] %= base;
        sum[i+1] += '0';
    }
    sum[0] += '0';
    for(int i = 0; i < 22; i++) { /* find the first non-zero bit */
        if (sum[i] != 0 && sum[i] != '0') {
            printf("%s\n", sum + i);
            return 0;
        }
    } 
    printf("0\n");/* If A + B = 0, then all bits are zero */
    return 0;
}