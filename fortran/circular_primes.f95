

program main

use euler

implicit none

        integer (kind=8), parameter :: MAXIMUM = 1000000
        integer (kind=8), parameter :: BASE = 10
        integer (kind=8) :: i, count;

        count = 1

        ! We iterate by adding two for we know it will be an odd number
        do i = 3, MAXIMUM, 2

                if(circular_prime(i)) then
                        call inc(count, ONE);
                endif
        end do

        call printint(count);


contains


        ! Circulates each integer until it either isn't a prime or if
        ! it is equal to itself

        pure function circular_prime(i)

                integer (kind=8), intent(in) :: i;
                integer (kind=8) :: tmp;
                logical :: circular_prime;

                circular_prime = .false.

                if(.NOT.possibly_circular(i)) then
                        return
                endif

                if(.NOT.isprime(i)) then
                        return
                endif

                tmp = i

                do while(.true.)

                        tmp = circulate(tmp)

                        if(.NOT. isprime(tmp)) then
                                return
                        endif

                        if(tmp == i) then
                                exit
                        endif
                end do

                circular_prime = .true.

                return

        end function circular_prime


        ! Simply puts the number which is at the end of the number to the front

        pure function circulate(i)

                integer (kind=8), intent(in) :: i;
                integer (kind=8) :: circulate;

                if(i < 10) then
                        circulate = i;
                        return
                endif

                circulate = (mod(i, BASE) * BASE ** (intlen(i) - 1) + i) / BASE

        end function circulate


        ! For a number to be prime it must be odd, unless it is two. In this
        ! notion, we may reduce our search space by testing if any of the
        ! digits is even. If so, we know that this number is impossible to
        ! be a circular prime. This saves a lot of cycles as we don't need to
        ! expensively check if numbers are prime or not if they aren't even
        ! in the realms of probability of being true.

        pure function possibly_circular(i)

                integer (kind=8), intent(in) :: i;
                integer (kind=8) :: tmp;
                logical :: possibly_circular;

                possibly_circular = .false.
                tmp = i;

                do while(tmp /= 0)

                        if(mod(mod(tmp, BASE), 2) == 0) then
                                return
                        endif

                        tmp = tmp / BASE;
                end do
                
                possibly_circular = .true.

        end function possibly_circular


end program main

