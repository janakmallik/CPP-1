#include<bits/stdc++.h>
using namespace std;

typedef struct Student
{
    char name[50];
    float GPA;
} student;

int main()
{
    int n;
    printf("enter n:");
    scanf("%d",&n);
    fflush(stdin);


    struct Student arr[n];


    FILE *file=fopen("data1.txt","w");
    
    fprintf(file,"%d\n",n);
    
    for(int i=0; i<n; i++)
    {
        printf("enter name:");
        gets(arr[i].name);
        fflush(stdin);
        printf("enter GPA:");
        
        scanf("%f",&arr[i].GPA);
        fflush(stdin);
        fprintf(file,"%s\t%f\n",arr[i].name,arr[i].GPA);
    }
    fclose(file);
    char x[50];
    float a;
    file=fopen("data2.txt","w");
    for(int i=0; i<n; i++)
    {
        for(int j=i+1; j<n; j++)
        {
            if(arr[i].GPA<=arr[j].GPA)
            {
                a=arr[i].GPA;
                arr[i].GPA=arr[j].GPA;
                arr[j].GPA=a;
                strcpy(x,arr[i].name);
                
                    strcpy(arr[i].name,arr[j].name);
                    strcpy(arr[j].name,x);
            }
        }
    }
    for(int i=0; i<n; i++)
    {

        fprintf(file,"%s\t%f\n",arr[i].name,arr[i].GPA);
    }
    fclose(file);
}
