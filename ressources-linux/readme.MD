# Filler checker for linux by Barrett Lavonne  
## Usage:  
Use bash, not shell  
Do not forget slash in players path (VM reads only full path to player)  
This checker is only for LINUX  
Carli is not in list of champions to play by default cause she does not move,
but you can add she manually via `vim checker.sh`:  
```shell script
#add "carli" or someone else is this list:
champs=("abanlin" "hcao" "champely" "grati" "superjeannot")
```
Default count games is 5, you can change `count=5` in script or use flag -g.
### Play with all champions on every map 5 times  
Use flag -p1 or -p2 with full path  
`bash ./checker -p1 /path/to/your/player/name.filler`  
### Play with chosen champion  
Use both -p1 flag and -p2 with full path  
`bash ./checker -p1 /path/to/your/player/name.filler -p2 /path/to/your/enemy/name.filler`
### Play on chosen map  
Use flag -m with full path to map  
`bash ./checker -p1 /path/to/your/player/name.filler -m ./maps/map00`  
### Play n times  
Use flag -g with some integer value  
For example, n = 20  
`bash ./checker -p1 /path/to/your/player/name.filler -g 20`  
  
---
You can mix flags. For example, to play with Hcao as p1 on map00 3 times:  
`bash ./checker -p2 /path/to/your/player/name.filler -p1 ./champions/hcao.filler -m ./maps/map00 -g 3`  
Checker does not check args and puts them to VM in such condition as you wrote, so
if you made a mistake then all logs will be empty.
After execution you'll get traces in trace_n.txt files and some statistic in result.txt.  
```shell script
#cat result.txt
Game № 56
map02
-p1  blavonne
-p2  hcao
seed = 2378
./blavonne.filler won
Score:
1574AGAINST361
#cat trace_0.txt
launched ./blavonne.filler
$$$ exec p1 : [./blavonne.filler]
launched ./champions/abanlin.filler
$$$ exec p2 : [./champions/abanlin.filler]
Plateau 15 17:
    01234567890123456
000 .................
001 .................
002 .................
003 .................
004 .................
005 .................
006 .................
007 .................
008 ..O..............
009 .................
010 .................
011 .................
012 ..............X..
013 .................
014 .................
Piece 2 3:
.**
.**
etc.
```
By default after checker.sh starts stat.sh - script analyses result.txt and prints
statistic:  
```shell script
Total score:
     abanlin         1
    champely         6
       carli         0
       grati         5
        hcao         2
superjeannot         6
      player        51
```
Good luck!
