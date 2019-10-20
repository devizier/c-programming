#include <stdio.h>
#include <stdlib.h>

// Declare your rectangle structure here!
typedef struct _retire_info {
    int months;
    double contribution, rate_of_return;
} retire_info;

void calculate(retire_info info, int *currentAge, double *currentSavings) {
    for (int i = 0; i < info.months; i += 1) {

        int ageInYears = *currentAge / 12;
        int currentMonthInYear = *currentAge % 12;

        printf("Age %3d month %2d you have $%.2lf\n", ageInYears, currentMonthInYear, *currentSavings);

        double interest = *currentSavings * info.rate_of_return;
        double added = interest + info.contribution;
        *currentSavings += added;

        *currentAge += 1;
    }
}

void retirement(int startAge,
                double initial,
                retire_info working,
                retire_info retired) {

    int currentAge = startAge;
    double currentSavings = initial;

    // calculate working
    calculate(working, &currentAge, &currentSavings);
    // calculate retired
    calculate(retired, &currentAge, &currentSavings);

}

int main() {
    retire_info working = {489, 1000, 0.045/12};
    retire_info retired = {384, -4000, 0.01/12};
    retirement(327, 21345, working, retired);
    return 1;
}
