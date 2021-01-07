(* Exercise 11 *)
datatype btree = Leaf | Node of (btree * int * btree);

fun sumAll Leaf = 0
  | sumAll (Node(left,value, right)) = value + (sumAll left) + (sumAll right);
