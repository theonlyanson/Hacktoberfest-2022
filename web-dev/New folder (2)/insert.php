

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
    .rms{
        height: 10vh;
        width: 20vh;
    }
    body{
        background-image: url("./download2.jpg");
        background-repeat: no-repeat;
        background-attachment: fixed;
        background-size: 100%;
    }
    .card{
opacity: 0.65;
width: 50%;
margin: auto;
    }
    .text{
        
    }
    .btn{
        width: 45%;
        align-items: center;
        align-content: center;
    }
     </style>



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
              <a class="nav-link text-right mr-1" href="./index.php"><h5>Home</h5>  <span class="sr-only">(current)</span></a>
            </li>
            <li class="nav-item">
              <a class="nav-link text-lg-right" href="./index.html"><h5>Insert</h5></a>
            </li>
            
              </div>
            </li>
          </ul>
        </div>
      </nav>
      <section class="my-4">
        <div class="py-4">
            
      
      <h2 class=" text text-center ">Student Details </h2>
        </div>
        <div class="card">
        <div class="w-50 m-auto">
          <form action="plan.php" method="POST">
            <div class="form-group ">
              <label> User Name:</label>
              <input type="text" name="name"  class="form-control" placeholder="Name">
                  </div>
                  <div class="form-group">
              <label>Age:</label>
              <input type="text" name="age"  class="form-control" placeholder="Age">
                  </div>
                  <div class="form-group">
              <label>Email:</label>
              <input type="email" name="email" class="form-control" placeholder="email">
                  </div>
                  
                  <button type="submt" class="btn btn-success width=40% ">Submit</button>
          </form>
        </div>
        </div>
      </section>













        <!-- <div class="card">
        <form>
            <div class="form-group form-center ">
              <label for="exampleInputEmail1">Email address</label>
              <input type="email" class="form-control" id="exampleInputEmail1" aria-describedby="emailHelp">
              <small id="emailHelp" class="form-text text-muted">We'll never share your email with anyone else.</small>
            </div>
            <div class="form-group">
              <label for="exampleInputPassword1">Password</label>
              <input type="password" class="form-control" id="exampleInputPassword1">
            </div>
            <div class="form-group form-check">
              <input type="checkbox" class="form-check-input" id="exampleCheck1">
              <label class="form-check-label" for="exampleCheck1">Check me out</label>
            </div>
            <button type="submit" class="btn btn-primary">Submit</button>
          </form>
        </div>
     
 -->













    <script src="https://cdn.jsdelivr.net/npm/jquery@3.5.1/dist/jquery.slim.min.js" integrity="sha384-DfXdz2htPH0lsSSs5nCTpuj/zy4C+OGpamoFVy38MVBnE+IbbVYUew+OrCXaRkfj" crossorigin="anonymous"></script>
<script src="https://cdn.jsdelivr.net/npm/bootstrap@4.6.1/dist/js/bootstrap.bundle.min.js" integrity="sha384-fQybjgWLrvvRgtW6bFlB7jaZrFsaBXjsOMm/tB9LTS58ONXgqbR9W8oWht/amnpF" crossorigin="anonymous"></script>
</body>
</html>