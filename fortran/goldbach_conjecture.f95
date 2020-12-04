
 ! It was proposed by Christian Goldbach that every odd composite number can be
 ! written as the sum of a prime and twice a square.
 !
 ! 9 = 7 + 2×1^2
 ! 15 = 7 + 2×2^2
 ! 21 = 3 + 2×3^2
 ! 25 = 7 + 2×3^2
 ! 27 = 19 + 2×2^2
 ! 33 = 31 + 2×1^2
 !
 ! It turns out that the conjecture was false.
 !
 ! What is the smallest odd composite that cannot be written as the sum of a
 ! prime and twice a square?
 !
 ! Answer: 5777
 !
 ! Project Euler: 46

program main

        use euler

implicit none

        integer (int32) :: i = 1;

24 &
        i = i + 2;

        if(isprime(i) .OR. satisfies_goldbach(i)) goto 24;

        print*, i

contains

        ! This function generates twice squares and subtracts this from the
        ! test number. If the number, once subtracted, is a prime, then this
        ! satisfies Goldbach's conjecture. Otherwise the function terminates
        ! when there exists no twice square that may be subtracted positively.

        pure logical function satisfies_goldbach(n)

                integer (int32), intent(in) :: n
                integer (int32) :: i, sqr;

                satisfies_goldbach = .FALSE.
                i = 1; sqr = 2;

                do while (sqr < n .AND. .NOT. satisfies_goldbach)

                        satisfies_goldbach = isprime(n - sqr);
                        i = i + 1
                        sqr = 2 * (i**2);

                end do

        end function satisfies_goldbach

end program main

