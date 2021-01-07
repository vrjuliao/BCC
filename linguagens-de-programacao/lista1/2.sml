(* Exercise 2 *)
fun pow (_, 0) = 1
  | pow (n, e) = n * (pow (n, (e-1)));