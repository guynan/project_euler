
program main

use euler

implicit none


        integer (kind=8), parameter :: MAXIMUM = 999;
        integer (kind=8), parameter :: START = 100;
        integer (kind=8) :: i, j, prod, longest;

        outer: &
        do i = START, MAXIMUM, 1

                inner: &
                do j = START, MAXIMUM, 1

                        prod = i * j;

                        if(prod < longest) then
                                cycle
                        endif

                        if(is_palindrome(prod)) then
                                longest = prod;
                        endif

                end do inner

        end do outer

        call printint(longest);


end program main

