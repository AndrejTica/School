#!/bin/bash
# ./do_create_keys.sh NAME
#

if [ $# -eq 0 ]
  then
    echo "enter NAME for key-public-NAME.pem"
    read NAME
  else
    NAME=$1
fi

openssl genrsa -out private.pem 4096
chmod 600 private.pem
openssl rsa -pubout -in private.pem -out key-public-$NAME.pem

echo ""
echo "[done] created private.pem"
echo "[done] created key-public-$NAME.pem"
echo ""
