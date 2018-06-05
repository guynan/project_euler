


fn main() {

    let mut sum = 0;

    for i in 1..1000 {
        if mult_3_5(i) {
            sum += i;
        }
    }

    println!("{}", sum);

}

fn mult_3_5(i : i32) -> bool {
    (i % 3 == 0) || (i % 5 == 0)
}

