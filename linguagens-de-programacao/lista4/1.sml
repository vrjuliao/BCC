signature MYMATH =
sig
  val fact : int -> int
  val halfPi : real
  val pow : (int * int ) -> int
  val double : int -> int
end;

structure MyMathLib :> MYMATH =
struct
  val halfPi = 3.14 / 2.0
  fun fact n = if n = 1 orelse n = 0
               then 1
               else if n < 0
               then ~1
               else n * (fact (n-1))
  fun pow(b, 0) = 1
    | pow(b, e) = b * pow(b, (e-1))
  fun double n = 2*n
end;

MyMathLib.pow(2, 3);

MyMathLib.double(6);

MyMathLib.fact(5);

MyMathLib.halfPi;