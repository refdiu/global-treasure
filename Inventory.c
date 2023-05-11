#include<stdio.h>
#include<string.h>

int inventory(int option)
{
    int choice, i, j, k;
    if(option == 1)
    {
        struct products
        {
            int COGS;
            int SP;
            int yr;
            char heading1[8];
            char heading2[8];
            char heading3[8];
        }details[5];
        strcpy(details[0].heading1, "  ");
        strcpy(details[0].heading2, "CP");
        strcpy(details[0].heading3, "SP");
        for(i = 1; i <= 5; i++)
        {
            printf("Enter the year:\n");
            scanf("%d", &details[i].yr);
            printf("Enter the cost price:\n");
            scanf("%d", &details[i].COGS);
            printf("Enter the selling price:\n");
            scanf("%d", &details[i].SP);
        }
        printf("%s ", details[0].heading1);
        for(j = 1; j <= 5; j++)
        {
            printf("%d ", details[j].yr);
        }
        printf("\n");
        printf("%s ", details[0].heading2);
        for(j = 1; j <= 5; j++)
        {
            printf("%d ", details[j].COGS);
        }
        printf("\n");
        printf("%s ", details[0].heading3);
        for(j = 1; j <= 5; j++)
        {
            printf("%d ", details[j].SP);
        }
        printf("\n");
        //now,
        int CPdat[5], SPdat[5];
        for(j = 1; j <= 5; j++)
        {
            CPdat[j-1] = details[j].COGS;
            SPdat[j-1] = details[j].SP;
        }
        int gd = DETECT, gm;
    initgraph(&gd, &gm, "");
    int left, top, right, bottom;
    bar(left = 150, top = 150,
    right = 190, bottom = 350);
    bar(left = 220, top = 250,
    right = 260, bottom = 350);
    bar(left = 290, top = 200,
    right = 330, bottom = 350);
    line(100, 50, 100, 350);
    line(100, 350, 400, 350);
    closegraph();
    }
    else if(option == 2)
    {
        int got;
        printf("Choose.....\n a) XMBC2022\n b) NMBC2022\n c) IORA2023\n");
        scanf("%d", &got);
        if(got == 1)
        {
            printf("Model: Red Latest\n Specifications: 15 GHz processor, Snapdragon 866\n Body: Carbon Fibre\n");
        }
        else if(got == 2)
        {
            printf("Model: Blue Old\n Specifications: 45 GHz processor, Snapdragon 946\n Body: Titanium\n");
        }
        else if(got == 3)
        {
            printf("Model: Black Wood\n Specifications: 1 THz processor, Snapdragon Lorem Ipsum\n Body: Nether\n");
        }
    }
    else
    {
        printf("Are you sure?(Y(1) or N(0))\n");
        scanf("%d", &choice);
        if(choice == 1)
        {
            printf("You can close this window now.");
        }
        else if(choice == 0)
        {
            printf("What option do you want then?\n");
            scanf("%d", &option);
            inventory(choice);
        }
    }
}

int main()
{
    int we, us;
    printf("Welcome\n");
    printf("Choose your option....\n");
    printf(" 1. Product Report\n 2. Product Details\n 3. Exit\n");
    scanf("%d", &we);
    us = inventory(we);
}
