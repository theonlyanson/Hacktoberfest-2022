<link rel="stylesheet" href="https://cdn.jsdelivr.net/npm/bootstrap@4.6.0/dist/css/bootstrap.min.css" integrity="sha384-B0vP5xmATw1+K9KRQjQERJvTumQW0nPEzvF6L/Z6nronJ3oUOFUFpCjEUQouq2+l" crossorigin="anonymous">

<?php


$con = mysqli_connect("localhost","root","","plan");
        if(mysqli_connect_error())
        {
            echo "error";
        }
        else{

$name = $_POST["name"] ?? "";
$age = $_POST["age"] ?? "";
$email = $_POST["email"]??"";




$que ='INSERT INTO `plan` values("'. $name . '","'. $age . '","' . $email . '")';
 echo $que;
if ( $con ->query($que)) {
    header("location:insert.php");
}
else{
    echo "<h1>failed</h1>";
}

}

?>
<br>
<br>
