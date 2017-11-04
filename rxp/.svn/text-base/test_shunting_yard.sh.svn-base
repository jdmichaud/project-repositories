exprs=`cat $1`
for expr in $exprs
do
  echo "rxp $expr"
  res=`./rxp $expr | uniq | wc -l`
  if [ $res != 1 ];
  then
      echo "$expr failed"
      echo "res: $res"
  fi
done
