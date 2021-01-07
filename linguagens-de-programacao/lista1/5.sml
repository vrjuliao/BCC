(* Exercise 5 *)
fun cumSum (f::s::t) = f::cumSum((f+s)::t)
  | cumSum (l) = l;