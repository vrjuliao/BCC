(* Exercise 1 *)
fun cube (x:real) = x*x*x;

(* Exercise 2 *)
fun pow (_, 0) = 1
  | pow (n, e) = n * (pow (n, (e-1)));

(* Exercise 3 *)
fun sumLists(a, b) = map (op +) (ListPair.zip(a, b));

(* Exercise 4 *)
fun max (h::t) = foldl (fn(a, b) => if a > b then a else b) h t;

(* Exercise 5 *)
fun cumSum (f::s::t) = f::cumSum((f+s)::t)
  | cumSum (l) = l;

(* Exercise 6 *)
fun greet name = 
  let 
    val hello = "Hello "
  in 
    if size(name) > 0 then
      hello^name
    else
      hello^"nobody"
  end;

(* Exercise 7 *)
fun has(h::t, elem) = elem = h orelse has(t, elem)
  | has ([], _) = false;

fun aux_split(_, []) = ([], "")
  | aux_split(tokens, ch::tail) = 
  let
    val (reslist, resword) = aux_split(tokens, tail)
  in
    if has(tokens, ch)
    then 
      if size(resword)>0 
      then (resword::reslist, "")
      else (reslist, resword)
    else (reslist, str(ch)^resword)
  end;

fun split phrase = 
  let
    val tokens = [#" ", #",", #".", #"-"]
    val (reslist, resword) = aux_split(tokens, explode(phrase))
  in
    if size(resword) > 0
    then resword::reslist
    else reslist
  end;

(* Exercise 8 *)
fun allTrue (h::t) = h andalso allTrue(t)
  | allTrue [] = true;

(* Exercise 9 *)
datatype dinheiro = Real of real | Centavos of int | Pessoa_Dinheiro of (string * real);
fun amount (Real r) = floor(r * 100.0)
  | amount (Centavos c) = c
  | amount (Pessoa_Dinheiro(_, r)) = amount (Real(r));

(* Exercise 10 *)
datatype Planeta = Mercurio | Venus   | Terra | Marte
                 | Jupiter  | Saturno | Urano | Netuno;

fun calcAge daysPerYear months = ((months div 12)*daysPerYear) + ((months mod 12)*(daysPerYear div 12));

fun planetAge (months, Mercurio) = calcAge 88    months
  | planetAge (months, Venus)    = calcAge 225   months
  | planetAge (months, Terra)    = calcAge 365   months
  | planetAge (months, Marte)    = calcAge 687   months
  | planetAge (months, Jupiter)  = calcAge 4332  months
  | planetAge (months, Saturno)  = calcAge 10760 months
  | planetAge (months, Urano)    = calcAge 30681 months
  | planetAge (months, Netuno)   = calcAge 60190 months;

(* Exercise 11 *)
datatype btree = Leaf | Node of (btree * int * btree);

fun sumAll Leaf = 0
  | sumAll (Node(left,value, right)) = value + (sumAll left) + (sumAll right);

(* Exercise 12 *)
fun multiPairs (a, b) = map (op * ) (ListPair.zip(a, b));

(* Exercise 13 *)
fun squareOfSum (x, y) = foldr (op * ) 1 (map (op+) [(x, y), (x, y)]);