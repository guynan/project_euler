
module euler

        use ISO_FORTRAN_ENV
        use ISO_C_BINDING

implicit none

        ! Functions defined here
        ! isprime, inc, intrev, is_palindrome, is_natural

! Constants

        ! Purely a construction of convenience
        integer (int64), parameter :: ONE = 1
        real, parameter :: NATURAL_THRESHOLD = 0.0005;

! Integer kind specifiers

        integer (int64), parameter :: i8 = INT8;
        integer (int64), parameter :: i16 = INT16;
        integer (int64), parameter :: i32 = INT32;
        integer (int64), parameter :: i64 = INT64;
        integer (int64), parameter :: i128 = C_INT128_T;

! Interfaces

        ! Immeadiate addition
        interface inc
                module procedure inc_32, inc_64, inc_128
        end interface inc

        ! Immeadiate division
        interface idiv
                module procedure idiv_64, idiv_128
        end interface idiv

        ! Immeadiate Multiplication
        interface imult
                module procedure imult_64, imult_128
        end interface imult

        interface intlen
                module procedure intlen_64, intlen_128
        end interface intlen

        interface intrev
                module procedure intrev64, intrev32
        end interface intrev

        interface isprime
                module procedure isprime_32, isprime_64
        end interface isprime

        interface printint
                module procedure printint_32, printint_64;
        end interface printint


        interface
		!standard C library qsort
                subroutine qsort(array,elem_count,elem_size,compare) bind(C,name="qsort")
                        import
                        type(c_ptr),value :: array
                        integer(c_size_t),value :: elem_count
                        integer(c_size_t),value :: elem_size
                        type(c_funptr), value :: compare
                        !int(*compare)(const void *, const void *)
                end subroutine qsort
        end interface

contains

        ! This is here because I really miss the '+=' operator from C
        ! Operates on TWO instances of 64 bit numbers.

        pure subroutine inc_32(base, offset)

                integer (int32), intent(out) :: base;
                integer (int32), intent(in) :: offset;

                base = base + offset;
                return

        end subroutine inc_32


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


        ! Division immediate; base /= offset;

        pure subroutine idiv_64(base, offset)

                integer (int64), intent(out) :: base;
                integer (int64), intent(in) :: offset;

                base = base / offset;
                return

        end subroutine idiv_64


        pure subroutine idiv_128(base, offset)

                integer (kind=C_INT128_T), intent(out) :: base;
                integer (kind=C_INT128_T), intent(in) :: offset;

                base = base / offset;
                return

        end subroutine idiv_128


        ! Multiplication immeadiate; base *= offset

        pure subroutine imult_64(base, offset)

                integer (int64), intent(out) :: base;
                integer (int64), intent(in) :: offset;

                base = base * offset;
                return

        end subroutine imult_64


        pure subroutine imult_128(base, offset)

                integer (kind=C_INT128_T), intent(out) :: base;
                integer (kind=C_INT128_T), intent(in) :: offset;

                base = base * offset;
                return

        end subroutine imult_128


        ! This subroutine is borne out of convenience for the native print
        ! method is usually overkill when one wishes to print an integer

        subroutine printint_64(i)
 
                integer (int64), intent(in) :: i
                write (*, '(I0)') i;

        end subroutine printint_64

        subroutine printint_32(i)

                integer (int32), intent(in) :: i
                write (*, '(I0)') i;

        end subroutine printint_32

        ! Reverses a 64-bit integer

        pure function intrev64(x)

                integer (int64), intent(in) :: x
                integer (int64) :: intrev64
                integer (int64) :: tmp

                intrev64  = 0
                tmp = x;

                do while (tmp /= 0)
                        intrev64 = intrev64 * 10
                        call inc(intrev64, mod(tmp, 10));
                        tmp = tmp / 10
                enddo

                return

        end function intrev64


        ! Reverse a 32-bit integer

        pure function intrev32(x)

                integer (int32), intent(in) :: x
                integer (int32) :: intrev32
                integer (int32) :: tmp

                intrev32  = 0
                tmp = x;

                do while (tmp /= 0)
                        intrev32 = intrev32 * 10
                        call inc(intrev32, mod(tmp, 10));
                        tmp = tmp / 10
                enddo

                return

        end function intrev32

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


        ! Brute force approach to distinguishing primes

        pure function isprime_64 (s)

                integer (int64), intent(in) :: s
                integer (int64) :: i, top
                logical :: isprime_64

                isprime_64 = .NOT. (s < 2 .OR. mod(s, 2) == 0);

                top = int(sqrt(real(s)));
                i = 3;

                do while(isprime_64 .AND. i <= top)
                        isprime_64 = (mod(s, i) /= 0);
                        i = i + 2;
                end do

                isprime_64 = (isprime_64 .OR. s == 2);

                return

        end function isprime_64


        pure function isprime_32 (s)

                integer (int32), intent(in) :: s
                integer (int32) :: i, top
                logical :: isprime_32

                isprime_32 = .NOT. (s < 2 .OR. mod(s, 2) == 0);

                top = int(sqrt(real(s)));
                i = 3;

                do while(isprime_32 .AND. i <= top)
                        isprime_32 = (mod(s, i) /= 0);
                        i = i + 2;
                end do

                isprime_32 = (isprime_32 .OR. s == 2);

                return

        end function isprime_32


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
                        call idiv(tmp, 10_int64);
                        call inc(intlen_64, 1_i64);
                end do

        end function intlen_64


        pure function intlen_128(i)

                integer (kind=C_INT128_T), intent(in) :: i;
                integer (kind=C_INT128_T) :: intlen_128, tmp;

                intlen_128= 1;
                tmp = i;

                do while(tmp >= 10)
                        call idiv(tmp, 10_i128);
                        call inc(intlen_128, 1_i128);
                end do

        end function intlen_128


        ! Checks if there is a natural result of the square root

        pure function perfect_square(x)

                integer (int64), intent(in) :: x;
                integer (int64) :: tmp;
                logical :: perfect_square;

                tmp = int(sqrt(real(x)));
                perfect_square = ((tmp * tmp) == x);

        end function perfect_square


        ! This is an immensely dirty way of checking whether a number is
        ! natural. This works by seeing whether the decimal part of the number
        ! is less than the NATURAL_THRESHOLD which is somwhat arbitrarily
        ! defined as about 0.0005. Works, but isn't pretty

        pure function is_natural(x)

                real, intent(in) :: x;
                logical :: is_natural;

                is_natural = (abs(x - real(nint(x))) < NATURAL_THRESHOLD);

        end function is_natural


end module euler

