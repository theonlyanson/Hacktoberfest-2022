<!DOCTYPE html>
<html lang="en">

<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Document</title>
    <link rel="stylesheet" href="https://cdn.jsdelivr.net/npm/bootstrap@4.6.1/dist/css/bootstrap.min.css" integrity="sha384-zCbKRCUGaJDkqS1kPbPd7TveP5iyJE0EjAuZQTgFLD2ylzuqKfdKlfG/eSrtxUkn" crossorigin="anonymous">

</head>
<style>
    .rms {
        height: 10vh;
        width: 20vh;
    }

    body {
        background-image: url("./download5.jpg");
        background-repeat: no-repeat;
        background-attachment: fixed;
        background-size: cover;
    }
    .card{
        opacity: 0.55;
    }
</style>

<?php
$con = mysqli_connect("localhost", "root", "", "plan");


?>

<body>

    <nav class="navbar navbar-expand-sm navbar-darkt bg-light tab-content text-right">
        <div class="logo ">
            <img src="./download1.png" class="rms">
        </div>
        <!-- <a class="navbar-brand" href="./download.jpg"> Navbar </a> -->
        <button class="navbar-toggler" type="button" data-toggle="collapse" data-target="#navbarNavDropdown" aria-controls="navbarNavDropdown" aria-expanded="false" aria-label="Toggle navigation">
            <span class="navbar-toggler-icon"></span>
        </button>
        <div class="collapse navbar-collapse" id="navbarNavDropdown">
            <ul class="navbar-nav ml-auto">
                <li class="nav-item active">
                    <a class="nav-link text-right mr-1" href="#">
                        <h5>Home</h5> <span class="sr-only">(current)</span>
                    </a>
                </li>
                <li class="nav-item">
                    <a class="nav-link text-lg-right" href="./insert.php">
                        <h5>Insert</h5>
                    </a>
                </li>
                <li class="nav-item">
                    <a class="nav-link text-lg-right" href="./show.php">
                        <h5>View</h5>
                    </a>
                </li>


        </div>
        </li>
        </ul>
        </div>
    </nav>
    

<script src="https://cdn.jsdelivr.net/npm/jquery@3.5.1/dist/jquery.slim.min.js" integrity="sha384-DfXdz2htPH0lsSSs5nCTpuj/zy4C+OGpamoFVy38MVBnE+IbbVYUew+OrCXaRkfj" crossorigin="anonymous"></script>
<script src="https://cdn.jsdelivr.net/npm/bootstrap@4.6.1/dist/js/bootstrap.bundle.min.js" integrity="sha384-fQybjgWLrvvRgtW6bFlB7jaZrFsaBXjsOMm/tB9LTS58ONXgqbR9W8oWht/amnpF" crossorigin="anonymous"></script>
</body>

</html>