// demo_popen.c

#include <stdio.h>
#include <stdlib.h>

#define BUF_SIZE 1024

int main()
{
    char buf[BUF_SIZE];
    FILE *pstream;


    pstream = popen("sort /etc/passwd", "r");
    while (fgets(buf, BUF_SIZE, pstream))
    {
        fputs(buf, stdout);
    }
    fclose(pstream);


    pstream = popen("pstree", "r");
    while (fgets(buf, BUF_SIZE, pstream))
    {
        fputs(buf, stdout);
    }
    fclose(pstream);


    char *cmd = "curl -s -L http://www.zamg.ac.at/ogd | grep Salzburg | awk -F\";\" '{print $2 \";\" $4 \";\" $5 \";hat \" $6 \" Grad celsius\"}'";

    pstream = popen(cmd, "r");
    while (fgets(buf, BUF_SIZE, pstream))
    {
        fputs(buf, stdout);
    }
    fclose(pstream);

    return 0;
}

// gcc demo_popen.c -o demo_popen.exe; ./demo_popen.exe
