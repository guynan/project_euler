

program main

implicit none


        integer, parameter :: N_DIVISORS = 500
        integer, parameter :: ONE = 1

        print*, max_tri_divis(N_DIVISORS)


contains

        ! This is here because I really miss the '+=' operator from C
        ! Operates on TWO instances of 64 bit numbers.

        pure subroutine inc(base, offset)

                integer, intent(out) :: base
                integer, intent(in) :: offset

                base = base + offset

                return

        end subroutine inc


        ! Calculate what Triangle number is the first to have in excess of
        ! `m` divisors 
 
        pure function max_tri_divis(m)

                integer, intent(in) :: m
                integer :: max_tri_divis
                integer :: i, tri

                i = 3 
                tri = 3 

                do while (.true.)
                        if (numdivis(tri) > m) then
                                max_tri_divis = tri
                                exit
                        endif

                        call inc(tri, i)
                        call inc(i, ONE)

                end do

                return

        end function max_tri_divis


        ! Calculate the number of divisors for a given number `x` by
        ! by searching up to the square and multiplying that count by 2

        pure function numdivis(x)
        
                integer, intent(in) :: x
                integer :: numdivis

                ! local
                integer :: i

                i = 1
                numdivis = 0

                do while ((i ** 2) < x)

                        if (mod(x, i) == 0) then
                                call inc(numdivis, ONE)
                        endif

                        call inc(i, ONE)

                end do

                numdivis = 2 * numdivis

                return
        
        end function numdivis


end program main

