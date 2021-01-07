(* Exercise 8 *)
fun allTrue (h::t) = h andalso allTrue(t)
  | allTrue [] = true;