

program main

        use ISO_FORTRAN_ENV

        integer (int64) :: maximum
        integer (int64) :: largest, i

        maximum = 600851475143_int64


        i = 1

        do while (i * i < maximum)

                if((mod(maximum, i) == 0) .AND. isprime(i)) then
                        largest = i
                endif

                i = i + 1

        end do


        print*, largest


contains
        
        function isprime (s)
                logical :: isprime
                integer (kind=8) :: s, i, top

                isprime = .false.  

                if(s <= 1) then
                        return
                end if

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

                return

        end function isprime


end program main
