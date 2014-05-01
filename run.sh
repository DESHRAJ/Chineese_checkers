#!/bin/bash
`chmod +x socket`
`chmod +x player1`
`chmod +x player2`
`chmod +x code_warrior.jar`
`killall java 2>/dev/null`
`killall ./socket 2>/dev/null`
`killall ./player1 2>/dev/null`
`killall ./player2 2>/dev/null`

FILE="Moves_Out"
if [ -f $FILE ]
then
`rm $FILE ` 
fi
FILE="in"
if [ -f $FILE ]
then
`rm $FILE ` 
fi
FILE="out"
if [ -f $FILE ]
then
`rm $FILE ` 
fi
java -jar code_warrior.jar &
sleep 2
./socket localhost 6789
