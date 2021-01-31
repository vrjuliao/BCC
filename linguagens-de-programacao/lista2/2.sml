datatype area = RConst of real
              | AQuadrado of area
              | ACirculo of area
              | ARetangulo of area * area;

fun eval (RConst (r1)) = r1
  | eval (AQuadrado (a)) = eval(a)*eval(a)
  | eval (ACirculo (r)) = 3.14*(eval r)*(eval r)
  | eval (ARetangulo (l1, l2)) = (eval l1) * (eval l2);

val e = ACirculo(RConst 2.0);
eval e;