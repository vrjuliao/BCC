(* Exercise 13 *)
fun squareOfSum (x, y) = foldr (op * ) 1 (map (op+) [(x, y), (x, y)]);