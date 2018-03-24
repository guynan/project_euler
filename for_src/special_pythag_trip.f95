
! A Pythagorean triplet is a set of 
! three natural numbers, a < b < c, for which,
! a^2 + b^2 = c^2
! For example, 32 + 42 = 9 + 16 = 25 = 52.
! There exists exactly one Pythagorean triplet 
! for which a + b + c = 1000.
! Find the product abc.
! 
! Project Euler: 9
! Answer: 31875000


program main

use euler

implicit none

        ! a + b + c = 1000
        ! 1000 - (a + b) = c

        integer (kind=8), parameter :: PERIMETER = 1000
        integer (kind=8) :: a, b, c

        outer: do a = 1, PERIMETER, 1

                inner: do b = 1, PERIMETER, 1
                        
                        c = PERIMETER - (a + b)

                        if(c <= 0) then
                                exit inner
                        endif

                        if(pythag_triplet(a, b, c)) then
                                exit outer
                        endif

                end do inner
        
        end do outer

        print*, a * b * c


contains


        ! Test whether a triple is pythagorean - the long way

        pure function pythag_triplet(a, b, c)

                integer (kind=8), intent(in) :: a, b, c
                logical :: pythag_triplet

                pythag_triplet = (a ** 2 + b ** 2 == c ** 2)

                return

        end function pythag_triplet


        ! It can be shown that;
        !
        ! 500 = (a + b) - (a*b) / 1000
        !
        ! In this notion, we can check if a*b is divisible
        ! by 1000 and then if the above equation holds
        !
        ! More generally, Perimeter / 2 = (a + b) - (a * b) / perimeter
        !
        ! @param: PERIMETER must be defined to 

        pure function special_pythag(a, b)

                integer (kind=8), intent(in) :: a, b
                integer (kind=8) :: prod
                logical :: special_pythag

                special_pythag = .false.

                prod = a * b
                
                if(mod(prod, PERIMETER) /= 0) then
                        return
                endif

                special_pythag = (PERIMETER / 2 == (a + b) - prod / PERIMETER)

                return

        end function special_pythag


end program main

