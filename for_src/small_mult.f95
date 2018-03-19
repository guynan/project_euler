
program main

        implicit none

        integer :: i

        i = 1

        do
                if(evenly_divis(i)) then
                        exit
                end if

                i = i + 1
        end do

        print *, i


contains

        function evenly_divis (a)
                integer :: a, i
                logical :: evenly_divis

                evenly_divis = .true.

                do i = 1, 20, 1

                        if(mod(a, i) /= 0) then
                                evenly_divis = .false.
                                exit
                        end if

                end do

                return

        end function evenly_divis


end program main
