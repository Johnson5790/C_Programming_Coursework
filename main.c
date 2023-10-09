/*
 * C Programming: Coursework Assignment (2023)
 *
 * Naicheng Shao
 * May 1, 2023
 *
 * Since the purpose of this homework is to use the compiler to read a txt file containing 319
 * data and write a C program that will perform a statistical analysis of the first 100 results
 * from the dataset and then output the findings onto the terminal in a pre-specified format.
 * In other words, to realize the processing of obtaining the average, standard deviation,
 * maximum value, and minimum value of this file. So I used loops, functions, file input and
 * output and other course content on the overall code framework.
 * In this assignment, I refer to the relevant content in the lecture notes and some sample
 * programs in the lab manual
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*
 * Function Name: mean
 * Function Brief: Prints the information of average value.
 *
 * This function takes the sum of 100 data and realized through a for 
 * loop to obtain the average.
 * 
 * Function Prameters: 
 *  (1) sum
 *  (2) dataset[]
 * Example usage:
 *
 *     mean(float dataset[])
 *     dataset[i]
 */
float mean(float dataset[])
{
    float sum = 0;
    int i = 0;
    for(i = 0; i<100; i++)
    {
        sum += dataset[i];
    }
    return sum/100;
}

/*
 * Function Name: sdev
 * Function Brief: Prints the information of sample standard deviation value.
 *
 * This function use the while loop to realize the expression of the sample 
 * standard deviation formula, so as to calculate the result.
 * 
 * Function Prameters: 
 *  (1) mean
 *  (2) dataset[]
 *
 * Example usage:
 *
 *     sdev(float dataset[], float mean)
 *     dataset[i]
 */
float sdev(float dataset[], float mean)
{
    int i = 0;
    float b = 0, a;
    while (i<100){
    a = (dataset[i]-mean)*(dataset[i]-mean);
    i++;
    b += a;
    }
    return sqrt(b/99);
}

/*
 * Function Name: Min
 * Function Brief: Prints the information of minimum value.
 *
 * This function Use the first data of this group of data as the initial value, 
 * let it compare with all other data, if you get the number smaller than it, 
 * update the result of this initial value, loop 100 times, and get the final 
 * minimum value.
 * 
 * Function Prameters: 
 *  (1) dataset[]
 *
 * Example usage:
 *
 *     Min(float dataset[])
 *     dataset[i]
 */
float Min(float dataset[])
{
    float min = dataset[0];
    for(int i = 1; i<100; i++)
    {
        if (dataset[i]<min){
            min = dataset[i];
        }
    }
    return min;
}

/*
 * Function Name: Max
 * Function Brief: Prints the information of maximum value.
 *
 * This function Use the first data of this group of data as the initial value, 
 * let it compare with all other data, if you get the number bigger than it, 
 * update the result of this initial value, loop 100 times, and get the final
 * maximum value.
 * 
 * Function Prameters: 
 *  (1) dataset[]
 *
 * Example usage:
 *
 *     Max(float dataset[])
 *     dataset[i]
 */
float Max(float dataset[])
{
    float max = dataset[0];
    for(int i = 1; i<100; i++)
    {
        if (dataset[i]>max){
            max = dataset[i];
        }
    }
    return max;

}

/*
 * Function Name: main
 * Function Brief: Read all the data in the txt file using the file's input 
 * and output functions
 *
 * This function call all the calculation methods defined in the above function, 
 * output all the data, and output the result at the same time, so the data width 
 * is positioned at 8, and the decimal is kept to two digits.
 * 
 * Function Prameters: 
 *  (1) test_number[319]
 *  (2) charge_capacity[319]
 *  (3) energy_capacity[319]
 * Example usage:
 *
 *     fp = fopen("dataset.txt", "r")
 *     float sdevc = sdev(charge_capacity, mean(charge_capacity))
 *     float sdeve = sdev(energy_capacity, mean(energy_capacity))
 */
int main()
{
    FILE *fp;
    int test_number[319];
    float charge_capacity[319];
    float energy_capacity[319]; /*Define the three sets of data as arrays.*/
    fp = fopen("dataset.txt", "r");
    int i;
    for(i = 0; i<319; i++)
    {
        fscanf(fp, "%d,%f,%f", &test_number[i], &charge_capacity[i], &energy_capacity[i]);
        /*printf("test_number:%d  charge_capacity:%f  energy_capacity:%f\n", test_number[i], charge_capacity[i], energy_capacity[i]);*/
    }

    float sdevc = sdev(charge_capacity, mean(charge_capacity));
    float sdeve = sdev(energy_capacity, mean(energy_capacity));
    printf("| 9782|  Charge |  Energy |\n");
    printf("|-----|---------|---------|\n");
    printf("| Mean|%8.2lf |%8.2lf |\n", mean(charge_capacity), mean(energy_capacity));
    printf("| Sdev|%8.2lf |%8.2lf |\n", sdevc, sdeve);
    printf("| Min |%8.2lf |%8.2lf |\n", Min(charge_capacity), Min(energy_capacity));
    printf("| Max |%8.2lf |%8.2lf |\n", Max(charge_capacity), Max(energy_capacity));

    return 0;
}

