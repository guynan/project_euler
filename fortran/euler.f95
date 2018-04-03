
module euler

implicit none

        ! Functions defined here
        ! isprime, inc, intrev, is_palindrome

        ! Constants

        integer (kind=8), parameter :: ONE = 1

contains

        ! This is here because I really miss the '+=' operator from C
        ! Operates on TWO instances of 64 bit numbers.

        pure subroutine inc(base, offset)

                integer (kind=8), intent(out) :: base;
                integer (kind=8), intent(in) :: offset;

                base = base + offset;

                return

        end subroutine inc


        ! This subroutine is borne out of convenience for the native print
        ! method is usually overkill when one wishes to print an integer

        subroutine printint(i)
                
                integer (kind=8), intent(in) :: i

                write (*, '(I0)') i;

        end subroutine printint


        ! Reverses a 64-bit integer

        pure function intrev(x)

                integer (kind=8), intent(in) :: x
                integer (kind=8) :: intrev
                integer (kind=8) :: tmp
                
                intrev  = 0
                tmp = x;

                do while (tmp /= 0)
                        intrev = intrev * 10
                        call inc(intrev, mod(tmp, 10));
                        tmp = tmp / 10
                enddo

                return

        end function intrev


        ! Tests if a number is a Palindrome through an integer
        ! Reversal process. Operates on 64-bits

        function is_palindrome(x)

                integer (kind=8), intent(in) :: x;
                integer (kind=8) :: tmp;
                logical :: is_palindrome;

                tmp = x;
                is_palindrome = (intrev(tmp) == tmp);

                return

        end function is_palindrome


        pure function isprime (s)

                logical :: isprime
                integer (kind=8), intent(in) :: s
                integer (kind=8) :: i, top

                isprime = .false.  

                if(s <= 1) then
                        return
                endif

                top = int(sqrt(real(s))) + 1

                do i = 2, top + 1, 1

                        if (i == top) then
                                isprime = .true.
                                exit
                        end if

                        if(mod(s, i) == 0) then
                                exit
                        end if

                end do

        end function isprime


        ! Uses Euler's method for calculating the greatest common divisor

        pure function gcd(a, b)

                integer (kind=8), intent(in) :: a, b
                integer (kind=8) :: gcd, tmp, y

                gcd = a
                y = b

                ! Note could make gcd = x
                do while(y /= 0)
                        tmp = mod(gcd, y)
                        gcd = y
                        y = tmp

                end do

        end function gcd


        ! Get the length of the digit as if it were a string

        pure function intlen(i)

                integer (kind=8), intent(in) :: i;
                integer (kind=8) :: intlen, tmp;

                intlen = 1;
                tmp = i;

                ! Else len will be 2
                if(i < 10) then
                        return
                endif

                intlen = 0

                do while(tmp /= 0)
                        tmp = tmp / 10;
                        call inc(intlen, ONE);
                end do

        end function intlen


end module euler

