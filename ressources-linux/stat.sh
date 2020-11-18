#!/bin/bash
#colors-------------------------------------------------------------------------
green=\\e[1\;32m
end_c=\\e[0m
#-------------------------------------------------------------------------------
FILE="./result.txt"
#players------------------------------------------------------------------------
abanlin=0
champely=0
carli=0
hcao=0
superjeannot=0
grati=0
player=$1

if test -f "$FILE"; then
	abanlin=$(sed -n 's/.\/maps\/// ; /map/p; s/.filler// ; s/.\/champions\/// ; s/.\/// ; /won/p' result.txt | grep won | grep "abanlin" | wc -l)
	grati=$(sed -n 's/.\/maps\/// ; /map/p; s/.filler// ; s/.\/champions\/// ; s/.\/// ; /won/p' result.txt | grep won | grep "grati" | wc -l)
	champely=$(sed -n 's/.\/maps\/// ; /map/p; s/.filler// ; s/.\/champions\/// ; s/.\/// ; /won/p' result.txt | grep won | grep "champely" | wc -l)
	hcao=$(sed -n 's/.\/maps\/// ; /map/p; s/.filler// ; s/.\/champions\/// ; s/.\/// ; /won/p' result.txt | grep won | grep "hcao" | wc -l)
	carli=$(sed -n 's/.\/maps\/// ; /map/p; s/.filler// ; s/.\/champions\/// ; s/.\/// ; /won/p' result.txt | grep won | grep "carli" | wc -l)
	superjeannot=$(sed -n 's/.\/maps\/// ; /map/p; s/.filler// ; s/.\/champions\/// ; s/.\/// ; /won/p' result.txt | grep won | grep "superjeannot" | wc -l)
	if [ "${player}" != "" ]; then
		i=$(sed -n 's/.\/maps\/// ; /map/p; s/.filler// ; s/.\/champions\/// ; s/.\/// ; /won/p' result.txt | grep won | grep ${player} | wc -l)
	fi
	echo -e "${green}Total score:${end_c}"
	printf '%12s%10d\n' "abanlin" ${abanlin}
	printf '%12s%10d\n' "champely" ${champely}
	printf '%12s%10d\n' "carli" ${carli}
	printf '%12s%10d\n' "grati" ${grati}
	printf '%12s%10d\n' "hcao" ${hcao}
	printf '%12s%10d\n' "superjeannot" ${superjeannot}
	if [ "${player}" = "" ]; then
		player="player"
		i=$(grep won result.txt | wc -l)
		i=$(($i - $abanlin - $carli - $champely - $grati - $hcao - $superjeannot))
	fi
	printf '%12s%10d\n' ${player} $i
fi
