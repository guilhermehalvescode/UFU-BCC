#!/usr/bin/env bash
sum=(0 0)
args=("$@")
TIMEFORMAT="%R"
for i in {0..1} 
do
  for j in {1..11} 
  do 
    start=$(date +%s.%6N)
    ./${args[$i]}
    end=$(date +%s.%6N)
    elapsed=$(echo "scale=6; $end - $start" | bc)
    if [ $j -ne 1 ] 
    then
      echo "(${args[$i]}) seconds: $elapsed" >> seconds.txt
      sum[$i]=$(echo "scale=6;${sum[$i]}+$elapsed" | bc)
    fi
  done
  sum[$i]=$(echo "scale=6;${sum[$i]}/10.0" | bc)
  echo "TIME AVERAGE (${args[$i]}) => ${sum[$i]}" >> benchs.txt
done
echo "DIFF VALUE: $(echo "scale=6;${sum[0]}-${sum[1]}" | bc)" >> benchs.txt
