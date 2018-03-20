
! If we take 47, reverse and add, 47 + 74 = 121, which is palindromic.

! Not all numbers produce palindromes so quickly. For example,

! 349 + 943 = 1292,
! 1292 + 2921 = 4213
! 4213 + 3124 = 7337

! That is, 349 took three iterations to arrive at a palindrome.
! 
! Although no one has proved it yet, it is thought that some numbers, 
! like 196, never produce a palindrome. A number that never 
! forms a palindrome through the reverse and add process is called
! a Lychrel number. Due to the theoretical nature of these numbers, 
! and for the purpose of this problem, we shall assume that a number 
! is Lychrel until proven otherwise. In addition you are given 
! that for every number below ten-thousand, it will either (i) 
! become a palindrome in less than fifty iterations, or, (ii) no one, 
! with all the computing power that exists, has managed so far 
! to map it to a palindrome. In fact, 10677 is the first 
! number to be shown to require over fifty iterations 
! before producing a palindrome: 
! 4668731596684224866951378664 (53 iterations, 28-digits).
! 
! Surprisingly, there are palindromic numbers that are 
! themselves Lychrel numbers; the first example is 4994.

! How many Lychrel numbers are there below ten-thousand?

! Project Euler: 55 
!
! Answer: 249 


program main

implicit none

        integer, parameter :: MAX_ITER = 50;
        integer, parameter :: MAXIMUM = 10000;
        integer (kind=16), parameter :: ONE = 1;

        integer (kind=16) :: c = 0


        integer (kind=16) :: i
        do i = 1, MAXIMUM, 1

                if(is_lycherl(i)) then
                        call inc(c, ONE)
                endif

        enddo

        print*, c


contains


        subroutine inc(base, offset)

                integer (kind=16), intent(out) :: base;
                integer (kind=16), intent(in) :: offset;
                integer (kind=16) :: tmp;

                tmp = offset;
                base = base + tmp;

                return

        end subroutine inc


        function intrev(x)

                integer (kind=16), intent(in) :: x
                integer (kind=16) :: intrev
                integer (kind=16) :: tmp
                
                intrev  = 0
                tmp = x;

                do while (tmp /= 0)
                        intrev = intrev * 10
                        call inc(intrev, mod(tmp, 10));
                        tmp = tmp / 10
                enddo

                return

        end function intrev


        function is_lycherl(x)

                integer (kind=16), intent(in) :: x
                integer (kind=16) :: iterc
                integer (kind=16) :: n
                logical :: is_lycherl

                is_lycherl = .true.
                iterc = 1
                n = x

                call inc(n, intrev(n))

                do while(iterc < MAX_ITER)

                        if(is_palindrome(n)) then
                                is_lycherl = .false.
                                exit
                        endif

                        call inc(n, intrev(n))
                        call inc(iterc, ONE)
                                
                enddo

                return

        end function is_lycherl


        function is_palindrome(x)

                integer (kind=16), intent(in) :: x;
                integer (kind=16) :: tmp;
                logical :: is_palindrome;

                tmp = x;
                is_palindrome = (intrev(x) == x);

                return

        end function is_palindrome


end program main

