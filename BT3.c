#include<stdio.h>
#include<conio.h>
#include<math.h>
#include<stdlib.h>

int timkiem(int a[], int n, int x){
    for(int i=0;i<n;i++)
    {
        if(a[i]==x)  return i;
    }
    return -1;
    
}
void sapxeptang(int a[],int n)
{
    int tg;
    for(int i = 0; i < n - 1; i++){
        for(int j = i + 1; j < n; j++){
            if(a[i] > a[j]){
                // Hoan vi 2 so a[i] va a[j]
                tg = a[i];
                a[i] = a[j];
                a[j] = tg;        
            }
        }
    }
    
    
    printf("\nMang da sap xep la: ");
    for(int i = 0; i < n; i++){
        printf("%5d", a[i]);
    }
}

void sapxepgiam(int a[], int n)
{
    int tg;
    for(int i = 0; i < n - 1; i++){
        for(int j = i + 1; j < n; j++){
            if(a[i] < a[j]){
                // Hoan vi 2 so a[i] va a[j]
                tg = a[i];
                a[i] = a[j];
                a[j] = tg;        
            }
        }
    }
    
    
    printf("\nMang da sap xep la: ");
    for(int i = 0; i < n; i++){
        printf("%5d", a[i]);
    }   
}
int main(void)
{
    int s1[] = {1,2,5,13,17,19,21};
    int s2[] = {47,74,21,174,196,14,34};

    /*Tìm kích thước và chiều dài của các mảng cần ghép*/
     int size1 = sizeof(s1);
     printf("%d\n",size1); // 28
     int length1 = sizeof(s1)/ sizeof(int);
     printf("%d\n",length1); // 7
     int size2 = sizeof(s2);
     printf("%d\n",size2);//28
     int length2 = sizeof(s2)/ sizeof(int); 
     printf("%d\n",length2);// 7
    

    /* Khai báo mảng kết quả với độ dài đủ để chứa 2 mảng trên*/
    int length = length1 + length2;
    printf("%d\n",length);
    int result[length];
    // khai báo chỉ số mảng result
    int index =0;
     //Copy mảng s1 vào result
    for (int i =0 ;i< length1;i++)
    {
        result[index] = s1[i];
        index = index + 1;
    }
 
    // copy mảng s2 vào mảng result
    for (int i =0 ;i< length2;i++)
    {
        result[index] = s2[i];
        index = index + 1;
    }

    /*Kiểm tra kết quả ghép nối mảng*/
    for(int i = 0; i < length; i++) {
      printf("%d ", result[i]);
    }
    printf("\n");

    // tìm phần tử bất kỳ
    int n;
    fflush(stdin);
    printf("input text:");
    scanf("%d",&n);
    fflush(stdin);

    int vt = timkiem(result,length,n);
    if(vt != -1){
        printf("Tim thay phan tu => vi tri %d", vt+1);
    }
    else printf("Khong tim thay phan tu %d",n);
    
    // sắp xếp tăng
    sapxeptang(result,length);
    // sắp xếp giảm
    sapxepgiam(result,length);
    return 0;
    
}    
    
