#!/bin/bash
for i in {1..30}; do docker run -d -p `expr 8800 + $i`:80 -p `expr 3306 + $i`:3306 -p `expr 4400 + $i`:4444  --name=ahofa_dvwa$i vulnerables/web-dvwa:latest; done
