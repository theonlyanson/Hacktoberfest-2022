<link rel="stylesheet" href="https://cdn.jsdelivr.net/npm/bootstrap@4.6.0/dist/css/bootstrap.min.css" integrity="sha384-B0vP5xmATw1+K9KRQjQERJvTumQW0nPEzvF6L/Z6nronJ3oUOFUFpCjEUQouq2+l" crossorigin="anonymous">

<?php


$con = mysqli_connect("localhost","root","","users");
        if(mysqli_connect_error())
        {
            echo "error";
        }
        else{

$name = $_POST["name"] ?? "";
$email = $_POST["email"] ?? "";
$password = $_POST["password"] ?? "";
$number = $_POST["number"] ?? "";



$que ='INSERT INTO `users` values("'. $name . '","'. $email . '","' . $password . '","' . $number . '")';
 echo $que;
if ( $con ->query($que)) {
    header("location:index.php");
}
else{
    echo "<h1>failed</h1>";
}

}

?>
<br>    
<br>
