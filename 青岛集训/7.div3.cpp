#include <stdio.h>                                                                                                                                                               
#include <stdlib.h>                                                                                                                                                                
#include <cstring>                                                                                                                                                                  
#define MAX 10000                                                                                                                                                                          
                                                                                                                                                                                           
// 把数值的低位放在数组的低位                                                                                                                                                              
void transform(const char *str, int *ans) {                                                                                                                                                
    int len = strlen(str);                                                                                                                                                                 
    ans[0] = len;                                                                                                                                                                          
    // 易错点 ans[len--] 导致 i < len 改变, 判断条件值不能参与运算                                                                                                                         
    for (int i = 0; i < ans[0]; i++) {                                                                                                                                                     
        ans[len--] = str[i] - '0';                                                                                                                                                         
    }                                                                                                                                                                                      
    return ;                                                                                                                                                                               
}                                                                                                                                                                                          
                                                                                                                                                                                           
void func_add(int *a, int *b, int *ans) {                                                                                                                                                  
    ans[0] = (a[0] > b[0] ? a[0] : b[0]);                                                                                                                                                  
    // 易错点 i、j 值的意义，容易写为0                                                                                                                                                     
    for (int i = 1; i <= ans[0]; i++) {                                                                                                                                                    
        ans[i] = a[i] + b[i];                                                                                                                                                              
    }                                                                                                                                                                                      
    for (int j = 1; j <= ans[0]; j++) {                                                                                                                                                    
        if (ans[j] < 10) continue;                                                                                                                                                         
        ans[j + 1] += ans[j] / 10;                                                                                                                                                         
        ans[j] %= 10;                                                                                                                                                                      
        ans[0] += (j == ans[0]);                                                                                                                                                           
    }                                                                                                                                                                                      
    return ;                                                                                                                                                                               
}                                                                                                                                                                                          
                                                                                                                                                                                           
int swap(int *a, int *b, int *ans) {                                                                                                                                                       
    // flag = 1 发生交换                                                                                                                                                                   
    int flag = 0;                                                                                                                                                                          
    if (a[0] < b[0]) flag = 1;                                                                                                                                                             
    // 比较两数数位相同时的大小, 注意 i 值, 从高到低                                                                                                                                       
    for (int i = b[0]; (!flag) && i >= 1; i--) {                                                                                                                                           
        // return 1 可以相减                                                                                                                                                               
        if (a[i] < b[i]) flag = 1;                                                                                                                                                         
        if (a[i] > b[i] || (i == 1 && a[i] - b[i] == 0)) break;                                                                                                                            
    }                                                                                                                                                                                      
    for (int i = 0; flag && i <= ans[0]; i++) {                                                                                                                                            
        a[i] ^= b[i];                                                                                                                                                                      
        b[i] ^= a[i];                                                                                                                                                                      
        a[i] ^= b[i];                                                                                                                                                                      
    }                                                                                                                                                                                      
    if (flag) return 1;                                                                                                                                                                    
    else return 0;                                                                                                                                                                         
}                                                                                                                                                                                          
                                                                                                                                                                                           
void func_sub1(int *a, int *b, int *ans) {                                                                                                                                                 
    ans[0] = (a[0] > b[0] ? a[0] : b[0]);                                                                                                                                                  
    // 进行交换                                                                                                                                                                            
    int flag = 0;                                                                                                                                                                          
    if (a[0] <= b[0]) flag = swap(a, b, ans);                                                                                                                                              
    for (int i = 1; i <= ans[0]; i++) {                                                                                                                                                    
        ans[i] = a[i] - b[i];                                                                                                                                                              
    }                                                                                                                                                                                      
    for (int j = 1; j <= ans[0]; j++) {                                                                                                                                                    
        // 易错, 0 值也要参与判断                                                                                                                                                          
        if (ans[j] >= 0) continue;                                                                                                                                                         
        ans[j] += 10;                                                                                                                                                                      
        ans[j + 1]--;                                                                                                                                                                      
    }                                                                                                                                                                                      
    // 计算结果的位数                                                                                                                                                                      
    for (int k = ans[0]; k >= 1; k--) {                                                                                                                                                    
        if (ans[k]) break;                                                                                                                                                                 
        if (k == 1 && ans[k] == 0) break;                                                                                                                                                  
        ans[0]--;                                                                                                                                                                          
    }                                                                                                                                                                                      
    // 负数输出负号 -                                                                                                                                                                      
    if (flag) printf("-");                                                                                                                                                                 
}                                                                                                                                                                                          
                                                                                                                                                                                           
void func_sub2(int *a, int *b, int *ans) {                                                                                                                                                 
    ans[0] = (a[0] > b[0] ? a[0] : b[0]);                                                                                                                                                  
    // flag = 1 为正数，flag = -1 为负数                                                                                                                                                   
    int flag = 0;                                                                                                                                                                          
    // 易错，从高位开始                                                                                                                                                                    
    for (int i = ans[0]; i >= 1; i--) {                                                                                                                                                    
        ans[i] = a[i] - b[i];                                                                                                                                                              
        if (!flag && ans[i] > 0) flag = 1;                                                                                                                                                 
        if (!flag && ans[i] < 0) flag = -1;                                                                                                                                                
    }                                                                                                                                                                                      
    if (!flag) {                                                                                                                                                                           
        ans[0] = 1;                                                                                                                                                                        
        ans[1] = 0;                                                                                                                                                                        
    }                                                                                                                                                                                      
    // 非负数计算法                                                                                                                                                                        
    for (int j = 1; (flag == 1) && j <= ans[0]; j++) {                                                                                                                                     
        // 易错, 0 值也要参与判断                                                                                                                                                          
        if (ans[j] >= 0) continue;                                                                                                                                                         
        ans[j] += 10;                                                                                                                                                                      
        ans[j + 1]--;                                                                                                                                                                      
    }                                                                                                                                                                                      
    // 负数计算法                                                                                                                                                                          
    for (int j = 1; (flag == -1) && j <= ans[0]; j++) {                                                                                                                                    
        if (ans[j] > 0) {                                                                                                                                                                  
            ans[j] = 10 - ans[j];                                                                                                                                                          
            ans[j + 1]++;                                                                                                                                                                  
        }                                                                                                                                                                                  
        if (ans[j] < 0){                                                                                                                                                                   
            ans[j] = -ans[j];                                                                                                                                                              
        }                                                                                                                                                                                  
    }                                                                                                                                                                                      
    // 计算结果的位数                                                                                                                                                                      
    for (int k = ans[0]; k >= 1; k--) {                                                                                                                                                    
        if (ans[k]) break;                                                                                                                                                                 
        if (k == 1 && ans[k] == 0) break;                                                                                                                                                  
        ans[0]--;                                                                                                                                                                          
    }                                                                                                                                                                                      
    // 负数输出负号 -                                                                                                                                                                      
    if (flag == -1) printf("-");                                                                                                                                                           
    return ;                                                                                                                                                                               
}                                                                                                                                                                                          
                                                                                                                                                                                           
void func_mult(int *a, int *b, int *ans) {                                                                                                                                                 
    // 特殊用例                                                                                                                                                                            
    if (a[0] == 1 && a[1] == 0 || b[0] == 1 && b[1] == 0) {                                                                                                                                
        ans[0] = 1;                                                                                                                                                                        
        ans[1] = 0;                                                                                                                                                                        
        return ;                                                                                                                                                                           
    }                                                                                                                                                                                      
    // 易错点 i、j 值的意义，容易写为0                                                                                                                                                     
    int temp[MAX + 5] = {0};                                                                                                                                                               
    for (int k = 1; k <= b[0]; k++) {                                                                                                                                                      
        // 清空temp值                                                                                                                                                                      
        memset(temp, 0, sizeof(temp));                                                                                                                                                     
        // 乘法运算每一次进一位                                                                                                                                                            
        temp[0] = a[0] + k - 1;                                                                                                                                                            
        for (int i = 1; i <= a[0]; i++) {                                                                                                                                                  
            // 乘法运算每一次进一位                                                                                                                                                        
            temp[i + k - 1] = a[i] * b[k];                                                                                                                                                 
        }                                                                                                                                                                                  
        for (int j = 1; j <= temp[0]; j++) {                                                                                                                                               
            if (temp[j] < 10) continue;                                                                                                                                                    
            temp[j + 1] += temp[j] / 10;                                                                                                                                                   
            temp[j] %= 10;                                                                                                                                                                 
            temp[0] += (j == temp[0]);                                                                                                                                                     
        }                                                                                                                                                                                  
        func_add(temp, ans, ans);                                                                                                                                                          
    }                                                                                                                                                                                      
    return ;                                                                                                                                                                               
}                                                                                                                                                                                          
                                                                                                                                                                                           
void func_sub3(int *a, int *b, int *ans) {                                                                                                                                                 
    ans[0] = (a[0] > b[0] ? a[0] : b[0]);                                                                                                                                                  
    for (int i = 1; i <= ans[0]; i++) {                                                                                                                                                    
        ans[i] = a[i] - b[i];                                                                                                                                                              
    }                                                                                                                                                                                      
    for (int j = 1; j <= ans[0]; j++) {                                                                                                                                                    
        // 易错, 0 值也要参与判断                                                                                                                                                          
        if (ans[j] >= 0) continue;                                                                                                                                                         
        ans[j] += 10;                                                                                                                                                                      
        ans[j + 1]--;                                                                                                                                                                      
    }                                                                                                                                                                                      
    // 计算结果的位数                                                                                                                                                                      
    for (int k = ans[0]; k >= 1; k--) {                                                                                                                                                    
        if (ans[k]) break;                                                                                                                                                                 
        if (k == 1 && ans[k] == 0) break;                                                                                                                                                  
        ans[0]--;                                                                                                                                                                          
    }                                                                                                                                                                                      
}                                                                                                                                                                                          
                                                                                                                                                                                           
int comp(int *a, int *b) {                                                                                                                                                                 
    // 比较两数数位相同时的大小, 注意 i 值, 从高到低                                                                                                                                       
    for (int i = b[0]; i >= 1; i--) {                                                                                                                                                      
        // return 1 可以相减                                                                                                                                                               
        if (a[i] < b[i]) return 0;                                                                                                                                                         
        if (a[i] >= b[i] || (i == 1 && a[i] - b[i] == 0)) return 1;                                                                                                                         
    }                                                                                                                                                                                      
}                                                                                                                                                                                          
                                                                                                                                                                                           
// b / a                                                                                                                                                                                   
void func_div(int *a, int *b, int *ans) {                                                                                                                                                  
    // 商的索引                                                                                                                                                                            
    int buff = b[0] - a[0] + 1;                                                                                                                                                            
    int cnt = 0;                                                                                                                                                                           
    while (buff >= 1) {                                                                                                                                                                    
        // 特殊情况，被除数为0 或者 除数大于被除数                                                                                                                                         
        // 易错点 把 a 当作被除数                                                                                                                                                          
        if (!cnt && (a[0] > b[0] || b[0] == 1 && b[0] == 0)) {                                                                                                                             
            ans[0] = 1;                                                                                                                                                                    
            ans[1] = 0;                                                                                                                                                                    
            return ;                                                                                                                                                                       
        }                                                                                                                                                                                  
        // 除数大于被除数                                                                                                                                                                  
        if (!cnt && b[0] == a[0]) {                                                                                                                                                        
            for (int i = b[0]; i >= 1; i--) {                                                                                                                                              
                if (a[i] == b[i]) continue;                                                                                                                                                
                if (a[i] < b[i]) break;                                                                                                                                                    
                ans[0] = 1;                                                                                                                                                                
                ans[1] = 0;                                                                                                                                                                
                return ;                                                                                                                                                                   
            }                                                                                                                                                                              
        }                                                                                                                                                                                  
        // 临时数组处理每一次除法                                                                                                                                                          
        int temp[MAX + 5] = {0};                                                                                                                                                           
        temp[0] = a[0];                                                                                                                                                                    
        // 易错点 sizeof() 取值大小                                                                                                                                                        
        memmove(temp + 1, b + buff, sizeof(int) * (b[0] - buff + 1));                                                                                                                      
        // 易错点 判断循环的条件，在循环内外导致的问题                                                                                                                                     
        while (comp(temp, a)) {                                                                                                                                                            
            func_sub3(temp, a, temp);                                                                                                                                                      
            // 每使用一次减法 商加1 最高位的商为数位                                                                                                                                       
            ans[buff] += 1;                                                                                                                                                                
            if (cnt == 0) ans[0] = buff;                                                                                                                                                   
            cnt++;                                                                                                                                                                         
        }                                                                                                                                                                                  
        // 易错点 sizeof() 取值大小                                                                                                                                                        
        memmove(b + buff, temp + 1, sizeof(int) * a[0]);                                                                                                                                   
        // 刷新temp数组                                                                                                                                                                    
        memset(temp, 0, sizeof(temp));                                                                                                                                                     
        // 计算结果的位数                                                                                                                                                                  
        for (int k = b[0]; k >= 1; k--) {                                                                                                                                                  
            if (b[k]) break;                                                                                                                                                               
            if (k == 1 && b[k] == 0) break;                                                                                                                                                
            b[0]--;                                                                                                                                                                        
        }                                                                                                                                                                                  
        // 易错点 只在循环外写buff导致死循环                                                                                                                                               
        buff = b[0] - a[0] + 1;                                                                                                                                                            
    }                                                                                                                                                                                      
    return ;                                                                                                                                                                               
}                                                                                                                                                                                          
                                                                                                                                                                                           
int main() {                                                                                                                                                                               
    char str_a[MAX + 5], str_b[MAX + 5];                                                                                                                                                   
    scanf("%s%s", str_a, str_b);                                                                                                                                                           
    int a[MAX + 5] = {0}, b[MAX + 5] = {0};                                                                                                                                                
    transform(str_a, a);                                                                                                                                                                   
    transform(str_b, b);                                                                                                                                                                   
    int ans[MAX + 5] = {0};                                                                                                                                                                
    // 加法                                                                                                                                                                                
    // func_add(a, b, ans);                                                                                                                                                                
    // 减法                                                                                                                                                                                
    // func_sub1(a, b, ans);                                                                                                                                                               
    // func_sub2(a, b, ans);                                                                                                                                                               
    // 乘法                                                                                                                                                                                
    // func_mult(a, b, ans);                                                                                                                                                               
    // 除法                                                                                                                                                                                
    func_div(a, b, ans);                                                                                                                                                                   
    for (int i = ans[0]; i >= 1; i--) {                                                                                                                                                    
        printf("%d", ans[i]);                                                                                                                                                              
    }                                                                                                                                                                                      
    return 0;                                                                                                                                                                              
}                    

