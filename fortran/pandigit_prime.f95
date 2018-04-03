
program main

use euler

implicit none

        integer (kind=8), parameter :: MAXIMUM = 7654321

        integer (kind=8) :: i 

        do i = MAXIMUM, 0, -2
                if(pandigital(i) .AND. isprime(i)) then
                        exit
                endif
        end do

        call printint(i);


contains

        
        ! It sure ain't pretty, however, this is a semi efficient way of
        ! deducing whether a number `i` is pandigital or not

        pure function pandigital(i)

                integer (kind=8), intent(in) :: i
                integer (kind=8) :: tmp, dig, len_
                integer (kind=8), dimension(:), allocatable :: pan
                logical :: pandigital
                len_ = intlen(i);

                allocate(pan(len_));

                pandigital = .false.

                ! Zero the array
                do tmp = 1, len_ -1, 1
                        pan(tmp) = 0
                end do

                tmp = i

                do while(tmp /= 0)
                        dig = (mod(tmp, 10))

                        if(dig == 0) then
                                GOTO 24
                        endif

                        call inc(pan(dig), ONE);
                        tmp = tmp / 10
                end do

                do tmp = 1, len_ -1, 1

                        if(pan(tmp) /= 1) then
                                GOTO 24
                        endif
                end do

                pandigital = .true.

        24 &
        CONTINUE

                deallocate(pan)

                return

        end function pandigital


end program main

