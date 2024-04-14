echo 'Enter the value of a'
read a

fact=1

while[ $a -gt 1]
do 
   fact=$(( fact * a))
   a=$(($a-1))
done
echo $fact
