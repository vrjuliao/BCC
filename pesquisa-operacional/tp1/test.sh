for ((i = 1; i <= 100; ++i)); do
	echo $i
	diff -w <(python3 main.py < in/in${i}.txt) ans/ans${i}.txt || break
done
