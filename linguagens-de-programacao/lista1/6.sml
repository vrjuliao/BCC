
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
