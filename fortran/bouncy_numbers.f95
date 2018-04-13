
! Working from left-to-right if no digit is exceeded by the digit to its left
! it is called an increasing number; for example, 134468.
!
! Similarly if no digit is exceeded by the digit to its right it is called a
! decreasing number; for example, 66420.
!
! We shall call a positive integer that is neither increasing nor decreasing a
! "bouncy" number; for example, 155349.
!
! Clearly there cannot be any bouncy numbers below one-hundred, but just over
! half of the numbers below one-thousand (525) are bouncy. In fact, the least
! number for which the proportion of bouncy numbers first reaches 50% is 538.
!
! Surprisingly, bouncy numbers become more and more common and by the time we
! reach 21780 the proportion of bouncy numbers is equal to 90%.
!
! Find the least number for which the proportion of bouncy numbers is exactly
! 99%.
!
! Project Euler: 112
!
! Answer: 1587000

program main

use euler

implicit none


        ! Constants

        integer (int64), parameter :: START = 21780
        integer (int64), parameter :: START_RATIO = 90
        integer (int64), parameter :: END_RATIO = 99

        integer (int64) :: n, i, tmp;

        i = START + 1;
        n = (START * START_RATIO) / 100;

        do while(.TRUE.)

                if ((.NOT. desc(i)) .AND. (.NOT. asc(i))) then
                        call inc(n, 1_int64);
                endif

                tmp = (i * END_RATIO) / 100;

                if(tmp == n .AND. (mod(i * END_RATIO, 100) == 0)) then
                        exit;
                endif

                call inc(i, ONE);

        end do

        call printint(i);


contains


        pure function desc(x)

                integer (int64), intent(in) :: x
                integer (int64) :: i, last
                logical :: desc
                desc = .FALSE.

                i = x
                
                last = mod(i, 10);
                call idiv(i, 10_int64);

                do while(i /= 0)
                        if(mod(i, 10) > last) then
                                return;
                        endif

                        last = mod(i, 10);
                        call idiv(i, 10_int64);
                end do

                desc = .true.;

        end function desc


        pure function asc(x)

                integer (int64), intent(in) :: x
                integer (int64) :: i, last
                logical :: asc
                asc = .FALSE.

                i = x
                
                last = mod(i, 10);
                call idiv(i, 10_int64);

                do while(i /= 0)
                        if(mod(i, 10) < last) then
                                return;
                        endif

                        last = mod(i, 10);
                        call idiv(i, 10_int64);
                end do

                asc = .true.;

        end function asc

end program main

