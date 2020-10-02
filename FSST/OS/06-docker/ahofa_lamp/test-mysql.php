<?php
$dbh = mysql_connect('localhost', 'root', 'comein');
if (!$dbh) {
    die('Could not connect: ' . mysql_error());
}
echo 'Connected successfully to Mysql database';
mysql_close($dbh);
?>
