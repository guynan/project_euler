
 ! Take the number 192 and multiply it by each of 1, 2, and 3:
 !
 ! 192 × 1 = 192
 ! 192 × 2 = 384
 ! 192 × 3 = 576
 !
 ! By concatenating each product we get the 1 to 9 pandigital, 192384576. We
 ! will call 192384576 the concatenated product of 192 and (1,2,3)
 !
 ! The same can be achieved by starting with 9 and multiplying by 1, 2, 3, 4,
 ! and 5, giving the pandigital, 918273645, which is the concatenated product
 ! of 9 and (1,2,3,4,5).
 !
 ! What is the largest 1 to 9 pandigital 9-digit number that can be formed as
 ! the concatenated product of an integer with (1,2, ... , n) where n > 1?
 !
 ! Project Euler: 38
 !
 ! Answer: 932718654


program main

        use euler

implicit none

        integer (int32), parameter :: MAX_PROD = 9876;
        integer (int32), parameter :: MAX_DIGIT_LEN = 9;
        integer (int32), parameter :: FAULT_BIT_POS = 14;
        integer (int32), parameter :: PANDIGIT_BITM = Z'3FE';

        integer (int32) :: i, largest, tmp;

        largest = 0;

        do i = 2, MAX_PROD
                tmp = pandigital_mult(i);
                largest = merge(tmp, largest, (tmp > largest));
        end do

        print *, largest


contains

        ! This function takes an integer and concatenates its consecutive
        ! products with the previous number. We then test whether the largest
        ! number produced is pandigital--returning the produced number if true, 
        ! or returning zero if the number is no pandigital.

        pure function pandigital_mult(i)

                integer, intent(in) :: i;
                integer (int32) :: cat, prod, pandigital_mult;

                cat = i; prod = 2;

                do while (ceiling(log10(real(cat))) < MAX_DIGIT_LEN)
                        cat = concat(cat, prod * i);
                        call inc(prod, 1);
                end do

                pandigital_mult = merge(cat, 0, pandigital(cat));

        end function pandigital_mult


        ! This function concatenates a and b forming ab. Rather concisely, we
        ! take the number 'a' and multiply it by 10 to the power of how long
        ! the 'b' integer is.

        pure function concat(a, b)

                integer, intent(in) :: a, b;
                integer :: concat;

                concat = (a * (10 ** ceiling(log10(real(b))))) + b;

        end function concat


        ! This function initialises an integer where the bits are then used to
        ! represent the presence of digits in the number passed as an argument.
        ! For example, if the number has a '2' in it, then the second bit will
        ! be set. If the bit has already been toggled and there is a secondary
        ! appearance, then the fault bit--bit 14--will be set, and execution of
        ! the loop will stop. This is then compared against 0x3FE, which
        ! represents all numbers being set, which is a pandigital number.

        pure function pandigital(arg)

                integer (int32) :: num, set_ints, ld, pos;
                integer, intent(in) :: arg;
                logical :: pandigital;

                set_ints = 0; num = arg;

                do while (num /= 0 .AND. set_ints <= PANDIGIT_BITM)
                        ld = mod(num, 10)
                        pos = merge(FAULT_BIT_POS, ld, BTEST(set_ints, ld))
                        set_ints = IBSET(set_ints, pos);
                        num = num / 10;
                end do

                pandigital = (set_ints == PANDIGIT_BITM);

        end function pandigital

        ! write(*, '(B0)') set_ints; ! This is used to print binary

end program main

