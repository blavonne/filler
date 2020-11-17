#!/bin/bash
#colors-------------------------------------------------------------------------
green=\\e[1\;32m
red=\\e[1\;31m
rose=\\e[1\;1\;35m
end_c=\\e[0m
#-------------------------------------------------------------------------------
count=5
champs=("abanlin" "hcao" "champely" "carli" "grati" "superjeannot")
maps=("map00" "map01" "map02")

put_usage() {
  echo -e "${red}Some args are missing.${end_c}"
  echo -e "Usage:"
  echo -e "sh checker.sh -pN ./yours.filler [-pM ./champions/name.filler] [-m ./map/map00] [-g L]"
  echo -e "-p${green}N${end_c} is your player number"
  echo -e "-p${green}M${end_c} is your enemy number"
  echo -e "-${green}L${end_c} is repeat count"
  echo -e "-params in [] are optional,"
  echo -e "so if you don't choose any, script plays 5"
  echo -e "games with every champion on every map."
}

if [ $# -lt 2 ]; then
  put_usage
  exit
fi

for i in "$@"; do
  if [ "$i" = "-p2" ]; then
    player2=$i
    buf=$i
  elif [ "$i" = "-p1" ]; then
    player1=$i
    buf=$i
  elif [ "$buf" = "-p1" ]; then
    p1_path=$i
    buf=0
  elif [ "$buf" = "-p2" ]; then
    p2_path=$i
    buf=0
  elif [ "$i" = "-m" ]; then
    buf=$i
  elif [ "$buf" = "-m" ]; then
    map=$i
    buf=0
  elif [ "$i" = "-g" ]; then
    buf=$i
  elif [ "$buf" = "-g" ]; then
    count=$i
    buf=0
  fi
done

rm -f trace*.txt > /dev/null
rm -f result.txt > /dev/null

file_i=0

if [ "$player2" != "" ]; then
  if [ "$map" != "" ]; then
    for ((i=0; i<count; i++)); do
      res=$(./filler_vm ${player1} ${p1_path} ${player2} ${p2_path} -f ${map})
      cat ./filler.trace >> result.txt
      echo "${res}" >> ./trace_${file_i}.txt
      echo -e ${player1} ${p1_path} >> result.txt
      echo -e ${player2} ${p2_path} >> result.txt
      echo -e ${map} >> result.txt
      cat ./trace_${file_i}.txt | grep fin >> result.txt
      echo "" >> result.txt
      file_i=$((file_i + 1))
      echo -e "${green}Game $i ${p1_path} VS ${p2_path} on ${map} done.${end_c}"
      echo -e "${rose}#Next...${end_c}"
    done
  else
    for m in ${maps[*]}; do
      for ((i=0; i<count; i++)); do
        res=$(./filler_vm ${player1} ${p1_path} ${player2} ${p2_path} -f ${m})
        cat ./filler.trace >> result.txt
        echo "${res}" >> ./trace_${file_i}.txt
        echo -e ${player1} ${p1_path} >> result.txt
        echo -e ${player2} ${p2_path} >> result.txt
        echo -e ${m} >> result.txt
        cat ./trace_${file_i}.txt | grep fin >> result.txt
        echo "" >> result.txt
        file_i=$((file_i + 1))
        echo -e "${green}Game $i ${p1_path} VS ${p2_path} on ${m} done.${end_c}"
        echo -e "${rose}##Next...${end_c}"
      done
    done
  fi
else
	if [ "$player1" = "-p1" ]; then
		player2="-p2"
	elif [ "$player1" = "-p2" ]; then
		player2="-p1"
	fi
  if [ "$map" != "" ]; then
    for ((i=0; i<count; i++)); do
      for j in ${champs[*]}; do
        res=$(./filler_vm ${player1} ${p1_path} ${player2} ./champions/${j}.filler -f ${map})
        cat ./filler.trace >> result.txt
        echo "${res}" >> ./trace_${file_i}.txt
        echo -e ${player1} ${p1_path} >> result.txt
        echo -e ${player2} ${j} >> result.txt
        echo -e ${map} >> result.txt
        cat ./trace_${file_i}.txt | grep fin >> result.txt
        echo "" >> result.txt
        file_i=$((file_i + 1))
        echo -e "${green}Game $i ${p1_path} VS ${j} on ${map} done.${end_c}"
        echo -e "${rose}###Next...${end_c}"
      done
    done
  else
    for m in ${maps[*]}; do
      for j in ${champs[*]}; do
        for ((i=0; i<count; i++)); do
          res=$(./filler_vm ${player1} ${p1_path} ${player2} ./champions/${j}.filler -f ./maps/${m})
          cat ./filler.trace >> result.txt
          echo "${res}" >> ./trace_${file_i}.txt
          echo -e ${player1} ${p1_path} >> result.txt
          echo -e ${player2} ${j} >> result.txt
          echo -e ${m} >> result.txt
          cat ./trace_${file_i}.txt | grep fin >> result.txt
          echo "" >> result.txt
          file_i=$((file_i + 1))
          echo -e "${green}Game $i ${p1_path} VS ${j} on ${m} done.${end_c}"
          echo -e "${rose}####Next...${end_c}"
        done
      done
    done
  fi
fi

echo -e "${green}All games are done, see${end_c} ${rose}trace_N.txt${end_c} ${green}and${end_c} ${rose}result.txt.${end_c}"