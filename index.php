<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>HomePage</title>
</head>
<body>
<p><a href="login.php">login</a></p>
<?php
    //inizio della sessione
    session_start();
    //si effettua un controllo sull'username, se non rispetta il controllo viene rimandato alla pagina del login caso contrario accedi alla pagina riservata
    if (!isset($_SESSION['username'])) {
        echo '<p><a href="login.php">pagina riservata</a></p>';
    } else {
        echo '<p><a href="riservata.php">Pagina Riservata</a></p>';//collegamento pagina riservata
    }
    ?>
        
    
</body>
</html>