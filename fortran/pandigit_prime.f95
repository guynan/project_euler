
 ! We shall say that an n-digit number is
 ! pandigital if it makes use of all the
 ! digits 1 to n exactly once. For
 ! example, 2143 is a 4-digit pandigital
 ! and is also prime. What is the largest
 ! pandigital prime that exists?
 !
 ! Answer: 7652413

program main

        use euler

implicit none

        ! The key here is noting that the greatest pandigit 1 - 9 is 987654321,
        ! though by use of the divisibility rule, by taking the sum over all
        ! the digits we note that all permutations of the maxima across
        ! 9******** and also 8*******, we note that their digital sums are 45
        ! and 36 respectively which means that they are both at least divisible
        ! by 3. Thus these can be excluded from the search as for the number
        ! to be prime it must not be divisible by anything aside from one and
        ! itself. We thus start at 7654321

        integer (int32), parameter :: MAXIMUM = 7654321

        integer (int32) :: i;

        i = MAXIMUM
24 &
        i = i - 2

        if ((.NOT. n_pandigit(i)) .OR. (.NOT. isprime(i))) goto 24

        call printint(i);


contains


        function n_pandigit(x)

                integer (int32) :: x, i, set_ints, bit_mask, len
                logical :: n_pandigit

                n_pandigit = .TRUE.
                set_ints = 0; bit_mask = 0; len = 0;
                i = x;

                do while (i > 0.AND. n_pandigit)
                        bit_mask = mod(i, 10); ! NOT A BIT MASK CHANGE NAME
                        n_pandigit = .NOT. BTEST(set_ints, bit_mask)
                        set_ints = IBSET(set_ints, bit_mask);

                        len = IOR(len, 1);
                        len = ISHFT(len, 1);
                        i = i / 10;

                end do

                n_pandigit = (len == set_ints)

        end function n_pandigit

end program main

