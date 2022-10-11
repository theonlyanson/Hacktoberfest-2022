console.log("welcome to tic tac toe")
let music = new Audio("music.mp3")
let audioturn =new Audio("ting.mp3")
let gameover = new Audio("gameover.mp3")
let turn= "X"
let game=false;

// function to change the turn 
function changeTurn(){
    return turn=="X"?"0":"X"
}

// function to check for a win
 checkWin = ()=>{
    let boxtexts=document.getElementsByClassName("boxtext");
    let win=[
        [0,1,2],
        [3,4,5],
        [6,7,8],
        [0,3,6],
        [1,4,7],
        [2,5,8],
        [0,4,8],
        [2,4,6],
    ]
    win.forEach(e=>{
        if((boxtexts[e[0]].innerHTML==boxtexts[e[1]].innerHTML) && (boxtexts[e[1]].innerHTML==boxtexts[e[2]].innerHTML) && (boxtexts[e[0]].innerHTML!="")){
              game=true;
              document.getElementsByClassName("info")[0].innerHTML="won by"+boxtexts[e[0]].innerHTML; 
              document.querySelector(".imgbox").getElementsByTagName("img")[0].style.width="300px" 
              document.querySelector(".imgbox").getElementsByTagName("img")[0].style.height="300px"    

        }
    })
}   

// Game Logic
let boxes =document.getElementsByClassName("box");
Array.from(boxes).forEach(element =>{
    let boxtext=element.querySelector('.boxtext');
    console.log("11")
    element.addEventListener('click',()=>{
    if(boxtext.innerHTML==""){
        console.log("11");
        boxtext.innerHTML=turn;
        turn=changeTurn();
        audioturn.play();
        checkWin();
        if(!game){
        document.getElementsByClassName("info")[0].innerHTML="turn for"+turn;
        }
    }
    })
})
