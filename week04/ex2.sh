gcc ex2.c -o ex2
./ex2 &
pid2=$!
for ((i=1; i < 5; i++))
do
pstree $pid2
sleep 2
done
