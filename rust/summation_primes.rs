



fn main () {

    let mut sum : i64 = 2;
    let max = 2000000;

    for i in 3..max {

        if isprime(i) {
            sum += i as i64;
        }
    }

    println!("{}", sum);

}

fn isprime(n : i32) -> bool {

    if (n <= 2) || (n & 0x1 == 0) {
        return n == 2;
    }

    let lim = (n as f32).sqrt().round() as i32;
    let mut i = 3;

    while i <= lim {

        if n % i == 0 {
            return false;
        }

        i += 2;
    }

    true
}

