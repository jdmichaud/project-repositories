exprs=`cat $1`
for expr in $exprs
do
  echo "rxp $expr"
  ./rxp $expr
  if [ $? -ne 0 ];
  then
      echo "$expr failed"
      echo "res: $res"
  fi
done
