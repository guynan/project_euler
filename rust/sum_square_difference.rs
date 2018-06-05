


fn main () {

    let mut sum = 0;
    let mut sqr_sum = 0;

    for i in 1..100 {
        sqr_sum += (i as i64).pow(2);
        sum += i;
    }

    println!("{}", (sum as i64).pow(2) - sqr_sum);

}
