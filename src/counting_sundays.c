
#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>


int32_t get_days_month(int32_t month, int32_t year);
int main(int argc, char** argv);

enum months {
        JAN = 1, FEB = 2, MAR = 3, APR = 4,
        MAY = 5, JUN = 6, JUL = 7, AUG = 8,
        SEP = 9, OCT = 10, NOV = 11, DEC = 12
};

enum days {
        MON, TUE, WED, THU, FRI, SAT, SUN
};

int main(int argc, char** argv)
{
        (void) argc;
        (void) argv;

        int32_t day = MON;
        int32_t count = 0;

        for(int32_t year = 1900; year <= 2000; year++){

                for(int i = JAN; i <= DEC; i++){

                        int32_t days_month = get_days_month(i, year);
                        for(int date = 1; date <= days_month; date++){

                                if(date == 1 && day == SUN && year >= 1901){
                                        count++;
                                }

                                day = (day == SUN) ? MON : day + 1;
                        }
                }
        }

        printf("%"PRId32"\n", count);

        return 0;

}

int32_t get_days_month(int32_t month, int32_t year)
{
        int days = 31;
        switch(month) {
                case SEP:
                        days = 30;
                        break;
                case APR:
                        days = 30;
                        break;
                case JUN:
                        days = 30;
                        break;
                case NOV:
                        days = 30;
                        break;
                case FEB:
                        if(year % 4 == 0 &&
                                (year % 1000 == 0 && year % 400 != 0)){
                                days = 29;
                        } else {
                                days = 28;
                        }
                        break;
                default:
                        break;
        }
        return days;

}

