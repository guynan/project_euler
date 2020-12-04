! The binomial coefficients nCk can be arranged in triangular form, Pascal's
 ! triangle, like this:
 !
 ! It can be seen that the first eight rows of Pascal's triangle contain twelve
 ! distinct numbers: 1, 2, 3, 4, 5, 6, 7, 10, 15, 20, 21 and 35.
 !
 ! A positive integer n is called squarefree if no square of a prime divides n.
 ! Of the twelve distinct numbers in the first eight rows of Pascal's triangle,
 ! all except 4 and 20 are squarefree. The sum of the distinct squarefree
 ! numbers in the first eight rows is 105.
 !
 ! Find the sum of the distinct squarefree numbers in the first 51 rows of
 ! Pascal's triangle.


program main

        ! a few FUTURE optimisations;
        ! We only have to calculate half the entries in Pascal's triange.
        ! The last (distinct) value of squarefree nums can be kept in a
        ! variable as the new entries will always be of increasing value...
        ! Kinda... Maybe if I do it from the top, and work down...
        ! We can check whether the row contains any by seeing if the product of
        ! the row is divisible by a squarefree number and if not we don't check
        ! it. There is a relationship between the products of consecutive rows;
        ! if the new product is divisible by a square prime, then we check
        ! individual entries, otherwise not
        ! We can traverse this in order by finding the max
        ! If the row number starts with a prime, then all subsequent numbers
        ! are divisible by that prime.

        use euler

implicit none

        integer (C_INT64_t), dimension(:), allocatable, TARGET :: sqrfree_arr;
        integer (int32), parameter :: MAX_ARR_LEN = 1000;
        integer (int32), parameter :: ROW_HEIGHT = 50;
        integer (C_INT64_t) :: n, k, tmp;
        integer (C_SIZE_T) :: arr_in;

        allocate(sqrfree_arr(MAX_ARR_LEN));
        sqrfree_arr = 0;

        arr_in = 1;

        row_loop: &
        do n = 1, ROW_HEIGHT

                index_loop: &
                do k = 0, ((n / 2) + merge(0, 0, BTEST(n, 0)))
                        tmp = binomial_coefficient(n, k);
                        if(squarefree(tmp)) then
                                sqrfree_arr(arr_in) = tmp;
                                arr_in = arr_in + 1;
                        endif

                end do index_loop

        end do row_loop

        print*, sum_discrete(sqrfree_arr, arr_in);
        
        deallocate(sqrfree_arr)


contains


        ! This function accepts an array to count discrete entries in the
        ! array. This is done by sorting the array and ignoring duplicates.

        function sum_discrete(array, len_)

                external compar
                integer (C_INT) :: compar;

                integer (C_SIZE_T) :: len_;
                integer (C_INT64_t) :: prev, sum_discrete, sum, n;
                integer (C_INT64_t), dimension(:), allocatable, TARGET :: array;

                sum = 0; prev = 0;

                call qsort(c_loc(array(1)), len_, sizeof(len_), c_funloc(compar))

                do n = 1, len_
                        sum = sum + merge(array(n), 0_i64, (array(n) /= prev));
                        prev = array(n);
                end do

                sum_discrete = sum;

        end function 



        ! The factors of the number `lim' are tested by iterating up to the
        ! square of that number. All factors that may be squared and remain a
        ! factor are tested for primality. The number of divisors is taken note
        ! of in the iterations so that it may be divided by that number so we
        ! approach the square faster.

        pure function squarefree(lim)

                integer (C_INT64_t), intent(in) :: lim;
                integer (C_INT64_t) :: n, i, ndiv;
                logical :: squarefree;

                n = lim; i = 2;
                
                squarefree = .TRUE.;

                do while ((i * i) <= n .AND. squarefree)

                        ndiv = intbool(mod(n, i) == 0);
                        ndiv = ndiv + intbool(ndiv > 0 .AND. (mod(n/i, i) == 0));
                        squarefree = .NOT. (ndiv == 2 .AND. isprime(i));
                        n = n / (i ** ndiv);
                        i = i + 1;

                end do 

        end function squarefree


        ! This function directly replicates the integer equivalence of booleans
        ! in C. This is solid functionality that it turns out I can't live
        ! without.

        pure function intbool(logical)
                
                integer (C_INT64_T) :: intbool;
                logical, intent(in) :: logical

                intbool = merge(1, 0, (logical));

        end function intbool


        ! N is the row, k is the index
        pure function binomial_coefficient(n, k)

                integer (C_INT64_t), intent(in) :: n, k
                integer (C_INT64_t) :: i, binomial_coefficient;

                binomial_coefficient = 1;

                do i = 0, k - 1
                        call imult(binomial_coefficient, (n - i));
                        call idiv(binomial_coefficient, (i + 1));
                end do

        end function binomial_coefficient

end program main


! This is the comparison function that is referenced by 'compar'. Fortran
! automatically appends an '_' to the end of the function prototype. Due to the
! C function signature, it must always return an integer. 
integer (C_INT) function compar_ (a, b) BIND(C)

        use ISO_C_BINDING 
        use ISO_FORTRAN_ENV

        integer (C_INT64_t) :: a, b

        if (a .lt. b) compar_ = -1
        if (a .eq. b) compar_ = 0
        if (a .gt. b) compar_ = 1

end function compar_

