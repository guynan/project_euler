 ! A composite is a number containing at least 
 ! two prime factors. For example, 15 = 3 × 5; 
 ! 9 = 3 × 3; 12 = 2 × 2 × 3.

 ! There are ten composites below thirty containing 
 ! precisely two, not necessarily distinct, prime 
 ! factors: 4, 6, 9, 10, 14, 15, 21, 22, 25, 26.

 ! How many composite integers, n < 10**8, have
 ! precisely two, not necessarily distinct, prime factors?

 ! Project Euler: 187 
 !
 ! Answer: 17427258 !/

program main

        use euler

implicit none

        integer (int32), parameter :: MAXIMUM = 100000000;
        integer (int32), parameter :: N_PRIMES = 3005000;
        integer (int32), allocatable :: primes(:);
        integer (int32) :: i, j, s_count, lim;
        integer (int64) :: tmp;

        lim = MAXIMUM / 2;

        allocate (primes(N_PRIMES));

        call init_primes(primes, lim);

        s_count = 0;

        outer: &
        do i = 1, N_PRIMES, 1

                if(primes(i) == 0) then
                        exit outer;
                endif

                inner: &
                do j = i, N_PRIMES, 1

                        tmp = primes(i);
                        tmp = tmp * primes(j);

                        if(tmp == 0 .OR. tmp >= MAXIMUM) then
                                exit inner;
                        endif

                        call inc(s_count, 1);

                end do inner

        end do outer

        call printint(s_count);

contains

        subroutine init_primes(primes, n)

                integer (int32), intent(out) :: primes(:);
                integer (int32), intent(in) :: n;
                integer (int32) :: i, c;
                primes = 0;

                c = 2;
                primes(1) = 2;

                do i = 3, n, 2

                        if(isprime(i)) then
                                primes(c) = i;
                                call inc(c, 1);
                        endif
                end do

        end subroutine init_primes


end program main

