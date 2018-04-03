
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
FLAGS= -Wall -Wextra -O2
OUT=euler.o

all: $(OUT)

euler.o:
	$(CC) -c $(SRC) $(FLAGS) -o $(OUT)

10001st_prime: $(OUT)
	$(CC) $(FLAGS) 10001st_prime.f95 $(OUT)

amicable_number:
	$(CC) $(FLAGS) amicable_number.f95

divis_tri_number:
	$(CC) $(FLAGS) divis_tri_number.f95

even_fib:
	$(CC) $(FLAGS) even_fib.f95

factorial_digits: $(OUT)
	$(CC) $(FLAGS) factorial_digits.f95 $(OUT)

largest_prime_factor:
	$(CC) $(FLAGS) largest_prime_factor.f95

lycherl_num:
	$(CC) $(FLAGS) lycherl_num.f95

mult_3_5:
	$(CC) $(FLAGS) mult_3_5.f95

reversible_numbers: $(OUT)
	$(CC) $(FLAGS) reversible_numbers.f95 $(OUT)

special_pythag_trip: $(OUT)
	$(CC) $(FLAGS) special_pythag_trip.f95 $(OUT)

square_digit_chains:
	$(CC) $(FLAGS) square_digit_chains.f95

summation_primes: $(OUT)
	$(CC) $(FLAGS) summation_primes.f95 $(OUT)

clean:
	rm -rf *.mod *.o a.out

