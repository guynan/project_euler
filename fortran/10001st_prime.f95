

program main

        use ISO_FORTRAN_ENV

        integer (int64) :: primec, i

        i = 1
        primec = 0

        do
                if(isprime(i)) then
                        primec = primec + 1
                endif

                if(primec == 10001) then
                        exit
                endif

                i = i + 1

        end do

        print*, i


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

