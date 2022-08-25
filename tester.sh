#!/bin/bash
make re

DEFAULT='\033[0m'
RED='\033[1;31m'
GREEN='\033[1;32m'
YELLOW='\033[0;33m'
PURPLE='\033[0;35m'
CYAN='\033[0;36m'

FT_EXEC='./ft_containers'
FT_TEXT='ft_containers.txt'
STD_EXEC='./std_containers'
STD_TEXT='std_containers.txt'
RESULT='diff_result.txt'

echo -e ${PURPLE}"\n${FT_EXEC} > ${FT_TEXT}"${DEFAULT}
${FT_EXEC} > ${FT_TEXT}

echo -e ${PURPLE}"${STD_EXEC} > ${STD_TEXT}"${DEFAULT}
${STD_EXEC} > ${STD_TEXT}

echo -e ${PURPLE}"diff ${FT_TEXT} ${STD_TEXT} > ${RESULT}"${DEFAULT}
diff ${FT_TEXT} ${STD_TEXT} > ${RESULT}

echo -e ${YELLOW}"Checking contents of ${RESULT}"${DEFAULT}
if [ -s ${RESULT} ]; then
	echo -e "Status: "${RED}"[KO]"${DEFAULT}
else
	echo -e "Status: "${GREEN}"[OK]"${DEFAULT}
fi

rm ${FT_TEXT} ${STD_TEXT} ${RESULT}
