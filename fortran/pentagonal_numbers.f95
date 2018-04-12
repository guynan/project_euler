

program main

use euler

implicit none

        integer (int64) :: a, b, pa, pb;
        a = 5

        OUTER: &
        do while(.TRUE.)

                pa = a;
                call pent(pa);

                INNER: &
                do b = 5, a/2, 1

                        pb = b;
                        call pent(pb);

                        if(pentagonal(pa-pb) .AND. pentagonal(pb+pa)) then
                                exit OUTER;
                        endif

                end do INNER

                call inc(a, 1_int64);

        end do OUTER

        call printint(pa-pb);


contains


        pure subroutine pent(x)

                integer (int64), intent(inout) :: x;
                x = (3 * x**2 - x)/2;

        end subroutine pent


        ! Utilise the fact that we can test if a number is pentagonal or not by
        ! using: 24x + 1 == y;
        ! Where y is a perfect square. AND, for non generalised solutions of
        ! n >= 0, we also must qualify that (24x + 1)**0.5 % 6 == 5

        pure function pentagonal(x)

                integer (int64), intent(in) :: x;
                integer (int64) :: tmp;
                logical :: pentagonal;

                tmp = 24 * x + 1;
                
                pentagonal = (perfect_square(tmp) .AND. &
                        mod(int(sqrt(real(tmp))), 6) == 5)

        end function pentagonal


end program main

