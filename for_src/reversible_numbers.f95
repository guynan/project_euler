program main


use euler


implicit none


        ! Constants
        integer (kind=8), parameter :: MAXIMUM = 1000000000
        integer (kind=8), parameter :: BASE = 10

        integer (kind=8) :: n, i

        n = 0

        do i = 11, MAXIMUM, 2

                if(is_reversible(i)) then
                        call inc(n, ONE)
                end if
                
        end do

        n = n * 2

        print*, n

contains

        pure function is_reversible(i)

                integer (kind=8), intent(in) :: i
                logical :: is_reversible

                integer (kind=8) :: rev

                ! We know that intrev must be a pure function by 
                ! definition thus `i` will not be modified.
                rev = intrev(i)

                is_reversible = .false.

                if(mod(rev, 2) /= 0) then
                        return
                endif

                is_reversible = only_odds(rev + i)

                return

        end function is_reversible


        pure function only_odds(x)
                
                integer (kind=8), intent(in) :: x
                logical :: only_odds

                integer (kind=8) :: i

                i = x

                ! Innocent until proven guilty
                only_odds = .true.

                do while(i /= 0)

                        if (mod(mod(i, BASE), 2) == 0) then
                                only_odds = .false.
                                exit
                        endif

                        i = i / BASE

                end do

                return

        end function only_odds


end program main
