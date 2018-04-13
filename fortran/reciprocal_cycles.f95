
program main

use euler

implicit none


        integer (int64), parameter :: MAXIMUM = 1000;
        integer (int64), parameter :: BASE = 10;
        integer (int64) :: i, len_, n, tmp;

        len_ = 0;

        do i = 1, MAXIMUM, 2

                tmp = reciprocal_count(i);

                if(tmp > len_) then
                        len_ = tmp;
                        n = i;
                endif

        end do

        call printint(n)


contains


        pure function reciprocal_count(i)

                integer (int64), intent(in) :: i;
                integer (int64) :: init_rem, rem;
                integer (int64) :: reciprocal_count;

                reciprocal_count = 1;

                if(mod(i, 5) == 0) then
                        return
                endif

                init_rem = 1
                rem = mod(BASE, i);

                do while(rem /= 0 .AND. rem /= init_rem)
                        rem = mod((BASE * rem), i);
                        call inc(reciprocal_count, ONE);
                end do

        end function reciprocal_count


end program main
