
#
# To compile the specific file;
#		$make file
# Note that file is stripped of it's file extension
#
# To make the Euler module --which a few programs depend upon--;
#		$make
# Will compile this module
#

CC=gfortran
SRC=euler.f95
FLAGS= -Wall -Wextra -g
OPT_LEVEL=-O2
OUT=euler.o

all: $(OUT)

euler.o: euler.f95
	$(CC) -c $(SRC) $(FLAGS) $(OPT_LEVEL) -o $(OUT)

10001st_prime: $(OUT)
	$(CC) $(FLAGS) $(OPT_LEVEL) 10001st_prime.f95 $(OUT)

amicable_num:
	$(CC) $(FLAGS) $(OPT_LEVEL) amicable_num.f95

circular_primes: $(OUT)
	$(CC) $(FLAGS) $(OPT_LEVEL) circular_primes.f95 $(OUT)

divis_tri_number:
	$(CC) $(FLAGS) $(OPT_LEVEL) divis_tri_number.f95

even_fib:
	$(CC) $(FLAGS) $(OPT_LEVEL) even_fib.f95

factorial_digits: $(OUT)
	$(CC) $(FLAGS) $(OPT_LEVEL) factorial_digits.f95 $(OUT)

integer_right_triangles:
	$(CC) $(FLAGS) $(OPT_LEVEL) integer_right_triangles.f95 $(OUT)

largest_palindrome: $(OUT)
	$(CC) $(FLAGS) $(OPT_LEVEL) largest_palindrome.f95 $(OUT)

largest_prime_factor: $(OUT)
	$(CC) $(FLAGS) $(OPT_LEVEL) largest_prime_factor.f95 $(OUT)

lycherl_num:
	$(CC) $(FLAGS) $(OPT_LEVEL) lycherl_num.f95

mult_3_5:
	$(CC) $(FLAGS) $(OPT_LEVEL) mult_3_5.f95

non_abundant_sums:
	$(CC) $(FLAGS) $(OPT_LEVEL) non_abundant_sums.f95

pandigit_prime:: $(OUT)
	$(CC) $(FLAGS) $(OPT_LEVEL) pandigit_prime.f95 $(OUT)

reversible_numbers: $(OUT)
	$(CC) $(FLAGS) $(OPT_LEVEL) reversible_numbers.f95 $(OUT)

special_pythag_trip: $(OUT)
	$(CC) $(FLAGS) $(OPT_LEVEL) special_pythag_trip.f95 $(OUT)

square_digit_chains:
	$(CC) $(FLAGS) $(OPT_LEVEL) square_digit_chains.f95

sub_string_divis: $(OUT)
	$(CC) $(FLAGS) $(OPT_LEVEL) sub_string_divis.f95 $(OUT)

summation_primes: $(OUT)
	$(CC) $(FLAGS) $(OPT_LEVEL) summation_primes.f95 $(OUT)

tri_pent_hex: $(OUT)
	$(CC) $(FLAGS) $(OPT_LEVEL) tri_pent_hex.f95 $(OUT)

clean:
	rm -rf *.mod *.o a.out

