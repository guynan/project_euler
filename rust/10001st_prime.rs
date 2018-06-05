



fn main () {


    let mut c = 1;
    let mut i = 3;

    loop {

        if isprime(i) {
            c += 1;

            if c == 10001 {
                break;
            }
        }

        i += 2;
    }

    println!("{}", i);

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

