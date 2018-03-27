
! Find the summation of primes under 2m

program main

use euler

implicit none

        integer, parameter :: MAXIMUM = 2000000
        
        integer (kind=8) :: n
        integer (kind=8) :: sumn = 2

        do n = 3, MAXIMUM, 1
                if(isprime(n)) then
                        call inc(sumn, n)
                endif
        end do

        print*, sumn

end program main
