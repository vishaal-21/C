#include<stdio.h>
#include<math.h>
void main()
{
    int a,b,c,disc,x1,x2;
    float img;
    printf("Enter coefficient of x^2, x and constant : ");
    scanf("%d%d%d",&a,&b,&c);

    disc=(b*b)-(4*a*c);

    printf("Roots of %dx^2 + %dx + %d are : ",a,b,c);
    switch(disc>0)
    {
        case 1:
        x1=(-b+sqrt(disc))/(2*a);
        x2=(-b-sqrt(disc))/(2*a);
        printf("Real and distinct = %d, %d",x1,x2);
        break;

        case 0:
        switch(disc==0)
        {
            case 1:
            x1=x2=-b/(2*a);
            printf("Real and equal = %d, %d",x1,x2);
            break;

            case 0:
            x1=x2=-b/(2*a);
            img=sqrt(-disc)/(2*a);
            printf("Imaginary = %d+i%f, %d-i%f",x1,img,x2,img);
            break;
        }
    }
}
