
 ! Find the unique positive integer whose square has the form
 ! 1_2_3_4_5_6_7_8_9_0,
 ! where each "_" is a single digit.
 !
 ! Project Euler: 206 
 ! Answer: 1389019170


program main

        use euler

implicit none

        integer (int64) :: i, MIN_RES = 1020304050607080900_i64;

        i = floor(sqrt(dble(MIN_RES)))

        do while(.TRUE.)
                if(concealed_sqr(i*i)) then
                        goto 24;
                endif

                i = i + 1
        end do

24 &
        print *, i


contains

        pure function concealed_sqr(tmp)

                integer (int64), intent(in) :: tmp;
                integer (int64) :: a, i;
                logical :: concealed_sqr;

                concealed_sqr = (mod(tmp, 10) == 0)
                i = tmp / 100;

                a = 9;
                do while(i > 0 .AND. concealed_sqr)
                        concealed_sqr = (mod(i, 10) == a);
                        i = i / 100;
                        a = a - 1;
                end do
        
        end function concealed_sqr


end program main

