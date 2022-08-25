#!/bin/bash
make re

DEFAULT='\033[0m'
RED='\033[1;31m'
GREEN='\033[1;32m'
YELLOW='\033[0;33m'
CYAN='\033[0;36m'

echo -e "${YELLOW}Redirecting ft_containers to ft${DEFAULT}"
./ft_containers > ft
echo -e "${YELLOW}Redirecting std_containers to std${DEFAULT}"
./std_containers > std
echo -e "${YELLOW}diff ft std${DEFAULT}"
diff ft std > final

if [ -s final ]; then
	echo -e "${RED}FAILED -42${DEFAULT}"
else
	echo -e "${GREEN}PASS 125${DEFAULT}"
fi

rm ft std final
make fclean
