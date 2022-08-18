#include <stdio.h>

void nhapMang( int a[], int n)
{
    for(int i= 0 ; i < n; i++)
    {
        printf("Phan tu thu [%d] = ", i+1);
        scanf("%d", &a[i]);
    }
    printf("\n");
}


int isEqual(int a1[], int a2[], int m, int n)
{
    // kiểm tra nếu kích thước mảng m >= n thì lấy kích thước m
    // ngược lại kích thước mảng là n
    int mang;
    if(m >= n)  mang = m;
    else        mang = n;

    int flat = 1; // cờ báo nếu bằng nhau là 1
    for( int i  = 0; i < mang; i++)
    {
        if((sizeof(a1) == sizeof(a2)) && (a1[i] == a2[i]))
        {
            flat = 1;
        }
        else
        {
            flat = 0;
            break;
        }
    }

    if(flat == 1) return 1;
    else          return 0;
}


int main(int argc, char const *argv[])
{
    int n;
    int a1[n];
    printf("Nhap so luong phan tu mang 1: ");
    scanf_s("%d\n", &n);
    nhapMang(a1, n);

    int m;
    int a2[m];
    printf("Nhap so luong phan tu mang 2: ");
    scanf_s("%d\n", &m);
    nhapMang(a2, m);


    int result = isEqual(a1,a2,m,n);
    if (result == 1)   printf("hai mang bang nhau");
    else               printf("hai mang khong bang nhau");
    return 0;
}