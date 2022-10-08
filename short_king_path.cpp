#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
 
int max(int a , int b){
  if(a >= b){
    return a;
  }
  else return b;
}
 
  
int main (){
    
    
 
    char tx1 , tx2 ; int y1 , y2 ;
    scanf("%c%d %c%d",&tx1,&y1,&tx2,&y2);
  
    int x1 = tx1 - 'a' , x2 = tx2 - 'a' ;
    
    printf("%d\n",max (abs(x2-x1) , abs (y2-y1))) ;
 
    while (x1 != x2 || y1 != y2){
        if (x1 < x2){
            printf("R")  ;
            x1 += 1 ;
        }
        else if (x1 > x2){
            printf("L") ;
            x1 -= 1 ;
        }
        if (y1 < y2){
            printf("U") ;
            y1 += 1 ;
        }
        else if (y1 > y2){
            printf("D") ;
            y1 -= 1 ;
        }
        printf("\n") ;
    }
    
 
}
 
