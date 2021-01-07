(* Exercise 12 *)
fun multiPairs (a, b) = map (op * ) (ListPair.zip(a, b));
