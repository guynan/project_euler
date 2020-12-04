
 ! The decimal number, 585 = 10010010012
 ! (binary), is palindromic in both bases.
 !
 ! Find the sum of all numbers, less than
 ! one million, which are palindromic in
 ! base 10 and base 2.
 !
 ! Project Euler: 36
 ! Answer: 872187

program main

        use euler

implicit none

        integer (int32), parameter :: MAX_N = 1000000;
        integer (int32) :: i, sum;

        sum = 0

        do i = 1, MAX_N
                if(intrev(i) == i .and. binrev(i) == i) sum = sum + i
        end do

        print*, sum


contains

        ! This function works the same as the base 10 one; we start with a
        ! blank integer, and read results from one end, appending to the other

        function binrev(x)

                integer (int32) :: binrev, x, n
                binrev = 0;
                n = x

                do while (n > 0)
                        binrev = IEOR(ISHFT(binrev, 1), IAND(n, 1));
                        n = ISHFT(n, -1);

                end do

        end function binrev


end program main

