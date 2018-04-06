

program main

        use ISO_FORTRAN_ENV

implicit none


        ! Rearrangement using a + b + c = p; a^2 + b^2 = c^2 gives us;
        ! b = (p^2 - 2pa)/(2p - 2a)
        ! So if we iterate up to p <= 1000, and across all a; for a < b;
        ! the solution for b should be natural if there is a solution

        integer (int64), parameter :: MAXIMUM = 1000;
        integer (int64) :: a, p, num_sol, max_sol, largest;

        num_sol = 0
        largest = 0
        max_sol = 0

        OUTER: &
        do p = 2, MAXIMUM, 1

                num_sol = 0

                INNER: &
                do a = 2, p/2, 1

                        if(mod(p**2 - 2*p*a, (2*(p - a))) == 0) then
                                num_sol = num_sol + 1;
                        endif

                end do inner

                if(num_sol > max_sol) then
                        max_sol = num_sol;
                        largest = p;
                endif

        end do outer

        print*,(largest);


end program main
