
module euler

        use ISO_FORTRAN_ENV
        use ISO_C_BINDING

implicit none

        ! Functions defined here
        ! isprime, inc, intrev, is_palindrome

        ! Constants

        integer (int64), parameter :: ONE = 1

        ! Integer kind specifiers

        integer (int64), parameter :: i8 = INT8;
        integer (int64), parameter :: i16 = INT16;
        integer (int64), parameter :: i32 = INT32;
        integer (int64), parameter :: i64 = INT64;
        integer (int64), parameter :: i128 = C_INT128_T;

        ! Interfaces

        interface inc
                module procedure inc_64, inc_128
        end interface inc

        interface intlen
                module procedure intlen_64, intlen_128
        end interface intlen

contains

        ! This is here because I really miss the '+=' operator from C
        ! Operates on TWO instances of 64 bit numbers.

        pure subroutine inc_64(base, offset)

                integer (int64), intent(out) :: base;
                integer (int64), intent(in) :: offset;

                base = base + offset;

                return

        end subroutine inc_64


        pure subroutine inc_128(base, offset)

                integer (kind=C_INT128_T), intent(out) :: base;
                integer (kind=C_INT128_T), intent(in) :: offset;

                base = base + offset;

                return

        end subroutine inc_128


        ! This subroutine is borne out of convenience for the native print
        ! method is usually overkill when one wishes to print an integer

        subroutine printint(i)
                
                integer (int64), intent(in) :: i

                write (*, '(I0)') i;

        end subroutine printint


        ! Reverses a 64-bit integer

        pure function intrev(x)

                integer (int64), intent(in) :: x
                integer (int64) :: intrev
                integer (int64) :: tmp
                
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

                integer (int64), intent(in) :: x;
                integer (int64) :: tmp;
                logical :: is_palindrome;

                tmp = x;
                is_palindrome = (intrev(tmp) == tmp);

                return

        end function is_palindrome


        pure function isprime (s)

                logical :: isprime
                integer (int64), intent(in) :: s
                integer (int64) :: i, top

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

                integer (int64), intent(in) :: a, b
                integer (int64) :: gcd, tmp, y

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

        pure function intlen_64(i)

                integer (int64), intent(in) :: i;
                integer (int64) :: intlen_64, tmp;

                intlen_64 = 1;
                tmp = i;

                do while(tmp >= 10)
                        tmp = tmp / 10;
                        call inc(intlen_64, 1_i64);
                end do

        end function intlen_64


        pure function intlen_128(i)

                integer (kind=C_INT128_T), intent(in) :: i;
                integer (kind=C_INT128_T) :: intlen_128, tmp;

                intlen_128= 1;
                tmp = i;

                do while(tmp >= 10)
                        tmp = tmp / 10;
                        call inc(intlen_128, 1_i128);
                end do

        end function intlen_128


end module euler

