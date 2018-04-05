
program even_fib

        implicit none

        integer :: first, second, tmp, maximum, sumx

        sumx = 0
        first = 1
        second = 1
        maximum = 4000000

        do
                tmp = first + second

                if (tmp > MAXIMUM) then
                        exit
                end if

                if(mod(tmp, 2) == 0) then
                        sumx = sumx + tmp
                end if

                first = second
                second = tmp

        end do

        print *, sumx

end program even_fib

