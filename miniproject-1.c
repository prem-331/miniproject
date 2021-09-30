#include <stdio.h>
#define max 20000
void add(char input1[], char input2[] , char answer[]){
    int carry = 0;
    for (int i = max-1; i>=0;i--){
        int number = (input1[i] - '0') + (input2[i] - '0') + carry;
        answer[i] = (number % 10) + '0';
        carry = number/10;
    }
}
void copy2on1(char input1[], char input2[]){
        for (int i = max-1; i>=0; i--)
    input1[i] = input2[i];

}
char fibo1[max];
char fibo2[max];
char answer[max];

int main(){
    for (int i = 0; i < max; i++){
        fibo1[i] = fibo2[i] = answer[i] = '0';
    }
    fibo2[max-1] = '1';
    int n;
    scanf("%d" , &n);
    if (n == 0 || n == 1){
        printf("%c" , n+'0');
    }
    else{
        for (int i = 2; i<= n; i++){
            add(fibo1, fibo2, answer);
            copy2on1(fibo1, fibo2);
            copy2on1(fibo2, answer);
        }

        int firstnum = 0;
        for(int i =0 ; i < max ; i++){
            if(firstnum == 0 && answer[i] == '0')
            continue;
            
            if(firstnum == 0 && answer[i] != '0')
            firstnum = 1;
            printf("%c", answer[i]);
        }
    }
    return 0;
}