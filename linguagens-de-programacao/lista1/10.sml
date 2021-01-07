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
