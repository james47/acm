$i
while [ true ]
do
echo $((i = i + 1))
./make > 1.in
./ac < 1.in > 1.out
./wa < 1.in > 2.out
if ! diff 1.out 2.out
then 
	break
fi 
done

