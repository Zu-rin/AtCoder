use std::io::*;
use std::str::FromStr;

fn main(){
    let mut s = String::new();
    stdin().read_line(&mut s).ok();
    let mut d = s.split_whitespace().map(|n| i32::from_str(n).unwrap());
    let (x, y) = (d.next().unwrap(), d.next().unwrap());
    println!("{}", y / x);
}