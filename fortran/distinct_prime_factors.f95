
! The first two consecutive numbers to have two distinct prime factors are:
!
! 14 = 2 × 7
! 15 = 3 × 5
!
! The first three consecutive numbers to have three distinct prime factors
! are:
!
! 644 = 2² × 7 × 23
! 645 = 3 × 5 × 43
! 646 = 2 × 17 × 19.
!
! Find the first four consecutive integers to have four distinct prime factors
! each. What is the first of these numbers?
!
! Project Euler: 47
!
! Answer: 134043


program main

        use euler

implicit none

        ! This code starts by picking a number and then adding to it to see if
        ! the number of factors is equal to the number that we are looking for.
        ! If so, it checks the next consecutive number to see if it too has the
        ! same property.  If in any event that it does not, but has passed the
        ! zero threshold, we can add the number that did pass the constraint
        ! and move one past that for we know that those integers have been
        ! check and will not contribute to a successful solution.

        integer (int32), parameter :: N_CONSEC = 4;
        integer (int32) :: c, i;

        c = 0; i = 0;

        do while (c /= N_CONSEC)

                call inc(i, (c + 1));
                c = 0;

                do while(count_factors(i + c) == N_CONSEC .AND. c < N_CONSEC)
                        call inc(c, 1);
                end do

        end do

        call printint(i);

contains


        ! We remove all factors of two so that we can iterate via two, by only
        ! checking the odd numbers henceforth. We also divide by the number
        ! which is a factor such that we arrive at our upper limit sooner. If
        ! `n` is equal to one, then this means that we successfully got all the
        ! prime factors. If not, then it must in fact be a prime, and thus we
        ! must add this for we don't iterate up to the original number itself

        function count_factors(n)
        
                integer (int32) :: count_factors, n, i;

                count_factors = intbool(.NOT. BTEST(n, 0));

                do while (.NOT. BTEST(n, 0)); n = ISHFT(n, -1); end do;

                i = 3;

                do while ((i * i) < n)

                        call inc(count_factors, intbool(mod(n, i) == 0));

                        do while (mod(n, i) == 0)
                                n = n / i;
                        end do

                        call inc(i, 2);
                end do 

                call inc(count_factors, intbool(n > 1));

        end function count_factors


        ! This function directly replicates the integer equivalence of booleans
        ! in C. This is solid functionality that it turns out I can't live
        ! without.

        pure function intbool(logical)
                
                integer (int32) :: intbool;
                logical, intent(in) :: logical

                intbool = merge(1, 0, (logical));

        end function intbool


end program main

