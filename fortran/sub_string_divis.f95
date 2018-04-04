
! The number, 1406357289, is a 0 to 9 pandigital number because it is made up
! of each of the digits 0 to 9 in some order, but it also has a rather
! interesting sub-string divisibility property.

! Let d1 be the 1st digit, d2 be the 2nd digit, and so on. In this way, we
! note the following:

! d2d3d4=406 is divisible by 2
! d3d4d5=063 is divisible by 3
! d4d5d6=635 is divisible by 5
! d5d6d7=357 is divisible by 7
! d6d7d8=572 is divisible by 11
! d7d8d9=728 is divisible by 13
! d8d9d10=289 is divisible by 17
! Find the sum of all 0 to 9 pandigital numbers with this property.

! Project Euler: 43

! Answer: 16695334890 */

program main

use euler

implicit none

        ! Constants

        integer (int64), parameter :: START = 1023456789_i64
        integer (int64), parameter :: MAXIMUM = 4999999999_i64
        integer (int64), parameter :: PAN_STEP = 9;
        integer (int64), parameter :: BASE = 10;
        integer (int64), dimension(7) :: PRIMES;
        integer (int64) :: sum, i

        PRIMES = (/17, 13, 11, 7, 5, 3, 2 /)

        sum = 0;

        do i = START, MAXIMUM, PAN_STEP

                if(sub_str_divis(i) .AND. pandigital(i)) then
                        call inc(sum, i);
                endif

        end do

        call printint(sum);


contains


        pure function digital_sum(i)

                integer (int64), intent(in) :: i
                integer (int64) :: tmp, digital_sum;

                digital_sum = 0;
                tmp = i;

                do while(tmp /= 0)
                        call inc(digital_sum, mod(tmp, BASE)); 
                        tmp = tmp / BASE;
                end do

                return

        end function digital_sum


        ! This is very non reusably defined as whether or not the number, taken
        ! in sections of three numbers and assessing whether each of those
        ! numbers is divisible by a prime. However arbitrary, here it is;

        pure function sub_str_divis(x)

                integer (int64), intent(in) :: x;
                logical :: sub_str_divis;

                integer (int64) :: n, tmp, i;

                sub_str_divis = .false.;
                n = x;
                i = 1;

                do while(n > 1000)

                        tmp = mod(n, 1000);

                        if(mod(tmp, PRIMES(i)) /= 0) then
                                return;
                        endif

                        call inc(i, 1_i64);
                        n = n / 10;
                end do

                sub_str_divis = .true.;

                return

        end function sub_str_divis


        ! It sure ain't pretty, however, this is a semi efficient way of
        ! deducing whether a number `i` is pandigital or not

        pure function pandigital(i)

                integer (int64), intent(in) :: i
                integer (int64), dimension(10) :: pan
                integer (int64) :: tmp
                logical :: pandigital

                pandigital = .false.

                ! Zero the array
                pan = 0

                tmp = i

                do while(tmp /= 0)
                        call inc(pan(mod(tmp, 10) + 1), 1_i64);
                        tmp = tmp / 10;
                end do

                do tmp = 1, 10, 1

                        if(pan(tmp) /= 1) then
                                return;
                        endif
                end do

                pandigital = .true.

                return

        end function pandigital


end program main

