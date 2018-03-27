

program main

        implicit none

        integer :: c = 1, i;

        integer :: maximum = 10000000

        ! c is the count of how many number chains arrive at 89

        do i = 1, MAXIMUM

                if(number_chain(i) == 89) then
                        call inc(c, 1)
                endif

        enddo

        print*, c


contains


        ! Increment a number i by the value x.
        ! This is here because I miss += 
        subroutine inc(base, offset)

                integer, intent (in):: offset
                integer, intent (out):: base

                base = base + offset
                return

        end subroutine inc


        function number_chain(r)

                integer, intent (in) :: r

                integer :: i
                integer :: sumx, number_chain
                i = r

                outer: do

                        sumx = 0
                        
                        inner: do while (i /= 0)
                                call inc(sumx, mod(i, 10) ** 2)
                                i = i / 10
                        end do inner

                        i = sumx

                        if(sumx == 1 .OR. sumx == 89) then
                                number_chain = sumx;
                                exit
                        endif

                end do outer

                return

        end function number_chain    


end program main

