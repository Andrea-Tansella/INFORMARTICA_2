<?php
session_start();   
session_destroy(); //distrugge la sessione e riporta alla pagina del Login
header('Location: login.php');
exit;
?>