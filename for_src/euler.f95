
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


        function isprime (s)

                logical :: isprime
                integer (kind=8) :: s, i, top

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
        


end module euler

