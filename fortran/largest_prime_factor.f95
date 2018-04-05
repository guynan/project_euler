

program main

use euler
use ISO_FORTRAN_ENV

implicit none

        integer (int64), parameter :: maximum = 600851475143_int64;
        integer (int64) :: largest, i

        i = 1
        largest = 0

        do while (i ** 2 < maximum)

                if((mod(maximum, i) == 0) .AND. isprime(i)) then
                        largest = i
                endif

                call inc(i, 1_int64);

        end do

        call printint(largest);


end program main

