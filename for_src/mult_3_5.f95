module main

implicit none

contains

        function mult_3_5 (i) result (res)

                integer :: i
                logical :: res 

                res = ((mod(i, 3) == 0) .OR. (mod(i, 5) == 0))

        end function mult_3_5 


end module main



program euler

use main

implicit none

        integer :: top, sumx, i

        top = 1000
        sumx = 0

        do i = 1, TOP, 1
                if (mult_3_5(i)) then
                        sumx = sumx + i
                end if
        end do

        print *, "", sumx

end program euler

