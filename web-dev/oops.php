



<?php
// class fruit{
//     public $name;
//     public $color;

//     function set_name($name){
//         $this->name = $name;
//     }
//     function get_name(){
//         return $this->name;
//     }
// }
// $apple =new fruit();
// $banana =new fruit();
// $apple->set_name('apple');
// $banana->set_name('banana');

// echo $apple->get_name();
// echo "<br>";
// echo $banana->get_name();


//-----get and post----//


// if(isset($_GET["name"])|| isset($_GET["age"])){
//     echo "hi". $_GET['name']. "<br>";
//     echo "your age is".$_GET['age']." years";
//     exit();

// }



// ?>
<!-- <body>
<html>
    <form action =" <?php $_PHP_SELF ?> "method ="GET">
    Name: <input type="text" name ="name" />
    Age: <input type="text" name="age"/>
    <input type="submit" />
    </form>
</body>
</html> -->

<?php
if(isset($_POST["name"])|| isset($_POST["age"])){
    if(preg_match("/[^A-Za-z'-]/",  $_POST['name'])){
        die("inavalid name. name should be alphabet");
        
    }
    echo "hi". $_POST['name']. "<br>";
    echo "your age is".$_POST['age']." years";
    exit();

}
?>
<body>
<html>
    <form action =" <?php $_PHP_SELF ?> "method ="POST">
    Name: <input type="text" name ="name" />
    Age: <input type="text" name="age"/>
    <input type="submit" />
    </form>
</body>
</html>