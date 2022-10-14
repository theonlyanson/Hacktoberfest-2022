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
    body{
        background-image: url("./download5.jpg") ;
        background-repeat: no-repeat;
        background-attachment: fixed;
    }
    h2{
        text-align: center;
        margin-top: 100%;
    }
    row{
        color: white;
    }
</style>
<h2>Student Details</h2>
<?php
$con = mysqli_connect("localhost","root","","plan");
if(mysqli_connect_error())
{
    echo "error";
}
else{

    $que = "SELECT * FROM `plan`";
    $result = $con->query($que);
    $count = 0;
    foreach($result as $row) {



?>
<section>
<div class="container">
   

    
        <form action="./plan.php" method="POST">
                 
        <div class="row mt-4">
                 <div class="col col-12 col-md-3 col-bg-3">
                        <h5>Username:</h5>
                    <input class="form-control form-control-lg" value="<?php echo $row["name"]; ?>" name="name">
                    </div>
                    <hr>
                    <div class="col col-12 col-md-3 col-lg-3">
                        <h5>Age:</h5>
                    <input class="form-control form-control-lg" value="<?php echo $row["age"]; ?>"  name="age">
                    </div>
                    <hr>
                    <div class="col col-12 col-md-3 col-lg-3">
                        <h5>Email:</h5>
                    <input class="form-control form-control-lg" value="<?php echo $row["email"]; ?>" name="email">
                    </div>
                 </div>
                    <hr>
                    
                    </div>


<?php
    }
}?>
</form>
</section>












<script src="https://cdn.jsdelivr.net/npm/jquery@3.5.1/dist/jquery.slim.min.js" integrity="sha384-DfXdz2htPH0lsSSs5nCTpuj/zy4C+OGpamoFVy38MVBnE+IbbVYUew+OrCXaRkfj" crossorigin="anonymous"></script>
<script src="https://cdn.jsdelivr.net/npm/bootstrap@4.6.1/dist/js/bootstrap.bundle.min.js" integrity="sha384-fQybjgWLrvvRgtW6bFlB7jaZrFsaBXjsOMm/tB9LTS58ONXgqbR9W8oWht/amnpF" crossorigin="anonymous"></script>
</body>
</html>