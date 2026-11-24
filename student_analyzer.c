#include <stdio.h>

#define MAX 100
#define SUBJECTS 5
#define PASS_MARK 40

int main()
{
    int n = 0;
    int marks[MAX][SUBJECTS];
    int total[MAX];
    float percentage[MAX];

    int i, j;
    int choice;
    int topper = 0;
    int fail;
    float classAverage;
    float sumPercentage = 0;

    do
    {
        printf("\n========== STUDENT RESULT ANALYZER ==========\n");
        printf("1. Enter Student Marks\n");
        printf("2. Display Student Results\n");
        printf("3. Display Class Performance\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:

                printf("\nEnter number of students: ");
                scanf("%d", &n);

                if(n <= 0 || n > MAX)
                {
                    printf("Invalid number of students!\n");
                    n = 0;
                    break;
                }

                sumPercentage = 0;

                for(i = 0; i < n; i++)
                {
                    printf("\n--- Student %d ---\n", i + 1);

                    total[i] = 0;

                    for(j = 0; j < SUBJECTS; j++)
                    {
                        do
                        {
                            printf("Enter marks for Subject %d (0-100): ", j + 1);
                            scanf("%d", &marks[i][j]);

                            if(marks[i][j] < 0 || marks[i][j] > 100)
                            {
                                printf("Invalid marks! Enter marks between 0 and 100.\n");
                            }

                        } while(marks[i][j] < 0 || marks[i][j] > 100);

                        total[i] = total[i] + marks[i][j];
                    }

                    percentage[i] = total[i] / 5.0;

                    sumPercentage = sumPercentage + percentage[i];
                }

                printf("\nStudent data entered successfully!\n");
                break;


            case 2:

                if(n == 0)
                {
                    printf("\nPlease enter student marks first!\n");
                    break;
                }

                printf("\n========== STUDENT RESULTS ==========\n");

                for(i = 0; i < n; i++)
                {
                    fail = 0;

                    for(j = 0; j < SUBJECTS; j++)
                    {
                        if(marks[i][j] < PASS_MARK)
                        {
                            fail = 1;
                        }
                    }

                    printf("\nStudent %d\n", i + 1);
                    printf("Total Marks : %d / 500\n", total[i]);
                    printf("Percentage  : %.2f%%\n", percentage[i]);

                    if(fail == 1)
                    {
                        printf("Grade       : F\n");
                        printf("Status      : FAIL\n");
                    }
                    else
                    {
                        if(percentage[i] >= 90)
                            printf("Grade       : A+\n");

                        else if(percentage[i] >= 80)
                            printf("Grade       : A\n");

                        else if(percentage[i] >= 70)
                            printf("Grade       : B\n");

                        else if(percentage[i] >= 60)
                            printf("Grade       : C\n");

                        else if(percentage[i] >= 50)
                            printf("Grade       : D\n");

                        else
                            printf("Grade       : E\n");

                        printf("Status      : PASS\n");
                    }
                }

                break;


            case 3:

                if(n == 0)
                {
                    printf("\nPlease enter student marks first!\n");
                    break;
                }

                topper = 0;

                for(i = 1; i < n; i++)
                {
                    if(percentage[i] > percentage[topper])
                    {
                        topper = i;
                    }
                }

                classAverage = sumPercentage / n;

                printf("\n========== CLASS PERFORMANCE ==========\n");

                printf("Class Topper       : Student %d\n", topper + 1);
                printf("Topper Percentage  : %.2f%%\n", percentage[topper]);
                printf("Class Average      : %.2f%%\n", classAverage);

                break;


            case 4:

                printf("\nThank you! Program terminated.\n");
                break;


            default:

                printf("\nInvalid choice! Please enter 1 to 4.\n");
        }

    } while(choice != 4);

    return 0;
}