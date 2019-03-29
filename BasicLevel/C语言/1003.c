/* 分析得答案正确的条件：
 * 1. 只含有且必须含有 P、A、T；
 * 2. P在T之前，两者数量为1，PT之间必有A;
 * 3. (P左侧A的数量) * (P、T之间A的数量) = T右侧A的数量;
 */
#include <stdio.h>
#include <string.h>
#define LEN 101

int main() {
    int cnt_str = 0; //字符串个数
    scanf("%d", &cnt_str);
    for (int i = 0; i < cnt_str; i++) {
        char str[LEN];
        scanf("%s", str);//读入字符串  
        int cnt_P = 0, cnt_T = 0, isRight = 1;
        int pos_P = 0, pos_T = 0; //设置P、T的下标 
        for (int i = 0; i < strlen(str); i++) {
            if (str[i] == 'P') {
                pos_P = i; //记录P的下标 
                cnt_P++;
            } else if (str[i] == 'T') {
                pos_T = i; // 记录T的下标 
                cnt_T++;
            } else if (str[i] != 'A') {//有其他字符 
            	isRight = 0;
            	break;
			}
        }
        if (isRight && cnt_P == 1 && cnt_T == 1) {//如果字符串只有PAT三种字符 且 P、T数量为1 
            int l_A = 0, c_A = 0, r_A = 0; // 声明左、中、右 字符A的数量 
            l_A = pos_P;
            c_A = pos_T - pos_P - 1;
            r_A = strlen(str) - pos_T - 1;
            if (c_A > 0 && l_A * c_A == r_A) {//PT之间有A，且A的数量 左*中 = 右 
                printf("YES\n");
                continue;
            }
        }  
        printf("NO\n");
    } 
    return 0;
} 