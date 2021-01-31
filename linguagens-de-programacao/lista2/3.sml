datatype perimetro = RConst of real
                   | PQuadrado of perimetro
                   | PCirculo of perimetro
                   | PRetangulo of perimetro * perimetro
                   | PTriangulo of perimetro * perimetro * perimetro;

fun eval (RConst (r1)) = r1
  | eval (PQuadrado (a)) = 4.0*eval(a)
  | eval (PCirculo (r)) = 6.28*(eval r)
  | eval (PRetangulo (l1, l2)) = (2.0*(eval l1)) + (2.0*(eval l2))
  | eval (PTriangulo (l1, l2, l3)) = foldr (op+) 0.0 [eval l1, eval l2, eval l3];

val p = PQuadrado(RConst 4.0);
eval p;

val t = PTriangulo(RConst 4.0, RConst 5.0, RConst 5.0);
eval t;