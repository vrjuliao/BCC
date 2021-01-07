fun fib_list 0 = [0, 0, 0]
  | fib_list 1 = [1, 0, 0]
  | fib_list a = 
    let 
      val a1::a2::garbage = fib_list (a-1)
    in
      [a1+a2, a1, a2]
    end
;

fun iterative_fib a = hd(fib_list a);

iterative_fib 40;