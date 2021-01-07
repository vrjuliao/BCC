(* Exercise 4 *)
fun max (h::t) = foldl (fn(a, b) => if a > b then a else b) h t;