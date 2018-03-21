
program main


implicit none


        integer, parameter :: ONE = 1
        integer, parameter :: MAXIMUM = 10000
        integer :: sumn, n

        sumn = 0

        do n = 1, MAXIMUM -1, 1
                if(is_amicable(n)) then
                        call inc(sumn, n)
                endif
        end do

        print*, sumn


contains

        ! This is here because I really miss the '+=' operator from C

        pure subroutine inc(base, offset)

                integer, intent(out) :: base
                integer, intent(in) :: offset

                base = base + offset

                return

        end subroutine inc


        ! This is here because I really miss the '-=' operator from C

        pure subroutine dec(base, offset)

                integer, intent(out) :: base
                integer, intent(in) :: offset

                base = base - offset

                return

        end subroutine dec


        pure function is_amicable(n)

                integer, intent(in) :: n
                logical :: is_amicable

                integer :: i, k, sum_a, sum_b
                sum_a = 0
                sum_b = 0

                k = (n / 2) + 1

                do i = 1, k - 1, 1
                        if(mod(n, i) == 0) then
                                call inc(sum_a, i)
                        endif
                end do

                do i = 1, sum_a - 1, 1

                        if(mod(sum_a, i) == 0) then
                                call inc(sum_b, i)
                        endif

                end do

                is_amicable = ((sum_b == n) .AND. (n /= i))

                return

        end function is_amicable


end program main
