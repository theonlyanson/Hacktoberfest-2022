<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    
    <title>Photoblog</title>
    <link rel="stylesheet" href="https://cdn.jsdelivr.net/npm/bootstrap@4.6.1/dist/css/bootstrap.min.css" integrity="sha384-zCbKRCUGaJDkqS1kPbPd7TveP5iyJE0EjAuZQTgFLD2ylzuqKfdKlfG/eSrtxUkn" crossorigin="anonymous">                                                                                                                  
</head>

<body>
<nav class="navbar navbar-expand-lg navbar-dark bg-info">
  <a class="navbar-brand text-white" href="#">Shop Fun</a>
  <button class="navbar-toggler" type="button" data-toggle="collapse" data-target="#navbarSupportedContent" aria-controls="navbarSupportedContent" aria-expanded="false" aria-label="Toggle navigation">
    <span class="navbar-toggler-icon"></span>
  </button>

  <div class="collapse navbar-collapse" id="navbarSupportedContent">
    <ul class="navbar-nav mr-auto">
      <li class="nav-item active">
        <a class="nav-link" href="#">Account <span class="sr-only"></span></a>
      </li>
      <li class="nav-item">
        <a class="nav-link text-white" href="#">Kids</a>
      </li>
      <li class="nav-item dropdown">
        <a class="nav-link dropdown-toggle text-white" href="#" id="navbarDropdown" role="button" data-toggle="dropdown" aria-expanded="false">
        Categories
        </a>
        <div class="dropdown-menu" aria-labelledby="navbarDropdown">
          <a class="dropdown-item" href="#watches">Watches</a>
          <div class="dropdown-divider"></div>
          <a class="dropdown-item" href="#Footware">Footware</a>
          <div class="dropdown-divider"></div>
          <a class="dropdown-item" href="#Gadgets">Gadgets</a>
        </div>
      </li> 
      <li class="nav-item">
        <a class="nav-link disabled text-white" href="#contact">Contact us</a>
      </li>
      <li class="nav-item">
        <a class="nav-link disabled text-white" href="#About">About Us</a>
      </li>
    </ul>
    <form class="form-inline my-2 my-lg-0">
      <input class="form-control mr-sm-2" type="search" placeholder="Search" aria-label="Search">
      <button class="btn btn-outline-light my-2 my-sm-0 " type="submit">Help</button>
    </form>
  </div>
</nav>


<div id="carouselExampleCaptions" class="carousel slide" data-ride="carousel">
  <ol class="carousel-indicators">
    <li data-target="#carouselExampleCaptions" data-slide-to="0" class="active"></li>
    <li data-target="#carouselExampleCaptions" data-slide-to="1"></li>
    <li data-target="#carouselExampleCaptions" data-slide-to="2"></li>
  </ol>
  <div class="carousel-inner">
    <div class="carousel-item active">
      <img src="f1.gif" class="d-block w-100" alt="Footware">
      <div class="carousel-caption d-none d-md-block">
        <h5>Footware</h5>
        <p>Some representative placeholder content for the first slide.</p>
      </div>
    </div>
    <div class="carousel-item">
      <img src="w1.jpeg" class="d-block w-100" alt="watches">
      <div class="carousel-caption d-none d-md-block">
        <h5>watches</h5>
        <p>Some representative placeholder content for the second slide.</p>
      </div>
    </div>
    <div class="carousel-item">
      <img src="g1.jpg" class="d-block w-100" alt="Gadgets">
      <div class="carousel-caption d-none d-md-block">
        <h5>Gadgets</h5>
        <p>Some representative placeholder content for the third slide.</p>
      </div>
    </div>
  </div>
  <button class="carousel-control-prev" type="button" data-target="#carouselExampleCaptions" data-slide="prev">
    <span class="carousel-control-prev-icon" aria-hidden="true"></span>
    <span class="sr-only">Previous</span>
  </button>
  <button class="carousel-control-next" type="button" data-target="#carouselExampleCaptions" data-slide="next">
    <span class="carousel-control-next-icon" aria-hidden="true"></span>
    <span class="sr-only">Next</span>
  </button>
</div>

<a id="watches">
<section class="my-4">
  <div class="py-4">

<h2 class="text-center">Watches </h2>
  </div>
  <div class="container-fluid">
    <div class="row">
  <div class="col-lg-4 col-md-4 col-12">
    <img src="w3.jpg " class="img-fluid pb-3 width=40vh">
  </div>
  <div class="col-lg-4 col-md-4 col-12">
    <img src="w4.jpeg" class="img-fluid pb-3 width=40% height=20%">
  </div><div class="col-lg-4 col-md-4 col-12">
    <img src="w5.jpg" class="img-fluid pb-3">
  </div><div class="col-lg-4 col-md-4 col-12">
    <img src="w6.jpeg" class="img-fluid pb-3">
  </div>
  </div>
  </div>

</section>
</a>
<a id="Footware">
<section class="my-4">
  <div class="py-4">

<h2 class="text-center">Footware </h2>
  </div>
  <div class="container-fluid">
    <div class="row">
  <div class="col-lg-4 col-md-4 col-12">
    <img src="f2.jpg" class="img-fluid pb-3">
  </div>
  <div class="col-lg-4 col-md-4 col-12">
    <img src="f3.jpg" class="img-fluid pb-3">
  </div><div class="col-lg-4 col-md-4 col-12">
    <img src="f4.webp" class="img-fluid pb-3">
  </div><div class="col-lg-4 col-md-4 col-12">
    <img src="f6.webp" class="img-fluid pb-3">
  </div>
  </div>
  </div>

</section>
</a>
<a id="Gadgets">
<section class="my-4">
  <div class="py-4">

<h2 class="text-center">Gadgets </h2>
  </div>
  <div class="container-fluid">
    <div class="row">
  <div class="col-lg-4 col-md-4 col-12">
    <img src="g2.webp" class="img-fluid pb-3">
  </div>
  <div class="col-lg-4 col-md-4 col-12">
    <img src="g3.jpg" class="img-fluid pb-3">
  </div><div class="col-lg-4 col-md-4 col-12">
    <img src="g4.jpg" class="img-fluid pb-3">
  </div><div class="col-lg-4 col-md-4 col-12">
    <img src="g6.jpg" class="img-fluid pb-3">
  </div>
  </div>
  </div>

</section>
</a>
<a id="contact">
<section class="my-4">
  <div class="py-4">

<h2 class="text-center">Contact Us </h2>
  </div>

  <div class="w-50 m-auto">
    <form action="about.php" method="POST">
      <div class="form-group">
        <label> User Name:</label>
        <input type="text" name="name" class="form-control">
            </div>
            <div class="form-group">
        <label>Password:</label>
        <input type="text" name="password" class="form-control">
            </div>
            <div class="form-group">
        <label>Email:</label>
        <input type="email" name="email" class="form-control">
            </div>
            <div class="form-group">
        <label>Number:</label>
        <input type="text" name="number" class="form-control">
            </div>
            <button type="submt" class="btn btn-success width=40%">Submit</button>
    </form>
  </div>
</section>
</a>
<a id="About">
<section class="my-4">
  <div class="py-4">

<h2 class="text-center">About Us </h2>
  </div>
</section>
</a>
















<script src="https://cdn.jsdelivr.net/npm/jquery@3.5.1/dist/jquery.slim.min.js" integrity="sha384-DfXdz2htPH0lsSSs5nCTpuj/zy4C+OGpamoFVy38MVBnE+IbbVYUew+OrCXaRkfj" crossorigin="anonymous"></script>
<script src="https://cdn.jsdelivr.net/npm/bootstrap@4.6.1/dist/js/bootstrap.bundle.min.js" integrity="sha384-fQybjgWLrvvRgtW6bFlB7jaZrFsaBXjsOMm/tB9LTS58ONXgqbR9W8oWht/amnpF" crossorigin="anonymous"></script>  
</body>
</html>