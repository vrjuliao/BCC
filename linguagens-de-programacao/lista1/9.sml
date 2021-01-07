(* Exercise 9 *)
datatype dinheiro = Real of real | Centavos of int | Pessoa_Dinheiro of (string * real);
fun amount (Real r) = floor(r * 100.0)
  | amount (Centavos c) = c
  | amount (Pessoa_Dinheiro(_, r)) = amount (Real(r));