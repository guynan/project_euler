
program main

use euler

implicit none


        ! Constants
        integer (kind=8), parameter :: MAXIMUM = 1600000
        integer (kind=8), parameter :: BASE = 10

        integer (kind=8), dimension(10) :: facts
        integer (kind=8) :: i, last, sum;
        
        sum = 0;
        last = 1;

        facts(1) = 1 
        do i = 2, 10, 1
                facts(i) = last * (i - 1);
                last = facts(i);
        end do

        do i = 5 , MAXIMUM, 1

                if(i == digital_factorial_sum(i)) then
                        call inc(sum, i);
                endif
        end do

        call printint(sum);

contains


        ! For each digit in the number, we sum the factorial of said digit

        pure function digital_factorial_sum(i)

                ! Define in and out vars
                integer (kind=8), intent(in) :: i
                integer (kind=8) :: digital_factorial_sum

                ! Locals
                integer (kind=8) :: tmp;

                digital_factorial_sum = 0;
                tmp = i;

                do while(tmp /= 0)

                        call inc(digital_factorial_sum, &
                                        facts(mod(tmp, BASE) + 1));
                        tmp = tmp / BASE;
                end do

        end function digital_factorial_sum


end program main

