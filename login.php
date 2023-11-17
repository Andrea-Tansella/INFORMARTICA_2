<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>login</title>
</head>
<body>
<?php
// inizio della sessione
session_start();
//consente di definire una stringa di testo multiriga in modo più leggibile rispetto all'utilizzo di virgolette o apici.
$logIn=<<<LOGIN
    <h1>Richiesta credenziali per accesso</h1>
    <p>Dati: username = andrea, password=1234</p>   
    <form method="POST" action="login.php">
        <label for="username">Username</label>
        <input type="text" name="username" placeholder="Inserire username" required/>
        <br/>
        <br/>
        <label for="password">Password</label>
        <input type="password" name="password" placeholder="Password" required/>
        <br/>
        <br/>
        <input type="submit" name="ACCEDI" value="ACCEDI"/>
    </form>
LOGIN;

//controllo se rispetta il metodo post
if ($_SERVER['REQUEST_METHOD'] === 'POST') {
    $username = "andrea"; 
    $password = "1234";
    // controllo se la password e username sono valide in caso positivo vieni mandato nella pagina riservata in caso contrario ti riporta al login
    if ($_POST['username'] === $username && $_POST['password'] === $password) {
        $_SESSION['username'] = $username;//memorizzare il nome dell'utente in sessione
        header('Location: riservata.php');
        exit();
    } else {
        echo "<p>Credenziali errate. Riprova.</p> $logIn";//stampa a schermo l'echo e butta fuori login
    }
} else {
    echo $logIn;
}
?>
</body>
</html>
