

program main

use euler

implicit none


        integer (int64), parameter :: MAXIMUM = 100;
        integer (int64) :: sqr_sum, sum_, i;

        sqr_sum = 0;
        sum_ = 0;

        do i = 0, MAXIMUM, 1
                call inc(sqr_sum, i**2);
                call inc(sum_, i);
        end do

        call printint(sum_**2 - sqr_sum);


end program main
