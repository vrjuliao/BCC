signature MYMATH =
sig
  exception NegativeValue;
  val fact : int -> int
  val halfPi : real
  val pow : (int * int ) -> int
  val double : int -> int
end;

structure MyMathLib :> MYMATH =
struct
  exception NegativeValue;
  val halfPi = 3.14 / 2.0
  fun fact n = if n = 1 orelse n = 0
               then 1
               else if n < 0
               then raise NegativeValue
               else n * (fact (n-1))
  fun pow(b, 0) = 1
    | pow(b, e) = if e > 0 then b * pow(b, (e-1)) else raise NegativeValue
  fun double n = 2*n
end;
  
fun useMyMathLib(n, "pow") = (print (Int.toString(MyMathLib.pow(n,n)))
    handle MyMathLib.NegativeValue => print "Nao posso lidar com numeros negativos!")
  | useMyMathLib(n,"fact") = (print (Int.toString(MyMathLib.fact(n)))
    handle MyMathLib.NegativeValue => print "Nao posso lidar com numeros negativos!")
  | useMyMathLib _ =  print "";
  


useMyMathLib(2, "pow");
useMyMathLib(~2, "fact");