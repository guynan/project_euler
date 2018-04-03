! The number 3797 has an interesting property.
! Being prime itself, it is possible
! to continuously remove digits from left to right,
! and remain prime at each stage: 3797, 797, 97, and 7.
! Similarly we can work from right to left: 3797, 379, 37, and 3.

! Find the sum of the only eleven primes that are
! both truncatable from left to right and right to left.

! NOTE: 2, 3, 5, and 7 are not considered to be truncatable primes.

! Answer: 748317
! Project Euler: 37


program main

use euler

implicit none

        integer (kind=8), parameter :: PRIME_C = 11;
        integer (kind=8), parameter :: BASE = 10;
        integer (kind=8), parameter :: TWO = 2;
        integer (kind=8) :: c, sum, i;

        c = 0;
        sum = 0;
        i = 3;


        do while(.true.)

                if(truncatable_prime(i)) then

                        call inc(c, ONE);
                        call inc(sum, i);

                        if(c == PRIME_C) then
                                goto 24
                        endif
                endif

                call inc(i, TWO);

        end do


24      CONTINUE

        call printint(sum);


contains


        ! Establishes whether an integer is a truncatable prime. We do this
        ! efficiently by leveraging most of the work into
        ! `possibly_truncatable`, whereby we can check if a number is even
        ! remotely worth running through an expensive check to see if it is
        ! prime. We then check if it is truncatable from both L&R

        pure function truncatable_prime(i)

                integer (kind=8), intent(in) :: i;
                logical :: truncatable_prime

                truncatable_prime = .false.

                if(i < 10 .OR. (.NOT. possibly_truncatable(i))) then
                        return
                endif

                truncatable_prime = (right_trunc(i) .AND. left_trunc(i))

                return

        end function truncatable_prime


        pure function right_trunc(i)

                integer (kind=8), intent(in) :: i;
                integer (kind=8) :: tmp;
                logical :: right_trunc;

                tmp = i;
                right_trunc = .false.

                do while(tmp /= 0)

                        if(.NOT. isprime(tmp)) then
                                return;
                        endif

                        tmp = tmp / 10;

                end do

                right_trunc = .true.

        end function right_trunc


        ! Truncate from the left in a method that is much akin to how we do it
        ! in the `right_trunc` function.

        pure function left_trunc(i)

                integer (kind=8), intent(in) :: i;
                integer (kind=8) :: tmp;
                logical :: left_trunc

                tmp = i;
                left_trunc = .false.

                do while(tmp /= 0)

                        if(.NOT. isprime(tmp)) then
                                return;
                        endif

                        tmp = intrev(intrev(tmp) / 10);

                end do

                left_trunc = .true.

                return

        end function left_trunc


        ! For a number to be prime it must be odd, unless it is two. In this
        ! notion, we may reduce our search space by testing if any of the
        ! digits is even. If so, we know that this number is impossible to
        ! be a truncatable prime. This saves a lot of cycles as we don't need 
        ! to expensively check if numbers are prime or not if they aren't even
        ! in the realms of probability of being true.

        pure function possibly_truncatable(i)

                integer (kind=8), intent(in) :: i;
                integer (kind=8) :: tmp, end_d;
                logical :: possibly_truncatable, has_2;

                possibly_truncatable = .false.
                has_2 = .false.
                tmp = i;

                do while(tmp /= 0)

                        ! Check if the end digit is even, but allow one
                        ! occurance of two
                        end_d = mod(tmp, BASE);

                        if(mod(end_d, 2) == 0) then

                                if (end_d == 2) then

                                        if(has_2) then
                                                return;
                                        else
                                                has_2 = .true.
                                        endif 
                                else
                                        return;

                                endif
                        endif

                        tmp = tmp / BASE;
                end do
                
                possibly_truncatable = .true.

        end function possibly_truncatable


end program main

