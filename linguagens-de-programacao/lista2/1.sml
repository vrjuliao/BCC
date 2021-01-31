datatype expr = IConst of int 
              | Plus of expr * expr 
              | Minus of expr * expr
              | Multi of expr * expr
              | Div of expr * expr
              | Max of expr * expr
              | Min of expr * expr
              | Eq of expr * expr
              | Gt of expr * expr;

fun eval (IConst i) = i
  | eval (Plus  (e1, e2)) = eval(e1) + eval(e2)
  | eval (Minus (e1, e2)) = eval(e1) - eval(e2)
  | eval (Multi (e1, e2)) = eval(e1) * eval(e2)
  | eval (Eq    (e1, e2)) = if eval(e1) = eval(e2) then 1 else 0
  | eval (Gt    (e1, e2)) = if eval(e1) > eval(e2) then 1 else 0
  | eval (Div   (e1, e2)) = 
    let 
      val ee2 = eval(e2)
    in
      if ee2 = 0 then 0 else eval(e1) div ee2
    end
  | eval (Max   (e1, e2)) = 
    let 
      val (ee1, ee2) = (eval(e1), eval(e2))
    in
      if ee1 > ee2 then ee1 else ee2
    end
  | eval (Min   (e1, e2)) = 
    let 
      val (ee1, ee2) = (eval(e1), eval(e2))
    in
      if ee1 < ee2 then ee1 else ee2
    end;

val e1 = Max(IConst 3, Plus(IConst 2, IConst 3));
eval e1;

val e2 = Div(Multi(IConst 5, IConst 4), Minus(IConst 4, IConst 4));
eval e2;