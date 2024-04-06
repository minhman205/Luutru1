#include<time.h>
#include<stdio.h>
int main()
{
   clock_t begin = clock(); //ghi l?i th?i gian d?u

   //Ðo?n chuong trình c?n do
   int a[]={12,10,45,56,89,85,24,10};
   for(int i=0;i<10;i++)
   printf("%d \t", a[i]);
  
   
   for(int i=0;i<10;i++)
   printf("%d \t", a[i]);
   
   clock_t end = clock(); //ghi l?i th?i gian lúc sau
   printf("Time run: %f",900000000000000*(float)(end-begin)/CLOCKS_PER_SEC,"s");
   return 0;
}
