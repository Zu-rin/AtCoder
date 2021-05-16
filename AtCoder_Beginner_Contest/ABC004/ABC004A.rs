use std::io::*;

fn main(){
    let mut num = String::new();
    stdin().read_line(&mut num).ok();
    let ans: i32 = num.trim().parse().unwrap();
    println!("{}", ans * 2);
}