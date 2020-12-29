<?php
/* is_professoren.php */

$conn= mysqli_connect("localhost", "is_uni","comein","is_uni") or
				die("Verbindungsversuch fehlgeschlagen");
                               
mysqli_select_db($conn, "is_uni") or 
				die("Konnte die Datenbank nicht waehlen.");

$sql    = "SELECT persnr, name FROM is_uni.is_professoren";

$query  = mysqli_query($conn, $sql) or 
				die("Anfrage nicht erfolgreich");

$anzahl = mysqli_num_rows($query);

echo "Anzahl der Datensätze: $anzahl";
?>

<table border="1"><tr><td>PERSNR</td><td>NAME</td></tr>

<?php
while ($row = mysqli_fetch_array($query)){
   print "<tr><td>";
   print $row['persnr'] . "</td>";
   print "<td>" . $row['name'] . "</td></tr>";
}

print "</table>";

// Free resultset
mysqli_free_result($query);

// Closing connection
mysqli_close($conn);
?>
