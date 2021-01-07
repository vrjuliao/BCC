(* Exercise 3 *)
fun sumLists(a, b) = map (op +) (ListPair.zip(a, b));