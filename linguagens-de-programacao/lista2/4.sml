datatype UnOp = Not;
datatype BinOp = Add | Sub | Mul | Gt | Eq | Or;
datatype Sexpr = IConst of int
               | Op1 of UnOp * Sexpr
               | Op2 of BinOp * Sexpr * Sexpr;

fun simplify (IConst (i)) = IConst (i)
  | simplify (Op1 (unop, sexpr)) = 
    (case sexpr
    of Op1(unop2, sexpr2) => simplify(sexpr2)
     | _ => Op1(unop, simplify(sexpr)))
  | simplify (Op2 (binop, sexpr1, sexpr2)) = 
    let 
      val(x1, x2) = (simplify(sexpr1), simplify(sexpr2))
    in
      case binop
      of Sub => (
        if x2 = IConst(0) then x1
        else if x2 = x1 then IConst(0)
        else Op2(binop, x1, x2)
      )| Add => (
        if x2 = IConst(0) then x1
        else if x1 = IConst(0) then x2
        else Op2(binop, x1, x2)
      )| Mul => (
        if x2 = IConst(1) then x1
        else if x1 = IConst(1) then x2
        else if x1 = IConst(0) orelse x2 = IConst(0) then IConst(0)
        else Op2(binop, x1, x2)
      )| Or => (
        if x1 = x2 then x1
        else Op2(binop, x1, x2)
      )| _ => Op2(binop, x1, x2)
    end;

val exp1 = Op2(Mul, Op2(Add, IConst 1, IConst 0), Op2(Add, IConst 9, IConst 0));
simplify exp1;

val exp2 = Op2 (Mul, Op2 (Add, IConst 1, IConst 0), Op2 (Add, Op2 (Or, IConst 10,
IConst 12), IConst 0));
simplify exp2;

val exp3 = Op1(Not, Op1(Not, Op1(Not, Op2(Mul, IConst(2), IConst(0)))));
simplify exp3;

val t = Op2(Mul, Op2(Add, IConst 1, IConst 2), Op2(Add, IConst 9, IConst 3));
simplify t