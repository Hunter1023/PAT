#include <stdio.h>

int main() {
    char c; 
    int lines = 0, hasASCII[127] = {0}; //空格的码值为32 
    while (lines < 2) { 
        c = getchar(); // 读取字符 
        if (c == '\n') { //回车 
        	lines++; // 读取下一行 
		} else if(!hasASCII[(int)c]) { //是第一次读到的字符 
            putchar(c); //输出
            hasASCII[(int)c] = 1; //标记已经读取过
        }
    }
    return 0;
}
