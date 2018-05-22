
program main

use euler

implicit none

        ! This one is done by a pen and paper reduction of the problem. I
        ! found that I could represent the right corner trivially as the
        ! number of what iteration of square it was, squared. The subsequent
        ! results were as follows;
        !
        ! S0 = n**2;
        ! S1 = n**2 - (n - 1);
        ! S2 = n**2 - 2(n - 1);
        ! S3 = n**2 - 3(n - 1);
        !
        ! Thus, our formula for the sum of all of these 'rings' in the square
        ! is subsequently: 4n**2 - 6(n-1). Note however, this solution is for
        ! n in reals > 1

        integer (int64), parameter :: MAX_N = 1001;
        integer (int64) :: sum_diag, n;

        sum_diag = 1;

        do n = 3, MAX_N, 2
                sum_diag = sum_diag + outer_spiral_sum(n);
        end do

        call printint(sum_diag);

contains

        pure function outer_spiral_sum(n)

                integer (int64), intent(in) :: n;
                integer (int64) :: outer_spiral_sum;

                outer_spiral_sum = (4 * n ** 2) - 6 * n + 6;

        end function outer_spiral_sum


end program main

