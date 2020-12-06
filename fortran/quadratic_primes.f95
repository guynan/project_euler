
! Quadratic Primes
!
! Project Euler: 27
!
! Answer: -59231

program main

        use euler

implicit none

        integer (int32) :: chain, a, b;
        integer (int32) :: product, longest;
        integer (int32), parameter :: MAX_ = 1000;
        integer (int32), parameter :: MIN_ = -999;

        do a = MIN_, MAX_, 2

                do b = a, MAX_, 2

                        chain = consecprimes(a, b);

                        if(chain > longest) then
                                longest = chain
                                product = a * b
                        end if
                end do

        end do

        print*, product


contains


        pure function consecprimes(a, b)

                integer (int32) :: n, consecprimes;
                integer (int32), intent(in) :: a, b;

                n = 1; consecprimes = 0;

                do while(isprime(quad_f(a, b, n)))
                        consecprimes = consecprimes + 2;
                        n = n + 2;
                end do

        end function consecprimes


        ! Quadratic function

        pure function quad_f(a, b, n)

                integer (int32), intent(in) :: a, b, n;
                integer (int32)  :: quad_f;

                quad_f = (n ** 2) + (a * n) + b;

        end function quad_f

end program main

