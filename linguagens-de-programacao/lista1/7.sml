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