<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>riservata</title>
</head>
<body>
<h1>Verifica dati inseriti</h1>

<?php
//inizio sessione
session_start();
//controllo se username è valido in caso contrario riporta alla pagina del Login
if (!isset($_SESSION['username'])) {
    header('Location: login.php');
    exit();
}
$nome = $_SESSION['username'];

 echo "<b>Benvenuto $nome Nell'area riservata del sito</b>";
?>
<a href="logout.php">logout</a>
    
</body>
</html>