fn main() {
    let value = vec![3,3,1,2,6]; //Your value here ^^
    let result: Vec<i32> = bubble_sort(value);
    println!("{:?}", result);
}

fn bubble_sort(data: Vec<i32>) -> Vec<i32> {
    let mut rem: Vec<i32> = data.clone();
    let mut dup: Vec<i32> = data.clone(); 
    //This creates a duplicate, so when you recall a variable in the original array, the values won't be identical..

    let mut b = 0;
    while b < ((data.len()-1)).try_into().unwrap() {
        for x in 0..data.len()-1 {
            if rem[x] > rem[x+1] {
                rem[x] = rem[x+1]; rem[x+1] = dup[x]; //inefficient way of swapping values >-<
                dup = rem.clone();
                } else { b += 1 } //Checks if the array is already solved 
            }
        }
    return rem
}
