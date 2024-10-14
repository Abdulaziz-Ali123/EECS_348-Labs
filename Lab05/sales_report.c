#include <stdio.h>
#include <string.h>

// Define constants for months and the number of sales
#define MONTHS 12

//store month names
const char* month_names[] = {"January", "February", "March", "April", "May", "June", 
                             "July", "August", "September", "October", "November", "December"};

//print s
void print_six_month_average(double sales[]) {
    printf("Six-Month Moving Average Report:\n");
    //loop through first 6 months
    for (int i = 0; i <= MONTHS - 6; i++) {
        double sum = 0;
        //for each of those month loop thorugh the next 6 months
        for (int j = i; j < i + 6; j++) {
            sum += sales[j];
        }
        //caclulate average and print it
        double average = sum / 6;
        printf("%s-%s $%.2f\n", month_names[i], month_names[i + 5], average);
    }
    printf("\n");
}

//print sales summary
void print_sales_summary_report(double sales[]) {
    //initiallze min max as the first elements of sales
    //initilaze min_month and max_month  and total as 0
    double min = sales[0], max = sales[0], total = 0;
    int min_month = 0, max_month = 0;
    
    //looop through says array 
    for (int i = 0; i < MONTHS; i++) {
        //if the current arrya is less than the set min
        // make that the new min 
        if (sales[i] < min) {
            min = sales[i];
            min_month = i;
        }
        //if the current array is greater than the set max
        // make that the new max
        if (sales[i] > max) {
            max = sales[i];
            max_month = i;
        }
        
        //add the current sale to total
        total += sales[i];
    }

    //calculate average over the 12 months
    double avg = total / MONTHS;
    
    //print the min max and average sales
    printf("Sales summary report:\n");
    printf("Minimum sales: $%.2f (%s)\n", min, month_names[min_month]);
    printf("Maximum sales: $%.2f (%s)\n", max, month_names[max_month]);
    printf("Average sales: $%.2f\n\n", avg);
}

// print sales highest to lowest 
void print_sales_highest_to_lowest(double sales[]) {
    //store the soreted sales and months that corilate with the sales
    double sorted_sales[MONTHS];
    int sorted_months[MONTHS];
    
    // copy sales and month indicies to sorted sales and month
    for (int i = 0; i < MONTHS; i++) {
        sorted_sales[i] = sales[i];
        sorted_months[i] = i;
    }
    
    // loop through each month
    for (int i = 0; i < MONTHS - 1; i++) {
        //for each element loop through again
        //compare each element to every next element
        for (int j = i + 1; j < MONTHS; j++) {
            //if the current sales value is less than the next
            if (sorted_sales[i] < sorted_sales[j]) {
                // swap the sales
                double temp_sales = sorted_sales[i];
                sorted_sales[i] = sorted_sales[j];
                sorted_sales[j] = temp_sales;
                
                // swap the months
                int temp_month = sorted_months[i];
                sorted_months[i] = sorted_months[j];
                sorted_months[j] = temp_month;
            }
        }
    }
    
    printf("Sales Report (Highest to Lowest):\n");
    printf("Month       Sales\n");
    
    //for each month print the sales report in decending order
    for (int i = 0; i < MONTHS; i++) {
        printf("%-12s $%.2f\n", month_names[sorted_months[i]], sorted_sales[i]);
    }
    printf("\n");
}

// print monthly sales report
void print_monthly_sales_report(double sales[]) {
    printf("Monthly Sales Report for 2024\n");
    printf("Month       Sales\n");
    //loop through all the months and print the sales for that month
    for (int i = 0; i < MONTHS; i++) {
        printf("%-12s $%.2f\n", month_names[i], sales[i]);
    }
    printf("\n");
}

int main() {
    //track sales
    double sales[MONTHS];

    // Open the input file for reading
    FILE *file = fopen("sales_report.txt", "r");
    if (file == NULL) {
        //catch no file found error
        printf("Could not open file 'sales_report.txt'.\n");
        //end program
        return 1;
    }
    
    // Read sales data from the file
    for (int i = 0; i < MONTHS; i++) {
        //read file data into sales array
        if (fscanf(file, "%lf", &sales[i]) != 1) {
            //catch invalid data error
            printf("Error: Invalid data in file.\n");
            fclose(file);
            return 1;
        }
    }
    
    // Close the file
    fclose(file);
    
    // Print reports
    print_monthly_sales_report(sales);
    print_sales_summary_report(sales);
    print_six_month_average(sales);
    print_sales_highest_to_lowest(sales);
    
    return 0;
}
