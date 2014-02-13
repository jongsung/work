#include <stdio.h>
#include <string.h>
#include <stdlib.h>


#define STR_LEN 200


int LinearSearch(int ar[], int len, int target);
int test_LinearSearch(void);

int BinarySearch(int array[], int len, int target);
int test_BinarySearch(void);

int DecToBin(int DecNum, int binArry[]);
int test_DecToBin(void);

int Divisor(int num);
int test_Divisor(void);

int BubbleSort(int array[], int len);
int test_BubbleSort(void);

int BubbleSortString(char (*array)[STR_LEN], int len);
int test_BubbleSortString(void);
int test_BubbleSortString2(void);

int test(void);

int main(void)
{
    //test_LinearSearch();
    //test_BinarySearch();
    //test_DecToBin();
    //test_Divisor();
    //test_BubbleSort();
    test_BubbleSortString();
    test_BubbleSortString2();
    //test();
    
    return 0;
}




int LinearSearch(int ar[], int len, int target)
{
    int i;
    
    printf("%s, %d\n", __FUNCTION__, __LINE__);    
    
    for(i=0 ; i<len ; i++)
    {
        printf("[%s, %d], ar[%d]=%d, target=%d\n", __FUNCTION__, __LINE__, i, ar[i], target);
        
        if(ar[i] == target)
        {
            //printf("founded ar[%d] = target(%d)\n", i, target);
            return i;
        }
    }
    
    return -1;
}

int test_LinearSearch(void)
{
    int arr[] = {3, 5, 2, 4, 9};
    int idx = 0;

    printf("%s, %d\n", __FUNCTION__, __LINE__);
    
    idx = LinearSearch(arr, sizeof(arr)/sizeof(int), 4);
    if(idx == -1)
    {
        printf("[%s, %d], search failed\n", __FUNCTION__, __LINE__);
        return -1;
    }
    else
    {
        printf("[%s, %d], search successful, idx=%d\n", __FUNCTION__, __LINE__, idx);
    }

    return 0;
}


int BinarySearch(int array[], int len, int target)
{
    int first = 0;
    int last = len-1;
    int middle = (first + last)/2;

    printf("%s, %d\n", __FUNCTION__, __LINE__);
    
    while(first <= last)
    {
        if (array[middle] < target)
        {
            first = middle + 1;    
        }
        else if ( array[middle] == target ) 
        {
            printf("%d found at location %d.\n", target, middle);
            return middle;
        }
        else
        {
            last = middle - 1;
        }

        middle = (first + last)/2;
    }
    
    if ( first > last )
    printf("Not found! %d is not present in the list.\n", target);
    
    return -1;
}

int test_BinarySearch(void)
{
    int arr[] = {1,2,3,4,5,6,7,8,9};
    int idx = 0;

    printf("%s, %d\n", __FUNCTION__, __LINE__);
    
    idx = BinarySearch(arr, sizeof(arr)/sizeof(int), 2);
    if(idx == -1)
    {
        printf("[%s, %d], search failed\n", __FUNCTION__, __LINE__);
        return -1;
    }
    else
    {
        printf("[%s, %d], search successful, idx=arr[%d]\n", __FUNCTION__, __LINE__, idx);
    }

    return 0;
}


int DecToBin(int DecNum, int binArry[])
{
    int i = 0;
    int count = 0;
    int total_count;
    int tmpArry[20];

    printf("%s, %d\n", __FUNCTION__, __LINE__);
    
    while(DecNum > 0)
    {
        tmpArry[count++] = DecNum%2;
        DecNum = DecNum/2;
    }
    
    total_count = count;
    
    for(i=0; i<count; i++)
    {
        binArry[i] = tmpArry[count-i-1];
    }
    
    return total_count;
}

int test_DecToBin(void)
{
    int binArray[20] = {0, };
    int count, i;
    int DecNum;

    printf("%s, %d\n", __FUNCTION__, __LINE__);
    
    printf("input decimal value:");
    scanf("%d", &DecNum);
    
    count = DecToBin(DecNum, binArray);
    
    printf("Dec:%d, Bin:", DecNum);
    for(i=0 ; i<count ; i++)
    {
        printf("%d", binArray[i]);
    }
    
    return 0;
}

int Divisor(int num)
{
    int i = 0;
    
    printf("%s, %d\n", __FUNCTION__, __LINE__);

    for(i=1; i<=num ; i++)
    {
        if((num%i) == 0)
            printf("%d ", i);
    }
    
    return 0;
}

int test_Divisor(void)
{
    int num;
    int ret;
    
    printf("%s, %d\n", __FUNCTION__, __LINE__);
    
    while(1)
    {
        printf("\ninput number:");
        ret = scanf("%d", &num);
        
        if(ret == EOF)
            break;
    
        if(num < 0)
        {
            printf("error: invalid value\n");
        }
        else 
        {    
            Divisor(num);
        }
    }
    
    return 0;
}


int BubbleSort(int array[], int len)
{
    int i, j;
    int tmp;
    
    printf("%s, %d\n", __FUNCTION__, __LINE__);
    
    for(i=0; i<len-1; i++)
    {
        for(j=0; j<len-i-1; j++)
        {
            if(array[j] > array[j+1])
            {
                tmp = array[j];
                array[j] = array[j+1];
                array[j+1] = tmp;
            }
        }
    }
    
    return 0;
}


int test_BubbleSort(void)
{
    int i;
    int arr[5] = {3, 2, 1, 4, 5};
    
    printf("%s, %d\n", __FUNCTION__, __LINE__);
    
    BubbleSort(arr, sizeof(arr)/sizeof(int));
    for(i=0 ; i<sizeof(arr)/sizeof(int) ; i++)
    {
        printf("arr[%d] = %d\n", i, arr[i]);
    }
    
    return 0;
}



int BubbleSortString(char (*array)[STR_LEN], int len)
{
    int i, j;
    char temp[STR_LEN];
    
    printf("%s, %d\n", __FUNCTION__, __LINE__);
    
    for(i=0 ; i<len-1 ; i++)
    {
        for(j=0; j<len-i-1 ; j++)
        {
            if(strcmp(array[j], array[j+1]) > 0)
            {
                strcpy(temp, array[j]);
                strcpy(array[j], array[j+1]);
                strcpy(array[j+1], temp);
            }
        }
    }
    
    return 0;
}

int test_BubbleSortString(void)
{
    int i;
    char strArry[5][STR_LEN] = {"Cool", "And", "Boy", "Eight", "Down"};
    
    printf("%s, %d\n", __FUNCTION__, __LINE__);
    
    for(i=0; i<5 ; i++)
    {
        printf("strArry[%d] = %s\n", i, strArry[i]);
    }
    
    BubbleSortString(strArry, 5);
    
    for(i=0; i<5 ; i++)
    {
        printf("strArry[%d] = %s\n", i, strArry[i]);
    }
    
    return 0;
}

int test_BubbleSortString2(void)
{
    int i, j;
    char *str1 = "Cool";
    char *str2 = "And";
    char *str3 = "Boy";
    char *str4 = "Eight";
    char *str5 = "Down";
    char *ptmpstr = NULL;
    int len = 0;
    
    char *strArry[5] = {str1, str2, str3, str4, str5};
    
    printf("%s, %d\n", __FUNCTION__, __LINE__);
    
    printf("sizeof strArry=%d\n", sizeof(strArry)/sizeof(int));

    len = sizeof(strArry)/sizeof(int);
    
    for(i=0; i<len ; i++)
    {
        printf("strArry[%d] = %s\n", i, strArry[i]);
    }
    
    for(i=0 ; i<len-1 ; i++)
    {
        for(j=0 ; j<len-i-1 ; j++)
        {
            if(strcmp(strArry[j], strArry[j+1]) > 0)
            {
                ptmpstr = strArry[j];
                strArry[j] = strArry[j+1];
                strArry[j+1] = ptmpstr;
            }
        }
    }
    
    for(i=0; i<len ; i++)
    {
        printf("strArry[%d] = %s\n", i, strArry[i]);
    }
    
    return 0;
}


int test(void)
{
    int i;
    int sel = 0;
    int start = 0;
    
    for(;;)
    {
        fputs("odd(1), even(2)", stdout);
        scanf("%d", &sel);
        
        if((sel == 1) || (sel == 2))
            break;
        else
            printf("input error !\n");
    }

    start = (sel==1) ? 2 : 3;
    for( ; start<=9 ; start+=2)
    {
        for(i=1; i<=9 ; i++)
        {
            printf("%d * %d = %d\n", start, i, start* i);
        }
    }
    
    return 0;
}
