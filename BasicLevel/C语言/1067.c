/*
 * （字符的读取，可回顾1054. 求平均值）
 * PS：用户输入的长度未知，可通过 创建大容量的字符数组 解题；
 */
#include <stdio.h>
#include <string.h>

int main() {
    int N;
    char c, password[21], user[21];
    scanf("%s %d", password, &N); 
    getchar();//读掉回车 
    while(N--) {//允许尝试的次数 
        scanf("%20[^\n]", user);//读取回车之前的字符，最多20位 （存在读了20位，还没有读完输入的情况） 
        c = getchar();
        if(!strcmp(user, "#") && c == '\n') {//输入的是 #，结束 
            break;
        } else if(!strcmp(correct, user) && c == '\n') {//输入的是正确答案，结束 
            printf("Welcome in\n");
            break;
        } else {//错误答案
            printf("Wrong password: %s%c", user, c);
            while(c != '\n') {//输入的密码位数很多，读取直到回车 
            	c = getchar();
            	printf("%c", c);
			}
            if(!N) {//尝试次数结束，输出 
				printf("Account locked\n");
			} 
        }
    }
    return 0;
}